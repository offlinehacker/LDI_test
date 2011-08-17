#include "WorkingThread.h"
WorkingThread::WorkingThread( VideoProcessorManager *lVideoProcessorManager, CameraSourceManager *lCameraSourceManager, VideoIOConfiguration *lVideoIOConfiguration, OutputManager *lOutputManager ): wxThread( wxTHREAD_DETACHED )
{
	cVideoProcessorManager= lVideoProcessorManager;
	cCameraSourceManager= lCameraSourceManager;
	cVideoIOConfiguration= lVideoIOConfiguration;
	cOutputManager= lOutputManager;
	working= true;
	VideoSourceOpened= false;
	VideoIsProcessing= false;
	VideoIsRecording= false;
}

WorkingThread::~WorkingThread()
{
	if( VideoIsRecording )
		delete( cVideoRecorder );
}

void *WorkingThread::Entry()
{
	IplImage *NextFrame= NULL;
	IplImage *NewFrame= NULL;
	IplImage *LastFrame= NULL;

	while(working)
	{
		if(VideoSourceOpened)
		{
			NextFrame= cCameraSourceManager->GetNextFrameAndPreProcess();
			if(!NextFrame)
				continue;
			if( VideoIsRecording )
				cVideoRecorder->RecordFrame( NextFrame );
			cVideoIOConfiguration->DisplayFrame( NextFrame, "In" );
			if(NextFrame)
			{
				if( VideoIsProcessing )
				{
					cVideoProcessorManager->TransferOptions();
					LastFrame= NextFrame;
					for( int x=0; x<cVideoProcessorManager->GetVideoProcessorCount(); x++ )
					{
						NewFrame= cVideoProcessorManager->GetVideoProcessor( x )->ProcessVideoFrame( LastFrame );
						if(x!=0)
							cvReleaseImage( &LastFrame );
						if(!NewFrame)
							break;

						cVideoIOConfiguration->DisplayFrame( NewFrame, cVideoProcessorManager->GetVideoProcessor( x )->GetVideoProcessorName() );
					}

					cVideoIOConfiguration->DisplayFrame( NextFrame, "Out" );
					cOutputManager->DisplayOutputData();
				}
			}
		}

		cvReleaseImage( &NextFrame );
	}

	return NULL;
}

void WorkingThread::OnExit( )
{
}

bool WorkingThread::OpenVideoSource()
{
	if(VideoSourceOpened)
	{
		CloseVideoSource();
		OpenVideoSource();
	}

	CameraSource *lCameraSource= cCameraSourceManager->GetSelectedCamera();
	if(!lCameraSource)
		return false;

	if(lCameraSource->OpenCamera())
	{
		VideoSourceOpened= true;
		return true;
	}

	return false;
}

bool WorkingThread::CloseVideoSource()
{
	CameraSource *lCameraSource= cCameraSourceManager->GetSelectedCamera();
	if(!lCameraSource)
		return false;

	lCameraSource->CloseCamera();
	VideoSourceOpened= false;
	return false;
}

bool WorkingThread::StartVideoRecording( char *filename )
{
	if(VideoIsRecording)
	{
		VideoIsRecording= false;
		delete( cVideoRecorder );
	}
	cVideoRecorder= new VideoRecorder( filename, cCameraSourceManager->GetSelectedCamera()->GetWidth(), cCameraSourceManager->GetSelectedCamera()->GetHeight() );
	if( cVideoRecorder->IsOpened() )
	{
		VideoIsRecording= true;
		return true;
	}

	return false;
}

void WorkingThread::StopVideoRecording()
{
	VideoIsRecording= false;
	cVideoRecorder->StopRecording();
	delete( cVideoRecorder );
}