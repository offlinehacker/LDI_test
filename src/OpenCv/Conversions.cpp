#include "Conversions.h"

IplImage *RgbToBW( IplImage *InputImage )
{
	IplImage *dst;

	//We don't need to convert image
	if(InputImage->depth==1)
	{
		dst= cvCloneImage(InputImage);
		return dst;
	}

	int width= InputImage->width;
	int height= InputImage->height;

	dst= cvCreateImage( cvSize(width,height),IPL_DEPTH_8U, 1 );
	cvCvtColor( InputImage, dst, CV_RGB2GRAY );

	return dst;
}

IplImage *BWToRgb( IplImage *InputImage )
{
	IplImage *dst;

	//Image is already RGB
	if( InputImage->colorModel[0]=='R' )
	{
		dst= cvCloneImage(InputImage);
		return dst;
	}

	int width= InputImage->width;
	int height= InputImage->height;

	dst= cvCreateImage( cvSize(width,height),IPL_DEPTH_8U, 3 );
	cvCvtColor( InputImage, dst, CV_GRAY2RGB );

	return dst;
}