
// MDITestView.h : CMDITestView ��Ľӿ�
//

#pragma once


class CMDITestView : public CView
{
protected: // �������л�����
	CMDITestView();
	DECLARE_DYNCREATE(CMDITestView)

// ����
public:
	CMDITestDoc* GetDocument() const;

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
	virtual ~CMDITestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MDITestView.cpp �еĵ��԰汾
inline CMDITestDoc* CMDITestView::GetDocument() const
   { return reinterpret_cast<CMDITestDoc*>(m_pDocument); }
#endif

