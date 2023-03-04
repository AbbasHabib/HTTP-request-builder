#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <curl/curl.h>
#include <iostream>
#include <atomic>

//! @brief  HttpRequest is an abstract class that
//!         every Http request type inherit from 
//!         and derive its functionalities
class HttpRequest
{
private:
    //! @brief  indicates if curl_global_init is initalized or not
    //!         it's an atomic operation to avoid multiple initialization
    //!         if concurrent access occurred
    static std::atomic<bool> s_isGloballyInitialized;
    static size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string *data);
    
protected:
    //! @brief CURL pointer used to initialize request params
    CURL *m_curlPtr{nullptr};
    //! @brief Http Request headers
    struct curl_slist* m_headers{NULL};
    //! @brief latest response inserted inside the responseString
    std::string m_responseString{};

public:

    static void initHttpRequestsGlobal();
    static void cleanHttpRequestsGlobal();
    //! @brief default constructor is deleted
    HttpRequest() = delete;
    
    //! @brief parameterized constructor
    HttpRequest(const std::string& url);

    //! @brief Add data to Request header
    //! @param data data to be added to request header
    void addDataToHeader(const std::string& data);

    //! @brief Add JWT token to Request header
    //! @param jwtToken token to be added to request header
    void addJWTtokenToHeader(const std::string& jwtToken);

    //! @brief sends GetRequestClient
    //! @return return response string
    const std::string getResponse();

    //! @brief sends GetRequestClient
    //! @return true if succeed
    //! @return false if fails
    CURLcode send();

    //! @brief every request inherit from it to initialize its request params
    virtual bool init() = 0;

    //! @brief destructor
    virtual ~HttpRequest();
};

#endif