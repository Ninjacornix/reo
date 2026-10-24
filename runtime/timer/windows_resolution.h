#pragma once
#ifdef _WIN32
#include <windows.h>
#include <mmsystem.h>
#include <cstdio>

namespace reo {
// The IRQ worker uses timed waits for the original 60 Hz clock and short
// VBlank intervals. Scope the precision request to the running game and pair
// it on every normal or exceptional return. This does not alter guest timing.
class ScopedTimerResolution {
    using ProcessInformationFunction = BOOL (WINAPI*)(HANDLE, PROCESS_INFORMATION_CLASS, LPVOID, DWORD);
    bool active_ = false;
    PROCESS_POWER_THROTTLING_STATE previous_{};
    bool policyChanged_ = false;
    ProcessInformationFunction setPolicy_ = nullptr;
public:
    explicit ScopedTimerResolution(bool request = true) {
        if (request) {
            previous_.Version = PROCESS_POWER_THROTTLING_CURRENT_VERSION;
            auto module = GetModuleHandleW(L"kernel32.dll");
            auto getPolicy = reinterpret_cast<ProcessInformationFunction>(GetProcAddress(module, "GetProcessInformation"));
            setPolicy_ = reinterpret_cast<ProcessInformationFunction>(GetProcAddress(module, "SetProcessInformation"));
            if (getPolicy && setPolicy_ && getPolicy(GetCurrentProcess(), ProcessPowerThrottling,
                                                    &previous_, sizeof(previous_))) {
                auto policy = previous_;
                constexpr ULONG controlled = PROCESS_POWER_THROTTLING_EXECUTION_SPEED |
                                             PROCESS_POWER_THROTTLING_IGNORE_TIMER_RESOLUTION;
                policy.ControlMask |= controlled;
                policy.StateMask &= ~controlled;
                policyChanged_ = setPolicy_(GetCurrentProcess(), ProcessPowerThrottling,
                                           &policy, sizeof(policy)) != FALSE;
                std::fprintf(stderr, "[FRAME-PACING] process timing policy=%s previous_control=%lu previous_state=%lu\n",
                             policyChanged_ ? "active" : "unavailable", previous_.ControlMask, previous_.StateMask);
            }
            active_ = timeBeginPeriod(1) == TIMERR_NOERROR;
            std::fprintf(stderr, "[FRAME-PACING] Windows 1ms timer precision=%s\n",
                         active_ ? "active" : "unavailable");
        }
    }
    ~ScopedTimerResolution() {
        if (active_) timeEndPeriod(1);
        if (policyChanged_)
            setPolicy_(GetCurrentProcess(), ProcessPowerThrottling, &previous_, sizeof(previous_));
    }
    ScopedTimerResolution(const ScopedTimerResolution&) = delete;
    ScopedTimerResolution& operator=(const ScopedTimerResolution&) = delete;
    bool active() const { return active_; }
};
}
#endif
