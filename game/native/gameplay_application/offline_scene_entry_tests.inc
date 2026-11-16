// Actual installed-room VM uses the canonical Update-owned navigation command.
// A zero-neighbor result still reaches812170 and700330. This fixture retains
// the actual Playback and embedded SGL script owners required by that path.
void offline_scene_entry_application(const std::filesystem::path& path){
    namespace navigation=reo::native::gameplay_navigation;
    Notifications notices;auto source=std::make_shared<const reo::assets::Source>(path);
    application::NativeSession host(source,profile(),notices,0);
    check(host.install_room({41,73,0})==application::SessionStatus::completed);
    auto& native=host.world();native.session().room_variants.restore({});
    auto bytes=destination_policy_graph(73);for(unsigned i=0;i<5;++i)bytes[56+12+64*i+1]=0;
    const unsigned directory=56+440;bytes.resize(bytes.size()+8);put_policy(bytes,directory+8*4,64u);
    put_policy(bytes,directory+64,1u);put_policy(bytes,directory+68,0xau);
    std::vector<std::byte> skeleton(112);const auto write=[&](unsigned at,auto value){std::memcpy(skeleton.data()+at,&value,sizeof value);};
    write(4,2u);write(8,112u);write(16,1u);write(20,16u);write(28,1u);write(36,84u);write(48,0xffffffffu);write(52,0xffffffffu);
    for(unsigned at:{88u,92u,96u})write(at,1.f);
    const auto rig=reo::native::animation::Skeleton::import_raw(skeleton);
    navigation::ImportFailure failure;const auto asset=navigation::Asset::read(bytes,failure);check(bool(asset));
    check(native.navigation().bind(std::make_shared<const navigation::Asset>(*asset)));
    for(unsigned i=0;i<3;++i){auto actor=std::make_unique<world::Actor>();actor->active=i<2;actor->slot=std::uint8_t(i);
        actor->model=std::make_shared<reo::native::animation::Instance>(rig);actor->animation=std::make_shared<reo::native::animation::Playback>(actor->model,false);
        actor->room=73;actor->ai_control=std::uint8_t(i!=0);actor->ai_execution.emplace();actor->navigation_route.emplace();
        check(bool(native.spawn_primary(i,std::move(actor)).id));}
    auto actor=native.primary(1);actor->navigation_route->current_node=0;actor->navigation_route->destination_node=4;
    actor->navigation_route->destination_room=99;actor->primary=4;actor->secondary=8;actor->phase=9;actor->subphase=10;
    actor->ai_execution->goal=7;actor->ai_execution->action=8;
    const std::array<unsigned,6> words{1,0x020001a2,1,73,2,0xa};std::vector<std::byte> script(sizeof words);
    std::memcpy(script.data(),words.data(),sizeof words);
    const auto program=std::make_shared<const scenario::Program>(std::vector<std::vector<std::byte>>{script},scenario::DispatchProfile::offline_actor);
    check(!program->unsupported());
    const auto install=[&]{for(unsigned channel=1;channel<=3;++channel)check(host.update().scripts().install(channel,program)==scenario::Status::completed);};
    install();check(host.step_room_script().status==application::SessionStatus::completed);++script_steps;
    check(actor->room==73&&actor->position.x==200&&actor->position.y==0&&actor->position.z==300&&actor->navigation_route->current_node==2);
    check(actor->navigation_route->destination_node==4&&actor->navigation_route->destination_room==99);
    check(actor->ai_execution->goal==0&&actor->ai_execution->previous_goal==7&&actor->ai_execution->action==0&&actor->ai_execution->previous_action==8);
    check(actor->primary==1&&actor->secondary==0&&actor->phase==0&&actor->subphase==0&&actor->animation->motion==0);
    check(host.update().scripts().channels()[2].block_index==8&&host.update().scripts().channels()[2].program);
    // Full room/node words are checked before the first published store.
    const auto old_position=actor->position;
    check(host.update().actor_offline_navigation().command(1,65536u+73,2)==scenario::OfflineNavigationStatus::unavailable);
    check(actor->room==73&&actor->position.x==old_position.x&&actor->position.y==old_position.y&&actor->position.z==old_position.z);
    actor->active=false;check(host.update().actor_offline_navigation().command(1,0xffffffffu,0xffffffffu)==scenario::OfflineNavigationStatus::completed);
    actor->active=true;actor->ai_control=0;check(host.update().actor_offline_navigation().command(1,0xffffffffu,0xffffffffu)==scenario::OfflineNavigationStatus::completed);
    actor->ai_control=1;
    scenario::Interpreter orphan;check(orphan.install(1,program)==scenario::Status::completed);
    scenario::Providers missing;missing.world=&native;missing.flags=&host.update().flags();missing.canonical_flags=&host.update().flags();
    check(orphan.tick_offline_channel(1,{true,false,0,73},{0,0,73},missing).status==scenario::Status::provider_unavailable);
    check(!host.update().clock().update_counter()&&host.close()==application::SessionStatus::completed);
}
