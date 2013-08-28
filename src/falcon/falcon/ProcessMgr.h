#pragma once
#include <vector>
#include "IProcess.h"
#include "IPage.h"

class ProcessMgr
{
public:
	ProcessMgr(void);
	~ProcessMgr(void);
	
	void ProcessPage(IPage* a_Page);
private:
	std::vector<IProcess*> m_Processes;
};
