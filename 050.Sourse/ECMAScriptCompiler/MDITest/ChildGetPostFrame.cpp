// CChildGetPostFrame.cpp : CChildGetPostFrame 类的实现
//

#include "stdafx.h"
#include "MDITest.h"

#include "ChildGetPostFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildGetPostFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildGetPostFrame, CMDIChildWnd)
	
END_MESSAGE_MAP()

// CChildFrame 构造/析构


CChildGetPostFrame::CChildGetPostFrame(void)
{
}


CChildGetPostFrame::~CChildGetPostFrame(void)
{
}

BOOL CChildGetPostFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame 诊断

#ifdef _DEBUG
void CChildGetPostFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildGetPostFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}
#endif //_DEBUG

