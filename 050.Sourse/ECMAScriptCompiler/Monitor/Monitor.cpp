// Monitor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

#include <string>
//#include "E:\项目管理\140.Front-end-Interaction-Involotion\050.Sourse\ScriptCompiler\ECMAScript\ECMAScript.h"


#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )

using namespace std;

typedef void (*lpParseSourse)(const wchar_t* pSourse);

//Trace debug info
class MyTrace
{
public:
	MyTrace():open_state(true)
	{
	}

	void Print(string s)
	{
		if(open_state)
		{
			cout<<s<<endl;
		}
	}
	void OpenLog()
	{
		open_state = true;
	}
	void CloseLog()
	{
		open_state = false;
	}
private:
	bool open_state;
};

int _tmain(int argc, _TCHAR* argv[])
{
	MyTrace trace;
	//log.CloseLog();

	wstring sourse;
	wchar_t psourse[1000];
	wmemset(psourse, 0 ,1000);

	/*fetch the sourse stream*/
	if (argc==1)
	{
		cout<<"please input sourse code file."<<endl;
		char pmbfilename[200];
		memset(pmbfilename, 0 ,200);
		cin>>pmbfilename;
		fflush(stdin);//clear flush content ,such as enter key

		wchar_t pfilename[200];
		wmemset(pfilename, 0 ,200);
		
		//this app run on the win7 chinese command line enviroment, so 
		//the default standard input encoding is GB2312,
		//we should change the encoding to wchart_t(=unicode) 
		MultiByteToWideChar(CP_OEMCP,NULL,pmbfilename,200,pfilename,200);

		wstring filename;
		filename.append(pfilename);

		
		filename=L"E:\\项目管理\\FrontendInteractionInvolotionProject\\050.Sourse\\ECMAScriptCompiler\\Debug\\source.js";
		FILE* f = _wfopen(filename.c_str(),L"r,ccs=UNICODE");
		if(f)
		{
			while (!feof(f))
			{
				wchar_t* ret = fgetws(psourse,999,f);
				if (ret == NULL)
				{
					if(ferror(f))
					{
						cout<<"Error occured while read the sourse file."<<endl;
					}

					sourse.clear();
					break;
				}
				else
				{
					sourse.append(psourse);
					wmemset(psourse, 0 ,1000);
				}
			}
			
			if(fclose(f) == EOF)
			{
				cout<<"Failed to close sourse file."<<endl;
			}/*
			else
			{
				cout<<"Succeed to close sourse file."<<endl;
			}*/
		}
	}
	else
	{
		sourse =wstring(argv[1]);
	}

	if (sourse.length() == 0)
	{
		cout<<"No sourse to be parsed."<<endl;
		return 0;
	}

	HINSTANCE hDll;//句柄
	lpParseSourse ParseSourse;
	hDll = LoadLibraryA("ECMAScript.dll");
	if(hDll)
	{
		//cout<<"load succeed."<<endl;
		ParseSourse = (lpParseSourse)GetProcAddress(hDll,"ParseSourse");
		if(ParseSourse)
		{
			trace.Print("starting parse......");
			ParseSourse(sourse.c_str());
		}
	}

	return 0;
}

