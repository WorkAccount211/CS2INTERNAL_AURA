#include "features/rage/antiaim_engine.hpp"
#include "core/config.hpp"
#include <cmath>
#include <windows.h>

AntiAimEngine g_AntiAimEngine;

void AntiAimEngine::Run(QAngle& viewAngles, bool& sendPacket) {
    if (!g_Config.antiAimEnabled) return;

    // Pitch Anti-Aim
    switch (g_Config.antiAimPitch) {
        case 1: viewAngles.pitch = 89.0f; break;   // Down
        case 2: viewAngles.pitch = -89.0f; break;  // Up
        case 3: viewAngles.pitch = 89.0f * std::sin(static_cast<float>(GetTickCount()) * 0.015f); break; // Jitter
        case 4: viewAngles.pitch = 0.0f; break;    // Zero
        default: break;
    }

    // Yaw Anti-Aim
    switch (g_Config.antiAimYaw) {
        case 1: viewAngles.yaw += 180.0f; break; // Backward
        case 2: viewAngles.yaw += static_cast<float>(GetTickCount() % 360) * g_Config.antiAimSpinSpeed * 0.1f; break; // Spin
        case 3: viewAngles.yaw += 90.0f; break;  // Freestand
        case 4: // LBY Breaker / Desync
            sendPacket = false;
            viewAngles.yaw += g_Config.antiAimBodyLean;
            break;
        case 5: // Directional Jitter
            viewAngles.yaw += 180.0f + (std::sin(static_cast<float>(GetTickCount()) * 0.02f) * g_Config.antiAimJitterRange);
            break;
        default:
            break;
    }

    viewAngles.Clamp();
}
