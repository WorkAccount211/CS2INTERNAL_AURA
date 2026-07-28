#pragma once
#include <string>

class ConfigSystemAdvanced {
public:
    void SaveConfig(const std::string& filename);
    void LoadConfig(const std::string& filename);
    void ExportToClipboard();
    void ImportFromClipboard();
    void SyncToCloud();
    void LoadFromCloud();
};

extern ConfigSystemAdvanced g_ConfigAdvanced;
