#pragma once
#include "sdk/vector.hpp"
#include "sdk/entity.hpp"

class Visuals {
public:
    void RenderESP();
    void RenderChams();
    void RenderGlow();
    void RenderBombTimer();
    void RenderWatermark();
    void RenderKeybinds();
    void RenderSpectatorList();
    
    bool WorldToScreen(const Vector3D& world, Vector2D& screen, const ViewMatrix& matrix);
};

extern Visuals g_Visuals;
