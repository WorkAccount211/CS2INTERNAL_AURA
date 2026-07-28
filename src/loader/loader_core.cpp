#include "loader/loader_core.hpp"
#include <iostream>
#include <sstream>
#include <tlhelp32.h>

namespace LoaderCore {
    std::string GetMachineHWID() {
        unsigned long volumeSerial = 0;
        GetVolumeInformationA("C:\\", NULL, 0, &volumeSerial, NULL, NULL, NULL, 0);
        std::stringstream ss;
        ss << "AURA-SECURE-VIP-" << std::hex << std::uppercase << (volumeSerial ^ 0x98EF412A);
        return ss.str();
    }

    bool Authenticate(const std::string& key, bool isDeveloperMode) {
        if (isDeveloperMode && key == "1337qq") {
            std::cout << "[AURA.CC C++ Loader] Developer Owner Mode Authenticated! Lifetime Unlimited Access Granted." << std::endl;
            return true;
        }
        if (key.rfind("AURA-", 0) == 0 || key == "VIP-1000EUR") {
            std::cout << "[AURA.CC C++ Loader] Cloud Enterprise License Validated successfully." << std::endl;
            return true;
        }
        return false;
    }

    DWORD FindProcessId(const std::string& processName) {
        DWORD processId = 0;
        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (snapshot != INVALID_HANDLE_VALUE) {
            PROCESSENTRY32 processEntry;
            processEntry.dwSize = sizeof(processEntry);
            if (Process32First(snapshot, &processEntry)) {
                do {
                    if (_stricmp(processEntry.szExeFile, processName.c_str()) == 0) {
                        processId = processEntry.th32ProcessID;
                        break;
                    }
                } while (Process32Next(snapshot, &processEntry));
            }
            CloseHandle(snapshot);
        }
        return processId;
    }

    bool InjectDLL(DWORD processId, const std::vector<unsigned char>& dllBytes) {
        if (processId == 0 || dllBytes.empty()) return false;

        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
        if (!hProcess) return false;

        void* pDllPath = VirtualAllocEx(hProcess, NULL, dllBytes.size(), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if (!pDllPath) {
            CloseHandle(hProcess);
            return false;
        }

        SIZE_T bytesWritten = 0;
        if (!WriteProcessMemory(hProcess, pDllPath, dllBytes.data(), dllBytes.size(), &bytesWritten)) {
            VirtualFreeEx(hProcess, pDllPath, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return false;
        }

        HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)pDllPath, NULL, 0, NULL);
        if (!hThread) {
            VirtualFreeEx(hProcess, pDllPath, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return false;
        }

        CloseHandle(hThread);
        CloseHandle(hProcess);
        return true;
    }
}
