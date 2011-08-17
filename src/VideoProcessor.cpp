#include "VideoProcessor.h"

VideoProcessor::VideoProcessor( char* lname )
{
	strncpy(name, lname, 19 );

}

VideoProcessorManager::VideoProcessorManager()
{
	VideoProcessorCount= 0;
	processing=false;
}

VideoProcessorManager::~VideoProcessorManager()
{
	for( int x=0; x<VideoProcessorCount; x++ )
	{
		delete(cVideoProcessors[x]);
	}
}

bool VideoProcessorManager::AddVideoProcessor( VideoProcessor *lVideoProcessor )
{
	if(VideoProcessorCount>=20)
		return false;

	cVideoProcessors[VideoProcessorCount]= lVideoProcessor;
	VideoProcessorCount++;

	return true;
}

bool VideoProcessor::TransferOptions()
{
	return true;
}

bool VideoProcessorManager::TransferOptions()
{
	if(processing)
		return false;

	for( int x=0; x<VideoProcessorCount; x++ )
	{
		cVideoProcessors[x]->TransferOptions();
	}

	return true;
}

IplImage *VideoProcessorManager::ProcessVideoFrame( IplImage *lVideoFrame )
{
	processing= true;

	IplImage *OldFrame= lVideoFrame;
	IplImage *NewFrame;
	for( int x=0; x<VideoProcessorCount; x++ )
	{
		NewFrame= cVideoProcessors[x]->ProcessVideoFrame( OldFrame );
		cvReleaseImage(&OldFrame);
	}

	processing= false;

	return NewFrame;
}

VideoProcessor* VideoProcessorManager::GetVideoProcessor( int index )
{
	if( index>=VideoProcessorCount )
		return NULL;

	return cVideoProcessors[index];
}

VideoProcessor* VideoProcessorManager::GetVideoProcessorByName( char* name )
{
	for( int x=0; x<VideoProcessorCount; x++ )
	{
		if( !strcmp(cVideoProcessors[x]->GetVideoProcessorName(),name) )
			return cVideoProcessors[x];
	}

	return NULL;
}

int VideoProcessorManager::GetVideoProcessorCount()
{
	return VideoProcessorCount;
}