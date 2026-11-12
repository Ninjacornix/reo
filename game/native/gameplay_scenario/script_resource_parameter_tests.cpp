#include "script_resource_parameters.hpp"
#include "../gameplay_world/inventory.hpp"
#include "../gameplay_world/resource_factory.hpp"
#include "interpreter.hpp"
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace scene=reo::native::gameplay_scenario;
namespace world=reo::native::gameplay_world;
namespace {
std::size_t checks{},owner_cases{},script_cases{};
void check(bool value,const std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Script resource parameter check at "+std::to_string(at.line()));
}
world::Profile profile(){world::Profile p;p.layouts.push_back({});return p;}
scene::ResourceTemplates metadata(){
    std::vector<std::byte> bytes(32+24*3);const auto put=[&](unsigned at,auto value){std::memcpy(bytes.data()+at,&value,sizeof value);};
    put(0,3u);put(4,3u);put(16,32u);
    for(unsigned i=0;i<3;++i){put(32+24*i,i==0?0x40000u:i==1?0x20000u:0u);put(32+24*i+8,std::int16_t(100));put(32+24*i+18,std::uint16_t(31+i));}
    scene::ResourceTemplates result;check(result.load(bytes));return result;
}
struct Fixture {
    std::shared_ptr<world::Session> session=std::make_shared<world::Session>();
    world::World world{profile(),session};scene::SceneResources resources;scene::ResourceTemplates templates=metadata();
    world::ResourceModels models;world::ResourceFrames frames{world,resources,models,nullptr,{},&templates};
    world::WorldInventory inventory{world,resources,templates,frames};
    // Retirement never selects a static asset; this is a real cold asset owner.
    std::shared_ptr<const world::ResourceStaticAssets> assets=std::make_shared<world::ResourceStaticAssets>();
    world::ResourceFactory factory{models,frames,templates,assets};
    scene::ScriptResourceParameters commands{world,resources,templates,models,factory,inventory};
    Fixture(){world.mode=1;for(unsigned i=0;i<4;++i){auto actor=std::make_unique<world::Actor>();actor->active=true;actor->slot=std::uint8_t(i);actor->character=3;check(bool(world.spawn_primary(i,std::move(actor)).id));}}
    scene::SceneResourceId install(unsigned slot,unsigned content,unsigned index,unsigned owner=1){
        scene::SceneDescriptor descriptor;descriptor.active=1;descriptor.flags=0x20001;descriptor.instance_index=std::uint8_t(index);
        descriptor.attachment_id=std::uint16_t(content);descriptor.template_index=std::uint8_t(content-31);descriptor.parameter=17;descriptor.ownership_tag=std::uint16_t(owner);
        const auto id=resources.load(slot,descriptor);check(bool(id));return *id;
    }
};
void owners(){
    {
        Fixture fixture;const auto id=fixture.install(13,31,13);fixture.install(14,32,14);
        const auto created=fixture.models.create();check(created.status==world::ResourceModelStatus::completed);
        auto entry=*fixture.resources.get(id);entry.primary=created.model;check(fixture.resources.replace(id,entry)==scene::SceneStatus::completed);
        auto actor=fixture.world.primary(0);actor->inventory.carried={13,14,14,0};actor->selected_resource=actor->secondary_equipped_resource=13;actor->resource_action=99;
        check(fixture.commands.ready(31,0)&&fixture.commands.command(31,0)==scene::SceneStatus::completed);
        entry=*fixture.resources.get(id);check(!entry.active&&!entry.primary&&entry.parameter==17&&entry.flags==0x20000000u);
        check(fixture.resources.active_count()==1&&fixture.models.available()==64&&!created.model->current()&&!fixture.models.retain(created.id));
        check((actor->inventory.carried==std::array<std::uint8_t,4>{14,0,0,0})&&!actor->selected_resource&&!actor->secondary_equipped_resource&&!actor->resource_action);++owner_cases;
    }
    {
        Fixture fixture;const auto id=fixture.install(13,31,14);fixture.install(14,32,14);
        // Self-index metadata chooses row1, not descriptor13's own row0.
        check(fixture.commands.command(31,0)==scene::SceneStatus::completed);
        check(fixture.resources.get(id)->active&&fixture.resources.get(id)->parameter==0);
        check(fixture.commands.command(31,32767)==scene::SceneStatus::completed&&fixture.resources.get(id)->parameter==100);
        check(fixture.commands.command(31,-32768)==scene::SceneStatus::completed&&fixture.resources.get(id)->parameter==-32768);++owner_cases;
    }
    {
        Fixture fixture;const auto id=fixture.install(13,31,13,5);
        check(!fixture.commands.ready(31,0)&&fixture.commands.command(31,0)==scene::SceneStatus::provider_unavailable);
        check(fixture.resources.get(id)->active&&fixture.resources.get(id)->parameter==17);
        check(fixture.commands.command(31,1)==scene::SceneStatus::completed&&fixture.resources.get(id)->parameter==1);++owner_cases;
    }
    for(bool inactive:{false,true}){
        Fixture fixture;const auto id=fixture.install(13,31,14);const auto metadata=fixture.install(14,32,14);
        auto descriptor=*fixture.resources.get(metadata);descriptor.active=inactive?0:1;descriptor.template_index=inactive?0:255;
        check(fixture.resources.replace(metadata,descriptor)==scene::SceneStatus::completed);
        // Fallback row128 is cleared in this fixture: its maximum clamps to0,
        // while the separate flag query is zero regardless of fallback flags.
        check(fixture.commands.command(31,11)==scene::SceneStatus::completed);
        check(fixture.resources.get(id)->active&&fixture.resources.get(id)->parameter==0);++owner_cases;
    }
    {
        Fixture fixture;fixture.world.mode=0;fixture.session->gameplay_flags=1;
        check(fixture.models.close()==world::ResourceModelStatus::completed);
        check(fixture.commands.ready(31,0)&&fixture.commands.command(31,0)==scene::SceneStatus::completed);
        check(!fixture.commands.ready(32,1));++owner_cases;
    }
    {
        Fixture fixture;scene::SceneResources foreign;
        world::ResourceFrames frames(fixture.world,foreign,fixture.models,nullptr,{},&fixture.templates);
        world::ResourceFactory factory(fixture.models,frames,fixture.templates,fixture.assets);bool failed=false;
        try{scene::ScriptResourceParameters commands(fixture.world,fixture.resources,fixture.templates,fixture.models,factory,fixture.inventory);}catch(const std::invalid_argument&){failed=true;}
        check(failed);++owner_cases;
    }
}
std::vector<std::byte> script(std::uint16_t resource,std::int16_t quantity){
    std::vector<std::byte> result;const auto put=[&](std::uint32_t value){for(unsigned i=0;i<4;++i)result.push_back(std::byte((value>>(8*i))&255));};
    for(const auto word:std::array{0x02000110u,0u,77u,0u,0x02000170u,std::uint32_t(resource),std::uint32_t(std::uint16_t(quantity)),0u,0xau})put(word);
    return result;
}
void scripts(){
    Fixture fixture;fixture.install(13,31,13);scene::Providers providers;providers.world=&fixture.world;
    const auto run=[&](scene::Providers value){scene::Interpreter native;auto program=std::make_shared<const scene::Program>(std::vector<std::vector<std::byte>>{script(31,0)});
        check(program->needs_resource_parameters());check(native.install(0,program)==scene::Status::completed);
        const auto result=native.tick(0,{},value);return std::pair{result.status,native.counters()[0]};};
    check(run(providers)==std::pair{scene::Status::provider_unavailable,0u});++script_cases;
    providers.resource_parameters=&fixture.commands;
    scene::SceneResources foreign;providers.scene_resources=&foreign;check(run(providers)==std::pair{scene::Status::provider_unavailable,0u});++script_cases;
    providers.scene_resources=&fixture.resources;providers.resource_templates=&fixture.templates;
    check(run(providers)==std::pair{scene::Status::yielded,77u}&&!fixture.resources.get(*fixture.resources.slot(13))->active);++script_cases;
    fixture.world.mode=0;fixture.session->gameplay_flags=1;providers.resource_parameters=nullptr;providers.scene_resources=nullptr;providers.resource_templates=nullptr;
    check(run(providers)==std::pair{scene::Status::yielded,77u});++script_cases;
}
}
int main()try{owners();scripts();std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"owner_cases\":"<<owner_cases<<",\"script_cases\":"<<script_cases<<",\"game_launched\":false}\n";}
catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
