#ifndef __CAMERASOURCEH__
#define __CAMERASOURCEH__

#include "highgui.h"
#include "cv.h"
#include "cvaux.h"
#include "cxcore.h"

#include "CyclicBuffer.h"//Za zapisovanje video podatkov
#include "RecordVideo.h"

#define WIN32_LARRY
#define LAST_FRAMES_COUNT 100

#define CAMERA_SOURCE_TYPE_CAM 0
#define CAMERA_SOURCE_TYPE_VIDEO 1


//Glavni class za video source
class CameraSource//Predstavlja doloceno kamero in ne vec kamer
{
protected:
	CyclicImageBuffer *LastFrames;//Sem se shranjujejo zadnji prebrani frejmi, v primeru ce video ustavimo
	char CameraSourceType;

	int Width;
	int Height;
	int Fps;
	int Depth;
	int Channels;
public:
	bool opened;

	CameraSource( int LastFramesCount );
	~CameraSource();

	virtual void OpenVideoSoruce(){}
	virtual void CloseVideoSource(){}
	virtual void PauseVideo(){}
	virtual IplImage *GetFrame(){ return NULL; }//Dobi naslednji frame in tega obenem shrani v spomin
	virtual IplImage *GetLastFrame();//Dobi zadnji ze prebrani frame
	virtual int GetWidth(){ if(opened) return Width; }
	virtual int GetHeight(){ if(opened) return Height; }
	virtual int GetDepth(){ if(opened) return Depth; }
	virtual int GetChannels(){ if(opened) return Channels; }
	virtual int GetFps(){ if(opened) return Fps; }
};

#define MAX_CV_CAMERAS 20
class CameraSourceVideo: public CameraSource//Dela preko opencv metod za kamere
{
private:
	struct CvCapture *CameraCapture;
	int cam_id;//id kamere iz katere pobiramo video
	bool pause;
public:
	bool flip;
	bool swap_rgb;
public:
	void OpenVideoSoruce();
	void CloseVideoSource();
	void Pause();
	IplImage *GetFrame();//Dobi naslednji frame in tega obenem shrani v spomin
	//IplImage *GetLastFrame();//Dobi zadnji ze prebrani frame
	void SetCamId( int id );
	int GetCamId();
	void SetCameraCapture( CvCapture* lCameraCapture );
	void ExportVideoToFile( char* filename );

	~CameraSourceVideo();
	CameraSourceVideo( int LastFramesCount );
};

CameraSourceVideo **RetriveCVCameras();//Dobi "handlerje" za vse OpenCv kamere
void DestroyCVCameras( CameraSourceVideo** lCameraSourceVideo );//Klice delte na vse "handlerje"

class CameraSourceAVI: public CameraSource
{
private:
	char* filename;
public:
	/*void OpenVideoSource();
	void CloseVideoSource();
	void Pause();
	IplImage *GetFrame();
	IplImage *GetLastFrame();*/
};

#endif