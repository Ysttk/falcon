#include "StdAfx.h"
#include "IProcess.h"

IProcess::IProcess(void)
{
}

IProcess::~IProcess(void)
{
}

bool IProcess::IsTargetPage(IPage* a_Page) {
	return m_NextStep->IsTargetPage(a_Page);
}

bool IProcess::ProcessPage(IPage* a_Page) {
	return m_NextStep->ProcessPage(a_Page);
}