#ifndef __VIDEOPROCESSORH__
#define __VIDEOPROCESSORH__

#include "cv.h"
#include "highgui.h"
#include "cvaux.h"

#include <stdio.h>

#define MAX_VIDEO_PROCESSORS 20

class VideoProcessor
{
private:
	char name[20];
	bool processing;

public:
	//Processes video frame and returns processed one
	virtual IplImage* ProcessVideoFrame( IplImage *InputFrame ){ return NULL; }
	//Transfers new options to video processor
	virtual bool TransferOptions();
	char *GetVideoProcessorName(){ return name; }

	VideoProcessor( char* lname );
	~VideoProcessor(){}
};

//Class for storing video processors, and processing frames thru them
class VideoProcessorManager
{
private:
	VideoProcessor *cVideoProcessors[MAX_VIDEO_PROCESSORS];
	int VideoProcessorCount;
	bool processing;

public:
	bool AddVideoProcessor( VideoProcessor *lVideoProcessor );

	//Processes video frame by all video processors
	IplImage* ProcessVideoFrame( IplImage* InputFrame );
	VideoProcessor* GetVideoProcessor( int index );
	VideoProcessor* GetVideoProcessorByName( char* name );
	int GetVideoProcessorCount();
	bool TransferOptions();

	VideoProcessorManager();
	~VideoProcessorManager();
};
#endif