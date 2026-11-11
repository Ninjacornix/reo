namespace {
void scene_scopes(const char* archive,const char* manifest){
    namespace s=reo::native::gameplay_scenario;
    auto source=std::make_shared<reo::assets::Source>(archive);g::ActorAssets assets(source);g::HumanoidMotionAssets content(source);s::content::ScenarioArchive input(source);
    const auto base=content.ensure_base(content.initial_banks(false));const std::array<std::uint8_t,8> characters{0,1,2,3,4,5,6,7};const auto banks=content.overlay(1,characters,*base);
    struct Case {std::shared_ptr<const s::CutsceneDescriptor> descriptor;std::size_t group;unsigned character,model_class;};
    std::vector<Case> cases;std::array<unsigned,2> counts{};std::ifstream rows(manifest);check(bool(rows));unsigned scenario,sequence,variant,suffix,version;
    while(rows>>scenario>>sequence>>variant>>suffix>>version){
        if(version!=950)continue;
        const auto descriptor=s::read_cutscene_descriptor(input,std::uint16_t(scenario),std::uint8_t(sequence),std::uint8_t(variant),std::uint8_t(suffix));check(bool(descriptor));
        for(std::size_t group=0;group<std::min<std::size_t>(16,descriptor->actor_groups().size());++group){
            const auto header=descriptor->section(descriptor->actor_groups()[group][7]);std::uint16_t active,identity;std::int16_t kind,definition;
            std::memcpy(&active,header.data()+2,2);std::memcpy(&kind,header.data()+4,2);std::memcpy(&identity,header.data()+6,2);std::memcpy(&definition,header.data()+10,2);
            const auto model_class=unsigned(std::uint8_t(definition^1));
            if(active==65535||kind!=0||model_class>1||counts[model_class]>=8)continue;
            cases.push_back({descriptor,group,identity<8?unsigned(identity):0u,model_class});++counts[model_class];
        }
    }
    check(rows.eof()&&counts[0]==8&&counts[1]==8);
    for(const auto& item:cases)for(unsigned source_slot:{0u,5u})for(unsigned paused:{0u,1u}){
        g::World world(profile(),std::make_shared<g::Session>());world.room=0x1234;world.paused=std::int8_t(paused);world.session().asset_loading_mode=1;
        g::HumanoidMotionOwner motions(world);check(motions.publish(banks).status==g::HumanoidPublicationStatus::completed);g::PrimaryActorModels owner(world,motions);
        for(unsigned slot:{0u,5u}){
            auto initial=std::make_unique<g::Actor>();initial->slot=std::uint8_t(slot);initial->character=std::uint8_t(item.character);
            const auto id=world.spawn_primary(slot,std::move(initial)).id;const auto prepared=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);
            check(owner.apply(*prepared,{}).status==g::PrimaryModelStatus::completed);
            const auto actor=world.resolve(id);actor->model->local_translation(0,{slot?99.f:12.f,34,56});actor->animation->channel(a::ModelBank::primary,0).selector=std::uint16_t(slot?95:70);
        }
        auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed);
        s::CutscenePrimaryRoster roster;roster.characters.fill(255);roster.characters[source_slot]=std::uint8_t(item.character);roster.eligible_count=1;
        const s::CutscenePrimaryChoice choice{std::uint8_t(item.group),0,std::uint8_t(item.character),std::uint8_t(item.model_class),std::uint8_t(source_slot)};
        const auto constructed=owner.construct_scene_primary(choice,roster,content);check(constructed.status==g::PrimaryModelStatus::completed&&constructed.release_on_exit==bool(item.model_class));
        const auto temporary=world.resolve(constructed.id);check(temporary&&temporary->slot==0&&!owner.capture(constructed.id));
        const auto main=world.primary(0);const auto main_model=main->model;const auto pending=g::PrimaryActorModels::prepare(owner.capture(world.identity(0)).value(),assets,content);
        const auto scope=owner.open_scene_models();check(scope.has_value()&&!owner.open_scene_models()&&!owner.capture(world.identity(0)));
        check(owner.apply(*pending,{}).status==g::PrimaryModelStatus::stale&&!owner.capture_scene(g::PrimarySceneModelScope{},constructed.id,*item.descriptor,item.group));++scene_scope_refusals;
        check(!owner.capture_scene(*scope,constructed.id,*item.descriptor,item.group+1));++scene_scope_refusals;
        const auto expected_class=temporary->model_pose_class;temporary->model_pose_class^=1;
        check(!owner.capture_scene(*scope,constructed.id,*item.descriptor,item.group));temporary->model_pose_class=expected_class;++scene_scope_refusals;
        check(g::initialize_primary_slot(world,constructed.id,std::uint8_t(item.character),*motions.snapshot())==g::PrimaryInitializationStatus::unavailable);++scene_scope_refusals;
        const auto request=owner.capture_scene(*scope,constructed.id,*item.descriptor,item.group);check(request.has_value());
        const auto prepared=g::PrimaryActorModels::prepare(*request,assets,content);const auto before=keys(owner);const auto before_model=temporary->model;
        if(!paused){reo::native::gameplay_update::State restore;restore.notification_pending=1;const auto denied=owner.apply(*prepared,restore);check(denied.status==g::PrimaryModelStatus::unavailable&&temporary->model==before_model&&keys(owner)==before);++scene_scope_refusals;}
        reo::native::gameplay_update::State state;state.notification_pending=std::uint8_t(paused);
        const auto applied=owner.apply(*prepared,state);check(applied.status==g::PrimaryModelStatus::completed&&applied.initialized&&applied.rebound);
        compare_cache(before,keys(owner),0,std::uint8_t(item.character),std::uint8_t(item.model_class),1,world.paused,applied);++scene_scope_cache_cases;
        check(temporary->model==owner.resident(0).primary&&temporary->animation->model()==temporary->model&&temporary->model!=main_model&&temporary->primary_state&&temporary->motion_bank_aliases[2]->character==item.character);
        if(!item.model_class){check(!applied.replaced&&!applied.character_released&&temporary->model->local_translation(0).x==12);++scene_scope_reuses;}
        else{check(applied.replaced);++scene_scope_rebuilds;}
        check(temporary->animation->channel(a::ModelBank::primary,0).selector==(source_slot?95:70));
        temporary->model->local_translation(0,{321,654,987});const auto retained=owner.resident(0);
        check(owner.return_scene_models(*scope)==g::PrimaryModelStatus::unavailable&&owner.release_scene_model(*scope,0,content).status==g::PrimaryModelStatus::unavailable);++scene_scope_refusals;
        check(pool.initialize()==g::ScenePrimaryStatus::model_in_use);
        const auto tables=content.release_scene_tables(*motions.snapshot());
        check(motions.publish(tables).status==g::HumanoidPublicationStatus::completed&&temporary->animation->resources[1]->cleared()&&tables->scripted().other_modes->cleared());
        check(owner.apply(*prepared,{}).status==g::PrimaryModelStatus::stale);++scene_scope_bank_cleanups;
        bool reset_observed{};
        auto reset_token=std::shared_ptr<int>(new int(1),[&](int* p){
            delete p;
            if(!world.busy()||!pool.busy()||pool.identity_at(0)==constructed.id||world.resolve(constructed.id)||
               owner.resident(0).primary!=retained.primary||owner.reset_scene_actors(*scope)!=g::PrimaryModelStatus::busy||
               owner.return_scene_models(*scope)!=g::PrimaryModelStatus::busy||owner.close()!=g::PrimaryModelStatus::busy)std::terminate();
            reset_observed=true;++scene_scope_guards;
        });
        world.resolve(pool.identity_at(7))->model_asset=std::shared_ptr<const g::ActorModelAsset>(reset_token,nullptr);reset_token.reset();
        check(owner.reset_scene_actors(*scope)==g::PrimaryModelStatus::completed&&!world.resolve(constructed.id)&&pool.identity_at(0)!=constructed.id&&owner.resident(0).primary==retained.primary);++scene_scope_resets;
        check(reset_observed);
        check(!world.resolve(pool.identity_at(0))->active&&!owner.capture_scene(*scope,constructed.id,*item.descriptor,item.group));
        check(owner.reset_scene_actors(*scope)==g::PrimaryModelStatus::completed);
        if(constructed.release_on_exit){
            check(owner.return_scene_models(*scope)==g::PrimaryModelStatus::unavailable);++scene_scope_refusals;
            bool release_observed{};
            world.primary(5)->animation->resources[0]=std::shared_ptr<const a::MotionBank>(new a::MotionBank,[&](const a::MotionBank* bank){
                delete bank;
                if(!world.busy()||owner.resident(0).primary||owner.release_scene_model(*scope,0,content).status!=g::PrimaryModelStatus::busy||
                   owner.return_scene_models(*scope)!=g::PrimaryModelStatus::busy||motions.close()!=g::HumanoidPublicationStatus::busy)std::terminate();
                release_observed=true;++scene_scope_guards;
            });
            const auto release_before=keys(owner);const auto released=owner.release_scene_model(*scope,0,content);check(release_observed);
            check(released.status==g::PrimaryModelStatus::completed&&released.retired&&released.character_released&&!owner.resident(0).primary);
            compare_release(release_before,keys(owner),0,released);++scene_scope_releases;
            const auto empty=keys(owner);const auto repeated=owner.release_scene_model(*scope,0,content);check(repeated.status==g::PrimaryModelStatus::completed&&!repeated.retired);compare_release(empty,keys(owner),0,repeated);
        }else check(owner.release_scene_model(*scope,0,content).status==g::PrimaryModelStatus::unavailable);
        check(owner.return_scene_models(*scope)==g::PrimaryModelStatus::completed&&!world.busy());++scene_scope_returns;
        check(owner.return_scene_models(*scope)==g::PrimaryModelStatus::stale&&owner.reset_scene_actors(*scope)==g::PrimaryModelStatus::stale&&owner.release_scene_model(*scope,0,content).status==g::PrimaryModelStatus::stale);++scene_scope_refusals;
        if(!item.model_class){check(main->model&&main->model!=retained.primary&&main->model->local_translation(0).x==321);check(temporary->model==retained.primary&&retained.primary->local_translation(0).x==321);}
        const auto defaults=content.ensure_base(motions.snapshot());
        check(motions.publish(defaults).status==g::HumanoidPublicationStatus::completed&&defaults->base_loaded());
        const std::array<std::uint8_t,1> returning_characters{std::uint8_t(item.character)};
        const auto returning_banks=content.overlay(1,returning_characters,*defaults);
        check(motions.publish(returning_banks).status==g::HumanoidPublicationStatus::completed&&!returning_banks->character(item.character)->cleared());++scene_scope_bank_restorations;
        for(unsigned slot:{0u,5u}){
            const auto actor=world.primary(slot);check(actor->animation->channel(a::ModelBank::primary,0).selector==(slot?95:70));
            const auto reinitialize=g::PrimaryActorModels::prepare(owner.capture(world.identity(slot)).value(),assets,content);
            check(owner.apply(*reinitialize,{}).status==g::PrimaryModelStatus::completed&&actor->model&&actor->primary_state);++scene_scope_reinitializations;
        }
        check(owner.close()==g::PrimaryModelStatus::completed&&world.close()==g::Status::completed);
    }
    const auto& sample=cases.front();
    // Insufficient spare generations cannot reset or partially retire the old
    // actor/model set. Existing independent physical resources stay owned.
    {
        auto limited=profile();limited.entities.capacity=11;g::World world(limited,std::make_shared<g::Session>());world.session().asset_loading_mode=1;
        g::HumanoidMotionOwner motions(world);check(motions.publish(banks).status==g::HumanoidPublicationStatus::completed);g::PrimaryActorModels owner(world,motions);
        for(unsigned slot:{0u,5u}){auto initial=std::make_unique<g::Actor>();initial->slot=std::uint8_t(slot);initial->character=std::uint8_t(sample.character);const auto id=world.spawn_primary(slot,std::move(initial)).id;const auto prepared=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);check(owner.apply(*prepared,{}).status==g::PrimaryModelStatus::completed);}
        auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed);
        s::CutscenePrimaryRoster roster;roster.characters.fill(255);roster.characters[0]=std::uint8_t(sample.character);roster.eligible_count=1;
        const auto made=owner.construct_scene_primary({std::uint8_t(sample.group),0,std::uint8_t(sample.character),std::uint8_t(sample.model_class),0},roster,content);check(made.status==g::PrimaryModelStatus::completed);
        const auto scope=owner.open_scene_models();check(scope.has_value());const auto prepared=g::PrimaryActorModels::prepare(owner.capture_scene(*scope,made.id,*sample.descriptor,sample.group).value(),assets,content);check(owner.apply(*prepared,{}).status==g::PrimaryModelStatus::completed);
        std::array<g::actors::EntityId,8> before;for(unsigned i=0;i<8;++i)before[i]=pool.identity_at(i);const auto resource=owner.resident(0);
        check(owner.reset_scene_actors(*scope)==g::PrimaryModelStatus::full&&!world.busy()&&owner.resident(0).primary==resource.primary);
        for(unsigned i=0;i<8;++i){check(before[i]==pool.identity_at(i)&&world.resolve(before[i]));}
        ++scene_scope_capacity_refusals;
        check(owner.close()==g::PrimaryModelStatus::completed&&world.close()==g::Status::completed);
    }
    // No canonical animation capability is manufactured for an absent or
    // uninitialized inactive main Actor during return from an unmatched scene.
    for(bool inactive_main:{false,true}){
        g::World world(profile(),std::make_shared<g::Session>());world.session().asset_loading_mode=1;g::HumanoidMotionOwner motions(world);check(motions.publish(banks).status==g::HumanoidPublicationStatus::completed);g::PrimaryActorModels owner(world,motions);
        if(inactive_main)check(bool(world.spawn_primary(0,std::make_unique<g::Actor>()).id));
        auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed);s::CutscenePrimaryRoster roster;roster.characters.fill(255);
        const auto made=owner.construct_scene_primary({std::uint8_t(sample.group),0,std::uint8_t(sample.character),std::uint8_t(sample.model_class),{}},roster,content);check(made.status==g::PrimaryModelStatus::completed&&made.release_on_exit);
        const auto scope=owner.open_scene_models();check(scope.has_value());const auto prepared=g::PrimaryActorModels::prepare(owner.capture_scene(*scope,made.id,*sample.descriptor,sample.group).value(),assets,content);check(owner.apply(*prepared,{}).status==g::PrimaryModelStatus::completed);
        check(owner.reset_scene_actors(*scope)==g::PrimaryModelStatus::completed&&owner.release_scene_model(*scope,0,content).status==g::PrimaryModelStatus::completed&&owner.return_scene_models(*scope)==g::PrimaryModelStatus::completed);
        const auto main=world.primary(0);check(inactive_main?main&&!main->active&&!main->model&&!main->animation&&!main->primary_state:!main);++scene_scope_absent_returns;
        check(owner.close()==g::PrimaryModelStatus::completed&&world.close()==g::Status::completed);
    }
}
}
