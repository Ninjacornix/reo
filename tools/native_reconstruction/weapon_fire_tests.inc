#include "game/native/gameplay_world/weapon_fire.hpp"
unsigned weapon_fire_cases{},weapon_fire_callbacks{},weapon_fire_refusals{};
namespace fire_fixture {
using namespace depletion_fixture;
struct Event {
    unsigned kind{},argument{};
    std::optional<m::Matrix> basis;
    std::optional<m::Vector> position;
};
struct Capture {
    std::vector<Event> events;
    std::uint8_t* memory{};g::Actor* actor{};unsigned raw_actor{};
    unsigned mutation_at{},mutation_action{};
    void append(Event event){
        events.push_back(std::move(event));
        if(mutation_at&&events.size()==mutation_at){
            if(memory)put(memory,raw_actor+0xca8,std::uint16_t(mutation_action));
            else actor->resource_action=std::uint16_t(mutation_action);
        }
    }
};
Capture* original{};
struct Ui final:g::ResourceHealthUi {
    g::World& world;Capture& capture;
    Ui(g::World& w,Capture& c):world(w),capture(c){}
    bool bound_to(const g::World& w)const noexcept override{return &world==&w;}
    bool feedback(const g::actors::EntityId&,std::uint8_t selector)noexcept override{capture.append({0,selector,{},{}});return true;}
    bool close()noexcept override{std::terminate();}
    bool message(const g::ResourceHealthNotice&)noexcept override{std::terminate();}
};
struct Effects final:g::WeaponEffects {
    g::World& world;Capture& capture;
    Effects(g::World& w,Capture& c):world(w),capture(c){}
    bool bound_to(const g::World& w)const noexcept override{return &world==&w;}
    bool pose_work(const g::actors::EntityId&,const m::Matrix& basis,m::Vector point,std::uint32_t resource)override{capture.append({1,resource,basis,point});return true;}
    bool transient_light(const g::actors::EntityId&,m::Vector point)override{capture.append({2,0,{},point});return true;}
    bool contact_style(const g::actors::EntityId&,const m::Matrix& basis,m::Vector point,std::uint8_t style)override{capture.append({3,style,basis,point});return true;}
    bool flight(const g::actors::EntityId&,const m::Matrix& basis,std::uint32_t style)override{capture.append({4,style,basis,{}});return true;}
};
}
bool weapon_fire_port(std::uint8_t* memory,R5900Context* context){
    using namespace fire_fixture;if(!original)return false;
    Event event;event.argument=GPR_U32(context,7);
    switch(context->pc){
    case 0x665ca0:event.kind=0;event.argument=GPR_U32(context,5);break;
    case 0x5823e0:event.kind=1;event.basis=get<m::Matrix>(memory,GPR_U32(context,5));event.position=get<m::Vector>(memory,GPR_U32(context,6));break;
    case 0x6b24f0:event.kind=2;event.argument=0;event.position=get<m::Vector>(memory,GPR_U32(context,5));break;
    case 0x5dd270:event.kind=3;event.basis=get<m::Matrix>(memory,GPR_U32(context,5));event.position=get<m::Vector>(memory,GPR_U32(context,6));break;
    case 0x58e6d0:event.kind=4;event.argument=GPR_U32(context,6);event.basis=get<m::Matrix>(memory,GPR_U32(context,5));break;
    default:return false;
    }
    check(GPR_U32(context,4)==original->raw_actor);original->append(std::move(event));return true;
}
void compare_weapon_fire(consumption_fixture::Consuming& f,reo::native::gameplay_world::animation_events::BasicAudio& audio,
    std::shared_ptr<const reo::native::animation::WeaponProgramBank> cleared){
    using namespace fire_fixture;
    Capture source,native;source.memory=f.q.memory;source.raw_actor=0x4a5c30;
    const auto actor=f.q.world.primary(0);native.actor=actor.get();
    Ui ui(f.q.world,native);Effects effects(f.q.world,native);
    g::WorldResourcePrograms programs(f.q.world,f.q.resources);
    g::ResourceWeaponFire fire(f.q.world,f.q.resources,f.q.templates,audio,programs,&ui,&effects);
    const auto [made,raw_model]=f.q.create(42,7);check(made.status==g::ResourceModelStatus::completed);
    for(unsigned n=0;n<32768;++n){
        auto pose=m::identity();m::compose_euler_radians(pose,{float(int(n%31)-15)*.1f,float(int(n%29)-14)*.07f,float(int(n%23)-11)*.11f});
        for(unsigned i=0;i<3;++i)for(unsigned j=0;j<3;++j)pose[i][j]*=float(1+(n+i)%3);
        pose[3]={100,-50,70,1};made.model->pose=pose;made.model->position={float(int(n%99)-49),-20,123};
        put(f.q.memory,raw_model+0x1c0,pose);put(f.q.memory,raw_model+0x200,made.model->position);
        s::SceneDescriptor item;item.active=1;item.instance_index=3;item.ownership_tag=1;
        item.template_index=0;item.parameter=std::int16_t(n%3);item.attachment_id=42;item.primary=made.model;
        sync(f.q,3,item);put(f.q.memory,address(3)+0x1c,raw_model);
        actor->category=0;actor->slot=0;actor->character=std::uint8_t((n/64)%8);
        actor->primary=std::uint8_t(n%3==0?5:n%3==1?2:0);actor->secondary=std::uint8_t((n/3)%3==0?2:(n/3)%3==1?12:0);
        actor->subphase=std::uint8_t((n/9)%2);actor->resource_action=std::uint16_t(n%64);actor->selected_resource=3;
        actor->weapon_programs=cleared;actor->motion_style=0;inventory_fixture::export_actor(f.q.memory,*actor);
        f.q.memory[0x4a5c32]=0;f.q.memory[0x4a5c33]=0;f.q.memory[0x4a5c38]=actor->primary;
        f.q.memory[0x4a5c39]=actor->secondary;f.q.memory[0x4a5c3b]=actor->subphase;f.q.memory[0x4a5c30+0xb99]=0;
        std::fill_n(f.q.memory+0x749180,2048,0);made.model->program={};f.q.memory[raw_model+9]=0;
        source.events.clear();native.events.clear();
        source.mutation_at=native.mutation_at=n%5==0?1u+(n/5)%5:0;
        source.mutation_action=native.mutation_action=(n/7)%64;
        original=&source;call(f.q.memory,0x65e880,{0x4a5c30,0xabcd0003});original=nullptr;
        if(!fire.fire_resource(f.q.world.identity(0),0xabcd0003))throw std::runtime_error("Firing unavailable n="+std::to_string(n));
        if(source.events.size()!=native.events.size())throw std::runtime_error("Firing event count n="+std::to_string(n));
        for(unsigned i=0;i<source.events.size();++i){const auto& a=source.events[i];const auto& b=native.events[i];
            check(a.kind==b.kind&&a.argument==b.argument&&bool(a.basis)==bool(b.basis)&&bool(a.position)==bool(b.position));
            if(a.basis&&std::memcmp(&*a.basis,&*b.basis,sizeof(m::Matrix)))throw std::runtime_error("Firing matrix n="+std::to_string(n)+" event="+std::to_string(i));
            if(a.position&&std::memcmp(&*a.position,&*b.position,sizeof(m::Vector)))throw std::runtime_error("Firing position n="+std::to_string(n)+" event="+std::to_string(i));
            ++weapon_fire_callbacks;
        }
        check(actor->resource_action==get<std::uint16_t>(f.q.memory,0x4a5c30+0xca8));
        check(made.model->program.phase==f.q.memory[raw_model+9]);++weapon_fire_cases;
    }
    actor->resource_action=1;
    g::ResourceWeaponFire missing(f.q.world,f.q.resources,f.q.templates,audio,programs,nullptr,nullptr);
    check(!missing.fire(f.q.world.identity(0),3));++weapon_fire_refusals;
    check(!fire.fire({},3));++weapon_fire_refusals;
}
