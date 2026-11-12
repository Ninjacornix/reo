#include "game/native/gameplay_effects/periodic_visuals.hpp"
#include "game/native/gameplay_world/world.hpp"
#include "game/native/gameplay_contact_world/contacts.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <source_location>
namespace g=reo::native::gameplay_world;namespace e=reo::native::gameplay_effects;namespace m=reo::native::transform_math;namespace c=reo::native::gameplay_collision;namespace r=reo::native::gameplay_contact_world;namespace s=reo::native::gameplay_session;
unsigned checks{},cases{},calls{},frames{},constructors{},unavailable{},retired{},floor_queries{},action_refusals{},guards{},work_at=0x30000;
constexpr unsigned parent_at=0x20000,motion_at=0x22000,point_at=0x24000,raw_base=0x30000,child_base=0x80000;
void check(bool v,std::source_location p=std::source_location::current()){++checks;if(!v)throw std::runtime_error("Inherited trail owners "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}template<class T>void put(std::uint8_t* p,unsigned at,T v){transform_write(p,at,v);}
e::InheritedTrailState read_state(std::uint8_t* p){e::InheritedTrailState x;x.phase=p[work_at+8];x.ordinal=p[work_at+5];x.parent_type=p[work_at+0x32];x.latched=p[work_at+9];x.motion_variant=p[work_at+10];x.visible=p[work_at+1];x.delay=get<std::int16_t>(p,work_at+12);x.remaining=get<std::int16_t>(p,work_at+14);x.age=get<std::int16_t>(p,work_at+16);x.rotation_offset=get<std::int16_t>(p,work_at+0x234);x.attributes=get<std::uint16_t>(p,work_at+0x23e);x.position=get<m::Vector>(p,work_at+0x38);x.previous_position=get<m::Vector>(p,work_at+0x44);x.velocity=get<m::Vector>(p,work_at+0xc0);x.acceleration=get<m::Vector>(p,work_at+0xcc);x.target=get<m::Vector>(p,work_at+0xe4);x.scale=get<m::Vector>(p,work_at+0xb4);x.angles=get<std::array<std::int16_t,4>>(p,work_at+0x90);x.feedback_scale=get<float>(p,work_at+0xa8);return x;}
void vector_equal(const char* label,m::Vector a,m::Vector b){++checks;if(std::memcmp(&a,&b,12))throw std::runtime_error(std::string(label)+" case "+std::to_string(cases)+" actual "+std::to_string(a.x)+","+std::to_string(a.y)+","+std::to_string(a.z)+" source "+std::to_string(b.x)+","+std::to_string(b.y)+","+std::to_string(b.z));}
void equal(const e::InheritedTrailState& a,const e::InheritedTrailState& b){
 check(a.phase==b.phase&&a.ordinal==b.ordinal&&a.parent_type==b.parent_type&&a.latched==b.latched&&a.motion_variant==b.motion_variant&&a.visible==b.visible);
 check(a.delay==b.delay&&a.remaining==b.remaining&&a.age==b.age&&a.rotation_offset==b.rotation_offset&&a.attributes==b.attributes);
 vector_equal("position",a.position,b.position);vector_equal("previous",a.previous_position,b.previous_position);vector_equal("velocity",a.velocity,b.velocity);vector_equal("acceleration",a.acceleration,b.acceleration);vector_equal("target",a.target,b.target);vector_equal("scale",a.scale,b.scale);
 check(a.angles==b.angles);check(std::bit_cast<unsigned>(a.feedback_scale)==std::bit_cast<unsigned>(b.feedback_scale));
}

std::vector<std::byte> grid(std::uint8_t type){std::vector<std::byte> out(120);const auto write=[&]<class T>(unsigned at,T v){std::memcpy(out.data()+at,&v,sizeof v);};write(8,1024u);write(12,1024u);write(16,1u);write(20,1u);write(32,32u);write(36,56u);write(40,40u);write(48,0u);write(52,UINT32_MAX);write(64,unsigned(type));write(68,c::Vec3{-100,0,-100});write(80,c::Vec3{-100,0,1000});write(92,c::Vec3{1000,0,-100});write(104,c::Vec3{0,1,0});return out;}
struct Room final:r::RoomInvocation {
    g::actors::EntityStore ids{{1}};r::RoomId id{ids.create(std::make_unique<g::actors::Entity>()).id};c::response::Grid floors;c::regions::World regions;c::room_objects::Owner objects;g::CollisionRoom view;
    explicit Room(std::uint8_t type):floors(c::response::Grid::import(grid(type))),view{floors,floors,regions,objects,{},{},false,false}{}
    r::RoomId identity()const noexcept override{return id;}bool current(r::RoomId v)const noexcept override{return v==id&&bool(ids.acquire(v.entity));}std::uint16_t room_number()const noexcept override{return 7;}const g::CollisionRoom& geometry()const override{return view;}std::shared_ptr<reo::native::gameplay_scenario::SceneMatrixPrograms> programs()const override{throw std::runtime_error("Trail floor does not use matrix programs");}
};
struct Rooms final:r::RoomResources {std::shared_ptr<Room> room;unsigned reads{};std::shared_ptr<r::RoomInvocation> retain(std::uint16_t number)override{++reads;return number==7?room:nullptr;}} rooms;

struct Record {unsigned address{};g::actors::EntityId reference;bool live{true};};
std::vector<Record> records;std::shared_ptr<const e::EffectBank> bank;e::PeriodicVisuals* reference_owner{};s::Random* original_random{};unsigned raw_ordinal{},attempted{},constructor_unavailable{};bool constructing{},source_retired{},source_action{};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++calls;switch(context->pc){
 case 0x6525c0:case 0x6525d0:{
  e::WorkRequest q;check(!GPR_U32(context,4));q.position=get<m::Vector>(memory,GPR_U32(context,5));q.child_mask=GPR_U32(context,6);q.effect=std::uint16_t(GPR_U32(context,7));q.variant=std::int16_t(GPR_U32(context,8));q.flags=GPR_U32(context,9);q.update=context->pc==0x6525d0?e::WorkUpdate::scaled:e::WorkUpdate::ordinary;
  const auto made=reference_owner->create(q);if(constructing)++attempted;
  if(made.status!=e::WorkStatus::completed){constructor_unavailable+=made.status==e::WorkStatus::unavailable;SET_GPR_U32(context,2,0);break;}
  const auto raw=raw_base+0x1000*raw_ordinal++;check(raw_ordinal<32);std::memset(memory+raw,0,0x240);put(memory,raw+0xb4,m::Vector{1,1,1});put(memory,raw+0x208,std::array<float,4>{1,1,1,1});put(memory,raw+0x200,q.flags|0xa000u);put(memory,raw+0x44,*q.position);const auto bound=bank->bind(q.effect,q.variant);const auto& group=*bank->tracks().group(bound.group);put(memory,raw+14,group.lifetime);memory[raw+0x31]=std::uint8_t(bound.pieces.size());
  const auto meta=0x180000+raw_ordinal*0x10000,draw=meta+0x4000,header=meta+0x8000;put(memory,raw+0x1f4,header);put(memory,header+0x18,meta);put(memory,meta+0x808,draw);
  for(unsigned i=0;i<bound.pieces.size();++i){const auto child=child_base+raw_ordinal*0x2000+i*0x100;put(memory,raw+0x134+4*i,child);put(memory,raw+0x114+2*i,std::int16_t(bound.pieces[i].selector));std::memset(memory+child,0,0x100);put(memory,child+2,std::uint16_t(i));put(memory,child+4,q.flags|0xa800u);put(memory,child+12,m::Vector{1,1,1});put(memory,meta+0x1024+32*i,std::int16_t(i));put(memory,draw+152*i+4,unsigned(bank->geometry().meshes()[bound.pieces[i].mesh].indices.size()));}
  if(constructing){check(GPR_U32(context,10)==0x5789c0);records.push_back({raw,made.edit->identity(),true});}
  SET_GPR_U32(context,2,raw);++constructors;break;
 }
 case 0x1aec80:check(GPR_U32(context,4)==1);SET_GPR_U32(context,2,original_random->request(1));break;
 case 0x616f20:{check(GPR_U32(context,6)==255);const auto point=get<c::Vec3>(memory,GPR_U32(context,4));const auto floor=rooms.room->floors.floor(point,255);context->f[0]=floor.height;memory[GPR_U32(context,5)]=floor.type;++floor_queries;break;}
 case 0x654d40:check(GPR_U32(context,4)==parent_at&&GPR_U32(context,5)==14);source_action=true;break;
 case 0x5783a0:check(GPR_U32(context,4)==parent_at&&!GPR_U32(context,6)&&!GPR_U32(context,7));source_action=true;break;
 case 0x652880:check(GPR_U32(context,4)==work_at);SET_GPR_U32(context,2,1);break;
 case 0x652d60:check(GPR_U32(context,4)==work_at);break;
 case 0x651d00:check(GPR_U32(context,4)==work_at);source_retired=true;break;
#include "original_dispatch.hpp"
 default:throw std::runtime_error("Unadmitted inherited trail owner helper "+std::to_string(context->pc));
 }context->pc=GPR_U32(context,31);
}
void invoke(std::uint8_t* memory,unsigned pc,std::array<unsigned,5> args){R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&context,4+i,args[i]);for(unsigned n=0;context.pc!=0x1234&&n<8;++n)original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);}
std::vector<std::vector<std::byte>> corpus(const char* path){std::ifstream in(path,std::ios::binary);unsigned count{};in.read(reinterpret_cast<char*>(&count),4);check(count==12);std::vector<std::vector<std::byte>> out;for(unsigned i=0;i<count;++i){unsigned size{};in.read(reinterpret_cast<char*>(&size),4);check(size&&size<10000000);out.emplace_back(size);in.read(reinterpret_cast<char*>(out.back().data()),size);check(bool(in));}return out;}
int main(int argc,char** argv)try{
 check(argc==2);const auto assets=corpus(argv[1]);std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);
 for(unsigned asset=0;asset<assets.size();asset+=2){bank=e::EffectBank::import(assets[asset],assets[asset+1]);
  for(unsigned type:{7u,10u,19u,29u,30u})for(unsigned motion_kind:{13u,18u})for(int delay:{-2,0,3,32767,32768,65535,0x12340000})for(unsigned explicit_point=0;explicit_point<2;++explicit_point)for(unsigned airborne=0;airborne<2;++airborne)for(unsigned pressure=0;pressure<2;++pressure){
   auto session=std::make_shared<g::Session>();g::Profile p;p.layouts.push_back({});p.entities.capacity=16;auto world=std::make_shared<g::World>(p,session);world->room=7;const auto parent=world->spawn_primary(0,std::make_unique<g::Actor>()).id,motion=world->spawn_primary(1,std::make_unique<g::Actor>()).id;check(parent&&motion);world->resolve(parent)->slot=std::uint8_t(type);auto moving=world->resolve(motion);moving->pose_work.emplace();moving->pose_work->kind=std::uint8_t(motion_kind);moving->primary=3;moving->subphase=1;moving->position={10,airborne?100.f:-10.f,10};moving->pose_work->velocity={.25f,-1,.5f};moving->pose_work->acceleration={0,-.125f,-.0625f};moving->orientation={0,1234,0,-17};
   s::Random source_random;e::PeriodicVisuals native(bank,session->random),reference(bank,source_random);reference_owner=&reference;original_random=&source_random;rooms.room=std::make_shared<Room>(0);records.clear();raw_ordinal=0;attempted=0;constructor_unavailable=0;
   if(pressure){for(unsigned i=0;i<168;++i){const e::WorkRequest q{{},m::Vector{},0,36};const auto a=native.create(q),b=reference.create(q);check(a.status==b.status);if(a.status!=e::WorkStatus::completed)break;}}
   memory[parent_at+3]=std::uint8_t(type);memory[motion_at+4]=std::uint8_t(motion_kind);memory[motion_at+8]=3;memory[motion_at+11]=1;put(memory,motion_at+0x38,m::Vector{moving->position.x,moving->position.y,moving->position.z});put(memory,motion_at+0xc0,moving->pose_work->velocity);put(memory,motion_at+0xcc,moving->pose_work->acceleration);put(memory,motion_at+0x90,moving->orientation);const m::Vector point{20,moving->position.y+1,20};put(memory,point_at,point);
   constructing=true;invoke(memory,0x578620,{parent_at,motion_at,1,explicit_point?point_at:0u,std::uint32_t(delay)});constructing=false;const auto made=native.create_inherited_trails({world,&rooms,nullptr,parent,motion,explicit_point?std::optional(point):std::nullopt,delay});check(made.created==records.size()&&made.attempted==attempted&&native.size()==reference.size()&&native.piece_count()==reference.piece_count());check((made.status==e::WorkStatus::unavailable)==bool(constructor_unavailable));
   for(unsigned i=0;i<records.size();++i){work_at=records[i].address;const auto state=native.inherited_trail_state(made.identities[i]);check(bool(state));equal(*state,read_state(memory));}
   if(made.status==e::WorkStatus::unavailable){++unavailable;++cases;continue;}
   for(unsigned frame=0;frame<24&&!records.empty();++frame){source_action=false;for(unsigned i=unsigned(records.size());i-->0;){auto& record=records[i];if(!record.live)continue;work_at=record.address;source_retired=false;invoke(memory,0x5789c0,{work_at,0,0,0,0});if(source_retired){record.live=false;check(reference.retire(record.reference));++retired;}}
    const auto result=native.update({0,1,0});check(result.status==(source_action?e::VisualStatus::invalid_profile:e::VisualStatus::completed));for(unsigned i=0;i<records.size();++i){work_at=records[i].address;const auto state=native.inherited_trail_state(made.identities[i]);check(bool(state)==records[i].live);if(state)equal(*state,read_state(memory));}check(session->random.state()==source_random.state());++frames;
    if(source_action){++action_refusals;break;}
   }
   if(airborne&&!pressure&&std::any_of(records.begin(),records.end(),[](const auto& r){return r.live;})&&native.failure()==e::VisualStatus::completed&&delay==-2){
    check(rooms.room->ids.retire(rooms.room->id.entity)==g::actors::EntityStatus::completed);check(native.update({0,1,0}).status==e::VisualStatus::invalid_profile);++guards;
    rooms.room=std::make_shared<Room>(0);e::PeriodicVisuals recycled(bank,session->random);const auto fresh=recycled.create_inherited_trails({world,&rooms,nullptr,parent,motion,{},0});check(fresh.created==5);check(world->retire_primary(1)==g::actors::EntityStatus::completed);check(recycled.update({0,1,0}).status==e::VisualStatus::completed&&recycled.size()==0);for(const auto& id:fresh.identities)check(!recycled.inherited_trail_state(id));++guards;
   }
   if(!records.empty()){const auto old=made.identities[0];native.close();check(!native.inherited_trail_state(old));}++cases;
  }
 }
 check(cases==3360&&constructors>0&&frames>0&&retired>0&&action_refusals>0&&guards>0);std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"frames\":"<<frames<<",\"constructors\":"<<constructors<<",\"retirements\":"<<retired<<",\"action_refusals\":"<<action_refusals<<",\"guards\":"<<guards<<",\"unavailable_profiles\":"<<unavailable<<",\"floor_queries\":"<<floor_queries<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
