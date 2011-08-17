#ifndef __OUTPUTH__
#define __OUTPUTH__

#include <string.h>

#define MAX_OUTPUTS 20
#define MAX_OUTPUT_NAME 20

class Output
{
private:
	char name[MAX_OUTPUT_NAME];

public:
	//Displays data from speciffic output
	virtual bool DisplayOutputData(){ return true; }
	char* GetOutputName(){ return name; }

	Output( char* lname );
	~Output(){}
};

class OutputManager
{
private:
	Output *Outputs[MAX_OUTPUTS];
	int OutputCount;

public:
	//Adds another output
	bool AddOutput( Output *lOutput );
	//Gets count of outputs
	int GetOutputCount(){ return OutputCount; }
	//Gets output by its index
	Output *GetOutputById( int id );
	//Gets output by its name
	Output *GetOutputByName( char* name );

	//Displays data from all outputs
	bool DisplayOutputData();

	OutputManager();
	~OutputManager();
};

#endif