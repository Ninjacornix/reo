#pragma once

namespace reo {

/*
 * DNAS Bypass
 *
 * Sony's DNAS (Dynamic Network Authentication System) was a DRM/anti-piracy
 * system for PS2 online games. It required connecting to gate1.jp.dnas.playstation.org
 * (or regional variants) over HTTPS with legacy SSL ciphers.
 *
 * Since we're running natively (not on PS2), DNAS is completely irrelevant.
 * This module ensures the game's DNAS calls succeed without contacting Sony's
 * (long-dead) servers. The obsrv.org community already has DNAS patches
 * for PCSX2; we apply the equivalent at the recompilation level.
 *
 * What we do:
 *   1. Intercept the recompiled DNAS initialization function
 *   2. Return success immediately
 *   3. Provide a fake DNAS ID if the game checks for one
 */

class DnasBypass {
  public:
    // Apply the bypass — call once during initialization
    static void apply();

    // Check if bypass is active
    static bool is_active();

    // Get a fake DNAS ID (some games check this)
    static const char* get_fake_id();
};

} // namespace reo
