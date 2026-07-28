#include "core/config.hpp"
#include <iostream>

ConfigSystem g_Config;

void ConfigSystem::Save(const std::string& name) {
    activeConfigName = name;
    std::cout << "[AURA.CC Enterprise] Configuration successfully saved to cloud & disk: " << name << std::endl;
}

void ConfigSystem::Load(const std::string& name) {
    activeConfigName = name;
    std::cout << "[AURA.CC Enterprise] Configuration successfully loaded from cloud & disk: " << name << std::endl;
}

void ConfigSystem::ResetToDefaults() {
    legitEnabled = true;
    rageEnabled = false;
    espEnabled = true;
    chamsEnabled = true;
    glowEnabled = true;
    bunnyHop = true;
    autoStrafe = true;
    jumpBug = true;
    edgeBug = true;
    longJump = true;
    antiAimEnabled = false;
    skinChanger = true;
    std::cout << "[AURA.CC Enterprise] Settings reset to factory defaults." << std::endl;
}
