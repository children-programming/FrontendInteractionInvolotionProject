/********************************************************************
// 
// parent class for Expr..., and this class will be used in class Expr
//
//
// 
// CopyRight Yes!Data  http://www.yesdata.net
//
********************************************************************/
#pragma once
#include <iostream>
#include "Expr.h"

using namespace std;

namespace www_yesdata_net
{
	class CExprNode
	{
		//friend wostream& operator<<(wostream&, CExprNode&);
		friend class CExpr;
	public:
		CExprNode(int v);
		virtual ~CExprNode(void);
	protected:
		CExprNode(void);
	protected:
		virtual void print(wostream&) = 0;
		virtual CExprNode* copy() = 0;
	};
}

