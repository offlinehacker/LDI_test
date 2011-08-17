#include "Output2Derived.h"

#include "Frames/MainFrame.h"

Output2Derived::Output2Derived( wxWindow* parent )
:
Output2( parent )
{
}

Output2Derived::Output2Derived( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : Output2( parent )
{

	MainFrame *tMainFrame= (MainFrame*)parent;
	ContoursProcessor *tContoursProcessor= (ContoursProcessor*)tMainFrame->GetVideoProcessorManager()->GetVideoProcessorByName("contours");
	if(!tContoursProcessor)
		return;
	cOutputContourObjects= new OutputContourObjects(m_grid1, tContoursProcessor );

	tMainFrame->GetOutputManager()->AddOutput( cOutputContourObjects );
}

OutputContourObjects::OutputContourObjects( wxGrid *lGrid, ContoursProcessor *lContoursProcessor ): Output("ContourObjects")
{
	Grid= lGrid;
	cContoursProcessor= lContoursProcessor;
}

bool OutputContourObjects::DisplayOutputData()
{
	if(!cContoursProcessor->GetResults())
		return false;

	CvSeq *tContourObjects= cContoursProcessor->GetContourObjects();
	Grid->ClearGrid();

	T_MEAS_RESULTS_REC *ContourResult;
	for( int x=0; x<cContoursProcessor->GetResults()->total; x++ )
	{
		ContourResult = (T_MEAS_RESULTS_REC *)cvGetSeqElem(tContourObjects,x);

		wxString ObjectNo= wxString::Format(wxT("%d"),(int)ContourResult->ObjNo);
		wxString Area= wxString::Format(wxT("%d"),(int)ContourResult->Area);
		wxString CenterX= wxString::Format(wxT("%d"),(int)ContourResult->Center.x);
		wxString CenterY= wxString::Format(wxT("%d"),(int)ContourResult->Center.y);

		Grid->SetCellValue(x,0,ObjectNo);
		Grid->SetCellValue(x,1,Area);
		Grid->SetCellValue(x,2,CenterX);
		Grid->SetCellValue(x,3,CenterY);
	}
	return true;
}
