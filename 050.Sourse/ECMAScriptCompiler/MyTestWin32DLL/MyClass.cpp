#define _WWW_YESDATA_NET_DLL_EXPORT_

#include "MyClass.h"
#include <iostream>

using namespace www_yesdata_net;
using namespace std;

CMyClass::CMyClass(void)
{
}


CMyClass::~CMyClass(void)
{
}

void CMyClass::Print(void)
{
	cout<<"WARNING! Print blank string."<<endl;
}

void CMyClass::Print(string str)
{
	if (str.length() >0 )
	{
		cout<<str<<endl;
	}
	else
	{
		cout<<"WARNING! No resourse to be printed."<<endl;
	}

}