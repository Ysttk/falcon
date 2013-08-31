#pragma once
#include <vector>
#include <map>
#include "IStep.h"
#include "IPage.h"

class IProcess
{
public:
	IProcess(void);
	~IProcess(void);

	bool IsTargetPage(IPage* a_Page);
	bool ProcessPage(IPage* a_Page);

	bool BeginBuildSteps() {
		if (isCurrentBuildingSteps) 
			return false;
		isCurrentBuildingSteps = true;
		return true;
	}

	bool AddStep(IStep* cStep, int retryTimes=1) {
		if ( !isCurrentBuildingSteps) return false;
		m_Steps.push_back(cStep);
		m_StepRetryTimes.insert(std::make_pair<IStep*, int>(cStep, retryTimes));
		return true;
	}
	void EndBuildSteps() {
		isCurrentBuildingSteps = false;
		RetryNextStep();
	}

	bool ResetNextStep() {
		if (isCurrentBuildingSteps) return false;
		m_NextStep = m_Steps[0];
		m_NextStepRetryTimes = m_StepRetryTimes[m_NextStep];
		m_NextStepIndex = 0;
		return true;
	}
	
private:
	bool isCurrentBuildingSteps;

	std::vector<IStep*> m_Steps;
	std::map<IStep*, int> m_StepRetryTimes;

	int m_NextStepRetryTimes;
	IStep* m_NextStep;
	int m_NextStepIndex;

};
