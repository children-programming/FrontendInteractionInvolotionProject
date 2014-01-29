/********************************************************************
// 
// 
//    
// Created On 01/17/2014
// Updated On 01/29/2014
// CopyRight Yes!Data  http://www.yesdata.net
//
********************************************************************/
#include "ECMAScript.h"
#include "Expr.h"

using namespace www_yesdata_net;


void ParseSourse(const wchar_t* pSourse)
{
	wstring sourse(pSourse);
	CFourOperations fo(sourse);
	fo.Invok();
}