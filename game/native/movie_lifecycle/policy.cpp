#include "policy.hpp"
#include <algorithm>
#include <cstdio>
namespace reo::native::movie_lifecycle {
Reply Policy::call(std::string_view kind,std::span<const std::uint32_t> args)noexcept{return ports_.call(kind,args,state_);}
Reply Policy::command(unsigned component,unsigned command,std::span<const std::uint32_t> args)noexcept {
    if(!(state_.components&(1u<<component)))return{};
    std::array<char,32> name{};std::snprintf(name.data(),name.size(),"command-%u-%u",component,command);return call(name.data(),args);
}
std::uint32_t Policy::error(std::uint32_t code)noexcept{return call("error",{&code,1}).status;}
std::uint32_t Policy::broadcast(unsigned value)noexcept{for(unsigned i=0;i<9;++i){const auto result=command(i,value).status;if(result)return result;}return 0;}
bool Policy::construct()noexcept {
    // Workspace clearing is a native value reset, not guest memory emulation.
    const auto registry=state_.registry;const auto reuse=state_.reuse;
    state_={};state_.registry=registry;state_.reuse=reuse;state_.pending=1;
    for(const auto name:{"header_init","metadata_init","metrics_init","statistics_init","error_init"})(void)call(name);
    state_.current=config_.defaults;state_.saved=config_.defaults;
    (void)call("clock_init");
    if(call("streams_init").status)return false;
    (void)call("components_init");state_.components=config_.components;
    (void)call("shared_init");
    if(broadcast(3))return false;
    state_.actual=1;state_.requested=1;return true;
}
std::uint32_t Policy::destroy_children()noexcept{state_.actual=0;state_.requested=0;return broadcast(4);}
std::uint32_t Policy::reset()noexcept {
    if(state_.actual==4){const auto result=command(7,7).status;if(result)return result;}
    state_.actual=1;state_.requested=1;return 0;
}
std::uint32_t Policy::rebuild()noexcept {
    const auto snapshot_enabled=state_.current[8];std::uint32_t old_snapshot{};
    if(snapshot_enabled){const auto old=state_.actual?command(0,9):Reply{error(0xff000134)};
        if(!old.snapshot_written){defined_=false;return 0;}old_snapshot=old.snapshot;}
    (void)call("header_clear");(void)call("streams_clear");
    const auto destroyed=destroy_children();if(destroyed)return destroyed;
    // Save AFTER destroy callbacks, restore AFTER all constructor callbacks.
    const auto saved=state_.saved;
    if(!construct())return error(0xff000202);
    state_.current=saved;state_.saved=saved;
    if(snapshot_enabled){
        const auto fresh=command(0,9);if(fresh.status)return fresh.status;
        if(!fresh.snapshot_written){defined_=false;return 0;}
        const std::array values{old_snapshot,fresh.snapshot};const auto reconciled=command(0,10,values).status;if(reconciled)return reconciled;
        const std::uint32_t flag=1;(void)call("stream_flag",{&flag,1});state_.pending=1;
    }
    return 0;
}
std::uint32_t Policy::stop()noexcept {
    if(state_.actual==1)return 0;
    const auto result=reset();if(result)return result;
    if(config_.hooks)(void)call("guard_enter");
    state_.reuse=1;const auto rebuilt=rebuild();state_.reuse=0;
    if(config_.hooks)(void)call("guard_leave");
    return rebuilt;
}
Result Policy::execute(Operation op)noexcept {
    defined_=true;std::uint32_t value{};
    switch(op){
    case Operation::create:{
        if(!config_.source_available || config_.workspace_bytes<0x2ba0){(void)error(0xff000203);break;}
        const auto free=std::find(state_.registry.begin(),state_.registry.end(),0u);if(free==state_.registry.end())break;
        const auto index=static_cast<unsigned>(free-state_.registry.begin());value=construct();state_.registry[index]=value?1:0;break;}
    case Operation::start:
        if(!state_.actual){value=error(0xff000132);break;}
        state_.requested=state_.current[47]==1?3:4;state_.pending=1;break;
    case Operation::reset:value=reset();break;
    case Operation::rebuild:value=rebuild();break;
    case Operation::stop:
        if(!state_.actual){value=error(0xff000133);break;}
        value=stop();state_.pending=1;break;
    case Operation::destroy:
        if(!state_.actual){value=error(0xff000131);break;}
        (void)stop();(void)call("header_clear");(void)call("streams_clear");value=destroy_children();
        for(auto& entry:state_.registry)if(entry==1)entry=0;
        break;
    }
    return{value,defined_};
}
}
