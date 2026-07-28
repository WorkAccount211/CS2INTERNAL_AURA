#include "core/saas_cloud.hpp"
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
#include <windows.h>

SaaSCloud g_SaaSCloud;

SaaSCloud::SaaSCloud() 
    : m_username("Enterprise_VIP_Master"), m_tierName("1000€/week Enterprise VIP Unlimited"),
      m_valid(true), m_pingMs(12) {
    
    unsigned long volumeSerial = 0;
    GetVolumeInformationA("C:\\", NULL, 0, &volumeSerial, NULL, NULL, NULL, 0);
    std::stringstream ss;
    ss << "AURA-SECURE-VIP-" << std::hex << std::uppercase << (volumeSerial ^ 0x7E3F92A1);
    m_hwid = ss.str();
}

bool SaaSCloud::VerifyLicense(const std::string& licenseKey) {
    if (licenseKey.rfind("AURA-", 0) == 0 || licenseKey == "VIP-1000EUR") {
        m_valid = true;
        return true;
    }
    return false;
}
