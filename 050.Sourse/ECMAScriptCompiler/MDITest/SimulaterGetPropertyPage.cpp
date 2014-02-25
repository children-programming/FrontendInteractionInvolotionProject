// SimulaterGetPropertyPage.cpp : 实现文件
//

#include "stdafx.h"
#include "MDITest.h"
#include "SimulaterGetPropertyPage.h"
#include "afxdialogex.h"


// SimulaterGetPropertyPage 对话框

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
	// TODO: 在此添加专用代码和/或调用基类

	CPropertyPage::OnOK();
}


BOOL SimulaterGetPropertyPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_str_uri = _T("http://180.166.20.236/DailyReport/Login.aspx");
	UpdateData(FALSE);

	//m_ctl_uri.UpdateData(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
