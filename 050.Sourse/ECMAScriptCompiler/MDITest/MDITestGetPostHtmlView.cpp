// MDITestGetPostHtmlView.cpp : 实现文件
//

#include "stdafx.h"
#include "MDITest.h"
#include "MDITestGetPostHtmlView.h"
#include "MDITestGetPostDoc.h"
#include "resource.h"


// CMDITestGetPostHtmlView

IMPLEMENT_DYNCREATE(CMDITestGetPostHtmlView, CHtmlView)

CMDITestGetPostHtmlView::CMDITestGetPostHtmlView()
{

}

CMDITestGetPostHtmlView::~CMDITestGetPostHtmlView()
{
}

void CMDITestGetPostHtmlView::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMDITestGetPostHtmlView, CHtmlView)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CMDITestGetPostHtmlView 诊断

#ifdef _DEBUG
void CMDITestGetPostHtmlView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMDITestGetPostHtmlView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG


// CMDITestGetPostHtmlView 消息处理程序


void CMDITestGetPostHtmlView::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类
	pDC->TextOutA(10, 20, CString(_T("I am html")));
}


void CMDITestGetPostHtmlView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	SetAddressBar(true);
	SetFullScreen(true);
	SetMenuBar(true);
	SetStatusBar(true);
	SetToolBar(1);

	LoadFromResource(IDS_STRING_DEFAULT_HTML);
}


void CMDITestGetPostHtmlView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: 在此添加专用代码和/或调用基类
	
}


void CMDITestGetPostHtmlView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CHtmlView::OnPaint()
	CMDITestGetPostDoc* pDoc = NULL;
	pDoc = (CMDITestGetPostDoc*)GetDocument();
	CString uri = pDoc->GetURI();
	if(uri.GetLength() > 0 )
	{
		this->Navigate2(uri.operator LPCSTR(), NULL, NULL);
		//Navigate2(_T("http://www.msdn.microsoft.com/vstudio/"),NULL,NULL);
	}
}
