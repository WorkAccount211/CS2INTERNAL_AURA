#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

struct LuaCallback {
    std::string eventName;
    std::string scriptName;
    int callbackRef;
};

class LuaAdvancedEngine {
private:
    std::vector<std::string> m_loadedScripts;
    std::vector<LuaCallback> m_callbacks;
    bool m_initialized = false;

public:
    void Initialize();
    void Shutdown();
    void LoadScript(const std::string& filename);
    void UnloadScript(const std::string& filename);
    void ReloadAll();
    void ExecuteCode(const std::string& code);
    
    // Neverlose / Gamesense / Fatality Compatible Native API Bindings
    void RegisterNativeAPI();
    void TriggerEvent(const std::string& eventName);

    const std::vector<std::string>& GetLoadedScripts() const { return m_loadedScripts; }
};

extern LuaAdvancedEngine g_LuaAdvancedEngine;
