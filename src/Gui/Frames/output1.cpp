///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "output1.h"

///////////////////////////////////////////////////////////////////////////

Output1::Output1( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bMainSizer;
	bMainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Statistics:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bMainSizer->Add( m_staticText1, 0, wxALL, 5 );
	
	m_Grid = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_Grid->CreateGrid( 6, 11 );
	m_Grid->EnableEditing( false );
	m_Grid->EnableGridLines( true );
	m_Grid->EnableDragGridSize( false );
	m_Grid->SetMargins( 0, 0 );
	
	// Columns
	m_Grid->SetColSize( 0, 40 );
	m_Grid->SetColSize( 1, 40 );
	m_Grid->SetColSize( 2, 40 );
	m_Grid->SetColSize( 3, 40 );
	m_Grid->SetColSize( 4, 40 );
	m_Grid->SetColSize( 5, 40 );
	m_Grid->SetColSize( 6, 40 );
	m_Grid->SetColSize( 7, 40 );
	m_Grid->SetColSize( 8, 40 );
	m_Grid->SetColSize( 9, 40 );
	m_Grid->SetColSize( 10, 40 );
	m_Grid->EnableDragColMove( false );
	m_Grid->EnableDragColSize( false );
	m_Grid->SetColLabelSize( 15 );
	m_Grid->SetColLabelValue( 0, wxT("Mer") );
	m_Grid->SetColLabelValue( 1, wxT("CX") );
	m_Grid->SetColLabelValue( 2, wxT("CY") );
	m_Grid->SetColLabelValue( 3, wxT("AX") );
	m_Grid->SetColLabelValue( 4, wxT("AY") );
	m_Grid->SetColLabelValue( 5, wxT("MinX") );
	m_Grid->SetColLabelValue( 6, wxT("MaxX") );
	m_Grid->SetColLabelValue( 7, wxT("MinY") );
	m_Grid->SetColLabelValue( 8, wxT("MaxY") );
	m_Grid->SetColLabelValue( 9, wxT("StddX") );
	m_Grid->SetColLabelValue( 10, wxT("StddY") );
	m_Grid->SetColLabelAlignment( wxALIGN_LEFT, wxALIGN_CENTRE );
	
	// Rows
	m_Grid->SetRowSize( 0, 17 );
	m_Grid->SetRowSize( 1, 17 );
	m_Grid->SetRowSize( 2, 17 );
	m_Grid->SetRowSize( 3, 17 );
	m_Grid->SetRowSize( 4, 17 );
	m_Grid->SetRowSize( 5, 17 );
	m_Grid->EnableDragRowSize( false );
	m_Grid->SetRowLabelSize( 10 );
	m_Grid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_Grid->SetDefaultCellBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_Grid->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	bMainSizer->Add( m_Grid, 0, wxALL, 5 );
	
	this->SetSizer( bMainSizer );
	this->Layout();
}

Output1::~Output1()
{
}
