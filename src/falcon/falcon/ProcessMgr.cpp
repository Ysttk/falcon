#include "StdAfx.h"
#include "ProcessMgr.h"
#include "stdlib.h"


ProcessMgr::ProcessMgr(void)
{
}

ProcessMgr::~ProcessMgr(void)
{
}


void ProcessMgr::ProcessPage(IPage* a_Page) {
	char tmpStr[1024];
	LOG_INFO(LogString(_T("Iterating processes in Process Manage with Page Id:"))+Int2Str(a_Page->GetId()));
	for (std::vector<IProcess*>::iterator itr = m_Processes.begin();
		itr != m_Processes.end(); ++itr) {
		IProcess* process = *itr;
		assert(process);
		LOG_DEBUG(LogString(_T("Current process Id:"))+Int2Str((*itr)->GetId()));
		if (process->IsTargetPage(a_Page)) {
			process->ProcessPage(a_Page);
			return;
		}
	}

}