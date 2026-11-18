#include "session_scenario_resources.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <stdexcept>
namespace a=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario::content;
struct ReentrantSource final:reo::assets::PositionedSource {
    std::shared_ptr<const reo::assets::Source> disk;
    mutable std::function<void()> callback;
    explicit ReentrantSource(std::shared_ptr<const reo::assets::Source> value):disk(std::move(value)){}
    std::uint64_t size()const noexcept override{return disk->size;}
    std::size_t read(std::uint64_t offset,std::size_t count,void* target)const override{
        disk->read(offset,count,target);
        if(callback){auto call=std::move(callback);callback={};call();}
        return count;
    }
};
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("owned NETBIO00 source required");
    unsigned checks{};const auto check=[&](bool value){++checks;if(!value)throw std::runtime_error("scenario resource check "+std::to_string(checks));};
    auto source=std::make_shared<const reo::assets::Source>(argv[1]);s::ScenarioArchive archive(source);
    auto session=std::make_shared<w::Session>();session->scenario=41;session->asset_loading_mode=1;
    w::Profile profile;profile.layouts.push_back({});w::World world(profile,session);
    a::SessionScenarioResources owner(world,archive);check(owner.bound_to(world)&&!owner.ready());
    check(owner.load_placements()==a::ScenarioDataStatus::unavailable&&owner.load_doors()==a::ScenarioDataStatus::unavailable);
    check(owner.initialize()==a::ScenarioDataStatus::completed&&owner.ready());
    check(owner.initialize()==a::ScenarioDataStatus::unavailable&&owner.positions().empty()&&!owner.doors());
    check(owner.load_placements()==a::ScenarioDataStatus::completed);
    const auto first=owner.placement(2,0,0);check(first.status==a::ScenarioDataStatus::completed&&first.placement.has_value());
    check(first.placement->yaw==0xe000&&first.placement->position==std::array<std::int32_t,3>{3314,-1000,3630});
    check(owner.placement(254,0,0).status==a::ScenarioDataStatus::completed&&!owner.placement(254,0,0).placement);
    check(owner.load_doors()==a::ScenarioDataStatus::completed);const auto doors=owner.doors();
    check(doors&&doors->groups.size()==1060&&doors->metadata==55&&doors->admissions.size()==128);
    check(std::all_of(doors->admissions.begin(),doors->admissions.end(),[](std::byte value){return value==std::byte{};}));
    check(owner.reset_positions()==a::ScenarioDataStatus::completed&&owner.positions().size()==64);
    check(std::all_of(owner.positions().begin(),owner.positions().end(),[](const auto& row){return row.type==0&&row.id==0&&row.group==0&&row.x==0&&row.z==0;}));
    session->scenario=3;check(owner.load_placements()==a::ScenarioDataStatus::unavailable&&owner.load_doors()==a::ScenarioDataStatus::unavailable);
    check(owner.placement(2,0,0).placement.has_value()&&owner.doors());
    session->scenario=41;check(owner.close()==a::ScenarioDataStatus::completed&&!owner.ready()&&!owner.doors()&&owner.positions().empty());
    check(owner.load_placements()==a::ScenarioDataStatus::closed&&owner.close()==a::ScenarioDataStatus::completed);
    for(unsigned kind=0;kind<3;++kind){
        auto backend=std::make_shared<ReentrantSource>(source);
        auto nested_source=std::make_shared<const reo::assets::Source>("reentrant scenario resources",backend);
        s::ScenarioArchive nested_archive(nested_source);
        auto state=std::make_shared<w::Session>();state->scenario=41;state->asset_loading_mode=1;
        w::World nested_world(profile,state);a::SessionScenarioResources nested_owner(nested_world,nested_archive);
        check(nested_owner.initialize()==a::ScenarioDataStatus::completed);
        check(nested_owner.load_placements()==a::ScenarioDataStatus::completed&&nested_owner.load_doors()==a::ScenarioDataStatus::completed&&
              nested_owner.load_return_points()==a::ScenarioDataStatus::completed&&nested_owner.reset_positions()==a::ScenarioDataStatus::completed);
        const auto retained=nested_owner.return_points();check(retained&&retained->rooms().size()==23);
        bool closed{};backend->callback=[&]{closed=nested_world.close()==w::Status::completed;};
        const auto result=kind==0?nested_owner.load_placements():kind==1?nested_owner.load_doors():nested_owner.load_return_points();
        check(closed&&result==a::ScenarioDataStatus::closed&&!nested_owner.ready()&&!nested_owner.busy());
        check(!nested_owner.doors()&&!nested_owner.return_points()&&nested_owner.positions().empty()&&
              nested_owner.placement(2,0,0).status==a::ScenarioDataStatus::closed);
        check(retained->rooms().size()==23&&nested_owner.close()==a::ScenarioDataStatus::completed);
    }
    std::cout<<"{\"checks\":"<<checks<<",\"scenario\":41,\"source\":\"owned NETBIO00\",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
