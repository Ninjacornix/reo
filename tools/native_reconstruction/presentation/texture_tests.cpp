#include "game/native/gameplay_presentation/texture.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
int main(int argc,char** argv)try{
    if(argc!=3)return 2;
    std::ifstream input(argv[1],std::ios::binary);std::vector<char> raw{std::istreambuf_iterator<char>(input),{}};
    const auto decoded=reo::native::gameplay_presentation::decompress_texture(std::as_bytes(std::span(raw)));
    const auto texture=reo::native::gameplay_presentation::decode_texture(decoded);
    bool refused=false;try{(void)reo::native::gameplay_presentation::decode_texture(std::span<const std::byte>(decoded).first(8));}catch(const std::invalid_argument&){refused=true;}
    if(!refused)throw std::runtime_error("Truncated TIM2 accepted");
    constexpr std::byte invalid[]{std::byte{0},std::byte{0x80},std::byte{1},std::byte{0x08}};
    refused=false;try{(void)reo::native::gameplay_presentation::decompress_texture(invalid);}catch(const std::invalid_argument&){refused=true;}
    if(!refused)throw std::runtime_error("Invalid compressed backreference accepted");
    std::ofstream output(argv[2],std::ios::binary);output.write(reinterpret_cast<const char*>(texture.rgba.data()),std::streamsize(texture.rgba.size()));
    if(!output)throw std::runtime_error("Texture fixture output unavailable");
    std::cout<<texture.width<<' '<<texture.height<<'\n';
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
