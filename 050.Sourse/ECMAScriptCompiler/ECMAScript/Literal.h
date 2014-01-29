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

