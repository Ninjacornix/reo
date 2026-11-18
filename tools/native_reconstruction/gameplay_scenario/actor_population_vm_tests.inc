#include "game/native/gameplay_scenario/actor_room_population.hpp"
namespace {
std::size_t actor_population_dispatches{},actor_population_refusals{};
void actor_population_vm_tests(){
    ActorFixture fixture;vm::FlagState flags;std::vector<std::uint8_t> ram(0x900000);install_original_tables(ram);
    vm::Providers providers;providers.world=&fixture.world;providers.flags=providers.canonical_flags=&flags;
    const std::array<std::uint32_t,12> signed_counts{0,1,2,3,4,5,6,7,8,0xffffffffu,0x80000000u,0x80000001u};
    const std::array<std::uint32_t,5> rooms{0,73,0x8000,0xffff,0xabcd0049};
    const std::array<std::uint32_t,8> statuses{0,0x20,0x40,0x80,0x100,0x400,0x5e0,0xfffffa1f};
    const auto seed=[&](std::uint32_t population,std::uint32_t room,unsigned trial){
        fixture.session->primary_population=population;fixture_write(ram.data(),0x4baea0,population);
        fixture.world.mode=ram[0x3243f2]=1;
        fixture_write(ram.data(),0x75a4b0,trial%5);fixture_write(ram.data(),0x75a4c0,(trial/5)%4);
        for(unsigned i=0;i<8;++i){auto actor=fixture.world.primary(i);const auto at=0x4a5c30+0x10e0*i;
            actor->active=(trial&(1u<<(i%5)))!=0;actor->status=statuses[(trial/4+i)%statuses.size()];
            actor->room=std::uint16_t(room+((trial&32)&&i==trial%8?1u:0u));
            ram[at]=actor->active?std::uint8_t((trial&2)?0x80:1):0;
            fixture_write(ram.data(),at+0xba0,actor->status);fixture_write(ram.data(),at+0x1e2,actor->room);
        }
    };
    const auto dispatch=[&](std::uint32_t opcode,std::initializer_list<std::uint32_t> payload,bool offline,unsigned trial){
        const std::vector<std::uint8_t> before(ram.begin()+0x4a5c30,ram.begin()+0x4a5c30+8*0x10e0);
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,3});emit(bytes,opcode,payload);
        emit(bytes,0x110,{0,11});emit(bytes,0xe4);emit(bytes,0x110,{0,17});emit(bytes,0xe5);emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        const vm::TickContext context{true,false,0};const auto result=offline?
            native.tick_offline_channel(0,context,{trial%5,(trial/5)%4,0},providers):native.tick(0,context,providers);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);
        check(std::memcmp(before.data(),ram.data()+0x4a5c30,before.size())==0);++actor_population_dispatches;
    };
    for(bool offline:{false,true})for(const auto population:signed_counts)for(const auto room:rooms)
    for(const auto mode:{0u,1u,0x100u,0xffffffffu})for(unsigned trial=0;trial<64;++trial){
        assertion_context="151 offline="+std::to_string(offline)+" count="+std::to_string(population)+" room="+std::to_string(room)+" mode="+std::to_string(mode)+" trial="+std::to_string(trial);
        seed(population,room,trial);dispatch(0x151,{room,mode},offline,trial);
    }
    const std::array<std::uint32_t,15> thresholds{0,1,2,3,4,5,6,7,8,9,10,11,12,0xffffffffu,0x80000000u};
    for(bool offline:{false,true})for(unsigned population=0;population<=8;++population)for(const auto room:rooms)
    for(const auto threshold:thresholds)for(const auto expected:{0u,1u,2u,0xffffffffu})for(unsigned trial=0;trial<64;++trial){
        assertion_context="153 offline="+std::to_string(offline)+" count="+std::to_string(population)+" room="+std::to_string(room)+" threshold="+std::to_string(threshold)+" expected="+std::to_string(expected)+" trial="+std::to_string(trial);
        seed(population,room,trial);dispatch(0x153,{room,threshold,expected},offline,trial);
    }
    // Full-word -1 bypasses every actor read and every threshold transform.
    for(bool offline:{false,true})for(const auto population:{0u,8u,9u,0x7fffffffu,0x80000000u,0xffffffffu})
    for(const auto threshold:{0u,5u,6u,8u,9u,0x7fffffffu,0x80000000u,0xffffffffu})for(const auto expected:{0u,1u,2u}){
        seed(population,0,0);dispatch(0x153,{0xffffffffu,threshold,expected},offline,0);
    }
    check(fixture.world.retire_primary(3)==reo::native::gameplay_actors::EntityStatus::completed);
    for(bool offline:{false,true})for(unsigned opcode:{0x151u,0x153u})for(unsigned profile=0;profile<3;++profile){
        fixture.session->primary_population=profile==0?std::optional<std::uint32_t>{}:std::optional<std::uint32_t>{profile==1?9u:8u};
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});if(opcode==0x151)emit(bytes,opcode,{73,1});else emit(bytes,opcode,{73,5,1});emit(bytes,0xa);
        vm::Interpreter native;check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary))==vm::Status::completed);
        const auto result=offline?native.tick_offline_channel(0,{true,false,0},{},providers):native.tick(0,{true,false,0},providers);
        check(result.status==vm::Status::provider_unavailable&&native.counters()[0]==0);++actor_population_refusals;
    }
    fixture.session->primary_population=0xffffffffu;
    check(vm::actor_population_rooms_match(fixture.world,73,1)==false);
    check(vm::actor_room_population_matches(fixture.world,0xffffffffu,0xffffffffu,1)==true);
    fixture.session->primary_population=0;
    check(vm::actor_population_rooms_match(fixture.world,73,0)==false&&vm::actor_room_population_matches(fixture.world,73,0,1)==true);
    for(unsigned opcode:{0x151u,0x153u}){
        std::vector<std::byte> bytes;emit(bytes,opcode,{73});bool refused{};try{const vm::Program program({bytes});}catch(const std::invalid_argument&){refused=true;}
        check(refused);++actor_population_refusals;
    }
    assertion_context.clear();
}
}
