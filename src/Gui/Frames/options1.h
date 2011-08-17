///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __options1__
#define __options1__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/slider.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Options1
///////////////////////////////////////////////////////////////////////////////
class Options1 : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxSlider* m_Treshold;
		wxButton* m_ResetStatistics;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTreshold( wxScrollEvent& event ){ event.Skip(); }
		virtual void OnResetStatistics( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		Options1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 240,230 ), long style = wxTAB_TRAVERSAL );
		~Options1();
	
};

#endif //__options1__
