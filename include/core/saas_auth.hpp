#pragma once
#include <string>

enum class SubscriptionTier {
    FREE = 0,
    PRO = 1,
    ENTERPRISE_VIP = 2 // 1000€ / week Tier with all features unlocked
};

class SaaSAuth {
private:
    std::string m_username;
    std::string m_hwid;
    std::string m_token;
    SubscriptionTier m_tier;
    bool m_authenticated;
    int m_daysRemaining;

public:
    SaaSAuth();

    bool Authenticate(const std::string& licenseKey);
    std::string GenerateHWID();
    
    bool IsAuthenticated() const { return m_authenticated; }
    SubscriptionTier GetTier() const { return m_tier; }
    std::string GetUsername() const { return m_username; }
    int GetDaysRemaining() const { return m_daysRemaining; }
    std::string GetTierName() const;
};

extern SaaSAuth g_SaaSAuth;
