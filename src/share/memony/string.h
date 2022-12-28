//
//	STRING TYPE
//	////////////////////////////////////////////////////
//	STRING IS A STRUCT FOR THE VM
//
//	EXAMPLE
//	////////////////////////////////////////////////////
//	I NEED TO GET A INPUT OF CHARS,BUT CHARS IS NOT GOOD
//	FOR DEVELOPED OR RUNNING
//
//	WHAT ARE REF_STRING AND STRING
//	////////////////////////////////////////////////////
//	I THINK:REF_STRING IS A TYPE,AND CONST,SO IT IS VERY
//	FAST AND SAFE
//	BECAUSE OF USER,STRING MAYBE NOT SAFE
//

#include "../utilities/types.h"

class New
{
public:
	
private:
	string str;
	u8 length;
	u4* ptr[];
	New();
	~New();
	void _BREAK_();
};