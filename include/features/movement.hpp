#pragma once
#include "sdk/vector.hpp"

class Movement {
public:
    void BunnyHop(struct C_CSPlayerPawn* localPawn, int& flags, int& buttons);
    void AutoStrafe(struct C_CSPlayerPawn* localPawn, QAngle& viewAngles, int& buttons);
    void JumpBug(struct C_CSPlayerPawn* localPawn, int& flags, int& buttons);
    void EdgeBug(struct C_CSPlayerPawn* localPawn, int& flags);
    void LongJump(struct C_CSPlayerPawn* localPawn, int& flags, int& buttons);
    void RenderSpeedometer(struct C_CSPlayerPawn* localPawn);
};

extern Movement g_Movement;
