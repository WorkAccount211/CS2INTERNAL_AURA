#include "features/skins.hpp"
#include "core/config.hpp"
#include <iostream>

SkinChanger g_SkinChanger;

void SkinChanger::Run() {
    if (!g_Config.skinChanger) return;
    // Apply knife paintkit, glove definitions, weapon custom skin indices & StatTrak
}
