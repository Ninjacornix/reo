#include "game/native/gameplay_presentation/raster.hpp"
#include "game/native/gameplay_scenario/fog.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
using namespace reo::native;
int main()try{
    gameplay_presentation::Raster target(32,32);
    gameplay_scenario::CameraProjectionMatrices projection;projection.perspective=transform_math::identity();
    gameplay_scenario::CameraViewport viewport{0,0,32,32,0,1};
    gameplay_presentation::Texture red{1,1,{255,0,0,255}},blue{1,1,{0,0,255,255}};
    gameplay_presentation::SurfaceVertex a{{-.8f,-.8f,0},0,0},b{{.8f,-.8f,0},0,0},c{{0,.8f,0},0,0};
    bool refused=false;try{target.triangle(a,b,c,red);}catch(const std::invalid_argument&){refused=true;}if(!refused)throw std::runtime_error("Missing camera accepted");
    target.viewport(viewport,projection);target.view(transform_math::identity());target.triangle(a,b,c,red);
    if(target.pixels()[16*32+16]!=0xffff0000u)throw std::runtime_error("Triangle pixel missing");
    a.world.z=b.world.z=c.world.z=.5f;target.triangle(a,b,c,blue);
    if(target.pixels()[16*32+16]!=0xffff0000u)throw std::runtime_error("Depth order wrong");
    a.world.z=b.world.z=c.world.z=-.5f;target.triangle(a,b,c,blue);
    if(target.pixels()[16*32+16]!=0xff0000ffu)throw std::runtime_error("Near triangle missing");
    target.clear();if(target.pixels()[16*32+16]!=0xff000000u)throw std::runtime_error("Clear failed");
    a.world.z=-2;b.world.z=c.world.z=0;target.triangle(a,b,c,red);
    if(target.pixels()[16*32+16]!=0xffff0000u)throw std::runtime_error("Near-plane clipping discarded visible triangle");
    target.clear();a.world.z=b.world.z=c.world.z=-2;target.triangle(a,b,c,red);
    if(target.pixels()[16*32+16]!=0xff000000u)throw std::runtime_error("Outside triangle reached framebuffer");
    for(unsigned plane=0;plane<6;++plane){
        target.clear();a={{-.8f,-.8f,0},0,0};b={{.8f,-.8f,0},0,0};c={{0,.8f,0},0,0};
        float* components[]{&a.world.x,&a.world.y,&a.world.z,&b.world.x,&b.world.y,&b.world.z,&c.world.x,&c.world.y,&c.world.z};
        *components[plane/2]=(plane&1)?2.f:-2.f;
        target.triangle(a,b,c,red);
        if(std::none_of(target.pixels().begin(),target.pixels().end(),[](auto pixel){return pixel==0xffff0000u;}))throw std::runtime_error("Frustum crossing lost");
    }
    gameplay_presentation::Texture white{1,1,{255,255,255,255}};
    target.clear();a={{-.8f,-.8f,0},0,0,{1,0,0,1}};b={{.8f,-.8f,0},0,0,{0,1,0,1}};c={{0,.8f,0},0,0,{0,0,1,1}};
    target.triangle(a,b,c,white);const auto mixed=target.pixels()[16*32+16];const auto r=(mixed>>16)&255,g=(mixed>>8)&255,bl=mixed&255;
    if(r<60||r>62||g<70||g>72||bl<121||bl>123||r+g+bl<250||r+g+bl>255)throw std::runtime_error("Authored vertex color interpolation failed: "+std::to_string(r)+","+std::to_string(g)+","+std::to_string(bl));
    target.clear();projection.perspective[2][3]=.5f;target.viewport(viewport,projection);
    a.world={-.6f,-.6f,-.5f};b.world={.8f,-.8f,0};c.world={0,1,.5f};target.triangle(a,b,c,white);
    const auto perspective=target.pixels()[16*32+16];const auto pr=(perspective>>16)&255,pg=(perspective>>8)&255,pb=perspective&255;
    if(pr<81||pr>84||pg<70||pg>74||pb<98||pb>101)throw std::runtime_error("Perspective-correct color interpolation failed");
    projection.perspective=transform_math::identity();target.viewport(viewport,projection);
    a.world={-.8f,-.8f,0};b.world={.8f,-.8f,0};c.world={0,.8f,0};
    target.clear();a.world.x=-2;target.triangle(a,b,c,white);const auto clipped=target.pixels()[16*32+16];
    if(!(clipped&0xff0000u)||!(clipped&0xff00u)||!(clipped&0xffu))throw std::runtime_error("Clipped color interpolation failed");
    target.clear();a={{-.8f,-.8f,0},0,0,{1,1,1,.5f}};b={{.8f,-.8f,0},0,0,{1,1,1,.5f}};c={{0,.8f,0},0,0,{1,1,1,.5f}};
    target.triangle(a,b,c,white);if(target.pixels()[16*32+16]!=0xff7f7f7fu)throw std::runtime_error("Authored alpha blend failed");
    target.clear();a.color=b.color=c.color={1,1,1,1};if(!target.global_alpha(.5f)||target.global_alpha(2.f))throw std::runtime_error("Global alpha admission failed");
    target.triangle(a,b,c,white);if(target.pixels()[16*32+16]!=0xff7f7f7fu)throw std::runtime_error("Graphics alpha not consumed");
    target.clear();if(!target.global_alpha(0.f))throw std::runtime_error("Zero global alpha refused");target.triangle(a,b,c,white);
    if(target.pixels()[16*32+16]!=0xff000000u)throw std::runtime_error("Zero graphics alpha drew pixels");
    gameplay_scenario::FogState scene_fog;scene_fog.near_distance=10;scene_fog.far_distance=10;
    scene_fog.color={10,20,30};scene_fog.flash={246,20,128,0};
    const auto prepared=gameplay_presentation::prepare_scene_fog(scene_fog);
    if(!prepared||prepared->near_distance!=10||prepared->far_distance!=11||prepared->color!=std::array<std::uint8_t,3>{0,40,0})
        throw std::runtime_error("Scene fog publication mismatch");
    if(!target.global_alpha(1.f)||!target.fog(gameplay_presentation::RasterFog{0,1,{0,40,0}}))throw std::runtime_error("Fog configuration refused");
    target.clear();target.triangle(a,b,c,white);if(target.pixels()[16*32+16]!=0xff002800u)throw std::runtime_error("Fog color not consumed");
    if(!target.fog(gameplay_presentation::RasterFog{-1,2,{0,40,0}}))throw std::runtime_error("Fog range refused");
    target.clear();target.triangle(a,b,c,white);if(target.pixels()[16*32+16]!=0xff556f55u)throw std::runtime_error("Fog interpolation failed");
    if(target.fog(gameplay_presentation::RasterFog{1,1,{}})||!target.fog(std::nullopt))throw std::runtime_error("Fog admission failed");
    target.clear();target.triangle(a,b,c,white);if(target.pixels()[16*32+16]!=0xffffffffu)throw std::runtime_error("Fog disable failed");
    std::cout<<"26 raster checks passed\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
