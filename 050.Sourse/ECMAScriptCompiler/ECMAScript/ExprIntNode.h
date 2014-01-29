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
