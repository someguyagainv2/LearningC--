#include <iostream>

using namespace std;

class basic 
{
  public:
    basic(int a, int b) {
      x = a;
      y = b;
    }

    int getSum() {
      return x+y;
    }
  private:
    int x;
    int y;
};

int main() {
  basic classx(20, 2);
  int total = classx.getSum();
  cout << total;
  return 1;
}
