#include "LDI_test.h"

//Adds a new application
IMPLEMENT_APP(LDI_test)

//Initialization of events
BEGIN_EVENT_TABLE(LDI_test, wxApp)
END_EVENT_TABLE()

//Where application starts
bool LDI_test::OnInit()
{
	//We create a new main frame
	cMainFrameDerived= new MainFrameDerived(NULL);

	//Show the frame
	cMainFrameDerived->Show(TRUE);
	SetTopWindow(cMainFrameDerived);

	return true;
}

//Where application exits
int LDI_test::OnExit()
{
	return wxApp::OnExit();
}