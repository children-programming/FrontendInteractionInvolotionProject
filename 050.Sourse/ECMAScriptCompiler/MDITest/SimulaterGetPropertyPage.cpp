// SimulaterGetPropertyPage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MDITest.h"
#include "SimulaterGetPropertyPage.h"
#include "afxdialogex.h"


// SimulaterGetPropertyPage �Ի���

IMPLEMENT_DYNAMIC(SimulaterGetPropertyPage, CPropertyPage)

SimulaterGetPropertyPage::SimulaterGetPropertyPage()
	: CPropertyPage(SimulaterGetPropertyPage::IDD)
{

	m_str_uri = _T("");
}

SimulaterGetPropertyPage::~SimulaterGetPropertyPage()
{
}

void SimulaterGetPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GET_URI, m_str_uri);
	DDV_MaxChars(pDX, m_str_uri, 1000);
	DDX_Control(pDX, IDC_EDIT_GET_URI, m_ctl_uri);
}


BEGIN_MESSAGE_MAP(SimulaterGetPropertyPage, CPropertyPage)
END_MESSAGE_MAP()


// Get the inputed URI


CString SimulaterGetPropertyPage::GetURI(void)
{
	return m_str_uri;;
}


void SimulaterGetPropertyPage::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	CPropertyPage::OnOK();
}


BOOL SimulaterGetPropertyPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_str_uri = _T("http://180.166.20.236/DailyReport/Login.aspx");
	UpdateData(FALSE);

	//m_ctl_uri.UpdateData(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
