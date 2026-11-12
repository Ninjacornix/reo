#include "game/native/gameplay_effects/resource_flight_queries.hpp"
#include "game/native/gameplay_world/resource_flight_audio.hpp"
#include "game/native/gameplay_world/flight_weapon_effects.hpp"
#include <limits>
unsigned flight_owner_cases{},flight_owner_frames{},flight_owner_cues{},flight_pcm_frames{},flight_signal_samples{},flight_owner_refusals{};
namespace flight_owner_fixture {
using namespace depletion_fixture;
namespace c=reo::native::gameplay_collision;namespace rct=reo::native::gameplay_contact_world;
struct Room final:rct::RoomInvocation {
    g::actors::EntityStore identities{{1}};rct::RoomId id{identities.create(std::make_unique<g::actors::Entity>()).id};
    c::response::Grid walls,floors;c::regions::World regions;c::room_objects::Owner objects;g::CollisionRoom view;
    Room(c::response::Grid wall,c::response::Grid floor):walls(std::move(wall)),floors(std::move(floor)),view{walls,floors,regions,objects,{},{},false,false}{}
    rct::RoomId identity()const noexcept override{return id;}
    bool current(rct::RoomId value)const noexcept override{return value==id&&bool(identities.acquire(value.entity));}
    std::uint16_t room_number()const noexcept override{return 7;}
    const g::CollisionRoom& geometry()const override{return view;}
    std::shared_ptr<s::SceneMatrixPrograms> programs()const override{throw std::runtime_error("Flight traces do not consume scene matrix programs");}
};
struct Rooms final:rct::RoomResources {
    std::shared_ptr<Room> room;bool missing{};unsigned reads{};
    std::shared_ptr<rct::RoomInvocation> retain(std::uint16_t number)override{++reads;return !missing&&number==7?room:nullptr;}
};
struct Audio final:e::FlightAudio {
    g::ResourceFlightAudio concrete;unsigned calls{};
    Audio(g::World& world,g::animation_events::BasicAudio& audio):concrete(world,audio){}
    bool bound_to(const g::World& world)const noexcept override{return concrete.bound_to(world);}
    bool cue(const g::actors::EntityId& id,m::Vector point)override{++calls;return concrete.cue(id,point);}
};
struct Original {
    e::RoomFlightQueries& queries;a::Owner& audio;reo::native::gameplay_session::Random& random;const a::SpatialContext& spatial;
    unsigned cue_calls{};std::optional<a::Result> result;
};
Original* current{};
std::vector<std::byte> bytes(const std::filesystem::path& path){std::ifstream file(path,std::ios::binary);const std::vector<char> data{std::istreambuf_iterator<char>(file),{}};check(!data.empty());std::vector<std::byte> result(data.size());std::memcpy(result.data(),data.data(),data.size());return result;}
void compare(std::uint8_t* memory,unsigned raw,const e::ResourceFlightState& state){
    check(state.visible==bool(memory[raw+1])&&state.phase==memory[raw+8]&&state.style==memory[raw+4]&&state.sticky==memory[raw+0x33]);
    check(state.lifetime==get<std::int16_t>(memory,raw+0xc)&&state.cooldown==get<std::int16_t>(memory,raw+0xe));
    const auto same=[&](unsigned offset,const auto& value){check(std::memcmp(&value,memory+raw+offset,sizeof value)==0);};
    same(0x50,state.basis);same(0x38,state.position);same(0x44,state.previous_position);same(0xd8,state.displacement);same(0xc0,state.velocity);same(0xcc,state.acceleration);same(0xb4,state.scale);same(0x208,state.color);same(0x90,state.angles);
}
}
bool resource_flight_port(std::uint8_t* memory,R5900Context* context){
    using namespace flight_owner_fixture;if(!current)return false;auto& original=*current;
    switch(context->pc){
    case 0x5795e0:case 0x57d560:{
        const bool floor=context->pc==0x57d560;check(GPR_U32(context,8)==(floor?0u:0x2ffffu)&&!GPR_U32(context,9));
        const auto start=get<m::Vector>(memory,GPR_U32(context,4)),end=get<m::Vector>(memory,GPR_U32(context,5));
        const auto result=floor?original.queries.floor(start,end):original.queries.wall(start,end);check(result.available);
        if(result.hit){put(memory,GPR_U32(context,6),result.hit->point);put(memory,GPR_U32(context,7),m::Vector{0,1,0});if(floor)memory[GPR_U32(context,10)]=result.hit->type;else put(memory,GPR_U32(context,10),unsigned(result.hit->type));}
        SET_GPR_U32(context,2,result.hit?1:0);return true;
    }
    case 0x1b93d0:{
        const auto bank=GPR_U32(context,4),event=GPR_U32(context,5);check((bank>=8&&bank<12&&event==4)||(bank==13&&event==7));check(GPR_U32(context,8)==1&&!GPR_U32(context,9)&&!GPR_U32(context,10));
        original.random.restore({get<std::uint16_t>(memory,0x3244b0),get<std::uint16_t>(memory,0x3244b8),memory[0x2b8de8]});
        const auto point=get<m::Vector>(memory,GPR_U32(context,7));original.result=original.audio.positional({bank,event},point,original.spatial,1);++original.cue_calls;
        put(memory,0x3244b0,original.random.state().primary);put(memory,0x3244b8,original.random.state().secondary);memory[0x2b8de8]=original.random.state().observed;return true;
    }
    default:return false;
    }
}
void compare_resource_flight_owner(const std::vector<std::vector<std::byte>>& corpus,const std::filesystem::path& directory,std::vector<std::uint8_t>& ram){
    using namespace flight_owner_fixture;auto* memory=ram.data();const auto wall=bytes(directory/"owned_flight_walls.bin"),floor=bytes(directory/"owned_flight_floors.bin"),cue=bytes(directory/"owned_flight_cue.bin");
    const std::span<const std::uint8_t> cue_bytes{reinterpret_cast<const std::uint8_t*>(cue.data()),cue.size()};
    auto room=std::make_shared<Room>(c::response::Grid::import(wall),c::response::Grid::import(floor));Rooms rooms;rooms.room=room;check(!room->floors.triangles().empty());
    for(unsigned asset=0;asset<corpus.size();asset+=2){
        const auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);auto session=std::make_shared<g::Session>();
        g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);world.room=7;
        std::array<g::actors::EntityId,4> actors;for(unsigned i=0;i<4;++i){auto actor=std::make_unique<g::Actor>();actor->slot=std::uint8_t(i);actor->position={1,2,3};actors[i]=world.spawn_primary(i,std::move(actor)).id;check(bool(actors[i]));}
        s::SceneResources resources;s::ResourceTemplates templates;a::SpatialContext spatial;spatial.world_to_screen=m::identity();
        auto engine=std::make_shared<b::Session>();a::Owner audio(engine,session->random);g::animation_events::BasicAudio frontend(world,audio,spatial,resources,templates);Audio actual_audio(world,frontend);
        auto reference_engine=std::make_shared<b::Session>();reo::native::gameplay_session::Random reference_random;a::Owner reference(reference_engine,reference_random);
        for(unsigned selected:{8u,9u,10u,11u,13u}){check(audio.install(audio.begin_bank(selected),cue_bytes).status==a::Status::completed);check(reference.install(reference.begin_bank(selected),cue_bytes).status==a::Status::completed);}
        for(unsigned style=0;style<32;++style)for(unsigned category:{0u,1u,2u})for(unsigned pose=0;pose<2;++pose){
            std::fill(ram.begin(),ram.end(),0);prepare(memory,corpus[asset],corpus[asset+1]);put(memory,0x294e00,m::identity());
            const auto slot=(style+pose)%4;const auto actor=world.resolve(actors[slot]);actor->category=std::uint8_t(category);const auto actor_raw=0x4a5c30+0x10e0*slot;
            memory[actor_raw+2]=actor->category;memory[actor_raw+3]=actor->slot;put(memory,actor_raw+0x38,actor->position);
            session->random.restore({std::uint16_t(style*997+pose),std::uint16_t(asset*257),std::uint8_t(style)});put(memory,0x3244b0,session->random.state().primary);put(memory,0x3244b8,session->random.state().secondary);memory[0x2b8de8]=session->random.state().observed;
            auto basis=m::identity();if(pose)m::compose_euler_radians(basis,{.3f,-.4f,.2f});
            const auto& triangle=room->floors.triangles()[(style+pose)%room->floors.triangles().size()];
            const m::Vector origin{(triangle.vertices[0].x+triangle.vertices[1].x+triangle.vertices[2].x)/3.f,(triangle.vertices[0].y+triangle.vertices[1].y+triangle.vertices[2].y)/3.f+20.f,(triangle.vertices[0].z+triangle.vertices[1].z+triangle.vertices[2].z)/3.f};
            spatial.listener=origin;actor->position={origin.x,origin.y,origin.z};put(memory,actor_raw+0x38,actor->position);
            auto offset=m::Vector{};if(const auto profile=e::resource_flight_profile(style))offset=m::direction(basis,profile->offset);
            basis[3]={origin.x-offset.x,origin.y-offset.y,origin.z-offset.z,1};put(memory,0x120000,basis);
            e::PeriodicVisuals owner(bank,session->random);check(owner.bind_resource_flights(world,rooms,actual_audio));check(owner.flights_bound_to(world));
            e::RoomFlightQueries source_queries(room);Original original{source_queries,reference,reference_random,spatial,0,{}};current=&original;
            const auto raw=get<unsigned>(memory,0x3b5838);call(memory,0x58e6d0,{actor_raw,0x120000,style});const auto native=owner.create_resource_flight(actors[slot],basis,style);
            const bool made=get<std::uint16_t>(memory,0x3b5828)==167;check(bool(native.id)==made);
            if(!made){check(native.status==e::WorkStatus::completed||native.status==e::WorkStatus::resource_missing);current=nullptr;++flight_owner_cases;continue;}
            check(native.status==e::WorkStatus::completed&&owner.size()==1&&owner.piece_count()==0);compare(memory,raw,*owner.resource_flight_state(native.id));
            const b::Command stop=b::StopAll{false};check(engine->apply({&stop,1}).status==b::Status::ok&&reference_engine->apply({&stop,1}).status==b::Status::ok);
            unsigned frames{};
            while(get<std::uint16_t>(memory,0x3b5828)==167){
                check(++frames<=48);const auto cues_before=actual_audio.calls;original.cue_calls=0;original.result.reset();
                call(memory,0x58e850,{raw});const auto report=owner.update({0,0,0});check(report.status==e::VisualStatus::completed);
                if(category<2)check(actual_audio.calls-cues_before==original.cue_calls);
                else{check(original.cue_calls==0);if(actual_audio.calls!=cues_before)check(!frontend.last_result());}
                flight_owner_cues+=original.cue_calls;
                if(original.result)check(frontend.last_result()&&frontend.last_result()->status==original.result->status&&frontend.last_result()->commands==original.result->commands);
                check(session->random.state()==reo::native::gameplay_session::RandomState{get<std::uint16_t>(memory,0x3244b0),get<std::uint16_t>(memory,0x3244b8),memory[0x2b8de8]});
                const auto state=owner.resource_flight_state(native.id);check(bool(state)==(get<std::uint16_t>(memory,0x3b5828)==167));
                const auto published=owner.retain();check(published&&published->visuals.size()==owner.size());
                if(state){compare(memory,raw,*state);check(published->visuals[0].flight&&published->visuals[0].category==7&&published->visuals[0].pieces.empty());}
                weapon_fixture::Gains gains;std::array<float,512> output{},expected{};check(engine->mix_add(output.data(),256,gains)==b::Status::ok&&reference_engine->mix_add(expected.data(),256,gains)==b::Status::ok&&output==expected);
                for(const auto value:output)if(value!=0)++flight_signal_samples;
                flight_pcm_frames+=256;++flight_owner_frames;
            }
            check(owner.size()==0&&owner.piece_count()==0);current=nullptr;++flight_owner_cases;
        }
        if(asset==0){
            unsigned style{};for(;style<32;++style){const auto profile=e::resource_flight_profile(style);if(profile&&bank->geometry().resolve(std::int16_t(profile->effect)))break;}check(style<32);
            e::PeriodicVisuals owner(bank,session->random);check(owner.bind_resource_flights(world,rooms,actual_audio));
            auto made=owner.create_resource_flight(actors[0],m::identity(),style);check(bool(made.id));
            for(unsigned i=0;i<45;++i)check(owner.update({}).status==e::VisualStatus::completed);
            check(owner.resource_flight_state(made.id)->lifetime==0);rooms.missing=true;const auto reads=rooms.reads;
            check(owner.update({}).status==e::VisualStatus::completed&&owner.resource_flight_state(made.id)->phase==2&&rooms.reads==reads);
            check(owner.update({}).status==e::VisualStatus::completed&&owner.size()==0&&rooms.reads==reads);rooms.missing=false;++flight_owner_refusals;
            g::FlightWeaponEffects adapter(world,owner);check(adapter.bound_to(world));
            check(adapter.flight(actors[0],m::identity(),style)&&owner.size()==1);
            check(!adapter.pose_work(actors[0],m::identity(),{},3)&&!adapter.transient_light(actors[0],{})&&!adapter.contact_style(actors[0],m::identity(),{},0));
            check(!adapter.flight({},m::identity(),style));check(owner.update({}).status==e::VisualStatus::completed);
            const auto frame=owner.retain();check(frame&&frame->visuals.size()==1&&owner.retire(frame->visuals[0].id)&&owner.size()==0);++flight_owner_refusals;
            for(unsigned i=0;i<168;++i)check(bool(owner.create_resource_flight(actors[0],m::identity(),style).id));
            auto invalid=m::identity();invalid[0][0]=std::numeric_limits<float>::quiet_NaN();check(owner.create_resource_flight(actors[0],invalid,style).status==e::WorkStatus::pool_full&&owner.size()==168);++flight_owner_refusals;
            owner.close();e::PeriodicVisuals missing(bank,session->random);check(missing.bind_resource_flights(world,rooms,actual_audio));made=missing.create_resource_flight(actors[0],m::identity(),style);check(bool(made.id));rooms.missing=true;
            check(missing.update({}).status==e::VisualStatus::invalid_profile&&!missing.retain());rooms.missing=false;++flight_owner_refusals;
            e::PeriodicVisuals stale(bank,session->random);check(stale.bind_resource_flights(world,rooms,actual_audio));made=stale.create_resource_flight(actors[3],m::identity(),style);check(bool(made.id));check(world.retire_primary(3)==g::actors::EntityStatus::completed);check(stale.update({}).status==e::VisualStatus::completed&&stale.size()==0);++flight_owner_refusals;
        }
    }
    current=nullptr;check(flight_owner_frames>0&&flight_owner_cues>0&&flight_signal_samples>0);
}
