#pragma once
#include "sdk/vector.hpp"

class LegitBot {
public:
    void Run(struct C_CSPlayerPawn* localPawn, QAngle& viewAngles, bool isShooting);
    void RunTriggerbot(struct C_CSPlayerPawn* localPawn);
    void ApplyRCS(QAngle& viewAngles, QAngle& punchAngle);
};

class RageBot {
public:
    void Run(struct C_CSPlayerPawn* localPawn, QAngle& viewAngles, bool& sendPacket);
    void RunAutoWall();
    void RunMultiPoint();
    void RunResolver();
};

extern LegitBot g_LegitBot;
extern RageBot g_RageBot;
