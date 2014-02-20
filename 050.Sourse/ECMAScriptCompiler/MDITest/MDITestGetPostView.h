#pragma once
#include "afxwin.h"
#include "MDITestGetPostDoc.h"
class CMDITestGetPostView :
	public CView
{
protected: // �������л�����
	CMDITestGetPostView();
	DECLARE_DYNCREATE(CMDITestGetPostView)

// ����
public:
	CMDITestGetPostDoc* GetDocument() const;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMDITestGetPostView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnSimulaterGet();
};

#ifndef _DEBUG  // MDITestView.cpp �еĵ��԰汾
inline CMDITestGetPostDoc* CMDITestGetPostView::GetDocument() const
   { return reinterpret_cast<CMDITestGetPostDoc*>(m_pDocument); }
#endif
