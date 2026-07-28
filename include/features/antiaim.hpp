#pragma once
#include "sdk/vector.hpp"

class AntiAim {
public:
    void Run(QAngle& viewAngles, bool& sendPacket);
};

extern AntiAim g_AntiAim;
