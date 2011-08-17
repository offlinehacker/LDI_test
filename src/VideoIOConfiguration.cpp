#include "VideoIOConfiguration.h"

VideoIOConfiguration::VideoIOConfiguration()
{
	VideoOutputsCount= 0;
}

bool VideoIOConfiguration::AddVideoOutput( CCamView *VideoOutput )
{
	if( VideoOutputsCount>= MAX_VIDEO_OUTPUTS )
		return false;

	cVideoIOOutputRelations[VideoOutputsCount].VideoOutput= VideoOutput;
	VideoOutputsCount++;

	return true;
}

bool VideoIOConfiguration::SelectVideoOutputForName( char* name, int OutputId )
{
	if(OutputId>=MAX_VIDEO_OUTPUTS)
		return false;

	strcpy( cVideoIOOutputRelations[OutputId].name, name );

	return true;
}

void VideoIOConfiguration::DisplayFrame( IplImage *frame, char* name )
{
	if(!frame)
		return;
	for( int x=0; x<VideoOutputsCount; x++ )
	{
		if(!strcmp(name, cVideoIOOutputRelations[x].name) )
			cVideoIOOutputRelations[x].VideoOutput->DrawCam( frame );
	}
}
