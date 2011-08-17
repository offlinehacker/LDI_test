///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MainFrame__
#define __MainFrame__

class CAMVIEW_CLASS;
class MAINFRAMEHEAD_CLASS;
class OPTIONS1_CLASS;
class OPTIONS2_CLASS;
class OPTIONS3_CLASS;
class OPTIONS4_CLASS;
class OPTIONS5_CLASS;
class OPTIONS6_CLASS;
class OUTPUT1_CLASS;
class OUTPUT2_CLASS;

#include "frame_setup.h"
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/combobox.h>
#include <wx/statusbr.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public MAINFRAMEHEAD_CLASS
{
	private:
	
	protected:
		OPTIONS1_CLASS* m_Options1;
		OPTIONS2_CLASS* m_Options2;
		OPTIONS3_CLASS* m_Options3;
		OPTIONS4_CLASS* m_Options4;
		OPTIONS5_CLASS* m_Options5;
		OPTIONS6_CLASS* m_Options6;
		CAMVIEW_CLASS* VideoFrame1;
		wxComboBox* m_VideoSelector1;
		CAMVIEW_CLASS* VideoFrame2;
		wxComboBox* m_VideoSelector2;
		CAMVIEW_CLASS* VideoFrame3;
		wxComboBox* m_VideoSelector3;
		CAMVIEW_CLASS* VideoFrame4;
		wxComboBox* m_VideoSelector4;
		OUTPUT1_CLASS* m_Output1;
		OUTPUT2_CLASS* m_Output2;
		wxStatusBar* m_statusBar;
		wxMenuBar* m_menubar1;
		wxMenu* m_FileMenu;
		wxMenu* m_CameraMenu;
		wxMenu* m_Debug;
		wxMenu* m_HelpMenu;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnVideoSelector1Change( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnVideoSelector2Change( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnVideoSelector3Change( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnVideoSelector4Change( wxCommandEvent& event ){ event.Skip(); }
		virtual void LoadOptionsClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void SaveOptionsClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void ExitClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void SelectCameraSourceClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void StartCameraCaptureClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void StopCameraCaptureClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void StartVideoProcessingClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void StopVideoProcessingClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void StartVideoRecordingClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void StopVideoRecordingClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void OpenDebugLogClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void HelpClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void AboutClicked( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("LDI_test"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1024,768 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MainFrame();
	
};

#endif //__MainFrame__
