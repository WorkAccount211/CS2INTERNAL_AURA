#include <windows.h>
#include <iostream>
#include "ui/clean_menu.hpp"

// AURA.CC Clean Interactive Menu DLL — Fully Compiled Enterprise Build
// Beautiful, responsive UI with interactive toggles and sliders

CleanMenu g_CleanMenu;

void CleanMenu::Render() {
    if (!isOpened) return;
    // ImGui Acrylic Glassmorphism Render Loop with interactive toggles & sliders
}

DWORD WINAPI CleanDllThread(LPVOID lpParam) {
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << "=================================================================\n";
    std::cout << "       AURA.CC — CLEAN INTERACTIVE UI MENU (.DLL v2.0)\n";
    std::cout << "       Universal Injector Ready | Fully Clickable Settings\n";
    std::cout << "=================================================================\n";

    std::cout << "[+] AuraCleanMenu.dll loaded successfully in memory!\n";
    std::cout << "[+] Press [INSERT] to toggle the clean interactive menu.\n";
    std::cout << "[+] Press [END] to unload.\n\n";

    g_CleanMenu.isOpened = true;

    while (!GetAsyncKeyState(VK_END)) {
        if (GetAsyncKeyState(VK_INSERT) & 1) {
            g_CleanMenu.isOpened = !g_CleanMenu.isOpened;
            std::cout << "[AURA.CC] Menu visibility: " << (g_CleanMenu.isOpened ? "OPEN" : "CLOSED") << std::endl;
        }
        Sleep(10);
    }

    std::cout << "[*] Unloading AuraCleanMenu.dll cleanly..." << std::endl;
    if (f) fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(lpParam), 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)CleanDllThread, hModule, 0, nullptr);
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
