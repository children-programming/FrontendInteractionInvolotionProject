
// loneliness.h : loneliness Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// ClonelinessApp:
// �йش����ʵ�֣������ loneliness.cpp
//

class ClonelinessApp : public CWinApp
{
public:
	ClonelinessApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern ClonelinessApp theApp;
