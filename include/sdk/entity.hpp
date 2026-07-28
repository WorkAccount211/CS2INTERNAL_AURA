#pragma once
#include "vector.hpp"
#include <cstdint>

enum LifeState : uint8_t {
    LIFE_ALIVE = 0,
    LIFE_DYING = 1,
    LIFE_DEAD = 2
};

enum TeamNumber : int {
    TEAM_NONE = 1,
    TEAM_SPECTATOR = 1,
    TEAM_T = 2,
    TEAM_CT = 3
};

struct GameSceneNode {
    // Entity position and coordinate frame in Source 2
    Vector3D GetAbsOrigin() const {
        // Implementation pointer offset simulation
        return *reinterpret_cast<Vector3D*>(reinterpret_cast<uintptr_t>(this) + 0xC8);
    }
};

struct CEntityInstance {
    // Base entity instance
};

struct C_CSPlayerPawn {
    int GetHealth() const {
        return *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(this) + 0x334);
    }
    int GetArmor() const {
        return *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(this) + 0x23CC);
    }
    int GetTeamNum() const {
        return *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(this) + 0x3C3);
    }
    LifeState GetLifeState() const {
        return *reinterpret_cast<LifeState*>(reinterpret_cast<uintptr_t>(this) + 0x338);
    }
    Vector3D GetVelocity() const {
        return *reinterpret_cast<Vector3D*>(reinterpret_cast<uintptr_t>(this) + 0x3E8);
    }
    GameSceneNode* GetGameSceneNode() const {
        return *reinterpret_cast<GameSceneNode**>(reinterpret_cast<uintptr_t>(this) + 0x310);
    }
    bool IsAlive() const {
        return GetLifeState() == LIFE_ALIVE && GetHealth() > 0;
    }
};

struct CCSPlayerController {
    const char* GetPlayerName() const {
        return reinterpret_cast<const char*>(reinterpret_cast<uintptr_t>(this) + 0x640);
    }
    C_CSPlayerPawn* GetPlayerPawn() const {
        uint32_t pawnHandle = *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(this) + 0x80C);
        // Entity list resolve simulation
        return reinterpret_cast<C_CSPlayerPawn*>(pawnHandle);
    }
    bool IsLocalPlayer() const {
        // Return true if local controller
        return true;
    }
};
