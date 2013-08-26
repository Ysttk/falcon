// dllmain.h : 模块类的声明。

class CfalconModule : public CAtlDllModuleT< CfalconModule >
{
public :
	DECLARE_LIBID(LIBID_falconLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_FALCON, "{BC966732-6A7D-4774-9959-3B8CD81B6762}")
};

extern class CfalconModule _AtlModule;
