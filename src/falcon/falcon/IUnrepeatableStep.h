#pragma once
#include "istep.h"

class IUnrepeatableStep :
	public IStep
{
public:
	IUnrepeatableStep(void);
	~IUnrepeatableStep(void);

	virtual bool IsTargetPage(IPage*) =0;

	virtual bool ProcessPage(IPage*) =0;
};
