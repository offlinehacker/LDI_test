#include "CameraSource.h"

CameraSource::CameraSource()
{
	opened= false;
	width= -1;
	height= -1;
	fps= -1;
	depth= -1;
	channels= -1;
	tested=false;
}

CameraSource::~CameraSource()
{
	CloseCamera();
}

void CameraEnumerator::Reset()
{ 
	return; 
}