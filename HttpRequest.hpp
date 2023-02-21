#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <curl/curl.h>
#include <iostream>

class HttpRequest
{
    static uint32_t s_HttpClientsInUseCount;
    static bool s_isGlobalyInitialized;

public:
    static void initCurlGlobal();
    static size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string *data);
    HttpRequest();
    virtual ~HttpRequest();
};

#endif