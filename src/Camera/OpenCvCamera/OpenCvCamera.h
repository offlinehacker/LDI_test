#ifndef __OPENCVCAMERAH__
#define __OPENCVCAMERAH__

#include "../CameraSource.h"

#include "wx/thread.h"

#include "highgui.h"
#include "cv.h"
#include "cvaux.h"
#include "cxcore.h"

#include <stdlib.h>

#define MAX_CV_CAMERAS 5

class OpenCvCamera: public CameraSource
{
private:
	int cam_id;
	CvCapture *CameraHandle;

public:
	OpenCvCamera( int lcam_id );

	//Gets camera name
	char* GetCameraName();
	//For checking if camera exists and to get some of the camera parameters
	bool TestCamera();
	//Open our camera
	bool OpenCamera();
	//Close our camera
	void CloseCamera();
	//Get next frame from camera
	IplImage* GetNextFrame();
};

class CvVideoFile: public CameraSource
{
private:
	char *filename;
	CvCapture *CameraHandle;
	bool Postopen;

public:
	CvVideoFile();

	//Gets camera name
	char* GetCameraName();
	//Gets videofile for processing
	char* GetFilename(){ return filename; }
	//Sets videofile for processing
	void SetFilename( char* lfilename );
	//For checking if video file exists and to get some of the video file parameters
	bool TestCamera();
	//Open our video file
	bool OpenCamera();
	//Close our video file
	void CloseCamera();
	//Get next frame from video file
	IplImage* GetNextFrame();
};

//class for getting OpenCv cameras
class CvCameraEnumerator: public CameraEnumerator
{
private:
	//Index of camera that will be get next
	int NextEnumeratedCamera;
public:
	CvCameraEnumerator();

	//Gets next camera
	CameraSource *GetNextCamera();
	void Reset();
};

//class for getting video file cam support
class CvVideoFileEnumerator: public CameraEnumerator
{
private:
		bool first;
public:
	CvVideoFileEnumerator();

	//Gets next camera
	CameraSource *GetNextCamera();
	void Reset();
};
#endif
