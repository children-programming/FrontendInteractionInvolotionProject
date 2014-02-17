
// ChildFrm.cpp : CChildFrame 类的实现
//

#include "stdafx.h"
#include "MDITest.h"

#include "ChildFrm.h"
#include "SimulaterGetPropertyPage.h"
#include "Dialog1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	ON_COMMAND(ID_SIMULATER_GET, &CChildFrame::OnSimulaterGet)
END_MESSAGE_MAP()

// CChildFrame 构造/析构

CChildFrame::CChildFrame()
{
	// TODO: 在此添加成员初始化代码
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame 诊断

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}
#endif //_DEBUG

// CChildFrame 消息处理程序
void CChildFrame::OnSimulaterGet()
{
	// TODO: 在此添加命令处理程序代码
	/*CDialog1 d1;
	d1.DoModal();*/

	SimulaterGetPropertyPage c;
	CPropertySheet sheet(_T("URI"));
	sheet.AddPage(&c);
	if (sheet.DoModal() == ID_OK)
	{
		
	}

}
