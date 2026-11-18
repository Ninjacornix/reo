namespace {
void owned_scenes(const char* archive,const char* manifest){
    namespace s=reo::native::gameplay_scenario;
    auto source=std::make_shared<reo::assets::Source>(archive);g::ActorAssets assets(source);g::HumanoidMotionAssets content(source);s::content::ScenarioArchive input(source);
    const auto base=content.base();const std::array<std::uint8_t,8> characters{0,1,2,3,4,5,6,7};const auto banks=content.overlay(1,characters,*base);
    std::ifstream rows(manifest);check(bool(rows));unsigned scenario,sequence,variant,suffix,version;
    while(rows>>scenario>>sequence>>variant>>suffix>>version){
        if(version!=950)continue;
        const auto descriptor=s::read_cutscene_descriptor(input,std::uint16_t(scenario),std::uint8_t(sequence),std::uint8_t(variant),std::uint8_t(suffix));check(bool(descriptor));
        for(std::size_t group=0;group<descriptor->actor_groups().size();++group){
            const auto bytes=descriptor->section(descriptor->actor_groups()[group][7]);check(bytes.size()>=36);
            std::uint16_t active,identity;std::int16_t kind,definition;std::uint32_t scale,mask;
            std::memcpy(&active,bytes.data()+2,2);std::memcpy(&kind,bytes.data()+4,2);std::memcpy(&identity,bytes.data()+6,2);std::memcpy(&definition,bytes.data()+10,2);std::memcpy(&scale,bytes.data()+20,4);std::memcpy(&mask,bytes.data()+24,4);
            if(active==65535||(kind!=0&&kind!=3))continue;
            // The earlier roster-assignment phase is outside this adapter.
            // Bind one controlled canonical primary; do not claim that header6
            // alone determines the actor chosen by complete5F0DC0.
            const auto character=std::uint8_t(identity<8?identity:0),model_class=std::uint8_t(definition^1);
            for(std::int8_t pause:{std::int8_t(0),std::int8_t(1)}){
                g::World world(profile(),std::make_shared<g::Session>());world.paused=pause;world.room=0x1234;world.session().asset_loading_mode=1;
                g::HumanoidMotionOwner motions(world);check(motions.publish(banks).status==g::HumanoidPublicationStatus::completed);g::PrimaryActorModels models(world,motions);
                auto initial=std::make_unique<g::Actor>();initial->slot=0;initial->character=character;initial->model_pose_class=model_class;initial->appearance_variant=1;initial->movement_enabled=0;initial->scripted.emplace();initial->scripted->cue_phase=5;
                const auto id=world.spawn_primary(0,std::move(initial)).id;const auto actor=world.resolve(id);reo::native::gameplay_update::State state;
                for(unsigned pass=0;pass<2;++pass){
                    actor->appearance_variant=1;actor->movement_enabled=0;actor->room=0x1111;
                    const auto request=models.capture_scene(id,*descriptor,group);check(bool(request));const auto prepared=g::PrimaryActorModels::prepare(*request,assets,content);
                    check(actor->appearance_variant==1&&actor->room==0x1111&&!actor->movement_enabled);
                    world.room=0x5678;const auto result=models.apply(*prepared,state);
                    check(result.status==g::PrimaryModelStatus::completed&&result.initialized&&result.replaced==(pass==0));
                    check(actor->appearance_variant==0&&actor->movement_enabled==1&&actor->room==world.room&&actor->scripted->cue_phase==5&&actor->scripted->scale_profile==std::uint8_t(scale));
                    check(actor->model_asset->name()==g::ActorAssets::primary_model_name(character,0,model_class));
                    check(actor->primary_state->part_visibility.size()==actor->model_asset->part_count());
                    for(unsigned part=0;part<actor->model_asset->part_count();++part)check(actor->primary_state->part_visibility[part]==((mask>>part)&1u));
                    const auto expected=std::uint8_t(scale)?g::primary_actor_default(character).scale:g::Position{1,1,1};check(std::memcmp(&actor->model_scale,&expected,sizeof expected)==0);
                    const auto parameters=descriptor->actor_parameters(group);check(prepared->scene_parameters().size()==parameters.size());
                    for(std::size_t i=0;i<parameters.size();++i)check(parameters[i].key==prepared->scene_parameters()[i].key&&parameters[i].value==prepared->scene_parameters()[i].value);
                    compare_primary_scene(*descriptor,group,*actor,prepared->scene_parameters(),world.room,pause);scene_parameters+=parameters.size();++scene_cases;if(kind==3)++scene_kind_three_cases;
                }
                check(models.close()==g::PrimaryModelStatus::completed&&motions.close()==g::HumanoidPublicationStatus::completed&&world.close()==g::Status::completed);
            }
        }
    }
    check(rows.eof()&&scene_cases>0);
}
}
