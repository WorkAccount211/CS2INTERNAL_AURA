# AURA.CC CS2 Enterprise Internal Cheat Makefile
# C++20 / Windows Target (MinGW / MSVC compatible)

CXX = x86_64-w64-mingw32-g++
CXXFLAGS = -std=c++20 -O3 -shared -static -Iinclude -D_WIN32_WINNT=0x0A00
LDFLAGS = -lws2_32 -lpsapi

TARGET = bin/AuraInternal.dll
SRC = src/main.cpp src/core/memory.cpp src/core/saas_auth.cpp src/core/config.cpp src/features/visuals.cpp src/features/aimbot.cpp src/features/movement.cpp src/features/antiaim.cpp src/features/skins.cpp src/features/misc.cpp src/ui/menu.cpp

all: directories $(TARGET)

directories:
	mkdir -p bin

$(TARGET): $(SRC)
	@echo "[*] Compiling AURA.CC CS2 Enterprise Internal..."
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
	@echo "[+] Build complete: $(TARGET)"

clean:
	rm -rf bin
