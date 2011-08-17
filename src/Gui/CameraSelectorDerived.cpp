#include "CameraSelectorDerived.h"

CameraSelectorDerived::CameraSelectorDerived( CameraSourceManager* lCameraSourceManager, wxWindow* parent )
:
CameraSelector( parent )
{
	char CamInfo[200];
	cCameraSourceManager= lCameraSourceManager;
	if(!cCameraSourceManager->AreEnumerated())
		if(!cCameraSourceManager->EnumerateAllCameras())
			return;

	for( int x=0; x<cCameraSourceManager->GetCameraCount(); x++ )
	{
		sprintf( CamInfo, "Cam%d %s (W:%d, H:%d, D:%d, F:%dfps)", x, cCameraSourceManager->GetCameraById(x)->GetCameraName(), cCameraSourceManager->GetCameraById(x)->GetWidth(), cCameraSourceManager->GetCameraById(x)->GetHeight(), cCameraSourceManager->GetCameraById(x)->GetDepth(),cCameraSourceManager->GetCameraById(x)->GetFps()); 
		m_choice1->Append(wxString::FromAscii(CamInfo));
	}
}

void CameraSelectorDerived::OnCameraSelectorInit( wxInitDialogEvent& event )
{
	// TODO: Implement OnCameraSelectorInit
}

void CameraSelectorDerived::OnFlip( wxCommandEvent& event )
{
	cCameraSourceManager->SetFlip();
}

void CameraSelectorDerived::OnSwap( wxCommandEvent& event )
{
	cCameraSourceManager->SetSwap();
}

void CameraSelectorDerived::OnMore( wxCommandEvent& event )
{
	char filename[300];

	CameraSource *CurrentCamera= cCameraSourceManager->GetCameraById(m_choice1->GetCurrentSelection());
	if(!CurrentCamera)
		return;
	if(CurrentCamera->GetCamType()==CAM_TYPE_FILE)
	{
		wxFileDialog* lFileDialog= new wxFileDialog( this );
		lFileDialog->ShowModal();

		printf("dir: %s", (const char*)(lFileDialog->GetPath().ToAscii()) );
		sprintf( filename, "%s", (const char*)(lFileDialog->GetPath().ToAscii()) );
		CurrentCamera->SetFilename( filename );
	}
}

void CameraSelectorDerived::OnOK( wxCommandEvent& event )
{
	cCameraSourceManager->SelectCamera(m_choice1->GetCurrentSelection());
	Close();
}

void CameraSelectorDerived::OnCancel( wxCommandEvent& event )
{
	Close();
}
