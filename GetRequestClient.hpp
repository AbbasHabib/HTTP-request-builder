#ifndef GET_REQUEST_CLIENT_HPP
#define GET_REQUEST_CLIENT_HPP

#include "HttpRequest.hpp"

class GetRequestClient : HttpRequest
{
private:
    //! @brief CURL pointer used to initialize request params
    CURL *m_curlPtr{nullptr};

    //! @brief responses inserted inside the responseString
    std::string m_resposneString{};

public:
    //! @brief default construtor is deleted
    GetRequestClient() = delete;

    //! @brief copy construtor is deleted
    GetRequestClient(const GetRequestClient &) = delete;

    //! @brief construtor
    //! @param url the url to which the get request is to be sent
    GetRequestClient(std::string url);

    //! @brief sends GetRequestClient
    //! @return true if succeed
    //! @return false if fails
    bool send();

    //! @brief sends GetRequestClient
    //! @return return response string
    const std::string getResponse();

    //! @brief destructor
    ~GetRequestClient();
};

#endif