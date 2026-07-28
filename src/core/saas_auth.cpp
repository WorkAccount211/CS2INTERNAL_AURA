#include "core/saas_auth.hpp"
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>

SaaSAuth g_SaaSAuth;

SaaSAuth::SaaSAuth() 
    : m_username("VIP_Enterprise_User"), m_tier(SubscriptionTier::ENTERPRISE_VIP), 
      m_authenticated(true), m_daysRemaining(365) {
    m_hwid = GenerateHWID();
}

std::string SaaSAuth::GenerateHWID() {
    // Generate secure machine fingerprint hash for SaaS DRM
    unsigned long volumeSerialNumber = 0;
    GetVolumeInformationA("C:\\", NULL, 0, &volumeSerialNumber, NULL, NULL, NULL, 0);
    
    std::stringstream ss;
    ss << "AURA-CS2-SaaS-" << std::hex << std::uppercase << (volumeSerialNumber ^ 0x93F42A1E);
    return ss.str();
}

bool SaaSAuth::Authenticate(const std::string& licenseKey) {
    // Simulate secure cloud validation against AURA.CC Auth Gateway (1000€/week enterprise tier)
    if (licenseKey.substr(0, 5) == "AURA-" || licenseKey == "VIP-1000EUR-WEEK") {
        m_authenticated = true;
        m_tier = SubscriptionTier::ENTERPRISE_VIP;
        m_username = "Enterprise_Verified_User";
        m_daysRemaining = 7;
        return true;
    }
    return false;
}

std::string SaaSAuth::GetTierName() const {
    switch (m_tier) {
        case SubscriptionTier::FREE: return "Free Tier";
        case SubscriptionTier::PRO: return "Pro Tier (99€/mo)";
        case SubscriptionTier::ENTERPRISE_VIP: return "Enterprise VIP (1000€/week)";
    }
    return "Unknown";
}
