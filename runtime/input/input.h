#pragma once

#include <cstdint>

namespace reo {

/*
 * Input System
 *
 * Maps modern controllers (XInput/DirectInput) and keyboard to
 * DualShock 2 button state that the game expects.
 *
 * DualShock 2 button layout:
 *   Digital: Select, L3, R3, Start, Up, Right, Down, Left
 *            L2, R2, L1, R1, Triangle, Circle, Cross, Square
 *   Analog:  Left stick X/Y, Right stick X/Y
 *   Pressure: All face buttons + shoulders have 0-255 pressure
 */

// PS2 button bit positions (in the 16-bit digital buttons field)
enum PS2Button : uint16_t {
    PS2_SELECT = 0x0001,
    PS2_L3 = 0x0002,
    PS2_R3 = 0x0004,
    PS2_START = 0x0008,
    PS2_UP = 0x0010,
    PS2_RIGHT = 0x0020,
    PS2_DOWN = 0x0040,
    PS2_LEFT = 0x0080,
    PS2_L2 = 0x0100,
    PS2_R2 = 0x0200,
    PS2_L1 = 0x0400,
    PS2_R1 = 0x0800,
    PS2_TRIANGLE = 0x1000,
    PS2_CIRCLE = 0x2000,
    PS2_CROSS = 0x4000,
    PS2_SQUARE = 0x8000,
};

struct DualShock2State {
    uint16_t buttons;     // Bit field (0 = pressed, PS2 convention)
    uint8_t right_x;      // Right stick X (0x80 = center)
    uint8_t right_y;      // Right stick Y (0x80 = center)
    uint8_t left_x;       // Left stick X (0x80 = center)
    uint8_t left_y;       // Left stick Y (0x80 = center)
    uint8_t pressure[12]; // Pressure for: Right,Left,Up,Down,Tri,Circle,Cross,Square,L1,R1,L2,R2

    void reset() {
        buttons = 0xFFFF; // All released (0 = pressed)
        right_x = 0x80;
        right_y = 0x80;
        left_x = 0x80;
        left_y = 0x80;
        for (int i = 0; i < 12; i++)
            pressure[i] = 0;
    }
};

class Input {
  public:
    Input() = default;

    bool init();
    void shutdown();

    // Poll all input devices and update state
    void update();
    void update_controllers_only();

    // Get the current DualShock2-compatible state
    const DualShock2State& get_pad(int port = 0) const {
        return m_pads[port & 1];
    }

    // Keyboard mappings (default: WASD + arrow keys + typical bindings)
    // TODO: Configurable key mapping

  private:
    void update_xinput(int port);
    void update_keyboard();

    DualShock2State m_pads[2] = {};
    bool m_xinput_connected[2] = {};
};

} // namespace reo
