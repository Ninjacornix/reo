namespace {
void resident_ownership(const char* archive){
    auto source=std::make_shared<reo::assets::Source>(archive);g::ActorAssets assets(source);g::HumanoidMotionAssets content(source);
    const auto base=content.ensure_base(content.initial_banks(false));const std::array<std::uint8_t,1> characters{0};const auto banks=content.overlay(1,characters,*base);
    for(unsigned slot=0;slot<8;++slot)for(bool retain_lease:{false,true}){
        g::World world(profile(),std::make_shared<g::Session>());world.session().asset_loading_mode=1;
        g::HumanoidMotionOwner motions(world);check(motions.publish(banks).status==g::HumanoidPublicationStatus::completed);
        g::PrimaryActorModels owner(world,motions);g::actors::EntityId id;std::weak_ptr<const a::Instance> weak;
        bool destroyed{};g::PrimaryModelResources held;
        {
            auto initial=std::make_unique<g::Actor>();initial->slot=std::uint8_t(slot);
            id=world.spawn_primary(slot,std::move(initial)).id;
            const auto prepared=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);
            check(owner.apply(*prepared,{}).status==g::PrimaryModelStatus::completed);
            const auto actor=world.resolve(id);const auto resident=owner.resident(slot);
            check(resident.asset==actor->model_asset&&resident.primary==actor->model&&resident.secondary==actor->animation->secondary_model());
            actor->model->local_translation(0,{12,34,56});check(resident.primary->local_translation(0).y==34);
            weak=resident.primary;if(retain_lease)held=resident;
            if(!retain_lease){
                unsigned track_nodes{};for(const auto& node:actor->model->skeleton().nodes())track_nodes+=node.track==0;
                std::shared_ptr<const a::Clip> clip;
                for(unsigned key=0;key<2000&&!clip;++key){
                    const auto block=banks->scripted().other_modes->find(key,0);if(!block)continue;
                    try{auto candidate=block->clip();if(candidate->tracks().size()==track_nodes)clip=std::move(candidate);}catch(const std::invalid_argument&){}
                }
                check(bool(clip));
                auto observed=std::shared_ptr<const a::Clip>(clip.get(),[clip,&owner,&world,&destroyed,slot](const a::Clip*){
                    if(!world.busy()||owner.close()!=g::PrimaryModelStatus::busy||world.close()!=g::Status::busy||
                       owner.resident(slot).primary||owner.key(slot)!=g::PrimaryActorModels::CacheKey{})std::terminate();
                    destroyed=true;++resident_close_guards;
                });
                actor->model->bind(0,std::move(observed));
            }
        }
        check(world.retire_primary(slot)==g::actors::EntityStatus::completed&&!world.resolve(id)&&!weak.expired());
        check(owner.resident(slot).primary->local_translation(0).z==56);++resident_lifetimes;
        auto replacement=std::make_unique<g::Actor>();replacement->slot=std::uint8_t(slot);
        const auto next=world.spawn_primary(slot,std::move(replacement)).id;
        check(next!=id&&!owner.capture(next)&&!owner.capture_release(next)&&!owner.capture(id));++resident_stale_refusals;
        check(owner.close()==g::PrimaryModelStatus::completed&&!owner.resident(slot).primary&&!owner.resident(slot).asset);
        check(weak.expired()==!retain_lease&&destroyed==!retain_lease);
        if(retain_lease){check(held.primary->local_translation(0).x==12&&held.asset);held={};check(weak.expired());++resident_retained_leases;}
        check(world.close()==g::Status::completed);
    }
    // A failed initializer leaves an owned physical-work prefix even though
    // the cache key has not committed. A new generation cannot adopt it.
    g::World world(profile(),std::make_shared<g::Session>());world.session().asset_loading_mode=1;
    world.session().primary_initialization_snapshot.emplace();(*world.session().primary_initialization_snapshot)[0].selected_resource=1;
    g::HumanoidMotionOwner motions(world);check(motions.publish(banks).status==g::HumanoidPublicationStatus::completed);
    g::PrimaryActorModels owner(world,motions);const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;
    {
        const auto prepared=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);const auto result=owner.apply(*prepared,{});
        check(result.status==g::PrimaryModelStatus::unavailable&&result.replaced&&!result.initialized&&owner.key(0)==g::PrimaryActorModels::CacheKey{});
        check(owner.resident(0).primary==world.resolve(id)->model&&owner.resident(0).asset==world.resolve(id)->model_asset);++resident_prefixes;
    }
    const std::weak_ptr<const a::Instance> weak=owner.resident(0).primary;
    check(world.retire_primary(0)==g::actors::EntityStatus::completed&&!weak.expired());
    const auto next=world.spawn_primary(0,std::make_unique<g::Actor>()).id;
    check(!owner.capture(next)&&!owner.capture_release(next));++resident_stale_refusals;
    check(owner.close()==g::PrimaryModelStatus::completed&&weak.expired()&&world.close()==g::Status::completed);
}
}
