#ifndef __VIDEOIOCONFIGURATIONH__
#define __VIDEOIOCONFIGURATIONH__

#include <stdlib.h>

//Video sourface
#include "Gui/camview.h"

#define MAX_VIDEO_OUTPUTS 10

struct VideoIOOutptutRelations
{
	char name[20];
	CCamView *VideoOutput;
};

class VideoIOConfiguration
{
private:
	VideoIOOutptutRelations cVideoIOOutputRelations[MAX_VIDEO_OUTPUTS];
	//Pointers to video outputs;
	int VideoOutputsCount;

public:
	VideoIOConfiguration();
	//Adds another video output surface
	bool AddVideoOutput( CCamView *VideoOutput );
	//Gets count of video output surfaces
	int GetVideoOutputCount(){ return VideoOutputsCount; }
	//Selects video output for speciffic(video processor) name
	bool SelectVideoOutputForName( char* name, int OutputId );
	//Displays image on a surface with asociated name
	void DisplayFrame( IplImage *frame, char* name );
};

#endif