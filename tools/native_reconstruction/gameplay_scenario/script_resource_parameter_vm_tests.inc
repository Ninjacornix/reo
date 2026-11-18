#include "game/native/gameplay_scenario/script_resource_parameters.hpp"
#include "game/native/gameplay_world/inventory.hpp"
#include "game/native/gameplay_world/resource_factory.hpp"
namespace {
namespace resource_world=reo::native::gameplay_world;
std::size_t resource_parameter_dispatches{},resource_parameter_releases{},resource_parameter_refusals{};
bool resource_parameter_original_active{};
PS2Runtime::Function resource_parameter_port(std::uint32_t at){
    if(!resource_parameter_original_active)return nullptr;
    switch(at){
    case 0x5b1850:return original_resource_release;
    case 0x591be0:return original_resource_deactivate;
    case 0x5f2180:return original_inventory_detach;
    case 0x5f2330:return original_inventory_compact;
    default:return nullptr;
    }
}
resource_world::Profile resource_parameter_profile(){resource_world::Profile result;result.layouts.push_back({});return result;}
vm::ResourceTemplates resource_parameter_metadata(std::int16_t maximum,bool release){
    std::vector<std::byte> bytes(32+129*24);
    const auto write=[&](unsigned at,auto value){std::memcpy(bytes.data()+at,&value,sizeof value);};
    write(0,3u);write(4,129u);write(16,32u);
    for(unsigned i=0;i<129;++i){write(32+24*i,(release?0x40000u:0u)|(i==2?0x20000u:0u));write(32+24*i+8,maximum);write(32+24*i+18,std::uint16_t(31+i));}
    vm::ResourceTemplates result;check(result.load(bytes));return result;
}
struct ResourceParameterFixture {
    std::shared_ptr<resource_world::Session> session=std::make_shared<resource_world::Session>();
    resource_world::World world{resource_parameter_profile(),session};vm::SceneResources resources;vm::ResourceTemplates templates;
    resource_world::ResourceModels models;resource_world::ResourceFrames frames;
    resource_world::WorldInventory inventory;
    std::shared_ptr<const resource_world::ResourceStaticAssets> assets=std::make_shared<resource_world::ResourceStaticAssets>();
    resource_world::ResourceFactory factory;vm::ScriptResourceParameters commands;
    std::shared_ptr<resource_world::ResourceModel> model;
    ResourceParameterFixture(std::int16_t maximum,bool release,unsigned metadata,unsigned owner,unsigned trial):
        templates(resource_parameter_metadata(maximum,release)),frames(world,resources,models,nullptr,{},&templates),
        inventory(world,resources,templates,frames),factory(models,frames,templates,assets),commands(world,resources,templates,models,factory,inventory){
        world.mode=std::uint8_t(trial%4);session->gameplay_flags=std::uint16_t((trial/4)%4);
        for(unsigned i=0;i<4;++i){auto actor=std::make_unique<resource_world::Actor>();actor->active=true;actor->slot=std::uint8_t(i);actor->character=3;
            actor->inventory.carried={13,14,14,15};actor->inventory.storage[0]=13;actor->selected_resource=13;actor->secondary_equipped_resource=14;actor->resource_action=99;
            check(bool(world.spawn_primary(i,std::move(actor)).id));}
        for(unsigned i=13;i<16;++i){vm::SceneDescriptor d;d.active=(i==14&&metadata==2)?0:128;d.kind=std::uint8_t(i);d.room=7;
            d.instance_index=std::uint8_t(i==13&&metadata?14:i);d.attachment_id=std::uint16_t(31+i-13);d.authored_id=std::uint16_t(700+i);
            d.template_index=i==14&&metadata==3?std::uint8_t(255):std::uint8_t(i-13);d.parameter=-17;d.flags=0x20001;d.ownership_tag=std::uint16_t(owner+1);
            d.position={float(i),-float(i),float(i*3)};d.saved_position={-1,2,-3};d.yaw=123;d.tilt=456;d.saved_yaw=789;
            d.claim_tag=21;d.shape_profile=-3;d.orientation_variant=-4;check(bool(resources.load(i,d)));}
        if(trial&1){const auto created=models.create();check(created.status==resource_world::ResourceModelStatus::completed);model=created.model;
            const auto id=*resources.slot(metadata?14:13);auto d=*resources.get(id);d.primary=model;check(resources.replace(id,d)==vm::SceneStatus::completed);}
    }
    static void descriptor_bytes(std::uint8_t* out,const vm::SceneDescriptor& d){
        std::memset(out,0,60);out[0]=d.active;out[1]=d.room;out[2]=d.instance_index;out[3]=d.kind;
        const auto write=[&](unsigned at,auto value){std::memcpy(out+at,&value,sizeof value);};
        write(4,d.authored_id);write(6,d.attachment_id);write(8,d.position);write(20,d.tilt);write(22,d.yaw);write(24,d.flags);
        write(28,d.primary?0x500000u:0u);write(32,d.secondary?0x510000u:0u);write(36,d.parameter);write(40,d.ownership_tag);
        out[42]=d.claim_tag;out[43]=d.template_index;out[44]=std::bit_cast<std::uint8_t>(d.shape_profile);out[45]=std::bit_cast<std::uint8_t>(d.orientation_variant);
        write(46,d.saved_yaw);write(48,d.saved_position);
    }
    void export_original(std::vector<std::uint8_t>& ram){
        for(unsigned i=0;i<256;++i)descriptor_bytes(ram.data()+0x3c5630+60*i,*resources.get(*resources.slot(i)));
        fixture_write(ram.data(),0x743128,std::uint32_t(resources.active_count()));
        for(unsigned i=0;i<129;++i)std::memcpy(ram.data()+0x74bb50+24*i,templates.state().templates[i].encoded.data(),24);
        ram[0x3243f2]=world.mode;fixture_write(ram.data(),0x4bae96,session->gameplay_flags);
        for(unsigned i=0;i<4;++i){const auto actor=world.primary(i);const auto at=0x4a5c30+0x10e0*i;
            ram[at]=128;ram[at+0xb98]=actor->character;ram[at+0xc7c]=actor->selected_resource;ram[at+0xc7d]=actor->secondary_equipped_resource;
            std::memcpy(ram.data()+at+0xc84,actor->inventory.carried.data(),4);std::memcpy(ram.data()+at+0xc88,actor->inventory.storage.data(),32);fixture_write(ram.data(),at+0xca8,actor->resource_action);}
        std::memset(ram.data()+0x500000,0xa5,0x250);fixture_write(ram.data(),0x50001c,0u);fixture_write(ram.data(),0x500020,0u);
        fixture_write(ram.data(),0x3b5700,std::int16_t(models.available()));fixture_write(ram.data(),0x3b5708,model?0x500000u:0u);fixture_write(ram.data(),0x3b5710,model?0x500000u:0u);
    }
    void compare_original(const std::vector<std::uint8_t>& ram){
        for(unsigned i=0;i<256;++i){std::array<std::uint8_t,60> expected;descriptor_bytes(expected.data(),*resources.get(*resources.slot(i)));check(std::memcmp(expected.data(),ram.data()+0x3c5630+60*i,60)==0);}
        check(resources.active_count()==fixture_read<std::uint32_t>(ram.data(),0x743128));check(models.available()==fixture_read<std::uint16_t>(ram.data(),0x3b5700));
        for(unsigned i=0;i<4;++i){const auto actor=world.primary(i);const auto at=0x4a5c30+0x10e0*i;
            check(std::memcmp(actor->inventory.carried.data(),ram.data()+at+0xc84,4)==0);check(std::memcmp(actor->inventory.storage.data(),ram.data()+at+0xc88,32)==0);
            check(actor->selected_resource==ram[at+0xc7c]);check(actor->secondary_equipped_resource==ram[at+0xc7d]);check(actor->resource_action==fixture_read<std::uint16_t>(ram.data(),at+0xca8));}
        if(model){const bool retired=models.available()==64;check(model->current()!=retired);
            if(retired){check(fixture_read<std::uint32_t>(ram.data(),0x3b5710)==0);check(fixture_read<std::uint32_t>(ram.data(),0x3b5708)==0);
                check(fixture_read<std::uint32_t>(ram.data(),0x3b5720+63*4)==0x500000);for(unsigned i=0;i<0x250;++i)check(ram[0x500000+i]==0);++resource_parameter_releases;}}
    }
};
void script_resource_parameter_vm_tests(){
    std::vector<std::uint8_t> ram(0x900000);install_original_tables(ram);vm::FlagState flags;
    constexpr std::array<std::int16_t,8> values{INT16_MIN,-1,0,1,9,10,11,INT16_MAX};
    resource_parameter_original_active=true;
    for(bool offline:{false,true})for(unsigned metadata=0;metadata<4;++metadata)for(bool release:{false,true})for(unsigned trial=0;trial<64;++trial)for(unsigned owner=0;owner<4;++owner){
        assertion_context="170 offline="+std::to_string(offline)+" metadata="+std::to_string(metadata)+" release="+std::to_string(release)+" trial="+std::to_string(trial)+" owner="+std::to_string(owner);
        ResourceParameterFixture fixture(values[trial/8],release,metadata,owner,trial);fixture.export_original(ram);
        const auto resource=trial%16==15?std::uint16_t(0xffff):std::uint16_t(31);
        const auto quantity=values[trial%8];const unsigned category=trial%5,relation=(trial/5)%4;
        fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);
        std::vector<std::byte> bytes;emit(bytes,0x170,{0xbeef0000u|resource,0xabcd0000u|std::uint16_t(quantity)});emit(bytes,0x110,{0,77});emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        vm::Providers providers;providers.flags=providers.canonical_flags=&flags;providers.world=&fixture.world;providers.resource_parameters=&fixture.commands;providers.scene_resources=&fixture.resources;providers.resource_templates=&fixture.templates;
        const auto result=offline?native.tick_offline_channel(0,{}, {category,relation,0},providers):native.tick(0,{},providers);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);fixture.compare_original(ram);++resource_parameter_dispatches;
    }
    // Exact early gate executes with no resource provider or model pool.
    for(bool offline:{false,true}){
        ResourceParameterFixture fixture(100,true,0,0,0);fixture.session->gameplay_flags=1;fixture.export_original(ram);
        check(fixture.models.close()==resource_world::ResourceModelStatus::completed);
        std::vector<std::byte> bytes;emit(bytes,0x170,{31,0});emit(bytes,0x110,{0,77});emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        vm::Providers providers;providers.world=&fixture.world;providers.flags=providers.canonical_flags=&flags;
        const auto result=offline?native.tick_offline_channel(0,{}, {},providers):native.tick(0,{},providers);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);check(native.counters()[0]==77);++resource_parameter_dispatches;
    }
    resource_parameter_original_active=false;
    for(bool offline:{false,true}){
        ResourceParameterFixture fixture(100,true,0,0,1);vm::Providers providers;providers.flags=providers.canonical_flags=&flags;providers.world=&fixture.world;
        const auto refuse=[&](vm::Providers supplied){std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,0x170,{31,0});emit(bytes,0xa);vm::Interpreter native;
            check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary))==vm::Status::completed);
            const auto result=offline?native.tick_offline_channel(0,{}, {},supplied):native.tick(0,{},supplied);check(result.status==vm::Status::provider_unavailable&&native.counters()[0]==0);++resource_parameter_refusals;};
        refuse(providers);providers.resource_parameters=&fixture.commands;vm::SceneResources foreign;providers.scene_resources=&foreign;refuse(providers);
        providers.scene_resources=&fixture.resources;auto d=*fixture.resources.get(*fixture.resources.slot(13));d.ownership_tag=5;check(fixture.resources.replace(*fixture.resources.slot(13),d)==vm::SceneStatus::completed);refuse(providers);
        d.ownership_tag=1;d.template_index=129;check(fixture.resources.replace(*fixture.resources.slot(13),d)==vm::SceneStatus::completed);refuse(providers);
    }
    assertion_context.clear();
}
}
