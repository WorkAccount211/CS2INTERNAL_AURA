#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include <cstdint>

class Memory {
public:
    uintptr_t clientModule = 0;
    uintptr_t engineModule = 0;

    bool Initialize();
    uintptr_t FindPattern(uintptr_t moduleBase, const char* signature);
    
    template <typename T>
    T Read(uintptr_t address) {
        if (!address) return T{};
        return *reinterpret_cast<T*>(address);
    }

    template <typename T>
    bool Write(uintptr_t address, const T& value) {
        if (!address) return false;
        *reinterpret_cast<T*>(address) = value;
        return true;
    }
};

extern Memory g_Memory;
