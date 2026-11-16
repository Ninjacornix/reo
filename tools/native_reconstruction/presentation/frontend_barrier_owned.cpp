#include "game/native/gameplay_presentation/frontend_assets.hpp"
#include "game/native/gameplay_presentation/frontend_display.hpp"
#include "game/native/gameplay_world/world.hpp"
#include "runtime/assets/virtual_afs.h"
#include <windows.h>
#include <iostream>
#include <stdexcept>
namespace p=reo::native::gameplay_presentation;
namespace w=reo::native::gameplay_world;
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("owned NETBIO00 required");
    auto source=std::make_shared<const reo::assets::Source>(argv[1]);p::FrontendAssets assets(source);
    const auto common=assets.load_common_textures();if(!common||!common->loading_texture())throw std::runtime_error("loading texture unavailable");
    w::Profile profile;profile.layouts.push_back({});profile.entities.capacity=16;
    w::World world(profile,std::make_shared<w::Session>()),foreign(profile,std::make_shared<w::Session>());
    const auto window=CreateWindowExA(0,"STATIC","frontend barrier test",WS_OVERLAPPEDWINDOW,0,0,640,448,nullptr,nullptr,GetModuleHandleA(nullptr),nullptr);
    if(!window)throw std::runtime_error("window unavailable");ShowWindow(window,SW_SHOWNOACTIVATE);
    auto opened=p::WindowsVBlank::open(window);if(opened.status!=p::VBlankStatus::completed||!opened.owner)throw std::runtime_error("display clock unavailable");
    p::BackgroundState background;if(!background.select(0))throw std::runtime_error("background unavailable");
    p::FrontendDisplay display(world,window,*opened.owner,background);
    if(!display.bound_to(world)||display.bound_to(foreign)||display.quiesce(foreign)||display.resource_barriers()!=0)throw std::runtime_error("foreign world admitted");
    if(!display.drain())throw std::runtime_error("initial drain unavailable");
    for(unsigned i=0;i<3;++i)if(!display.loading_pass(*common->loading_texture()))throw std::runtime_error("loading pass unavailable");
    if(display.loading_passes()!=3||!display.pending_surface())throw std::runtime_error("pending loading surface absent");
    if(!display.quiesce(world)||display.pending_surface()||display.resource_barriers()!=1)throw std::runtime_error("pending surface not quiesced");
    if(!display.quiesce(world)||display.resource_barriers()!=2)throw std::runtime_error("idle barrier unavailable");
    if(opened.owner->close()!=p::VBlankStatus::completed||display.quiesce(world))throw std::runtime_error("closed clock accepted");
    if(!DestroyWindow(window))throw std::runtime_error("window cleanup failed");
    std::cout<<"{\"loading_passes\":3,\"barriers\":2,\"foreign_world_refused\":true,\"closed_clock_refused\":true,\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
