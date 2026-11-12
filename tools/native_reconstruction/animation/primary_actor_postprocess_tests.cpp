#include "game/native/gameplay_world/primary_actor_postprocess.hpp"
#include "game/native/gameplay_scenario/scene_model_bindings.hpp"
#include "game/native/animation/model.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
namespace w=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;namespace e=reo::native::gameplay_events;namespace a=reo::native::animation;namespace scene=reo::native::gameplay_scene;namespace collision=reo::native::gameplay_collision;
std::uint64_t checks{},calls{},cases{},weapons{},floors{},refusals{},lifetimes{};unsigned fixture{},floor_type{};std::vector<unsigned> original_weapons;
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Primary postprocess "+std::to_string(fixture)+" line "+std::to_string(at.line()));}
constexpr unsigned base=0x4a5c30,stride=0x10e0;
template<class T>void put(std::uint8_t* memory,unsigned at,T value){transform_write(memory,at,value);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;
 if(context->pc==0x616f20){put(memory,GPR_U32(context,5),std::uint8_t(floor_type));++floors;context->f[0]=0;context->pc=GPR_U32(context,31);return;}
 if(context->pc==0x65ec40){const auto at=GPR_U32(context,4);put(memory,at+0xba0,transform_read<unsigned>(memory,at+0xba0)&~0x80000000u);if(memory[at+0xc7c]){original_weapons.push_back((at-base)/stride);
 check(!(transform_read<unsigned>(memory,at+0xba4)&0x80));put(memory,at+0xba4,transform_read<unsigned>(memory,at+0xba4)|0x1000u);}context->pc=GPR_U32(context,31);return;}
 switch(context->pc){
#include "original_dispatch.hpp"
 default:throw std::runtime_error("Undeclared ordinary source call "+std::to_string(context->pc));}}
void invoke(std::uint8_t* memory){R5900Context c;PS2Runtime runtime;c.pc=0x66a3a0;SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);original_transform_port(memory,&c,&runtime);
 check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);}
collision::response::Grid grid(unsigned type){std::vector<std::byte> bytes(128);const auto write=[&](unsigned at,auto value){std::memcpy(bytes.data()+at,&value,sizeof value);};write(8,1000u);write(12,1000u);write(16,1u);write(20,1u);write(32,32u);write(36,56u);write(40,40u);write(48,0u);write(52,0xffffffffu);write(64,type);write(68,collision::Vec3{0,0,0});write(80,collision::Vec3{1000,0,0});write(92,collision::Vec3{0,0,1000});write(104,collision::Vec3{0,1,0});write(116,0.f);return collision::response::Grid::import(bytes);}
struct Weapon final:w::ActorWeaponActions{w::World& world;w::PrimaryActorPostprocess* worker{};std::vector<unsigned> observed;bool allow{true};explicit Weapon(w::World& value):world(value){}bool bound_to(const w::World& value)const noexcept override{return &world==&value;}bool refresh(const w::actors::EntityId& id)override{auto actor=world.resolve(id);
 check(bool(actor));
 check(world.busy()&&world.executing_primary().has_value());
 check(!worker||worker->run().status==w::PrimaryPostprocessStatus::busy);
 check(world.close()==w::Status::busy);
 check(!(actor->status&0x80000000u)&&!(actor->auxiliary_status&0x80));observed.push_back(unsigned(*world.executing_primary()));if(!allow)return false;actor->auxiliary_status|=0x1000u;++weapons;return true;}};
