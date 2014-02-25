
// MDITest.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MDITest.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "MDITestDoc.h"
#include "MDITestView.h"

#include "ChildGetPostFrame.h"
#include "MDITestGetPostDoc.h"
#include "MDITestGetPostView.h"
#include "MDITestGetPostHtmlView.h"
#include <AFXPRIV.H>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDITestApp

BEGIN_MESSAGE_MAP(CMDITestApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CMDITestApp::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CMDITestApp ����

CMDITestApp::CMDITestApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���:
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MDITest.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CMDITestApp ����

CMDITestApp theApp;


// CMDITestApp ��ʼ��

BOOL CMDITestApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)


	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_MDITestTYPE,
		RUNTIME_CLASS(CMDITestDoc),
		RUNTIME_CLASS(CChildFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(CMDITestView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	//Added by yuanaiqing
	CMultiDocTemplate* pDocTemplate2;
	pDocTemplate2 = new CMultiDocTemplate(IDR_MDITestGetPostTYPE,
		RUNTIME_CLASS(CMDITestGetPostDoc),
		RUNTIME_CLASS(CChildGetPostFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(CMDITestGetPostView));
	if (!pDocTemplate2)
		return FALSE;
	AddDocTemplate(pDocTemplate2);

	// ������ MDI ��ܴ���
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	// �� MDI Ӧ�ó����У���Ӧ������ m_pMainWnd ֮����������
	// ������/��
	m_pMainWnd->DragAcceptFiles();

	// ������׼ shell ���DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// ���á�DDE ִ�С�
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);


	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// �������ѳ�ʼ���������ʾ����������и���
	pMainFrame->ShowWindow(SW_SHOWMAXIMIZED);
	pMainFrame->UpdateWindow();

	// Initiate another CHtmlView
	//CView* pActiveView = ((CFrameWnd*)m_pMainWnd)->GetActiveView();//for SDI
	CView* pActiveView = pMainFrame->MDIGetActive()->GetActiveView();//for MDI
	
	m_pOldView = pActiveView;
	m_pNewView = (CView*)(new CMDITestGetPostHtmlView());
	if (NULL == m_pNewView)
	{
		return FALSE;
	}
	//CDocument* pCurrentDoc = ((CFrameWnd*)m_pMainWnd)->GetActiveDocument();//for SDI
	CDocument* pCurrentDoc = pMainFrame->MDIGetActive()->GetActiveDocument();//for MDI
	CCreateContext newContext;
	newContext.m_pNewViewClass = NULL;
	newContext.m_pNewDocTemplate = NULL;
	newContext.m_pLastView = NULL;
	newContext.m_pCurrentFrame = NULL;
	newContext.m_pCurrentDoc = pCurrentDoc;
	//The ID of the initial active view is AFX_IDW_PANE_FIRST
	//Increamenting this value by one for additional views works
	//in the standard document/view case but the technique cannot 
	//be extended for the CSplitterWnd
	UINT viewID = AFX_IDW_PANE_FIRST + 1;
	CRect rect(0, 0, 0, 0);
	//m_pNewView->Create(NULL, _T("HTML VIEW"), WS_CHILD, rect, m_pMainWnd, viewID, &newContext);//for SDI
	m_pNewView->Create(NULL, _T("HTML VIEW"), WS_CHILD, rect, pMainFrame->MDIGetActive(), viewID, &newContext);//for MDI
	m_pNewView->SendMessage(WM_INITIALUPDATE, 0, 0);


	return TRUE;
}

int CMDITestApp::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CMDITestApp ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CMDITestApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMDITestApp ��Ϣ�������

CView* CMDITestApp::SwitchView()
{
	CView* pActiveView = ((CMainFrame*)m_pMainWnd)->MDIGetActive()->GetActiveView();

	CView* pNewView = NULL;
	if (pActiveView == m_pOldView)
	{
		pNewView = m_pNewView;
	}
	else
	{
		pNewView = m_pOldView;
	}
	
	//Exchange view window IDs so RecalLayout() works
#ifndef _WIN32
	UINT temp  = ::GetWindowWord(pActiveView->m_hWnd, GWW_ID);
	::SetWindowWord(pNewView->m_hWnd, GWL_ID, temp);
#else
	UINT temp  = ::GetWindowLong(pActiveView->m_hWnd, GWL_ID);
	::SetWindowLong(pActiveView->m_hWnd, GWL_ID, ::GetWindowLong(pNewView->m_hWnd, GWL_ID));
	::SetWindowLong(pNewView->m_hWnd, GWL_ID, temp);
#endif

	pActiveView->ShowWindow(SW_HIDE);
	pNewView->ShowWindow(SW_SHOW);
	//((CFrameWnd*)m_pMainWnd)->SetActiveView(pNewView);
	((CMainFrame*)m_pMainWnd)->MDIGetActive()->SetActiveView(pNewView);
	//((CFrameWnd*)m_pMainWnd)->RecalcLayout();
	((CMainFrame*)m_pMainWnd)->MDIGetActive()->RecalcLayout();
	pNewView->Invalidate();

	return pNewView;
}
CView* CMDITestApp::GetOldView() const
{
	return m_pOldView;
}
void CMDITestApp::SetOldView(CView* val)
{
	m_pOldView = val;
}
CView* CMDITestApp::GetNewView() const
{
	return m_pNewView;
}
void CMDITestApp::SetNewView(CView* val)
{
	m_pNewView = val;
}

