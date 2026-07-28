-- AURA.CC Enterprise Sample Lua Script
-- Compatible with Neverlose / Gamesense / Fatality API standards

print("[AURA.CC] Lua API initialized successfully.")

-- Register a custom UI Menu item
local custom_watermark = ui.new_checkbox("Visuals", "Watermark", "Enable AURA.CC Elite Watermark", true)
local rage_fov_slider = ui.new_slider("Ragebot", "Targeting", "Rage FOV", 0, 180, 180)

client.set_event_callback("paint", function()
    if ui.get(custom_watermark) then
        render.text(15, 15, 255, 255, 255, 255, "n", 0, "AURA.CC | Enterprise VIP | 1000€/wk | FPS: 300 | Ping: 12ms")
    end
end)

client.set_event_callback("creatermove", function(cmd)
    -- Advanced strafe & movement enhancements inspired by strafe.one & Neverlose
    if cmd.buttons.in_jump and entity.get_local_player():is_airborne() then
        movement.auto_strafe(cmd)
    end
end)
