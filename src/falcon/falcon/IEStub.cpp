// IEStub.cpp : CIEStub ��ʵ��

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
		//����ָ��IWebBrowser2��ָ�롣  
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
        //�ڴ��ͷŻ����ָ���������Դ��  
        m_spWebBrowser.Release();  
    }
    //���ػ���ʵ��  
    return IObjectWithSiteImpl::SetSite(pUnkSite);  
	//return 0;
}  