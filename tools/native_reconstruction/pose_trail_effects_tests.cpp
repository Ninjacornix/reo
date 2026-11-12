#include "game/native/gameplay_world/pose_trail_effects.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <vector>
namespace g=reo::native::gameplay_world;namespace e=reo::native::gameplay_effects;namespace m=reo::native::transform_math;namespace c=reo::native::gameplay_collision;namespace r=reo::native::gameplay_contact_world;
unsigned checks{},cases{},calls{},emissions{},configurations{},required_inherited{},floor_queries{};constexpr unsigned parent_at=0x20000,motion_at=0x22000,point_at=0x24000,raw_work=0x30000;
void check(bool v,std::source_location p=std::source_location::current()){++checks;if(!v)throw std::runtime_error("Pose trail effects "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,unsigned at,T v){transform_write(p,at,v);}
struct Config {std::uint8_t mode{};std::int16_t delay{};std::array<float,6> policy;};
struct Edit final:e::WorkEdit,e::ParticleEdit {
    std::vector<Config> configs;g::actors::EntityId identity()const noexcept override{return{};}bool uniform_scale(float)noexcept override{return false;}bool third_angle(std::int16_t)noexcept override{return false;}bool add_attributes(std::uint16_t)noexcept override{return false;}bool set_attributes(std::uint16_t)noexcept override{return false;}bool feedback(m::Vector,float)noexcept override{return false;}
    bool configure_particle(std::uint8_t mode,std::int16_t delay,const std::array<float,6>& p)noexcept override{configs.push_back({mode,delay,p});return true;}
};
struct Work final:e::WorkBackend {reo::native::gameplay_session::Random& random;std::vector<e::WorkRequest> requests;std::shared_ptr<Edit> edit{std::make_shared<Edit>()};e::WorkStatus status{};explicit Work(reo::native::gameplay_session::Random& r):random(r){}bool admitted()const noexcept override{return true;}bool bound_to(const reo::native::gameplay_session::Random& r)const noexcept override{return &random==&r;}e::WorkCreated create(const e::WorkRequest& q)noexcept override{requests.push_back(q);return{status,status==e::WorkStatus::completed?edit:nullptr};}e::WorkStatus refresh_companion()noexcept override{return e::WorkStatus::unavailable;}};
std::vector<std::byte> grid(std::uint8_t type){std::vector<std::byte> out(120);const auto write=[&]<class T>(unsigned at,T v){std::memcpy(out.data()+at,&v,sizeof v);};write(8,1024u);write(12,1024u);write(16,1u);write(20,1u);write(32,32u);write(36,56u);write(40,40u);write(48,0u);write(52,UINT32_MAX);write(64,unsigned(type));write(68,c::Vec3{-100,0,-100});write(80,c::Vec3{-100,0,1000});write(92,c::Vec3{1000,0,-100});write(104,c::Vec3{0,1,0});return out;}
struct Room final:r::RoomInvocation {
    g::actors::EntityStore ids{{1}};r::RoomId id{ids.create(std::make_unique<g::actors::Entity>()).id};c::response::Grid floors;c::regions::World regions;c::room_objects::Owner objects;g::CollisionRoom view;
    explicit Room(std::uint8_t type):floors(c::response::Grid::import(grid(type))),view{floors,floors,regions,objects,{},{},false,false}{}
    r::RoomId identity()const noexcept override{return id;}bool current(r::RoomId v)const noexcept override{return v==id&&bool(ids.acquire(v.entity));}std::uint16_t room_number()const noexcept override{return 7;}const g::CollisionRoom& geometry()const override{return view;}std::shared_ptr<reo::native::gameplay_scenario::SceneMatrixPrograms> programs()const override{throw std::runtime_error("Trail floor does not use matrix programs");}
};
struct Rooms final:r::RoomResources {std::shared_ptr<Room> room;unsigned reads{};std::shared_ptr<r::RoomInvocation> retain(std::uint16_t number)override{++reads;return number==7?room:nullptr;}} rooms;
std::vector<e::WorkRequest> expected;std::vector<Config> expected_configs;unsigned profile{},original_mode{},original_queries{};
#ifdef REO_TRAIL_EFFECT_OWNERS
bool trail_owned_port(std::uint8_t*,R5900Context*);
#endif
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;
#ifdef REO_TRAIL_EFFECT_OWNERS
    if(trail_owned_port(memory,context)){context->pc=GPR_U32(context,31);return;}
#endif
    switch(context->pc){
    case 0x6525c0:case 0x6525d0:{e::WorkRequest q;check(!GPR_U32(context,4));q.position=get<m::Vector>(memory,GPR_U32(context,5));q.child_mask=GPR_U32(context,6);q.effect=std::uint16_t(GPR_U32(context,7));q.variant=std::int16_t(GPR_U32(context,8));q.flags=GPR_U32(context,9);expected.push_back(q);if(profile==0&&original_mode!=1){std::memset(memory+raw_work,0,0x240);put(memory,raw_work+0xb4,m::Vector{1,1,1});put(memory,raw_work+0x208,std::array<float,4>{1,1,1,1});put(memory,raw_work+0x200,q.flags);SET_GPR_U32(context,2,raw_work);}else SET_GPR_U32(context,2,0);break;}
    case 0x578900:{if(GPR_U32(context,4))expected_configs.push_back({std::uint8_t(GPR_U32(context,5)),std::int16_t(GPR_U32(context,6)),get<std::array<float,6>>(memory,GPR_U32(context,7))});o2_00578900_0x578900(memory,context,runtime);return;}
    case 0x616f20:{check(GPR_U32(context,6)==0x81);const auto p=get<c::Vec3>(memory,GPR_U32(context,4));const auto hit=rooms.room->floors.floor(p,0x81);context->f[0]=hit.height;memory[GPR_U32(context,5)]=hit.type;++original_queries;break;}
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted mapped trail helper "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
bool same(const e::WorkRequest& a,const e::WorkRequest& b){return !a.basis&&!b.basis&&a.position&&b.position&&std::memcmp(&*a.position,&*b.position,12)==0&&a.variant==b.variant&&a.effect==b.effect&&a.child_mask==b.child_mask&&a.flags==b.flags&&a.update==b.update;}
#ifdef REO_TRAIL_EFFECT_OWNERS
#include "tools/native_reconstruction/pose_trail_effect_owners.inc"
#endif
int main(int argc,char** argv)try{
    check(argc==
#ifdef REO_TRAIL_EFFECT_OWNERS
        2
#else
        1
#endif
    );
    std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);g::Profile p;p.layouts.push_back({});p.entities.capacity=16;auto session=std::make_shared<g::Session>();g::World world(p,session);world.room=7;const auto parent=world.spawn_primary(0,std::make_unique<g::Actor>()).id,motion=world.spawn_primary(1,std::make_unique<g::Actor>()).id;check(parent&&motion);Work work(session->random);g::MappedPoseTrailEffects emitter(world,work,rooms);std::array<std::shared_ptr<Room>,2> known{std::make_shared<Room>(0),std::make_shared<Room>(0x81)};check(known[1]->floors.floor({10,5,10},0x81).type==0x81);
    for(unsigned water=0;water<2;++water)for(profile=0;profile<4;++profile)for(unsigned mode=0;mode<256;++mode)for(unsigned type=0;type<256;++type){
        rooms.room=known[water];rooms.reads=0;expected.clear();expected_configs.clear();work.requests.clear();work.edit->configs.clear();original_queries=0;original_mode=mode;work.status=profile==0?e::WorkStatus::completed:profile==1?e::WorkStatus::pool_full:profile==2?e::WorkStatus::resource_missing:e::WorkStatus::unavailable;
        world.resolve(parent)->slot=memory[parent_at+3]=std::uint8_t(type);world.resolve(motion)->position={10,5,10};put(memory,motion_at+0x38,m::Vector{10,5,10});const m::Vector override{20,-7,20};put(memory,point_at,override);const bool explicit_point=type&1;const auto delay=std::int32_t(0xabcd8001u);R5900Context context;PS2Runtime runtime;context.pc=0x578620;SET_GPR_U32(&context,4,parent_at);SET_GPR_U32(&context,5,motion_at);SET_GPR_U32(&context,6,mode);SET_GPR_U32(&context,7,explicit_point?point_at:0);SET_GPR_U32(&context,8,std::uint32_t(delay));SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
        const bool result=emitter.emit_at(parent,motion,std::uint8_t(mode),explicit_point?std::optional(override):std::nullopt,delay);const bool needs_inherited=mode==1&&!expected.empty();check(result==(!needs_inherited&&(profile!=3||expected.empty())));check(rooms.reads==original_queries);
        if(needs_inherited){check(work.requests.empty());++required_inherited;}else{
            check(work.requests.size()==expected.size()&&work.edit->configs.size()==expected_configs.size());for(unsigned i=0;i<expected.size();++i)check(same(work.requests[i],expected[i]));for(unsigned i=0;i<expected_configs.size();++i){const auto& a=work.edit->configs[i];const auto& b=expected_configs[i];check(a.mode==b.mode&&a.delay==b.delay&&a.policy==b.policy);}emissions+=unsigned(expected.size());configurations+=unsigned(expected_configs.size());
        }floor_queries+=original_queries;++cases;
    }
    rooms.room=known[1];world.resolve(parent)->slot=0x13;rooms.room->ids.retire(rooms.room->id.entity);check(!emitter.emit(parent,motion,3));world.resolve(parent)->slot=0;check(emitter.emit(parent,{},0)&&emitter.emit({}, {},4)&&!emitter.emit({}, {},0));
#ifdef REO_TRAIL_EFFECT_OWNERS
    trail_effect_owners(memory,argv[1]);
#endif
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"emissions\":"<<emissions<<",\"configurations\":"<<configurations<<",\"required_inherited\":"<<required_inherited<<",\"floor_queries\":"<<floor_queries<<",\"original_calls\":"<<calls
#ifdef REO_TRAIL_EFFECT_OWNERS
    <<",\"owned_cases\":"<<owned_cases<<",\"owned_frames\":"<<owned_frames<<",\"owned_configurations\":"<<owned_configurations<<",\"owned_missing\":"<<owned_missing<<",\"owned_unavailable\":"<<owned_unavailable<<",\"owned_guards\":"<<owned_guards
#endif
    <<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
