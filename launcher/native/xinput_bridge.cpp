#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define XInputGetState SystemXInputGetStateDeclaration
#define XInputSetState SystemXInputSetStateDeclaration
#define XInputGetCapabilities SystemXInputGetCapabilitiesDeclaration
#include <xinput.h>
#undef XInputGetState
#undef XInputSetState
#undef XInputGetCapabilities
#include <stdint.h>

// Private launcher-only XInput adapter. The unmodified executable is copied
// beside this DLL; original build directories and Windows DLLs stay untouched.
struct SharedPad {
    DWORD magic;
    volatile LONG sequence;
    DWORD enabled, tick;
    XINPUT_STATE state;
};
static_assert(sizeof(SharedPad) == 32, "Launcher protocol layout");
struct SharedRumble {
    DWORD magic;
    volatile LONG sequence;
    DWORD tick;
    XINPUT_VIBRATION vibration;
};
static_assert(sizeof(SharedRumble) == 16, "Launcher rumble protocol layout");
static INIT_ONCE once = INIT_ONCE_STATIC_INIT;
static HMODULE systemLibrary;
static HANDLE mapping;
static const SharedPad* pad;
static SharedRumble* rumble;
static bool privatePad;
static BOOL CALLBACK initialize(PINIT_ONCE, PVOID, PVOID*) {
    wchar_t directory[MAX_PATH], name[256];
    UINT length = GetSystemDirectoryW(directory, MAX_PATH);
    if (length && length + 15 < MAX_PATH) {
        lstrcatW(directory, L"\\xinput1_4.dll");
        systemLibrary = LoadLibraryW(directory);
    }
    DWORD count = GetEnvironmentVariableW(L"REO_LAUNCHER_PAD_MAP", name, 256);
    privatePad = count != 0;
    if (count && count < 256) {
        mapping = OpenFileMappingW(FILE_MAP_READ | FILE_MAP_WRITE, FALSE, name);
        if (mapping) {
            auto* bytes = (uint8_t*)MapViewOfFile(mapping, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0,
                                                 sizeof(SharedPad) + sizeof(SharedRumble));
            if (bytes) {
                pad = (const SharedPad*)bytes;
                rumble = (SharedRumble*)(bytes + sizeof(SharedPad));
            }
        }
        // Older input-only producers may expose only the original 32 bytes.
        if (!pad) {
            if (mapping) CloseHandle(mapping);
            mapping = OpenFileMappingW(FILE_MAP_READ, FALSE, name);
            if (mapping)
                pad = (const SharedPad*)MapViewOfFile(mapping, FILE_MAP_READ, 0, 0, sizeof(SharedPad));
        }
    }
    return TRUE;
}
static void ready() {
    InitOnceExecuteOnce(&once, initialize, nullptr, nullptr);
}
static bool readPad(XINPUT_STATE& state) {
    ready();
    if (!pad || pad->magic != 0x52454F50)
        return false;
    for (int attempt = 0; attempt < 8; ++attempt) {
        LONG first = pad->sequence;
        if (first & 1)
            continue;
        MemoryBarrier();
        DWORD enabled = pad->enabled, tick = pad->tick;
        state = pad->state;
        MemoryBarrier();
        if (first != pad->sequence)
            continue;
        if (!enabled)
            return false;
        if (DWORD(GetTickCount() - tick) > 500)
            ZeroMemory(&state, sizeof(state));
        return true; // neutral on unplug/launcher stall, still reconnectable
    }
    ZeroMemory(&state, sizeof(state));
    return true;
}
extern "C" __declspec(dllexport) DWORD WINAPI XInputGetState(DWORD index, XINPUT_STATE* state) {
    if (!state)
        return ERROR_BAD_ARGUMENTS;
    ready();
    if (privatePad) {
        // The selected launcher device is the only game pad. Keep port zero
        // connected and neutral during startup, disconnects and lost heartbeats
        // so the game neither switches devices nor enables its default keyboard.
        ZeroMemory(state, sizeof(*state));
        if (index != 0) return ERROR_DEVICE_NOT_CONNECTED;
        if (!readPad(*state)) ZeroMemory(state, sizeof(*state));
        return ERROR_SUCCESS;
    }
    auto fn = (DWORD(WINAPI*)(DWORD, XINPUT_STATE*))GetProcAddress(systemLibrary, "XInputGetState");
    return fn ? fn(index, state) : ERROR_DEVICE_NOT_CONNECTED;
}
extern "C" __declspec(dllexport) DWORD WINAPI XInputSetState(DWORD index,
                                                             XINPUT_VIBRATION* vibration) {
    if (!vibration) return ERROR_BAD_ARGUMENTS;
    ready();
    if (privatePad) {
        // Never fall through to physical Xbox slot zero when the launcher has
        // selected a DualSense, another Xbox slot, keyboard or a disconnected pad.
        if (index != 0) return ERROR_DEVICE_NOT_CONNECTED;
        if (!rumble || rumble->magic != 0x52454f52 || !pad || pad->magic != 0x52454f50)
            return ERROR_SUCCESS;
        XINPUT_VIBRATION requested = *vibration;
        if (!pad->enabled || DWORD(GetTickCount() - pad->tick) > 500)
            ZeroMemory(&requested, sizeof(requested));
        for (int attempt = 0; attempt < 8; ++attempt) {
            LONG first = rumble->sequence;
            if (first & 1) continue;
            if (InterlockedCompareExchange(&rumble->sequence, LONG(DWORD(first) + 1), first) != first)
                continue;
            rumble->tick = GetTickCount();
            rumble->vibration = requested;
            MemoryBarrier();
            InterlockedExchange(&rumble->sequence, LONG(DWORD(first) + 2));
            return ERROR_SUCCESS;
        }
        return ERROR_BUSY;
    }
    auto fn =
        (DWORD(WINAPI*)(DWORD, XINPUT_VIBRATION*))GetProcAddress(systemLibrary, "XInputSetState");
    return fn ? fn(index, vibration) : ERROR_DEVICE_NOT_CONNECTED;
}
extern "C" __declspec(dllexport) DWORD WINAPI XInputGetCapabilities(DWORD index, DWORD flags,
                                                                    XINPUT_CAPABILITIES* caps) {
    if (!caps) return ERROR_BAD_ARGUMENTS;
    XINPUT_STATE state{};
    ready();
    if (index == 0 && (readPad(state) || privatePad)) {
        ZeroMemory(caps, sizeof(*caps));
        caps->Type = XINPUT_DEVTYPE_GAMEPAD;
        caps->SubType = XINPUT_DEVSUBTYPE_GAMEPAD;
        caps->Gamepad.wButtons = 0xF3FF;
        caps->Gamepad.bLeftTrigger = caps->Gamepad.bRightTrigger = 255;
        if (rumble && rumble->magic == 0x52454f52) {
            caps->Flags = XINPUT_CAPS_FFB_SUPPORTED;
            caps->Vibration.wLeftMotorSpeed = caps->Vibration.wRightMotorSpeed = 65535;
        }
        return ERROR_SUCCESS;
    }
    if (privatePad) {
        ZeroMemory(caps, sizeof(*caps));
        return ERROR_DEVICE_NOT_CONNECTED;
    }
    auto fn = (DWORD(WINAPI*)(DWORD, DWORD, XINPUT_CAPABILITIES*))GetProcAddress(
        systemLibrary, "XInputGetCapabilities");
    return fn ? fn(index, flags, caps) : ERROR_DEVICE_NOT_CONNECTED;
}
