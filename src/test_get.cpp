#include "HttpRequestBuilder.hpp"
#include <iostream>
#include <thread>
#include <memory>

static constexpr char CONTENT_TYPE_JSON[] = "Content-Type: application/json";


void sendRequest()
{
    HttpRequestBuilder HttpBuilder(HttpRequestBuilder::POST_REQUEST, "https://abbas.requestcatcher.com/test");

    std::string jsonObj = "{ \"name\" : \"abbas\" , \"age\" : \"55\" }";
    std::string ff = "TOKEN";
    std::unique_ptr<HttpRequest> httpRequest = HttpBuilder
                                .addJWTtokenToHeader(ff)
                                .addDataToBody(std::move(jsonObj))
                                .addDataToHeader("head", "data1")
                                .build();

    std::cout << jsonObj << '\n';

    if (httpRequest->send() == CURLE_OK)
    {
        std::cout << "[" << httpRequest->getResponse() << "]\n";
        std::cout << "[" << httpRequest->getResponseHeader() << "]\n";
    }
}

int main(int argc, char *argv[])
{
    sendRequest();
 
    HttpRequest::cleanHttpRequestsGlobal();
}