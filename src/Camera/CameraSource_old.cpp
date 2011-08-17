#include "CameraSource.h"

CameraSource::CameraSource( int LastFramesCount )
{
	LastFrames= new CyclicImageBuffer(LastFramesCount);
}

CameraSource::~CameraSource()
{
	delete(LastFrames);
}

void CameraSourceVideo::OpenVideoSoruce()
{
	if(!CameraCapture)//V primeru da kamera se ni bila odprta
	{
#ifdef WIN32_LARRY
		CameraCapture = cvCaptureFromCAM( cam_id );
		if(!CameraCapture)//Ce nam ne uspe dobiti kamere
			return;
	}

	// grab first frame to initialize format
	IplImage* pFrame = cvQueryFrame( CameraCapture );
	return;
#else
	int ncameras = cvcamGetCamerasCount();
	printf("DEBUG :: Found cameras=%d\n", ncameras );
	int w = 640;
	int h = 480;
	int nCam = 0;
	int t=1;
	int p=1;
	
	cvcamSetProperty(nCam, CVCAM_RNDWIDTH,  &w );
	cvcamSetProperty(nCam, CVCAM_RNDHEIGHT, &h );

	cvcamSetProperty(nCam, CVCAM_PROP_ENABLE, &t );

	int width = 320;
	int height = 200;


	HWND MyWin = (HWND)m_pCameraView->GetHandle();
	cvcamSetProperty(nCam, CVCAM_PROP_WINDOW, &MyWin ); 
	cvcamSetProperty(nCam, CVCAM_PROP_RENDER, &p );  

	
	cvcamSetProperty(0, CVCAM_PROP_CALLBACK, (void*)testcallback );
	cvcamInit();
	Sleep( 5000 );
	cvcamStart();
#endif
	Width = (int) cvGetCaptureProperty( CameraCapture, CV_CAP_PROP_FRAME_WIDTH );
	Height = (int) cvGetCaptureProperty( CameraCapture, CV_CAP_PROP_FRAME_HEIGHT );
	Fps = (int) cvGetCaptureProperty( CameraCapture, CV_CAP_PROP_FPS );
	Depth = pFrame->depth;
	Channels= pFrame->nChannels;
	opened= true;
}

CameraSourceVideo::CameraSourceVideo( int LastFramesCount ): CameraSource( LastFramesCount )
{
	CameraSourceType= CAMERA_SOURCE_TYPE_CAM;

	CameraCapture= NULL;
	pause= false;
	opened= false;
	swap_rgb= false;
	flip= false;
	cam_id= 0;
}

void CameraSourceVideo::CloseVideoSource()
{
	if(opened)
	{
	#ifdef WIN32_LARRY
		cvReleaseCapture( &CameraCapture );
	#else
		cvcamExit();
	#endif
	}

	opened= false;
}

void CameraSourceVideo::Pause()
{
	if(!pause)
		pause= true;
	else
		pause= false;
}

void CameraSourceVideo::SetCamId( int id )
{
	cam_id= id;
}

int CameraSourceVideo::GetCamId()
{
	return cam_id;
}

void CameraSourceVideo::ExportVideoToFile( char* filename )
{
	RecordVideo *lVideoRecorder= new RecordVideo( filename, GetWidth(), GetHeight() );

	int x=0;
	IplImage *tImage= NULL;
	while( tImage=LastFrames->GetPointerByFrame(x) )
	{
		lVideoRecorder->RecordFrame(tImage);
		x++;
	}

	delete( lVideoRecorder );
}

IplImage *CameraSourceVideo::GetFrame()//Dobi naslednji frame in tega obenem shrani v spomin
{
	if(pause)
		return NULL;

	IplImage* pFrame = NULL;

#ifdef WIN32_LARRY	
	// get frame if any
	pFrame = cvQueryFrame( CameraCapture );
#else
	// to test this - don't remmember how i got this working 
	// on linux 
	//pFrame = m_pLnxFrame;
	// get frame in linux ?

	cvcamPause();
	cvcamGetProperty(0,CVCAM_PROP_RAW,&pFrame);
	cvcamResume();

	pFrame = cvCloneImage( fimg );

	Sleep(400);
#endif
	//ali moramo spremeniti barvno paleto
	if( swap_rgb )
	{
		cvConvertImage( pFrame, pFrame, CV_CVTIMG_SWAP_RB );
	}

	//ali moramo obrniti sliko
	if( flip )
	{
		cvConvertImage( pFrame, pFrame, CV_CVTIMG_FLIP );
	}

	LastFrames->PutPointer( pFrame );

	return pFrame;
}

IplImage *CameraSource::GetLastFrame()
{
	return LastFrames->GetPointerByFrame(0);
}

CameraSourceVideo::~CameraSourceVideo()
{
	CloseVideoSource();
}

void CameraSourceVideo::SetCameraCapture( CvCapture* lCameraCapture )//Nastavi napravo za capture ce jo odpremo ze prej
{
	CameraCapture= lCameraCapture;
	this->OpenVideoSoruce();
}

CameraSourceVideo **RetriveCVCameras()//Dobi "handlerje" za vse OpenCv kamere
{
	CameraSourceVideo** lCameraSourceVideo = (CameraSourceVideo**)malloc(sizeof(CameraSourceVideo**)*MAX_CV_CAMERAS);
	memset( (void*)lCameraSourceVideo, 0x0, sizeof(CameraSourceVideo**)*MAX_CV_CAMERAS );//Nastavimo na nulo da potem vemo kaj zbrisati
	CameraSourceVideo *tCameraSourceVideo= NULL;
	int y= 0;

	for( int x=0; x<MAX_CV_CAMERAS; x++ )//Kaj ce se kamere skrivajo v visjih cifrah
	{
		CvCapture *tCapture= cvCaptureFromCAM( x );
		if(tCapture)
		{
			tCameraSourceVideo= new CameraSourceVideo(LAST_FRAMES_COUNT);
			tCameraSourceVideo->SetCamId( x );
			tCameraSourceVideo->SetCameraCapture( tCapture );
			if(!tCameraSourceVideo->opened)//Ce ne moremo odpreti obstajajoce kamere
			{
				delete(tCameraSourceVideo);
				continue;
			}
			lCameraSourceVideo[y]= tCameraSourceVideo;
			y++;
		}

		tCapture= NULL;
	}

	return lCameraSourceVideo;
}

void DestroyCVCameras( CameraSourceVideo** lCameraSourceVideo )//Klice delte na vse "handlerje"
{
	int x=0;
	while( lCameraSourceVideo[x] )
	{
		delete( lCameraSourceVideo[x] );
		x++;
	}
}