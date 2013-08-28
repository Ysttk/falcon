#pragma once
#include <vector>
#include "IStep.h"
#include "IPage.h"

class IProcess
{
public:
	IProcess(void);
	~IProcess(void);

	bool IsTargetPage(IPage* a_Page);
	bool ProcessPage(IPage* a_Page);
private:
	std::vector<IStep*> m_Steps;
	IStep* m_NextStep;
};
