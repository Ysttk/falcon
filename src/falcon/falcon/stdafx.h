// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// ĳЩ CString ���캯��������ʽ��

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
