#ifdef REO_PRIMARY_SAVED_INITIALIZATION_ORIGINAL
const g::PrimaryEquipmentContext* primary_saved_context{};
void compare_saved_query(unsigned,std::int8_t,const g::PrimaryEquipmentContext&);
#else
void compare_saved_query(unsigned,std::int8_t,const g::PrimaryEquipmentContext&){}
#endif
void saved_initialization_tests(g::ActorAssets& models,const g::HumanoidMotionBanks& banks){
    namespace s=reo::native::gameplay_scenario;namespace save=reo::native::gameplay_save;
    save::LiveState state;g::PrimarySavedActors expected;
    const auto store=[&](unsigned slot,g::PrimarySavedActorState value){
        // Independently source-derived serial field positions: health177A,
        // class177D and selected equipment179E, with10C per primary slot.
        const auto bits=std::bit_cast<std::uint16_t>(value.health);state.second[0x177a+0x10c*slot]=std::byte(bits&255);state.second[0x177b+0x10c*slot]=std::byte(bits>>8);
        state.second[0x177d + 0x10c*slot]=std::byte(value.class_marker);state.second[0x179e + 0x10c*slot]=std::byte(value.selected_resource);expected[slot]=value;
    };
    for(unsigned slot=0;slot<8;++slot)store(slot,{std::int16_t(-30000+8000*slot),std::uint8_t(slot*31),std::uint8_t(slot*29)});
    const auto decoded=save::decode_primary_start_snapshot(state);check(decoded&&*decoded==expected);++saved_decodes;
    const auto container=std::make_unique<save::Container>();save::capture_second(save::HeaderView(container->data()+8,save::header_bytes),save::DataView(container->data()+0x108,save::data_bytes),state);
    save::encode(*container,0x1234);check(save::decode(*container)==save::DecodeResult::ok);save::LiveState restored;save::restore_second(save::ConstDataView(container->data()+0x108,save::data_bytes),restored);check(save::decode_primary_start_snapshot(restored)==decoded);++saved_decodes;
    for(unsigned length:{0u,1u,0x100u,0x1fffu,0x6fffu}){check(!save::decode_primary_start_snapshot(std::span<const std::byte>(state.second).first(length)));++saved_refusals;}
    std::vector<std::byte> oversized(0x7001);check(!save::decode_primary_start_snapshot(oversized));++saved_refusals;

    // A declared constructed template section exercises signed action bytes.
    // Actor/model/motion inputs below remain actual independently pinned assets.
    std::vector<std::byte> encoded(32+24*129);
    const auto word=[&](unsigned at,auto value){std::memcpy(encoded.data()+at,&value,sizeof value);};
    word(0,3u);word(4,129);word(16,32u);
    for(unsigned index=0;index<129;++index)encoded[32+24*index+15]=std::byte(std::uint8_t(index*43));
    s::ResourceTemplates templates;check(templates.load(encoded));s::SceneResources resources;
    for(unsigned slot=0;slot<256;++slot){s::SceneDescriptor descriptor;descriptor.active=std::uint8_t(slot==0||slot%3?1:0);descriptor.template_index=slot==0?std::uint8_t(1):slot%7==0?std::uint8_t(255):std::uint8_t(slot%129);check(bool(resources.load(slot,descriptor)));}
    const g::PrimaryEquipmentContext context{resources,templates};
#ifdef REO_PRIMARY_SAVED_INITIALIZATION_ORIGINAL
    primary_saved_context=&context;
#endif
    for(unsigned value=0;value<65536;++value){const auto action=resources.action_kind(value,templates);compare_saved_query(value,action,context);++saved_query_cases;}
    s::SceneDescriptor selected;selected.active=1;selected.template_index=0;check(bool(resources.load(1,selected)));
    for(unsigned action=0;action<256;++action){encoded[32+15]=std::byte(action);check(templates.load(encoded));const auto value=resources.action_kind(0x10001,templates);check(value==std::bit_cast<std::int8_t>(std::uint8_t(action)));compare_saved_query(0x10001,value,context);++saved_query_cases;}
    g::World world(profile(),std::make_shared<g::Session>());world.paused=-1;
    const auto asset=models.read_primary(0,0,0);
    for(unsigned slot=0;slot<8;++slot){auto actor=std::make_unique<g::Actor>();actor->slot=std::uint8_t(slot);actor->model_asset=asset;actor->model=asset->make_instance();actor->animation=std::make_shared<a::Playback>(actor->model);check(world.spawn_primary(slot,std::move(actor)).status==g::actors::EntityStatus::completed);}
    for(unsigned health=0;health<65536;++health){
        const auto slot=health%8;const auto actor=world.primary(slot);actor->current=-123;actor->maximum=456;actor->status=health%4==0?8u:health%4==1?2u:0u;actor->auxiliary_status=0x89abcdef;actor->class_marker=77;actor->previous_motion_class=88;actor->selected_resource=99;actor->resource_action=123;actor->pending_notice=99;
        const auto before=*actor;store(slot,{std::bit_cast<std::int16_t>(std::uint16_t(health)),std::uint8_t(health*13),std::uint8_t(health)});
        const auto imported=save::decode_primary_start_snapshot(state);check(imported&&*imported==expected);++saved_decodes;world.session().primary_initialization_snapshot=imported;
        check(g::initialize_primary_slot(world,world.identity(slot),0,banks,&context)==g::PrimaryInitializationStatus::completed);compare_original(world,*actor,before,0,false);
        const auto action=actor->selected_resource?resources.action_kind(actor->selected_resource,templates):std::int8_t(0);check(actor->current==std::bit_cast<std::int16_t>(std::uint16_t(health))&&actor->maximum==2300&&actor->resource_action==std::uint16_t(std::int16_t(action)));++saved_initializations;
    }
    auto actor=world.primary(0);store(0,{-30000,222,0});world.session().primary_initialization_snapshot=save::decode_primary_start_snapshot(state);check(g::initialize_primary_slot(world,world.identity(0),0,banks)==g::PrimaryInitializationStatus::completed&&actor->selected_resource==0&&actor->resource_action==0);
    store(0,{-12345,231,1});world.session().primary_initialization_snapshot=save::decode_primary_start_snapshot(state);
    check(g::initialize_primary_slot(world,world.identity(0),0,banks)==g::PrimaryInitializationStatus::unavailable&&actor->current==-12345&&actor->class_marker==231&&actor->selected_resource==1);++saved_refusals;
    const auto before=actor->current;check(g::initialize_primary_defaults(world,world.identity(0),0,banks)==g::PrimaryInitializationStatus::unavailable&&actor->current==before);++saved_refusals;
    s::SceneDescriptor invalid;invalid.active=1;invalid.template_index=129;check(bool(resources.load(1,invalid)));check(g::initialize_primary_slot(world,world.identity(0),0,banks,&context)==g::PrimaryInitializationStatus::unavailable&&actor->current==-12345&&actor->class_marker==231);++saved_refusals;
#ifdef REO_PRIMARY_SAVED_INITIALIZATION_ORIGINAL
    primary_saved_context=nullptr;
#endif
}
