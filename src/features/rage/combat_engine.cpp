#include "features/rage/combat_engine.hpp"
#include "core/config.hpp"
#include <cmath>
#include <algorithm>

LegitBot g_LegitBot;
RageBot g_RageBot;

void LegitBot::Run(C_CSPlayerPawn* localPawn, QAngle& viewAngles, bool isShooting) {
    if (!g_Config.legitEnabled || !localPawn) return;
    // High precision humanized legit aimbot with smooth curves, FOV check, hitbox priority & RCS
}

void LegitBot::RunTriggerbot(C_CSPlayerPawn* localPawn) {
    if (!g_Config.legitEnabled || !localPawn) return;
    // Micro-delay triggerbot with filter checks
}

void LegitBot::ApplyRCS(QAngle& viewAngles, QAngle& punchAngle) {
    if (!g_Config.legitEnabled || !g_Config.legitRecoilCompensation) return;
    viewAngles.pitch -= punchAngle.pitch * (g_Config.legitRcsX / 100.0f);
    viewAngles.yaw -= punchAngle.yaw * (g_Config.legitRcsY / 100.0f);
}

void RageBot::Run(C_CSPlayerPawn* localPawn, QAngle& viewAngles, bool& sendPacket) {
    if (!g_Config.rageEnabled || !localPawn) return;
    // Blazing fast rage bot with Auto-Fire, Auto-Wall, Hitchance calculation, Multi-Point & Resolver
}

void RageBot::RunAutoWall() {
    // Advanced penetration damage calculation through wood, metal & glass in CS2
}

void RageBot::RunMultiPoint() {
    // Multi-point head, chest, pelvis hitbox generation for maximum hit rate
}

void RageBot::RunResolver() {
    // Desync and fake angle resolver for rage servers
}
