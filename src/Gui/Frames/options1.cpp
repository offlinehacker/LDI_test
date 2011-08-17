///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "options1.h"

///////////////////////////////////////////////////////////////////////////

Options1::Options1( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* ContoursOptionsSizer;
	ContoursOptionsSizer = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Treshold:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	ContoursOptionsSizer->Add( m_staticText1, 0, wxALL, 5 );
	
	m_Treshold = new wxSlider( this, wxID_ANY, 50, 0, 255, wxDefaultPosition, wxSize(100,100), wxSL_HORIZONTAL );
	ContoursOptionsSizer->Add( m_Treshold, 0, wxALL, 5 );
	
	m_ResetStatistics = new wxButton( this, wxID_ANY, wxT("Reset statistics"), wxDefaultPosition, wxDefaultSize, 0 );
	ContoursOptionsSizer->Add( m_ResetStatistics, 0, wxALL, 5 );
	
	this->SetSizer( ContoursOptionsSizer );
	this->Layout();
	
	// Connect Events
	m_Treshold->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_ResetStatistics->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Options1::OnResetStatistics ), NULL, this );
}

Options1::~Options1()
{
	// Disconnect Events
	m_Treshold->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_Treshold->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Options1::OnTreshold ), NULL, this );
	m_ResetStatistics->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Options1::OnResetStatistics ), NULL, this );
}
