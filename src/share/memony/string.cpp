#include "string.h"

New::New()
{
	
}
New::~New()
{
	_BREAK_();
}
void New::_BREAK_()
{
	free(&New::str.ptr);
	free(&New::str.length);
	free(&New::str.chars);
}
