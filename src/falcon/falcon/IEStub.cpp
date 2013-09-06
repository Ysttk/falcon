// IEStub.cpp : CIEStub 的实现

#include "stdafx.h"
#include "IEStub.h"

#include "shobjidl.h"

#include <shlobj.h>
// CIEStub
#include "Iepmapi.h"

#include "log4cxx/fileappender.h"
#include "log4cxx/rollingfileappender.h"


LoggerPtr rootLogger(Logger::getRootLogger());


void CIEStub::AdjustOutputLogFilePathByPermission() 
{
	static bool FirstTimeLoad = true;
	LOG_INFO("CIEStub:AdjustOutputLogFilePathByPermission Called with 'FirstTimeLoad'==:"+FirstTimeLoad);
	if (FirstTimeLoad) {
		 FirstTimeLoad = false;
		 LOG_DEBUG("AdjustOutputLogFilePathByPermisson try to adjust path");

		 AppenderList appenderList;
		 appenderList = rootLogger->getAllAppenders();

		 LogString logOutputFileName;
		 int num_appender = appenderList.size();
		 LOG_DEBUG("Number of Appenders:"+num_appender);
		 
		 for (int i=0; i<num_appender; i++) {
			 AppenderPtr appender = appenderList[i];
			 LOG_DEBUG(LogString(_T("Current processing appender:")).append(appender->getName()));
			 Appender* appenderSelf = appender.operator->();
			 FileAppender* fileAppender;
			 if (fileAppender = dynamic_cast<FileAppender *>(appenderSelf)) {
				logOutputFileName = fileAppender->getFile();
				LOG_DEBUG(LogString(_T("Found one file appender:")).append(logOutputFileName));
				 LPWSTR lpTempDir;
				 HRESULT hr =IEGetWriteableFolderPath(FOLDERID_InternetCache, &lpTempDir);
				 LogString NewOutputFullPath;
				 NewOutputFullPath = NewOutputFullPath.append(lpTempDir);
				 NewOutputFullPath = NewOutputFullPath.append(_T("\\"));
				 NewOutputFullPath = NewOutputFullPath.append(logOutputFileName);
				 CoTaskMemFree(lpTempDir);
				 
				 FileAppender* newFileAppender = new RollingFileAppender(
					 fileAppender->getLayout(), NewOutputFullPath);
				 AppenderPtr newAppender(newFileAppender);
				 
				 rootLogger->removeAppender(appender);
				 rootLogger->addAppender(newAppender);
				 
				 LOG_DEBUG(LogString(_T("New File Path altered to")).append(NewOutputFullPath));
			 }

		 }

	 }	

}


STDMETHODIMP CIEStub::SetSite(IUnknown* pUnkSite)  
   {  
	LOG_INFO("SetSite Called");

#ifdef ADJUST_OUTPUT_LOG_DIR
	AdjustOutputLogFilePathByPermission();
#endif

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

    } else {  
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

void STDMETHODCALLTYPE CIEStub::OnDocumentComplete(IDispatch* pDisp,VARIANT* pvarURL) 
{
	USES_CONVERSION;
	BSTR url = pvarURL->bstrVal;
	
	LOG_DEBUG(LogString(_T("IEStub::OnDocumentComplete Called with url:")).append(url));
	HRESULT hr = S_OK;   
    // 查询 IWebBrowser2 接口。   
    CComQIPtr<IWebBrowser2> spTempWebBrowser = pDisp;   
    // 此事件是否与顶级浏览器相关联?   
    if (spTempWebBrowser && m_spWebBrowser && m_spWebBrowser.IsEqualObject(spTempWebBrowser))   
    {   
		LOG_DEBUG("Found related page");
        // 从浏览器中获取当前文档对象……   
        CComPtr<IDispatch>  spDispDoc;   
        hr = m_spWebBrowser->get_Document(&spDispDoc);   
        if (SUCCEEDED(hr))   
        {   
            //查询 HTML 文档。   
            CComQIPtr<IHTMLDocument2> spHTMLDoc = spDispDoc;
			CComPtr<IHTMLElement> spBody;
			hr = spHTMLDoc->get_body(&spBody);
			LOG_INFO(LogString(_T("Found Document at url:")).append(url));
			CComBSTR bodyContent;
			hr = spBody->get_innerText(&bodyContent);
			LOG_DEBUG(LogString(_T("Page Content:")).append(bodyContent));
		}
	}
}
