#!/usr/bin/env python3
"""
AURA.CC Enterprise Build Script for AuraCleanMenu.dll
Automatically checks for MinGW-w64 compiler, installs it if missing, and compiles the DLL.
"""

import os
import subprocess
import sys

def run_cmd(cmd):
    print(f"[*] Running: {cmd}")
    result = subprocess.run(cmd, shell=True)
    if result.returncode != 0:
        print(f"[-] Command failed with code {result.returncode}")
        return False
    return True

def main():
    print("=================================================================")
    print("       AURA.CC — ENTERPRISE DLL AUTO-BUILD SCRIPT")
    print("=================================================================")

    # Check if x86_64-w64-mingw32-g++ is available
    check_mingw = subprocess.run("which x86_64-w64-mingw32-g++", shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    
    if check_mingw.returncode != 0:
        print("[*] MinGW-w64 compiler not found. Installing via apt-get...")
        print("[!] Note: If prompted for password in Codespaces, type: codespace")
        
        success = run_cmd("sudo apt-get update && sudo apt-get install -y g++-mingw-w64-x86-64 make")
        if not success:
            print("[-] Failed to install MinGW-w64. Please run manually:")
            print("    sudo apt-get update && sudo apt-get install -y g++-mingw-w64-x86-64 make")
            sys.exit(1)
    else:
        print("[+] MinGW-w64 compiler found!")

    # Create bin directory
    os.makedirs("bin", exist_ok=True)

    # Compile command
    compile_cmd = (
        "x86_64-w64-mingw32-g++ -std=c++20 -O3 -shared -static "
        "-Iinclude -D_WIN32_WINNT=0x0A00 "
        "src/main_clean.cpp src/ui/clean_menu.cpp src/core/config.cpp src/core/saas_cloud.cpp "
        "-o bin/AuraCleanMenu.dll -lws2_32 -lpsapi -ld3d11 -ld3dcompiler"
    )

    print("[*] Compiling AuraCleanMenu.dll...")
    if run_cmd(compile_cmd):
        print("\n[+] =========================================================")
        print("[+] BUILD SUCCESSFUL! File generated at: bin/AuraCleanMenu.dll")
        print("[+] =========================================================")
    else:
        print("\n[-] Build failed.")
        sys.exit(1)

if __name__ == "__main__":
    main()
