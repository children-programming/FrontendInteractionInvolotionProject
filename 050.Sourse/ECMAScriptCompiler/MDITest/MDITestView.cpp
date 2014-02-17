
// MDITestView.cpp : CMDITestView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MDITest.h"
#endif

#include "MDITestDoc.h"
#include "MDITestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDITestView

IMPLEMENT_DYNCREATE(CMDITestView, CView)

BEGIN_MESSAGE_MAP(CMDITestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMDITestView ����/����

CMDITestView::CMDITestView()
{
	// TODO: �ڴ˴���ӹ������

}

CMDITestView::~CMDITestView()
{
}

BOOL CMDITestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMDITestView ����

void CMDITestView::OnDraw(CDC* /*pDC*/)
{
	CMDITestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMDITestView ��ӡ

BOOL CMDITestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMDITestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMDITestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMDITestView ���

#ifdef _DEBUG
void CMDITestView::AssertValid() const
{
	CView::AssertValid();
}

void CMDITestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDITestDoc* CMDITestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDITestDoc)));
	return (CMDITestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMDITestView ��Ϣ�������
