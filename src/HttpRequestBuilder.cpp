#include "HttpRequestBuilder.hpp"
#include "GetRequestClient.hpp"
#include <string>

HttpRequestBuilder::HttpRequestBuilder(REQUEST_TYPE requestType, const std::string& url)
{
    switch (requestType)
    {
    case GET_REQUEST:
        m_httpRequest = std::make_unique<GetRequestClient>(url);
        break;
    case POST_REQUEST:
        // m_httpRequest = std::make_unique<GetRequestClient>(url);
        break;
    case PUT_REQUEST:
        // m_httpRequest = std::make_unique<GetRequestClient>(url);
        break;
    default:
        break;
    }

    m_httpRequest->init();
}

HttpRequestBuilder& HttpRequestBuilder::addDataToHeader(const std::string& data)
{
    m_httpRequest->addDataToHeader(data);
    return *this;
}

HttpRequestBuilder& HttpRequestBuilder::addJWTtokenToHeader(const std::string& jwtToken)
{
    m_httpRequest->addJWTtokenToHeader(jwtToken);
    return *this;
}


HttpRequestBuilder& HttpRequestBuilder::addDataToBody(const std::string& data)
{
    // m_httpRequest->addJWTtokenToHeader(data);
    return *this;
}

std::unique_ptr<HttpRequest> HttpRequestBuilder::build()
{
    return std::move(m_httpRequest);
}