#pragma once
#include "stdafx.h"
#include "mditestdoc.h"
#include "resource.h"       // ������
#include "HTTPResponse.h"

class CMDITestGetPostDoc :
	public CDocument
{
protected: // �������л�����
	CMDITestGetPostDoc();
	DECLARE_DYNCREATE(CMDITestGetPostDoc)
public:
	~CMDITestGetPostDoc(void);

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnUpdateSimulaterGet(CCmdUI *pCmdUI);
	afx_msg void OnMenuChangeView(CCmdUI *pCmdUI);
	void SetURI(const CString& uri);
	void StartSimulatingGet(void);
	const CHTTPResponse& GetResponseData() const;
private:
	// //URI
	CString m_uri;
	CHTTPResponse response;
	
public:
	CSize& GetDocSize(void);
	
	afx_msg void OnMenuChangeView();
	CString GetURI(void) const;
};

