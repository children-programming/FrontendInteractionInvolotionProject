#pragma once

#ifdef _WIN32_WCE
#error "Windows CE ��֧�� CHtmlView��"
#endif 

// CMDITestGetPostHtmlView Html ��ͼ

class CMDITestGetPostHtmlView : public CHtmlView
{
	DECLARE_DYNCREATE(CMDITestGetPostHtmlView)

public:
	CMDITestGetPostHtmlView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMDITestGetPostHtmlView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* /*pDC*/);
public:
	virtual void OnInitialUpdate();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	afx_msg void OnPaint();
};


