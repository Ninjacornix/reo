// Concrete fresh application with untouched owned content. Every external
// startup boundary refuses; this diagnostic never substitutes successful work.
void fresh_startup_diagnostic(const char* archive_path,const char* catalog_path,const char* effects_path){
    struct RequiredEffects final:w::PrimaryStartupEffects {
        app::NativeSession& host;std::string boundary;std::uint32_t work{};
        explicit RequiredEffects(app::NativeSession& value):host(value){}
        bool bound_to(const w::World& world)const noexcept override{return &world==&host.world();}
        w::PrimaryStartupStatus stop(const char* name,std::uint32_t address){boundary=name;work=address;return w::PrimaryStartupStatus::unavailable;}
        w::PrimaryStartupStatus voice_archive(std::uint8_t,std::uint8_t)override{return stop("voice_archive",0x1ba440);}
        w::PrimaryStartupStatus background(std::uint8_t)override{return stop("background",0x1af6a0);}
        w::PrimaryStartupStatus initialize_stream_stage()override{return stop("initialize_stream_stage",0x1b0510);}
        w::PrimaryStartupStatus run(w::PrimaryStartupWork value)override{return stop("work",std::uint32_t(value));}
        w::PrimaryStartupStatus actor_resources(w::PrimaryStartupWork value,const w::actors::EntityId&)override{return stop("actor_resources",std::uint32_t(value));}
        std::optional<std::int8_t> roster_kind(std::uint8_t)const noexcept override{return{};}
        std::optional<float> reference_height(std::uint8_t)const noexcept override{return{};}
    };
    const auto source=std::make_shared<const reo::assets::Source>(archive_path);Notifications notices;
    std::ifstream input_geometry(effects_path,std::ios::binary);unsigned count{};input_geometry.read(reinterpret_cast<char*>(&count),4);check(count==12);
    std::array<std::vector<std::byte>,2> geometry;
    for(auto& data:geometry){unsigned bytes{};input_geometry.read(reinterpret_cast<char*>(&bytes),4);check(bytes&&bytes<10000000);data.resize(bytes);input_geometry.read(reinterpret_cast<char*>(data.data()),bytes);check(bool(input_geometry));}
    const auto effects=reo::native::gameplay_effects::EffectBank::import(geometry[0],geometry[1]);
    std::ifstream input_contacts(catalog_path,std::ios::binary);std::vector<char> chars{std::istreambuf_iterator<char>(input_contacts),{}};check(!chars.empty());
    std::vector<std::byte> contact_bytes(chars.size());std::memcpy(contact_bytes.data(),chars.data(),chars.size());
    const auto contacts=std::make_shared<const reo::native::gameplay_collision::delivery::Catalog>(reo::native::gameplay_collision::delivery::Catalog::import(contact_bytes));
    app::OfflineLaunchInput launch{source,profile(),std::vector<std::byte>(32),{41,73,0},1,"DEF41.NBD",w::HumanoidMotionAssets::initial_banks(false),effects,contacts};
    // Explicit host choices, not an inferred frontend selection.
    launch.launch_record[3]=std::byte{41};launch.launch_record[4]=std::byte{1};launch.launch_record[5]=std::byte{1};
    launch.launch_record[16]=std::byte{1};launch.launch_record[24]=std::byte{1};launch.launch_record[28]=std::byte{2};
    const auto voice=std::filesystem::path(archive_path).parent_path()/"NETBIO01.DAT";
    if(std::filesystem::is_regular_file(voice))launch.voice_source=std::make_shared<reo::assets::Source>(voice.string());
    const auto made=app::OfflineApplication::create_fresh(std::move(launch),notices);check(made.status==app::OfflineApplicationStatus::completed&&bool(made.application));
    auto& application=*made.application;auto& host=application.session();
    std::optional<app::FrontendResult> frontend;
    std::shared_ptr<reo::native::adxt_output_session::Session> audio_output;
#ifdef _WIN32
    const auto window=CreateWindowExA(0,"STATIC","native startup frontier",WS_OVERLAPPEDWINDOW,
        0,0,640,448,nullptr,nullptr,GetModuleHandleA(nullptr),nullptr);
    check(window!=nullptr);ShowWindow(window,SW_SHOWNOACTIVATE);UpdateWindow(window);
    reo::Input host_input;check(host_input.init());
    check(application.bind_input(host_input,window)==app::OfflineApplicationStatus::completed);
    check(application.bind_display_clock(window)==app::OfflineApplicationStatus::completed);
    if(application.voice_selections()){
        auto mixer=std::make_shared<reo::native::audio_mix_tail::Mixer>(reo::native::audio_banks::v2::Config{},std::make_shared<TestBankGain>(),std::make_shared<TestMasterGain>());
        reo::native::adxt_output_session::Config config;config.bank_mix=mixer;
        audio_output=std::make_shared<reo::native::adxt_output_session::Session>(config,std::make_shared<reo::audio_output::CallbackSlot>(),std::make_shared<UnstartedAudioProvider>());
        check(application.bind_audio(mixer,audio_output)==app::OfflineApplicationStatus::completed);
    }
    frontend=application.begin_frontend();
#endif
    const auto prepared=application.prepare();
    RequiredEffects required(host);std::optional<w::PrimaryStartupReport> started;
    if(prepared.status==app::OfflineApplicationStatus::completed)started=application.start(&required);
    const auto bank=host.archive().scenario_scripts(41);check(bool(bank));
    const auto admitted=s::content::admit_script_program(*bank,s::DispatchProfile::offline_actor,s::content::ScriptRoots::scenario_startup);
    const auto& channel=host.update().scripts().channels()[0];const auto executing=channel.cursor_program?channel.cursor_program:channel.program;
    const auto record=executing?executing->record(channel.current):std::nullopt;
    std::cout<<"{\"diagnostic\":\"fresh_native_startup\",\"content_modified\":false,\"scenario\":41,\"installed_room\":73,\"prepare_status\":"<<unsigned(prepared.status)<<",\"prepare_stage\":"<<unsigned(prepared.stage)
        <<",\"startup_attempted\":"<<(started?"true":"false")<<",\"startup_status\":"<<(started?unsigned(started->status):UINT32_MAX)<<",\"startup_stage\":"<<(started?unsigned(started->stage):UINT32_MAX)
        <<",\"frontend_attempted\":"<<(frontend?"true":"false")<<",\"frontend_status\":"<<(frontend?unsigned(frontend->status):UINT32_MAX)<<",\"frontend_stage\":"<<(frontend?unsigned(frontend->stage):UINT32_MAX)
        <<",\"loading_passes\":"<<(application.frontend_display()?application.frontend_display()->loading_passes():0)
        <<",\"external_boundary\":\""<<required.boundary<<"\",\"external_source\":"<<required.work<<",\"startup_closure_status\":"<<unsigned(admitted.status)<<",\"admission_failure_opcode\":"<<admitted.opcode
        <<",\"channel_bound\":"<<(executing?"true":"false")<<",\"cursor_block\":"<<channel.current.block<<",\"cursor_offset\":"<<channel.current.offset<<",\"cursor_opcode\":"<<(record?record->opcode:UINT32_MAX)
        <<",\"frame_run\":false,\"native_startup_complete\":"<<(application.started()?"true":"false")<<"}\n";
    check(application.close()==app::OfflineApplicationStatus::completed);
    if(audio_output)check(audio_output->join()==reo::native::adxt_output_session::Status::completed);
#ifdef _WIN32
    host_input.shutdown();check(DestroyWindow(window)!=0);
#endif
}
