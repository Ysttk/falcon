#pragma once
#include "IPage.h"

class IStep
{
public:
	IStep(void);
	virtual ~IStep(void);

	virtual bool IsTargetPage(IPage*) =0;

	virtual bool ProcessPage(IPage*) =0;
};
