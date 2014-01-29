#pragma once
#include <string>
#include <iostream>
#include "exprnode.h"
#include "Expr.h"

using namespace std;

namespace www_yesdata_net
{
	class CExprUnaryNode :
		public CExprNode
	{

		//friend wostream& operator<<(wostream&, CExprUnaryNode&);
		friend class CExpr;
	public:
		// unary for int type
		//CExprUnaryNode(wstring o, int v);
		CExprUnaryNode(const wstring o, const CExpr& v);
		virtual ~CExprUnaryNode(void);

	protected:
		CExprUnaryNode(void); //		

	protected:
		virtual void print(wostream&);
		virtual CExprUnaryNode* copy();

	private:
		CExpr node;
		wstring op;

	};
}
