/********************************************************************
// 
// 
//    
// Created On 01/17/2014
// Updated On 01/29/2014
// CopyRight Yes!Data  http://www.yesdata.net
//
********************************************************************/
#include "MyTrace.h"

using namespace www_yesdata_net;

//initiate the static variable member ** member type must be defined 
bool CMyTrace::open_state(false);

CMyTrace::CMyTrace(void)
{
}


CMyTrace::~CMyTrace(void)
{
}

void CMyTrace::Print(wstring s)
	{
		if(open_state)
		{
			wcout<<s<<endl;
		}
	}

void CMyTrace::OpenLog()
{
	open_state = true;
}

void CMyTrace::CloseLog()
{
	open_state = false;
}
