#pragma once
#include <vector>

using namespace std;

//internal class define the header info of HTTP response 
class CHTTPResponseHeader
{
public:
	CHTTPResponseHeader();
	~CHTTPResponseHeader();
	DWORD GetState() const;
	void SetState(const DWORD& val);

private:
	DWORD state;
};

class CHTTPResponse
{	
public:
	CHTTPResponse(void);
	~CHTTPResponse(void);
	const DWORD GetHeaderState() const;
	void SetHeaderState(const DWORD& state);
	const vector<CString> GetContent() const;
	void SetContent(const CString& val);
private:
	CHTTPResponseHeader header;
	vector<CString> content;
};

