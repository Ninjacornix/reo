#include "game/native/gameplay_world/canonical_actor_sounds.hpp"
#include "game/native/gameplay_world/primary_actor_records.hpp"
#include "game/native/gameplay_world/room_pose_projectiles.hpp"
#include "game/native/gameplay_world/linked_pose_timing.hpp"
#include "game/native/gameplay_world/linked_updates.hpp"
#include "game/native/gameplay_world/linked_models.hpp"
#include "game/native/gameplay_world/pose_trail_effects.hpp"
#include "game/native/gameplay_world/inherited_pose_trails.hpp"
#include "game/native/gameplay_effects/periodic_visuals.hpp"
#include "reference.hpp"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <source_location>
namespace g=reo::native::gameplay_world;namespace a=reo::native::gameplay_audio;namespace b=reo::native::audio_banks::v2;namespace m=reo::native::transform_math;namespace c=reo::native::gameplay_collision;namespace r=reo::native::gameplay_contact_world;namespace s=reo::native::gameplay_scenario;namespace e=reo::native::gameplay_effects;
unsigned checks{},cases{},calls{},requests{},signal_samples{},banks{},split_passes{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Canonical actor sound "+std::to_string(at.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* memory,unsigned at){return transform_read<T>(memory,at);}template<class T>void put(std::uint8_t* memory,unsigned at,T value){transform_write(memory,at,value);}
a::Owner* reference_audio{};const a::SpatialContext* spatial{};std::optional<a::Result> reference_result;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++calls;switch(context->pc){
 case 0x1b93d0:check(reference_audio&&spatial&&GPR_U32(context,4)==12&&GPR_U32(context,6)==memory[0x20554]&&GPR_U32(context,7)==0x20038&&GPR_U32(context,8)==1&&!GPR_U32(context,9));reference_result=reference_audio->positional({GPR_U32(context,4),GPR_U32(context,5),UINT32_MAX,UINT32_MAX,std::uint8_t(GPR_U32(context,10))},get<a::Vector>(memory,GPR_U32(context,7)),*spatial,1);++requests;break;
#include "original_dispatch.hpp"
 default:throw std::runtime_error("Unadmitted canonical sound helper "+std::to_string(context->pc));
 }context->pc=GPR_U32(context,31);
}
struct Gains final:b::GainProvider{float gain(unsigned,unsigned,std::uint64_t)noexcept override{return 1;}};
g::Profile profile(){g::Profile p;p.layouts.push_back({});p.entities.capacity=256;return p;}
std::vector<std::uint8_t> raw_bytes(const char* path){std::ifstream input(path,std::ios::binary);const std::vector<char> raw{std::istreambuf_iterator<char>(input),{}};check(!raw.empty());return{reinterpret_cast<const std::uint8_t*>(raw.data()),reinterpret_cast<const std::uint8_t*>(raw.data()+raw.size())};}
std::vector<std::byte> bytes(const char* path){const auto raw=raw_bytes(path);std::vector<std::byte> out(raw.size());std::memcpy(out.data(),raw.data(),raw.size());return out;}
std::vector<std::vector<std::byte>> corpus(const char* path){std::ifstream input(path,std::ios::binary);unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(count==12);std::vector<std::vector<std::byte>> out;for(unsigned i=0;i<count;++i){unsigned size{};input.read(reinterpret_cast<char*>(&size),4);check(size&&size<10000000);out.emplace_back(size);input.read(reinterpret_cast<char*>(out.back().data()),size);check(bool(input));}return out;}
struct Room final:r::RoomInvocation {
 g::actors::EntityStore ids{{1}};r::RoomId id{ids.create(std::make_unique<g::actors::Entity>()).id};c::response::Grid walls,floors;c::regions::World regions;c::room_objects::Owner objects;g::CollisionRoom view;
 Room(c::response::Grid w,c::response::Grid f):walls(std::move(w)),floors(std::move(f)),view{walls,floors,regions,objects,{},{},false,false}{}
 r::RoomId identity()const noexcept override{return id;}bool current(r::RoomId value)const noexcept override{return value==id&&bool(ids.acquire(value.entity));}std::uint16_t room_number()const noexcept override{return 7;}const g::CollisionRoom& geometry()const override{return view;}std::shared_ptr<s::SceneMatrixPrograms> programs()const override{throw std::runtime_error("Sound pose floors do not use matrix programs");}
};
struct Rooms final:r::RoomResources{std::shared_ptr<Room> room;std::shared_ptr<r::RoomInvocation> retain(std::uint16_t n)override{return n==7?room:nullptr;}};
g::actors::EntityId work(g::PoseWorkPool& pool,unsigned kind){const auto made=pool.allocate();check(made.status==g::PoseWorkStatus::completed);const auto actor=pool.resolve(made.id);check(actor&&actor->pose_work&&!actor->sound_state&&!actor->projectile_variant);actor->active=true;actor->pose_work->update_bound=true;actor->pose_work->kind=std::uint8_t(kind);actor->pose_work->lifetime=1000;return made.id;}
int main(int argc,char** argv)try{
 check(argc==6);const auto cue=raw_bytes(argv[1]);auto session=std::make_shared<g::Session>();g::World world(profile(),session);check(g::initialize_primary_records(world).status==g::PrimaryRecordsStatus::completed);const auto id=world.identity(0);const auto actor=world.resolve(id);check(actor&&actor->sound_state==g::ActorSoundState{}&&actor->projectile_variant==0);
 auto engine=std::make_shared<b::Session>(),reference_engine=std::make_shared<b::Session>();a::Owner audio(engine,session->random);reo::native::gameplay_session::Random original_random;a::Owner original_audio(reference_engine,original_random);a::SpatialContext context;context.world_to_screen=m::identity();spatial=&context;reference_audio=&original_audio;g::CanonicalActorOffsetSound sound(world,audio,context);g::CanonicalActorSoundOffsets offsets(world);g::CanonicalProjectileParentVariant variants(world);
 check(sound.sound(id,7)&&!sound.last_result()&&offsets.find(id)==0&&variants.read(id)==0);const auto unknown=world.spawn_primary(7,nullptr);check(!unknown.id);
 const auto generic=world.spawn_linked(std::make_unique<g::Actor>()).id;check(bool(generic)&&!sound.sound(generic,7)&&!offsets.find(generic)&&!variants.read(generic));const auto linked=world.linked_models().allocate(true);check(linked.status==g::LinkedStatus::completed&&world.resolve(linked.id)->sound_state==g::ActorSoundState{}&&variants.read(linked.id)==0&&sound.sound(linked.id,7));
 check(audio.install(audio.begin_bank(12),cue).status==a::Status::completed&&original_audio.install(original_audio.begin_bank(12),cue).status==a::Status::completed);std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();Gains gains;
 const auto exercise=[&](unsigned n,std::uint8_t event,g::ActorSoundState metadata,g::Position point,unsigned frames=64){
  actor->sound_state=metadata;actor->projectile_variant=std::uint8_t(n);actor->position=point;memory[0x20554]=actor->sound_state->allocation_slot;memory[0x20033]=actor->sound_state->program_variant;put(memory,0x20038,actor->position);
  const auto seed=reo::native::gameplay_session::RandomState{std::uint16_t(n*257),std::uint16_t(n*997),std::uint8_t(n)};session->random.restore(seed);original_random.restore(seed);const b::Command stop=b::StopAll{false};check(engine->apply({&stop,1}).status==b::Status::ok&&reference_engine->apply({&stop,1}).status==b::Status::ok);reference_result.reset();
  R5900Context original;PS2Runtime runtime;original.pc=0x1b9310;SET_GPR_U32(&original,4,0x20000);SET_GPR_U32(&original,5,event);SET_GPR_U32(&original,29,0x1f00000);SET_GPR_U32(&original,31,0x1234);original_transform_port(memory,&original,&runtime);check(original.pc==0x1234&&GPR_U32(&original,29)==0x1f00000);
  check(sound.sound(id,event)&&bool(sound.last_result())==bool(reference_result));if(reference_result)check(sound.last_result()->status==reference_result->status&&sound.last_result()->commands==reference_result->commands&&sound.last_result()->source_return==reference_result->source_return);check(session->random.state()==original_random.state()&&offsets.find(id)==actor->sound_state->program_variant&&variants.read(id)==std::uint8_t(n));std::vector<float> actual(frames*2),expected(frames*2);check(engine->mix_add(actual.data(),frames,gains)==b::Status::ok&&reference_engine->mix_add(expected.data(),frames,gains)==b::Status::ok&&actual==expected);for(float value:actual)if(value!=0)++signal_samples;++cases;
 };
 for(unsigned n=0;n<65536;++n)exercise(n,std::uint8_t(n*7+(n>>8)),{std::uint8_t(n),std::uint8_t(n>>8)},{float(int(n%13)-6),float(int(n%7)-3),float(n%11)});
 // Independent event sweep removes metadata/event correlation: tag0/event0
 // must be reached with a nonzero allocation gate as well as the silent pair.
 for(unsigned event=0;event<256;++event)exercise(event,std::uint8_t(event),{1,0},{0,0,0},2048);
 if(!signal_samples){const auto snapshot=engine->snapshot();std::cerr<<"PCM control diagnostics: requests="<<snapshot.diagnostics.requests<<" unsupported="<<snapshot.diagnostics.unsupported<<" active="<<snapshot.diagnostics.active_voice_frames<<" signal="<<snapshot.diagnostics.signal_voice_frames<<"\n";}
 check(signal_samples>0);check(world.retire_primary(0)==g::actors::EntityStatus::completed&&!sound.sound(id,7)&&!offsets.find(id)&&!variants.read(id));g::World foreign(profile(),std::make_shared<g::Session>());check(!sound.bound_to(foreign)&&!offsets.bound_to(foreign)&&!variants.bound_to(foreign));
 const auto catalog=c::delivery::Catalog::import(bytes(argv[2]));const auto assets=corpus(argv[3]);const auto walls=bytes(argv[4]),floors=bytes(argv[5]);
 for(unsigned asset=0;asset<assets.size();asset+=2){
  auto own_session=std::make_shared<g::Session>();auto own_world=std::make_shared<g::World>(profile(),own_session);check(g::initialize_primary_records(*own_world).status==g::PrimaryRecordsStatus::completed);own_world->room=7;const auto parent=own_world->identity(0);own_world->resolve(parent)->room=7;own_world->resolve(parent)->slot=7;g::PoseWorkPool pool(*own_world);c::delivery::Packets packets;Rooms rooms;rooms.room=std::make_shared<Room>(c::response::Grid::import(walls),c::response::Grid::import(floors));std::optional<c::Vec3> origin;
  for(const auto& triangle:rooms.room->floors.triangles()){if((triangle.flags&0x80)||triangle.normal.y<=0)continue;const c::Vec3 point{(triangle.vertices[0].x+triangle.vertices[1].x+triangle.vertices[2].x)/3.f,(triangle.vertices[0].y+triangle.vertices[1].y+triangle.vertices[2].y)/3.f+5,(triangle.vertices[0].z+triangle.vertices[1].z+triangle.vertices[2].z)/3.f};if(rooms.room->floors.floor(point).triangle){origin=point;break;}}
  check(bool(origin));const auto floor=rooms.room->floors.floor(*origin);const auto bank=e::EffectBank::import(assets[asset],assets[asset+1]);e::PeriodicVisuals visuals(bank,own_session->random);g::InheritedPoseTrailEffects inherited(own_world,visuals,rooms);g::MappedPoseTrailEffects mapped(*own_world,visuals,rooms,&inherited);g::PresetPoseWork presets(*own_world,pool,packets,catalog);auto own_engine=std::make_shared<b::Session>();a::Owner own_audio(own_engine,own_session->random);g::CanonicalActorOffsetSound own_sound(*own_world,own_audio,context);g::CanonicalProjectileParentVariant own_variants(*own_world);g::RoomPoseArcs arcs(*own_world,pool,rooms);g::RoomPoseProjectiles callbacks(*own_world,pool,rooms,packets,catalog,&presets,&mapped,&own_sound,nullptr,nullptr,&arcs);
  const auto split=work(pool,12);const auto splitting=pool.resolve(split);splitting->primary=1;splitting->contact.related=parent;splitting->pose_work->emitter_owner=parent;splitting->pose_work->basis=m::identity();splitting->position={origin->x,floor.height-.5f,origin->z};const auto first=pool.update(&callbacks);check(first.status==g::PoseWorkStatus::completed&&first.called==5&&!pool.resolve(split)&&!splitting->active&&!splitting->visible&&pool.remaining()==60&&!own_sound.last_result());const auto oldest=pool.resolve(pool.tail()),newest=pool.resolve(pool.head());check(oldest&&newest&&oldest!=newest&&oldest->pose_work->ordinal==2&&newest->pose_work->ordinal==5&&oldest->primary==1&&newest->primary==1&&oldest->pose_work->lifetime==179&&newest->pose_work->lifetime==179);
  for(unsigned frame=0;frame<180&&pool.remaining()!=64;++frame){check(pool.update(&callbacks).status==g::PoseWorkStatus::completed);++split_passes;}check(pool.remaining()==64);
  const std::shared_ptr<const c::response::Grid> linked_floor(rooms.room,&rooms.room->floors);g::LinkedActorUpdates linked_updates(*own_world,{},linked_floor);check(linked_updates.run().status==g::LinkedUpdateStatus::completed);g::LinkedPoseTimingQuantum quantum(*own_world);g::RoomTimedPoseProjectiles timed(*own_world,pool,rooms,packets,catalog,&mapped,&quantum,&own_variants);const auto timed_id=work(pool,17);const auto timed_actor=pool.resolve(timed_id);timed_actor->pose_work->variant=255;timed_actor->contact.related=parent;timed_actor->position={origin->x,origin->y+100,origin->z};check(pool.update(&timed).status==g::PoseWorkStatus::completed&&timed_actor->primary==1&&timed_actor->pose_work->timer==30&&own_variants.read(parent)==0);check(pool.reset()==g::PoseWorkStatus::completed);visuals.close();++banks;
 }
 std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"requests\":"<<requests<<",\"signal_samples\":"<<signal_samples<<",\"owned_banks\":"<<banks<<",\"split_passes\":"<<split_passes<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
