////////////////////////////////////////////////////////////////////
// Name:		camera view header
// File:		camview.h
// Purpose:		interface for the CCamView class.
//
// Created by:	Larry Lart on 06-Jul-2006
// Updated by:	
//
////////////////////////////////////////////////////////////////////

#ifndef _CCAMVIEW_H
#define _CCAMVIEW_H

#include "cv.h"
#include "highgui.h"
#include "cvaux.h"

#include "wx/wxprec.h"

#include "../OpenCv/Conversions.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

// external classes
class CCamera;

class CCamView : public wxWindow
{
public: 
	CCamView( wxWindow *frame, wxWindowID id,const wxPoint& pos, const wxSize& size, long style );

// Operations
public:


// Implementation
public:
	virtual ~CCamView( );
	bool IsCaptureEnabled( );
	void CheckUpdate( );

	// Draw method
	void DrawCam( IplImage* pImg );
	void Draw( wxDC& dc );

// Protected data
protected:
	wxBitmap	m_pBitmap;

  	bool	m_bDrawing;
	bool	m_bNewImage;

	int m_nWidth;
	int m_nHeight;

// private methods
private:
	void	OnPaint(wxPaintEvent& event);
	void	OnSize( wxSizeEvent& even );

// protected data
protected:

	DECLARE_EVENT_TABLE()
};

#endif
