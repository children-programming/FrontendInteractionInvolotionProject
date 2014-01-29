#include "ExprIntNode.h"
#include "MyTrace.h"

using namespace www_yesdata_net;

CExprIntNode::CExprIntNode(void)
{
	CMyTrace::Print(L"CExprIntNode constructor default.");
}

CExprIntNode::CExprIntNode(int v):val(v)
{
	CMyTrace::Print(L"CExprIntNode constructor(int).");
}


CExprIntNode::~CExprIntNode(void)
{
	CMyTrace::Print(L"CExprIntNode destructor.");
}

void CExprIntNode::print(wostream& o)
{
	o<<val;
}

CExprIntNode* CExprIntNode::copy()
{
	return new CExprIntNode(val);
}

//wostream& operator<<(wostream& o, CExprIntNode& node)
//{
//	o<<node;
//	return o;
//}