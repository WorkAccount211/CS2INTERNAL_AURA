# 🌟 AURA.CC — CS2 Enterprise Ultimate SaaS Internal Cheat & DLL

<p align="center">
  <b>The Absolute Pinnacle of Counter-Strike 2 (Source 2) Internal Architecture</b><br>
  <i>Fully Functional Engine | Real Memory Offsets (sezzyaep/CS2-OFFSETS) | Real HWID User Fingerprint | Acrylic Menu</i>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/CS2-Source%202-blue?style=for-the-badge&logo=counter-strike" alt="CS2">
  <img src="https://img.shields.io/badge/Tier-Enterprise%20VIP-gold?style=for-the-badge" alt="SaaS Tier">
  <img src="https://img.shields.io/badge/Architecture-C%++20%20%7C%20Single%20File%20DLL-purple?style=for-the-badge" alt="Tech Stack">
  <img src="https://img.shields.io/badge/Status-Undetected%20(2026)-success?style=for-the-badge" alt="Status">
</p>

---

## 💎 Overview & Features

**AURA.CC Enterprise** is a state-of-the-art internal cheat suite for Counter-Strike 2. All files are fully synchronized, featuring real-time memory reading using up-to-date offsets, functional movement features (Bunny Hop, Auto Strafe), ESP overlays, Legit Aimbot with RCS, and a secure HWID machine fingerprint generator.

---

## 🛠️ How to Compile `aura_master_dll.cpp` into `AuraInternal.dll` (PC Guide)

Чтобы скомпилировать исходный код в полноценный файл `AuraInternal.dll` на ПК с Windows:

1. **Установите Visual Studio** (с поддержкой разработки на C++ / Desktop development with C++).
2. Создайте проект типа **Dynamic-Link Library (DLL)** в Visual Studio.
3. Добавьте файл `src/aura_master_dll.cpp` в ваш проект.
4. В свойствах проекта выберите конфигурацию **Release** и платформу **x64**.
5. Нажмите **Build -> Build Solution** (Ctrl + Shift + B).
6. Готовый файл `AuraInternal.dll` появится в папке `x64/Release/` вашего проекта.

---

## 💉 How to Run via Extreme Injector

1. Запустите **Counter-Strike 2**.
2. Запустите **Extreme Injector v3.x** (или любой другой универсальный DLL инжектор от имени Администратора).
3. В поле **Process Name** выберите процесс игры `cs2.exe`.
4. Нажмите **Add DLL** и выберите ваш скомпилированный файл `AuraInternal.dll`.
5. Нажмите кнопку **Inject**.
6. В игре появится консоль Extreme Injector с логами, подтверждающими успешную инжекцию и выводящими ваш **реальный HWID пользователя**.

---

## ⌨️ Hotkeys & Controls

* **`INSERT`** — Открыть / скрыть акриловое меню чита (в консоли выведется лог переключения `Menu toggled: OPEN / CLOSED`).
* **`END`** — Безопасно выгрузить DLL из игры.
* **`SPACE`** — Удержание для работы автоматического Bunny Hop.

---

## 📂 Repository Structure

```tree
.
├── include/
│   ├── core/         # Memory, config & d3d11 hooks
│   ├── features/     # ESP, Aimbot, Movement, Rage, Skins
│   ├── loader/       # C++ Loader core
│   ├── lua/          # Lua 5.4 VM & API bindings
│   ├── sdk/          # CS2 Offsets (sezzyaep sync) & vectors
│   └── ui/           # Clean menu states
├── src/
│   ├── core/ ...
│   ├── features/ ...
│   ├── loader/ ...
│   ├── lua/ ...
│   ├── ui/ ...
│   ├── aura_master_dll.cpp # Unified Master DLL Architecture
│   └── main.cpp            # DLL Entry point
├── images/           # UI Previews & Mockups
├── Makefile          # Build automation
└── README.md
```

---

## 🛡️ License & Commercial Terms

AURA.CC Enterprise SaaS is licensed under commercial terms. Unauthorized redistribution or reverse engineering is strictly prohibited by AURA.CC DRM.

*© 2026 AURA.CC Security. All Rights Reserved.*
