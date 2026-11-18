#include "startup_texture_registry.hpp"
#include "native_session.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
namespace a=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
struct Notices final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("owned NETBIO00 source required");unsigned checks{};
    const auto check=[&](bool value){++checks;if(!value)throw std::runtime_error("cockpit registry check "+std::to_string(checks));};
    auto source=std::make_shared<const reo::assets::Source>(argv[1]);w::Profile profile;profile.layouts.push_back({});Notices notices;
    a::NativeSession session(source,profile,notices,1);session.world().scenario=41;session.world().session().asset_loading_mode=1;
    a::StartupTextureRegistry registry(session.world(),source);check(registry.bound_to(session.world()));
    check(registry.release_cockpit_pair()==a::StartupTextureStatus::completed&&registry.bindings().empty());
    check(registry.load_scenario_common(session)==a::StartupTextureStatus::completed&&registry.bindings().size()==5);
    constexpr std::array<std::pair<unsigned,unsigned>,5> size{{{256,256},{256,256},{64,64},{128,128},{256,256}}};
    for(unsigned i=0;i<5;++i){const auto texture=registry.texture(0x2600+i);check(texture&&texture->width==size[i].first&&texture->height==size[i].second);}
    const auto first_2602=registry.texture(0x2602),first_item=registry.texture(0x2604);
    for(unsigned retry=0;retry<2;++retry){
        check(registry.release_cockpit_pair()==a::StartupTextureStatus::completed);
        check(registry.load_scenario_common(session)==a::StartupTextureStatus::completed);
        check(registry.texture(0x2602)==first_2602&&registry.texture(0x2604)==first_item);
    }
    const auto rows=registry.bindings();check(rows.size()==11);
    check(std::count_if(rows.begin(),rows.end(),[](const auto& row){return row.id==0x2602;})==3);
    check(std::count_if(rows.begin(),rows.end(),[](const auto& row){return row.id==0x2603;})==3);
    check(std::is_sorted(rows.begin(),rows.end(),[](const auto& lhs,const auto& rhs){return lhs.physical_slot<rhs.physical_slot;}));
    check(std::count_if(rows.begin(),rows.end(),[](const auto& row){return row.id==0x2604&&row.references==1;})==3);
    check(registry.load_game_etc()==a::StartupTextureStatus::completed&&registry.load_game_etc()==a::StartupTextureStatus::completed);
    const auto current=registry.bindings();const auto numeric=std::find_if(current.begin(),current.end(),[](const auto& row){return row.id==0x2500;});
    check(numeric!=current.end()&&numeric->references==2&&numeric->texture);
    auto foreign_source=std::make_shared<const reo::assets::Source>(argv[1]);a::NativeSession foreign(foreign_source,profile,notices,1);
    foreign.world().scenario=41;foreign.world().session().asset_loading_mode=1;
    check(registry.load_scenario_common(foreign)==a::StartupTextureStatus::unavailable&&registry.bindings().size()==12);
    check(registry.close()==a::StartupTextureStatus::completed&&!registry.texture(0x2602));
    std::cout<<"{\"checks\":"<<checks<<",\"source\":\"owned NETBIO00\",\"warm_retries\":2,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
