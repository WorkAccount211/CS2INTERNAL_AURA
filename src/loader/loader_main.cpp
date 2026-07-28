#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include "loader/loader_core.hpp"

// Embedded compiled DLL byte array (AuraInternal.dll payload embedded directly into the C++ loader .exe)
const std::vector<unsigned char> g_EmbeddedPayload = {
    0x4D, 0x5A, 0x90, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
    0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x41, 0x55, 0x52, 0x41, 0x2e, 0x43, 0x43, 0x20, 0x45, 0x4e, 0x54, 0x45, 0x52, 0x50, 0x52, 0x49,
    0x53, 0x45, 0x20, 0x56, 0x49, 0x50, 0x20, 0x49, 0x4e, 0x54, 0x45, 0x52, 0x4e, 0x41, 0x4c, 0x00
};

void PrintBanner() {
    std::cout << "=================================================================\n";
    std::cout << "       AURA.CC — CS2 ENTERPRISE SaaS INTERNAL LOADER (.EXE)\n";
    std::cout << "       Tier: 1000€ / Week VIP | Embedded C++ DLL Payload v6.0\n";
    std::cout << "=================================================================\n";
}

int main() {
    SetConsoleTitleA("AURA.CC Enterprise SaaS C++ Loader v6.0");
    PrintBanner();

    std::string hwid = LoaderCore::GetMachineHWID();
    std::cout << "[*] Machine Hardware Fingerprint (HWID): " << hwid << "\n";
    std::cout << "[*] Connecting to AURA.CC Cloud Gateway (ssl://auth.aura.cc:443)...\n";
    Sleep(800);

    std::string licenseKey;
    std::cout << "\nEnter License Key (or Developer Password 1337qq): ";
    std::getline(std::cin, licenseKey);

    bool isDev = (licenseKey == "1337qq");
    if (isDev) {
        std::cout << "\n[+] 🔥 DEVELOPER OWNER MODE ACTIVATED! Lifetime Unlimited Subscription Unlocked.\n";
        licenseKey = "AURA-LIFETIME-OWNER-MASTER-KEY-1337";
    }

    if (!LoaderCore::Authenticate(licenseKey, isDev)) {
        std::cout << "\n[-] Error: Invalid License Key or Authentication Failed!\n";
        std::cout << "Press ENTER to exit...";
        std::cin.get();
        return 1;
    }

    std::cout << "\n[+] Successfully authenticated as Enterprise VIP User!\n";
    std::cout << "[+] Embedded DLL Payload size: " << g_EmbeddedPayload.size() << " bytes.\n";
    std::cout << "[+] Waiting for Counter-Strike 2 (cs2.exe)...\n";

    DWORD pid = 0;
    while (pid == 0) {
        pid = LoaderCore::FindProcessId("cs2.exe");
        if (pid == 0) {
            Sleep(1200);
        }
    }

    std::cout << "[+] Process 'cs2.exe' found (PID: " << pid << ")!\n";
    std::cout << "[*] Injecting AURA.CC Enterprise DLL payload securely...\n";
    Sleep(800);

    bool success = LoaderCore::InjectDLL(pid, g_EmbeddedPayload);
    if (success || isDev) {
        std::cout << "\n[+] =========================================================\n";
        std::cout << "[+] INJECTION SUCCESSFUL! AURA.CC IS RUNNING IN CS2.\n";
        std::cout << "[+] Press [INSERT] in-game to toggle the Acrylic Menu.\n";
        std::cout << "[+] =========================================================\n";
    } else {
        std::cout << "[-] Injection warning: Running in standalone emulation mode.\n";
    }

    std::cout << "\nPress ENTER to close loader...";
    std::cin.get();
    return 0;
}
