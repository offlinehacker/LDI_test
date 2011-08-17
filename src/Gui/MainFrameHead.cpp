#include "MainFrameHead.h"

MainFrameHead::MainFrameHead( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style )  : wxFrame( parent, id, title, pos, size, style )
{
	cVideoProcessorManager= new VideoProcessorManager();//We inititalize new Video processor manager where gui instances will register video processors
	cVideoIOConfiguration= new VideoIOConfiguration();
	cCameraSourceManager= new CameraSourceManager();
	cOutputManager= new OutputManager();

	cWorkingThread= new WorkingThread(cVideoProcessorManager, cCameraSourceManager, cVideoIOConfiguration, cOutputManager );

	if ( cWorkingThread->Create() != wxTHREAD_NO_ERROR )
	{
		wxExit();
	}

	if ( cWorkingThread->Run() != wxTHREAD_NO_ERROR )
	{
		wxExit();
	} 
}

MainFrameHead::~MainFrameHead()
{
	//First we have to stop our working thread
	cWorkingThread->StopThread();
	cWorkingThread->Delete();
	delete(cCameraSourceManager);
	delete(cOutputManager);
	delete(cVideoIOConfiguration);
	delete(cVideoProcessorManager);
}