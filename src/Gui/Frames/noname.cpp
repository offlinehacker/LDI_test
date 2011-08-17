///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

CameraSelector::CameraSelector( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* MainSizerSub;
	MainSizerSub = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Camera source:") ), wxVERTICAL );
	
	wxArrayString m_choice1Choices;
	m_choice1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	m_choice1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVEBORDER ) );
	
	MainSizerSub->Add( m_choice1, 0, wxALL|wxEXPAND, 5 );
	
	MainSizer->Add( MainSizerSub, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* OptionsSizer;
	OptionsSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Options:") ), wxVERTICAL );
	
	MainSizer->Add( OptionsSizer, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 1, 2, 0, 0 );
	
	m_OK = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_OK, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_CANCEL = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_CANCEL, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	MainSizer->Add( gSizer1, 1, wxEXPAND, 5 );
	
	this->SetSizer( MainSizer );
	this->Layout();
}

CameraSelector::~CameraSelector()
{
	return;
}
