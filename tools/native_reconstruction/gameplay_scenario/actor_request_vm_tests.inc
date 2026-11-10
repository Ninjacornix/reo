#include "game/native/gameplay_scenario/actor_requests.hpp"
namespace {
std::size_t actor_request_consumers{},actor_request_dispatches{},actor_request_profile_refusals{};
namespace request_world=reo::native::gameplay_world;
void request_export(std::uint8_t* ram,std::uint32_t at,const request_world::Actor& a){
    ram[at+8]=a.primary;ram[at+9]=a.secondary;ram[at+10]=a.phase;ram[at+11]=a.subphase;
    fixture_write(ram,at+0x38,a.position);fixture_write(ram,at+0x92,a.orientation[1]);fixture_write(ram,at+0xd94,a.saved_action_position);fixture_write(ram,at+0xda0,a.saved_action_yaw);
    fixture_write(ram,at+0xba0,a.status);ram[at+0xad4]=a.transient_equipment;ram[at+0xad5]=a.control_request.kind;fixture_write(ram,at+0xad6,a.control_request.parameter);ram[at+0xbd0]=a.response_lock;
    fixture_write(ram,at+0xf78,a.input.pressed);fixture_write(ram,at+0xf7c,a.input.released);fixture_write(ram,at+0xf80,a.input.held);std::memcpy(ram+at+0xf84,a.input.history.data(),12);fixture_write(ram,at+0xf90,a.input.repeat);
}
request_world::Actor request_actor(unsigned seed,unsigned kind,unsigned pending,bool excluded){
    request_world::Actor a;a.primary=std::uint8_t(seed*17);a.secondary=std::uint8_t(seed*7);a.phase=std::uint8_t(seed*19);a.subphase=std::uint8_t(seed*11);a.position={float(seed)/4,-float(seed),float(seed)*3};a.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(seed*999));a.saved_action_position={-1,2,-3};a.saved_action_yaw=-12345;
    a.status=seed*0x1234567u;a.status=excluded?a.status|0x80:a.status&~0x80u;a.transient_equipment=std::uint8_t(pending);a.control_request={std::uint8_t(kind),std::uint16_t(seed*555)};a.response_lock=std::uint8_t(seed*13);
    a.input.pressed=seed*76543u;a.input.released=~(seed*54321u);a.input.held=seed*876543u;a.input.history={seed*777u,seed*888u,seed*999u};a.input.repeat=seed*321u;a.input.repeat_timer=-123;for(unsigned i=0;i<8;++i)a.input.analog[i]=std::int16_t(seed+i*123);return a;
}
void request_compare(const std::vector<std::uint8_t>& ram,std::uint32_t at,const std::array<std::uint8_t,0x10e0>& before,const request_world::Actor& a){auto expected=before;request_export(expected.data(),0,a);check(std::memcmp(ram.data()+at,expected.data(),expected.size())==0);}
void actor_requests_vm_tests(){
    std::vector<std::uint8_t> ram(0x900000);owned_request_constants(ram.data());
    for(unsigned kind=0;kind<256;++kind)for(unsigned seed=0;seed<64;++seed)for(unsigned pending:{0u,1u,128u,255u})for(bool excluded:{false,true}){
        assertion_context="request consumer kind="+std::to_string(kind)+" seed="+std::to_string(seed)+" pending="+std::to_string(pending)+" excluded="+std::to_string(excluded);
        auto actor=request_actor(seed,kind,pending,excluded);request_world::Session session;session.control_notice=std::uint8_t(seed*37);const auto before_notice=session.control_notice;const auto before_input=actor.input;
        std::memset(ram.data()+0x20000,int(seed&255),0x10e0);request_export(ram.data(),0x20000,actor);ram[0x4b9d18]=session.control_notice;std::array<std::uint8_t,0x10e0> before;std::memcpy(before.data(),ram.data()+0x20000,before.size());
        const auto result=vm::consume_actor_request(actor,session);
        if(pending&&!excluded&&!vm::actor_request_kind_supported(std::uint8_t(kind))){check(result==vm::ActorRequestStatus::unsupported_kind);check(session.control_notice==before_notice);check(actor.input==before_input);request_compare(ram,0x20000,before,actor);++actor_request_profile_refusals;continue;}
        R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,4,0x20000);SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);o2_0064AE50_0x64ae50(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++actor_request_consumers;
        check(result==(pending?vm::ActorRequestStatus::completed:vm::ActorRequestStatus::idle));request_compare(ram,0x20000,before,actor);check(ram[0x4b9d18]==session.control_notice);check(actor.input.repeat_timer==before_input.repeat_timer&&actor.input.analog==before_input.analog);
    }
    vm::FlagState flags;
    for(bool offline:{false,true})for(unsigned profile=0;profile<8;++profile)for(unsigned kind:{0u,5u,8u,0x17u,0x28u})for(unsigned op:{0x100u,0x109u})for(unsigned category=0;category<(offline?5u:1u);++category)for(unsigned relation=0;relation<(offline?3u:1u);++relation){
        assertion_context="request dispatch op="+std::to_string(op)+" kind="+std::to_string(kind)+" profile="+std::to_string(profile)+" offline="+std::to_string(offline)+" category="+std::to_string(category)+" relation="+std::to_string(relation);
        ActorFixture actors(profile,std::uint8_t(profile),offline);std::array<std::array<std::uint8_t,0x10e0>,8> before;
        for(unsigned i=0;i<8;++i){const auto a=actors.world.primary(i);const auto id=a->slot;const auto cls=a->category;*a=request_actor(profile+i,0,0,(profile&1)!=0);a->slot=id;a->category=cls;const auto at=0x4a5c30+i*0x10e0;std::memset(ram.data()+at,int((profile+i)&255),0x10e0);request_export(ram.data(),at,*a);std::memcpy(before[i].data(),ram.data()+at,0x10e0);}
        actors.session->control_notice=std::uint8_t(profile*17);ram[0x4b9d18]=actors.session->control_notice;actors.export_original(ram);install_original_tables(ram);owned_request_constants(ram.data());ram[0x3243e8]=1;fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);flags.restore(initial_flags());export_flags(ram,flags.snapshot());
        // Preserve guard bytes after the projection of existing canonical actor
        // metadata (this fixture intentionally owns no original Actor pointer).
        for(unsigned i=0;i<8;++i)std::memcpy(before[i].data(),ram.data()+0x4a5c30+i*0x10e0,0x10e0);
        std::vector<std::byte>b;emit(b,0x110,{0,11});emit(b,op,{0x12340000u|kind,0x87650000u|profile});emit(b,0x110,{1,99});const auto end=emit(b,0xa);vm::Interpreter native;
        if(offline)install_offline_program(native,ram,0,b);
        else{std::memcpy(ram.data()+0x10000,b.data(),b.size());fixture_write<std::uint32_t>(ram.data(),0x4bace0,0x10000);fixture_write<std::uint32_t>(ram.data(),0x4bad28,0x10000+end);fixture_write<std::uint32_t>(ram.data(),0x4bad40,0x90000);fixture_write<std::uint32_t>(ram.data(),0x90000,0x10000);fixture_write<std::uint32_t>(ram.data(),0x4bacf8,0);fixture_write<std::uint32_t>(ram.data(),0x4bad10,0);auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b});check(native.restore_channel(0,{program,{0,0},{0,end},0,0,0})==vm::Status::completed);}
        for(unsigned i=0;i<4;++i)fixture_write<std::uint32_t>(ram.data(),0x4bada8+4*i,0);
        if(offline)original_offline_call(ram,0,false);else{R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);o2_0068C660_0x68c660(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++invocations;}
        vm::Providers p;p.world=&actors.world;p.flags=&flags;p.canonical_flags=&flags;const auto result=offline?native.tick_offline_channel(0,{true,false,std::uint8_t(profile)},{category,relation,0},p):native.tick(0,{true,false,std::uint8_t(profile)},p);check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);
        for(unsigned i=0;i<8;++i)request_compare(ram,0x4a5c30+i*0x10e0,before[i],*actors.world.primary(i));
        const auto selected=actors.world.primary(profile);const auto at=0x4a5c30+profile*0x10e0;R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,4,at);SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);o2_0064AE50_0x64ae50(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++actor_request_consumers;check(vm::consume_actor_request(*selected,*actors.session)!=vm::ActorRequestStatus::unsupported_kind);
        for(unsigned i=0;i<8;++i){request_compare(ram,0x4a5c30+i*0x10e0,before[i],*actors.world.primary(i));}
        check(ram[0x4b9d18]==actors.session->control_notice);++actor_request_dispatches;
    }
    for(unsigned op:{0x100u,0x109u})for(unsigned kind=0;kind<256;++kind)if(!vm::actor_request_kind_supported(std::uint8_t(kind))){bool refused=false;try{std::vector<std::byte>b;emit(b,op,{kind,0});vm::Program program({b});}catch(const std::invalid_argument&){refused=true;}check(refused);}
    for(const auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor}){ActorFixture actors;std::vector<std::byte>b;emit(b,0x110,{0,88});emit(b,0x100,{5});emit(b,0xa);vm::Interpreter native;check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b},profile))==vm::Status::completed);vm::Providers p;p.flags=&flags;p.canonical_flags=&flags;const auto tick=[&]{return profile==vm::DispatchProfile::ordinary?native.tick(0,{},p):native.tick_offline_channel(0,{},{0,0,0},p);};check(tick().status==vm::Status::provider_unavailable);check(native.counters()[0]==0);p.world=&actors.world;actors.world.retire_primary(0);check(tick().status==vm::Status::provider_unavailable);check(native.counters()[0]==0);}
    auto snapshot=initial_flags();flags.restore(snapshot);for(unsigned record=0;record<256;++record)for(unsigned slot=0;slot<6;++slot)check(flags.strided_half(record,slot)==snapshot.strided[record][slot]);check(!flags.strided_half(256,0)&&!flags.strided_half(0,6)&&!flags.strided_half(0,256)&&!flags.strided_half(0xffffffffu,0));
}
}
