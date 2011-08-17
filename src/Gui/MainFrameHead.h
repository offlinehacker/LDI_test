#ifndef __MAINFRAMEHEADH__
#define __MAINFRAMEHEADH__

#include <wx/frame.h>

#include "../VideoProcessor.h"
#include "../VideoIOConfiguration.h"
#include "../WorkingThread.h"
#include "../Output.h"

class MainFrameHead: public wxFrame
{
protected:
	WorkingThread *cWorkingThread;
	VideoProcessorManager *cVideoProcessorManager;
	VideoIOConfiguration *cVideoIOConfiguration;
	CameraSourceManager *cCameraSourceManager;
	OutputManager *cOutputManager;

public:
	MainFrameHead( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style );
	~MainFrameHead();

	VideoProcessorManager *GetVideoProcessorManager(){ return cVideoProcessorManager; }
	VideoIOConfiguration* GetVideoIOConfiguration(){ return cVideoIOConfiguration; }
	CameraSourceManager* GetCameraSourceManager(){ return cCameraSourceManager; }
	OutputManager* GetOutputManager(){ return cOutputManager; }

};

#endif