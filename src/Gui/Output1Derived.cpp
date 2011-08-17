#include "Output1Derived.h"

#include "Frames/MainFrame.h"

Output1Derived::Output1Derived( wxWindow* parent )
:
Output1( parent )
{
}

Output1Derived::Output1Derived( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : Output1( parent )
{
	MainFrame *tMainFrame= (MainFrame*)parent;
	ContoursProcessor *tContoursProcessor= (ContoursProcessor*)tMainFrame->GetVideoProcessorManager()->GetVideoProcessorByName("contours");
	if(!tContoursProcessor)
		return;
	cOutputStatistics= new OutputStatistics(m_Grid, tContoursProcessor );

	tMainFrame->GetOutputManager()->AddOutput( cOutputStatistics );
}

bool OutputStatistics::DisplayOutputData()
{
	Grid->ClearGrid();

	T_MEAS_RESULTS_REC *ContourResult;
	for( int x=0; x<cContoursProcessor->GetResults()->total; x++ )
	{
		ContourResult = (T_MEAS_RESULTS_REC *) cvGetSeqElem(cContoursProcessor->GetStatistics(),x);
		if(!ContourResult)
			continue;

		wxString Area= wxString::Format(wxT("%d"),(int)(ContourResult->Area/cContoursProcessor->GetMeasurementImageCount()));
		wxString CenterX= wxString::Format(wxT("%d"),(int)(ContourResult->Center.x/cContoursProcessor->GetMeasurementImageCount()));
		wxString CenterY= wxString::Format(wxT("%d"),(int)(ContourResult->Center.y/cContoursProcessor->GetMeasurementImageCount()));
		wxString MinX= wxString::Format(wxT("%d"),(int)ContourResult->Min.x);
		wxString MinY= wxString::Format(wxT("%d"),(int)ContourResult->Min.y);
		wxString MaxX= wxString::Format(wxT("%d"),(int)ContourResult->Max.x);
		wxString MaxY= wxString::Format(wxT("%d"),(int)ContourResult->Max.y);

		Grid->SetCellValue(x,0,Area);
		Grid->SetCellValue(x,1,CenterX);
		Grid->SetCellValue(x,2,CenterY);
		Grid->SetCellValue(x,3,MinX);
		Grid->SetCellValue(x,4,MaxX);
		Grid->SetCellValue(x,5,MinY);
		Grid->SetCellValue(x,6,MaxY);
	}

	return true;
}

void OutputStatistics::SpeedTest()
{
	Grid->SetCellValue(sx,sy,wxT("test") );
	sx++;
	if( sx==6 )
	{
		sx= 0;
		sy++;
	}
	if( sy==6 )
		sy=0;
}


OutputStatistics::OutputStatistics( wxGrid *lGrid, ContoursProcessor *lContoursProcessor ): Output( "OutputStatistics" )
{
	Grid= lGrid;
	sx=0;
	sy=0;
	cContoursProcessor= lContoursProcessor;
}