#pragma once
#include <string>
#include <vector>

struct ThemeSettings {
    int accentColor = 0; // 0: Cyberpunk Purple, 1: Matrix Cyan, 2: Emerald Green, 3: Blood Red, 4: Sunset Orange, 5: Aurora Diamond
    float windowRounding = 12.0f;
    float frameRounding = 6.0f;
    float alpha = 0.94f;
    bool acrylicBlur = true;
    bool particleBackground = true;
    bool glowShadows = true;
};

class ConfigSystem {
public:
    // Theme & UI
    ThemeSettings theme;

    // Legit Bot
    bool legitEnabled = true;
    int legitKey = 0x06;
    float legitFov = 2.0f;
    float legitSmooth = 6.5f;
    int legitHitbox = 0; // 0: Head, 1: Neck, 2: Chest, 3: Nearest
    bool legitRecoilCompensation = true;
    float legitRcsX = 2.0f;
    float legitRcsY = 2.0f;
    bool legitCheckVisible = true;
    bool legitCheckTeam = true;
    bool legitAutoShoot = false;
    bool legitSilent = false;

    // Rage Bot
    bool rageEnabled = false;
    int rageTargetSelection = 0; // 0: Highest Damage, 1: Distance, 2: Cycle, 3: Health
    float rageFov = 180.0f;
    bool rageAutoFire = true;
    bool rageAutoWall = true;
    float rageMinDamage = 10.0f;
    bool rageHitchance = true;
    float rageMinHitchance = 75.0f;
    int rageHitboxSet = 0; // 0: Multi-Point, 1: Head Only, 2: Body Aim
    bool rageResolver = true;
    bool rageDoubleTap = true;
    bool rageHideShots = false;

    // Visuals / ESP
    bool espEnabled = true;
    bool espBox = true;
    int espBoxStyle = 0; // 0: Standard, 1: Corner, 2: 3D Box, 3: Gradient Glow
    bool espFilledBox = true;
    float espBoxAlpha = 0.25f;
    bool espSkeleton = true;
    int espSkeletonStyle = 0; // 0: Normal, 1: Thick Neon
    bool espHealthBar = true;
    int espHealthBarStyle = 0; // 0: Left, 1: Right, 2: Top Bar
    bool espArmorBar = true;
    bool espName = true;
    bool espWeapon = true;
    bool espAmmo = true;
    bool espDistance = true;
    bool espFlags = true; // Armor, Defuser, Scope, Blinded
    bool espSnaplines = false;
    int espSnaplineOrigin = 0; // 0: Bottom, 1: Center, 2: Crosshair

    // Chams & Glow
    bool chamsEnabled = true;
    int chamsMaterial = 0; // 0: Flat, 1: Shaded, 2: Pearl, 3: Glass, 4: Holographic, 5: Galaxy, 6: Wireframe
    bool chamsXqz = true; // Visible through walls
    bool glowEnabled = true;
    int glowStyle = 0;

    // World & Misc Visuals
    bool worldModulation = true;
    float worldNightMode = 0.2f;
    bool customSkybox = true;
    int skyboxPreset = 0; // 0: Space Galaxy, 1: Night Cyber, 2: Sunset, 3: Anime Pink
    bool bombTimer = true;
    bool watermark = true;
    bool keybindList = true;
    bool spectatorList = true;
    bool hitMarker = true;
    bool hitSound = true;
    int hitSoundPreset = 0; // 0: CS:S, 1: Bell, 2: Bubble, 3: Punch
    bool damageIndicator = true;
    bool crosshairCustom = true;
    int crosshairType = 0; // 0: Dot, 1: Cross, 2: Circle, 3: Dynamic Spiral

    // Movement Suite
    bool bunnyHop = true;
    bool autoStrafe = true;
    int autoStrafeType = 0; // 0: Viewangle, 1: Directional, 2: Retrack, 3: Max Speed
    bool jumpBug = true;
    bool edgeBug = true;
    bool longJump = true;
    bool edgeJump = true;
    bool blockBot = true;
    bool slideHelper = true;
    bool fastStop = true;
    bool velocityGraph = true;
    bool soundESP = true;

    // Anti-Aim (Rage)
    bool antiAimEnabled = false;
    int antiAimPitch = 0; // 0: Off, 1: Down, 2: Up, 3: Jitter, 4: Zero
    int antiAimYaw = 1;   // 0: Off, 1: Backward, 2: Spin, 3: Freestand, 4: LBY Breaker, 5: Directional
    float antiAimJitterRange = 45.0f;
    float antiAimSpinSpeed = 25.0f;
    bool antiAimFakeLag = true;
    int antiAimFakeLagLimit = 14;
    bool antiAimYawJitter = true;
    float antiAimBodyLean = 60.0f;

    // Skin & Inventory Changer
    bool skinChanger = true;
    int knifeModel = 0; // 0: Karambit, 1: Butterfly, 2: M9 Bayonet, 3: Talon, 4: Skeleton, 5: Stiletto
    int knifePaintKit = 416; // Doppler Sapphire / Emerald
    int gloveModel = 0; // 0: Sport Gloves, 1: Specialist, 2: Moto, 3: Hydra
    int glovePaintKit = 10006;
    bool agentChanger = true;
    bool statTrak = true;

    // Cloud Config & SaaS Settings
    std::string activeConfigName = "Default_Enterprise.aura";
    std::string cloudProfile = "Enterprise_VIP_1000EUR";
    int securityBypassLevel = 3; // Max Secure Kernel Emulation
    bool streamSafe = true;

    void Save(const std::string& name);
    void Load(const std::string& name);
    void ResetToDefaults();
};

extern ConfigSystem g_Config;
