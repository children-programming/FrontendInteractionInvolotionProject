#include "StdAfx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MDITest.h"
#endif

#include "MDITestGetPostView.h"
#include "SimulaterGetPropertyPage.h"
#include "Dialog1.h"
#include "MDITestGetPostDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMDITestView

IMPLEMENT_DYNCREATE(CMDITestGetPostView, CView)

BEGIN_MESSAGE_MAP(CMDITestGetPostView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SIMULATER_GET, &CMDITestGetPostView::OnSimulaterGet)
END_MESSAGE_MAP()

// CMDITestView ����/����

CMDITestGetPostView::CMDITestGetPostView()
{
	// TODO: �ڴ˴���ӹ������

}

CMDITestGetPostView::~CMDITestGetPostView()
{
}

BOOL CMDITestGetPostView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMDITestView ����

void CMDITestGetPostView::OnDraw(CDC* /*pDC*/)
{
	CMDITestGetPostDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMDITestView ��ӡ

BOOL CMDITestGetPostView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMDITestGetPostView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMDITestGetPostView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMDITestView ���

#ifdef _DEBUG
void CMDITestGetPostView::AssertValid() const
{
	CView::AssertValid();
}

void CMDITestGetPostView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDITestGetPostDoc* CMDITestGetPostView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDITestGetPostDoc)));
	return (CMDITestGetPostDoc*)m_pDocument;
}
#endif //_DEBUG


// CMDITestGetPostView ��Ϣ�������
void CMDITestGetPostView::OnSimulaterGet()
{
	// TODO: �ڴ���������������
	/*CDialog1 d1;
	d1.DoModal();*/

	SimulaterGetPropertyPage c;
	CPropertySheet sheet(_T("URI"));
	sheet.AddPage(&c);
	if (sheet.DoModal() == IDOK)
	{
		////Create New Child Frame
		//POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
		//if (pos != NULL)
		//{
		//	CDocTemplate *t = NULL;
		//	t = AfxGetApp()->GetNextDocTemplate(pos);//Get first
		//	t = AfxGetApp()->GetNextDocTemplate(pos);//Get second
		//	if (t != NULL)
		//	{
		//		POSITION pos_d = t->GetFirstDocPosition();
		//		CMDITestGetPostDoc* d = (CMDITestGetPostDoc*)t->GetNextDoc(pos_d);

		//		CChildGetPostFrame *f = (CChildGetPostFrame *)t->CreateNewFrame(d, NULL);
		//		f->ActivateFrame();
		//		
		//	}
		//}

		////Create New Mainframe
		CMDITestGetPostDoc *doc = (CMDITestGetPostDoc*)GetDocument();
		//c.UpdateData(TRUE);
		CString uri = c.GetURI();
		doc->SetURI(uri);
		doc->StartSimulatingGet();
		
	}

}