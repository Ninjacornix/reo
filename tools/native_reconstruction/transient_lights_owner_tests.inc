#include "game/native/gameplay_update/update.hpp"
#include "game/native/gameplay_world/transient_weapon_effects.hpp"
unsigned transient_owner_cases{},transient_owner_frames{},transient_owner_refusals{};
bool transient_owner_mode{},transient_original_task{},transient_deny_task{};
constexpr unsigned transient_task_at=0x120000,transient_actor_at=0x10000,transient_point_at=0x11000;
bool transient_owner_port(std::uint8_t* memory,R5900Context* context){
    const auto in_pool=[](unsigned address,unsigned offset){return(address>=0x747540+offset&&address<0x747540+64*56&&(address-0x747540-offset)%56==0)||(address>=0x748350+offset&&address<0x748350+64*56&&(address-0x748350-offset)%56==0);};
    switch(context->pc){
    case 0x573890:check(GPR_U32(context,4)==0&&GPR_U32(context,5)==0x5d83d0);check(!transient_original_task);if(transient_deny_task)SET_GPR_U32(context,2,0);else{std::memset(memory+transient_task_at,0,256);transient_original_task=true;SET_GPR_U32(context,2,transient_task_at);}return true;
    case 0x573740:check(transient_original_task&&GPR_U32(context,4)==transient_task_at);transient_original_task=false;return true;
    case 0x107c68:{const auto dst=GPR_U32(context,4),bytes=GPR_U32(context,6);check(in_pool(dst,0)&&bytes==56&&GPR_U32(context,5)==0);std::memset(memory+dst,0,bytes);SET_GPR_U32(context,2,dst);return true;}
    case 0x107ab0:{const auto dst=GPR_U32(context,4),src=GPR_U32(context,5),bytes=GPR_U32(context,6);check(in_pool(dst,4)&&bytes==52&&(src==0x100000||(src>=0x1e00000&&src<=0x2000000-bytes)));std::memcpy(memory+dst,memory+src,bytes);SET_GPR_U32(context,2,dst);return true;}
    default:return false;
    }
}
void call_transient_owner(std::uint8_t* memory,unsigned pc,std::array<unsigned,3> args={}){
    R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);
    for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&context,4+i,args[i]);
    original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
}
struct TransientNotifications final:reo::native::gameplay_scenario::FlagNotifications {
    bool changed(const reo::native::gameplay_scenario::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const reo::native::gameplay_scenario::StridedFlagChange&)noexcept override{std::terminate();}
};
struct TransientIdleTask final:reo::native::gameplay_tasks::Task {
    void update(reo::native::gameplay_tasks::Scheduler&,const reo::native::gameplay_tasks::Handle&)noexcept override{}
};
struct TransientCloseTask final:reo::native::gameplay_tasks::Task {
    l::TransientLights& owner;l::TransientStatus result{l::TransientStatus::unavailable};
    explicit TransientCloseTask(l::TransientLights& value):owner(value){}
    void update(reo::native::gameplay_tasks::Scheduler& tasks,const reo::native::gameplay_tasks::Handle& self)noexcept override{result=owner.close();(void)tasks.erase(self);}
};
void compare_transient_owner(std::uint8_t* memory){
    namespace w=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;
    namespace s=reo::native::gameplay_scenario;namespace t=reo::native::gameplay_tasks;
    w::Profile profile;profile.layouts.push_back({});w::World world(profile,std::make_shared<w::Session>());
    TransientNotifications notifications;u::Owner update(world,notifications);s::Lighting lights;l::TransientLights owner(update,lights);
    const auto id=world.spawn_primary(0,std::make_unique<w::Actor>()).id;check(bool(id));const auto actor=world.resolve(id);
    transient_owner_mode=true;
    const auto compare=[&]{
        check(lights.primary_count()==memory[0x747538]&&lights.auxiliary_count()==memory[0x748340]);
        for(unsigned i=0;i<64;++i){check(std::memcmp(&lights.primary()[i],memory+0x747540+56*i,sizeof(s::NativeLight))==0);check(std::memcmp(&lights.auxiliary()[i],memory+0x748350+56*i,sizeof(s::NativeLight))==0);}
    };
    for(unsigned primary_count:{0u,1u,31u,63u,64u})for(unsigned auxiliary_count:{0u,1u,31u,63u,64u})for(unsigned tag:{0u,7u,255u}){
        lights.reset_work();std::memset(memory+0x747540,0,64*56);std::memset(memory+0x748350,0,64*56);memory[0x747538]=memory[0x748340]=0;
        const auto definition=l::transient_definition({-1,2,-3});put(memory,0x100000,definition);
        for(unsigned i=0;i<primary_count;++i){call_transient_owner(memory,0x6b3090,{0x100000,17,1});check(bool(lights.allocate(&definition,17,1)));}
        for(unsigned i=0;i<auxiliary_count;++i){call_transient_owner(memory,0x6b2cc0,{0x100000,19,0});check(bool(lights.allocate_auxiliary(&definition,19)));}
        compare();actor->surface_material=std::uint8_t(tag);memory[transient_actor_at+0x175]=std::uint8_t(tag);
        const std::array<float,3> position{float(primary_count)-16,50,-float(auxiliary_count)};put(memory,transient_point_at,position);
        transient_original_task=false;transient_deny_task=false;call_transient_owner(memory,0x6b24f0,{transient_actor_at,transient_point_at,0});
        const auto made=owner.create(id,position);check(made.status==l::TransientStatus::completed&&transient_original_task&&update.linked().contains(made.task));
        check(made.lights==std::array<bool,2>{primary_count<64,auxiliary_count<64});compare();
        auto retained=owner.snapshot(made.task);check(retained&&retained->state.phase==0);
        unsigned frames{};
        while(transient_original_task){
            check(++frames<=4);call_transient_owner(memory,0x5d83d0,{transient_task_at});
            check(update.linked().run(t::Pass::update).status==t::Status::completed);compare();
            const auto snapshot=owner.snapshot(made.task);check(bool(snapshot)==transient_original_task);
            if(snapshot){check(snapshot->state.phase==memory[transient_task_at+8]&&snapshot->state.remaining[0]==get<std::int16_t>(memory,transient_task_at+12)&&snapshot->state.remaining[1]==get<std::int16_t>(memory,transient_task_at+14));check(bool(snapshot->lights[0])==bool(get<unsigned>(memory,transient_task_at+0x28))&&bool(snapshot->lights[1])==bool(get<unsigned>(memory,transient_task_at+0x24)));}
            ++transient_owner_frames;
        }
        check(update.linked().size()==0&&owner.failure()==l::TransientStatus::completed);
        if(retained->lights[0])check(retained->lights[0]->active);
        if(retained->lights[1])check(retained->lights[1]->active);
        ++transient_owner_cases;
    }
    lights.reset_work();w::TransientWeaponEffects bridge(update,lights,owner);check(bridge.bound_to(world));
    check(bridge.transient_light(id,{1,2,3})&&update.linked().size()==1&&lights.primary_count()==1&&lights.auxiliary_count()==1);
    check(!bridge.pose_work(id,reo::native::transform_math::identity(),{},3)&&!bridge.contact_style(id,reo::native::transform_math::identity(),{},0)&&!bridge.flight(id,reo::native::transform_math::identity(),0));++transient_owner_refusals;
    for(unsigned i=0;i<4;++i)check(update.linked().run(t::Pass::update).status==t::Status::completed);
    check(update.linked().size()==0&&lights.primary_count()==0&&lights.auxiliary_count()==0);++transient_owner_cases;
    const auto closer=std::make_shared<TransientCloseTask>(owner);check(update.linked().create(closer).status==t::Status::completed);
    check(update.linked().run(t::Pass::update).status==t::Status::completed&&closer->result==l::TransientStatus::busy&&bridge.bound_to(world));++transient_owner_refusals;
    s::Lighting other_lights;bool foreign_refused{};try{w::TransientWeaponEffects foreign(update,other_lights,owner);}catch(const std::invalid_argument&){foreign_refused=true;}check(foreign_refused);++transient_owner_refusals;
    lights.reset_work();std::memset(memory+0x747540,0,64*56);std::memset(memory+0x748350,0,64*56);memory[0x747538]=memory[0x748340]=0;
    for(unsigned i=0;i<t::Scheduler::capacity;++i)check(update.linked().create(std::make_shared<TransientIdleTask>()).status==t::Status::completed);
    transient_deny_task=true;call_transient_owner(memory,0x6b24f0,{transient_actor_at,transient_point_at,0});check(!transient_original_task&&owner.create(id,{1,2,3}).status==l::TransientStatus::task_full&&bridge.transient_light(id,{1,2,3}));compare();++transient_owner_refusals;
    check(update.linked().clear()==t::Status::completed);transient_deny_task=false;
    check(owner.create({},{}).status==l::TransientStatus::unavailable);++transient_owner_refusals;
    auto made=owner.create(id,{1,2,3});check(made.status==l::TransientStatus::completed);
    check(world.retire_primary(0)==w::actors::EntityStatus::completed);
    for(unsigned i=0;i<4;++i)check(update.linked().run(t::Pass::update).status==t::Status::completed);
    check(!owner.snapshot(made.task)&&lights.primary_count()==0&&lights.auxiliary_count()==0);++transient_owner_cases;
    const auto next=world.spawn_primary(0,std::make_unique<w::Actor>()).id;made=owner.create(next,{});check(made.status==l::TransientStatus::completed);
    lights.reset_work();const auto new_primary=lights.allocate(nullptr,5,0);const auto new_auxiliary=lights.allocate_auxiliary(nullptr,7);check(new_primary&&new_auxiliary);
    check(update.linked().run(t::Pass::update).status==t::Status::completed&&owner.failure()==l::TransientStatus::unavailable);
    check(lights.primary_count()==1&&lights.auxiliary_count()==1&&lights.light(*new_auxiliary)->tag==7&&!owner.snapshot(made.task));++transient_owner_refusals;
    check(owner.create(next,{}).status==l::TransientStatus::unavailable);check(owner.close()==l::TransientStatus::completed);check(owner.create(next,{}).status==l::TransientStatus::closed);++transient_owner_refusals;
    transient_owner_mode=false;check(update.close()==u::Status::completed);
}
