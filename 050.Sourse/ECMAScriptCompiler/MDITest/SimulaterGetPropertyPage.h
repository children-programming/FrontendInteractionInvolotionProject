#pragma once


// SimulaterGetPropertyPage �Ի���

class SimulaterGetPropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(SimulaterGetPropertyPage)

public:
	SimulaterGetPropertyPage();
	virtual ~SimulaterGetPropertyPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_MEDIUM_GET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString GetURI(void);
	CString m_str_uri;
	virtual void OnOK();
};
