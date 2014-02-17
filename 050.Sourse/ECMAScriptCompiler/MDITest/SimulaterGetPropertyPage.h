#pragma once


// SimulaterGetPropertyPage 对话框

class SimulaterGetPropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(SimulaterGetPropertyPage)

public:
	SimulaterGetPropertyPage();
	virtual ~SimulaterGetPropertyPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_MEDIUM_GET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString GetURI(void);
	CString m_str_uri;
	virtual void OnOK();
};
