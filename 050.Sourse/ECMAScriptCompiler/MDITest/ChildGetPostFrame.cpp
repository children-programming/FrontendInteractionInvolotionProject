// CChildGetPostFrame.cpp : CChildGetPostFrame ���ʵ��
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

// CChildFrame ����/����


CChildGetPostFrame::CChildGetPostFrame(void)
{
}


CChildGetPostFrame::~CChildGetPostFrame(void)
{
}

BOOL CChildGetPostFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame ���

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

