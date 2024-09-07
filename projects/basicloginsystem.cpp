#include <iostream>
#include <string.h>

void output(std::string text) {
    if (text.empty()) { return; }

    std::cout << text << "\n";
}

int main()
{
    output("SecLabs.");
    output("Please Login.");
    std::cout << "Username: ";

    std::string username, password;
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (username == "someguyagain" && password == "0xsomeguyagain") {
        output("Welcome To SecLabs.");
    }
    else {
        output("Authentication Failure Incorrect Credentials.");
    }
}
