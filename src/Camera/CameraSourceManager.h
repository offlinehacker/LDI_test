#ifndef __CAMERASOURCEMANAGERH__
#define __CAMERASOURCEMANAGERH__

#include <stdio.h>
#include <stdlib.h>

#include "CameraSource.h"
#include "OpenCvCamera/OpenCvCamera.h"

#define MAX_CAMERA_ENUMERATORS 5
#define MAX_CAMERA_COUNT 20

#define CAMERA_ENUMERATOR_1 CvCameraEnumerator
#define CAMERA_ENUMERATOR_2 CvVideoFileEnumerator

//!Used only for one video source
class CameraSourceManager
{
private:
	//All cameras in all enumerators
	CameraSource *AllCameras[MAX_CAMERA_COUNT];
	//Currently selected camera
	CameraSource *SelectedCamera;
	//Camera enumerators
	CameraEnumerator *CameraEnumerators[MAX_CAMERA_ENUMERATORS];
	//Count of enumerators
	int CameraEnumeratorsCount;
	//Count of all cameras
	int CameraCount;
	//Leave camera opened if it is switched
	bool LeaveOpened;
	//Are cameras already enumerated
	bool Enumerated;

	//Options for pre-processor
	//Flip our image frames
	bool FlipImage;
	//Swap colors in frames
	bool SwapColors;
	bool Postopen;

public:
	//Adds camera enumerator
	bool AddCameraEnumerator( CameraEnumerator *lCameraEnumerator );
	//Enumerates thru all cameras
	bool EnumerateAllCameras();
	//Call this function to save camera we are currently using to Selected camera
	void SelectCamera( int id );
	//Gets currently selected camera
	CameraSource* GetSelectedCamera(){ return SelectedCamera; }
	//Searces camera by its name
	int GetCameraIdByName( char* CameraName );
	//Gets camera count
	int GetCameraCount(){ return CameraCount; }
	CameraSource* GetCameraById( int id );
	//Are cameras already enumerated
	bool AreEnumerated(){ return Enumerated; }
	//Gets next frame from currently selected camera
	IplImage* GetNextFrame();
	//Gets next frame from currently selected camera and pre-processes it
	IplImage* GetNextFrameAndPreProcess();
	//Sets preprocessor option to flip our image
	void SetFlip();
	//Sets preprocessor option to swap our image
	void SetSwap();
	//Opens video source currently selected
	bool OpenVideoSource();
	//Closes video source currently selected
	void CloseVideoSource();

	CameraSourceManager();
	//We delete all camera providers.
	~CameraSourceManager();
};

#endif