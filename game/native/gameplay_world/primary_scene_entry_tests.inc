namespace {
std::array<std::uint8_t,8> visibility(const g::World& world){
    std::array<std::uint8_t,8> result{};for(unsigned slot=0;slot<8;++slot)if(const auto actor=world.primary(slot))result[slot]=actor->visible;return result;
}
void owned_entry(const char* archive){
    auto source=std::make_shared<reo::assets::Source>(archive);g::ActorAssets assets(source);g::HumanoidMotionAssets content(source);
    const auto base=content.base();const std::array<std::uint8_t,8> characters{0,1,2,3,4,5,6,7};const auto banks=content.overlay(1,characters,*base);
    for(unsigned mask=0;mask<16;++mask)for(unsigned rotation=0;rotation<4;++rotation)for(unsigned loading=0;loading<3;++loading){
        g::World world(profile(),std::make_shared<g::Session>());world.session().asset_loading_mode=1;
        g::HumanoidMotionOwner motions(world);check(motions.publish(banks).status==g::HumanoidPublicationStatus::completed);g::PrimaryActorModels models(world,motions);
        reo::native::gameplay_update::State state;std::array<std::shared_ptr<a::Instance>,8> previous_models;
        for(unsigned slot=0;slot<8;++slot){
            auto initial=std::make_unique<g::Actor>();initial->slot=std::uint8_t(slot);initial->character=std::uint8_t((slot+rotation)%8);initial->model_pose_class=std::uint8_t((slot+rotation)%2);initial->visible=true;
            const auto id=world.spawn_primary(slot,std::move(initial)).id;const auto actor=world.resolve(id);
            if(slot<4&&!(mask&(1u<<slot)))continue;
            const auto prepared=g::PrimaryActorModels::prepare(models.capture(id).value(),assets,content);check(models.apply(*prepared,state).status==g::PrimaryModelStatus::completed);
            actor->animation->channel(a::ModelBank::primary,0).timing.frame=5.5f;a::PoseBlend::root_reference(*actor->model,{float(slot),3,7});previous_models[slot]=actor->model;
        }
        if(loading==0)world.session().asset_loading_mode.reset();else world.session().asset_loading_mode=loading==1?0:128;
        bool retired_lease{};const auto retained_extra=world.primary(5)->model;
        world.primary(5)->animation->resources[0]=std::shared_ptr<const a::MotionBank>(new a::MotionBank,[&](const a::MotionBank* bank){
            bool complete=world.busy()&&models.close()==g::PrimaryModelStatus::busy&&motions.close()==g::HumanoidPublicationStatus::busy&&world.close()==g::Status::busy&&models.release_scene_entry(content).status==g::PrimaryModelStatus::busy&&motions.snapshot()&&!motions.snapshot()->base_loaded()&&world.primary(5)->model==retained_extra;
            for(unsigned slot=0;slot<4;++slot)complete=complete&&models.key(slot)==g::PrimaryActorModels::CacheKey{}&&!world.primary(slot)->model;
            if(!complete){std::terminate();}
            retired_lease=true;delete bank;
        });
        for(unsigned pass=0;pass<2;++pass){
            const auto before=keys(models);const auto before_visible=visibility(world);const auto released=models.release_scene_entry(content);
            check(released.status==g::PrimaryModelStatus::completed&&released.visited==4&&released.base_released&&!released.failed_slot&&!world.busy()&&!motions.snapshot()->base_loaded());
            const auto expected=pass?0u:unsigned(std::popcount(mask));check(released.retired==expected&&released.character_releases==expected);
            for(unsigned slot=0;slot<8;++slot){
                const auto actor=world.primary(slot);
                if(slot<4){check(models.key(slot)==g::PrimaryActorModels::CacheKey{}&&!actor->model);if(mask&(1u<<slot)){const auto root=actor->animation->root_reference();check(actor->animation->channel(a::ModelBank::primary,0).timing.frame==5.5f&&root.x==float(slot)&&root.y==3&&root.z==7&&!actor->visible);}}
                else check(models.key(slot)==before[slot]&&actor->model==previous_models[slot]&&actor->visible);
            }
            compare_entry(before,keys(models),before_visible,visibility(world),released);entry_retirements+=released.retired;++entry_cases;
        }
        check(retired_lease);++entry_guard_checks;
        check(models.close()==g::PrimaryModelStatus::completed&&models.release_scene_entry(content).status==g::PrimaryModelStatus::closed&&motions.close()==g::HumanoidPublicationStatus::completed&&world.close()==g::Status::completed);
    }
    g::World empty(profile(),std::make_shared<g::Session>());g::HumanoidMotionOwner motions(empty);check(motions.publish(base).status==g::HumanoidPublicationStatus::completed);g::PrimaryActorModels models(empty,motions);
    const auto before=keys(models);const auto visible=visibility(empty);const auto released=models.release_scene_entry(content);check(released.status==g::PrimaryModelStatus::completed&&released.visited==4&&released.retired==0&&released.base_released);compare_entry(before,keys(models),visible,visibility(empty),released);++entry_cases;
}
}
