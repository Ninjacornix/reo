#include "game/native/gameplay_presentation/model_mesh.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>
int main(int argc,char** argv)try{
    if(argc!=4)return 2;
    constexpr std::size_t expected_parts[]{69,96,4},expected_vertices[]{19439,19572,3556},expected_triangles[]{10837,13589,3910};
    std::size_t checks=0;
    for(int i=1;i<argc;++i){
        std::ifstream f(argv[i],std::ios::binary);std::vector<char> raw{std::istreambuf_iterator<char>(f),{}};
        const auto input=std::as_bytes(std::span(raw));const auto mesh=reo::native::gameplay_presentation::ModelMesh::import(input);
        std::size_t vertices=0,triangles=0,skinned=0;for(const auto& part:mesh.parts){vertices+=part.vertices.size();triangles+=part.triangles.size();for(const auto& v:part.vertices)if(!v.influences.empty())++skinned;}
        if(mesh.parts.size()!=expected_parts[i-1]||vertices!=expected_vertices[i-1]||triangles!=expected_triangles[i-1]||skinned!=(i==3?vertices:0))throw std::runtime_error("Owned mesh counts differ");++checks;
        std::size_t normalized=0,zero_mode=0,absent=0,format_zero=0,option_enabled=0;
        for(const auto& part:mesh.parts)if(part.render_profile){const auto& p=*part.render_profile;
            normalized+=p.color_mode==0x300;zero_mode+=p.color_mode==0;format_zero+=p.format==0;option_enabled+=p.option_12;
        }else ++absent;
        if((i==1&&(normalized!=69||format_zero!=69||option_enabled!=69||zero_mode||absent))||
           (i==2&&(normalized!=88||zero_mode!=1||absent!=7))||
           (i==3&&(absent!=4||normalized||zero_mode)))throw std::runtime_error("Owned render profiles differ");
        ++checks;
        // r0417300 part 9 vertex 0 has authored RGBA (20.611225..., 20.611225...,
        // 20.611225..., 204); source packs integer bytes, then normalizes.
        if(i==1){const auto& color=mesh.parts[9].vertices[0].color;
            if(color!=std::array<float,4>{20.f/255.f,20.f/255.f,20.f/255.f,102.f/128.f})
                throw std::runtime_error("Owned vertex color conversion differs");
            ++checks;}
        for(const auto& part:mesh.parts)for(const auto& tri:part.triangles){if(tri.a>=part.vertices.size()||tri.b>=part.vertices.size()||tri.c>=part.vertices.size())throw std::runtime_error("Out-of-range triangle");++checks;}
        bool refused=false;try{(void)reo::native::gameplay_presentation::ModelMesh::import(input.first(28));}catch(const std::invalid_argument&){refused=true;}if(!refused)throw std::runtime_error("Truncated model accepted");++checks;
        std::cout<<argv[i]<<" parts="<<mesh.parts.size()<<" vertices="<<vertices<<" triangles="<<triangles<<" skinned="<<skinned<<'\n';
    }
    std::cout<<"checks="<<checks<<'\n';
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
