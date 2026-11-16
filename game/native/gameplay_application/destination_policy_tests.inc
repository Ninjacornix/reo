// Controlled navigation data tests the real NativeSession offline VM and AI
// dispatch binding; no stock room transition or complete frame is claimed.
template<class T>void put_policy(std::vector<std::uint8_t>& bytes,unsigned at,T value){
    check(at+sizeof(T)<=bytes.size());std::memcpy(bytes.data()+at,&value,sizeof value);
}
std::vector<std::uint8_t> destination_policy_graph(unsigned room=1,unsigned variant=0){
    constexpr unsigned count=5,start=56,tail=12+64*count+4*count*count,directory=tail+8;
    std::vector<std::uint8_t> b(start+directory+64);put_policy(b,0,0x20030724u);put_policy(b,4,12u);put_policy(b,8,16u);put_policy(b,12,0u);put_policy(b,16,3u);
    for(unsigned i=0;i<3;++i){put_policy(b,20+12*i,std::uint16_t(room));put_policy(b,22+12*i,i==2?std::uint16_t(65535):std::uint16_t(variant));put_policy(b,24+12*i,start);put_policy(b,28+12*i,i==1?3u:0u);}
    put_policy(b,start,tail);put_policy(b,start+4,directory);put_policy(b,start+8,count);
    for(unsigned n=0;n<count;++n){const auto at=start+12+64*n;b[at]=1;b[at+1]=4;
        put_policy(b,at+4,float(100*n));put_policy(b,at+8,0.f);put_policy(b,at+12,300.f);put_policy(b,at+16,0xffffffffu);
        unsigned slot{};for(unsigned other=0;other<count;++other)if(other!=n){b[at+20+slot]=std::uint8_t(other);put_policy(b,at+24+2*slot,std::uint16_t(1));put_policy(b,at+36+2*slot,std::uint16_t(100));++slot;}
        for(unsigned p=0;p<4;++p)b[at+32+p]=std::uint8_t(1+((n+1)*(p+1))%13);
    }
    for(unsigned a=0;a<count;++a)for(unsigned d=0;d<count;++d){const auto at=start+12+64*count+4*(d*count+a);
        b[at]=a==d?255:std::uint8_t(d-(d>a?1:0));b[at+1]=b[at+2]=b[at+3]=255;}
    return b;
}

