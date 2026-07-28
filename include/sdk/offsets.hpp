#pragma once
#include <cstdint>

namespace Offsets {
    // CS2 Client dynamic and static offsets (Updated for latest 2026 Source 2 build)
    inline uintptr_t dwEntityList = 0x18DC488;
    inline uintptr_t dwLocalPlayerController = 0x1A28A18;
    inline uintptr_t dwLocalPlayerPawn = 0x18B4D48;
    inline uintptr_t dwViewMatrix = 0x1A35010;
    inline uintptr_t dwViewAngles = 0x1A42400;
    inline uintptr_t dwGlobalVars = 0x1731670;

    // Pawn offsets
    inline uintptr_t m_iHealth = 0x334;
    inline uintptr_t m_iTeamNum = 0x3C3;
    inline uintptr_t m_vecOrigin = 0xC8;
    inline uintptr_t m_vecViewOffset = 0xC50;
    inline uintptr_t m_aimPunchAngle = 0x14C0;
    inline uintptr_t m_fFlags = 0x3EC;
    inline uintptr_t m_lifeState = 0x338;
}
