/********************************************************************
// 
// ≤‚ ‘µº≥ˆC++¿‡
//
//
// 
// CopyRight Yes!Data  http://www.yesdata.net
//
********************************************************************/

#pragma once
#include <string>

#ifndef _WWW_YESDATA_NET_DLL_EXPORT_
#define DLLCALLBACK   __declspec( dllimport )
#else
#define DLLCALLBACK   __declspec( dllexport )
#endif
#define EXTERN_C extern "C"

using namespace std;

namespace www_yesdata_net
{
	EXTERN_C
	{
		class DLLCALLBACK CMyClass
		{
		public:
			CMyClass(void);
			virtual ~CMyClass(void);
			virtual void Print();
			virtual void Print(string);
		};
	}
}

