project(test_get_curl)

cmake_minimum_required(VERSION 3.10)


add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/test_get.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/GetRequestClient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/HttpRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/HttpRequestBuilder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/PostRequestClient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/PutRequestClient.cpp
    )

target_link_libraries(${PROJECT_NAME} curl)

