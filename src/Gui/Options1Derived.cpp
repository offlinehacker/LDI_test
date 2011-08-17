#include "Options1Derived.h"

#include "Frames/MainFrame.h"

class MainFrame;

Options1Derived::Options1Derived( wxWindow* parent )
:
Options1( parent )
{
	cContoursProcessor= new ContoursProcessor("contours");

	MainFrame *tFrame= (MainFrame*)parent;
	tFrame->GetVideoProcessorManager()->AddVideoProcessor( cContoursProcessor );
}

Options1Derived::Options1Derived( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
:
Options1( parent )
{
	cContoursProcessor= new ContoursProcessor("contours");

	MainFrame *tFrame= (MainFrame*)parent;
	tFrame->GetVideoProcessorManager()->AddVideoProcessor( cContoursProcessor );
}

void Options1Derived::OnTreshold( wxScrollEvent& event )
{
	cContoursProcessor->SetTreshold( m_Treshold->GetValue() );
	cContoursProcessor->TransferOptions();
}

void Options1Derived::OnResetStatistics( wxCommandEvent& event )
{
	cContoursProcessor->ResetStatistics();
}

ContoursProcessor::ContoursProcessor( char* lname ): VideoProcessor( lname )
{
	GuiOptions= new ContoursOptions();
	WorkingOptions= new ContoursOptions();
	InitProcessing();
}

bool ContoursProcessor::InitProcessing()
{
	storage = cvCreateMemStorage(0);
	ResultsStorage = cvCreateMemStorage(0);
	Tmp_img= NULL;
	img=NULL;
	pimg=NULL;
	ImageResult= 0;
	ImageStatResult = 0;
	contours = 0;
	pimg= NULL;
	img= NULL;
	Tmp_img= NULL;
	cnt_img= NULL;
	MeasurementImageCount= 0;

	return true;
}

void ContoursProcessor::CloseProcessing(void)
{
	if(Tmp_img)
		cvReleaseImage(&Tmp_img); 
	if(img)
		cvReleaseImage(&img);
	if(pimg)
		cvReleaseImage(&pimg);
	cvReleaseMemStorage( &storage ); 
	cvReleaseMemStorage( &ResultsStorage );
}

void ContoursProcessor::SetTreshold( int Value)
{
	ContoursOptions *lContoursOptions= (ContoursOptions*)GuiOptions;

	if(Value > 255 )
		return;

	lContoursOptions->Treshold= Value;
}

IplImage* ContoursProcessor::Process( IplImage *InputFrame )
{
	ContoursOptions *lContoursOptions= (ContoursOptions*)WorkingOptions;

	MeasurementImageCount++;
	if(pimg)
		cvReleaseImage(&pimg);
	pimg= cvCreateImage(cvGetSize(InputFrame),8, 1 );

	img= RgbToBW( InputFrame );

	cvThreshold(img, pimg, lContoursOptions->Treshold, 255, CV_THRESH_BINARY /*CV_THRESH_BINARY*/ );

	if (Tmp_img)
		cvReleaseImage(&Tmp_img);
	Tmp_img = cvCloneImage (pimg);
	if (cnt_img)
		cvReleaseImage(&cnt_img);
	cnt_img = cvCloneImage (InputFrame); 

	FindContours();

	cvReleaseMemStorage( &storage );
	cvReleaseImage( &img );

	return cnt_img;
}

bool ContoursProcessor::FindContours()
{
	if (storage==NULL)
    {
      storage = cvCreateMemStorage(0);
    }
    else
    {
      cvClearMemStorage(storage);
    }
    cvFindContours( Tmp_img, storage, &contours, sizeof(CvContour),
                    CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0) );
	if(ImageResult)
		cvClearSeq(ImageResult);
    if (contours)
    {
      if (ResultsStorage==NULL)
      {
        ResultsStorage = cvCreateMemStorage(0);
      }
      else
      {
        cvClearMemStorage(ResultsStorage);
      }
      ImageResult = cvCreateSeq(0,sizeof(CvSeq),sizeof(T_MEAS_RESULTS_REC),ResultsStorage);
      T_MEAS_RESULTS_REC ContourResult;
      int Idx=1;
      for( CvSeq* c=contours; c!=NULL; c=c->h_next ) { 
      //for (i=0;i<contours->total;i++)
        //ImageResult
        if (ImageResult)
        {
          cvContourMoments(c,&Moments);
          if ((Moments.m00>3000.0)&&(Moments.m00<8000.0))
          {
            memset(&ContourResult,0,sizeof(ContourResult));
            ContourResult.ObjNo=Idx;
            ContourResult.Area = Moments.m00;
            ContourResult.Center.x = Moments.m10/Moments.m00;
            ContourResult.Center.y = Moments.m01/Moments.m00;
            cvSeqPushFront(ImageResult,&ContourResult);
            Idx++;
          }
        }
      }
      CalcResult(ImageResult); 
      //PrintResults(0, res_img,ImageResult);
      cvDrawContours( cnt_img, contours, CV_RGB(128,0,0), CV_RGB(0,128,0), 3, 1, CV_AA, cvPoint(0,0) );
    }

	return true;
}

