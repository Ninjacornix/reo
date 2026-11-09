#include "offline.hpp"
#include "../gameplay_world/world.hpp"

namespace reo::native::gameplay_scenario {
Status OfflineCoordinator::restore(const OfflineState& value)noexcept{
    if(running_)return Status::busy;
    state_=value;return Status::completed;
}
OfflineResult OfflineCoordinator::tick(Interpreter& vm,std::size_t requested,bool enabled,
    std::span<const OfflinePartyActor,3> party,std::uint16_t current_room,std::uint8_t& selected,
    FlagState& flags,Providers providers,std::size_t budget,std::optional<std::uint32_t> stream_tick)noexcept{
    OfflineResult out;
    if(running_){out.status=Status::busy;return out;}
    if(requested>=Interpreter::channel_count){out.status=Status::invalid_channel;return out;}
    providers.flags=&flags;providers.canonical_flags=&flags;
    constexpr std::array<std::uint8_t,4> class_channel{1,2,3,0};
    const auto admitted=[&](std::size_t channel){const auto& c=vm.channels()[channel];return c.program&&c.program->profile()==DispatchProfile::offline_actor;};
    if(requested!=1){if(!admitted(requested)){out.status=Status::invalid_program;return out;}}
    else for(const auto& actor:party)if(actor.active&&(actor.script_class>=class_channel.size()||!admitted(class_channel[actor.script_class]))){out.status=Status::invalid_program;return out;}
    const auto missing_stream=[&](std::size_t channel,std::size_t owner){const auto& program=*vm.channels()[channel].program;
        return (program.needs_streams()&&(!stream_tick||!providers.streams||!providers.stream_backend))||
            (program.needs_saved_controls()&&(!providers.saved_controls||owner>=3))||
            (program.needs_world()&&(!providers.world||&selected!=&providers.world->selected_actor))||
            (program.needs_selected_actor()&&(!providers.world||!providers.world->primary(owner)))||
            (program.needs_action_choices()&&!providers.action_choices);};
    if(requested!=1){if(missing_stream(requested,selected)){out.status=Status::provider_unavailable;return out;}}
    else for(std::size_t i=0;i<party.size();++i)if(party[i].active&&missing_stream(class_channel[party[i].script_class],i)){out.status=Status::provider_unavailable;return out;}
    running_=true;struct Reset{bool& flag;~Reset(){flag=false;}} reset{running_};
    if(requested!=1){
        out.actors[0]=vm.tick_offline_channel(requested,{enabled,false,selected,current_room,stream_tick},{0,0,0},providers,budget);
        out.invocations=1;out.operations=out.actors[0].operations;out.status=out.actors[0].status;return out;
    }
    auto baseline=flags.shared();
    for(std::size_t i=0;i<party.size();++i){
        selected=static_cast<std::uint8_t>(i);const auto& actor=party[i];if(!actor.active)continue;
        flags.shared(baseline);
        const OfflineDispatch dispatch{std::uint32_t(actor.script_class)+1,actor.room==current_room?0u:1u,actor.room};
        out.actors[i]=vm.tick_offline_channel(class_channel[actor.script_class],{enabled,false,selected,current_room,stream_tick},dispatch,providers,budget-out.operations);
        ++out.invocations;out.operations+=out.actors[i].operations;
        if(out.actors[i].status!=Status::yielded&&out.actors[i].status!=Status::disabled){out.status=out.actors[i].status;return out;}
        const auto after=flags.shared();auto& delta=state_.actors[i];
        for(std::size_t j=0;j<16;++j){
            delta.added.scenario[j]=after.scenario[j]&~baseline.scenario[j];delta.removed.scenario[j]=baseline.scenario[j]&~after.scenario[j];
            delta.added.secondary[j]=after.secondary[j]&~baseline.secondary[j];delta.removed.secondary[j]=baseline.secondary[j]&~after.secondary[j];
        }
    }
    for(const auto& delta:state_.actors)for(std::size_t j=0;j<16;++j){
        baseline.scenario[j]=(baseline.scenario[j]|delta.added.scenario[j])&~delta.removed.scenario[j];
        baseline.secondary[j]=(baseline.secondary[j]|delta.added.secondary[j])&~delta.removed.secondary[j];
    }
    flags.shared(baseline);selected=0;out.status=Status::completed;return out;
}
} // namespace reo::native::gameplay_scenario
