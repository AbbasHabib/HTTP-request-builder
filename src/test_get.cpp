#include "HttpRequestBuilder.hpp"
#include <iostream>
#include <thread>
#include <memory>

static constexpr char CONTENT_TYPE_JSON[] = "Content-Type: application/json";

int main(int argc, char *argv[])
{

    HttpRequestBuilder HttpBuilder(HttpRequestBuilder::GET_REQUEST, "https://abbas.requestcatcher.com/test");

    std::unique_ptr<HttpRequest> httpRequest = HttpBuilder
                                .addDataToHeader("some-header: well")
                                .addJWTtokenToHeader("token")
                                .addDataToHeader(CONTENT_TYPE_JSON)
                                .build();

    if (httpRequest->send() == CURLE_OK)
    {
        std::cout << "[" << httpRequest->getResponse() << "]\n";
        std::cout << "[" << httpRequest->getResponseHeader() << "]\n";
    }
    HttpRequest::cleanHttpRequestsGlobal();

}