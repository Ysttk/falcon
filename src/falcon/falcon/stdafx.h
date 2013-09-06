// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// 某些 CString 构造函数将是显式的

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>

using namespace ATL;


#include <cassert>

// include log4cxx header files.
#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/helpers/exception.h"

using namespace log4cxx;
using namespace log4cxx::helpers;

extern LoggerPtr rootLogger;

#define LOG_DEBUG(msg)	LOG4CXX_DEBUG(rootLogger, msg)
#define LOG_INFO(msg)	LOG4CXX_INFO(rootLogger, msg)
#define LOG_WARN(msg)	LOG4CXX_WARN(rootLogger, msg)
#define LOG_ERROR(msg)	LOG4CXX_ERROR(rootLogger, msg)
#define LOG_FATAL(msg)	LOG4CXX_FATAL(rootLogger, msg)
