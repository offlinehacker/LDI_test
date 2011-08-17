#include "uEye.h"

#include "cv.h"
#include "highgui.h"

class IDSCamera: public CameraSource
{
private:
	char* config_file;

	HIDS m_hCam;                // handle to camera
	HWND m_hWndDisplay;            // handle to diplay window
	int    m_Ret;                    // return value of uEye  SDK functions
	int    m_nColorMode;            // Y8/RGB16/RGB24/REG32
	const int    m_nBitsPerPixel=8;        // number of bits needed store one pixel
    int    m_nSizeX;            // width of video 
	int    m_nSizeY;            // height of video
	int    m_lMemoryId;            // grabber memory - buffer   ID
	char* m_pcImageMemory;        // grabber memory - pointer to buffer
	const int m_nRenderMode = IS_RENDER_FIT_TO_WINDOW;    //render  mode

public:
	//Initializes IDS camera
	IDSCamera( char *config_file );
	~IDSCamera();

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