#pragma once

#include <string>
#include "FourOperations.h"

#ifndef _WWW_YESDATA_NET_DLL_EXPORT_
#define DLLCALLBACK   __declspec( dllimport )
#else
#define DLLCALLBACK   __declspec( dllexport )
#endif
#define CMethod extern "C"

CMethod DLLCALLBACK  void ParseSourse(const wchar_t* pSourse);