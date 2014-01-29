/********************************************************************
// 
// 
//    
// Created On 01/17/2014
// Updated On 01/29/2014
// CopyRight Yes!Data  http://www.yesdata.net
//
********************************************************************/
#pragma once
#include <string>
#include <iostream>

using namespace std;
namespace www_yesdata_net
{
	class CMyTrace
	{
	public:
		CMyTrace(void);
		~CMyTrace(void);
		static void Print(wstring s);
		static void OpenLog();
		static void CloseLog();
	private:
		static bool open_state;
	};
}

