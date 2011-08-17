#include "VideoRecorder.h"

VideoRecorder::VideoRecorder( char *lfilename, int width, int height )
{
	opened= false;
	filename= (char*)malloc(strlen(lfilename)+1);
	strcpy( filename, lfilename );

	RecorderHandle= cvCreateAVIWriter( filename, 0, 1, cvSize( width, height ), 1 );
	if(!RecorderHandle)
		return;

	opened= true;
}

bool VideoRecorder::RecordFrame( IplImage *VideoFrame )
{
	IplImage *ConvertedImage= BWToRgb(VideoFrame);
	cvWriteFrame( RecorderHandle, ConvertedImage );
	cvReleaseImage( &ConvertedImage );

	return true;
}

void VideoRecorder::StopRecording()
{
	cvReleaseVideoWriter( &RecorderHandle );
	opened= false;
}

VideoRecorder::~VideoRecorder()
{
	free( filename );
	if( opened )
		StopRecording();
}