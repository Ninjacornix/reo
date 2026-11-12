#include "game/native/gameplay_world/target_metrics.hpp"
#include "game/native/gameplay_world/linked_models.hpp"
#include "game/native/gameplay_world/auxiliary_actors.hpp"
std::uint64_t target_queries{},target_updates{},relation_updates{};
reo::native::gameplay_collision::response::Grid empty_grid(){
 std::vector<std::byte> raw(48);const auto write=[&](unsigned at,std::uint32_t value){std::memcpy(raw.data()+at,&value,4);};write(8,10000);write(12,10000);write(16,1);write(20,1);write(32,32);write(36,40);write(40,36);write(44,UINT32_MAX);return reo::native::gameplay_collision::response::Grid::import(raw);
}
void install_model(w::Actor& actor,const std::shared_ptr<const a::Skeleton>& skeleton){actor.head_reaction.emplace();actor.scripted.emplace();actor.model=std::make_shared<a::Instance>(skeleton);actor.animation=std::make_shared<a::Playback>(actor.model);auto parent=t::identity();parent[3]={actor.position.x,actor.position.y,actor.position.z,1};actor.model->rebuild(parent);}
constexpr unsigned linked_at=0x42eb00,linked_stride=3472;
void export_targets(std::uint8_t* memory,const w::World& world,const w::Actor& source,const std::array<std::shared_ptr<w::Actor>,4>& targets){
 std::fill_n(memory+linked_at,linked_stride*50,0);const auto& metrics=*const_cast<w::World&>(world).target_metrics().state();
 const unsigned order=source.category==0?0x3b2e10:0x3b2a80,cells=(source.category==0?0x3b41c0:0x3b3220)+400*source.slot;
 std::memset(memory+order,255,50*(source.category==0?8:10));const auto& sorted=source.category==0?metrics.primary_linked_order[source.slot]:metrics.auxiliary_linked_order[source.slot];std::memcpy(memory+order+50*source.slot,sorted.data(),50);
 for(unsigned j=0;j<targets.size();++j){const auto& target=*targets[j];const auto physical=*const_cast<w::World&>(world).linked_models().physical_slot(world.identity_of(target));const auto address=linked_at+linked_stride*unsigned(physical),work=0x900000+0x4000*j,nodes=0xa00000+0x20000*j;put(memory,address,std::uint8_t(target.active));put(memory,address+0x34,work);put(memory,address+0x38,target.position);put(memory,address+0xc94,target.targeting->flags);put(memory,address+0x552,*target.targeting->head_model_point);
  for(unsigned n=0;n<target.model->nodes().size();++n){put(memory,work+0x820+4*n,nodes+400*n);put(memory,nodes+400*n,target.model->nodes()[n].world);}
  const auto& cell=source.category==0?metrics.primary_linked[source.slot][physical]:metrics.auxiliary_linked[source.slot][physical];if(cell){put(memory,cells+8*unsigned(physical),cell->pair.distance);put(memory,cells+8*unsigned(physical)+4,cell->pair.bearing);put(memory,cells+8*unsigned(physical)+6,cell->wall);}
 }
}
void target_tests(std::uint8_t* memory,const std::shared_ptr<const a::Skeleton>& skeleton){
 w::Profile profile;profile.layouts.push_back({});auto session=std::make_shared<w::Session>();w::World world(profile,session);world.mode=1;session->session_state=0;
 auto source=std::make_unique<w::Actor>();source->active=source->visible=true;source->category=0;source->slot=0;source->room=7;source->position={500,100,500};install_model(*source,skeleton);check(world.spawn_primary(0,std::move(source)).status==w::actors::EntityStatus::completed);
 const auto created_aux=world.auxiliary_actors().allocate();check(created_aux.status==w::AuxiliaryStatus::completed);const auto auxiliary=world.resolve(created_aux.id);auxiliary->active=auxiliary->visible=true;auxiliary->category=1;auxiliary->room=7;auxiliary->position={500,100,500};install_model(*auxiliary,skeleton);const std::array<std::shared_ptr<w::Actor>,2> sources{world.primary(0),auxiliary};
 std::array<std::shared_ptr<w::Actor>,4> targets;for(unsigned j=0;j<targets.size();++j){const auto created=world.linked_models().allocate(true);check(created.status==w::LinkedStatus::completed);targets[j]=world.resolve(created.id);targets[j]->active=true;targets[j]->room=7;targets[j]->targeting.emplace();targets[j]->targeting->head_model_point=21;install_model(*targets[j],skeleton);}
 const auto grid=empty_grid();w::TargetMetricRoom room{grid,grid,{}, {}};
 for(const auto& actor:sources)for(unsigned variant=0;variant<64;++variant){phase="target selection";case_index=variant+64*actor->category;actor->orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(variant*1661));
  for(unsigned j=0;j<targets.size();++j){auto& target=*targets[j];target.active=(variant%7!=j);target.targeting->flags=(variant%5==j)?1u:0u;target.position={500.f+float(int(j)-1)*90.f,float(100+int(j)*35+int(variant%3)*140),600.f+float(j)*130.f};auto basis=t::identity();basis[3]={target.position.x,target.position.y,target.position.z,1};target.model->rebuild(basis);}
  check(world.target_metrics().rebuild(room).status==w::TargetMetricStatus::completed);export_actor(memory,*actor,world);put(memory,actor_at+2,actor->category);put(memory,actor_at+3,actor->slot);export_targets(memory,world,*actor,targets);
  for(unsigned selector:{0u,1u,2u,255u})for(std::int16_t aperture:{std::int16_t(INT16_MIN),std::int16_t(-20000),std::int16_t(0),std::int16_t(20000),std::int16_t(32767)})for(unsigned ordinal=0;ordinal<5;++ordinal)for(float distance:{0.f,600.f,1000.f}){
   const auto native=w::select_head_target(world,*actor,distance,std::uint8_t(selector),aperture,std::uint8_t(ordinal));const auto source_address=invoke(memory,0x65f0c0,actor_at,selector,std::uint16_t(aperture),distance,ordinal);const auto physical=world.linked_models().physical_slot(native);check(source_address==(physical?linked_at+linked_stride*unsigned(*physical):0u));++target_queries;
  }
  phase="target update";
  for(unsigned tick=0;tick<8;++tick){auto& h=*actor->head_reaction;h.mode=std::uint8_t((variant+tick)%3==0?0:1);h.ticks=std::int16_t(tick%3);h.retarget_ticks=std::int16_t(tick%4);h.target=tick%2?world.identity_of(*targets[tick%4]):w::actors::EntityId{};session->clock_mode=std::uint8_t(variant%2);session->random.restore({std::uint16_t(variant*123),456,7});export_actor(memory,*actor,world);put(memory,actor_at+2,actor->category);put(memory,actor_at+3,actor->slot);const auto physical=world.linked_models().physical_slot(h.target);put(memory,actor_at+0xbe0,physical?linked_at+linked_stride*unsigned(*physical):0u);export_targets(memory,world,*actor,targets);put(memory,0x3244b0,session->random.state().primary);put(memory,0x3244b8,session->random.state().secondary);
   invoke(memory,0x6613a0,actor_at,1);const auto result=w::update_head_reaction(world,*actor,1);check(result==w::HeadReactionStatus::applied);compare(memory,*actor);const auto chosen=world.linked_models().physical_slot(actor->head_reaction->target);check(transform_read<unsigned>(memory,actor_at+0xbe0)==(chosen?linked_at+linked_stride*unsigned(*chosen):0u));check(transform_read<std::uint16_t>(memory,0x3244b0)==session->random.state().primary);++target_updates;
  }
  phase="related actor";
  for(unsigned tick=0;tick<8;++tick){auto& script=*actor->scripted;script.relation_mode=1;script.related_actor=world.identity_of(*targets[tick%4]);script.relation_options=std::uint32_t(int(tick)*55-100);script.relation_parameter=tick%2?30u:UINT32_MAX;export_actor(memory,*actor,world);put(memory,actor_at+2,actor->category);put(memory,actor_at+3,actor->slot);export_targets(memory,world,*actor,targets);const auto related=*world.linked_models().physical_slot(script.related_actor);put(memory,actor_at+0xb4c,linked_at+linked_stride*unsigned(related));const auto target=world.linked_models().physical_slot(actor->head_reaction->target);put(memory,actor_at+0xbe0,target?linked_at+linked_stride*unsigned(*target):0u);invoke(memory,0x6613a0,actor_at,4);check(w::update_head_reaction(world,*actor,4)==w::HeadReactionStatus::applied);compare(memory,*actor);++relation_updates;}
  actor->scripted->relation_mode=0;
 }
}
