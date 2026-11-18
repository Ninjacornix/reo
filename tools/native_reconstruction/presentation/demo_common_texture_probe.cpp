#include "game/native/gameplay_presentation/texture.hpp"
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

int main(int argc,char** argv)try {
    if(argc!=2)throw std::runtime_error("compressed demo texture file required");
    std::ifstream input(argv[1],std::ios::binary);
    std::vector<char> raw{std::istreambuf_iterator<char>(input),{}};
    if(raw.empty())throw std::runtime_error("demo texture file empty");
    const auto expanded=reo::native::gameplay_presentation::decompress_texture(
        {reinterpret_cast<const std::byte*>(raw.data()),raw.size()});
    std::size_t at{};unsigned count{};std::uint64_t pixels{};
    while(at<expanded.size()){
        if(expanded.size()-at<32||std::memcmp(expanded.data()+at,"TIM2",4))throw std::runtime_error("demo texture sequence unavailable");
        const auto header=at+(std::to_integer<unsigned>(expanded[at+5])?128u:16u);
        if(header>expanded.size()-4)throw std::runtime_error("demo texture header unavailable");
        std::uint32_t total{};std::memcpy(&total,expanded.data()+header,4);
        if(total>expanded.size()-header)throw std::runtime_error("demo texture extent unavailable");
        const auto end=header+total;
        const auto value=reo::native::gameplay_presentation::decode_texture(
            std::span(expanded).subspan(at,end-at));
        pixels+=std::uint64_t(value.width)*value.height;++count;at=end;
    }
    std::cout<<"{\"textures\":"<<count<<",\"pixels\":"<<pixels<<",\"expanded_bytes\":"<<expanded.size()<<"}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
