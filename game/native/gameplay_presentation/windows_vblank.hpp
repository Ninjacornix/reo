#pragma once
#include <cstdint>
#include <memory>
namespace reo::native::gameplay_presentation {
enum class VBlankStatus {completed,unavailable,invalid_window,monitor_changed,unsupported_refresh,device_failure,closed,busy};
struct VBlankValue {VBlankStatus status{VBlankStatus::unavailable};std::uint32_t count{};};
class WindowsVBlank;
struct VBlankOpened {VBlankStatus status{VBlankStatus::unavailable};std::unique_ptr<WindowsVBlank> owner;};
// Owns one actual Windows display-output wait worker. The process-owned HWND
// outlives this owner. The observed counter starts at zero at open and advances
// only after real successful output vblank waits, even while the simulation is
// idle. A preempted worker may miss physical refreshes; no ticks are inferred.
class WindowsVBlank final {
public:
    static VBlankOpened open(void* window)noexcept;
    ~WindowsVBlank();
    WindowsVBlank(const WindowsVBlank&)=delete;
    WindowsVBlank& operator=(const WindowsVBlank&)=delete;
    VBlankValue counter()const noexcept;
    VBlankValue wait_next()noexcept;
    VBlankStatus close()noexcept;
private:
    struct Impl;
    explicit WindowsVBlank(std::unique_ptr<Impl>)noexcept;
    std::unique_ptr<Impl> impl_;
};
}
