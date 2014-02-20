#pragma once
#include "afxwin.h"
class CChildGetPostFrame :
	public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildGetPostFrame)
public:
	CChildGetPostFrame(void);
// 特性
public:

// 操作
public:

// 重写
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildGetPostFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

};

