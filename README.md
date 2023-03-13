# c++ HTTP-client with the smallest docker image
A c++ HTTP Client based on curl with the smallest docker image size out there :).
### HTTP-request-builder
Basically the builder handles the interactions with libcurl, all you need to do is add your HTTP request layers and send 🪃


## How to run

### build docker image
```bash
# build image
$ docker build -t http_requests_client_test .
# create a container and run it
$ docker run -d --name http_client_container http_requests_client_test:latest
```

## example code using the __HttpBuilder__
```c++
// builder pattern 
// send requests with ease 

static constexpr char IMP_HEADER_KEY[] = "head-key";
static constexpr char IMP_HEADER_VALUE[] = "some-value";


HttpRequestBuilder HttpBuilder(HttpRequestBuilder::GET_REQUEST, "https://abbas.requestcatcher.com/test");

std::unique_ptr<HttpRequest> httpRequest = HttpBuilder
                            .addDataToHeader("some-header: well")
                            .addJWTtokenToHeader("token")
                            .addDataToHeader(IMP_HEADER_KEY, IMP_HEADER_VALUE)
                            .build();

if (httpRequest->send() == CURLE_OK)
    std::cout << "[" << httpRequest->getResponse() << "]\n";

```

#### if you didn't use docker change in the CMake
```cmake
set(curl_installation_dir "<curl installation path (.so) libs path>")
# if it's installed globally in /usr/lib you can remove this line from cmake
```
