# HTTP-clien with the smallest docker image
A c++ HTTP Client library with the smallest docker image size ever :)

## How to run

### build docker image
```bash
# build image
$ docker build -t http_requests_client_test .
# create a container and run it
$ docker run -d --name http_client_container http_requests_client_test:latest
```

## example code using __HttpBuilder__
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
