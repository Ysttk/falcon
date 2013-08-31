#pragma once
#include "istep.h"

class IRepeatableStep :
	public IStep
{
public:
	IRepeatableStep(void);
	~IRepeatableStep(void);
	virtual bool IsTargetPage(IPage*) =0;

	virtual bool ProcessPage(IPage*) =0;
};
