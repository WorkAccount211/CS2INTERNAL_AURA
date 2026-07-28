#include "features/aimbot.hpp"
#include "core/config.hpp"
#include <cmath>
#include <algorithm>

Aimbot g_Aimbot;

QAngle Aimbot::CalculateAngle(const Vector3D& src, const Vector3D& dst, const QAngle& viewAngles) {
    Vector3D delta = src - dst;
    float hyp = delta.Length2D();
    QAngle angle;
    angle.pitch = std::atan2(-delta.z, hyp) * (180.0f / 3.14159265358979323846f);
    angle.yaw = std::atan2(delta.y, delta.x) * (180.0f / 3.14159265358979323846f) + 180.0f;
    angle.roll = 0.0f;
    angle.Clamp();
    return angle;
}

float Aimbot::GetFov(const QAngle& viewAngle, const QAngle& aimAngle) {
    QAngle delta = aimAngle - viewAngle;
    delta.Clamp();
    return std::sqrt(delta.pitch * delta.pitch + delta.yaw * delta.yaw);
}

void Aimbot::Run(C_CSPlayerPawn* localPawn, QAngle& viewAngles, bool isShooting) {
    if (!g_Config.aimbotEnabled) return;
    // Iterate entities, find target within FOV, apply smoothing, hitbone selection (Head/Neck/Chest)
}

void Aimbot::RunTriggerbot(C_CSPlayerPawn* localPawn) {
    if (!g_Config.triggerbotEnabled) return;
    // Check crosshair entity ID, apply delay, simulate attack command
}

void Aimbot::ApplyRCS(QAngle& viewAngles, QAngle& punchAngle) {
    if (!g_Config.rcsEnabled) return;
    // Recoil Control System: subtracting aim punch angle scaled by rcsX / rcsY
    viewAngles.pitch -= punchAngle.pitch * (g_Config.rcsX / 100.0f);
    viewAngles.yaw -= punchAngle.yaw * (g_Config.rcsY / 100.0f);
}
