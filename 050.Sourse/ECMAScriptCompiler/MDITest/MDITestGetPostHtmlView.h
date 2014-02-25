#pragma once

#ifdef _WIN32_WCE
#error "Windows CE 不支持 CHtmlView。"
#endif 

// CMDITestGetPostHtmlView Html 视图

class CMDITestGetPostHtmlView : public CHtmlView
{
	DECLARE_DYNCREATE(CMDITestGetPostHtmlView)

public:
	CMDITestGetPostHtmlView();           // 动态创建所使用的受保护的构造函数
	virtual ~CMDITestGetPostHtmlView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* /*pDC*/);
public:
	virtual void OnInitialUpdate();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	afx_msg void OnPaint();
};


