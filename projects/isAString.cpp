#include <iostream>
#include <ctype.h>

bool isString(string checkValue) {
    bool found = true;
    for (auto x = checkValue.begin(); x != checkValue.end(); x++) {
        if (isdigit(*x)) {
            found = false;
        } else if (!isdigit(*x)) { found = true; }
    }
    return found;
}



int main()
{
   bool isAString = isString("hello1 world");
   std::cout << isAString;
}

