
// lonelinessView.cpp : ClonelinessView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "loneliness.h"
#endif

#include "lonelinessDoc.h"
#include "lonelinessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ClonelinessView

IMPLEMENT_DYNCREATE(ClonelinessView, CView)

BEGIN_MESSAGE_MAP(ClonelinessView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// ClonelinessView ����/����

ClonelinessView::ClonelinessView()
{
	// TODO: �ڴ˴���ӹ������

}

ClonelinessView::~ClonelinessView()
{
}

BOOL ClonelinessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// ClonelinessView ����

void ClonelinessView::OnDraw(CDC* /*pDC*/)
{
	ClonelinessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// ClonelinessView ��ӡ

BOOL ClonelinessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void ClonelinessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void ClonelinessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// ClonelinessView ���

#ifdef _DEBUG
void ClonelinessView::AssertValid() const
{
	CView::AssertValid();
}

void ClonelinessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

ClonelinessDoc* ClonelinessView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ClonelinessDoc)));
	return (ClonelinessDoc*)m_pDocument;
}
#endif //_DEBUG


// ClonelinessView ��Ϣ�������
