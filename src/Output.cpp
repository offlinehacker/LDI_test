#include "Output.h"

Output::Output(char *lname)
{
	strncpy( name, lname, MAX_OUTPUT_NAME );
}


bool OutputManager::AddOutput( Output *lOutput )
{
	if( OutputCount>=MAX_OUTPUTS )
		return false;

	Outputs[OutputCount]= lOutput;
	OutputCount++;

	return true;
}

Output *OutputManager::GetOutputById( int id )
{
	if( id>OutputCount )
		return NULL;

	return Outputs[id];
}

Output *OutputManager::GetOutputByName( char* lname )
{
	for( int x=0; x<OutputCount; x++ )
	{
		if(!strcmp(Outputs[x]->GetOutputName(),lname))
			return Outputs[x];
	}

	return NULL;
}

bool OutputManager::DisplayOutputData()
{
	int rcnt=0;
	for( int x=0; x<OutputCount; x++ )
	{
		rcnt+= Outputs[x]->DisplayOutputData();
	}

	if( rcnt==OutputCount-1 )
		return true;

	return false;
}

OutputManager::OutputManager()
{
	OutputCount= 0;
}

OutputManager::~OutputManager()
{
	//We delete all outputs
	for( int x=0; x<OutputCount; x++ )
	{
		delete( Outputs[x] );
	}
}