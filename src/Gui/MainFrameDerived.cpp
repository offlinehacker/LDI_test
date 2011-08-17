#include "MainFrameDerived.h"

MainFrameDerived::MainFrameDerived( wxWindow* parent )
:
MainFrame( parent )
{
	cVideoIOConfiguration->AddVideoOutput( VideoFrame1 );
	cVideoIOConfiguration->AddVideoOutput( VideoFrame2 );
	cVideoIOConfiguration->AddVideoOutput( VideoFrame3 );
	cVideoIOConfiguration->AddVideoOutput( VideoFrame4 );

	m_VideoSelector1->Append(wxString::FromAscii("In"));
	m_VideoSelector1->Append(wxString::FromAscii("Out"));
	m_VideoSelector2->Append(wxString::FromAscii("In"));
	m_VideoSelector2->Append(wxString::FromAscii("Out"));
	m_VideoSelector3->Append(wxString::FromAscii("In"));
	m_VideoSelector3->Append(wxString::FromAscii("Out"));
	m_VideoSelector4->Append(wxString::FromAscii("In"));
	m_VideoSelector4->Append(wxString::FromAscii("Out"));

	for( int x=0; x<cVideoProcessorManager->GetVideoProcessorCount(); x++ )
	{
		m_VideoSelector1->Append( wxString::FromAscii(cVideoProcessorManager->GetVideoProcessor(x)->GetVideoProcessorName()) );
		m_VideoSelector2->Append( wxString::FromAscii(cVideoProcessorManager->GetVideoProcessor(x)->GetVideoProcessorName()) );
		m_VideoSelector3->Append( wxString::FromAscii(cVideoProcessorManager->GetVideoProcessor(x)->GetVideoProcessorName()) );
		m_VideoSelector4->Append( wxString::FromAscii(cVideoProcessorManager->GetVideoProcessor(x)->GetVideoProcessorName()) );
	}
}

void MainFrameDerived::OnVideoSelector1Change( wxCommandEvent& event )
{
	cVideoIOConfiguration->SelectVideoOutputForName((char*)m_VideoSelector1->GetValue().c_str(),0);
}

void MainFrameDerived::OnVideoSelector2Change( wxCommandEvent& event )
{
	cVideoIOConfiguration->SelectVideoOutputForName((char*)m_VideoSelector2->GetValue().c_str(),1);
}

void MainFrameDerived::OnVideoSelector3Change( wxCommandEvent& event )
{
	cVideoIOConfiguration->SelectVideoOutputForName((char*)m_VideoSelector3->GetValue().c_str(),2);
}

void MainFrameDerived::OnVideoSelector4Change( wxCommandEvent& event )
{
	cVideoIOConfiguration->SelectVideoOutputForName((char*)m_VideoSelector4->GetValue().c_str(),3);
}

void MainFrameDerived::LoadOptionsClicked( wxCommandEvent& event )
{
	// TODO: Implement LoadOptionsClicked
}

void MainFrameDerived::SaveOptionsClicked( wxCommandEvent& event )
{
	// TODO: Implement SaveOptionsClicked
}

void MainFrameDerived::ExitClicked( wxCommandEvent& event )
{
	wxExit();
}

void MainFrameDerived::SelectCameraSourceClicked( wxCommandEvent& event )
{
	CameraSelectorDerived lCameraSelectorDerived(cCameraSourceManager, this);
	lCameraSelectorDerived.ShowModal();
}

void MainFrameDerived::StartCameraCaptureClicked( wxCommandEvent& event )
{
	cWorkingThread->OpenVideoSource();
}

void MainFrameDerived::StopCameraCaptureClicked( wxCommandEvent& event )
{
	cWorkingThread->CloseVideoSource();
}

void MainFrameDerived::StartVideoProcessingClicked( wxCommandEvent& event )
{
	cWorkingThread->StartVideoProcessing();
}

void MainFrameDerived::StopVideoProcessingClicked( wxCommandEvent& event )
{
	cWorkingThread->StopVideoProcessing();
}

void MainFrameDerived::StartVideoRecordingClicked( wxCommandEvent& event )
{
	char filename[300];

	wxFileDialog* lFileDialog= new wxFileDialog( this );
	lFileDialog->ShowModal();

	sprintf( filename, "%s\\%s", (char*)(lFileDialog->GetDirectory().c_str()), (char*)(lFileDialog->GetFilename().c_str()) );

	cWorkingThread->StartVideoRecording( filename );
}

void MainFrameDerived::StopVideoRecordingClicked( wxCommandEvent& event )
{
	cWorkingThread->StopVideoRecording();
}

void MainFrameDerived::OpenDebugLogClicked( wxCommandEvent& event )
{
	// TODO: Implement OpenDebugLogClicked
}

void MainFrameDerived::HelpClicked( wxCommandEvent& event )
{
	// TODO: Implement HelpClicked
}

void MainFrameDerived::AboutClicked( wxCommandEvent& event )
{
	// TODO: Implement AboutClicked
}
