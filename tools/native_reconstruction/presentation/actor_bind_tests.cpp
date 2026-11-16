#include "game/native/gameplay_presentation/actor_bind.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
int main(int argc,char** argv)try{
    if(argc!=3)return 2;std::ifstream input(argv[1],std::ios::binary);std::vector<char> bytes{std::istreambuf_iterator<char>(input),{}};
    const auto matrices=reo::native::gameplay_presentation::actor_inverse_bind(std::as_bytes(std::span(bytes)));
    std::ofstream out(argv[2],std::ios::binary);out.write(reinterpret_cast<const char*>(matrices.data()),std::streamsize(matrices.size()*sizeof(matrices[0])));
    if(!out)throw std::runtime_error("Actor bind fixture output unavailable");std::cout<<matrices.size()<<'\n';
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
