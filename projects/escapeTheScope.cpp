
#include <iostream>

using std::string;

void changeName(string& user, string newName);

int main()
{
    string user = "someguyagain";
    std::cout << user << "\n";
    changeName(user, "somedudeagain");

    std::cout << user;
}

void changeName(string &user, string newName) {
    user = newName;
}
