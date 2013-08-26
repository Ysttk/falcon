// IEStub.h : CIEStub 的声明

#pragma once
#include "resource.h"       // 主符号

#include "falcon_i.h"

#include "exdispid.h"
#include "shlguid.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// CIEStub

class ATL_NO_VTABLE CIEStub :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIEStub, &CLSID_IEStub>,
	public IObjectWithSiteImpl<CIEStub>,
	public IDispatchImpl<IIEStub, &IID_IIEStub, &LIBID_falconLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispEventImpl<1, CIEStub, &DIID_DWebBrowserEvents2, &LIBID_SHDocVw, 1, 1>
{
public:
	CIEStub()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_IESTUB)

DECLARE_NOT_AGGREGATABLE(CIEStub)

BEGIN_COM_MAP(CIEStub)
	COM_INTERFACE_ENTRY(IIEStub)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectWithSite)
END_COM_MAP()


BEGIN_SINK_MAP(CIEStub)

END_SINK_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(SetSite)(IUnknown * pUnkSite);  

private:
	CComPtr<IWebBrowser2> m_spWebBrowser;
	BOOL m_fAdvise;
};

OBJECT_ENTRY_AUTO(__uuidof(IEStub), CIEStub)
