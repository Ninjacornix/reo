#include "game/native/gameplay_scenario/script_audio.hpp"
#include "game/native/gameplay_audio/scenario_cues.hpp"
namespace vm_audio_inputs {
#include "game/native/audio_banks/v2/test_inputs.hpp"
}
namespace {
namespace vm_audio=reo::native::gameplay_audio;
namespace vm_banks=reo::native::audio_banks::v2;
std::size_t script_audio_vm_dispatches{},script_audio_vm_port_calls{},script_audio_vm_frames{},script_audio_vm_signal{};
struct VmAudioPort {
    vm_audio::Owner* owner{};const vm_audio::SpatialContext* spatial{};
    std::uint16_t scenario{},last{};std::size_t calls{};
};
VmAudioPort* active_vm_audio_port{};
PS2Runtime::Function script_audio_port(std::uint32_t at){
    if(at!=0x1b8930)return nullptr;
    return +[](std::uint8_t* ram,R5900Context* context,PS2Runtime*){
        if(!active_vm_audio_port)throw std::runtime_error("Unbound original VM script-audio port");
        auto& port=*active_vm_audio_port;++port.calls;++script_audio_vm_port_calls;
        const auto cue=vm_audio::scenario_cue(port.scenario,GPR_U32(context,5));
        if(cue!=255){
            const auto point=GPR_U32(context,4);
            if(point){const vm_audio::Vector position{fixture_read<float>(ram,point),fixture_read<float>(ram,point+4),fixture_read<float>(ram,point+8)};
                (void)port.owner->positional({2,cue},position,*port.spatial,1);
            }else (void)port.owner->request({2,cue});
            port.last=std::uint16_t(cue);
        }
        SET_GPR_U32(context,2,0);done(context);
    };
}
struct VmAudioGain final:vm_banks::GainProvider {
    float gain(unsigned,unsigned,std::uint64_t)noexcept override{return 1;}
};
void script_audio_vm_tests(){
    std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ActorFixture actors;
    auto actual=std::make_shared<vm_banks::Session>(),expected=std::make_shared<vm_banks::Session>();
    reo::native::gameplay_session::Random expected_random;
    vm_audio::Owner owner(actual,actors.session->random),reference(expected,expected_random);
    auto input=vm_audio_inputs::bank();input.tq.assign(16+4*128+8*128,0);vm_audio_inputs::word16(input.tq,14,128);
    for(unsigned i=0;i<128;++i){const auto at=16+4*128+8*i;vm_audio_inputs::word32(input.tq,16+4*i,0x40000000u|at);
        const std::array<std::uint8_t,8> code{0xe0,127,0xe2,0,0xb2,127,0xff,0};std::copy(code.begin(),code.end(),input.tq.begin()+at);}
    vm_audio::Descriptors rows;for(unsigned i=0;i<rows.size();++i)rows[i]={0,std::uint16_t(i*13u),std::uint8_t(80+i%48),255,3,2,std::uint8_t(i%16),1,255};
    const std::array<std::span<const std::uint8_t>,3> parts{input.hd,input.bd,input.tq};
    check(owner.install_parts(owner.begin_bank(2),rows,parts).status==vm_audio::Status::completed);
    check(reference.install_parts(reference.begin_bank(2),rows,parts).status==vm_audio::Status::completed);
    vm_audio::SpatialContext spatial;spatial.world_to_screen=reo::native::transform_math::identity();spatial.world_to_screen[0][0]=.25f;spatial.world_to_screen[3][0]=320;
    vm::ScriptAudio frontend(actors.world,owner,spatial);VmAudioGain gain;VmAudioPort port{&reference,&spatial};
    active_vm_audio_port=&port;struct ResetPort{~ResetPort(){active_vm_audio_port=nullptr;}}reset;
    for(unsigned index=0;index<8;++index){auto actor=actors.world.primary(index);actor->position={float(index*350+25),float(-int(index)*100),float(index*75)};
        std::memcpy(ram.data()+0x4a5c30+0x10e0*index+0x38,&actor->position,12);}
    NoticeSink notifications;vm::FlagState flags(&notifications);
    const std::array<std::array<std::int32_t,3>,4> points{{{0,0,0},{1200,-300,200},{10000,0,0},{16777217,-16777217,8388609}}};
    const auto run=[&](bool offline,unsigned category,unsigned relation,unsigned scenario,unsigned event,unsigned mode,unsigned selector,std::array<std::int32_t,3> point){
        assertion_context="script73 VM offline="+std::to_string(offline)+" category="+std::to_string(category)+" relation="+std::to_string(relation)+" scenario="+std::to_string(scenario)+" event="+std::to_string(event)+" mode="+std::to_string(mode);
        const vm_banks::Command stop=vm_banks::StopAll{false};check(actual->apply({&stop,1}).status==vm_banks::Status::ok&&expected->apply({&stop,1}).status==vm_banks::Status::ok);
        const reo::native::gameplay_session::RandomState seed{std::uint16_t(91+event),std::uint16_t(37+selector),0};actors.session->random.restore(seed);expected_random.restore(seed);
        actors.session->scenario=port.scenario=std::uint16_t(scenario);actors.session->last_scenario_audio=port.last=0xa51c;port.calls=0;
        actors.world.selected_actor=std::uint8_t((event+category+relation)%8);ram[0x4baded]=actors.world.selected_actor;ram[0x3243e8]=1;
        fixture_write<std::uint32_t>(ram.data(),0x75a4b0,category);fixture_write<std::uint32_t>(ram.data(),0x75a4c0,relation);
        std::vector<std::byte> bytes;
        if(mode==1)emit(bytes,0x73,{event,mode,selector});
        else if(mode==2)emit(bytes,0x73,{event,mode,std::bit_cast<std::uint32_t>(point[0]),std::bit_cast<std::uint32_t>(point[1]),std::bit_cast<std::uint32_t>(point[2])});
        else emit(bytes,0x73,{event,mode});
        const auto tail=emit(bytes,0xa);const auto profile=offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary;
        auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},profile);
        check(!program->unsupported()&&program->needs_script_audio()==(mode<=2));
        vm::Interpreter native;check(native.restore_channel(0,{program,{0,0},{0,tail},0,0,0})==vm::Status::completed);
        std::memcpy(ram.data()+0x10000,bytes.data(),bytes.size());
        for(const auto pair:std::array<std::array<std::uint32_t,2>,7>{{{0x90000,0x10000},{0x4bace0,0x10000},{0x4bad28,0x10000+tail},{0x4bad40,0x90000},{0x4bacf8,0},{0x4bad10,0},{0x4bad58,0}}})fixture_write(ram.data(),pair[0],pair[1]);
        R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,4,0);SET_GPR_U32(&context,29,0x7f0000);SET_GPR_U32(&context,31,0xdeadbeef);
        if(offline)o2_007006D0_0x7006d0(ram.data(),&context,&runtime);else o2_0068C660_0x68c660(ram.data(),&context,&runtime);
        check(context.pc==0xdeadbeef);
        vm::Providers providers;providers.flags=providers.canonical_flags=&flags;
        if(mode<=2){providers.world=&actors.world;providers.script_audio=&frontend;}
        const vm::TickContext tick{true,false,actors.world.selected_actor};
        const auto result=offline?native.tick_offline_channel(0,tick,{category,relation,0},providers):native.tick(0,tick,providers);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);
        check(actors.session->last_scenario_audio==port.last);
        const auto a=actual->snapshot(),e=expected->snapshot();check(a.request_age==e.request_age);
        for(unsigned i=0;i<16;++i){const auto& x=a.ports[2].requests[i];const auto& y=e.ports[2].requests[i];
            check(x.index==y.index&&x.group==y.group&&x.request_volume==y.request_volume&&x.request_pan==y.request_pan&&x.request_pitch==y.request_pitch&&x.sequence.active==y.sequence.active&&x.sequence.cursor==y.sequence.cursor&&x.sequence.program_offset==y.sequence.program_offset);}
        const auto random=actors.session->random.state(),reference_random=expected_random.state();check(random.primary==reference_random.primary&&random.secondary==reference_random.secondary&&random.observed==reference_random.observed);
        std::array<float,64> output{},expected_output{};check(actual->mix_add(output.data(),32,gain)==vm_banks::Status::ok&&expected->mix_add(expected_output.data(),32,gain)==vm_banks::Status::ok);check(output==expected_output);
        for(float value:output)if(value!=0)++script_audio_vm_signal;
        ++script_audio_vm_dispatches;script_audio_vm_frames+=32;
    };
    for(bool offline:{false,true})for(unsigned category=0;category<(offline?5u:1u);++category)for(unsigned relation=0;relation<(offline?4u:1u);++relation)
    for(unsigned scenario:{0u,1u,2u,28u,35u,41u})for(unsigned event:{0u,1u,8u,31u,127u,207u}){
        run(offline,category,relation,scenario,event,0,0,{});
        for(unsigned actor=0;actor<8;++actor)run(offline,category,relation,scenario,event,1,actor,{});
        for(auto point:points)run(offline,category,relation,scenario,event,2,0,point);
        run(offline,category,relation,scenario,event,3,0,{});run(offline,category,relation,scenario,event,UINT32_MAX,0,{});
    }
    check(script_audio_vm_signal>0&&script_audio_vm_port_calls>0);
    // Whole-program admission runs before the leading counter instruction.
    const auto refusal=[&](std::uint32_t event,std::uint32_t mode,std::uint32_t actor,vm::Providers providers){
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,123});emit(bytes,0x73,{event,mode,actor,0,0});emit(bytes,0xa);
        vm::Interpreter native;check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes}))==vm::Status::completed);
        check(native.tick(0,{true,false,actors.world.selected_actor},providers).status==vm::Status::provider_unavailable&&native.counters()[0]==0);
    };
    actors.session->scenario=1;vm::Providers providers;providers.world=&actors.world;providers.script_audio=&frontend;
    refusal(0,0,0,{});auto missing=providers;missing.world=nullptr;refusal(0,0,0,missing);missing=providers;missing.script_audio=nullptr;refusal(0,0,0,missing);
    refusal(208,0,0,providers);refusal(0,1,8,providers);
    ActorFixture foreign;missing=providers;missing.world=&foreign.world;refusal(0,0,0,missing);
    actors.session->scenario.reset();refusal(0,0,0,providers);
    for(auto bytes:std::array<std::vector<std::byte>,2>{[]{std::vector<std::byte> b;emit(b,0x73,{0});return b;}(),[]{std::vector<std::byte>b;emit(b,0x73,{0,2,1});return b;}()}){
        bool refused=false;try{vm::Program program({bytes});}catch(const std::invalid_argument&){refused=true;}check(refused);
    }
    assertion_context.clear();
}
}
