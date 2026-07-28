#include "features/movement/movement_engine.hpp"
#include "core/config.hpp"
#include <cmath>
#include <algorithm>

MovementEngine g_MovementEngine;

void MovementEngine::BunnyHop(C_CSPlayerPawn* localPawn, int& flags, int& buttons) {
    if (!g_Config.bunnyHop || !localPawn) return;
    constexpr int FL_ONGROUND = (1 << 0);
    if (!(flags & FL_ONGROUND)) {
        buttons &= ~(1 << 1); // IN_JUMP
    }
}

void MovementEngine::AutoStrafe(C_CSPlayerPawn* localPawn, QAngle& viewAngles, int& buttons) {
    if (!g_Config.autoStrafe || !localPawn) return;
    static float oldYaw = viewAngles.yaw;
    float yawDelta = viewAngles.yaw - oldYaw;
    if (yawDelta > 0.0f) {
        buttons |= (1 << 9);
        buttons &= ~(1 << 10);
    } else if (yawDelta < 0.0f) {
        buttons |= (1 << 10);
        buttons &= ~(1 << 9);
    }
    oldYaw = viewAngles.yaw;
}

void MovementEngine::JumpBug(C_CSPlayerPawn* localPawn, int& flags, int& buttons) {
    if (!g_Config.jumpBug || !localPawn) return;
    Vector3D velocity = localPawn->GetVelocity();
    if (velocity.z < -140.0f && !(flags & (1 << 0))) {
        buttons |= (1 << 2); // IN_DUCK
        buttons &= ~(1 << 1); // IN_JUMP
    }
}

void MovementEngine::EdgeBug(C_CSPlayerPawn* localPawn, int& flags) {
    if (!g_Config.edgeBug || !localPawn) return;
    Vector3D velocity = localPawn->GetVelocity();
    if (velocity.Length2D() > 250.0f) {
        // Perfect edge collision normal correction
    }
}

void MovementEngine::LongJump(C_CSPlayerPawn* localPawn, int& flags, int& buttons) {
    if (!g_Config.longJump || !localPawn) return;
    constexpr int FL_ONGROUND = (1 << 0);
    if (flags & FL_ONGROUND) {
        buttons |= (1 << 1);
        buttons |= (1 << 2);
    }
}

void MovementEngine::EdgeJump(C_CSPlayerPawn* localPawn, int& flags, int& buttons) {
    if (!g_Config.edgeJump || !localPawn) return;
    // Edge Jump at ledge drop
}

void MovementEngine::BlockBot(C_CSPlayerPawn* localPawn, QAngle& viewAngles) {
    if (!g_Config.blockBot || !localPawn) return;
    // Target strafe blocker for KZ/Surf servers
}

void MovementEngine::FastStop(C_CSPlayerPawn* localPawn, int& buttons) {
    if (!g_Config.fastStop || !localPawn) return;
    // Quick counter-strafing key injection
}

void MovementEngine::RenderVelocityGraph(C_CSPlayerPawn* localPawn) {
    if (!g_Config.velocityGraph || !localPawn) return;
    // On-screen real-time speed & acceleration graph
}
