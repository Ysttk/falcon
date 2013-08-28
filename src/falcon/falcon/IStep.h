#pragma once
#include "IPage.h"

class IStep
{
public:
	IStep(void);
	virtual ~IStep(void)=0;

	virtual bool IsTargetPage(IPage*) =0;

	virtual bool ProcessPage(IPage*) =0;
};
