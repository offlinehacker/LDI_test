#include "CameraSourceManager.h"

bool CameraSourceManager::AddCameraEnumerator( CameraEnumerator *lCameraEnumerator )
{
	if(CameraEnumeratorsCount>=MAX_CAMERA_ENUMERATORS)
		return false;

	CameraEnumerators[CameraEnumeratorsCount]= lCameraEnumerator;
	CameraEnumeratorsCount++;

	return true;
}

CameraSourceManager::CameraSourceManager()
{
	SelectedCamera= NULL;
	CameraEnumeratorsCount= 0;
	LeaveOpened= false;
	Enumerated= false;

	//Preprocessor options
	FlipImage= false;
	SwapColors= false;

#ifdef CAMERA_ENUMERATOR_1
	AddCameraEnumerator( new CAMERA_ENUMERATOR_1() );
#endif
#ifdef CAMERA_ENUMERATOR_2
	AddCameraEnumerator( new CAMERA_ENUMERATOR_2() );
#endif
}

CameraSourceManager::~CameraSourceManager()
{
	for( int x=0; x<CameraEnumeratorsCount; x++ )
	{
		delete( CameraEnumerators[x] );
	}

	for( int x=0; x<CameraCount; x++ )
	{
		delete( AllCameras[x] );
	}
}

bool CameraSourceManager::EnumerateAllCameras()
{
	CameraSource* lCameraSource= NULL;
	//if we enumerate cameras again we should delete them first
	if(Enumerated)
	{
		for( int x=0; x<CameraCount; x++ )
		{
			delete( AllCameras[x] );
		}
	}

	CameraCount= -1;

	for( int x=0; x<CameraEnumeratorsCount; x++ )
	{
		//Reset enumerator counters
		CameraEnumerators[x]->Reset();
		do
		{
			lCameraSource= CameraEnumerators[x]->GetNextCamera();
			if(lCameraSource!=NULL) CameraCount++;
			if(lCameraSource)
			{
				AllCameras[CameraCount]= lCameraSource;
			}
		}
		while( lCameraSource );
	}

	CameraCount++;
	Enumerated= true;

	return true;
}

void CameraSourceManager::SelectCamera( int id )
{
	//if we dont have to switch camera
	if( SelectedCamera==AllCameras[id] )
		return;
	else
		SelectedCamera= AllCameras[id];

	//If selected camera is already opened
	if( (SelectedCamera && SelectedCamera->IsOpened() ) && !LeaveOpened )
		SelectedCamera->CloseCamera();
}

int CameraSourceManager::GetCameraIdByName( char* CameraName )
{
	for( int x=0; x<CameraCount; x++ )
	{
		if( !strcmp( AllCameras[x]->GetCameraName(), CameraName ) )
			return x;
	}

	return -1;
}

CameraSource* CameraSourceManager::GetCameraById( int id )
{
	if(id<CameraCount)
		return AllCameras[id];

	return NULL;
}

bool CameraSourceManager::OpenVideoSource()
{
	return SelectedCamera->OpenCamera();
}

void CameraSourceManager::CloseVideoSource()
{
	SelectedCamera->CloseCamera();
}

IplImage* CameraSourceManager::GetNextFrame()
{
	return SelectedCamera->GetNextFrame();
}

IplImage* CameraSourceManager::GetNextFrameAndPreProcess()
{
	IplImage *tFrame= SelectedCamera->GetNextFrame();
	if(!tFrame)
		return NULL;

	IplImage *NextFrame= cvCloneImage( tFrame );

	//Preprocessor
	if( SwapColors )
		cvConvertImage( NextFrame, NextFrame, CV_CVTIMG_SWAP_RB );
	if( FlipImage )
		cvConvertImage( NextFrame, NextFrame, CV_CVTIMG_FLIP );

	return NextFrame;
}

void CameraSourceManager::SetFlip()
{
	if(FlipImage)
		FlipImage=false;
	else
		FlipImage= true;
}

void CameraSourceManager::SetSwap()
{
	if(SwapColors)
		SwapColors= false;
	else
		SwapColors= true;
}
