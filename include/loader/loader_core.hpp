#pragma once
#include <windows.h>
#include <string>
#include <vector>

namespace LoaderCore {
    bool Authenticate(const std::string& key, bool isDeveloperMode);
    std::string GetMachineHWID();
    bool InjectDLL(DWORD processId, const std::vector<unsigned char>& dllBytes);
    DWORD FindProcessId(const std::string& processName);
}
