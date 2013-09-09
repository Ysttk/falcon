#pragma once

class IPage
{
public:
	IPage(void);
	virtual ~IPage(void)=0;
	virtual std::string GetUrl() =0;
	virtual void SetUrl(std::string) = 0;
	virtual int GetId() = 0;
};
