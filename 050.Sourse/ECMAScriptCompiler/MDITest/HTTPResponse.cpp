#include "StdAfx.h"
#include "HTTPResponse.h"

CHTTPResponseHeader::CHTTPResponseHeader():state(0)
{}
CHTTPResponseHeader::~CHTTPResponseHeader()
{}

DWORD CHTTPResponseHeader::GetState() const
{
	return state;
}
void CHTTPResponseHeader::SetState(const DWORD& val)
{
	state = val;
}


//------------------------------------------------
CHTTPResponse::CHTTPResponse(void)
{
}


CHTTPResponse::~CHTTPResponse(void)
{
}

const DWORD CHTTPResponse::GetHeaderState() const
{
	return header.GetState();
}

void CHTTPResponse::SetHeaderState(const DWORD& state)
{
	header.SetState(state);
}

const vector<CString> CHTTPResponse::GetContent() const
{
	return content;
}

void CHTTPResponse::SetContent(const CString& val)
{
	content.push_back(val);
}