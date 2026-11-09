#include "game/native/gameplay_scenario/scene_matrix_tables.hpp"
#include <bit>
#include <cmath>
#include <iostream>
#include <stdexcept>
int main()try{
 const auto& t=reo::native::gameplay_scenario::stock_scene_matrix_tables();bool first=true;std::cout<<'[';const auto emit=[&](std::int64_t value){if(!first)std::cout<<',';first=false;std::cout<<value;};
 for(auto v:t.descriptors)emit(v);
 for(auto pair:t.metadata)for(auto v:pair)emit(v);
 for(auto v:t.direct_remap)emit(v);
 for(const auto& p:t.programs){if(p.transform>3||!p.count||p.count>6)throw std::runtime_error("Invalid native program");emit(p.transform);emit(p.count);for(unsigned i=0;i<6;++i){if(i<p.count&&p.groups[i]>=59)throw std::runtime_error("Invalid native curve group");emit(p.groups[i]);}}
 for(const auto& g:t.groups){for(auto v:g.curves){if(v>=64)throw std::runtime_error("Invalid native curve identity");emit(v);}for(auto v:g.sounds){if(v< -1||v>=13)throw std::runtime_error("Invalid native sound identity");emit(v);}}
 for(const auto& curve:t.curves){if(curve.size()<2)throw std::runtime_error("Incomplete native curve");emit(curve.size());for(unsigned i=0;i<curve.size();++i){if(!std::isfinite(curve[i].value)||(i&&curve[i].time<=curve[i-1].time))throw std::runtime_error("Invalid native curve key");emit(std::bit_cast<std::uint32_t>(curve[i].value));emit(curve[i].time);}}
 for(const auto& sound:t.sounds){emit(sound.size());for(unsigned i=0;i<sound.size();++i){if(i&&sound[i].time<=sound[i-1].time)throw std::runtime_error("Invalid native sound timing");emit(sound[i].event);emit(sound[i].time);}}
 std::cout<<"]\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
