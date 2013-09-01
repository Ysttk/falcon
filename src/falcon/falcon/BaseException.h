#pragma once

class CBaseException
{
public:
	CBaseException(void);
	virtual ~CBaseException(void);
	virtual std::string GetMessage(void) =0 ;
};
