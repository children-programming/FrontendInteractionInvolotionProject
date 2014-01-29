#include "Expr.h"
#include "ExprIntNode.h"
#include "ExprUnaryNode.h"
#include "ExprBinaryNode.h"
#include "ExprNode.h"
#include "MyTrace.h"

using namespace www_yesdata_net;

CExpr::CExpr(void):node(0)
{
	CMyTrace::Print(L"CExpr default constructor.");

}

CExpr::CExpr(int v)
{
	node = new CExprIntNode(v);
	CMyTrace::Print(L"CExpr constructor(int).");
}

//delegate of CExprUnuayNode
//CExpr::CExpr(const wstring o, const int v)
//{
//	node = new CExprUnaryNode(o, v);
//}

CExpr::CExpr(const wstring o, const CExpr& v)
{
	
	node = new CExprUnaryNode(o, v);
	CMyTrace::Print(L"CExpr constructor(wstring, CExpr).");
}

//CExpr::CExpr(const int v1, const wstring o,const int v2)
//{
//	node = new CExprBinaryNode( v1, o, v2);
//}

CExpr::CExpr(const CExpr& v1, const wstring o, const CExpr& v2)
{

	node = new CExprBinaryNode(v1, o, v2);
	CMyTrace::Print(L"CExpr constructor(CExpr, wstring, CExpr).");
}

CExpr::CExpr(const CExpr& exp)
{
	*this = exp;
}

CExpr& CExpr::operator= (const CExpr& exp)
{
	if(this->node != exp.node)
	{
		this->node = exp.node->copy();
	}
	CMyTrace::Print(L"CExpr& CExpr::operator= (const CExpr& exp).");
	return *this;
}

CExpr::~CExpr(void)
{
	CMyTrace::Print(L"CExpr destructor.");
	if (node != 0)
	{
		delete node;
	}
}

void CExpr::print(wostream& o)
{
	node->print(o);
}

wostream& www_yesdata_net::operator<<(wostream& o, CExpr& e)
{
	e.print(o);
	return o;
}