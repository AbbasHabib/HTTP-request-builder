#include "GetRequestClient.hpp"
#include <string>

GetRequestClient::GetRequestClient(std::string url) : m_curlPtr(curl_easy_init())
{
    if (!m_curlPtr)
    {
        std::cout << "curl_easy_init failed !! \n";
        return;
    }

    //! HTTP version
    curl_easy_setopt(m_curlPtr, CURLOPT_USERAGENT, "curl/7.85.0");
    //! HTTP version
    curl_easy_setopt(m_curlPtr, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1);
    //! switch off the progress meter
    curl_easy_setopt(m_curlPtr, CURLOPT_NOPROGRESS, 1L);
    //! maximum number of redirects
    curl_easy_setopt(m_curlPtr, CURLOPT_MAXREDIRS, 50L);
    //! TCP keepalive probes will be sent
    curl_easy_setopt(m_curlPtr, CURLOPT_TCP_KEEPALIVE, 1L);
    //! send to url
    curl_easy_setopt(m_curlPtr, CURLOPT_URL, url.c_str());
    //! HttpRequest::writeFunction get's called with response data
    curl_easy_setopt(m_curlPtr, CURLOPT_WRITEFUNCTION, HttpRequest::writeFunction);
    //! data inserted inside m_resposneString
    curl_easy_setopt(m_curlPtr, CURLOPT_WRITEDATA, &m_resposneString);
}

bool GetRequestClient::send()
{
    //! Perform the request, res will get the return code
    CURLcode res = curl_easy_perform(m_curlPtr);
    //! Check for errors
    if (res != CURLE_OK)
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return false;
    }
    return true;
}

const std::string GetRequestClient::getResponse()
{
    return m_resposneString;
}

GetRequestClient::~GetRequestClient()
{
    curl_easy_cleanup(m_curlPtr);
}
