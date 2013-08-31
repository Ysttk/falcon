#pragma once
#include "baseexception.h"

class CTimeoutExcp :
	public CBaseException
{
public:
	CTimeoutExcp(void);
	virtual ~CTimeoutExcp(void);
};
