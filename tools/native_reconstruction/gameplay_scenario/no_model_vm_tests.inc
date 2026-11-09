// A typed NoModel is minted only by bounded authored input and admitted by a
// live room installation. Both VM entry paths preflight the WHOLE program.
std::size_t no_model_vm_cases{};
void no_model_vm_tests(){
    std::vector<std::byte> room(12+0xb0),script(128);
    const auto word=[](auto& b,unsigned at,std::uint32_t v){for(unsigned i=0;i<4;++i)b[at+i]=std::byte(v>>(8*i));};
    word(room,4,1);word(room,8,12);word(room,12,2);
    word(script,0,64);word(script,4,96);std::fill(script.begin()+64,script.end(),std::byte{255});
    auto data=std::make_shared<const std::vector<std::byte>>(script);
    vm::content::ScriptBank bank(data,vm::content::BankFormat::room_section);
    auto input=std::make_shared<const vm::RoomSceneInput>(room,bank,reo::native::gameplay_collision::ImportContext{1,1});
    for(const auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor})for(unsigned lease_case=0;lease_case<3;++lease_case)for(unsigned opcode:{0xb0u,0xb1u,0xb4u}){
        vm::SceneModels models({},{});reo::native::gameplay_actors::EntityStore entities;
        vm::SceneModelBindings bindings(models,entities);vm::SceneControls controls;
        reo::native::gameplay_collision::ownership::Proxies proxies(controls.records());
        vm::FlagState flags;std::uint16_t current_room=1;vm::SceneMatrixPrograms matrices(controls,models,bindings,flags,current_room);vm::RoomSceneGlobals globals;
        auto installed=vm::RoomSceneOwner::install(input,controls,proxies,models,matrices,globals,vm::NoModelRepair::authored_absent);
        check(installed.status==vm::RoomSceneStatus::completed&&installed.owner);
        if(lease_case==1)installed.owner->close();
        if(lease_case==2){auto map=models.remap();map[0]=0;models.room_remap(map);models.room_remap(input->mapping(1));}
        std::vector<std::byte>b;emit(b,1);emit(b,0x110,{0,42});emit(b,opcode,{0,0});emit(b,0xa);
        const auto before_visibility=models.state().visibility;const auto before_styles=models.state().styles;
        const auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b},profile);
        vm::Interpreter native;check(native.install(0,program)==vm::Status::completed);vm::Providers providers;providers.models=&models;
        if(profile==vm::DispatchProfile::ordinary){
            const auto result=native.tick(0,{},providers);check(result.status==(lease_case==0?vm::Status::yielded:vm::Status::provider_unavailable));
        }else{
            vm::OfflineCoordinator coordinator;std::array<vm::OfflinePartyActor,3>party{};std::uint8_t selected{};
            const auto result=coordinator.tick(native,0,true,party,current_room,selected,flags,providers);
            check(result.status==(lease_case==0?vm::Status::yielded:vm::Status::provider_unavailable));
        }
        check(native.counters()[0]==(lease_case==0?42u:0u));++no_model_vm_cases;
        check(models.state().visibility==before_visibility&&models.state().styles==before_styles);
        if(lease_case!=0){check(models.visibility(0,true)==vm::ModelStatus::invalid_pose_slot);check(models.state().styles==before_styles);}
        if(profile==vm::DispatchProfile::offline_actor){
            // Party preflight must refuse before evaluating ANY actor. All
            // three active references use the actual canonical provider.
            vm::Interpreter party_vm;check(party_vm.install(1,program)==vm::Status::completed);
            std::array<vm::OfflinePartyActor,3>party{{{true,0,1},{true,0,1},{true,0,1}}};
            vm::OfflineCoordinator coordinator;std::uint8_t selected{};
            const auto result=coordinator.tick(party_vm,1,true,party,current_room,selected,flags,providers);
            check(result.status==(lease_case==0?vm::Status::completed:vm::Status::provider_unavailable));
            check(party_vm.counters()[0]==(lease_case==0?42u:0u));check(result.invocations==(lease_case==0?3u:0u));++no_model_vm_cases;
        }
    }
    check(no_model_vm_cases==27);
}
