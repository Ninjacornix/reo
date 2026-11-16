#include "frontend_display.hpp"
#include "../gameplay_world/world.hpp"
#include <algorithm>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>
#endif
namespace reo::native::gameplay_presentation {
namespace {
bool window_ready(void* value)noexcept{
#ifdef _WIN32
    const auto window=static_cast<HWND>(value);DWORD process{};
    return window&&IsWindow(window)&&GetWindowThreadProcessId(window,&process)&&process==GetCurrentProcessId();
#else
    (void)value;return false;
#endif
}
}
FrontendDisplay::FrontendDisplay(gameplay_world::World& world,void* window,WindowsVBlank& clock,const BackgroundState& background):
    world_(world),window_(window),clock_(clock),background_(background),pixels_(640u*448u){
    if(world_.closed()||!window_ready(window_)||clock_.counter().status!=VBlankStatus::completed)throw std::invalid_argument("Frontend display unavailable");
}
bool FrontendDisplay::bound_to(const void* window,const WindowsVBlank& clock)const noexcept{return !world_.closed()&&window==window_&&&clock==&clock_&&window_ready(window_);}
bool FrontendDisplay::bound_to(const gameplay_world::World& world)const noexcept{return &world_==&world&&!world_.closed()&&window_ready(window_);}
bool FrontendDisplay::drain()noexcept{
    if(running_||!window_ready(window_)||clock_.counter().status!=VBlankStatus::completed)return false;
#ifdef _WIN32
    return GdiFlush()!=0;
#else
    return false;
#endif
}
bool FrontendDisplay::quiesce(const gameplay_world::World& world)noexcept{
    if(running_||!bound_to(world)||clock_.counter().status!=VBlankStatus::completed)return false;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    // The third1B0510 quad is still staged after that function returns.
    //18D6C0 submits the current pending buffer before waiting for completion.
    if(pending_){if(!submit())return false;pending_=false;}
#ifdef _WIN32
    if(!GdiFlush())return false;
    ++resource_barriers_;return true;
#else
    return false;
#endif
}
bool FrontendDisplay::submit()noexcept{
#ifdef _WIN32
    const auto hwnd=static_cast<HWND>(window_);RECT rect{};
    if(!window_ready(window_)||IsIconic(hwnd)||!GetClientRect(hwnd,&rect)||rect.right<=rect.left||rect.bottom<=rect.top)return false;
    const auto dc=GetDC(hwnd);if(!dc)return false;BITMAPINFO info{};
    info.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);info.bmiHeader.biWidth=640;info.bmiHeader.biHeight=-448;
    info.bmiHeader.biPlanes=1;info.bmiHeader.biBitCount=32;info.bmiHeader.biCompression=BI_RGB;
    const auto result=StretchDIBits(dc,0,0,rect.right-rect.left,rect.bottom-rect.top,0,0,640,448,pixels_.data(),&info,DIB_RGB_COLORS,SRCCOPY);
    ReleaseDC(hwnd,dc);return result!=-1&&result!=0;
#else
    return false;
#endif
}
bool FrontendDisplay::loading_pass(const Texture& texture)noexcept{
    if(running_||!window_ready(window_)||texture.width!=256||texture.height!=128||texture.rgba.size()!=256u*128u*4u)return false;
    const auto background=background_.parameter14();if(!background)return false;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    if(!initialized_){std::fill(pixels_.begin(),pixels_.end(),*background);initialized_=true;}
    // 1B0510 calls1BAAF0(1) before each 1AB860 draw: submit the previous
    // surface and observe a real display boundary before staging this quad.
    if(!submit())return false;pending_=false;
    if(clock_.wait_next().status!=VBlankStatus::completed)return false;
    std::fill(pixels_.begin(),pixels_.end(),*background);
    for(unsigned y=0;y<128;++y)for(unsigned x=0;x<256;++x){
        const auto at=(std::size_t(y)*256+x)*4;const auto alpha=unsigned(texture.rgba[at+3]);
        auto& pixel=pixels_[(std::size_t(y)+320)*640+x+368];const auto old=pixel;
        const auto blend=[&](unsigned channel,unsigned shift){return(unsigned(texture.rgba[at+channel])*alpha+((old>>shift)&255)*(255-alpha))/255;};
        pixel=0xff000000u|(blend(0,16)<<16)|(blend(1,8)<<8)|blend(2,0);
    }
    pending_=true;++loading_passes_;return true;
}
}
