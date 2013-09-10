#include "StdAfx.h"
#include "IProcess.h"
#include "BaseException.h"

int IProcess::GlobalIdCounter = 0;

IProcess::IProcess(void) : isCurrentBuildingSteps(false), id(GlobalIdCounter++)
{
}

IProcess::~IProcess(void)
{
}

bool IProcess::IsTargetPage(IPage* a_Page) {
	return m_NextStep->IsTargetPage(a_Page);
}

bool IProcess::ProcessPage(IPage* a_Page) {
	bool processResult;
	try {
		processResult = m_NextStep->ProcessPage(a_Page);
		m_NextStepRetryTimes--;
	} catch (CBaseException* exception) {
		processResult = false;
		LOG_INFO(exception->GetMessage());
	}
	if (processResult) {
		m_NextStep = m_Steps[++m_NextStepIndex];
		m_NextStepRetryTimes = m_StepRetryTimes[m_NextStep];
		return true;
	} else if (m_NextStepRetryTimes >= 0) 
		return ProcessPage(a_Page);
	else
		return false;
	
}