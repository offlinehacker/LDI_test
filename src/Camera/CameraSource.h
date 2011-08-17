#ifndef __CAMERASOURCEH__
#define __CAMERASOURCEH__

#include "highgui.h"
#include "cv.h"
#include "cvaux.h"
#include "cxcore.h"

#define CAM_TYPE_CAMERA 0
#define CAM_TYPE_FILE 1

class CameraSource
{
protected:
	char camera_name[20];
	
	bool opened;
	bool tested;
	int width;
	int height;
	int fps;
	int depth;
	int channels;

	char cam_type;//It can be camera or video file
public:
	CameraSource();
	~CameraSource();
	//Gets camera name
	virtual char* GetCameraName(){ return "nocam"; }
	//Gets camera type
	virtual char GetCamType(){ return cam_type; }
	//Gets camera width
	virtual int GetWidth(){ return width; }
	//Gets camera height
	virtual int GetHeight(){ return height; }
	//Gets camera fps
	virtual int GetFps(){ return fps; }
	//Gets camera depth
	virtual int GetDepth(){ return depth; }
	//Gets camera channels
	virtual int GetChannels(){ return channels; }
	//Returns info if camera is opened
	virtual bool IsOpened(){ return opened; }
	//This is only for video files
	virtual void SetFilename( char* filepath ){}

	//For checking if camera exists and to get some of the camera parameters
	virtual bool TestCamera(){ return false; }
	//Open our camera
	virtual bool OpenCamera(){ return false; }
	//Close our camera
	virtual void CloseCamera(){}
	//Get next frame from camera
	virtual IplImage* GetNextFrame(){ return NULL; }
};

class CameraEnumerator
{
public:
	virtual CameraSource *GetNextCamera(){ return NULL; }
	virtual void Reset();

};
#endif