void destination_policy_application(const std::filesystem::path& path){
    namespace navigation=reo::native::gameplay_navigation;
    namespace ai=reo::native::gameplay_ai;
    Notifications notices;auto source=std::make_shared<const reo::assets::Source>(path);
    application::NativeSession host(source,profile(),notices,0);
    check(host.install_room({41,73,0})==application::SessionStatus::completed);
    auto& native=host.world();native.session().room_variants.restore({});
    const auto bytes=destination_policy_graph(73,0);navigation::ImportFailure failure;
    const auto graph=navigation::Asset::read(bytes,failure);check(bool(graph));
    check(native.navigation().bind(std::make_shared<const navigation::Asset>(*graph)));
    for(unsigned i=0;i<3;++i){auto actor=std::make_unique<world::Actor>();actor->active=i<2;actor->slot=std::uint8_t(i);
        actor->character=std::uint8_t(i);actor->room=73;actor->position={0,0,300};actor->ai_control=1;
        actor->ai_execution.emplace();actor->navigation_route.emplace();actor->ai_execution->goal=7;actor->ai_execution->action=8;
        check(bool(native.spawn_primary(i,std::move(actor)).id));}
    native.primary(1)->status=0x5e0; //source1A0 deliberately includes excluded active AI
    std::vector<std::byte> script(24);const std::array<std::uint32_t,6> words{1,0x020001a0,73,0,2,0xa};
    std::memcpy(script.data(),words.data(),script.size());
    const auto program=std::make_shared<const scenario::Program>(std::vector<std::vector<std::byte>>{script},scenario::DispatchProfile::offline_actor);
    const auto install=[&]{for(unsigned channel=1;channel<=3;++channel)check(host.update().scripts().install(channel,program)==scenario::Status::completed);};
    install();const auto stepped=host.step_room_script();check(stepped.status==application::SessionStatus::completed);++script_steps;
    check(native.navigation().descriptor_policy(73,0)==2);
    for(unsigned i=0;i<2;++i){const auto& state=*native.primary(i)->ai_execution;
        check(state.goal==0&&state.previous_goal==7&&state.action==0&&state.previous_action==8&&state.goal_refresh==1);}
    check(native.primary(2)->ai_execution->goal==7&&native.primary(2)->ai_execution->action==8);
    auto actor=native.primary(1);actor->status=0;auto& state=*actor->ai_execution;
    state.goal=1;state.goal_refresh=0;state.goal_phases[0]=2;state.goal_parameters[1]=500;
    actor->navigation_route->current_node=0;const auto id=native.identity(1);check(bool(id));
    scenario::SceneResources unread_resources; //goal1 does not read resource descriptors
    const auto goal=host.update().dispatch_ai_goal(id,unread_resources);
    check(goal.status==ai::Status::completed&&goal.selected==1&&state.goal_phases[0]==3&&state.action==2&&state.observation_cooldown==90);
    check(actor->navigation_route->destination_node>0&&actor->navigation_route->destination_node<5);
    check(!stepped.update.clock_committed&&host.update().clock().update_counter()==0);
    const auto saved=*actor->ai_execution;actor->ai_execution.reset();install();
    const auto before=native.navigation().descriptor_policy(73,0);
    check(host.step_room_script().status==application::SessionStatus::script_failure);
    check(native.navigation().descriptor_policy(73,0)==before&&!actor->ai_execution);
    actor->ai_execution=saved;check(host.close()==application::SessionStatus::completed);
}
void offline_navigation_controls_application(const std::filesystem::path& path){
    namespace navigation=reo::native::gameplay_navigation;
    Notifications notices;auto source=std::make_shared<const reo::assets::Source>(path);
    application::NativeSession host(source,profile(),notices,0);
    check(host.install_room({41,73,0})==application::SessionStatus::completed);
    auto bytes=destination_policy_graph(73,0);constexpr unsigned start=56,tail=432,directory=440;
    bytes.insert(bytes.begin()+start+directory,128,0);put_policy(bytes,start+4,directory+128);put_policy(bytes,start+tail+4,8u);
    constexpr std::array<unsigned,8> modes{0,2,1,3,0,0,9,0};
    for(unsigned i=0;i<8;++i){const auto at=start+tail+8+16*i;bytes[at]=std::uint8_t(i!=2&&i!=3&&i!=7);
        bytes[at+1]=i==4?2:3;bytes[at+2]=i==5?8:7;bytes[at+3]=std::uint8_t(modes[i]);}
    put_policy(bytes,start+12+16,0u);navigation::ImportFailure failure;const auto imported=navigation::Asset::read(bytes,failure);check(bool(imported));
    const auto immutable=std::make_shared<const navigation::Asset>(*imported);auto& native=host.world();native.session().room_variants.restore({});check(native.navigation().bind(immutable));
    auto actor=std::make_unique<world::Actor>();actor->active=true;actor->slot=0;actor->room=73;
    const auto id=native.spawn_primary(0,std::move(actor)).id;check(bool(id));
    check(host.update().applicable_navigation_condition(id,73,0).index==0);
    std::array<scenario::SceneControlId,4> ids{};
    for(unsigned i=0;i<4;++i){const auto added=host.scene_controls().append({7,std::uint8_t(i<2),scenario::ControlTypeThree{modes[i],0}});check(bool(added));ids[i]=*added;}
    const std::array<unsigned,8> words{1,0x01000053,7,0x02000058,7,0xabcdef12,0,0xa};std::vector<std::byte> script(sizeof(words));std::memcpy(script.data(),words.data(),script.size());
    const auto program=std::make_shared<const scenario::Program>(std::vector<std::vector<std::byte>>{script},scenario::DispatchProfile::offline_actor);
    for(unsigned channel=1;channel<=3;++channel)check(host.update().scripts().install(channel,program)==scenario::Status::completed);
    const auto step=host.step_room_script();check(step.status==application::SessionStatus::completed);++script_steps;
    const auto graph=native.navigation().room(73);check(graph&&native.navigation().condition_count(73)==8);
    constexpr std::array<unsigned,8> active{0,0,1,1,1,1,1,0};
    for(unsigned i=0;i<8;++i)check(graph->conditions()[i][0]==active[i]);
    check(immutable->find_room(73,0)->conditions()[0][0]==1);
    check(host.update().applicable_navigation_condition(id,73,0).index==-1&&host.update().applicable_navigation_condition(id,73,2).index==2);
    for(unsigned i=0;i<4;++i){const auto control=host.scene_controls().get(ids[i]);check(bool(control));check(control->enabled==unsigned(i>=2));
        if(i==3)check(std::get<scenario::ControlTypeThree>(control->body).parameter==0xef12);}
    check(host.close()==application::SessionStatus::completed);
}
