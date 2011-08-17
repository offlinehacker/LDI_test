#include "IDSCamera.h"

//Gets camera name
char* IDSCamera::GetCameraName()
{
}

//For checking if camera exists and to get some of the camera parameters
bool IDSCamera::TestCamera()
{
}

//Open our camera
bool IDSCamera::OpenCamera()
{
	if (m_hCam!=0)
	{
        //free old image mem.
        is_FreeImageMem(m_hCam,m_pcImageMemory,m_lMemoryId);
        is_ExitCamera(m_hCam);
    }

    // init camera
    m_hCam = (HIDS) 0;    // open next camera
    m_Ret = is_InitCamera(&m_hCam,NULL);    // init camera
    
    if( m_Ret == IS_SUCCESS ){    
        // retrieve original image size
        SENSORINFO sInfo;
        is_GetSensorInfo(m_hCam,&sInfo);
        m_nSizeX = sInfo.nMaxWidth;
        m_nSizeY = sInfo.nMaxHeight;

        // setup the color depth to the current windows setting
        //is_GetColorDepth(m_hCam,&m_nBitsPerPixel,&m_nColorMode);
        is_SetColorMode(m_hCam, IS_SET_CM_Y8);

        //printf("m_nBitsPerPixel=%i  m_nColorMode=%i\n",m_nBitsPerPixel,IS_SET_CM_Y8);

        // memory initialization
        is_AllocImageMem(m_hCam, m_nSizeX, m_nSizeY, m_nBitsPerPixel, &m_pcImageMemory, &m_lMemoryId);
        //set memory active
        is_SetImageMem( m_hCam, m_pcImageMemory,m_lMemoryId ); 
        // display initialization
        is_SetImageSize( m_hCam, m_nSizeX, m_nSizeY );
        is_SetDisplayMode( m_hCam, IS_SET_DM_DIB);
  // Reinit with slower frame rate for testing on vmWare with USB 1.1        
      if( is_LoadParameters( m_hCam, config_file ) == IS_SUCCESS )
		  {
			  // realloc image mem with actual sizes and depth.
			  is_FreeImageMem( m_hCam, m_pcImageMemory, m_lMemoryId );
			  m_nSizeX = is_SetImageSize( m_hCam, IS_GET_IMAGE_SIZE_X, 0 );
			  m_nSizeY = is_SetImageSize( m_hCam, IS_GET_IMAGE_SIZE_Y, 0 );
			  switch( is_SetColorMode( m_hCam, IS_GET_COLOR_MODE ) )
			  {
			  case IS_SET_CM_RGB32:
				  m_nBitsPerPixel = 32;
				  break;
			  case IS_SET_CM_RGB24:
				  m_nBitsPerPixel = 24;
				  break;
			  case IS_SET_CM_RGB16:
			  case IS_SET_CM_UYVY:
				  m_nBitsPerPixel = 16;
				  break;
			  case IS_SET_CM_RGB15:
				  m_nBitsPerPixel = 15;
				  break;
			  case IS_SET_CM_Y8:
			  case IS_SET_CM_RGB8:
			  case IS_SET_CM_BAYER:
			  default:
				  m_nBitsPerPixel = 8;
				  break;
			  }

			  // memory initialization
			  is_AllocImageMem( m_hCam,
							  m_nSizeX,
							  m_nSizeY,
							  m_nBitsPerPixel,
							  &m_pcImageMemory,
							  &m_lMemoryId);
			  is_SetImageMem(m_hCam, m_pcImageMemory, m_lMemoryId );	// set memory active

			  // display initialization
			  is_SetImageSize(m_hCam, m_nSizeX, m_nSizeY );
		  }
    }
  return true;
}

//Close our camera
void IDSCamera::CloseCamera()
{
}

//Get next frame from camera
IplImage* IDSCamera::GetNextFrame()
{
}

//Initializes IDS camera
IDSCamera::IDSCamera( char *config_file )
{
}

IDSCamera::~IDSCamera()
{
}