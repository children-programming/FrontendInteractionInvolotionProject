// SimulaterGetPropage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MDITest.h"
#include "SimulaterGetPropage.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "MDITestGetPostView.h"
#include "MDITestGetPostDoc.h"


// CSimulaterGetPropage �Ի���

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


// CSimulaterGetPropage ��Ϣ�������


void CSimulaterGetPropage::OnClickedButtonGetStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
