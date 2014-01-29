/********************************************************************
// 
// 
//    
// Created On 01/17/2014
// Updated On 01/29/2014
// CopyRight Yes!Data  http://www.yesdata.net
//
********************************************************************/
#pragma once
#include "exprnode.h"
#include "Expr.h"
#include <iostream>

using namespace std;

namespace www_yesdata_net
{
	class CExprIntNode :
		public CExprNode
	{
		//friend wostream& operator<<(wostream&, CExprIntNode&);
		friend class CExpr;
	public:
		CExprIntNode(int);
		virtual ~CExprIntNode(void);
	protected:
		CExprIntNode(void);
		virtual void print(wostream&);
		virtual CExprIntNode* copy();
	private:
		int val;
	};
}
