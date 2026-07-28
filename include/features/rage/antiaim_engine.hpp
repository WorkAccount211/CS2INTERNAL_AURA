#pragma once
#include "sdk/vector.hpp"

class AntiAimEngine {
public:
    void Run(QAngle& viewAngles, bool& sendPacket);
};

extern AntiAimEngine g_AntiAimEngine;
