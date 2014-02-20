#pragma once
#include "afxwin.h"
#include "MDITestGetPostDoc.h"
class CMDITestGetPostView :
	public CView
{
protected: // 仅从序列化创建
	CMDITestGetPostView();
	DECLARE_DYNCREATE(CMDITestGetPostView)

// 特性
public:
	CMDITestGetPostDoc* GetDocument() const;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMDITestGetPostView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnSimulaterGet();
};

#ifndef _DEBUG  // MDITestView.cpp 中的调试版本
inline CMDITestGetPostDoc* CMDITestGetPostView::GetDocument() const
   { return reinterpret_cast<CMDITestGetPostDoc*>(m_pDocument); }
#endif
