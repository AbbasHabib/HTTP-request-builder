#include "HttpRequestBuilder.hpp"
#include <iostream>
#include <thread>
#include <memory>

static constexpr char CONTENT_TYPE_JSON[] = "Content-Type: application/json";

int main(int argc, char *argv[])
{

    HttpRequestBuilder HttpBuilder(HttpRequestBuilder::PUT_REQUEST, "https://abbas.requestcatcher.com/test");

    std::string jsonObj = "{ \"name\" : \"abbas\" , \"age\" : \"55\" }";
    
    std::unique_ptr<HttpRequest> httpRequest = HttpBuilder
                                .addDataToHeader("Accept: application/json")
                                .addDataToHeader("Content-Type: application/json")
                                .addDataToHeader("charset: utf-8")
                                .addDataToBody(jsonObj)
                                .build();

    if (httpRequest->send() == CURLE_OK)
    {
        std::cout << "[" << httpRequest->getResponse() << "]\n";
        std::cout << "[" << httpRequest->getResponseHeader() << "]\n";
    }
 
    HttpRequest::cleanHttpRequestsGlobal();
}