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
