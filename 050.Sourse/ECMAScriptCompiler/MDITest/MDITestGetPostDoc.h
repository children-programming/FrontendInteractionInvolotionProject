#pragma once
#include "stdafx.h"
#include "mditestdoc.h"
#include "resource.h"       // ������

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
	void SetURI(const CString& uri) const;
	void StartSimulatingGet(void) const;
private:
	// //URI
	CString m_uri;
};

