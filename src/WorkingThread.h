#ifndef _WORKER_H
#define _WORKER_H

#include "highgui.h"
#include "cv.h"
#include "cvaux.h"
#include "cxcore.h"

#include "wx/wxprec.h"
#include "wx/thread.h"
//For displaying video
#include "Gui/camview.h"

#include "Camera/CameraSourceManager.h"
#include "VideoProcessor.h"
#include "VideoIOConfiguration.h"
#include "Output.h"
#include "VideoRecorder.h"

//Our working thread for camera reading, processing and output
class WorkingThread : public wxThread
{
private:
	//Class for processing video
	VideoProcessorManager *cVideoProcessorManager;
	//Class for camera io
	CameraSourceManager *cCameraSourceManager;
	//class for video io
	VideoIOConfiguration *cVideoIOConfiguration;
	//Class for data output
	OutputManager *cOutputManager;
	//Class for video recording(managed by working thread)
	VideoRecorder *cVideoRecorder;

	bool VideoSourceOpened;
	bool VideoIsProcessing;
	bool VideoIsRecording;
	bool working;

public:
	WorkingThread( VideoProcessorManager *lVideoProcessorManager, CameraSourceManager *lCameraSourceManager, VideoIOConfiguration *lVideoIOConfiguration, OutputManager *lOutputManager );
	~WorkingThread();

	bool OpenVideoSource();
	bool StartVideoProcessing(){ VideoIsProcessing= true; return true; }
	bool CloseVideoSource();
	void StopVideoProcessing(){ VideoIsProcessing= false; }
	bool StartVideoRecording( char * filename );
	void StopVideoRecording();
	void StopThread(){ working= false; }

	//Thread entry point
	virtual void *Entry();
	virtual void OnExit();
};

#endif