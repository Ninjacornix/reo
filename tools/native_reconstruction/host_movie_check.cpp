#include "game/native/host_movie/player.hpp"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d11.h>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <stdexcept>
#include <string_view>
#include <thread>
#include <vector>

namespace movie=reo::native::host_movie;
namespace {
using Clock=std::chrono::steady_clock;
bool visible=false;
void messages(){if(!visible)return;MSG message;while(PeekMessageW(&message,nullptr,0,0,PM_REMOVE)){if(message.message==WM_QUIT)throw std::runtime_error("Native movie check window closed");TranslateMessage(&message);DispatchMessageW(&message);}}
template<class T>struct Com {T* p{};~Com(){if(p)p->Release();}T** out(){return &p;}T* operator->()const{return p;}};
void check(bool value,const char* why){if(!value)throw std::runtime_error(why);}
void hr(HRESULT value){check(SUCCEEDED(value),"Graphics operation failed");}
template<class F>void until(F&& fn,const char* why) {
    const auto deadline=Clock::now()+std::chrono::seconds(12);
    while(!fn()){messages();check(Clock::now()<deadline,why);std::this_thread::sleep_for(std::chrono::milliseconds(1));}
}
template<class F>void refused(F&& fn){bool rejected=false;try{fn();}catch(const std::invalid_argument&){rejected=true;}check(rejected,"Invalid operation did not refuse");}
}
LRESULT CALLBACK window_proc(HWND window,UINT message,WPARAM wparam,LPARAM lparam){if(message==WM_DESTROY){PostQuitMessage(0);return 0;}return DefWindowProcW(window,message,wparam,lparam);}
int wmain(int argc,wchar_t** argv)try {
    check(argc==3||argc==4,"Owned converted MP4 and corrupt test paths required; optional --window");const std::filesystem::path file=argv[1],corrupt=argv[2];
    visible=argc==4;check(!visible||std::wstring_view(argv[3])==L"--window","Unknown display option");
    Com<ID3D11Device> device;Com<ID3D11DeviceContext> context;
    hr(D3D11CreateDevice(nullptr,D3D_DRIVER_TYPE_HARDWARE,nullptr,D3D11_CREATE_DEVICE_VIDEO_SUPPORT|D3D11_CREATE_DEVICE_BGRA_SUPPORT,nullptr,0,D3D11_SDK_VERSION,device.out(),nullptr,context.out()));
    movie::Player player(device.p);check(player.snapshot().state==movie::State::closed,"Initial state");
    auto generation=player.open(file,{false,true,0.0});
    auto ready=[&]{auto s=player.snapshot();check(s.state!=movie::State::error,"Native movie load error");return s.state==movie::State::ready;};
    until(ready,"Initial movie readiness deadline");const auto metadata=player.snapshot();
    std::fprintf(stderr,"Native metadata: display=%ux%u aspect=%u:%u audio=%u duration=%.9f\n",metadata.display_width,metadata.display_height,metadata.aspect_x,metadata.aspect_y,unsigned(metadata.has_audio),metadata.duration_seconds);
    check(metadata.display_width==427&&metadata.display_height==320&&metadata.aspect_x*3==metadata.aspect_y*4&&!metadata.has_audio,"Expected owned movie display geometry and video-only source");
    D3D11_TEXTURE2D_DESC desc{};desc.Width=512;desc.Height=desc.Width*metadata.aspect_y/metadata.aspect_x;desc.MipLevels=desc.ArraySize=desc.SampleDesc.Count=1;
    desc.Format=DXGI_FORMAT_B8G8R8A8_UNORM;desc.Usage=D3D11_USAGE_DEFAULT;desc.BindFlags=D3D11_BIND_RENDER_TARGET|D3D11_BIND_SHADER_RESOURCE;
    Com<ID3D11Texture2D> target;hr(device->CreateTexture2D(&desc,nullptr,target.out()));
    HWND window=nullptr;Com<IDXGISwapChain> swapchain;Com<ID3D11Texture2D> backbuffer;
    if(visible) {
        WNDCLASSW cls{};cls.lpfnWndProc=window_proc;cls.hInstance=GetModuleHandleW(nullptr);cls.lpszClassName=L"ReoNativeMovieCheck";
        check(RegisterClassW(&cls)!=0,"Window registration");RECT bounds{0,0,static_cast<LONG>(desc.Width),static_cast<LONG>(desc.Height)};AdjustWindowRect(&bounds,WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU,FALSE);
        window=CreateWindowW(cls.lpszClassName,L"REO native MP4 playback test",WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT,bounds.right-bounds.left,bounds.bottom-bounds.top,nullptr,nullptr,cls.hInstance,nullptr);
        check(window!=nullptr,"Native test window");
        Com<IDXGIDevice> dxgi_device;hr(device->QueryInterface(IID_PPV_ARGS(dxgi_device.out())));Com<IDXGIAdapter> adapter;hr(dxgi_device->GetAdapter(adapter.out()));Com<IDXGIFactory> factory;hr(adapter->GetParent(IID_PPV_ARGS(factory.out())));
        DXGI_SWAP_CHAIN_DESC chain{};chain.BufferDesc.Width=desc.Width;chain.BufferDesc.Height=desc.Height;chain.BufferDesc.Format=desc.Format;chain.SampleDesc.Count=1;chain.BufferUsage=DXGI_USAGE_RENDER_TARGET_OUTPUT;chain.BufferCount=2;chain.OutputWindow=window;chain.Windowed=TRUE;chain.SwapEffect=DXGI_SWAP_EFFECT_DISCARD;
        hr(factory->CreateSwapChain(device.p,&chain,swapchain.out()));hr(swapchain->GetBuffer(0,IID_PPV_ARGS(backbuffer.out())));
    }
    auto read_desc=desc;read_desc.Usage=D3D11_USAGE_STAGING;read_desc.BindFlags=0;read_desc.CPUAccessFlags=D3D11_CPU_ACCESS_READ;
    Com<ID3D11Texture2D> readback;hr(device->CreateTexture2D(&read_desc,nullptr,readback.out()));
    std::vector<std::int64_t> times;std::uint64_t colored{};double pause_drift{};unsigned loop_wraps{};
    auto transfer=[&]{auto frame=player.transfer(generation,target.p);if(!frame.updated)return false;
        times.push_back(frame.pts_100ns);
        if(swapchain.p){context->CopyResource(backbuffer.p,target.p);hr(swapchain->Present(0,0));}
        if(times.size()%20==0) {
            context->CopyResource(readback.p,target.p);D3D11_MAPPED_SUBRESOURCE mapped{};
            hr(context->Map(readback.p,0,D3D11_MAP_READ,0,&mapped));
            const auto* data=static_cast<const unsigned char*>(mapped.pData);bool signal=false;
            for(unsigned y=0;y<desc.Height&&!signal;++y)for(unsigned x=0;x<desc.Width;++x){const auto* pixel=data+y*mapped.RowPitch+x*4;if(pixel[0]>20||pixel[1]>20||pixel[2]>20){signal=true;break;}}
            context->Unmap(readback.p,0);if(signal)++colored;
        }
        return true;};
    player.play(generation);const auto begin=Clock::now();
    until([&]{const auto state=player.snapshot();check(state.state!=movie::State::error,"Playback error");(void)transfer();return state.state==movie::State::ended;},"Complete playback deadline");
    const auto full_seconds=std::chrono::duration<double>(Clock::now()-begin).count();const auto full_count=times.size();
    check(full_seconds>metadata.duration_seconds-0.3&&full_seconds<metadata.duration_seconds+1.0,"Playback did not follow native real-time clock");
    check(full_count>=190&&full_count<=200&&colored>0,"Expected nearly complete paced picture delivery and actual colored GPU output");
    for(std::size_t i=1;i<times.size();++i)check(times[i]>times[i-1],"Unordered/duplicate native frame timestamps");
    player.seek(generation,0);player.play(generation);
    until([&]{(void)transfer();const auto s=player.snapshot();return !s.seeking&&s.position_seconds>=0.5&&s.position_seconds<1.5;},"Restart after EOF");
    player.pause(generation);std::this_thread::sleep_for(std::chrono::milliseconds(50));const auto paused=player.snapshot();
    std::this_thread::sleep_for(std::chrono::milliseconds(250));pause_drift=std::abs(player.snapshot().position_seconds-paused.position_seconds);
    check(paused.state==movie::State::paused&&pause_drift<0.005,"Paused native clock advanced");
    player.play(generation);until([&]{(void)transfer();return player.snapshot().position_seconds>paused.position_seconds+0.15;},"Resume did not progress");
    player.loop(generation,true);player.seek(generation,metadata.duration_seconds-0.15);
    until([&]{(void)transfer();const auto s=player.snapshot();if(!s.seeking&&s.position_seconds<0.5){++loop_wraps;return true;}return false;},"Native loop did not wrap");
    refused([&]{(void)player.open(file.parent_path()/"does-not-exist.mp4");});
    check(player.snapshot().generation==generation&&player.snapshot().loop,"Invalid open replaced active movie");
    refused([&]{player.seek(generation,-1);});refused([&]{player.volume(generation,2);});refused([&]{(void)player.transfer(generation,nullptr);});
    const auto previous=generation;generation=player.open(file,{false,true,0.0});check(generation>previous,"Replacement reused source identity");
    refused([&]{player.play(previous);});refused([&]{(void)player.transfer(previous,target.p);});
    until(ready,"Replacement readiness deadline");player.play(generation);
    until([&]{return transfer();},"Replacement produced no texture");
    player.close();check(player.snapshot().state==movie::State::closed&&player.snapshot().shutdown_error>=0,"Native source shutdown failed");
    refused([&]{player.play(generation);});refused([&]{(void)player.transfer(generation,target.p);});
    bool load_error=false;
    try {
        generation=player.open(corrupt,{false,true,0.0});
        until([&]{const auto s=player.snapshot();load_error=s.state==movie::State::error;return load_error;},"Corrupt movie produced no clear error");
    }catch(const std::runtime_error& error){if(std::string_view(error.what()).find("Native movie set source:")==0)load_error=true;else throw;}
    check(load_error,"Corrupt media did not report an error");
    generation=player.open(file,{false,true,0.0});until(ready,"Recovery from corrupt source");player.close();
    context->Flush();
    if(window)DestroyWindow(window);
    std::printf("{\"status\":\"native media-engine controls and GPU texture playback passed\",\"full_frames\":%zu,\"full_seconds\":%.6f,\"duration_seconds\":%.6f,\"colored_readbacks\":%llu,\"pause_drift_seconds\":%.9f,\"loop_wraps\":%u,\"last_generation\":%llu,\"corrupt_media_error_and_recovery\":true,\"game_run\":false,\"screen_presentation\":%s,\"audible_sync_tested\":false}\n",full_count,full_seconds,metadata.duration_seconds,static_cast<unsigned long long>(colored),pause_drift,loop_wraps,static_cast<unsigned long long>(generation),visible?"true":"false");return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}
