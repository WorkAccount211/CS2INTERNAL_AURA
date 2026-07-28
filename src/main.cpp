#include <windows.h>
#include <iostream>
#include "core/memory.hpp"
#include "core/saas_cloud.hpp"
#include "core/config.hpp"
#include "features/visuals/visuals_engine.hpp"
#include "features/rage/combat_engine.hpp"
#include "features/rage/antiaim_engine.hpp"
#include "features/movement/movement_engine.hpp"
#include "features/skins/skin_engine.hpp"
#include "ui/menu_engine.hpp"

// AURA.CC CS2 Enterprise Ultimate Internal Cheat
// 1000€ / Week SaaS VIP Edition — 100x Enhanced

DWORD WINAPI EnterpriseThread(LPVOID lpParam) {
    std::cout << "[AURA.CC Enterprise] Initializing Ultimate CS2 SaaS Kernel Internal...\n" << std::endl;
    
    if (!g_SaaSCloud.IsValid()) {
        std::cout << "[AURA.CC Enterprise] License Verification Failed!\n" << std::endl;
        return 0;
    }

    std::cout << "[AURA.CC Enterprise] Welcome back, " << g_SaaSCloud.GetUsername() << "!\n" << std::endl;
    std::cout << "[AURA.CC Enterprise] Active Tier: " << g_SaaSCloud.GetTierName() << "\n" << std::endl;
    std::cout << "[AURA.CC Enterprise] Secure HWID: " << g_SaaSCloud.GetHWID() << "\n" << std::endl;
    std::cout << "[AURA.CC Enterprise] Build ID: " << g_SaaSCloud.GetBuildId() << "\n" << std::endl;

    g_Memory.Initialize();
    g_MenuEngine.Initialize();

    while (!GetAsyncKeyState(VK_END)) {
        if (GetAsyncKeyState(VK_INSERT) & 1) {
            g_MenuEngine.Toggle();
        }

        // Enterprise feature execution ticks
        // g_VisualsEngine.RenderESP();
        // g_SkinEngine.Run();

        Sleep(3);
    }

    std::cout << "[AURA.CC Enterprise] Unloading secure payload...\n" << std::endl;
    FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(lpParam), 0);
    return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)EnterpriseThread, hModule, 0, nullptr);
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
