#include "StdAfx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "afxinet.h"//WinNet
#include "MDITest.h"//App

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
	ON_UPDATE_COMMAND_UI(ID_MENU_CHANGE_VIEW, &CMDITestGetPostDoc::OnMenuChangeView)
	ON_COMMAND(ID_MENU_CHANGE_VIEW, &CMDITestGetPostDoc::OnMenuChangeView)
END_MESSAGE_MAP()

CMDITestGetPostDoc::CMDITestGetPostDoc(void)
	: m_uri(_T("")),response()
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


void CMDITestGetPostDoc::SetURI(const CString& uri)
{
	m_uri = uri;
}

const CHTTPResponse& CMDITestGetPostDoc::GetResponseData() const
{
	return response;
}


void CMDITestGetPostDoc::StartSimulatingGet(void)
{
	try
	{
		BOOL bResult = FALSE;
		BOOL bRetVal = FALSE;
		DWORD dwType = 0;
		DWORD dwStateCode = 0;
		INTERNET_PORT wPort = 0;
		CString sServer = _T("");
		CString sObject = _T("");
		const int nTimeOut = 5000;

		bResult = AfxParseURL(m_uri, dwType, sServer, sObject, wPort);
		if (!bResult)
			return;

		CInternetSession session;
		session.SetOption(INTERNET_OPTION_CONNECT_TIMEOUT, nTimeOut);
		session.SetOption(INTERNET_OPTION_CONNECT_RETRIES, 1);
		CHttpConnection *connection = session.GetHttpConnection(sServer, wPort);
		if (connection)
		{
			CHttpFile *httpfile = connection->OpenRequest(
				CHttpConnection::HTTP_VERB_GET
				,sObject
				);
			if(httpfile->SendRequest())
			{

				CString verb = httpfile->GetVerb();
				CString filename = httpfile->GetFileName();
				CString url = httpfile->GetFileURL();
				CString info = "";
				DWORD state;
				if(httpfile->QueryInfoStatusCode(state))
				{
					response.SetHeaderState(state);
				}
				httpfile->QueryInfo(HTTP_QUERY_CONTENT_LENGTH, info);

				CString content = "";
		
				while(httpfile->ReadString(content))
				{
					response.SetContent(content);
				}
			}
		}

		//update all views
		((CDocument*)this)->UpdateAllViews(NULL);

	}
	catch(CInternetException* e)
	{
		AfxMessageBox("Connection error!");
	}
}

CSize& CMDITestGetPostDoc::GetDocSize(void)
{
	//�����ĵ���SIZE��
	//CScrollView��ˢ��ʱ����ȡ��ֵ������ʾ������
	//���ʡ�Լ����ˣ�ֱ��ʹ�ó�����Ļ��С��2468
	CSize size(2468,2468);
	return size;
}


void CMDITestGetPostDoc::OnMenuChangeView(CCmdUI *pCmdUI)
{
	// TODO: �ڴ���������������
	if (response.GetHeaderState() == 200)
	{
		pCmdUI->Enable(true);
	}
	else
	{
		pCmdUI->Enable(false);
	}
}


void CMDITestGetPostDoc::OnMenuChangeView()
{
	// TODO: �ڴ���������������
	((CMDITestApp*)AfxGetApp())->SwitchView();
}


CString CMDITestGetPostDoc::GetURI(void) const
{
	return m_uri;
}
