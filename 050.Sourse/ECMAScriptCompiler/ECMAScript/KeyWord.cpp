#include "KeyWord.h"
#include <algorithm>

using namespace www_yesdata_net;

CKeyWords::CKeyWords()
{
	key_word_list.push_back(L"+");
	key_word_list.push_back(L"-");
	key_word_list.push_back(L"*");
	key_word_list.push_back(L"/");
	key_word_list.push_back(L"function");
	key_word_list.push_back(L"(");
	key_word_list.push_back(L")");
	key_word_list.push_back(L"alert");
	key_word_list.push_back(L"print");
	key_word_list.push_back(L"\"");
	key_word_list.push_back(L";");
	
}

bool CKeyWords::VerifyKeyWord(wstring& the_given_word)
{
	list<wstring>::iterator it_result;
	it_result = find(key_word_list.begin(),key_word_list.end(),the_given_word);
	if(it_result != key_word_list.end())//found it
		return true;
	else
		return false;
}