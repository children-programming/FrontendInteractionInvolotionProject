#include "StdAfx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "SimulaterGetPropage.h"

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(true);
}


void CMDITestGetPostDoc::SetURI(const CString& uri) const
{
	//m_uri = uri;
}


void CMDITestGetPostDoc::StartSimulatingGet(void) const
{
}