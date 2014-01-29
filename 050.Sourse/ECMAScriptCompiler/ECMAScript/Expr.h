#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace www_yesdata_net
{

	class CExprNode;
	class CExprIntNode;
	class CExprUnaryNode;
	class CExprBinaryNode;
	
	class CExpr
	{
	public:
			friend wostream& operator<<(wostream&, CExpr&);
		public:
			CExpr(void);
			CExpr(int v);
			//CExpr(const wstring o, const int v);
			CExpr(const wstring o, const CExpr& v);
			//CExpr(const int v1, const wstring o, const int v2);	
			CExpr(const CExpr& v1, const wstring o, const CExpr& v2);	
			~CExpr(void);
		public:	
			CExpr(const CExpr& exp);
			void print(wostream&);
			CExpr& operator= (const CExpr& exp);
			//CExpr copy();
		private:
			CExprNode* node;

	};

	wostream& operator<<(wostream&, CExpr&);
}

