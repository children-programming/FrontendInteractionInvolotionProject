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
#include <string>

using namespace std;

namespace www_yesdata_net
{
	class AST
	{
	public:
		AST(void);
		AST(wstring&);
		~AST(void);
	public:
		void GenerateAST();

	private:
		wstring sourse;
	};
}

