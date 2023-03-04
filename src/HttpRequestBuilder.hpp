#ifndef HTTP_REQUEST_BUILDER_HPP
#define HTTP_REQUEST_BUILDER_HPP

#include <string>
#include "HttpRequest.hpp"
#include <memory>

class HttpRequestBuilder{
private:
    std::unique_ptr<HttpRequest> m_httpRequest{nullptr};
public:
    enum REQUEST_TYPE{
        POST_REQUEST,
        GET_REQUEST,
        PUT_REQUEST
    };

    HttpRequestBuilder(REQUEST_TYPE requestType, const std::string& url);
    HttpRequestBuilder& addDataToHeader(const std::string& data);
    HttpRequestBuilder& addJWTtokenToHeader(const std::string& jwtToken);
    HttpRequestBuilder& addDataToBody(const std::string& data);
    std::unique_ptr<HttpRequest> build();

};

#endif