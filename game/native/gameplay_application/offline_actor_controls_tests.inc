// Real application VM paths with controlled SGL and canonical actor/flag owners.
void offline_actor_controls_application(const std::filesystem::path& path){
    namespace navigation=reo::native::gameplay_navigation;
    auto source=std::make_shared<const reo::assets::Source>(path);Notifications notices;
    application::NativeSession host(source,profile(),notices,0);
    check(host.install_room({41,73,0})==application::SessionStatus::completed);
    auto& native=host.world();native.session().room_variants.restore({});
    navigation::ImportFailure failure;const auto parsed=navigation::Asset::read(destination_policy_graph(73),failure);check(bool(parsed));
    check(native.navigation().bind(std::make_shared<const navigation::Asset>(*parsed)));
    for(unsigned i=0;i<3;++i){auto actor=std::make_unique<world::Actor>();actor->active=i<2;actor->slot=std::uint8_t(i);
        actor->room=73;actor->ai_control=std::uint8_t(i!=0);actor->ai_execution.emplace();actor->navigation_route.emplace();
        actor->position={200,0,300};actor->navigation_route->current_node=2;check(bool(native.spawn_primary(i,std::move(actor)).id));}
    auto actor=native.primary(1);actor->status=0x5e0; // These commands do not use666080 exclusion.
    auto& state=*actor->ai_execution;state.goal=7;state.action=8;state.forced_content=99;state.forced_priority=-1;
    check(host.update().flags().actor_flag(scenario::ActorFlagFamily::primary,{false,1},19,true));
    const auto emit=[](std::vector<std::byte>& bytes,unsigned op,std::initializer_list<unsigned> values){
        unsigned shift{},words=1;while(words<1+values.size()){words*=2;++shift;}
        const auto begin=bytes.size();bytes.resize(begin+4*words);const auto header=op|(shift<<24);std::memcpy(bytes.data()+begin,&header,4);
        unsigned index{};for(const auto value:values){std::memcpy(bytes.data()+begin+4+4*index,&value,4);++index;}
    };
    const auto install=[&](const std::vector<std::byte>& bytes){
        const auto program=std::make_shared<const scenario::Program>(std::vector<std::vector<std::byte>>{bytes},scenario::DispatchProfile::offline_actor);
        check(!program->unsupported()&&host.update().scripts().install(1,program)==scenario::Status::completed);
        for(unsigned channel=2;channel<=3;++channel){std::vector<std::byte> empty;emit(empty,1,{});emit(empty,0xa,{});
            check(host.update().scripts().install(channel,std::make_shared<const scenario::Program>(std::vector<std::vector<std::byte>>{empty},scenario::DispatchProfile::offline_actor))==scenario::Status::completed);}
    };
    std::vector<std::byte> script;emit(script,1,{});emit(script,0x1a6,{1,0x123427e1,2});
    emit(script,0x1aa,{1,73,2});emit(script,0x40,{73,10});emit(script,0xe4,{});emit(script,0x40,{73,11});emit(script,0xe5,{});
    emit(script,0x1ac,{1,19,9});emit(script,0x40,{73,12});emit(script,0xe4,{});emit(script,0x40,{73,13});emit(script,0xe5,{});emit(script,0xa,{});
    install(script);check(host.step_room_script().status==application::SessionStatus::completed);++script_steps;
    check(state.forced_content==0x27e1&&state.forced_priority==0&&state.goal==0&&state.previous_goal==7&&state.action==0&&state.previous_action==8);
    check(host.update().flags().test_strided(73,10,0)==true&&host.update().flags().test_strided(73,11,0)==false);
    check(host.update().flags().test_strided(73,12,0)==true&&host.update().flags().test_strided(73,13,0)==false);
    actor->position.x=230;check(host.update().flags().actor_flag(scenario::ActorFlagFamily::primary,{false,1},19,false));
    for(unsigned bit=10;bit<=13;++bit)check(host.update().flags().strided(73,bit,0,false,false));
    install(script);check(host.step_room_script().status==application::SessionStatus::completed);++script_steps;
    check(host.update().flags().test_strided(73,10,0)==false&&host.update().flags().test_strided(73,11,0)==true);
    check(host.update().flags().test_strided(73,12,0)==false&&host.update().flags().test_strided(73,13,0)==true);
    script.clear();emit(script,1,{});emit(script,0x1a7,{1});emit(script,0x1a9,{1});emit(script,0xa,{});
    actor->inventory.carried[0]=3;actor->visible=true;actor->status=0;actor->auxiliary_status=0;
    install(script);check(host.step_room_script().status==application::SessionStatus::completed);++script_steps;
    check(state.forced_content==0&&state.forced_priority==-1&&!actor->active&&!actor->visible&&actor->status==0x5e0);
    //5F6800 mode0's remote-slot gate preserves inventory without requiring a graph.
    check(actor->inventory.carried[0]==3&&actor->auxiliary_status==0&&native.selected_actor==0);
    check(host.update().clock().update_counter()==0&&host.close()==application::SessionStatus::completed);
}
