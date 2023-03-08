#include "HttpRequestBuilder.hpp"
#include <iostream>
#include <thread>
#include <memory>

static constexpr char CONTENT_TYPE_JSON[] = "Content-Type: application/json";


void sendRequest(HttpRequestBuilder::REQUEST_TYPE requestType)
{
    HttpRequestBuilder HttpBuilder(requestType, "https://abbas.requestcatcher.com/test");

    std::string jsonObj = "{ \"name\" : \"abbas\" , \"age\" : \"55\" }";
    std::string token = "TOKEN";
    std::unique_ptr<HttpRequest> httpRequest = HttpBuilder
                                .addJWTtokenToHeader(token)
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
    using REQUEST =  HttpRequestBuilder::REQUEST_TYPE;
    REQUEST requestTypes[] = {REQUEST::GET_REQUEST, REQUEST::POST_REQUEST, REQUEST::PUT_REQUEST};
    uint8_t count = 0;
    while(true)
    {
        sendRequest(requestTypes[count]);
        count = (count + 1) % 3;
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    HttpRequest::cleanHttpRequestsGlobal();
}