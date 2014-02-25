// MDITestGetPostHtmlView.cpp : ʵ���ļ�
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


// CMDITestGetPostHtmlView ���

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


// CMDITestGetPostHtmlView ��Ϣ�������


void CMDITestGetPostHtmlView::OnDraw(CDC* pDC)
{
	// TODO: �ڴ����ר�ô����/����û���
	pDC->TextOutA(10, 20, CString(_T("I am html")));
}


void CMDITestGetPostHtmlView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	SetAddressBar(true);
	SetFullScreen(true);
	SetMenuBar(true);
	SetStatusBar(true);
	SetToolBar(1);

	LoadFromResource(IDS_STRING_DEFAULT_HTML);
}


void CMDITestGetPostHtmlView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: �ڴ����ר�ô����/����û���
	
}


void CMDITestGetPostHtmlView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CHtmlView::OnPaint()
	CMDITestGetPostDoc* pDoc = NULL;
	pDoc = (CMDITestGetPostDoc*)GetDocument();
	CString uri = pDoc->GetURI();
	if(uri.GetLength() > 0 )
	{
		this->Navigate2(uri.operator LPCSTR(), NULL, NULL);
		//Navigate2(_T("http://www.msdn.microsoft.com/vstudio/"),NULL,NULL);
	}
}