bool ContoursProcessor::CalcResult(CvSeq *Results)
{
  int i;
  T_MEAS_RESULTS_REC *ContourResult;
  T_MEAS_RESULTS_REC ContourStatResult;
  T_MEAS_RESULTS_REC *ContourStatResultP; // points in result queue
  for (i=0;i<Results->total;i++)
  {
    //sprintf(TextLine,FormatLine,);
    ContourResult = (T_MEAS_RESULTS_REC *) cvGetSeqElem(ImageResult,i);
    memset(&ContourStatResult,0,sizeof(ContourStatResult));
    if (!ImageStatResult)
    {
      ImageStatResult = cvCreateSeq(0,sizeof(CvSeq),sizeof(T_MEAS_RESULTS_REC),ResultsStorage);
    }
    if (ImageStatResult->total<Results->total)
    {
      // Inserting new elements for the first time
      ContourStatResult.Area = ContourResult->Area;
      ContourStatResult.ObjNo = ContourResult->ObjNo;
      ContourStatResult.Center.x = ContourResult->Center.x;
      ContourStatResult.Center.y = ContourResult->Center.y;
      ContourStatResult.Min.x = 32000;
      ContourStatResult.Min.y = 32000;
      ContourStatResult.Max.x = 0;
      ContourStatResult.Max.y = 0;
      cvSeqPushFront(ImageStatResult,&ContourStatResult);
    }
    else
    {
      ContourStatResultP = (T_MEAS_RESULTS_REC *) cvGetSeqElem(ImageStatResult,i);
      if (ContourStatResultP)
      {
        ContourStatResultP->Area += ContourResult->Area;
        ContourStatResultP->ObjNo = ContourResult->ObjNo;
        ContourStatResultP->Center.x += ContourResult->Center.x;
        ContourStatResultP->Center.y += ContourResult->Center.y;
        // Calc min x
        if (ContourStatResultP->Min.x>ContourResult->Center.x)
        {
          ContourStatResultP->Min.x = ContourResult->Center.x;
        }
        // Calc min y
        if (ContourStatResultP->Min.y>ContourResult->Center.y)
        {
          ContourStatResultP->Min.y = ContourResult->Center.y;
        }
        // Calc Max x
        if (ContourStatResultP->Max.x<ContourResult->Center.x)
        {
          ContourStatResultP->Max.x = ContourResult->Center.x;
        }
        // Calc Max y
        if (ContourStatResultP->Max.y<ContourResult->Center.y)
        {
          ContourStatResultP->Max.y = ContourResult->Center.y;
        }
      }

    }
  }
  return true;
}

CvSeq *ContoursProcessor::GetContourObjects()
{
	return ImageResult;
}

CvSeq *ContoursProcessor::GetStatistics()
{
	return ImageStatResult;
}

CvSeq *ContoursProcessor::GetResults()
{
	return ImageResult;
}

int ContoursProcessor::GetMeasurementImageCount()
{
	return MeasurementImageCount;
}

void ContoursProcessor::ResetStatistics()
{
	MeasurementImageCount=0;
	if (ImageStatResult)
	{
		cvClearSeq(ImageStatResult);
	}
	ImageStatResult = cvCreateSeq(0,sizeof(CvSeq),sizeof(T_MEAS_RESULTS_REC),ResultsStorage);
}
