#include "ECMAScript.h"
#include "Expr.h"

using namespace www_yesdata_net;


void ParseSourse(const wchar_t* pSourse)
{
	wstring sourse(pSourse);
	CFourOperations fo(sourse);
	fo.Invok();
}