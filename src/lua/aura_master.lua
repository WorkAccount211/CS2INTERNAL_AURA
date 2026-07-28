-- AURA.CC Master Enterprise Lua Script
-- Fully compatible with Neverlose & Gamesense API standards

print("[AURA.CC Lua] aura_master.lua loaded successfully.")

local watermark_enable = ui.new_checkbox("Visuals", "General", "Enable AURA.CC Elite Watermark", true)
local rainbow_chams = ui.new_color_picker("Visuals", "Chams", "Rainbow Glow Chams Color", 168, 85, 247, 255)
local rage_override_key = ui.new_keybind("Ragebot", "Anti-Aim", "Freestand Override Key", 6, false)

client.set_event_callback("paint", function()
    if ui.get(watermark_enable) then
        local ping = client.latency() * 1000
        render.gradient(15, 15, 310, 32, 19, 27, 46, 220, 11, 15, 25, 220, "h")
        render.text(25, 23, 168, 85, 247, 255, "n", 0, "AURA.CC")
        render.text(82, 23, 255, 255, 255, 255, "n", 0, "| Enterprise VIP | 300 FPS | " .. math.floor(ping) .."ms")
    end
end)

client.set_event_callback("creatermove", function(cmd)
    if ui.get(rage_override_key) then
        rage.override_yaw(180)
    end
end)
