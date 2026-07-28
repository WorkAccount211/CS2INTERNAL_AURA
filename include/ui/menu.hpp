#pragma once

class Menu {
private:
    bool m_opened = true;
    int m_activeTab = 0;

public:
    void Initialize();
    void Render();
    void Toggle() { m_opened = !m_opened; }
    bool IsOpened() const { return m_opened; }
};

extern Menu g_Menu;
