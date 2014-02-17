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
}


BEGIN_MESSAGE_MAP(SimulaterGetPropertyPage, CPropertyPage)
END_MESSAGE_MAP()


// Get the inputed URI


CString SimulaterGetPropertyPage::GetURI(void)
{
	return CString();
}


void SimulaterGetPropertyPage::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	CPropertyPage::OnOK();
}
