/********************************************************************
// 
// 
//    
// Created On 01/17/2014
// Updated On 01/29/2014
// CopyRight Yes!Data  http://www.yesdata.net
//
********************************************************************/
#pragma
#include <string>
#include <list>
using namespace std;

namespace www_yesdata_net
{
	class CKeyWords
	{
	public:
		CKeyWords();

	public:
		//Verify that whether the given word a key word or not . True:yes, a keyword; False: not a keyword
		bool VerifyKeyWord(wstring&);

	private:
		list<wstring> key_word_list;
	};
}