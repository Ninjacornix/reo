#include "input.h"
#include <cstdio>
#include <cstring>

#ifdef REO_PLATFORM_WINDOWS
#include <windows.h>
#include <xinput.h>
#pragma comment(lib, "xinput.lib")
#endif

namespace reo {

bool Input::init() {
    m_pads[0].reset();
    m_pads[1].reset();

#ifdef REO_PLATFORM_WINDOWS
    // Check for connected XInput controllers
    for (int i = 0; i < 2; i++) {
        XINPUT_STATE state;
        memset(&state, 0, sizeof(state));
        m_xinput_connected[i] = (XInputGetState(i, &state) == ERROR_SUCCESS);
        if (m_xinput_connected[i]) {
            printf("[INPUT] XInput controller %d connected\n", i);
        }
    }
#endif

    printf("[INPUT] Initialized (XInput + keyboard)\n");
    return true;
}

void Input::shutdown() {
    printf("[INPUT] Shutdown\n");
}

void Input::update() {
#ifdef REO_PLATFORM_WINDOWS
    for (int i = 0; i < 2; i++) {
        if (m_xinput_connected[i]) {
            update_xinput(i);
        }
    }
#endif
    update_keyboard();
}

void Input::update_controllers_only() {
    for (int i = 0; i < 2; ++i) {
        m_pads[i].reset();
#ifdef REO_PLATFORM_WINDOWS
        update_xinput(i);
#endif
    }
}

#ifdef REO_PLATFORM_WINDOWS
void Input::update_xinput(int port) {
    XINPUT_STATE state;
    memset(&state, 0, sizeof(state));

    if (XInputGetState(port, &state) != ERROR_SUCCESS) {
        m_xinput_connected[port] = false;
        return;
    }

    auto& pad = m_pads[port];
    uint16_t buttons = 0xFFFF; // All released

    WORD xb = state.Gamepad.wButtons;

    // Map XInput buttons → PS2 buttons
    if (xb & XINPUT_GAMEPAD_BACK)
        buttons &= ~PS2_SELECT;
    if (xb & XINPUT_GAMEPAD_LEFT_THUMB)
        buttons &= ~PS2_L3;
    if (xb & XINPUT_GAMEPAD_RIGHT_THUMB)
        buttons &= ~PS2_R3;
    if (xb & XINPUT_GAMEPAD_START)
        buttons &= ~PS2_START;
    if (xb & XINPUT_GAMEPAD_DPAD_UP)
        buttons &= ~PS2_UP;
    if (xb & XINPUT_GAMEPAD_DPAD_RIGHT)
        buttons &= ~PS2_RIGHT;
    if (xb & XINPUT_GAMEPAD_DPAD_DOWN)
        buttons &= ~PS2_DOWN;
    if (xb & XINPUT_GAMEPAD_DPAD_LEFT)
        buttons &= ~PS2_LEFT;
    if (xb & XINPUT_GAMEPAD_LEFT_SHOULDER)
        buttons &= ~PS2_L1;
    if (xb & XINPUT_GAMEPAD_RIGHT_SHOULDER)
        buttons &= ~PS2_R1;
    if (xb & XINPUT_GAMEPAD_Y)
        buttons &= ~PS2_TRIANGLE;
    if (xb & XINPUT_GAMEPAD_B)
        buttons &= ~PS2_CIRCLE;
    if (xb & XINPUT_GAMEPAD_A)
        buttons &= ~PS2_CROSS;
    if (xb & XINPUT_GAMEPAD_X)
        buttons &= ~PS2_SQUARE;

    // Analog triggers → L2/R2
    if (state.Gamepad.bLeftTrigger > 30) {
        buttons &= ~PS2_L2;
        pad.pressure[10] = state.Gamepad.bLeftTrigger;
    } else {
        pad.pressure[10] = 0;
    }

    if (state.Gamepad.bRightTrigger > 30) {
        buttons &= ~PS2_R2;
        pad.pressure[11] = state.Gamepad.bRightTrigger;
    } else {
        pad.pressure[11] = 0;
    }

    pad.buttons = buttons;

    // Analog sticks (XInput: -32768 to 32767) → PS2 (0-255, 128=center)
    pad.left_x = (uint8_t)((state.Gamepad.sThumbLX + 32768) >> 8);
    pad.left_y = (uint8_t)(255 - ((state.Gamepad.sThumbLY + 32768) >> 8)); // Inverted Y
    pad.right_x = (uint8_t)((state.Gamepad.sThumbRX + 32768) >> 8);
    pad.right_y = (uint8_t)(255 - ((state.Gamepad.sThumbRY + 32768) >> 8));
}
#endif

void Input::update_keyboard() {
#ifdef REO_PLATFORM_WINDOWS
    // If an XInput controller is connected, skip keyboard to avoid conflicts
    if (m_xinput_connected[0])
        return;

    auto& pad = m_pads[0];
    pad.reset(); // Start with all released

    // Helper: check if key is pressed
    auto key = [](int vk) -> bool { return (GetAsyncKeyState(vk) & 0x8000) != 0; };

    uint16_t buttons = 0xFFFF;

    // D-pad / movement: WASD
    if (key('W'))
        buttons &= ~PS2_UP;
    if (key('S'))
        buttons &= ~PS2_DOWN;
    if (key('A'))
        buttons &= ~PS2_LEFT;
    if (key('D'))
        buttons &= ~PS2_RIGHT;

    // Face buttons
    if (key(VK_SPACE))
        buttons &= ~PS2_CROSS; // Space → X (confirm)
    if (key('E'))
        buttons &= ~PS2_CIRCLE; // E → Circle
    if (key('Q'))
        buttons &= ~PS2_SQUARE; // Q → Square
    if (key('R'))
        buttons &= ~PS2_TRIANGLE; // R → Triangle

    // Shoulders and triggers
    if (key('1'))
        buttons &= ~PS2_L1;
    if (key('2'))
        buttons &= ~PS2_R1;
    if (key('3')) {
        buttons &= ~PS2_L2;
        pad.pressure[10] = 255;
    }
    if (key('4')) {
        buttons &= ~PS2_R2;
        pad.pressure[11] = 255;
    }

    // Keep the host fullscreen chord out of the game's Start button, even
    // when Control is released before Enter.
    static bool reservedEnter = false;
    if (!key(VK_RETURN))
        reservedEnter = false;
    else if (key(VK_CONTROL) || key(VK_LCONTROL) || key(VK_RCONTROL))
        reservedEnter = true;
    if (key(VK_RETURN) && !reservedEnter)
        buttons &= ~PS2_START;
    if (key(VK_BACK))
        buttons &= ~PS2_SELECT;
    if (key('Z'))
        buttons &= ~PS2_L3;
    if (key('X'))
        buttons &= ~PS2_R3;

    pad.buttons = buttons;

    // Right stick: arrow keys (for camera control)
    if (key(VK_LEFT))
        pad.right_x = 0x00;
    if (key(VK_RIGHT))
        pad.right_x = 0xFF;
    if (key(VK_UP))
        pad.right_y = 0x00;
    if (key(VK_DOWN))
        pad.right_y = 0xFF;

    // Left stick: WASD mapped to analog as well (for games that use analog)
    if (key('W'))
        pad.left_y = 0x00;
    if (key('S'))
        pad.left_y = 0xFF;
    if (key('A'))
        pad.left_x = 0x00;
    if (key('D'))
        pad.left_x = 0xFF;

    // Set pressure for digital buttons (full press = 255)
    if (!(buttons & PS2_CROSS))
        pad.pressure[6] = 255;
    if (!(buttons & PS2_CIRCLE))
        pad.pressure[5] = 255;
    if (!(buttons & PS2_SQUARE))
        pad.pressure[7] = 255;
    if (!(buttons & PS2_TRIANGLE))
        pad.pressure[4] = 255;
    if (!(buttons & PS2_L1))
        pad.pressure[8] = 255;
    if (!(buttons & PS2_R1))
        pad.pressure[9] = 255;
    if (!(buttons & PS2_UP))
        pad.pressure[2] = 255;
    if (!(buttons & PS2_DOWN))
        pad.pressure[3] = 255;
    if (!(buttons & PS2_LEFT))
        pad.pressure[1] = 255;
    if (!(buttons & PS2_RIGHT))
        pad.pressure[0] = 255;
#endif
}

} // namespace reo
