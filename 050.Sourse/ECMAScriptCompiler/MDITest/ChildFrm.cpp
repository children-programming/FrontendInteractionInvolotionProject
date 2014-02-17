
// ChildFrm.cpp : CChildFrame ���ʵ��
//

#include "stdafx.h"
#include "MDITest.h"

#include "ChildFrm.h"
#include "SimulaterGetPropertyPage.h"
#include "Dialog1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	ON_COMMAND(ID_SIMULATER_GET, &CChildFrame::OnSimulaterGet)
END_MESSAGE_MAP()

// CChildFrame ����/����

CChildFrame::CChildFrame()
{
	// TODO: �ڴ����ӳ�Ա��ʼ������
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame ���

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}
#endif //_DEBUG

// CChildFrame ��Ϣ��������
void CChildFrame::OnSimulaterGet()
{
	// TODO: �ڴ�����������������
	/*CDialog1 d1;
	d1.DoModal();*/

	SimulaterGetPropertyPage c;
	CPropertySheet sheet(_T("URI"));
	sheet.AddPage(&c);
	if (sheet.DoModal() == ID_OK)
	{
		
	}

}