#pragma once
#include "afxwin.h"
class CChildGetPostFrame :
	public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildGetPostFrame)
public:
	CChildGetPostFrame(void);
// ����
public:

// ����
public:

// ��д
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildGetPostFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

};

