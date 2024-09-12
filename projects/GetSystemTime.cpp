#include <Windows.h>

SYSTEMTIME returnSystemTime() {
    SYSTEMTIME time;
    GetSystemTime(&time);
    return time;
}

int main() {
  SYSTEMTIME value = returnSystemTime();
  std::string systemTime = value.wHour+":"+value.wMinute;
  std::cout << systemTime;
}
