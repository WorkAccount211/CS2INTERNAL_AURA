#pragma once

struct VisualsTab {
    bool espBox = true;
    int boxStyle = 0; // 0: 2D Box, 1: Corner, 2: 3D Box
    bool espSkeleton = true;
    bool espHealthBar = true;
    bool espArmorBar = true;
    bool espName = true;
    bool espWeapon = true;
    bool espDistance = false;
    bool espSnaplines = false;
    float boxAlpha = 0.8f;

    bool chamsEnabled = true;
    int chamsMaterial = 0; // 0: Flat, 1: Shaded, 2: Glass, 3: Glow
    bool xqz = true;

    bool watermark = true;
    bool spectatorList = true;
    bool bombTimer = true;
};

struct LegitTab {
    bool enabled = false;
    int key = 1; // Mouse 5
    float fov = 3.5f;
    float smooth = 6.0f;
    int hitbox = 0; // 0: Head, 1: Neck, 2: Chest
    bool rcs = true;
    float rcsX = 2.0f;
    float rcsY = 2.0f;
    bool triggerbot = false;
    int triggerDelay = 50;
};

struct RageTab {
    bool enabled = false;
    float fov = 180.0f;
    bool autoFire = true;
    bool autoWall = true;
    float minDamage = 10.0f;
    bool hitchance = true;
    float hitchanceVal = 75.0f;

    bool antiAim = false;
    int pitch = 0; // 0: Off, 1: Down, 2: Up, 3: Jitter
    int yaw = 1;   // 0: Off, 1: Backward, 2: Spin, 3: Freestand
    float spinSpeed = 20.0f;
};

struct MovementTab {
    bool bunnyHop = true;
    bool autoStrafe = true;
    int strafeType = 0; // 0: Viewangle, 1: Directional
    bool jumpBug = false;
    bool edgeBug = false;
    bool longJump = false;
    bool speedometer = true;
};

struct MiscTab {
    bool skinChanger = false;
    int knifeModel = 0; // 0: Karambit, 1: Butterfly, 2: M9 Bayonet
    int gloveModel = 0; // 0: Sport, 1: Specialist
    bool clantag = true;
    bool hitmarkers = true;
    int accentColor = 0; // 0: Purple, 1: Cyan, 2: Green, 3: Red
};

class CleanMenu {
public:
    bool isOpened = true;
    int activeTab = 0; // 0: Visuals, 1: Legit, 2: Rage, 3: Movement, 4: Misc

    VisualsTab visuals;
    LegitTab legit;
    RageTab rage;
    MovementTab movement;
    MiscTab misc;

    void Render();
};

extern CleanMenu g_CleanMenu;
