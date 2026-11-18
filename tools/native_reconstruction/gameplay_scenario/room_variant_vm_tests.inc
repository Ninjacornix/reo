#include "game/native/gameplay_navigation/bank.hpp"
namespace {
std::size_t room_variant_handlers{},room_variant_dispatches{},room_variant_refusals{},room_variant_world_cases{};
void room_variant_vm_tests(){
    ActorFixture actors;auto& variants=actors.session->room_variants;std::vector<std::uint8_t> ram(0x800000);
    actors.export_original(ram);ram[0x4b9d1f]=0x81;ram[0x4b9da0]=0x79;
    for(unsigned room=0;room<128;++room)for(unsigned value=0;value<256;++value){
        const auto raw=value|((room*257+value)<<8);fixture_write(ram.data(),0x20000,room);fixture_write(ram.data(),0x20004,raw);
        R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,4,0x20000);SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);o2_0068ECA0_0x68eca0(ram.data(),&c,&runtime);
        check(c.pc==0xdeadbeef&&GPR_U32(&c,2)==0&&variants.store(room,raw));
        for(unsigned i=0;i<128;++i)check(variants.get(i)==ram[0x4b9d20+i]);
        check(ram[0x4b9d1f]==0x81&&ram[0x4b9da0]==0x79);++room_variant_handlers;
    }
    for(unsigned selected=0;selected<4;++selected)for(unsigned room:{0u,7u,127u})for(unsigned value:{0u,1u,255u,0xffffff80u,0xffffffffu}){
        std::vector<std::byte> b;emit(b,0x110,{0,77});emit(b,0x5a,{room,value});emit(b,0x110,{1,88});const auto end=emit(b,0xa);
        run({b},{0,end},1,selected%6,std::uint8_t(selected));++room_variant_dispatches;
    }
    check(vm::Interpreter::coverage()[0x5a].native_algorithm&&vm::Interpreter::coverage()[0x5a].world_required);
    // Offline701840 also refreshes the canonical navigation owner. Its cold,
    // warm and missing-provider cases live in verify_offline_room_variants.py.
    check(vm::Interpreter::coverage(vm::DispatchProfile::offline_actor)[0x5a].native_algorithm);
    for(unsigned room:{128u,256u,0xffffffffu}){check(!variants.store(room,99)&&!variants.get(room));++room_variant_refusals;}
    for(unsigned room:{128u,0xffffffffu}){
        std::vector<std::byte> b;emit(b,0x110,{0,77});emit(b,0x5a,{room,1});emit(b,0xa);vm::Interpreter interpreter;
        check(interpreter.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b}))==vm::Status::completed);
        check(interpreter.tick(0,{}).status==vm::Status::provider_unavailable&&interpreter.counters()[0]==0);
        vm::Providers providers;providers.world=&actors.world;
        check(interpreter.tick(0,{},providers).status==vm::Status::provider_unavailable&&interpreter.counters()[0]==77);++room_variant_refusals;
    }
    {bool refused=false;try{std::vector<std::byte> b;emit(b,0x5a,{7});vm::Program program({b});}catch(const std::invalid_argument&){refused=true;}check(refused);++room_variant_refusals;}
    // Real World navigation holds this same session owner. Script writes do
    // not silently rebind loaded graph pointers; the original binds explicitly.
    namespace nav=reo::native::gameplay_navigation;
    std::vector<std::uint8_t> bytes(116);
    for(const auto [at,value]:{std::pair{0u,0x20030724u},{4u,12u},{8u,16u},{16u,1u},{20u,7u},{24u,32u},{32u,12u},{36u,20u}})fixture_write(bytes.data(),at,value);
    nav::ImportFailure failure;auto asset=nav::Asset::read(bytes,failure);check(bool(asset));auto shared=std::make_shared<const nav::Asset>(std::move(*asset));
    variants.store(7,0);auto& bank=actors.world.navigation();check(bank.bind(shared)&&bank.room(7));++room_variant_world_cases;
    std::vector<std::byte> b;emit(b,0x5a,{7,1});emit(b,0xa);vm::Interpreter interpreter;
    check(interpreter.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b}))==vm::Status::completed);vm::Providers providers;providers.world=&actors.world;
    check(interpreter.tick(0,{},providers).status==vm::Status::yielded&&variants.get(7)==1&&bank.room(7));++room_variant_world_cases;
    check(bank.bind(shared)&&!bank.room(7));++room_variant_world_cases;
    check(actors.world.close()==reo::native::gameplay_world::Status::completed&&!bank.bound()&&!bank.bind(shared)&&!bank.occupancy(7,0));++room_variant_world_cases;
    bool closed=false;try{(void)actors.world.navigation();}catch(const std::runtime_error&){closed=true;}check(closed);
    check(interpreter.tick(0,{},providers).status==vm::Status::provider_unavailable);++room_variant_refusals;
}
}
