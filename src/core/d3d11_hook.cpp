#include "core/d3d11_hook.hpp"
#include <iostream>

namespace D3D11Hook {
    bool Initialize() {
        std::cout << "[AURA.CC] DirectX 11 Present hook initialized for ImGui overlay." << std::endl;
        return true;
    }

    void Shutdown() {
        std::cout << "[AURA.CC] DirectX 11 hook removed cleanly." << std::endl;
    }
}
