// SimulaterGetPropage.cpp : 实现文件
//

#include "stdafx.h"
#include "MDITest.h"
#include "SimulaterGetPropage.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "MDITestGetPostView.h"
#include "MDITestGetPostDoc.h"


// CSimulaterGetPropage 对话框

IMPLEMENT_DYNAMIC(CSimulaterGetPropage, CPropertyPage)

CSimulaterGetPropage::CSimulaterGetPropage(CWnd* pParent /*=NULL*/)
	: CPropertyPage(CSimulaterGetPropage::IDD)
	, pDoc(NULL)
{

	m_uri = _T("");
}

CSimulaterGetPropage::~CSimulaterGetPropage()
{
	
}


void CSimulaterGetPropage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GET_URI, m_uri);
	DDV_MaxChars(pDX, m_uri, 1000);
}


BEGIN_MESSAGE_MAP(CSimulaterGetPropage, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GET_START, &CSimulaterGetPropage::OnClickedButtonGetStart)
END_MESSAGE_MAP()


// CSimulaterGetPropage 消息处理程序


void CSimulaterGetPropage::OnClickedButtonGetStart()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(FALSE);
	
	if (pDoc != NULL )
	{
		pDoc->SetURI(m_uri);
		pDoc->StartSimulatingGet();
	}

}

void CSimulaterGetPropage::SetDoc(const CMDITestGetPostDoc* doc)
{
	pDoc = doc;
}


BOOL CSimulaterGetPropage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
