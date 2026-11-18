#include "game/native/gameplay_presentation/raster.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("factor cases required");
    std::ifstream input(argv[1]);float clip_w{},near_distance{},far_distance{};unsigned expected{},checks{};
    while(input>>clip_w>>near_distance>>far_distance>>expected){
        const auto actual=reo::native::gameplay_presentation::fog_factor(clip_w,{near_distance,far_distance,{}});
        if(!actual||*actual!=expected)throw std::runtime_error("VU and native fog factor differ");
        ++checks;
    }
    if(!input.eof()||!checks)throw std::runtime_error("invalid factor cases");
    std::cout<<"{\"checks\":"<<checks<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
