#include "script_resource_activation.hpp"
#include "interpreter.hpp"
#include "flags.hpp"
#include "../gameplay_world/resource_factory.hpp"
#include <bit>
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace scene=reo::native::gameplay_scenario;
namespace world=reo::native::gameplay_world;
namespace {
std::size_t checks{},commands{},scripts{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Resource activation check at "+std::to_string(at.line()));
}
world::Profile profile(){world::Profile result;result.layouts.push_back({});return result;}
struct Fixture {
    std::shared_ptr<world::Session> session=std::make_shared<world::Session>();world::World world{profile(),session};
    scene::SceneResources resources;scene::ResourceTemplates templates;world::ResourceModels models;
    world::ResourceFrames frames{world,resources,models,nullptr,{},&templates};
    std::shared_ptr<const world::ResourceStaticAssets> assets=std::make_shared<world::ResourceStaticAssets>();
    world::ResourceFactory factory{models,frames,templates,assets};
    scene::ScriptResourceActivation activation{world,resources,templates,models,factory};
    Fixture(){world.mode=1;world.room=7;}
    scene::SceneResourceId install(scene::SceneDescriptor descriptor){const auto id=resources.load(13,std::move(descriptor));check(bool(id));return *id;}
};
void owner_commands(){
    for(unsigned mode:{0u,1u,2u,255u})for(auto delay:std::array<std::int16_t,7>{INT16_MIN,-32767,-1,0,1,3,INT16_MAX}){
        Fixture fixture;fixture.session->clock_mode=std::uint8_t(mode);scene::SceneDescriptor descriptor;
        descriptor.active=128;descriptor.kind=255;descriptor.authored_id=31;descriptor.attachment_id=65535;descriptor.instance_index=201;
        descriptor.room=7;descriptor.flags=0xa5a50000u;const auto id=fixture.install(descriptor);
        check(fixture.activation.command(31,delay)==scene::SceneStatus::completed);
        const auto current=*fixture.resources.get(id);const auto model=std::dynamic_pointer_cast<world::ResourceModel>(current.primary);
        check(model&&model->current()&&model->active&&!model->visible&&model->resource_slot==201&&model->content_id==65535);
        check(model->program.elapsed==(mode?std::int16_t(delay/2):delay));
        check(bool(std::dynamic_pointer_cast<world::DelayedResourceWork>(model->work)));
        check(current.flags==((descriptor.flags|1u)&~0x200000u)&&fixture.models.available()==63);++commands;
    }
    for(unsigned trial=0;trial<32;++trial){
        Fixture fixture;scene::SceneDescriptor descriptor;descriptor.active=(trial&1)?128:0;descriptor.kind=(trial&2)?1:0;
        descriptor.authored_id=31;descriptor.room=(trial&4)?7:8;descriptor.ownership_tag=(trial&8)?1:0;descriptor.flags=0x202000u;
        if(trial&16)descriptor.primary=std::make_shared<scene::SceneAttachment>();
        const auto id=fixture.install(descriptor);
        check(fixture.activation.command(31,80)==scene::SceneStatus::completed);const auto current=*fixture.resources.get(id);
        const bool active=descriptor.active&&descriptor.kind,construct=active&&!descriptor.primary&&descriptor.room==7&&!descriptor.ownership_tag;
        check(current.flags==(active?(construct?(descriptor.flags|1u)&~0x200000u:descriptor.flags|1u):descriptor.flags));
        check(fixture.models.available()==(construct?63u:64u));++commands;
    }
    {
        Fixture fixture;scene::SceneDescriptor descriptor;descriptor.active=descriptor.kind=1;descriptor.authored_id=31;descriptor.room=7;descriptor.flags=0x200000;
        const auto id=fixture.install(descriptor);for(unsigned i=0;i<64;++i)check(fixture.models.create().status==world::ResourceModelStatus::completed);
        check(fixture.activation.command(31,80)==scene::SceneStatus::completed);const auto current=*fixture.resources.get(id);
        check(current.flags==1&&!current.primary&&!fixture.models.available());++commands;
    }
    {
        Fixture fixture;scene::SceneDescriptor descriptor;descriptor.authored_id=31;const auto first=fixture.install(descriptor);
        descriptor.active=descriptor.kind=1;descriptor.room=7;check(bool(fixture.resources.load(14,descriptor)));
        check(fixture.activation.command(31,80)==scene::SceneStatus::completed&&!fixture.resources.get(first)->active&&fixture.models.available()==64);++commands;
        check(fixture.models.close()==world::ResourceModelStatus::completed);
        for(auto literal:std::array<std::int16_t,3>{0,-1,INT16_MIN})check(fixture.activation.command(literal,80)==scene::SceneStatus::completed);
    }
}
std::vector<std::byte> script(std::int16_t id){
    const std::array<std::uint32_t,9> words{0x02000110u,0u,77u,0u,0x02000174u,std::uint32_t(std::uint16_t(id))|0xabcd0000u,0xbeef0050u,0u,0xau};
    std::vector<std::byte> bytes(sizeof words);std::memcpy(bytes.data(),words.data(),sizeof words);return bytes;
}
void script_commands(){
    for(bool offline:{false,true}){
        Fixture fixture;scene::FlagState flags;scene::Providers providers;providers.flags=providers.canonical_flags=&flags;providers.world=&fixture.world;
        const auto run=[&](std::int16_t id,scene::Providers supplied){scene::Interpreter interpreter;
            auto program=std::make_shared<const scene::Program>(std::vector<std::vector<std::byte>>{script(id)},offline?scene::DispatchProfile::offline_actor:scene::DispatchProfile::ordinary);
            check(program->needs_resource_activation()==(id>0)&&program->needs_world()==(id>0));
            check(interpreter.install(0,program)==scene::Status::completed);
            const auto result=offline?interpreter.tick_offline_channel(0,{}, {},supplied):interpreter.tick(0,{},supplied);
            ++scripts;return std::pair{result.status,interpreter.counters()[0]};};
        for(auto id:std::array<std::int16_t,3>{0,-1,INT16_MIN}){auto literal=providers;literal.world=nullptr;check(run(id,literal)==std::pair{scene::Status::yielded,77u});}
        check(run(31,providers)==std::pair{scene::Status::provider_unavailable,0u});providers.resource_activation=&fixture.activation;
        scene::SceneResources foreign;providers.scene_resources=&foreign;check(run(31,providers)==std::pair{scene::Status::provider_unavailable,0u});
        providers.scene_resources=&fixture.resources;providers.resource_templates=&fixture.templates;check(run(31,providers)==std::pair{scene::Status::yielded,77u});
    }
}
}
int main()try{owner_commands();script_commands();std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"commands\":"<<commands<<",\"scripts\":"<<scripts<<",\"game_launched\":false}\n";}
catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
