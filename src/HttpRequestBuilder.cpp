#include "HttpRequestBuilder.hpp"
#include "GetRequestClient.hpp"
#include "PostRequestClient.hpp"
#include "PutRequestClient.hpp"
#include <string>

HttpRequestBuilder::HttpRequestBuilder(REQUEST_TYPE requestType, const std::string& url)
{
    switch (requestType)
    {
    case GET_REQUEST:
        m_httpRequest = std::make_unique<GetRequestClient>(url);
        break;
    case POST_REQUEST:
        m_httpRequest = std::make_unique<PostRequestClient>(url);
        break;
    case PUT_REQUEST:
        m_httpRequest = std::make_unique<PutRequestClient>(url);
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
    m_httpRequest->addDataToBody(std::make_shared<std::string>(data));
    return *this;
}

std::unique_ptr<HttpRequest> HttpRequestBuilder::build()
{
    return std::move(m_httpRequest);
}
