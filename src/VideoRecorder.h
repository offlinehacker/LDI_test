#ifndef __VIDEORECORDERHH__
#define __VIDEORECORDERH__

#include "cv.h"
#include "cvaux.h"
#include "highgui.h"

#include "OpenCv/Conversions.h"

class VideoRecorder
{
private:
	CvVideoWriter *RecorderHandle;

	bool opened;
	char *filename;
	int width;
	int height;

public:
	VideoRecorder( char *lfilename, int width, int height  );
	~VideoRecorder();
	bool RecordFrame( IplImage *VideoFrame );
	void StopRecording();

	bool IsOpened(){ return opened; }
	int GetWidth(){ return width; }
	int GetHeight(){ return height; }
};

#endif