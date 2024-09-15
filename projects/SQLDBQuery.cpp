// The function you see called sendRequest is one I made where I pass values to it as if it was py requests I can link code atp

#include <iostream>
#include "Curlfuncs.h"

int main()
{
    string headers[1] = { "Content-Type: application/json" };
    string value = "{\"csrf\":\"AuthorizationPasswordHere\", \"query\": \"SELECT username FROM loginSystemExample\"}";
    const std::string data = sendRequest("https://vpsIP:PORT/queryDB", "post", 1, headers, value.c_str());
    std::cout << data;

}

// Way I did this was by hosting VPS backend on express that listens on endpoint URI for data which has password what matches then a query
// Due to all complex ways of connecting to db on C++
