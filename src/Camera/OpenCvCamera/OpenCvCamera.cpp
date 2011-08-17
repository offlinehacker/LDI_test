#include "OpenCvCamera.h"

char* OpenCvCamera::GetCameraName()
{
	sprintf( camera_name, "cv_%d", cam_id );
	return camera_name;
}

OpenCvCamera::OpenCvCamera( int lcam_id ): CameraSource()
{
	cam_id= lcam_id;
	cam_type= CAM_TYPE_CAMERA;
}

bool OpenCvCamera::TestCamera()
{
	CvCapture *tCapture= cvCaptureFromCAM(cam_id);
	if(tCapture)
	{
		width = (int) cvGetCaptureProperty( tCapture, CV_CAP_PROP_FRAME_WIDTH );
		height = (int) cvGetCaptureProperty( tCapture, CV_CAP_PROP_FRAME_HEIGHT );
		fps = (int) cvGetCaptureProperty( tCapture, CV_CAP_PROP_FPS );

		IplImage* tFrame;
		for( int x=0; x<10; x++ )//We try to get at least one frame in time(camera needs some time to start)
		{
			wxThread::Sleep(100);
			tFrame = cvQueryFrame( tCapture );
			if( tFrame )//here we have a frame
				break;
		}
		if(!tFrame)
		{
			delete(tCapture);
			return false;
		}
		
		depth = tFrame->depth;
		channels= tFrame->nChannels;
		if(width<=0)
			width= tFrame->width;
		if(height<=0)
			height= tFrame->height;

		cvReleaseCapture(&tCapture);

		tested=true;

		return true;
	}

	return false;
}

//Open our camera
bool OpenCvCamera::OpenCamera()
{
	if(tested || TestCamera())
	{
		CameraHandle= cvCaptureFromCAM(cam_id);
		if(CameraHandle)
		{
			opened= true;
			return true;
		}
	}

	return false;
}

//Close our camera
void OpenCvCamera::CloseCamera()
{
	if(opened)
		cvReleaseCapture(&CameraHandle);
}

//Get next frame from camera
IplImage* OpenCvCamera::GetNextFrame()
{
	IplImage* pFrame= NULL;

	if(!CameraHandle)
		opened= false;

	if(opened)
		pFrame = cvQueryFrame( CameraHandle );

	return pFrame;
}

CameraSource *CvCameraEnumerator::GetNextCamera()
{
	for(int x=NextEnumeratedCamera; x<MAX_CV_CAMERAS; x++ )
	{
		OpenCvCamera *EnumCamera= new OpenCvCamera(x);
		if(EnumCamera->TestCamera())
		{
			NextEnumeratedCamera=x+1;
			return (CameraSource*)EnumCamera;
		}
		delete(EnumCamera);
	}

	return NULL;
}

void CvCameraEnumerator::Reset()
{
	NextEnumeratedCamera= 0;
}

CvVideoFile::CvVideoFile(): CameraSource()
{
	filename= NULL;
	cam_type= CAM_TYPE_FILE;
	Postopen= true;
}

void CvVideoFile::SetFilename( char* lfilename )
{
	if( filename )
	{
		CloseCamera();
		free( filename );
		filename= (char*)malloc( strlen(lfilename) );
		strcpy( filename, lfilename );
	}
	else
	{
		filename= (char*)malloc( strlen(lfilename) );
		strcpy( filename, lfilename );
	}
}

char* CvVideoFile::GetCameraName()
{
	if(filename)
		sprintf( camera_name, "vf_'%s'", filename );
	else
		sprintf( camera_name, "vf_'notset'" );
	return camera_name;
}

bool CvVideoFile::TestCamera()
{
	if(!filename)
		return false;

	CameraHandle= cvCaptureFromAVI(filename);
	if(CameraHandle)
	{
		width = (int) cvGetCaptureProperty( CameraHandle, CV_CAP_PROP_FRAME_WIDTH );
		height = (int) cvGetCaptureProperty( CameraHandle, CV_CAP_PROP_FRAME_HEIGHT );
		fps = (int) cvGetCaptureProperty( CameraHandle, CV_CAP_PROP_FPS );

		IplImage* tFrame=NULL;
		for( int x=0; x<10; x++ )//We try to get at least one frame in time(camera needs some time to start)
		{
			wxThread::Sleep(100);
			tFrame = cvQueryFrame( CameraHandle );
			if( tFrame )//here we have a frame
				break;
		}
		if(!tFrame)
		{
			delete(CameraHandle);
			return false;
		}
		
		depth = tFrame->depth;
		channels= tFrame->nChannels;
		if(width<=0)
			width= tFrame->width;
		if(height<=0)
			height= tFrame->height;

		//cvReleaseCapture(&CameraHandle);

		return true;
	}

	return false;
}

bool CvVideoFile::OpenCamera()
{
	//if(TestCamera())
	//{
		opened= true;
		return true;
	//}

	//return false;
}

void CvVideoFile::CloseCamera()
{
	if(opened && !Postopen)
		cvReleaseCapture(&CameraHandle);
	Postopen=true;
}

IplImage* CvVideoFile::GetNextFrame()
{
	if(Postopen)
	{
		TestCamera();
		Postopen= false;
	}

	IplImage* pFrame= NULL;

	if(CameraHandle)
		pFrame = cvQueryFrame( CameraHandle );
		wxThread::Sleep(1000);
	if(!pFrame)
	{
		//CloseCamera();
	}

	return pFrame;
}

CvCameraEnumerator::CvCameraEnumerator(): CameraEnumerator()
{
	NextEnumeratedCamera= 0;

}

CvVideoFileEnumerator::CvVideoFileEnumerator(): CameraEnumerator()
{
	first= false;
}

CameraSource *CvVideoFileEnumerator::GetNextCamera()
{
	if(first)
		return NULL;

	CvVideoFile *EnumCamera= new CvVideoFile();
	first=true;
	return (CameraSource*)EnumCamera;
}

void CvVideoFileEnumerator::Reset()
{
	first= false;
}
