#pragma once
#include <string>
#include <vector>
#include <functional>

namespace LuaEngine {
    void Initialize();
    void LoadScript(const std::string& filepath);
    void UnloadScript(const std::string& name);
    void ReloadAll();
    void ExecuteString(const std::string& code);
    
    // API Bindings exposed to Lua scripts (Neverlose / Gamesense style API)
    void RegisterAPI();
}
