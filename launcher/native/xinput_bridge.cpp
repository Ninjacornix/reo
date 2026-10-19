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
static INIT_ONCE once = INIT_ONCE_STATIC_INIT;
static HMODULE systemLibrary;
static HANDLE mapping;
static const SharedPad* pad;
static BOOL CALLBACK initialize(PINIT_ONCE, PVOID, PVOID*) {
    wchar_t directory[MAX_PATH], name[256];
    UINT length = GetSystemDirectoryW(directory, MAX_PATH);
    if (length && length + 15 < MAX_PATH) {
        lstrcatW(directory, L"\\xinput1_4.dll");
        systemLibrary = LoadLibraryW(directory);
    }
    DWORD count = GetEnvironmentVariableW(L"REO_LAUNCHER_PAD_MAP", name, 256);
    if (count && count < 256) {
        mapping = OpenFileMappingW(FILE_MAP_READ, FALSE, name);
        if (mapping)
            pad = (const SharedPad*)MapViewOfFile(mapping, FILE_MAP_READ, 0, 0, sizeof(SharedPad));
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
    if (index == 0 && readPad(*state))
        return ERROR_SUCCESS;
    ready();
    auto fn = (DWORD(WINAPI*)(DWORD, XINPUT_STATE*))GetProcAddress(systemLibrary, "XInputGetState");
    return fn ? fn(index, state) : ERROR_DEVICE_NOT_CONNECTED;
}
extern "C" __declspec(dllexport) DWORD WINAPI XInputSetState(DWORD index,
                                                             XINPUT_VIBRATION* vibration) {
    XINPUT_STATE state{};
    if (index == 0 && readPad(state))
        return ERROR_SUCCESS; // no physical rumble support
    ready();
    auto fn =
        (DWORD(WINAPI*)(DWORD, XINPUT_VIBRATION*))GetProcAddress(systemLibrary, "XInputSetState");
    return fn ? fn(index, vibration) : ERROR_DEVICE_NOT_CONNECTED;
}
extern "C" __declspec(dllexport) DWORD WINAPI XInputGetCapabilities(DWORD index, DWORD flags,
                                                                    XINPUT_CAPABILITIES* caps) {
    XINPUT_STATE state{};
    if (index == 0 && caps && readPad(state)) {
        ZeroMemory(caps, sizeof(*caps));
        caps->Type = XINPUT_DEVTYPE_GAMEPAD;
        caps->SubType = XINPUT_DEVSUBTYPE_GAMEPAD;
        caps->Gamepad.wButtons = 0xF3FF;
        caps->Gamepad.bLeftTrigger = caps->Gamepad.bRightTrigger = 255;
        return ERROR_SUCCESS;
    }
    ready();
    auto fn = (DWORD(WINAPI*)(DWORD, DWORD, XINPUT_CAPABILITIES*))GetProcAddress(
        systemLibrary, "XInputGetCapabilities");
    return fn ? fn(index, flags, caps) : ERROR_DEVICE_NOT_CONNECTED;
}
