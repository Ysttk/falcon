#include "StdAfx.h"
#include "ProcessMgr.h"

ProcessMgr::ProcessMgr(void)
{
}

ProcessMgr::~ProcessMgr(void)
{
}


void ProcessMgr::ProcessPage(IPage* a_Page) {
	for (std::vector<IProcess*>::iterator itr = m_Processes.begin();
		itr != m_Processes.end(); ++itr) {
		IProcess* process = *itr;
		assert(process);
		if (process->IsTargetPage(a_Page)) {
			process->ProcessPage(a_Page);
			return;
		}
	}

}