#pragma once
#include <string>
#include <chrono>

class SaaSCloud {
private:
    std::string m_username;
    std::string m_tierName;
    std::string m_hwid;
    std::chrono::system_clock::time_point m_expiration;
    bool m_valid;
    int m_pingMs;

public:
    SaaSCloud();

    bool VerifyLicense(const std::string& licenseKey);
    std::string GetHWID() const { return m_hwid; }
    std::string GetUsername() const { return m_username; }
    std::string GetTierName() const { return m_tierName; }
    bool IsValid() const { return m_valid; }
    int GetPing() const { return m_pingMs; }
    std::string GetBuildId() const { return "AURA-CS2-2026.Q3-RELEASE"; }
};

extern SaaSCloud g_SaaSCloud;
