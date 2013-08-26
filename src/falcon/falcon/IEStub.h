// IEStub.h : CIEStub ������

#pragma once
#include "resource.h"       // ������

#include "falcon_i.h"

#include "exdispid.h"
#include "shlguid.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
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
