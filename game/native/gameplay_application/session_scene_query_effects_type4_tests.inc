// Included by the initialized SessionStartup fixture after canonical room
// resources and SessionSceneQueryEffects are bound.
#include "session_resources.hpp"
inline void session_scene_query_effects_type4_tests(
    app::NativeSession& host,app::SessionSceneQueryEffects& effects,
    const std::shared_ptr<w::Actor>& actor) {
    check(actor&&actor->category==0&&host.resources()&&host.resources()->initialized());
    auto& world=host.world();auto& flags=host.update().flags();
    const auto original_flags=flags.snapshot();const auto original_mode=world.mode;
    const auto original_selected=world.selected_actor;const auto original_owner=world.session().inventory_owner;
    const auto original_status=actor->status;const auto original_category=actor->category;
    const auto original_slot=actor->slot;const auto original_phase=world.session().message_phase;
    const auto actor_id=world.identity_of(*actor);check(bool(actor_id));
    std::uint32_t missing=0xffff;
    for(unsigned i=0;i<0x10000&&host.resources()->inventory().find_by_content(actor_id,missing);++i)
        --missing;
    check(host.resources()->inventory().find_by_content(actor_id,missing)==0);
    const auto call=[&](std::uint32_t operation,std::uint32_t bank,std::uint32_t content){
        scene::Record record;record.authored_id=501;record.body=s::ControlTypeFour{bank,0};
        record.other_content=content;
        record.inventory_policy=scene::InventoryPolicyCallback{
            0,0,0,operation,bank,content,0xffffffffu};
        return effects.dispatch(world,*actor,{},record);
    };
    world.mode=1;world.selected_actor=std::uint8_t(actor->slot);world.session().message_phase=0;
    flags.restore({});world.session().inventory_owner=2;actor->status|=0x8000u;
    const auto consumed=call(0,0,missing);
    check(consumed&&*consumed&&flags.get(s::FlagBank::scenario,501)==true);
    check(world.session().inventory_owner==0&&!(actor->status&0x8000u));

    flags.restore({});actor->status=original_status;
    const auto absent=call(1,1,missing);
    check(absent&&!*absent&&!flags.get(s::FlagBank::scenario,501).value_or(false));
    check(!flags.actor_flag(s::ActorFlagFamily::primary,1,501).value_or(false));

    flags.restore({});world.session().inventory_owner=2;actor->status|=0x8000u;
    const auto destroyed=call(3,0,missing);
    check(destroyed&&*destroyed&&flags.get(s::FlagBank::scenario,501)==true);
    check(world.session().inventory_owner==0&&!(actor->status&0x8000u));

    // 5C4230 exits for nonprimary actors before requiring its typed payload.
    actor->category=1;scene::Record nonprimary;nonprimary.body=s::ControlTypeFour{};
    const auto no_op=effects.dispatch(world,*actor,{},nonprimary);
    check(no_op&&*no_op);

    // Gate3 is the mode-zero/nonlocal path; actor1 remains a canonical primary
    // record and the default operation performs no inventory or flag work.
    actor->category=0;auto other=world.primary(1);
    if(other){const auto before=flags.snapshot();world.mode=0;world.selected_actor=0;
        scene::Record remote;remote.authored_id=502;remote.body=s::ControlTypeFour{};
        remote.inventory_policy=scene::InventoryPolicyCallback{3,0,0,4,0,0,0xffffffffu};
        const auto admitted=effects.dispatch(world,*other,{},remote);
        check(admitted&&*admitted&&flags.snapshot().shared.scenario==before.shared.scenario);
    }
    flags.restore(original_flags);world.mode=original_mode;world.selected_actor=original_selected;
    world.session().inventory_owner=original_owner;world.session().message_phase=original_phase;
    actor->status=original_status;actor->category=original_category;actor->slot=original_slot;
}
