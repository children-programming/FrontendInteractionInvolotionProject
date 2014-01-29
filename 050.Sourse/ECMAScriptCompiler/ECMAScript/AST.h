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

