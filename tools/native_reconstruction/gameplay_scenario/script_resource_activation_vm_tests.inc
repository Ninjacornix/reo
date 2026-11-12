#include "game/native/gameplay_scenario/script_resource_activation.hpp"
namespace {
std::size_t resource_activation_dispatches{},resource_activation_constructed{},resource_activation_refusals{};
constexpr std::uint32_t activation_pool=0x3f4010,activation_stride=0x250;
void call_activation_pool_reset(std::vector<std::uint8_t>& ram){
    R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x7f0000);SET_GPR_U32(&context,31,0xdeadbeef);
    o2_00590BE0_0x590be0(ram.data(),&context,&runtime);check(context.pc==0xdeadbeef);
}
struct ResourceActivationFixture {
    std::shared_ptr<resource_world::Session> session=std::make_shared<resource_world::Session>();
    resource_world::World world{resource_parameter_profile(),session};vm::SceneResources resources;vm::ResourceTemplates templates;
    resource_world::ResourceModels models;resource_world::ResourceFrames frames{world,resources,models,nullptr,{},&templates};
    std::shared_ptr<const resource_world::ResourceStaticAssets> assets=std::make_shared<resource_world::ResourceStaticAssets>();
    resource_world::ResourceFactory factory{models,frames,templates,assets};vm::ScriptResourceActivation activation{world,resources,templates,models,factory};
    explicit ResourceActivationFixture(unsigned trial,unsigned clock){
        world.mode=1;world.room=(trial&4)?7:263;session->clock_mode=std::uint8_t(clock);
        const unsigned population=(trial&64)?64u:(trial&16)?1u:0u;
        for(unsigned i=0;i<population;++i)check(models.create(resource_world::ResourceModelPlacement::front).status==resource_world::ResourceModelStatus::completed);
        vm::SceneDescriptor descriptor;descriptor.authored_id=31;descriptor.active=(trial&1)?128:0;descriptor.kind=(trial&2)?255:0;
        descriptor.room=7;descriptor.ownership_tag=(trial&8)?0:1;descriptor.instance_index=std::uint8_t(trial%3==0?14:13);
        descriptor.attachment_id=std::uint16_t(trial&1?31:65535);descriptor.flags=0x80200200u;
        descriptor.position={1.25f,-2.5f,3.75f};descriptor.tilt=0x8123;descriptor.yaw=0x7fed;descriptor.parameter=-123;
        descriptor.saved_position={-1,2,-3};descriptor.saved_yaw=0xffff;descriptor.template_index=255;
        if(trial&16)descriptor.primary=models.retain(models.head());
        if(trial&32)descriptor.secondary=std::make_shared<vm::SceneAttachment>();
        check(bool(resources.load(13,descriptor)));
        // A later active duplicate must never replace the first authored match.
        descriptor.active=128;descriptor.kind=1;descriptor.flags=0x7ffffffeu;descriptor.primary.reset();descriptor.secondary.reset();
        check(bool(resources.load(14,descriptor)));
    }
    std::uint32_t address(const resource_world::ResourceModelId& id)const{
        const auto slot=models.physical_slot(id);return slot?activation_pool+activation_stride**slot:0;
    }
    std::uint32_t attachment(const std::shared_ptr<vm::SceneAttachment>& value)const{
        const auto model=std::dynamic_pointer_cast<resource_world::ResourceModel>(value);
        return model?address(models.identity_of(*model)):value?0x510000u:0u;
    }
    void descriptor_bytes(std::uint8_t* bytes,const vm::SceneDescriptor& value)const{
        ResourceParameterFixture::descriptor_bytes(bytes,value);fixture_write(bytes,28,attachment(value.primary));fixture_write(bytes,32,attachment(value.secondary));
    }
    void model_bytes(std::uint8_t* bytes,const resource_world::ResourceModelId& id)const{
        std::memset(bytes,0,activation_stride);const auto model=models.retain(id);if(!model)return;
        const auto write=[&](unsigned at,auto value){std::memcpy(bytes+at,&value,sizeof value);};
        bytes[0]=model->active?1:0;bytes[1]=model->visible?1:0;bytes[2]=model->category;bytes[6]=model->physical_slot;
        write(0xc,model->use_delay);write(0x10,model->program.elapsed);
        if(model->work){check(bool(std::dynamic_pointer_cast<resource_world::DelayedResourceWork>(model->work)));write(0x14,0x593550u);write(0x18,0x371ef0u);}
        write(0x1c,address(models.previous(id)));write(0x20,address(models.next(id)));
        std::memcpy(bytes+0x30,model->part_enabled.data(),6);write(0x36,model->content_id);std::memcpy(bytes+0x40,model->parts.data(),6*64);
        write(0x1c0,model->pose);write(0x200,model->position);write(0x20c,model->use_vector);std::memcpy(bytes+0x21c,model->angles.data(),6);
        std::memcpy(bytes+0x224,model->use_parameters.data(),8);write(0x22c,model->axis_scale);write(0x238,model->draw_tag);write(0x23c,model->flags);
        bytes[0x240]=model->resource_slot;bytes[0x241]=model->draw_layer;write(0x242,model->asset_index);
    }
    void export_original(std::vector<std::uint8_t>& ram){
        call_activation_pool_reset(ram);
        for(unsigned i=0;i<256;++i)descriptor_bytes(ram.data()+0x3c5630+60*i,*resources.get(*resources.slot(i)));
        fixture_write(ram.data(),0x3b5700,std::int16_t(models.available()));fixture_write(ram.data(),0x3b5708,address(models.head()));fixture_write(ram.data(),0x3b5710,address(models.tail()));
        for(auto id=models.head();id;id=models.next(id))model_bytes(ram.data()+address(id),id);
        fixture_write(ram.data(),0x3243dc,world.room);ram[0x3243cc]=session->clock_mode;
        // A real cold ResourceStaticAssets owner matches the original empty
        // signed cache. Complete372490 executes, including its miss result.
        fixture_write(ram.data(),0x3dba50,std::int16_t(0));
    }
    void compare_original(const std::vector<std::uint8_t>& ram){
        for(unsigned i=0;i<256;++i){std::array<std::uint8_t,60> expected;descriptor_bytes(expected.data(),*resources.get(*resources.slot(i)));check(std::memcmp(expected.data(),ram.data()+0x3c5630+60*i,60)==0);}
        check(models.available()==fixture_read<std::uint16_t>(ram.data(),0x3b5700));
        check(address(models.head())==fixture_read<std::uint32_t>(ram.data(),0x3b5708));check(address(models.tail())==fixture_read<std::uint32_t>(ram.data(),0x3b5710));
        for(auto id=models.head();id;id=models.next(id)){std::array<std::uint8_t,activation_stride> expected;model_bytes(expected.data(),id);
            check(std::memcmp(expected.data(),ram.data()+address(id),expected.size())==0);if(models.retain(id)->work)++resource_activation_constructed;}
    }
};
void script_resource_activation_vm_tests(){
    std::vector<std::uint8_t> ram(0x900000);install_original_tables(ram);vm::FlagState flags;
    const std::array<float,16> identity{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};std::memcpy(ram.data()+0x294e00,identity.data(),64);
    constexpr std::array<std::int16_t,8> delays{INT16_MIN,-32767,-1,0,1,3,80,INT16_MAX};
    constexpr std::array<std::int16_t,8> ids{31,31,31,31,0,-1,INT16_MIN,32767};
    for(bool offline:{false,true})for(unsigned clock:{0u,1u,2u,255u})for(unsigned di=0;di<8;++di)for(unsigned trial=0;trial<128;++trial){
        assertion_context="174 offline="+std::to_string(offline)+" clock="+std::to_string(clock)+" delay="+std::to_string(delays[di])+" trial="+std::to_string(trial);
        ResourceActivationFixture fixture(trial,clock);fixture.export_original(ram);
        const auto authored=ids[(trial/8+di)%8];const unsigned category=trial%5,relation=(trial/5)%4;
        fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);
        std::vector<std::byte> bytes;emit(bytes,0x174,{0xabcd0000u|std::uint16_t(authored),0xbeef0000u|std::uint16_t(delays[di])});emit(bytes,0x110,{0,77});emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        vm::Providers providers;providers.flags=providers.canonical_flags=&flags;
        if(authored>0){providers.world=&fixture.world;providers.resource_activation=&fixture.activation;providers.scene_resources=&fixture.resources;providers.resource_templates=&fixture.templates;}
        const auto result=offline?native.tick_offline_channel(0,{}, {category,relation,0},providers):native.tick(0,{},providers);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);fixture.compare_original(ram);++resource_activation_dispatches;
    }
    for(bool offline:{false,true}){
        ResourceActivationFixture fixture(15,0);vm::Providers providers;providers.flags=providers.canonical_flags=&flags;providers.world=&fixture.world;
        const auto refuse=[&](vm::Providers supplied){std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,0x174,{31,80});emit(bytes,0xa);vm::Interpreter native;
            check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary))==vm::Status::completed);
            const auto result=offline?native.tick_offline_channel(0,{}, {},supplied):native.tick(0,{},supplied);
            check(result.status==vm::Status::provider_unavailable&&native.counters()[0]==0&&fixture.models.available()==64);++resource_activation_refusals;};
        refuse(providers);providers.resource_activation=&fixture.activation;
        vm::SceneResources foreign;providers.scene_resources=&foreign;refuse(providers);providers.scene_resources=&fixture.resources;
        vm::ResourceTemplates foreign_templates;providers.resource_templates=&foreign_templates;refuse(providers);providers.resource_templates=&fixture.templates;
        check(fixture.models.close()==resource_world::ResourceModelStatus::completed);refuse(providers);
    }
    assertion_context.clear();
}
}
