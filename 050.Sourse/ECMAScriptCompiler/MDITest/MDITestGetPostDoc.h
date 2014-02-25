#pragma once
#include "stdafx.h"
#include "mditestdoc.h"
#include "resource.h"       // 主符号
#include "HTTPResponse.h"

class CMDITestGetPostDoc :
	public CDocument
{
protected: // 仅从序列化创建
	CMDITestGetPostDoc();
	DECLARE_DYNCREATE(CMDITestGetPostDoc)
public:
	~CMDITestGetPostDoc(void);

// 生成的消息映射函数
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

