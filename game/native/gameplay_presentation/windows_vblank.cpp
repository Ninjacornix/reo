#include "windows_vblank.hpp"
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <new>
#include <thread>
#include <utility>
#ifdef _WIN32
#include <windows.h>
#include <dxgi.h>
#endif
namespace reo::native::gameplay_presentation {
struct WindowsVBlank::Impl {
#ifdef _WIN32
    HWND window{};HMONITOR monitor{};IDXGIOutput* output{};
    wchar_t device_name[32]{};
    DWORD refresh{};
#endif
    std::atomic<std::uint32_t> count{};
    std::atomic<bool> stopping{},failed{};
    mutable std::mutex mutex;
    std::condition_variable wake;
    std::thread worker;
    std::atomic<bool> closed{};
    ~Impl(){
        stopping.store(true,std::memory_order_release);wake.notify_all();if(worker.joinable())worker.join();
#ifdef _WIN32
        if(output)output->Release();
#endif
    }
    VBlankStatus validate()const noexcept{
        if(closed.load(std::memory_order_acquire)||stopping.load(std::memory_order_acquire))return VBlankStatus::closed;
        if(failed.load(std::memory_order_acquire))return VBlankStatus::device_failure;
#ifdef _WIN32
        DWORD process{};if(!window||!IsWindow(window)||!GetWindowThreadProcessId(window,&process)||process!=GetCurrentProcessId())return VBlankStatus::invalid_window;
        if(MonitorFromWindow(window,MONITOR_DEFAULTTONEAREST)!=monitor)return VBlankStatus::monitor_changed;
        DEVMODEW mode{};mode.dmSize=sizeof mode;if(!EnumDisplaySettingsW(device_name,ENUM_CURRENT_SETTINGS,&mode))return VBlankStatus::device_failure;
        if(mode.dmDisplayFrequency!=59&&mode.dmDisplayFrequency!=60)return VBlankStatus::unsupported_refresh;
        if(refresh&&mode.dmDisplayFrequency!=refresh)return VBlankStatus::monitor_changed;
        return VBlankStatus::completed;
#else
        return VBlankStatus::unavailable;
#endif
    }
};
WindowsVBlank::WindowsVBlank(std::unique_ptr<Impl> impl)noexcept:impl_(std::move(impl)){}
WindowsVBlank::~WindowsVBlank(){(void)close();}
VBlankOpened WindowsVBlank::open(void* raw)noexcept{
#ifdef _WIN32
    try{
        auto state=std::make_unique<Impl>();state->window=static_cast<HWND>(raw);DWORD process{};
        if(!state->window||!IsWindow(state->window)||!GetWindowThreadProcessId(state->window,&process)||process!=GetCurrentProcessId())return{VBlankStatus::invalid_window,{}};
        state->monitor=MonitorFromWindow(state->window,MONITOR_DEFAULTTONEAREST);if(!state->monitor)return{};
        IDXGIFactory* factory=nullptr;if(FAILED(CreateDXGIFactory(__uuidof(IDXGIFactory),reinterpret_cast<void**>(&factory)))||!factory)return{};
        for(UINT a=0;!state->output;++a){IDXGIAdapter* adapter=nullptr;const auto ar=factory->EnumAdapters(a,&adapter);if(ar==DXGI_ERROR_NOT_FOUND)break;if(FAILED(ar)||!adapter){factory->Release();return{};}
            for(UINT o=0;;++o){IDXGIOutput* output=nullptr;const auto result=adapter->EnumOutputs(o,&output);if(result==DXGI_ERROR_NOT_FOUND)break;if(FAILED(result)||!output){adapter->Release();factory->Release();return{};}
                DXGI_OUTPUT_DESC desc{};if(SUCCEEDED(output->GetDesc(&desc))&&desc.AttachedToDesktop&&desc.Monitor==state->monitor){state->output=output;for(unsigned i=0;i<32;++i)state->device_name[i]=desc.DeviceName[i];break;}output->Release();}
            adapter->Release();}
        factory->Release();if(!state->output)return{};
        const auto admission=state->validate();if(admission!=VBlankStatus::completed)return{admission,{}};
        DEVMODEW mode{};mode.dmSize=sizeof mode;if(!EnumDisplaySettingsW(state->device_name,ENUM_CURRENT_SETTINGS,&mode))return{};
        if(mode.dmDisplayFrequency!=59&&mode.dmDisplayFrequency!=60)return{VBlankStatus::unsupported_refresh,{}};state->refresh=mode.dmDisplayFrequency;
        auto* borrowed=state.get();state->worker=std::thread([borrowed]{
            while(!borrowed->stopping.load(std::memory_order_acquire)){
                if(FAILED(borrowed->output->WaitForVBlank())){{std::lock_guard lock(borrowed->mutex);borrowed->failed.store(true,std::memory_order_release);}borrowed->wake.notify_all();return;}
                {std::lock_guard lock(borrowed->mutex);if(borrowed->stopping.load(std::memory_order_acquire))break;borrowed->count.fetch_add(1,std::memory_order_release);}
                borrowed->wake.notify_all();
            }
        });
        return{VBlankStatus::completed,std::unique_ptr<WindowsVBlank>(new WindowsVBlank(std::move(state)))};
    }catch(...){return{};}
#else
    (void)raw;return{};
#endif
}
VBlankValue WindowsVBlank::counter()const noexcept{
    if(!impl_)return{VBlankStatus::closed,0};const auto status=impl_->validate();
    return{status,status==VBlankStatus::completed?impl_->count.load(std::memory_order_acquire):0};
}
VBlankValue WindowsVBlank::wait_next()noexcept{
    if(!impl_)return{VBlankStatus::closed,0};const auto initial=counter();if(initial.status!=VBlankStatus::completed)return initial;
    std::unique_lock lock(impl_->mutex);impl_->wake.wait(lock,[&]{return impl_->count.load(std::memory_order_acquire)!=initial.count||impl_->failed.load(std::memory_order_acquire)||impl_->stopping.load(std::memory_order_acquire);});
    return counter();
}
VBlankStatus WindowsVBlank::close()noexcept{
    if(!impl_||impl_->closed.load(std::memory_order_acquire))return VBlankStatus::completed;
    {std::lock_guard lock(impl_->mutex);impl_->stopping.store(true,std::memory_order_release);}impl_->wake.notify_all();
    if(impl_->worker.joinable())impl_->worker.join();impl_->closed.store(true,std::memory_order_release);
    return impl_->failed.load(std::memory_order_acquire)?VBlankStatus::device_failure:VBlankStatus::completed;
}
}
