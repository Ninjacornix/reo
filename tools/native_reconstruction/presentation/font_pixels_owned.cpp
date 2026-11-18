#include "game/native/gameplay_presentation/font_face.hpp"
#include "game/native/gameplay_presentation/raster.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>
namespace p=reo::native::gameplay_presentation;
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("owned font required");
    std::ifstream file(argv[1],std::ios::binary);std::vector<char> raw{std::istreambuf_iterator<char>(file),{}};
    std::vector<std::byte> bytes(raw.size());std::transform(raw.begin(),raw.end(),bytes.begin(),[](char c){return std::byte(std::uint8_t(c));});
    p::FontFace font(std::move(bytes));p::Raster raster(640,448);raster.clear(0xff000000);
    const auto index=p::FontFace::index(std::uint16_t(p::FontFace::single_code('A')));
    const p::FontGlyph glyph{100,100,20,0x808080,index,128,true};
    if(!raster.text(font,std::span(&glyph,1)))throw std::runtime_error("glyph draw refused");
    constexpr std::array<unsigned,4> alpha{0,42,85,128};std::size_t checks=0,lit=0;
    for(unsigned y=0;y<20;++y)for(unsigned x=0;x<10;++x){
        const auto n=y*20+x;const auto packed=std::uint8_t(raw[std::size_t(index)*100+n/4]);
        const auto a=alpha[(packed>>(6-2*(n%4)))&3];const auto intensity=240*a/128;
        const auto expected=0xff000000u|(intensity<<16)|(intensity<<8)|intensity;
        if(raster.pixels()[(y+100)*640+x+100]!=expected)throw std::runtime_error("owned glyph pixel differs");
        ++checks;if(intensity)++lit;
    }
    if(!lit||raster.pixels()[100*640+110]!=0xff000000u)throw std::runtime_error("glyph crop coverage");++checks;
    const auto before=std::vector<std::uint32_t>(raster.pixels().begin(),raster.pixels().end());
    auto invisible=glyph;invisible.alpha=0;if(!raster.text(font,std::span(&invisible,1)))throw std::runtime_error("transparent glyph refused");
    if(!std::equal(before.begin(),before.end(),raster.pixels().begin()))throw std::runtime_error("transparent glyph modified pixels");++checks;
    raster.clear(0xff000000);auto offscreen=glyph;offscreen.x=-50;
    std::vector<p::FontGlyph> limited(255,offscreen);limited.push_back(glyph);auto beyond=glyph;beyond.x=300;limited.push_back(beyond);
    if(!raster.text(font,limited))throw std::runtime_error("bounded glyph draw refused");
    bool visible=false;for(unsigned y=100;y<120;++y)for(unsigned x=100;x<110;++x)visible|=raster.pixels()[y*640+x]!=0xff000000u;
    if(!visible)throw std::runtime_error("last admitted glyph missing");++checks;
    for(unsigned y=100;y<122;++y)for(unsigned x=300;x<312;++x)
        if(raster.pixels()[y*640+x]!=0xff000000u)throw std::runtime_error("glyph beyond512-emission budget drawn");
    ++checks;
    std::cout<<"{\"owned_glyph\":"<<index<<",\"lit_pixels\":"<<lit<<",\"checks\":"<<checks<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
