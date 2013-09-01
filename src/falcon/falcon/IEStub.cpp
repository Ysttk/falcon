// IEStub.cpp : CIEStub 的实现

#include "stdafx.h"
#include "IEStub.h"

#include "shobjidl.h"

#include <shlobj.h>
// CIEStub

LoggerPtr rootLogger(Logger::getRootLogger());

STDMETHODIMP CIEStub::SetSite(IUnknown* pUnkSite)  
   {  
	 LOG4CXX_INFO(rootLogger, "IEStub::GetSite Called");
    if(pUnkSite!=NULL)  
    {
		//缓存指向IWebBrowser2的指针。  
		HRESULT hr = pUnkSite->QueryInterface(IID_IWebBrowser2,(void**)&m_spWebBrowser); 

		if (SUCCEEDED(hr) && m_spWebBrowser!=0) {
		   hr = DispEventAdvise(m_spWebBrowser);
		   if (SUCCEEDED(hr)) {
			   m_fAdvise=TRUE;
		   }
	   }

    }  
    else  
    {  
		if (m_fAdvise) {
			DispEventUnadvise(m_spWebBrowser);
			m_fAdvise=FALSE;
		}
        //在此释放缓存的指针和其他资源。  
        m_spWebBrowser.Release();  
    }
    //返回基类实现  
    return IObjectWithSiteImpl::SetSite(pUnkSite);  
	//return 0;
}  