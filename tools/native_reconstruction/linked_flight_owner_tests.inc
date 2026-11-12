#include "game/native/gameplay_world/linked_flight_effects.hpp"
#include <filesystem>
namespace linked_owner_fixture {
namespace c=reo::native::gameplay_collision;namespace r=reo::native::gameplay_contact_world;namespace s=reo::native::gameplay_scenario;namespace l=reo::native::gameplay_lighting;namespace t=reo::native::gameplay_tasks;namespace a=reo::native::gameplay_audio;namespace b=reo::native::audio_banks::v2;
std::vector<std::byte> bytes(const std::filesystem::path& p){std::ifstream f(p,std::ios::binary);const std::vector<char> raw{std::istreambuf_iterator<char>(f),{}};check(!raw.empty());std::vector<std::byte> out(raw.size());std::memcpy(out.data(),raw.data(),raw.size());return out;}
struct Room final:r::RoomInvocation {
    g::actors::EntityStore identities{{1}};r::RoomId id{identities.create(std::make_unique<g::actors::Entity>()).id};
    c::response::Grid walls,floors;c::regions::World regions;c::room_objects::Owner objects;g::CollisionRoom view;
    Room(c::response::Grid w,c::response::Grid f):walls(std::move(w)),floors(std::move(f)),view{walls,floors,regions,objects,{},{},false,false}{}
    r::RoomId identity()const noexcept override{return id;}
    bool current(r::RoomId value)const noexcept override{return value==id&&bool(identities.acquire(value.entity));}
    std::uint16_t room_number()const noexcept override{return 7;}
    const g::CollisionRoom& geometry()const override{return view;}
    std::shared_ptr<s::SceneMatrixPrograms> programs()const override{throw std::runtime_error("Linked floor query does not consume scene matrix programs");}
};
struct Rooms final:r::RoomResources {
    std::shared_ptr<Room> room;bool missing{};
    std::shared_ptr<r::RoomInvocation> retain(std::uint16_t number)override{return !missing&&number==7?room:nullptr;}
};
struct Rig {
    std::shared_ptr<g::Session> session{std::make_shared<g::Session>()};g::World world;g::PoseWorkPool pool;
    s::SceneResources resources;s::ResourceTemplates templates;d::Packets packets;g::ResourcePoseWork poses;
    s::Lighting lighting;l::Pool lights{lighting};t::Scheduler tasks;l::TimedLights timed;
    std::shared_ptr<b::Session> engine{std::make_shared<b::Session>()};a::Owner audio;
    a::SpatialContext spatial;g::PackedActorAudio frontend;g::ResourceLinkedFlightEffects effects;g::LinkedResourceFlight updates;
    g::actors::EntityId parent,work;std::shared_ptr<g::ResourceModel> model;
    Rig(Rooms& rooms,const d::Catalog& catalog,std::span<const std::uint8_t> cue):world({{g::input::Remap{1,2,4}},1,{256,UINT64_MAX}},session),pool(world),poses(world,pool,resources,templates,packets,catalog),timed(world,tasks,lights),audio(engine,session->random),frontend(world,audio,spatial),effects(world,rooms,poses,timed,frontend,packets,catalog),updates(world,pool,resources,effects){
        world.room=7;spatial.world_to_screen=m::identity();parent=world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(parent));world.resolve(parent)->category=0;world.resolve(parent)->slot=0;world.resolve(parent)->surface_material=3;
        check(audio.install(audio.begin_bank(8),cue).status==a::Status::completed);
        model=std::make_shared<g::ResourceModel>(m::identity(),m::identity(),reo::native::animation::Vector{},0);
        s::SceneDescriptor descriptor;descriptor.active=1;descriptor.instance_index=3;descriptor.primary=model;check(bool(resources.load(3,descriptor)));
    }
    void reset(){check(tasks.clear()==t::Status::completed);lighting.reset_work();while(packets.head())check(packets.release(packets.head()));check(pool.reset()==g::PoseWorkStatus::completed);const b::Command stop=b::StopAll{false};check(engine->apply({&stop,1}).status==b::Status::ok);const auto made=pool.allocate();check(made.status==g::PoseWorkStatus::completed);work=made.id;}
};
Rig* reference{};
struct Gains final:b::GainProvider {float gain(unsigned,unsigned,std::uint64_t)noexcept override{return 1;}};
void sync(std::uint8_t* memory,g::Actor& actor){
    actor.primary=memory[work_at+8];actor.visible=memory[work_at+1];actor.auxiliary_status=memory[work_at+0x115];actor.contact.serial=memory[work_at+0x116];actor.pose_work->timer=get<std::int16_t>(memory,work_at+12);actor.pose_work->lifetime=get<std::int16_t>(memory,work_at+18);actor.position=get<g::Position>(memory,work_at+0x38);actor.pose_work->velocity=get<m::Vector>(memory,work_at+0xc0);actor.previous_orientation=get<std::array<std::int16_t,4>>(memory,work_at+0x98);
}
}
unsigned owner_cases{},owner_frames{},owner_light_frames{},owner_pcm_frames{},owner_pcm_signal{},owner_refusals{};
bool linked_owner_port(std::uint8_t* memory,R5900Context* context){
    using namespace linked_owner_fixture;if(!reference)return false;auto& rig=*reference;
    switch(context->pc){
    case 0x616f20:{check(GPR_U32(context,6)==255);const auto hit=rig.effects.floor(get<m::Vector>(memory,GPR_U32(context,4)));check(bool(hit));context->f[0]=hit->height;memory[GPR_U32(context,5)]=hit->type;return true;}
    case 0x5822a0:check(GPR_U32(context,4)==parent_at&&GPR_U32(context,5)==0&&GPR_U32(context,6)==20&&GPR_U32(context,7)==0x6a&&GPR_U32(context,8)==0&&GPR_U32(context,10)==2);check(rig.effects.burst(rig.parent,get<m::Vector>(memory,GPR_U32(context,9))));SET_GPR_U32(context,2,0);return true;
    case 0x6b2760:check(GPR_U32(context,4)==parent_at&&rig.effects.light(rig.parent,get<m::Vector>(memory,GPR_U32(context,5))));return true;
    case 0x1ba5e0:check(GPR_U32(context,4)==work_at&&GPR_U32(context,5)==0x12&&rig.effects.sound(rig.work,0x12));return true;
    case 0x5da2c0:check(GPR_U32(context,4)==work_at&&GPR_U32(context,6)==0&&rig.effects.packet(rig.work,std::uint8_t(GPR_U32(context,5))));SET_GPR_U32(context,2,0);return true;
    default:return false;
    }
}
void linked_owner_checks(std::uint8_t* memory,const d::Catalog& catalog,const std::filesystem::path& directory){
    using namespace linked_owner_fixture;const auto walls=bytes(directory/"owned_flight_walls.bin"),floors=bytes(directory/"owned_flight_floors.bin"),cue=bytes(directory/"owned_flight_cue.bin");Rooms rooms;rooms.room=std::make_shared<Room>(c::response::Grid::import(walls),c::response::Grid::import(floors));check(!rooms.room->floors.triangles().empty());
    const std::span<const std::uint8_t> cue_data{reinterpret_cast<const std::uint8_t*>(cue.data()),cue.size()};Rig native(rooms,catalog,cue_data),source(rooms,catalog,cue_data);Gains gains;
    for(unsigned n=0;n<1024;++n){
        native.reset();source.reset();const auto actor=native.pool.resolve(native.work),source_actor=source.pool.resolve(source.work);check(actor&&source_actor);const auto& triangle=rooms.room->floors.triangles()[n%rooms.room->floors.triangles().size()];
        const g::Position origin{(triangle.vertices[0].x+triangle.vertices[1].x+triangle.vertices[2].x)/3.f,(triangle.vertices[0].y+triangle.vertices[1].y+triangle.vertices[2].y)/3.f+25.f,(triangle.vertices[0].z+triangle.vertices[1].z+triangle.vertices[2].z)/3.f};
        for(auto* rig:{&native,&source}){
            const auto work=rig->pool.resolve(rig->work);work->active=true;work->category=9;work->slot=3;work->contact.related=rig->parent;work->position=origin;work->orientation={0,193,0,0};work->contact.recipient={255,255};work->contact.related_recipient={255,255};work->projectile_contact.normal={.25f,1,-.5f};
            work->pose_work->update_bound=true;work->pose_work->kind=9;work->pose_work->lifetime=-1;work->pose_work->basis=m::identity();rig->model->position={origin.x,origin.y,origin.z};rig->model->use_vector={.5f,7,-1};rig->model->use_parameters={37,-73,97,-101};rig->model->angles={1,65535,32768};rig->model->content_id=std::uint16_t(n%8==0?0x72:n%8==1?0x9b:n%8==2?0x9c:n%8==3?0x9d:n%8==4?0x9e:n%8==5?0x9f:0x71);rig->model->flags=0;rig->session->clock_mode=std::uint8_t(n&1);rig->session->random.restore({std::uint16_t(n*13),std::uint16_t(n*31),std::uint8_t(n)});rig->spatial.listener={origin.x,origin.y,origin.z};
        }
        std::memset(memory+work_at,0,stride);memory[work_at]=1;memory[work_at+2]=9;memory[work_at+3]=3;for(unsigned at=0x117;at<=0x11a;++at)memory[work_at+at]=255;put(memory,work_at+0x28,parent_at);put(memory,work_at+0x38,actor->position);put(memory,work_at+0x90,actor->orientation);put(memory,work_at+18,std::int16_t(-1));put(memory,work_at+0x160,actor->projectile_contact.normal);put(memory,0x3c564c+3*60,model_at);put(memory,model_at+0x36,native.model->content_id);put(memory,model_at+0x200,native.model->position);put(memory,model_at+0x20c,native.model->use_vector);put(memory,model_at+0x224,native.model->use_parameters);put(memory,model_at+0x21c,native.model->angles);put(memory,model_at+0x23c,0u);memory[0x3243cc]=native.session->clock_mode;
        for(unsigned frame=0;frame<4;++frame){
            if(frame==1){actor->contact.serial=source_actor->contact.serial=memory[work_at+0x116]=std::uint8_t(1+n%3);if(n%16==15)actor->contact.recipient.token=source_actor->contact.recipient.token=memory[work_at+0x118]=2;}
            reference=&source;invoke(memory,0x583c50,{work_at});reference=nullptr;check(native.updates.update(native.pool,native.work,9));sync(memory,*source_actor);
            check(actor->primary==source_actor->primary&&actor->visible==source_actor->visible&&actor->contact.serial==source_actor->contact.serial&&actor->pose_work->lifetime==source_actor->pose_work->lifetime&&actor->pose_work->timer==source_actor->pose_work->timer&&actor->auxiliary_status==source_actor->auxiliary_status);
            check(std::memcmp(&actor->position,&source_actor->position,12)==0&&std::memcmp(&actor->pose_work->velocity,&source_actor->pose_work->velocity,12)==0&&actor->previous_orientation==source_actor->previous_orientation);check(native.model->flags==get<unsigned>(memory,model_at+0x23c)&&std::memcmp(&native.model->position,memory+model_at+0x200,12)==0&&std::memcmp(native.model->angles.data(),memory+model_at+0x21c,6)==0);
            check(native.pool.remaining()==source.pool.remaining()&&native.packets.size()==source.packets.size()&&native.tasks.size()==source.tasks.size()&&native.lighting.primary_count()==source.lighting.primary_count());
            auto left=native.packets.head(),right=source.packets.head();while(left&&right){const auto actual=native.packets.acquire(left),expected=source.packets.acquire(right);check(actual.state().definition==expected.state().definition&&actual.state().delivery.bank==expected.state().delivery.bank);left=actual.next();right=expected.next();}check(!left&&!right);
            check(native.frontend.last_result().has_value()==source.frontend.last_result().has_value());if(native.frontend.last_result())check(native.frontend.last_result()->status==source.frontend.last_result()->status&&native.frontend.last_result()->commands==source.frontend.last_result()->commands);
            check(native.session->random.state()==source.session->random.state());std::array<float,512> mixed{},expected{};check(native.engine->mix_add(mixed.data(),256,gains)==b::Status::ok&&source.engine->mix_add(expected.data(),256,gains)==b::Status::ok&&mixed==expected);for(float f:mixed)if(f!=0)++owner_pcm_signal;owner_pcm_frames+=256;++owner_frames;
        }
        // Real ungated task continues through canonical scheduler after parent
        // retirement; compare every primary light coefficient to independent
        // source-requested owner. The complete curve is separately differential.
        if(native.tasks.size()){
            check(native.world.retire_primary(0)==g::actors::EntityStatus::completed&&source.world.retire_primary(0)==g::actors::EntityStatus::completed);
            for(unsigned tick=0;native.tasks.size()&&tick<80;++tick){check(native.tasks.run(t::Pass::update).status==t::Status::completed&&source.tasks.run(t::Pass::update).status==t::Status::completed);const auto actual=native.lights.snapshot(),expected=source.lights.snapshot();check(actual.size()==expected.size());for(unsigned i=0;i<actual.size();++i)check(std::memcmp(&actual[i].value.descriptor,&expected[i].value.descriptor,sizeof(l::Definition))==0);++owner_light_frames;}check(!native.tasks.size()&&!source.tasks.size());
            native.parent=native.world.spawn_primary(0,std::make_unique<g::Actor>()).id;source.parent=source.world.spawn_primary(0,std::make_unique<g::Actor>()).id;for(auto* rig:{&native,&source}){rig->world.resolve(rig->parent)->category=0;rig->world.resolve(rig->parent)->slot=0;rig->world.resolve(rig->parent)->surface_material=3;}
        }++owner_cases;
    }
    rooms.missing=true;check(!native.effects.floor({}));++owner_refusals;rooms.missing=false;check(bool(native.effects.floor({})));rooms.room->identities.retire(rooms.room->id.entity);check(!native.effects.floor({}));++owner_refusals;
    check(native.effects.sound({},7)); // Null sound source is a measured normal skip.
    check(!native.updates.update(native.pool,native.work,20));++owner_refusals;
    native.packets.close();check(!native.effects.bound_to(native.world)&&!native.effects.burst(native.parent,{})&&!native.effects.packet(native.work,0x69));++owner_refusals;
    check(owner_cases&&owner_frames&&owner_light_frames);
}
