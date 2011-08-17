#ifndef __LDITESTH__
#define __LDITESTH__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// wxwindows headers
#include "wx/wxprec.h"
#include "wx/statline.h"
#include "wx/minifram.h"
#include "wx/thread.h"
#include "wx/app.h"

#ifndef  WX_PRECOMP
	#include "wx/wx.h"
#endif //precompiled headers

//Our frames
#include "Gui/MainFrameDerived.h"
#include "WorkingThread.h"

//Start class of our application
class LDI_test : public wxApp
{
private:
	MainFrameDerived *cMainFrameDerived;
// protected methods
protected:
	bool OnInit( );
	int OnExit( );

	DECLARE_EVENT_TABLE()
};

#endif
