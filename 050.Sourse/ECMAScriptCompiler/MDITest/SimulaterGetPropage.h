#pragma once
#include "MDITestGetPostDoc.h"
#include "MDITestGetPostView.h"

// CSimulaterGetPropage �Ի���

class CSimulaterGetPropage : public CPropertyPage
{
	DECLARE_DYNAMIC(CSimulaterGetPropage)

public:
	CSimulaterGetPropage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSimulaterGetPropage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_MEDIUM_GET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
