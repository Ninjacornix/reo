#include "game/native/gameplay_scenario/scene_record_parameters.hpp"
namespace {
std::size_t scene_record_parameter_dispatches{},scene_record_parameter_packets{};
struct SceneParameterSink final:reo::native::gameplay_update::GameplayMessageSink {
    std::vector<reo::native::gameplay_update::SceneRecordParameterMessage> packets;
    bool ready{true};
    bool send(const reo::native::gameplay_update::ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const reo::native::gameplay_update::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const reo::native::gameplay_update::ResourcePositionMessage&)noexcept override{return false;}
    bool send(const reo::native::gameplay_update::ActorStatusMessage&)noexcept override{return false;}
    bool send(const reo::native::gameplay_update::SceneRecordParameterMessage& value)noexcept override{packets.push_back(value);return true;}
    bool scene_record_parameters_ready()const noexcept override{return ready;}
};
std::vector<reo::native::gameplay_update::SceneRecordParameterMessage>* original_scene_parameter_packets{};
PS2Runtime::Function scene_parameter_port(std::uint32_t at){
    if(!original_scene_parameter_packets||(at!=0x811190&&at!=0x810870))return nullptr;
    return +[](std::uint8_t* memory,R5900Context* c,PS2Runtime*){
        const auto p=GPR_U32(c,5);check(GPR_U32(c,4)==5&&GPR_U32(c,6)==0&&GPR_U32(c,7)==4&&memory[p]==6&&memory[p+1]==6);
        original_scene_parameter_packets->push_back({c->pc==0x811190?reo::native::gameplay_update::MessageRoute::mode_zero:reo::native::gameplay_update::MessageRoute::mode_one,memory[p+4],memory[p+5]});done(c);
    };
}
void scene_record_parameter_vm_tests(){
    std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ActorFixture actors;NoticeSink notices;vm::FlagState flags(&notices);
    SceneParameterSink sink;sink.packets.reserve(8);std::vector<reo::native::gameplay_update::SceneRecordParameterMessage> packets;packets.reserve(8);
    original_scene_parameter_packets=&packets;struct Reset{~Reset(){original_scene_parameter_packets=nullptr;}}reset;
    std::vector<std::byte> input(16+96*32);const std::uint32_t header=16;std::memcpy(input.data(),&header,4);
    for(unsigned index=0;index<31;++index){input[16+96*index+0x49]=std::byte{1};input[16+96*index+0x33]=std::byte{255};}
    input[16+96*31+2]=std::byte{255};actors.session->scenario=0;
    check(actors.session->enemy_descriptors.import(input,*actors.session,true,0).status==vm::EnemyImportStatus::completed);
    const std::array<std::uint8_t,6> phases{0,1,2,3,128,255};
    for(bool offline:{false,true})for(unsigned category=0;category<(offline?5u:1u);++category)
    for(unsigned relation=0;relation<(offline?4u:1u);++relation)for(auto phase:phases)for(unsigned mode:{0u,1u,2u,255u})for(unsigned trial=0;trial<8;++trial){
        assertion_context="166VM offline="+std::to_string(offline)+" category="+std::to_string(category)+" relation="+std::to_string(relation)+" phase="+std::to_string(phase)+" mode="+std::to_string(mode)+" trial="+std::to_string(trial);
        const auto condition=std::uint8_t(trial*37u),parameter=std::uint8_t(trial*17u),value=std::uint8_t(trial*97u+31u);
        for(unsigned index=0;index<256;++index){auto& record=*actors.session->enemy_descriptors.record(index);
            record.condition=std::uint8_t(condition+(index%3==0));record.parameter23=std::uint8_t(parameter+(index%5==0));record.parameter2e=std::uint8_t(~value);}
        actors.session->message_phase=phase;actors.world.mode=std::uint8_t(mode);actors.world.selected_actor=ram[0x4baded]=0;
        ram[0x3243fb]=phase;ram[0x3243f2]=std::uint8_t(mode);ram[0x3243e8]=1;
        fixture_write<std::uint32_t>(ram.data(),0x75a4b0,category);fixture_write<std::uint32_t>(ram.data(),0x75a4c0,relation);
        export_enemies(actors.session->enemy_descriptors,ram);packets.clear();sink.packets.clear();
        std::vector<std::byte> bytes;emit(bytes,0x166,{0xabcd0000u|condition,0x12340000u|parameter,0x98760000u|value});const auto tail=emit(bytes,0xa);
        const auto profile=offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary;
        auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},profile);
        check(!program->unsupported()&&program->needs_world()&&program->needs_scene_record_parameters());
        vm::Interpreter native;check(native.restore_channel(0,{program,{0,0},{0,tail},0,0,0})==vm::Status::completed);
        std::memcpy(ram.data()+0x10000,bytes.data(),bytes.size());
        for(const auto pair:std::array<std::array<std::uint32_t,2>,7>{{{0x90000,0x10000},{0x4bace0,0x10000},{0x4bad28,0x10000+tail},{0x4bad40,0x90000},{0x4bacf8,0},{0x4bad10,0},{0x4bad58,0}}})fixture_write(ram.data(),pair[0],pair[1]);
        R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,4,0);SET_GPR_U32(&context,29,0x7f0000);SET_GPR_U32(&context,31,0xdeadbeef);
        if(offline)o2_007006D0_0x7006d0(ram.data(),&context,&runtime);else o2_0068C660_0x68c660(ram.data(),&context,&runtime);
        check(context.pc==0xdeadbeef);
        vm::Providers providers;providers.world=&actors.world;providers.flags=providers.canonical_flags=&flags;
        if(vm::scene_record_parameter_notification_required(actors.world))providers.messages=&sink;
        const auto result=offline?native.tick_offline_channel(0,{}, {category,relation,0},providers):native.tick(0,{},providers);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);compare_enemies(actors.session->enemy_descriptors,ram);
        check(packets.size()==sink.packets.size());
        for(unsigned i=0;i<packets.size();++i)check(packets[i].route==sink.packets[i].route&&packets[i].ordinal==sink.packets[i].ordinal&&packets[i].value==sink.packets[i].value);
        scene_record_parameter_packets+=packets.size();++scene_record_parameter_dispatches;
    }
    const auto refusal=[&](vm::Providers providers){
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,123});emit(bytes,0x166,{1,2,3});emit(bytes,0xa);
        vm::Interpreter native;check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes}))==vm::Status::completed);
        check(native.tick(0,{},providers).status==vm::Status::provider_unavailable&&native.counters()[0]==0);
    };
    actors.world.mode=0;actors.session->message_phase=1;vm::Providers providers;providers.world=&actors.world;refusal(providers);
    providers.messages=&sink;sink.ready=false;refusal(providers);sink.ready=true;
    providers.world=nullptr;refusal(providers);
    for(auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor}){std::vector<std::byte> bytes;emit(bytes,0x166,{1});bool refused=false;try{vm::Program p({bytes},profile);}catch(const std::invalid_argument&){refused=true;}check(refused);}
    assertion_context.clear();
}
}
