#include "StdAfx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "SimulaterGetPropage.h"

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MDITestGetPostDoc.h"
#endif

#include "MDITestDoc.h"

#include <propkey.h>

IMPLEMENT_DYNCREATE(CMDITestGetPostDoc, CDocument)

BEGIN_MESSAGE_MAP(CMDITestGetPostDoc, CDocument)
	ON_UPDATE_COMMAND_UI(ID_SIMULATER_GET, &CMDITestGetPostDoc::OnUpdateSimulaterGet)
	
END_MESSAGE_MAP()

CMDITestGetPostDoc::CMDITestGetPostDoc(void)
	: m_uri(_T(""))
{
}


CMDITestGetPostDoc::~CMDITestGetPostDoc(void)
{
}

void CMDITestGetPostDoc::OnUpdateSimulaterGet(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(true);
}


void CMDITestGetPostDoc::SetURI(const CString& uri) const
{
	//m_uri = uri;
}


void CMDITestGetPostDoc::StartSimulatingGet(void) const
{
}