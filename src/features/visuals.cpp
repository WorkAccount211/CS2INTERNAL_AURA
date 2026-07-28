#include "features/visuals.hpp"
#include "core/config.hpp"
#include "core/saas_auth.hpp"
#include <iostream>

Visuals g_Visuals;

bool Visuals::WorldToScreen(const Vector3D& world, Vector2D& screen, const ViewMatrix& matrix) {
    Vector3D transformed = matrix.TransformPoint(world);
    if (transformed.x == 0 && transformed.y == 0 && transformed.z == 0) return false;

    float screenWidth = 1920.0f; // Mock resolution
    float screenHeight = 1080.0f;

    screen.x = (screenWidth * 0.5f) + (transformed.x * screenWidth * 0.5f);
    screen.y = (screenHeight * 0.5f) - (transformed.y * screenHeight * 0.5f);
    return true;
}

void Visuals::RenderESP() {
    if (!g_Config.espEnabled) return;
    // ImGui ESP rendering loop for players, boxes, skeletons, health bars, snaplines, weapon names
}

void Visuals::RenderChams() {
    if (!g_Config.chamsEnabled) return;
    // DirectX material override for Chams (Flat, Shaded, Glow)
}

void Visuals::RenderGlow() {
    if (!g_Config.glowEnabled) return;
    // Source 2 Glow effect pass
}

void Visuals::RenderBombTimer() {
    if (!g_Config.bombTimer) return;
    // C4 explosion countdown timer & site indicator
}

void Visuals::RenderWatermark() {
    if (!g_Config.watermark) return;
    // SaaS 1000€/week enterprise watermark: "AURA.CC | CS2 Enterprise | FPS: 300 | Ping: 12ms | User: Enterprise_VIP"
}

void Visuals::RenderKeybinds() {
    if (!g_Config.keybindList) return;
    // Active keybind list overlay
}

void Visuals::RenderSpectatorList() {
    if (!g_Config.spectatorList) return;
    // Spectator list overlay showing who is spectating local player
}
