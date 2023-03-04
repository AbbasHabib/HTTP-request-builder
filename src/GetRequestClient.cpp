#include "GetRequestClient.hpp"
#include <string>

GetRequestClient::GetRequestClient(std::string url) : HttpRequest(url)
{
    if (!m_curlPtr)
    {
        std::cout << "curl_easy_init failed !! \n";
        return;
    }
}

bool GetRequestClient::init()
{
    if (!m_curlPtr)
    {
        std::cout << "curl_easy_init failed !! \n";
        return false;
    }
    curl_easy_setopt(m_curlPtr, CURLOPT_HTTPGET, 1L);
    //! switch off the progress meter
    curl_easy_setopt(m_curlPtr, CURLOPT_NOPROGRESS, 1L);
    //! maximum number of redirects
    curl_easy_setopt(m_curlPtr, CURLOPT_MAXREDIRS, 50L);
    
    return true;
}
