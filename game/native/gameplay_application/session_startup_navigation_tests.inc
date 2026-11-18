// Controlled EVB continuation: full closure remains admitted while graph state
// is supplied between entry1 and entry2, as5EB520/68C890/1D3F60 order it.
void navigation_startup_ordering(){
    Notifications notes;auto state=std::make_shared<w::Session>();w::World world(profile(),state);u::Owner owner(world,notes);
    world.mode=0;world.room=7;state->room_variants.restore({});check(world.navigation().initialize_cold_empty());
    std::vector<std::byte> skeleton(112);
    const auto put=[&](auto& bytes,std::size_t at,const auto& value){check(at+sizeof value<=bytes.size());std::memcpy(bytes.data()+at,&value,sizeof value);};
    for(const auto& [at,value]:std::array<std::pair<unsigned,unsigned>,8>{{{4,2},{8,112},{16,1},{20,16},{28,1},{36,84},{48,UINT32_MAX},{52,UINT32_MAX}}})put(skeleton,at,value);
    for(const auto at:{88u,92u,96u})put(skeleton,at,1.f);
    const auto rig=reo::native::animation::Skeleton::import_raw(skeleton);
    auto actor=std::make_unique<w::Actor>();actor->slot=3;actor->active=true;actor->ai_control=1;actor->room=9;actor->position={9,8,7};
    actor->ai_execution.emplace();actor->ai_execution->goal=17;actor->ai_execution->action=23;actor->navigation_route.emplace();
    actor->model=std::make_shared<reo::native::animation::Instance>(rig);actor->animation=std::make_shared<reo::native::animation::Playback>(actor->model,false);actor->animation->motion=77;
    check(bool(world.spawn_primary(3,std::move(actor)).id));const auto retained=world.primary(3);
    std::vector<std::byte> evb(180);put(evb,4,128u);put(evb,8,140u);
    const std::array<std::uint32_t,3> first{0x01000044,37,0xd};std::memcpy(evb.data()+128,first.data(),sizeof first);
    const std::array<std::uint32_t,10> later{1,0x020001a0,7,0,1,0x020001a2,3,7,0,0xa};std::memcpy(evb.data()+140,later.data(),sizeof later);
    const auto closure=s::content::admit_script_program(s::content::ScriptBank(std::make_shared<const std::vector<std::byte>>(evb),s::content::BankFormat::scenario_evb),s::DispatchProfile::offline_actor,s::content::ScriptRoots::scenario_startup);
    check(closure.status==s::content::ScriptAdmission::admitted&&closure.program&&closure.program->record({2,4})->opcode==0x1a0&&closure.program->record({2,20})->opcode==0x1a2);
    auto& vm=owner.scripts();check(vm.install(0,closure.program,{1,0})==s::Status::completed);
    s::Providers providers;providers.world=&world;providers.flags=providers.canonical_flags=&owner.flags();providers.actor_offline_navigation=&owner.actor_offline_navigation();
    const auto tick=[&]{return vm.tick_offline_channel(0,{true,false,0,7},{0,0,7},providers);};
    const auto first_pass=tick();check(first_pass.status==s::Status::yielded&&first_pass.operations==2&&vm.channels()[0].current==s::Position{2,0}&&owner.flags().get(s::FlagBank::bounded_byte,37)==true);
    const auto policy_refusal=tick();check(policy_refusal.status==s::Status::provider_unavailable&&policy_refusal.opcode==0x1a0&&policy_refusal.position==s::Position{2,4});
    check(retained->room==9&&retained->position.x==9&&retained->ai_execution->goal==17&&retained->ai_execution->action==23&&!world.navigation().bound());
    auto channel=vm.channels()[0];channel.current={2,20};check(vm.restore_channel(0,channel)==s::Status::completed);
    const auto movement_refusal=tick();check(movement_refusal.status==s::Status::provider_unavailable&&movement_refusal.opcode==0x1a2&&movement_refusal.position==s::Position{2,20});
    check(retained->room==9&&retained->position.x==9&&retained->animation->motion==77);
    // A real typed SGL publication, with one valid node and no edge/script,
    // supplies the exact dependency without a successful callback replacement.
    std::vector<std::uint8_t> graph(184);put(graph,0,0x20030724u);put(graph,4,12u);put(graph,8,16u);put(graph,16,1u);put(graph,20,std::uint16_t(7));put(graph,24,32u);
    put(graph,32,80u);put(graph,36,88u);put(graph,40,1u);graph[44]=1;put(graph,56,300.f);put(graph,60,UINT32_MAX);std::fill_n(graph.begin()+108,4,255);
    reo::native::gameplay_navigation::ImportFailure error;const auto parsed=reo::native::gameplay_navigation::Asset::read(graph,error);check(bool(parsed));
    check(world.navigation().bind(std::make_shared<const reo::native::gameplay_navigation::Asset>(*parsed)));
    channel=vm.channels()[0];channel.current={2,4};check(vm.restore_channel(0,channel)==s::Status::completed);
    const auto second_pass=tick();check(second_pass.status==s::Status::yielded&&world.navigation().descriptor_policy(7,0)==1);
    check(retained->room==7&&retained->position.x==0&&retained->position.y==0&&retained->position.z==300&&retained->navigation_route->current_node==0&&retained->navigation_route->refresh==1&&retained->animation->motion==0);
    check(retained->ai_execution->goal==0&&retained->ai_execution->action==0);
    providers.actor_offline_navigation=nullptr;check(tick().status==s::Status::provider_unavailable);
    check(owner.close()==u::Status::completed);check(world.close()==w::Status::completed);
}
