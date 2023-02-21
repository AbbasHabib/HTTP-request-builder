#include "GetRequestClient.hpp"
#include <iostream>

void fun()
{
    GetRequestClient getRequestClient("https://dog-api.kinduff.com/api/facts?number=5");
    getRequestClient.send();

    std::cout << "\n[" << getRequestClient.getResponse() << "]\n";
}

int main()
{
    fun();
    fun();
    fun();
    fun();
}