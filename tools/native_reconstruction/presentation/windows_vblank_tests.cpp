#include "game/native/gameplay_presentation/windows_vblank.hpp"
#include <windows.h>
#include <chrono>
#include <iostream>
#include <stdexcept>
#include <thread>
using namespace reo::native::gameplay_presentation;
int main()try{
    if(WindowsVBlank::open(nullptr).status!=VBlankStatus::invalid_window)throw std::runtime_error("Null window admitted");
    const HWND window=CreateWindowExA(0,"STATIC","native vblank fixture",0,0,0,16,16,nullptr,nullptr,GetModuleHandleA(nullptr),nullptr);
    if(!window)throw std::runtime_error("Real process window unavailable");
    auto opened=WindowsVBlank::open(window);if(opened.status!=VBlankStatus::completed||!opened.owner)throw std::runtime_error("Real primary output or 60Hz mode unavailable");
    const auto first=opened.owner->wait_next();if(first.status!=VBlankStatus::completed||!first.count)throw std::runtime_error("Hardware vblank wait unavailable");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    const auto later=opened.owner->counter();if(later.status!=VBlankStatus::completed||std::uint32_t(later.count-first.count)<2)throw std::runtime_error("Idle hardware vblanks did not advance");
    const auto next=opened.owner->wait_next();if(next.status!=VBlankStatus::completed||next.count==later.count)throw std::runtime_error("Next hardware vblank was not observed");
    if(!DestroyWindow(window))throw std::runtime_error("Window teardown failed");
    if(opened.owner->counter().status!=VBlankStatus::invalid_window)throw std::runtime_error("Retired window admitted");
    if(opened.owner->close()!=VBlankStatus::completed||opened.owner->counter().status!=VBlankStatus::closed)throw std::runtime_error("Vblank owner teardown failed");
    std::cout<<"{\"checks\":7,\"idle_vblank_delta\":"<<std::uint32_t(later.count-first.count)<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
