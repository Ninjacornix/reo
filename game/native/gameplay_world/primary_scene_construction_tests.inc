namespace {
void construction_owned(const char* archive){
    auto source=std::make_shared<reo::assets::Source>(archive);g::ActorAssets assets(source);g::HumanoidMotionAssets content(source);
    const auto base=content.base();const std::array<std::uint8_t,8> characters{0,1,2,3,4,5,6,7};const auto banks=content.overlay(1,characters,*base);
    using Roster=reo::native::gameplay_scenario::CutscenePrimaryRoster;
    using Choice=reo::native::gameplay_scenario::CutscenePrimaryChoice;
    for(unsigned temporary=0;temporary<8;++temporary)for(unsigned main=0;main<8;++main)for(unsigned model_class:{0u,1u})for(unsigned paused:{0u,1u}){
        g::World world(profile(),std::make_shared<g::Session>());world.room=std::uint16_t(0x120+temporary);world.paused=std::int8_t(paused);world.session().asset_loading_mode=1;
        g::HumanoidMotionOwner motions(world);check(motions.publish(banks).status==g::HumanoidPublicationStatus::completed);g::PrimaryActorModels owner(world,motions);
        auto initial=std::make_unique<g::Actor>();initial->slot=std::uint8_t(main);initial->character=std::uint8_t(main);
        const auto source_id=world.spawn_primary(main,std::move(initial)).id;const auto original=world.resolve(source_id);reo::native::gameplay_update::State state;
        const auto loaded=g::PrimaryActorModels::prepare(owner.capture(source_id).value(),assets,content);check(owner.apply(*loaded,state).status==g::PrimaryModelStatus::completed);
        original->current=std::int16_t(123+main);original->primary=1;original->secondary=2;original->phase=3;original->subphase=4;original->position={7,8,9};original->model_variant=37;original->appearance_variant=19;
        original->scripted.emplace();auto& script=*original->scripted;script.cue_phase=3;script.request_flags=0xffffffff;original->model_correction_skip=2;script.scale_lock=3;script.request_phase=4;script.motion_selector=5;script.motion_blend_duration=6;
        script.relation_mode=7;script.related_actor=source_id;script.relation_options=8;script.relation_parameter=9;script.relation_offset={10,11,12};script.command_angles={13,14,15};original->model_offset_frame=77;script.movement_angles={16,17};script.forward_step=18;script.yaw_step=19;script.movement_remaining=20;script.track_two_motion=21;script.scale_profile=22;
        original->primary_state->initialization_marker=0x7654;
        const auto source_before=g::copy_actor_owned(*original);check(source_before.status==g::ActorCopyStatus::completed);
        auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed);
        for(unsigned i=0;i<temporary;++i)world.resolve(pool.identity_at(i))->active=true;
        const auto old_id=pool.identity_at(temporary);const auto old_actor=world.resolve(old_id);
        Roster roster;roster.characters=characters;roster.eligible_count=4;const auto before=roster;
        const Choice choice{3,std::uint8_t(temporary),std::uint8_t(main),std::uint8_t(model_class),std::uint8_t(main)};
        if(main%3==0)world.session().asset_loading_mode.reset();else world.session().asset_loading_mode=std::uint8_t(main%3==1?0:128);
        const auto constructed=owner.construct_scene_primary(choice,roster,content);check(constructed.status==g::PrimaryModelStatus::completed&&constructed.id&&constructed.roster_slot==main&&constructed.release_on_exit==bool(model_class));
        const auto actor=world.resolve(constructed.id);check(actor&&pool.identity_at(temporary)==constructed.id&&!world.resolve(old_id)&&!old_actor->active&&world.identity(main)==source_id);
        check(actor->active&&!actor->visible&&actor->slot==temporary&&actor->primary==6&&actor->secondary==0&&actor->phase==0&&actor->subphase==0&&actor->model_variant==0&&actor->character==main&&actor->model_pose_class==model_class&&actor->room==world.room);
        check(actor->current==original->current&&actor->position.y==8&&actor->appearance_variant==19&&actor->primary_state->initialization_marker==0x7654&&actor->model_offset_frame==77);
        check(actor->model&&actor->model!=source_before.actor->model&&actor->animation->model()==actor->model&&!owner.capture(constructed.id));
        check(constructed.retirement_completed==bool(model_class)&&constructed.main_model_retired==bool(model_class)&&bool(original->model)==!model_class&&roster.characters[main]==(model_class?255:main));
        compare_construction(*old_actor,*source_before.actor,*actor,before,roster,choice,world.room,constructed);++construction_cases;
        const auto repeated=owner.construct_scene_primary(choice,roster,content);check(repeated.status==(temporary==7?g::PrimaryModelStatus::full:g::PrimaryModelStatus::stale)&&!repeated.id&&pool.identity_at(temporary)==constructed.id);++construction_refusals;
        check(world.close()==g::Status::completed);
    }
    // Unmatched requests retain the old inactive record's values, not an
    // invented cold actor. Model/cache admission is a later phase.
    for(unsigned character:{17u,255u}){
        g::World world(profile(),std::make_shared<g::Session>());world.room=87;g::HumanoidMotionOwner motions(world);g::PrimaryActorModels owner(world,motions);auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed);
        const auto old_id=pool.identity_at(0);const auto old_actor=world.resolve(old_id);old_actor->current=456;old_actor->primary=22;old_actor->scripted.emplace();old_actor->model_offset_frame=123;
        const auto old=g::copy_actor_owned(*old_actor);Roster roster;roster.characters=characters;roster.eligible_count=4;const auto before=roster;const Choice choice{0,0,std::uint8_t(character),0,{}};
        const auto made=owner.construct_scene_primary(choice,roster,content);const auto actor=world.resolve(made.id);check(made.status==g::PrimaryModelStatus::completed&&made.release_on_exit&&!made.roster_slot&&!made.retirement_completed&&actor&&actor->current==456&&actor->model_offset_frame==123&&!actor->model);
        compare_construction(*old.actor,*old.actor,*actor,before,roster,choice,world.room,made);++construction_cases;
    }
    // One spare generation is required before publication. Refusal keeps the
    // inactive identity and caller-owned roster intact.
    auto limited=profile();limited.entities.capacity=8;g::World world(limited,std::make_shared<g::Session>());g::HumanoidMotionOwner motions(world);g::PrimaryActorModels owner(world,motions);auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed);
    const auto id=pool.identity_at(0);Roster roster;roster.characters=characters;const auto made=owner.construct_scene_primary({0,0,17,0,{}},roster,content);check(made.status==g::PrimaryModelStatus::full&&!made.id&&pool.identity_at(0)==id&&!world.resolve(id)->active);++construction_refusals;
}
void construction_lifetimes(const char* archive){
    auto source=std::make_shared<reo::assets::Source>(archive);g::ActorAssets assets(source);g::HumanoidMotionAssets content(source);const auto base=content.base();const std::array<std::uint8_t,8> characters{0,1,2,3,4,5,6,7};const auto banks=content.overlay(1,characters,*base);
    using Roster=reo::native::gameplay_scenario::CutscenePrimaryRoster;using Choice=reo::native::gameplay_scenario::CutscenePrimaryChoice;
    for(unsigned model_class:{0u,1u}){
        g::World world(profile(),std::make_shared<g::Session>());world.session().asset_loading_mode=1;g::HumanoidMotionOwner motions(world);check(motions.publish(banks).status==g::HumanoidPublicationStatus::completed);g::PrimaryActorModels owner(world,motions);reo::native::gameplay_update::State state;
        for(unsigned slot:{0u,5u}){auto initial=std::make_unique<g::Actor>();initial->slot=std::uint8_t(slot);initial->character=std::uint8_t(slot);const auto id=world.spawn_primary(slot,std::move(initial)).id;const auto prepared=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);check(owner.apply(*prepared,state).status==g::PrimaryModelStatus::completed);}
        auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed);const auto previous=pool.identity_at(0);Roster roster;roster.characters=characters;roster.eligible_count=4;const Choice choice{0,0,0,std::uint8_t(model_class),0};
        const auto verify=[&](){const auto next=pool.identity_at(0);const auto actor=world.resolve(next);bool complete=world.busy()&&pool.busy()&&next!=previous&&!world.resolve(previous)&&actor&&actor->active&&actor->model&&actor->animation->model()==actor->model&&roster.characters[0]==(model_class?255:0)&&bool(world.primary(0)->model)==!model_class;
            reo::native::gameplay_scenario::CutsceneRosterState held;held.roster.characters.fill(77);complete=complete&&reo::native::gameplay_scenario::CutsceneRosterPreparation::apply(world,held,0)==reo::native::gameplay_scenario::CutsceneRosterStatus::busy&&held.roster.characters[0]==77;
            complete=complete&&owner.construct_scene_primary(choice,roster,content).status==g::PrimaryModelStatus::busy&&owner.close()==g::PrimaryModelStatus::busy&&motions.close()==g::HumanoidPublicationStatus::busy&&pool.close()==g::ScenePrimaryStatus::busy&&world.close()==g::Status::busy;
            if(!complete){std::terminate();}
            ++construction_guards;};
        auto token=std::shared_ptr<int>(new int(1),[&](int* p){delete p;verify();});world.resolve(previous)->model_asset=std::shared_ptr<const g::ActorModelAsset>(token,nullptr);token.reset();
        if(model_class)world.primary(5)->animation->resources[0]=std::shared_ptr<const a::MotionBank>(new a::MotionBank,[&](const a::MotionBank* p){delete p;verify();});
        const auto result=owner.construct_scene_primary(choice,roster,content);check(result.status==g::PrimaryModelStatus::completed&&construction_guards==unsigned(model_class?3:1)&&!world.busy());
    }
    // Resource publication can reject an unrelated incomplete actor. The
    // constructed generation is then an explicit prefix, not a ready scene.
    g::World world(profile(),std::make_shared<g::Session>());world.session().asset_loading_mode=1;g::HumanoidMotionOwner motions(world);check(motions.publish(banks).status==g::HumanoidPublicationStatus::completed);g::PrimaryActorModels owner(world,motions);auto main=std::make_unique<g::Actor>();const auto main_id=world.spawn_primary(0,std::move(main)).id;reo::native::gameplay_update::State state;const auto loaded=g::PrimaryActorModels::prepare(owner.capture(main_id).value(),assets,content);check(owner.apply(*loaded,state).status==g::PrimaryModelStatus::completed);
    const auto main_model=world.resolve(main_id)->model;auto malformed=std::make_unique<g::Actor>();malformed->motion_bank_aliases[0]=g::HumanoidMotionAlias{g::HumanoidMotionFamily::general,0};check(world.spawn_linked(std::move(malformed)).status==g::actors::EntityStatus::completed);
    auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed);const auto old_id=pool.identity_at(0);Roster roster;roster.characters=characters;roster.eligible_count=4;const auto result=owner.construct_scene_primary({0,0,0,1,0},roster,content);
    check(result.status==g::PrimaryModelStatus::unavailable&&result.id&&!result.retirement_completed&&!result.main_model_retired&&pool.identity_at(0)==result.id&&!world.resolve(old_id)&&world.resolve(main_id)->model==main_model&&roster.characters[0]==0&&!owner.capture(result.id)&&!world.busy());++construction_refusals;
}
}
