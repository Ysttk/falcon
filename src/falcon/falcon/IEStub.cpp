// IEStub.cpp : CIEStub 的实现

#include "stdafx.h"
#include "IEStub.h"

#include "shobjidl.h"

#include <shlobj.h>
// CIEStub
#include "Iepmapi.h"

#include "log4cxx/fileappender.h"^


LoggerPtr rootLogger(Logger::getRootLogger());
bool FirstTimeLoad = true;


STDMETHODIMP CIEStub::SetSite(IUnknown* pUnkSite)  
   {  
	 
	 if (FirstTimeLoad) {
		 FirstTimeLoad = false;
		//PropertyConfigurator::configure("C:\\log4cxx.properties");

		 LOG4CXX_INFO(rootLogger, "IEStub::GetSite Called");
		 AppenderList appenderList;
		 appenderList = rootLogger->getAllAppenders();

		 LogString logOutputFileName;
		 int num_appender = appenderList.size();
		 for (int i=0; i<num_appender; i++) {
			 AppenderPtr appender = appenderList[i];
			 Appender* appenderSelf = appender.operator->();
			 FileAppender* fileAppender;
			 if (fileAppender = dynamic_cast<FileAppender *>(appenderSelf)) {

				logOutputFileName = fileAppender->getFile();
				 LPWSTR lpTempDir;
				 HRESULT hr =IEGetWriteableFolderPath(FOLDERID_InternetCache, &lpTempDir);
				 LogString NewOutputFullPath;
				 NewOutputFullPath = NewOutputFullPath.append(lpTempDir);
				 NewOutputFullPath = NewOutputFullPath.append(_T("\\"));
				 NewOutputFullPath = NewOutputFullPath.append(logOutputFileName);
				 CoTaskMemFree(lpTempDir);
				
				 fileAppender->setFile(NewOutputFullPath);

				 LOG4CXX_INFO(rootLogger, "New File Path altered");
			 }

		 }
	 }	




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