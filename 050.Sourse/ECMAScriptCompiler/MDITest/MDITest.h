
// MDITest.h : MDITest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMDITestApp:
// �йش����ʵ�֣������ MDITest.cpp
//

class CMDITestApp : public CWinApp
{
public:
	CMDITestApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
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
