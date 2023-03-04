# Vehicle-HTTP-client
Vehicle HTTP Client library 

```c++
// builder pattern 
// send requests with ease 

static constexpr char CONTENT_TYPE_JSON[] = "Content-Type: application/json";


HttpRequestBuilder HttpBuilder(HttpRequestBuilder::GET_REQUEST, "https://abbas.requestcatcher.com/test");

std::unique_ptr<HttpRequest> httpRequest = HttpBuilder
                            .addDataToHeader("some-header: well")
                            .addJWTtokenToHeader("token")
                            .addDataToHeader(CONTENT_TYPE_JSON)
                            .build();

if (httpRequest->send() == CURLE_OK)
    std::cout << "[" << httpRequest->getResponse() << "]\n";

HttpRequest::cleanHttpRequestsGlobal();
```