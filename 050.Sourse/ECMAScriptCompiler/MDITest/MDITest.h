
// MDITest.h : MDITest 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMDITestApp:
// 有关此类的实现，请参阅 MDITest.cpp
//

class CMDITestApp : public CWinApp
{
public:
	CMDITestApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	CView* m_pOldView;
	CView* m_pNewView;
public:
	CView* SwitchView();
	CView* GetOldView() const;
	void SetOldView(CView* val);
	CView* GetNewView() const;
	void SetNewView(CView* val);
};

extern CMDITestApp theApp;
