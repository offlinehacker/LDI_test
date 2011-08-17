///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "frame_setup.h"

#include "MainFrame.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : MAINFRAMEHEAD_CLASS( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 1024,768 ), wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );
	
	wxGridSizer* gMainSizer;
	gMainSizer = new wxGridSizer( 2, 2, 0, 0 );
	
	wxStaticBoxSizer* sbSubOptionsSizer;
	sbSubOptionsSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Options") ), wxVERTICAL );
	
	wxGridSizer* gOptionsSizer;
	gOptionsSizer = new wxGridSizer( 3, 2, 0, 0 );
	
	wxStaticBoxSizer* Options1Sizer;
	Options1Sizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Contours") ), wxVERTICAL );
	
	m_Options1 = new OPTIONS1_CLASS( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Options1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVEBORDER ) );
	
	Options1Sizer->Add( m_Options1, 1, wxEXPAND | wxALL, 5 );
	
	gOptionsSizer->Add( Options1Sizer, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* Options2Sizer;
	Options2Sizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Options 2") ), wxVERTICAL );
	
	m_Options2 = new OPTIONS2_CLASS( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Options2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVEBORDER ) );
	
	Options2Sizer->Add( m_Options2, 1, wxEXPAND | wxALL, 5 );
	
	gOptionsSizer->Add( Options2Sizer, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* Options3Sizer;
	Options3Sizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Options 3") ), wxVERTICAL );
	
	m_Options3 = new OPTIONS3_CLASS( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Options3->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVEBORDER ) );
	
	Options3Sizer->Add( m_Options3, 1, wxEXPAND | wxALL, 5 );
	
	gOptionsSizer->Add( Options3Sizer, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* Options4Sizer;
	Options4Sizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Options 4") ), wxVERTICAL );
	
	m_Options4 = new OPTIONS4_CLASS( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Options4->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVEBORDER ) );
	
	Options4Sizer->Add( m_Options4, 1, wxEXPAND | wxALL, 5 );
	
	gOptionsSizer->Add( Options4Sizer, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* Options5Sizer;
	Options5Sizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Options 5") ), wxVERTICAL );
	
	m_Options5 = new OPTIONS5_CLASS( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Options5->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVEBORDER ) );
	
	Options5Sizer->Add( m_Options5, 1, wxEXPAND | wxALL, 5 );
	
	gOptionsSizer->Add( Options5Sizer, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* Options6Sizer;
	Options6Sizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Options 6") ), wxVERTICAL );
	
	m_Options6 = new OPTIONS6_CLASS( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Options6->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVEBORDER ) );
	
	Options6Sizer->Add( m_Options6, 1, wxEXPAND | wxALL, 5 );
	
	gOptionsSizer->Add( Options6Sizer, 1, wxEXPAND, 5 );
	
	sbSubOptionsSizer->Add( gOptionsSizer, 1, wxEXPAND, 5 );
	
	gMainSizer->Add( sbSubOptionsSizer, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSubVideoSizer;
	sbSubVideoSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Video") ), wxVERTICAL );
	
	wxGridSizer* gVideoSizer;
	gVideoSizer = new wxGridSizer( 2, 2, 0, 0 );
	
	gVideoSizer->SetMinSize( wxSize( -1,480 ) ); 
	wxBoxSizer* VideoFrame1Sizer;
	VideoFrame1Sizer = new wxBoxSizer( wxVERTICAL );
	
	VideoFrame1 = new CAMVIEW_CLASS( this, wxID_ANY, wxDefaultPosition, wxSize( -1,128 ), wxTAB_TRAVERSAL );
	VideoFrame1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	
	VideoFrame1Sizer->Add( VideoFrame1, 0, wxEXPAND | wxALL, 5 );
	
	m_VideoSelector1 = new wxComboBox( this, wxID_ANY, wxT("Select video source ..."), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_VideoSelector1->SetMinSize( wxSize( 150,-1 ) );
	
	VideoFrame1Sizer->Add( m_VideoSelector1, 0, wxALL, 5 );
	
	gVideoSizer->Add( VideoFrame1Sizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* VideoFrame2Sizer;
	VideoFrame2Sizer = new wxBoxSizer( wxVERTICAL );
	
	VideoFrame2 = new CAMVIEW_CLASS( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	VideoFrame2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	
	VideoFrame2Sizer->Add( VideoFrame2, 1, wxEXPAND | wxALL, 5 );
	
	m_VideoSelector2 = new wxComboBox( this, wxID_ANY, wxT("Select video source ..."), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_VideoSelector2->SetMinSize( wxSize( 150,-1 ) );
	
	VideoFrame2Sizer->Add( m_VideoSelector2, 0, wxALL, 5 );
	
	gVideoSizer->Add( VideoFrame2Sizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* VideoFrame3Sizer;
	VideoFrame3Sizer = new wxBoxSizer( wxVERTICAL );
	
	VideoFrame3 = new CAMVIEW_CLASS( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	VideoFrame3->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	
	VideoFrame3Sizer->Add( VideoFrame3, 1, wxEXPAND | wxALL, 5 );
	
	m_VideoSelector3 = new wxComboBox( this, wxID_ANY, wxT("Select video source ..."), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_VideoSelector3->SetMinSize( wxSize( 150,-1 ) );
	
	VideoFrame3Sizer->Add( m_VideoSelector3, 0, wxALL, 5 );
	
	gVideoSizer->Add( VideoFrame3Sizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* VideoFrame4Sizer;
	VideoFrame4Sizer = new wxBoxSizer( wxVERTICAL );
	
	VideoFrame4 = new CAMVIEW_CLASS( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	VideoFrame4->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	
	VideoFrame4Sizer->Add( VideoFrame4, 1, wxEXPAND | wxALL, 5 );
	
	m_VideoSelector4 = new wxComboBox( this, wxID_ANY, wxT("Select video source ..."), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_VideoSelector4->SetMinSize( wxSize( 150,-1 ) );
	
	VideoFrame4Sizer->Add( m_VideoSelector4, 0, wxALL, 5 );
	
	gVideoSizer->Add( VideoFrame4Sizer, 1, wxEXPAND, 5 );
	
	sbSubVideoSizer->Add( gVideoSizer, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbOutputSizer;
	sbOutputSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Output data") ), wxVERTICAL );
	
	m_Output1 = new OUTPUT1_CLASS( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Output1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	
	sbOutputSizer->Add( m_Output1, 1, wxEXPAND | wxALL, 5 );
	
	m_Output2 = new OUTPUT2_CLASS( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_Output2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	
	sbOutputSizer->Add( m_Output2, 1, wxEXPAND | wxALL, 5 );
	
	sbSubVideoSizer->Add( sbOutputSizer, 1, wxEXPAND, 5 );
	
	gMainSizer->Add( sbSubVideoSizer, 1, wxEXPAND, 5 );
	
	this->SetSizer( gMainSizer );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	m_menubar1 = new wxMenuBar( 0 );
	m_FileMenu = new wxMenu();
	wxMenuItem* m_LoadOptions;
	m_LoadOptions = new wxMenuItem( m_FileMenu, wxID_ANY, wxString( wxT("Load options...") ) , wxEmptyString, wxITEM_NORMAL );
	m_FileMenu->Append( m_LoadOptions );
	
	wxMenuItem* m_SaveOptions;
	m_SaveOptions = new wxMenuItem( m_FileMenu, wxID_ANY, wxString( wxT("Save options...") ) , wxEmptyString, wxITEM_NORMAL );
	m_FileMenu->Append( m_SaveOptions );
	
	wxMenuItem* m_Exit;
	m_Exit = new wxMenuItem( m_FileMenu, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_FileMenu->Append( m_Exit );
	
	m_menubar1->Append( m_FileMenu, wxT("File") );
	
	m_CameraMenu = new wxMenu();
	wxMenuItem* m_SelectCamSource;
	m_SelectCamSource = new wxMenuItem( m_CameraMenu, wxID_ANY, wxString( wxT("Select camera source ...") ) , wxEmptyString, wxITEM_NORMAL );
	m_CameraMenu->Append( m_SelectCamSource );
	
	wxMenuItem* m_StartCameraCapture;
	m_StartCameraCapture = new wxMenuItem( m_CameraMenu, wxID_ANY, wxString( wxT("Start camera capture") ) , wxEmptyString, wxITEM_NORMAL );
	m_CameraMenu->Append( m_StartCameraCapture );
	
	wxMenuItem* m_StopCameraCapture;
	m_StopCameraCapture = new wxMenuItem( m_CameraMenu, wxID_ANY, wxString( wxT("Stop camera capture") ) , wxEmptyString, wxITEM_NORMAL );
	m_CameraMenu->Append( m_StopCameraCapture );
	
	wxMenuItem* m_StartVideoProcessing;
	m_StartVideoProcessing = new wxMenuItem( m_CameraMenu, wxID_ANY, wxString( wxT("Start video processing") ) , wxEmptyString, wxITEM_NORMAL );
	m_CameraMenu->Append( m_StartVideoProcessing );
	
	wxMenuItem* m_StopVideoProcessing;
	m_StopVideoProcessing = new wxMenuItem( m_CameraMenu, wxID_ANY, wxString( wxT("Stop video processing") ) , wxEmptyString, wxITEM_NORMAL );
	m_CameraMenu->Append( m_StopVideoProcessing );
	
	wxMenuItem* m_StartVideoRecording;
	m_StartVideoRecording = new wxMenuItem( m_CameraMenu, wxID_ANY, wxString( wxT("Start video recording") ) , wxEmptyString, wxITEM_NORMAL );
	m_CameraMenu->Append( m_StartVideoRecording );
	
	wxMenuItem* m_StopVideoRecording;
	m_StopVideoRecording = new wxMenuItem( m_CameraMenu, wxID_ANY, wxString( wxT("Stop video recording") ) , wxEmptyString, wxITEM_NORMAL );
	m_CameraMenu->Append( m_StopVideoRecording );
	
	m_menubar1->Append( m_CameraMenu, wxT("Camera") );
	
	m_Debug = new wxMenu();
	wxMenuItem* m_OpenDebugLog;
	m_OpenDebugLog = new wxMenuItem( m_Debug, wxID_ANY, wxString( wxT("Open debug log ...") ) , wxEmptyString, wxITEM_NORMAL );
	m_Debug->Append( m_OpenDebugLog );
	
	m_menubar1->Append( m_Debug, wxT("Debug") );
	
	m_HelpMenu = new wxMenu();
	wxMenuItem* m_Help;
	m_Help = new wxMenuItem( m_HelpMenu, wxID_ANY, wxString( wxT("Help") ) , wxEmptyString, wxITEM_NORMAL );
	m_HelpMenu->Append( m_Help );
	
	wxMenuItem* m_About;
	m_About = new wxMenuItem( m_HelpMenu, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_HelpMenu->Append( m_About );
	
	m_menubar1->Append( m_HelpMenu, wxT("Help") );
	
	this->SetMenuBar( m_menubar1 );
	
	
	// Connect Events
	m_VideoSelector1->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnVideoSelector1Change ), NULL, this );
	m_VideoSelector2->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnVideoSelector2Change ), NULL, this );
	m_VideoSelector3->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnVideoSelector3Change ), NULL, this );
	m_VideoSelector4->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnVideoSelector4Change ), NULL, this );
	this->Connect( m_LoadOptions->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::LoadOptionsClicked ) );
	this->Connect( m_SaveOptions->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::SaveOptionsClicked ) );
	this->Connect( m_Exit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::ExitClicked ) );
	this->Connect( m_SelectCamSource->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::SelectCameraSourceClicked ) );
	this->Connect( m_StartCameraCapture->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::StartCameraCaptureClicked ) );
	this->Connect( m_StopCameraCapture->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::StopCameraCaptureClicked ) );
	this->Connect( m_StartVideoProcessing->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::StartVideoProcessingClicked ) );
	this->Connect( m_StopVideoProcessing->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::StopVideoProcessingClicked ) );
	this->Connect( m_StartVideoRecording->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::StartVideoRecordingClicked ) );
	this->Connect( m_StopVideoRecording->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::StopVideoRecordingClicked ) );
	this->Connect( m_OpenDebugLog->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OpenDebugLogClicked ) );
	this->Connect( m_Help->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::HelpClicked ) );
	this->Connect( m_About->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::AboutClicked ) );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_VideoSelector1->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnVideoSelector1Change ), NULL, this );
	m_VideoSelector2->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnVideoSelector2Change ), NULL, this );
	m_VideoSelector3->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnVideoSelector3Change ), NULL, this );
	m_VideoSelector4->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrame::OnVideoSelector4Change ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::LoadOptionsClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::SaveOptionsClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::ExitClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::SelectCameraSourceClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::StartCameraCaptureClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::StopCameraCaptureClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::StartVideoProcessingClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::StopVideoProcessingClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::StartVideoRecordingClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::StopVideoRecordingClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OpenDebugLogClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::HelpClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::AboutClicked ) );
}
