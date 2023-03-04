project(test_get_curl)

cmake_minimum_required(VERSION 3.16.3)

set(curl_installation_dir "/home/abbas/curl_hhtp_cpp/curl")

find_library(curl_lib curl NAMES libcurl PATHS ${curl_installation_dir}/build/lib)

if(${curl_lib} STREQUAL curl_lib-NOTFOUND)
    message("NOT FOUND")
else()
    message(${curl_lib})
endif()


add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/test_get.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GetRequestClient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/HttpRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/HttpRequestBuilder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/PostRequestClient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/PutRequestClient.cpp
    )

include_directories(${curl_installation_dir}/include/curl ${curl_installation_dir}/lib/)

target_link_libraries(${PROJECT_NAME} ${curl_lib})

