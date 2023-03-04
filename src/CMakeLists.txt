project(test_get_curl)
cmake_minimum_required(VERSION 3.16.3)

find_library(CURL_LIBRARY
    NAMES curl curllib libcurl_imp curllib_static lcurl libcurl
    HINTS "/lib/x86_64-linux-gnu"
)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/test_get.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/GetRequestClient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HttpRequest.cpp)

target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARY})

