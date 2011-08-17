///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CameraSelector__
#define __CameraSelector__

#include <wx/string.h>
#include <wx/choice.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class CameraSelector
///////////////////////////////////////////////////////////////////////////////
class CameraSelector : public wxDialog 
{
	private:
	
	protected:
		wxChoice* m_choice1;
		wxCheckBox* m_Flip;
		wxCheckBox* m_SwapRGB;
		wxButton* m_More;
		wxButton* m_OK;
		wxButton* m_CANCEL;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCameraSelectorInit( wxInitDialogEvent& event ){ event.Skip(); }
		virtual void OnFlip( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSwap( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnMore( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		CameraSelector( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Select your camera ..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 304,200 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CameraSelector();
	
};

#endif //__CameraSelector__
