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
	enum SYMBOL_TYPE
	{
		 NAME =1
		,OPERATOR
		,PROCEDURE
		,VALUE
	} enum_symbol_type;

	class SymbolTable
	{
	public:
		SymbolTable(void);
		~SymbolTable(void);

	public:
		void perform();

	private:
		/*wstring name;
		bool keyword;
		SYMBOL_TYPE type;
		SymbolTable& item;*/

	};

}
