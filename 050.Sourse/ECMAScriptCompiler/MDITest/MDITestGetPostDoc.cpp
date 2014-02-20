#include "StdAfx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "afxinet.h"//WinNet

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
	try
	{
		CInternetSession session;
		CHttpConnection *connection = session.GetHttpConnection(
			"150.34.222.125"
			,1
			,80);
		CHttpFile *httpfile = connection->OpenRequest(
			CHttpConnection::HTTP_VERB_GET
			,""
			,m_uri.operator LPCSTR()
			,INTERNET_FLAG_DONT_CACHE
			,NULL
			,"HTTP/1.0"
			);
		httpfile->SendRequest();

		CString verb = httpfile->GetVerb();
		CString filename = httpfile->GetFileName();
		CString url = httpfile->GetFileURL();
		CString info = "";
		DWORD state;
		if(httpfile->QueryInfoStatusCode(state))
		{
			
		}
		httpfile->QueryInfo(HTTP_QUERY_CONTENT_LENGTH, info);
		int i = 1;

	}
	catch(CInternetException* e)
	{
		AfxMessageBox("Connection error!");
	}
}