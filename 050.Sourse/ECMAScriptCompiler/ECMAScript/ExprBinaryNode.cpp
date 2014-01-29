#include "ExprBinaryNode.h"
#include "MyTrace.h"

using namespace www_yesdata_net;

CExprBinaryNode::CExprBinaryNode(void)
{
	CMyTrace::Print(L"CExprBinaryNode constructor default.");
}

//CExprBinaryNode::CExprBinaryNode(int v1, wstring o, int v2):op(o),val1(v1),val2(v2)
//{}

CExprBinaryNode::CExprBinaryNode(const CExpr& v1, const wstring o, const CExpr& v2)
	:op(o),node1(v1),node2(v2)
{
	CMyTrace::Print(L"CExprBinaryNode constructor(CExpr&, wstring, CExpr&).");
}


CExprBinaryNode::~CExprBinaryNode(void)
{
	CMyTrace::Print(L"CExprBinaryNode destructor.");
}

// print evalled result
void CExprBinaryNode::print(wostream& o)
{
	o<< L"(" << node1 << op << node2 << L")";
}

CExprBinaryNode* CExprBinaryNode::copy()
{
	return new CExprBinaryNode(node1, op, node2);
}

//wostream& operator<<(wostream& o, CExprBinaryNode& node)
//{
//	node.print(o);
//	return o;
//}