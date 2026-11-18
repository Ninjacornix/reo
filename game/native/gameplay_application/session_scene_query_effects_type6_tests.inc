// Included only after the startup fixture owns a live NativeSession and the
// room matrix service. The original-body comparison lives in the tool oracle.
#include "../gameplay_scenario/scene_matrix_programs.hpp"
inline void session_scene_query_effects_type6_tests(
    app::NativeSession& host,app::SessionSceneQueryEffects& effects,
    const std::shared_ptr<w::Actor>& actor) {
    check(bool(actor));
    auto& world=host.world();auto& session=world.session();
    const auto saved_request=actor->interaction_request;
    const auto saved_transient=actor->transient_action;
    const auto saved_model=actor->scene_model;
    const auto saved_class=actor->motion_class;
    const auto saved_category=actor->category;
    const auto saved_slot=actor->slot;
    const auto saved_heading=actor->orientation[1];
    const auto saved_mode=world.mode;const auto saved_selected=world.selected_actor;
    const auto saved_scenario=session.scenario;
    const auto saved_transition=session.scene_transition_publication;
    const auto invoke=[&](std::uint32_t mode,std::uint8_t category,bool special,
                          std::uint32_t yaw,std::int32_t y,std::uint32_t p58,
                          std::uint32_t p5c,std::uint32_t matrix_index){
        actor->category=category;actor->motion_class=special?0x1a:0;
        actor->orientation[1]=0;actor->interaction_request= w::InteractionRequest{};
        actor->transient_action=0;actor->scene_model=s::ModelReference{};
        scene::Record record;record.body=s::ControlTypeSix{42,p5c,matrix_index};
        record.ladder_entry=scene::LadderEntryDetails{mode,s::ModelReference{0}};
        record.other_content=yaw;record.other_resource_class=p58;
        scene::CollisionShape shape{};shape.bounds[3].x=y;record.collision=shape;
        return effects.dispatch(world,*actor,{},record);
    };

    // Default room matrix is the canonical zero matrix. The selected mode0
    // branch rotates source offset(0,0,-40), compares ordered dot<=0, and
    // publishes AB9/AB8/ABC/AC8/ABB.
    world.mode=1;world.selected_actor=0;actor->slot=1;
    auto result=invoke(0,0,false,0,0,0,0,0);
    check(result&&*result&&actor->transient_action==1&&actor->interaction_request);
    check(actor->interaction_request->kind==0x0b&&actor->interaction_request->anchor.z==-40.0f);
    check(actor->interaction_request->orientation==0&&actor->scene_model.encoded()==0);

    // Special mode0 uses the scene origin and signed P+20 value for Y.
    result=invoke(0,0,true,0,-73,0,0,0);
    check(result&&*result&&actor->interaction_request->kind==0x0e);
    check(actor->interaction_request->anchor.x==0.0f&&actor->interaction_request->anchor.y==-73.0f&&
          actor->interaction_request->anchor.z==0.0f);

    // Special class0 mode4 publishes globals before the actor's short request.
    world.mode=0;world.selected_actor=0;actor->slot=0;session.scenario=19;
    result=invoke(4,0,true,0,0,23,5,0);
    check(result&&*result&&session.scene_transition_publication);
    check(session.scene_transition_publication->kind==4&&
          session.scene_transition_publication->variant==0x85&&
          session.scene_transition_publication->scenario==19&&
          session.scene_transition_publication->destination==23);
    check(actor->interaction_request->kind==0x0f&&actor->interaction_request->parameter==1&&
          actor->transient_action==1);

    // Source class1 mode4 deliberately omits the global publication and ABA.
    session.scene_transition_publication.reset();
    result=invoke(4,1,true,0,0,23,5,0);
    check(result&&*result&&!session.scene_transition_publication&&
          actor->interaction_request->kind==0x0f&&actor->interaction_request->parameter==1&&
          actor->transient_action==1);

    actor->interaction_request=saved_request;actor->transient_action=saved_transient;
    actor->scene_model=saved_model;actor->motion_class=saved_class;actor->category=saved_category;
    actor->slot=saved_slot;actor->orientation[1]=saved_heading;world.mode=saved_mode;
    world.selected_actor=saved_selected;session.scenario=saved_scenario;
    session.scene_transition_publication=saved_transition;
}
