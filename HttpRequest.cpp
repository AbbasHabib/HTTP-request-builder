#include "HttpRequest.hpp"

uint32_t HttpRequest::s_HttpClientsInUseCount = 0;
bool HttpRequest::s_isGlobalyInitialized = false;

HttpRequest::HttpRequest()
{
    if (HttpRequest::s_HttpClientsInUseCount == 0)
        initCurlGlobal();
    s_HttpClientsInUseCount++;

    std::cout << "new request client number of requests -> " << s_HttpClientsInUseCount << '\n';
}

void HttpRequest::initCurlGlobal()
{
    if (s_isGlobalyInitialized)
    {
        try
        {
            std::cout << "Global init !!\n";
            curl_global_init(CURL_GLOBAL_DEFAULT);
        }
        catch (...)
        {
            std::cout << "Error initializing CURL Global ::HttpRequest \n";
        }
    }
    else
    {
        s_isGlobalyInitialized = true;
    }
}

HttpRequest::~HttpRequest()
{
    s_HttpClientsInUseCount--;
    std::cout << "request client left number of requests -> " << s_HttpClientsInUseCount << '\n';
    if (s_HttpClientsInUseCount == 0)
    {
        std::cout << "Global Clean up!!\n";
        curl_global_cleanup();
    }
}

size_t HttpRequest::writeFunction(void *ptr, size_t size, size_t nmemb, std::string *data)
{
    data->append((char *)ptr, size * nmemb);
    return size * nmemb;
}

