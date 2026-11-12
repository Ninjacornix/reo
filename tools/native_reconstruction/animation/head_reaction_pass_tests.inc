#include "game/native/gameplay_world/scene_primary_actors.hpp"
#include "game/native/gameplay_world/auxiliary_actors.hpp"
std::uint64_t cinematic_passes{};
void project_pass_actor(std::uint8_t* memory,const w::Actor& actor,const w::World& world,unsigned address,unsigned work,unsigned nodes){
 export_actor(memory,actor,world);put(memory,actor_at,std::uint8_t(actor.active));put(memory,actor_at+1,std::uint8_t(actor.visible));put(memory,actor_at+2,actor.category);put(memory,actor_at+0xb98,actor.character);put(memory,actor_at+0xbb4,actor.model_variant);put(memory,actor_at+0xbbc,actor.appearance_variant);put(memory,actor_at+0x54d,actor.model_pose_class);put(memory,actor_at+0x54a,actor.contact_flags);put(memory,actor_at+0xfac,actor.secondary_pose_category_override.value_or(0));
 std::memcpy(memory+address,memory+actor_at,0x10e0);put(memory,address+0x34,work);
 for(unsigned n=0;n<actor.model->nodes().size();++n){std::memcpy(memory+nodes+400*n,memory+nodes_at+400*n,400);put(memory,work+0x820+4*n,nodes+400*n);const auto& link=actor.model->links()[n];put(memory,nodes+400*n+0xc8,link.parent?nodes+400*unsigned(*link.parent):0u);put(memory,nodes+400*n+0xcc,link.sibling?nodes+400*unsigned(*link.sibling):0u);put(memory,nodes+400*n+0xd0,link.child?nodes+400*unsigned(*link.child):0u);}
}
void pass_tests(std::uint8_t* memory,const std::shared_ptr<const a::Skeleton>& skeleton){
 w::Profile profile;profile.layouts.push_back({});auto session=std::make_shared<w::Session>();w::World world(profile,session);session->session_state=0;auto& temporary=world.scene_primary_actors();check(temporary.initialize()==w::ScenePrimaryStatus::completed);std::vector<w::actors::EntityId> ids;
 for(unsigned i=0;i<8;++i)ids.push_back(temporary.identity_at(i));
 auto& auxiliary=world.auxiliary_actors();for(unsigned i=0;i<3;++i){const auto created=auxiliary.allocate(1);check(created.status==w::AuxiliaryStatus::completed);ids.push_back(created.id);}
 for(unsigned i=0;i<ids.size();++i){const auto actor=world.resolve(ids[i]);actor->category=std::uint8_t(i<8?0:1);actor->character=0;actor->position={float(i)*17,0,float(i)*13};install_model(*actor,skeleton);}
 constexpr unsigned temporary_at=0xc00000,auxiliary_at=0xd00000,work_base=0x1000000,nodes_base=0x1100000;
 w::CinematicActorReactions pass(world);
 for(unsigned variant=0;variant<64;++variant){phase="cinematic pass";case_index=variant;put(memory,0x38edd0,temporary_at);put(memory,0x3b59f0,auxiliary_at);std::size_t expected{};
  for(unsigned i=0;i<ids.size();++i){const auto actor=world.resolve(ids[i]);actor->active=(i+variant)%4!=0;actor->visible=(i+variant)%3!=0;actor->scripted->request_flags=variant%2?4:0;actor->scripted->relation_parameter=std::array<std::uint32_t,3>{0,30,UINT32_MAX}[(i+variant)%3];actor->scripted->relation_offset={700,140,900};actor->scripted->relation_mode=0;const auto address=i<8?temporary_at+0x10e0*i:auxiliary_at+0x1170*(i-8);project_pass_actor(memory,*actor,world,address,work_base+0x4000*i,nodes_base+0x20000*i);if(i>=8)put(memory,address+0x1c,i+1<ids.size()?auxiliary_at+0x1170*(i-7):0u);expected+=actor->active&&actor->visible;}
  invoke(memory,0x5ecbe0);const auto result=pass.run();check(result.status==w::HeadReactionStatus::applied&&result.temporary_visits==8&&result.auxiliary_visits==3&&result.heads==expected&&result.secondary==expected&&!world.busy());
  for(unsigned i=0;i<ids.size();++i){const auto actor=world.resolve(ids[i]);const auto address=i<8?temporary_at+0x10e0*i:auxiliary_at+0x1170*(i-8);std::memcpy(memory+actor_at,memory+address,0x10e0);std::memcpy(memory+nodes_at,memory+nodes_base+0x20000*i,400*actor->model->nodes().size());compare(memory,*actor);}
  ++cinematic_passes;
 }
 // A required missing component retains the prefix and releases both guards.
 const auto first=world.resolve(ids[0]);first->active=first->visible=true;first->head_reaction.reset();first->scripted->relation_parameter=30;const auto refused=pass.run();check(refused.status==w::HeadReactionStatus::unavailable&&refused.failed==ids[0]&&!world.busy());++refusals;
}
