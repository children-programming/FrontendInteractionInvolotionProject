/********************************************************************
// 
// 
//    
// Created On 01/17/2014
// Updated On 01/29/2014
// CopyRight Yes!Data  http://www.yesdata.net
//
********************************************************************/
#include "ExprNode.h"
#include "MyTrace.h"

using namespace www_yesdata_net;

//do not open the default structor function
CExprNode::CExprNode(void)
{
	CMyTrace::Print(L"CExprNode constructor default.");
}

CExprNode::CExprNode(int v)
{
	CMyTrace::Print(L"CExprNode constructor(int).");
}


CExprNode::~CExprNode(void)
{
	CMyTrace::Print(L"CExprNode destructor.");
	
}