void export_actor(std::uint8_t* memory,unsigned index,const w::Actor& actor){const auto at=base+stride*index;std::fill_n(memory+at,stride,0);memory[at]=actor.active;memory[at+1]=actor.visible;memory[at+2]=actor.category;memory[at+3]=actor.slot;memory[at+8]=actor.primary;memory[at+9]=actor.secondary;memory[at+10]=actor.phase;memory[at+11]=actor.subphase;memory[at+0x174]=actor.surface_kind;memory[at+0x54f]=actor.motion_class;memory[at+0xbb4]=actor.model_variant;memory[at+0xb98]=actor.character;memory[at+0xc7c]=actor.selected_resource;put(memory,at+0x38,actor.position);put(memory,at+0x44,actor.previous_position);put(memory,at+0x90,actor.orientation);put(memory,at+0xa0,actor.previous_orientation);put(memory,at+0x1e2,actor.room);put(memory,at+0x544,actor.current);put(memory,at+0x546,actor.maximum);put(memory,at+0x54a,actor.contact_flags);put(memory,at+0xba0,actor.status);put(memory,at+0xba4,actor.auxiliary_status);put(memory,at+0x4ec,actor.root_motion_delta.z);put(memory,at+0xce2,*actor.surface_transition_flags);put(memory,at+0xfac,*actor.secondary_pose_category_override);put(memory,at+0xd94,actor.saved_action_position);put(memory,at+0xda0,actor.saved_action_yaw);
 const auto work=0x200000+index*0x2000,node=0x220000+index*0x200;put(memory,at+0x34,work);put(memory,work+0x874,node);put(memory,node+0x104,actor.model->nodes()[21].parameters);const auto& h=*actor.head_reaction;put(memory,at+0xbd1,h.mode);put(memory,at+0xbd2,h.ticks);put(memory,at+0xbd4,h.step);put(memory,at+0xbd8,h.current);put(memory,at+0xc30,h.retarget_ticks);put(memory,at+0xbe0,0u);
}
void compare(std::uint8_t* memory,unsigned index,const w::Actor& actor){const auto at=base+stride*index;
 check(actor.status==transform_read<unsigned>(memory,at+0xba0));
 check(actor.auxiliary_status==transform_read<unsigned>(memory,at+0xba4));
 if(actor.primary!=memory[at+8]||actor.secondary!=memory[at+9]||actor.phase!=memory[at+10]||actor.subphase!=memory[at+11])std::cerr<<"Action actor "<<index<<" native "<<unsigned(actor.primary)<<","<<unsigned(actor.secondary)<<","<<unsigned(actor.phase)<<","<<unsigned(actor.subphase)<<" original "<<unsigned(memory[at+8])<<","<<unsigned(memory[at+9])<<","<<unsigned(memory[at+10])<<","<<unsigned(memory[at+11])<<"\n";
 check(actor.primary==memory[at+8]&&actor.secondary==memory[at+9]&&actor.phase==memory[at+10]&&actor.subphase==memory[at+11]);
 check(std::memcmp(&actor.position,memory+at+0x38,12)==0&&std::memcmp(actor.orientation.data(),memory+at+0x90,8)==0);
 check(*actor.surface_transition_flags==memory[at+0xce2]);
 check(std::memcmp(&actor.saved_action_position,memory+at+0xd94,12)==0&&actor.saved_action_yaw==transform_read<std::int16_t>(memory,at+0xda0));const auto& h=*actor.head_reaction;
 check(h.mode==memory[at+0xbd1]&&h.ticks==transform_read<std::int16_t>(memory,at+0xbd2)&&h.retarget_ticks==transform_read<std::int16_t>(memory,at+0xc30));
 check(std::memcmp(h.current.data(),memory+at+0xbd8,4)==0&&std::memcmp(h.step.data(),memory+at+0xbd4,4)==0);}
