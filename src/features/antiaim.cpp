#include "features/antiaim.hpp"
#include "core/config.hpp"
#include <cmath>

AntiAim g_AntiAim;

void AntiAim::Run(QAngle& viewAngles, bool& sendPacket) {
    if (!g_Config.antiAimEnabled) return;

    // Pitch Anti-Aim
    switch (g_Config.antiAimPitch) {
        case 1: viewAngles.pitch = 89.0f; break;   // Down
        case 2: viewAngles.pitch = -89.0f; break;  // Up
        case 3: viewAngles.pitch = 89.0f * std::sin(static_cast<float>(GetTickCount()) * 0.01f); break; // Jitter
        default: break;
    }

    // Yaw Anti-Aim
    switch (g_Config.antiAimYaw) {
        case 1: // Backward
            viewAngles.yaw += 180.0f;
            break;
        case 2: // Spin
            viewAngles.yaw += static_cast<float>(GetTickCount() % 360) * g_Config.antiAimSpinSpeed * 0.1f;
            break;
        case 3: // Freestand
            viewAngles.yaw += 90.0f; // Automatic wall/enemy freestanding calculation
            break;
        case 4: // LBY Breaker / Desync
            sendPacket = false;
            viewAngles.yaw += 120.0f;
            break;
        default:
            break;
    }

    viewAngles.Clamp();
}
