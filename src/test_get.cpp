#include "GetRequestClient.hpp"
#include <iostream>
#include <thread>
#include <memory>

static constexpr char CONTENT_TYPE_JSON[] = "Content-Type: application/json";


int main(int argc, char* argv[])
{
    std::unique_ptr<HttpRequest> getReq = std::make_unique<GetRequestClient>("https://abbas.requestcatcher.com/test");

    getReq->init();
    getReq->addDataToHeader("someheader: well");
    getReq->addDataToHeader(CONTENT_TYPE_JSON);
    getReq->addJWTtokenToHeader("tokeen");

    if( getReq->send() == CURLE_OK);
        std::cout << "\n[" << getReq->getResponse() << "]\n";

}