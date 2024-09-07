#include <Windows.h>
#include <iostream>
#include <psapi.h>
#include <tchar.h>

int main()
{
    DWORD proccesses[1024], proccessCount;
    
    if (!EnumProcesses(proccesses, sizeof(proccesses), &proccessCount)) {
        std::cerr << "Error occured most likely permission";
    }

    for (DWORD i = 0; i < proccessCount; i++) {
        if (i == 0) {
            continue;
        }
        HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, proccesses[i]);
        if (hProcess) {
            TCHAR processName[MAX_PATH];
            DWORD size = MAX_PATH;
            if (GetModuleBaseName(hProcess, nullptr, processName, sizeof(processName) / sizeof(TCHAR))) {
                _tprintf(TEXT("Process Name: %s\n"), processName);
                CloseHandle(hProcess);
            }
        }
    }
}
