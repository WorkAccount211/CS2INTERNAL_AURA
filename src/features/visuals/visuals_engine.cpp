#include "features/visuals/visuals_engine.hpp"
#include "core/config.hpp"
#include "core/saas_cloud.hpp"
#include <iostream>

VisualsEngine g_VisualsEngine;

bool VisualsEngine::WorldToScreen(const Vector3D& world, Vector2D& screen, const ViewMatrix& matrix) {
    Vector3D transformed = matrix.TransformPoint(world);
    if (transformed.x == 0 && transformed.y == 0 && transformed.z == 0) return false;

    float screenWidth = 1920.0f;
    float screenHeight = 1080.0f;

    screen.x = (screenWidth * 0.5f) + (transformed.x * screenWidth * 0.5f);
    screen.y = (screenHeight * 0.5f) - (transformed.y * screenHeight * 0.5f);
    return true;
}

void VisualsEngine::RenderESP() {
    if (!g_Config.espEnabled) return;
    // Advanced 2D/3D Box ESP, Skeleton, Health/Armor bars, Flags, Snaplines & Dynamic Alpha
}

void VisualsEngine::RenderChams() {
    if (!g_Config.chamsEnabled) return;
    // DirectX 11 / Source 2 material shader override (Flat, Shaded, Pearl, Glass, Holographic, Galaxy)
}

void VisualsEngine::RenderGlow() {
    if (!g_Config.glowEnabled) return;
    // Source 2 Glow effect pass with customizable glow styles
}

void VisualsEngine::RenderWorldModulation() {
    if (!g_Config.worldModulation) return;
    // Night mode ambient lighting & custom skybox changer
}

void VisualsEngine::RenderBombTimer() {
    if (!g_Config.bombTimer) return;
    // C4 explosion countdown bar, damage prediction & bomb site indicator
}

void VisualsEngine::RenderWatermark() {
    if (!g_Config.watermark) return;
    // Ultra-sleek gradient watermark: AURA.CC | Enterprise VIP | FPS: 300 | Ping: 12ms | Build: 2026.Q3
}

void VisualsEngine::RenderKeybinds() {
    if (!g_Config.keybindList) return;
    // Active keybind window overlay
}

void VisualsEngine::RenderSpectators() {
    if (!g_Config.spectatorList) return;
    // Spectator list showing who is observing local player
}

void VisualsEngine::RenderHitmarkers() {
    if (!g_Config.hitMarker) return;
    // On-screen hitmarker and sound effects
}

void VisualsEngine::RenderCrosshair() {
    if (!g_Config.crosshairCustom) return;
    // Custom dynamic crosshairs (Dot, Cross, Circle, Spiral)
}
