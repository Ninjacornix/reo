#include "game/native/gameplay_presentation/frontend_assets.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("owned NETBIO00 required");
    const auto source=std::make_shared<const reo::assets::Source>(argv[1]);
    reo::native::gameplay_presentation::FrontendAssets assets(source);
    const auto font=assets.load_font();const auto common=assets.load_common_textures();
    if(!common||common->expanded().size()!=2043328||!common->loading_texture()||
       common->loading_texture()->width!=256||common->loading_texture()->height!=128)throw std::runtime_error("owned frontend resources unavailable");
    const auto glyph=font.bitmap(reo::native::gameplay_presentation::FontFace::index(std::uint16_t(reo::native::gameplay_presentation::FontFace::single_code('A'))));
    if(glyph.size()!=100||std::all_of(glyph.begin(),glyph.end(),[](std::byte value){return value==std::byte{};}))throw std::runtime_error("owned font unavailable");
    std::cout<<"{\"expanded_bytes\":"<<common->expanded().size()<<",\"loading_width\":"<<common->loading_texture()->width<<",\"loading_height\":"<<common->loading_texture()->height<<",\"checks\":5,\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
