///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __noname__
#define __noname__

#include <wx/string.h>
#include <wx/choice.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
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
		wxButton* m_OK;
		wxButton* m_CANCEL;
	
	public:
		CameraSelector( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Select your camera ..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 304,150 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CameraSelector();
	
};

#endif //__noname__
