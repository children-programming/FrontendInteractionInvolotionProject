#pragma once
#include "MDITestGetPostDoc.h"
#include "MDITestGetPostView.h"

// CSimulaterGetPropage 对话框

class CSimulaterGetPropage : public CPropertyPage
{
	DECLARE_DYNAMIC(CSimulaterGetPropage)

public:
	CSimulaterGetPropage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSimulaterGetPropage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_MEDIUM_GET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_uri;
	afx_msg void OnClickedButtonGetStart();
private:
	const CMDITestGetPostDoc* pDoc;
public:
	void SetDoc(const CMDITestGetPostDoc* doc);
	virtual BOOL OnInitDialog();
};
