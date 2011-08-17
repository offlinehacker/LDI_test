///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "output2.h"

///////////////////////////////////////////////////////////////////////////

Output2::Output2( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bMainSizer;
	bMainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Contours:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bMainSizer->Add( m_staticText1, 0, wxALL, 5 );
	
	m_grid1 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_grid1->CreateGrid( 6, 4 );
	m_grid1->EnableEditing( false );
	m_grid1->EnableGridLines( true );
	m_grid1->EnableDragGridSize( false );
	m_grid1->SetMargins( 0, 0 );
	
	// Columns
	m_grid1->SetColSize( 0, 40 );
	m_grid1->SetColSize( 1, 40 );
	m_grid1->SetColSize( 2, 40 );
	m_grid1->SetColSize( 3, 40 );
	m_grid1->EnableDragColMove( false );
	m_grid1->EnableDragColSize( false );
	m_grid1->SetColLabelSize( 15 );
	m_grid1->SetColLabelValue( 0, wxT("Obj") );
	m_grid1->SetColLabelValue( 1, wxT("Mer") );
	m_grid1->SetColLabelValue( 2, wxT("CX") );
	m_grid1->SetColLabelValue( 3, wxT("CY") );
	m_grid1->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_grid1->SetRowSize( 0, 17 );
	m_grid1->SetRowSize( 1, 17 );
	m_grid1->SetRowSize( 2, 17 );
	m_grid1->SetRowSize( 3, 17 );
	m_grid1->SetRowSize( 4, 17 );
	m_grid1->SetRowSize( 5, 17 );
	m_grid1->EnableDragRowSize( false );
	m_grid1->SetRowLabelSize( 10 );
	m_grid1->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_grid1->SetDefaultCellBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_grid1->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bMainSizer->Add( m_grid1, 0, wxALL, 5 );
	
	this->SetSizer( bMainSizer );
	this->Layout();
}

Output2::~Output2()
{
}
