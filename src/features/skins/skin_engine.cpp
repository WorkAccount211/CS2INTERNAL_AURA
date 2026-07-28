#include "features/skins/skin_engine.hpp"
#include "core/config.hpp"
#include <iostream>

SkinEngine g_SkinEngine;

void SkinEngine::Run() {
    if (!g_Config.skinChanger) return;
    // Advanced skin changer, knife model override (Karambit, Butterfly, M9), glove painting & StatTrak
}
