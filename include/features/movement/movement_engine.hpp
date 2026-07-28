#pragma once
#include "sdk/vector.hpp"

class MovementEngine {
public:
    void BunnyHop(struct C_CSPlayerPawn* localPawn, int& flags, int& buttons);
    void AutoStrafe(struct C_CSPlayerPawn* localPawn, QAngle& viewAngles, int& buttons);
    void JumpBug(struct C_CSPlayerPawn* localPawn, int& flags, int& buttons);
    void EdgeBug(struct C_CSPlayerPawn* localPawn, int& flags);
    void LongJump(struct C_CSPlayerPawn* localPawn, int& flags, int& buttons);
    void EdgeJump(struct C_CSPlayerPawn* localPawn, int& flags, int& buttons);
    void BlockBot(struct C_CSPlayerPawn* localPawn, QAngle& viewAngles);
    void FastStop(struct C_CSPlayerPawn* localPawn, int& buttons);
    void RenderVelocityGraph(struct C_CSPlayerPawn* localPawn);
};

extern MovementEngine g_MovementEngine;
