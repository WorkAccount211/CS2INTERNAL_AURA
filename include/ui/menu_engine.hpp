#pragma once

class MenuEngine {
private:
    bool m_opened = true;
    int m_activeTab = 0;
    int m_subTabLegit = 0;
    int m_subTabRage = 0;
    int m_subTabVisuals = 0;
    int m_subTabMovement = 0;

public:
    void Initialize();
    void Render();
    void Toggle() { m_opened = !m_opened; }
    bool IsOpened() const { return m_opened; }
};

extern MenuEngine g_MenuEngine;
