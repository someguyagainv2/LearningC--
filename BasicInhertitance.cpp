#include <iostream>
using namespace std;

class father
{
    public:
        father() {};
        int x = 0;

        void sayHello() {
            cout << "Hello Son";
        }
};

class son: public father
{
    public:
        son() {};
};

int main() {
    son obj;
    obj.sayHello();
    return 0;
}
