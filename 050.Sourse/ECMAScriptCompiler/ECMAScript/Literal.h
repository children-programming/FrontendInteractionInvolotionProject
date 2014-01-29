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
//template <class T>

namespace www_yesdata_net
{
	class CLiteral :
		public CExprNode
	{
	public:
		CLiteral(void);
		virtual  ~CLiteral(void);
	};
}

