#include "ExprUnaryNode.h"
#include "MyTrace.h"

using namespace www_yesdata_net;

CExprUnaryNode::CExprUnaryNode(void):op(L""),node(0)
{
	CMyTrace::Print(L"CExprUnaryNode constructor default.");
}

// unary for int type
//CExprUnaryNode::CExprUnaryNode(wstring o, int v):op(o),val(v)
//{
//}

CExprUnaryNode::CExprUnaryNode(const wstring o, const CExpr& v):op(o),node(v)
{
	CMyTrace::Print(L"CExprUnaryNode constructor(wstring, CExpr&).");
}


CExprUnaryNode::~CExprUnaryNode(void)
{
	CMyTrace::Print(L"CExprUnaryNode destructor.");
}


// print evalled result
void CExprUnaryNode::print(wostream& o)
{
	//::operator<<(::operator<<(o,op), node);
	o<<op<<node;
}

CExprUnaryNode* CExprUnaryNode::copy()
{
	return new CExprUnaryNode(op, node);
}

//wostream& operator<<(wostream& o, CExprUnaryNode& node)
//{
//	node.print(o);
//	return o;
//}