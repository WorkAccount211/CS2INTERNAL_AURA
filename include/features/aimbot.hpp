#pragma once
#include "sdk/vector.hpp"

class Aimbot {
private:
    QAngle CalculateAngle(const Vector3D& src, const Vector3D& dst, const QAngle& viewAngles);
    float GetFov(const QAngle& viewAngle, const QAngle& aimAngle);

public:
    void Run(struct C_CSPlayerPawn* localPawn, QAngle& viewAngles, bool isShooting);
    void RunTriggerbot(struct C_CSPlayerPawn* localPawn);
    void ApplyRCS(QAngle& viewAngles, QAngle& punchAngle);
};

extern Aimbot g_Aimbot;
