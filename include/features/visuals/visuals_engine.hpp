#pragma once
#include "sdk/vector.hpp"
#include "sdk/entity.hpp"

class VisualsEngine {
public:
    void RenderESP();
    void RenderChams();
    void RenderGlow();
    void RenderWorldModulation();
    void RenderBombTimer();
    void RenderWatermark();
    void RenderKeybinds();
    void RenderSpectators();
    void RenderHitmarkers();
    void RenderCrosshair();
    
    bool WorldToScreen(const Vector3D& world, Vector2D& screen, const ViewMatrix& matrix);
};

extern VisualsEngine g_VisualsEngine;