int main(int argc,char** argv)try{
 check(argc==2);_mm_setcsr(0x1f80);std::ifstream input(argv[1],std::ios::binary);std::vector<char> raw((std::istreambuf_iterator<char>(input)),{});const auto skeleton=a::Skeleton::import_raw(std::as_bytes(std::span(raw)));std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());
 for(unsigned seed=0;seed<512;++seed){fixture=seed;original_weapons.clear();w::Profile profile;profile.layouts.push_back({});w::World world(profile,std::make_shared<w::Session>());world.mode=std::uint8_t(seed%4);world.selected_actor=std::uint8_t(seed%8);world.room=7;world.session().session_state=std::int16_t(seed%3);world.paused=std::int8_t(seed%2);auto records=std::make_shared<scene::Records>();s::SceneControls controls(records);s::SceneModelState model_state;s::RoomModelRemap remap{};s::SceneModels models(model_state,remap);reo::native::gameplay_actors::EntityStore objects;s::SceneModelBindings bindings(models,objects);s::FlagState flags;s::SceneMatrixPrograms::State states;states[0].contact.gate=2;s::SceneMatrixPrograms programs(controls,models,bindings,flags,world.room,states);e::Statistics statistics(e::RuleBook::create({e::RuleGroup{}},{0}));e::Events events;
 check(statistics.initialize(0,events)==e::StatisticsStatus::completed);
  scene::Record parent;parent.body=s::ControlTypeTwo{};const auto parent_id=records->create(parent);
 check(bool(parent_id));scene::Record proxy;proxy.body=s::ControlOther{0x85};proxy.source=*parent_id;proxy.collision=scene::CollisionShape{{{{0,0},{1000,0},{1000,1000},{0,1000}}},-100,100,1,false,{}};const auto proxy_id=records->create(proxy);
 check(bool(proxy_id));put(memory.data(),0x3b5150,std::uint16_t(126));put(memory.data(),0x3b5160,0x250000u);memory[0x250030]=0x85;put(memory.data(),0x250028,0x250100u);put(memory.data(),0x250034,0u);put(memory.data(),0x250040,0x250100u);put(memory.data(),0x250000,proxy.collision->bounds);put(memory.data(),0x250020,proxy.collision->lower);put(memory.data(),0x250024,proxy.collision->upper);memory[0x250130]=2;put(memory.data(),0x250128,0u);put(memory.data(),0x250140,0u);memory[0x4a3621]=2;memory[0x4a3622]=0;std::memset(memory.data()+0x4b9e20,0,sizeof flags.snapshot().strided);
  floor_type=seed%4;const auto floor_grid=grid(floor_type);
 check(floor_grid.floor({100,50,100}).type==floor_type);std::vector<std::shared_ptr<w::Actor>> actors;std::vector<std::shared_ptr<const a::JointSnapshot>> poses;
  for(unsigned index=0;index<8;++index){auto actor=std::make_unique<w::Actor>();actor->active=(seed+index)%7!=0;actor->visible=(seed+index)%2;actor->category=std::uint8_t((seed+index)%3);actor->slot=std::uint8_t(index);actor->room=std::uint16_t((seed+index)%5?7:8);actor->primary=std::uint8_t((seed+index)%3);actor->secondary=std::uint8_t((seed+index)%4?74:0);actor->phase=3;actor->subphase=4;actor->motion_class=255;actor->surface_kind=std::uint8_t((seed+index)%5);actor->contact_flags=std::uint16_t((seed+index)%3?0:2);actor->status=((seed+index)%2?0x80000000u:0u)|((seed+index)%16);actor->selected_resource=std::uint8_t((seed+index)%4?1:0);actor->auxiliary_status=0x80u|seed;actor->position={100.f+float(index),float(int(seed%5)-2)*20.f,100.f};actor->previous_position={90,10,90};actor->orientation={1,200,3,4};actor->previous_orientation={5,600,7,8};actor->root_motion_delta.z=float(int(seed%127)-63)*.25f;actor->current=std::int16_t(seed*31);actor->maximum=100;actor->surface_transition_flags=std::uint8_t(seed);actor->secondary_pose_category_override=2;actor->head_reaction.emplace();actor->head_reaction->mode=5;actor->head_reaction->ticks=13;actor->head_reaction->current={123,-456};actor->model_variant=0;actor->character=0;actor->model=std::make_shared<a::Instance>(skeleton);actor->model->rebuild(reo::native::transform_math::identity());auto created=world.spawn_primary(index,std::move(actor));
 check(bool(created.id));actors.push_back(world.resolve(created.id));poses.push_back(actors.back()->model->retain());export_actor(memory.data(),index,*actors.back());}
  memory[0x3243f2]=world.mode;memory[0x4baded]=world.selected_actor;put(memory.data(),0x3243dc,world.room);put(memory.data(),0x324200,world.session().session_state);put(memory.data(),0x4badf8,world.paused);for(unsigned at:{0x3b84b0u,0x3b84bcu,0x3b84c8u,0x3b84ccu,0x3b84d0u,0x3b84d4u,0x3b84d8u})put(memory.data(),at,0u);memory[0x3b84f5]=0;invoke(memory.data());Weapon weapon(world);w::PrimaryActorPostprocess worker(world,*records,programs,flags,statistics,&floor_grid,&weapon);weapon.worker=&worker;const auto report=worker.run();
 check(report.status==w::PrimaryPostprocessStatus::completed);
 check(!world.busy()&&!world.executing_primary());
 check(weapon.observed==original_weapons);
 check(world.selected_actor==memory[0x4baded]);for(unsigned i=0;i<8;++i){compare(memory.data(),i,*actors[i]);
 check(actors[i]->model->retain()==poses[i]);++lifetimes;}const auto& c=statistics.state().actors;
 check(c.forward_distance==transform_read<unsigned>(memory.data(),0x3b84b0));
 check(c.health_high==transform_read<unsigned>(memory.data(),0x3b84c8)&&c.health_middle==transform_read<unsigned>(memory.data(),0x3b84cc)&&c.health_low==transform_read<unsigned>(memory.data(),0x3b84d0));
 check(c.status_one==transform_read<unsigned>(memory.data(),0x3b84d4)&&c.status_two==transform_read<unsigned>(memory.data(),0x3b84d8));
 check(std::memcmp(flags.snapshot().strided.data(),memory.data()+0x4b9e20,sizeof flags.snapshot().strided)==0);
 check(programs.inspect(0)->interaction==memory[0x4a3622]);const auto source_owner=transform_read<unsigned>(memory.data(),0x250034);
 check(!source_owner||records->acquire(*proxy_id)->value.owner==world.identity((source_owner-base)/stride));
  if(seed%16==0){original_weapons.clear();weapon.observed.clear();invoke(memory.data());const auto repeated=worker.run();
   check(repeated.status==w::PrimaryPostprocessStatus::completed&&weapon.observed==original_weapons&&world.selected_actor==memory[0x4baded]);
   for(unsigned i=0;i<8;++i){compare(memory.data(),i,*actors[i]);check(actors[i]->model->retain()==poses[i]);++lifetimes;}
   check(c.forward_distance==transform_read<unsigned>(memory.data(),0x3b84b0));
   check(c.health_high==transform_read<unsigned>(memory.data(),0x3b84c8)&&c.health_middle==transform_read<unsigned>(memory.data(),0x3b84cc)&&c.health_low==transform_read<unsigned>(memory.data(),0x3b84d0));
   check(c.status_one==transform_read<unsigned>(memory.data(),0x3b84d4)&&c.status_two==transform_read<unsigned>(memory.data(),0x3b84d8));
   check(std::memcmp(flags.snapshot().strided.data(),memory.data()+0x4b9e20,sizeof flags.snapshot().strided)==0&&programs.inspect(0)->interaction==memory[0x4a3622]);++cases;
  }
  if(seed==8){for(auto& actor:actors)actor->active=false;auto& actor=*actors[0];actor.active=true;actor.category=0;actor.slot=0;actor.room=8;actor.status=0x80000000u;actor.selected_resource=1;actor.auxiliary_status|=0x80;world.mode=0;
   w::PrimaryActorPostprocess missing_weapon(world,*records,programs,flags,statistics,nullptr);const auto unavailable=missing_weapon.run();
   check(unavailable.status==w::PrimaryPostprocessStatus::unavailable&&unavailable.same_room==0&&!(actor.status&0x80000000u)&&!(actor.auxiliary_status&0x80)&&!world.busy());++refusals;
   actor.status=0x80000000u;actor.selected_resource=0;check(missing_weapon.run().status==w::PrimaryPostprocessStatus::completed&&actor.status==0&&world.selected_actor==0);
   actor.room=7;actor.primary=1;actor.contact_flags=0;actor.head_reaction->mode=5;const auto floor_refusal=missing_weapon.run();
   check(floor_refusal.status==w::PrimaryPostprocessStatus::unavailable&&floor_refusal.same_room==1&&floor_refusal.reactions==0&&actor.head_reaction->mode==5&&!world.busy());++refusals;
   actor.primary=0;actor.contact_flags=2;e::Statistics uninitialized(e::RuleBook::create({e::RuleGroup{}},{0}));w::PrimaryActorPostprocess missing_statistics(world,*records,programs,flags,uninitialized,nullptr);const auto stats_refusal=missing_statistics.run();
   check(stats_refusal.status==w::PrimaryPostprocessStatus::unavailable&&stats_refusal.reactions==1&&stats_refusal.statistics==0&&actor.head_reaction->mode==0&&!world.busy());++refusals;
   const auto retained=actors[0];check(world.close()==w::Status::completed&&worker.run().status==w::PrimaryPostprocessStatus::closed&&retained->model->retain()==poses[0]);++lifetimes;
  }
  if(seed<8){const auto lease=actors[0];lease->active=true;lease->status|=0x80000000u;lease->selected_resource=1;lease->auxiliary_status|=0x80;weapon.allow=false;const auto before=statistics.state().actors;const auto failure=worker.run();
 check(failure.status==w::PrimaryPostprocessStatus::unavailable&&failure.failed==world.identity(0));
 check(!(lease->status&0x80000000u)&&!(lease->auxiliary_status&0x80));
 check(statistics.state().actors.forward_distance==before.forward_distance&&!world.busy());++refusals;
 check(world.retire_primary(0)==w::actors::EntityStatus::completed&&!world.resolve(failure.failed)&&lease->model->retain()==poses[0]);++lifetimes;}
  ++cases;
 }
 std::cout<<"{\"checks\":"<<checks<<",\"complete_outer_cases\":"<<cases<<",\"weapon_boundary_calls\":"<<weapons<<",\"floor_boundary_calls\":"<<floors<<",\"refusals\":"<<refusals<<",\"lifetimes\":"<<lifetimes<<",\"source_calls\":"<<calls<<"}\n";
}catch(const std::exception& x){std::cerr<<x.what()<<'\n';return 1;}

