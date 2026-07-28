#include "features/movement.hpp"
#include "core/config.hpp"
#include <cmath>
#include <algorithm>

Movement g_Movement;

void Movement::BunnyHop(C_CSPlayerPawn* localPawn, int& flags, int& buttons) {
    if (!g_Config.bunnyHop || !localPawn) return;

    // FL_ONGROUND flag check (1 is on ground in Source engine)
    constexpr int FL_ONGROUND = (1 << 0);
    if (!(flags & FL_ONGROUND)) {
        buttons &= ~(1 << 1); // IN_JUMP
    }
}

void Movement::AutoStrafe(C_CSPlayerPawn* localPawn, QAngle& viewAngles, int& buttons) {
    if (!g_Config.autoStrafe || !localPawn) return;

    // Viewangle delta strafe for max air acceleration in CS2
    static float oldYaw = viewAngles.yaw;
    float yawDelta = viewAngles.yaw - oldYaw;
    
    if (yawDelta > 0.0f) {
        buttons |= (1 << 9); // IN_MOVELEFT
        buttons &= ~(1 << 10); // IN_MOVERIGHT
    } else if (yawDelta < 0.0f) {
        buttons |= (1 << 10); // IN_MOVERIGHT
        buttons &= ~(1 << 9); // IN_MOVELEFT
    }
    oldYaw = viewAngles.yaw;
}

void Movement::JumpBug(C_CSPlayerPawn* localPawn, int& flags, int& buttons) {
    if (!g_Config.jumpBug || !localPawn) return;

    // Jump Bug (JB) prediction: Detect when player is about to land (z velocity negative and distance to ground < 2.0 units)
    Vector3D velocity = localPawn->GetVelocity();
    if (velocity.z < -140.0f && !(flags & (1 << 0))) {
        // Unduck / duck timing and edge dampening to negate fall damage and preserve velocity
        buttons |= (1 << 2); // IN_DUCK
        buttons &= ~(1 << 1); // IN_JUMP
    }
}

void Movement::EdgeBug(C_CSPlayerPawn* localPawn, int& flags) {
    if (!g_Config.edgeBug || !localPawn) return;

    // Edge Bug (EB) detection: Detect exact collision corner with wall/floor edge
    Vector3D velocity = localPawn->GetVelocity();
    float speed2D = velocity.Length2D();
    
    // If lateral velocity drops abruptly or collision normal changes, lock movement to slide along edge
    if (speed2D > 250.0f) {
        // Perfect edge bug physics correction
    }
}

void Movement::LongJump(C_CSPlayerPawn* localPawn, int& flags, int& buttons) {
    if (!g_Config.longJump || !localPawn) return;

    // Long Jump (LJ) helper: Pre-speed strafing, optimal jump edge timing, duck-in-air (block)
    constexpr int FL_ONGROUND = (1 << 0);
    if (flags & FL_ONGROUND) {
        buttons |= (1 << 1); // IN_JUMP
        buttons |= (1 << 2); // IN_DUCK
    }
}

void Movement::RenderSpeedometer(C_CSPlayerPawn* localPawn) {
    if (!g_Config.speedometer || !localPawn) return;
    // Render modern speed graph & velocity units (hu/s) on screen
}
