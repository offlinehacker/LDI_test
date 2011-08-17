///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "CameraSelector.h"

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
	m_choice1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	m_choice1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVEBORDER ) );
	
	MainSizerSub->Add( m_choice1, 0, wxALL|wxEXPAND, 5 );
	
	MainSizer->Add( MainSizerSub, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* OptionsSizer;
	OptionsSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Options:") ), wxHORIZONTAL );
	
	m_Flip = new wxCheckBox( this, wxID_ANY, wxT("Flip picture"), wxDefaultPosition, wxDefaultSize, 0 );
	
	OptionsSizer->Add( m_Flip, 0, wxALL, 5 );
	
	m_SwapRGB = new wxCheckBox( this, wxID_ANY, wxT("Swap RGB"), wxDefaultPosition, wxDefaultSize, 0 );
	
	OptionsSizer->Add( m_SwapRGB, 0, wxALL, 5 );
	
	m_More = new wxButton( this, wxID_ANY, wxT("..."), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	OptionsSizer->Add( m_More, 0, wxALL, 5 );
	
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
	
	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( CameraSelector::OnCameraSelectorInit ) );
	m_Flip->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CameraSelector::OnFlip ), NULL, this );
	m_SwapRGB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CameraSelector::OnSwap ), NULL, this );
	m_More->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CameraSelector::OnMore ), NULL, this );
	m_OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CameraSelector::OnOK ), NULL, this );
	m_CANCEL->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CameraSelector::OnCancel ), NULL, this );
}

CameraSelector::~CameraSelector()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( CameraSelector::OnCameraSelectorInit ) );
	m_Flip->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CameraSelector::OnFlip ), NULL, this );
	m_SwapRGB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( CameraSelector::OnSwap ), NULL, this );
	m_More->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CameraSelector::OnMore ), NULL, this );
	m_OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CameraSelector::OnOK ), NULL, this );
	m_CANCEL->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CameraSelector::OnCancel ), NULL, this );
}
