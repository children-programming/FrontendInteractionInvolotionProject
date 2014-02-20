#include "StdAfx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SIMULATER_GET, &CMDITestGetPostView::OnSimulaterGet)
END_MESSAGE_MAP()

// CMDITestView 构造/析构

CMDITestGetPostView::CMDITestGetPostView()
{
	// TODO: 在此处添加构造代码

}

CMDITestGetPostView::~CMDITestGetPostView()
{
}

BOOL CMDITestGetPostView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMDITestView 绘制

void CMDITestGetPostView::OnDraw(CDC* /*pDC*/)
{
	CMDITestGetPostDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMDITestView 打印

BOOL CMDITestGetPostView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMDITestGetPostView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMDITestGetPostView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMDITestView 诊断

#ifdef _DEBUG
void CMDITestGetPostView::AssertValid() const
{
	CView::AssertValid();
}

void CMDITestGetPostView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDITestGetPostDoc* CMDITestGetPostView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDITestGetPostDoc)));
	return (CMDITestGetPostDoc*)m_pDocument;
}
#endif //_DEBUG


// CMDITestGetPostView 消息处理程序
void CMDITestGetPostView::OnSimulaterGet()
{
	// TODO: 在此添加命令处理程序代码
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