#include "startup_texture_registry.hpp"
#include "native_session.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <stdexcept>
namespace a=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
struct Notices final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
struct ReentrantSource final:reo::assets::PositionedSource {
    std::shared_ptr<const reo::assets::Source> source;
    mutable std::function<void()> callback;
    std::optional<std::uint64_t> trigger_offset;
    explicit ReentrantSource(std::shared_ptr<const reo::assets::Source> value):source(std::move(value)){}
    std::uint64_t size()const noexcept override{return source->size;}
    std::size_t read(std::uint64_t at,std::size_t n,void* out)const override{
        if(callback&&(!trigger_offset||at==*trigger_offset)){auto call=std::move(callback);callback={};call();}
        source->read(at,n,out);return n;
    }
};
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("owned NETBIO00 source required");
    auto disk=std::make_shared<const reo::assets::Source>(argv[1]);const auto root=reo::assets::table(*disk,0,disk->size);
    const auto offset=[&](const char* archive,const char* member){
        const auto top=std::find_if(root.entries.begin(),root.entries.end(),[&](const auto& row){return row.name==archive;});
        if(top==root.entries.end())throw std::runtime_error("archive unavailable");const auto list=reo::assets::table(*disk,top->offset,top->size);
        const auto item=std::find_if(list.entries.begin(),list.entries.end(),[&](const auto& row){return row.name==member;});
        if(item==list.entries.end())throw std::runtime_error("member unavailable");return std::uint64_t(top->offset)+item->offset;
    };
    const std::array<std::optional<std::uint64_t>,3> triggers{{{},offset("romdata_usa.afs","cockpit.tex"),offset("r041.afs","sii_041.itt")}};
    unsigned checks{};
    for(unsigned i=0;i<triggers.size();++i){
        auto backend=std::make_shared<ReentrantSource>(disk);auto source=std::make_shared<const reo::assets::Source>("reentrant owned asset",backend);
        w::Profile profile;profile.layouts.push_back({});Notices notices;a::NativeSession session(source,profile,notices,1);
        session.world().scenario=41;session.world().session().asset_loading_mode=1;
        a::StartupTextureRegistry registry(session.world(),source);bool closed{};backend->trigger_offset=triggers[i];
        backend->callback=[&]{closed=session.world().close()==w::Status::completed;};
        const auto status=registry.load_scenario_common(session);
        if(!closed||status!=a::StartupTextureStatus::closed||registry.bindings().size()!=(i==2?4u:0u))
            throw std::runtime_error("reentrant world close: case="+std::to_string(i)+" closed="+std::to_string(closed)+" status="+
                std::to_string(unsigned(status))+" bindings="+std::to_string(registry.bindings().size()));
        checks+=3;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
