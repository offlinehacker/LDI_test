#define DEFINED_FRAMES

//When we do not set any controls
#ifdef BLANK_FRAMES
	#include "options1.h"
	#include "options2.h"	
	#include "options3.h"
	#include "options4.h"
	#include "options5.h"
	#include "options6.h"

	#include "output1.h"
	#include "output2.h"

	#include "../camview.h"
	#include "../MainFrameHead.h"


	#define OPTIONS1_CLASS Options1
	#define OPTIONS2_CLASS Options2
	#define OPTIONS3_CLASS Options3
	#define OPTIONS4_CLASS Options4
	#define OPTIONS5_CLASS Options5
	#define OPTIONS6_CLASS Options6

	#define OUTPUT1_CLASS Output1
	#define OUTPUT2_CLASS Output2

	#define CAMVIEW_CLASS CCamView
	#define MAINFRAMEHEAD_CLASS MainFrameHead
#endif

//When we se controls
#ifdef DEFINED_FRAMES
	#include "../Options1Derived.h"
	#include "options2.h"	
	#include "options3.h"
	#include "options4.h"
	#include "options5.h"
	#include "options6.h"

	#include "../Output1Derived.h"
	#include "../Output2Derived.h"

	#include "../camview.h"
	#include "../MainFrameHead.h"

	#define OPTIONS1_CLASS Options1Derived
	#define OPTIONS2_CLASS Options2
	#define OPTIONS3_CLASS Options3
	#define OPTIONS4_CLASS Options4
	#define OPTIONS5_CLASS Options5
	#define OPTIONS6_CLASS Options6

	//class OPTIONS1_CLASS;

	#define OUTPUT1_CLASS Output1Derived
	#define OUTPUT2_CLASS Output2Derived

	#define CAMVIEW_CLASS CCamView
	#define MAINFRAMEHEAD_CLASS MainFrameHead
#endif