#include "original_fixture.hpp"
#include "original_declarations.inc"
#include "game/native/gameplay_scenario/scene_controls.hpp"
#include "game/native/gameplay_scenario/saved_controls.hpp"
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <vector>
namespace vm=reo::native::gameplay_scenario;
namespace {
std::size_t checks{},calls{};
void check(bool v){++checks;if(!v)throw std::runtime_error("Typed controls check "+std::to_string(checks));}
constexpr std::uint32_t base=0x500000,stride=256,saved_base=0x700000;
void project(std::uint8_t* ram,std::uint32_t at,const vm::SceneControl& r){
    fixture_write(ram,at+0x40,r.authored_id);ram[at+0x3c]=r.enabled;ram[at+0x32]=r.counter;
    std::visit([&](const auto& b){using T=std::decay_t<decltype(b)>;
        if constexpr(std::is_same_v<T,vm::ControlTypeZero>)ram[at+0x30]=0;
        else if constexpr(std::is_same_v<T,vm::ControlTypeOne>)ram[at+0x30]=1;
        else if constexpr(std::is_same_v<T,vm::ControlTypeTwo>){ram[at+0x30]=2;fixture_write(ram,at+0x50,b.selector);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeThree>){ram[at+0x30]=3;fixture_write(ram,at+0x44,b.mode);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeFour>){ram[at+0x30]=4;fixture_write(ram,at+0x44,b.selector);fixture_write(ram,at+0x64,b.mode);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeFive>)ram[at+0x30]=5;
        else if constexpr(std::is_same_v<T,vm::ControlTypeSix>){ram[at+0x30]=6;fixture_write(ram,at+0x54,b.selector);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeSeven>){ram[at+0x30]=7;fixture_write(ram,at+0x70,b.selector);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeNine>)ram[at+0x30]=9;
        else if constexpr(std::is_same_v<T,vm::ControlTypeEleven>)ram[at+0x30]=11;
        else if constexpr(std::is_same_v<T,vm::ControlTypeThirteen>){ram[at+0x30]=13;fixture_write(ram,at+0x44,b.selector);}
        else ram[at+0x30]=b.type;
    },r.body);
}
std::vector<vm::SceneControl> initial(){
    std::vector<vm::SceneControl> records;
    for(const auto id:{0u,42u,UINT32_MAX}){
        const auto add=[&](vm::SceneControlBody b){records.push_back({id,0x81,std::move(b)});};
        add(vm::ControlTypeZero{});add(vm::ControlTypeOne{});
        for(const auto v:{0u,1u,2u,7u,UINT32_MAX}){add(vm::ControlTypeTwo{v});add(vm::ControlTypeThree{v});add(vm::ControlTypeFour{v,v^1u});}
        add(vm::ControlTypeFive{});add(vm::ControlTypeSix{id});add(vm::ControlTypeSeven{id});
        add(vm::ControlTypeNine{});add(vm::ControlTypeEleven{});add(vm::ControlTypeThirteen{id});add(vm::ControlOther{255});
    }
    return records;
}
std::vector<vm::SavedControl> saved_initial(){
    std::vector<vm::SavedControl> values;
    for(unsigned type=0;type<16;++type)for(const auto id:{0u,42u,255u})for(unsigned sel=0;sel<4;++sel)
        values.push_back({0x81,std::uint8_t(type),std::uint8_t(id),std::uint8_t(sel)});
    return values;
}
void call(PS2Runtime::Function fn,std::vector<std::uint8_t>& ram){
    R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,4,0x10000);SET_GPR_U32(&c,29,0x8f0000);SET_GPR_U32(&c,31,0xdeadbeef);
    fn(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);check(GPR_U32(&c,2)==0);++calls;
}
}
int main()try{
    std::vector<std::uint8_t> ram(0x900000),expected(0x900000);
    const auto records=initial();const auto saved=saved_initial();
    constexpr std::array<PS2Runtime::Function,4> functions{o2_006920E0_0x6920e0,o2_006922B0_0x6922b0,o2_007020E0_0x7020e0,o2_00702380_0x702380};
    for(unsigned fn=0;fn<4;++fn)for(unsigned owner=0;owner<3;++owner)for(unsigned relation=0;relation<2;++relation)for(bool enabled:{false,true})
    for(const auto type:{0u,1u,2u,3u,4u,5u,6u,7u,9u,11u,13u,14u,255u,UINT32_MAX})
    for(const auto id:{0u,42u,255u,UINT32_MAX})for(const auto selector:{0u,1u,2u,7u,UINT32_MAX}){
        vm::SceneControls live;live.enabled(enabled);std::vector<vm::SceneControlId> ids;ids.reserve(records.size());
        for(std::size_t i=0;i<records.size();++i){const auto at=base+std::uint32_t(i)*stride;std::fill(ram.begin()+at,ram.begin()+at+stride,0xa5);project(ram.data(),at,records[i]);fixture_write(ram.data(),at+0x28,i+1<records.size()?at+stride:0u);ids.push_back(*live.append(records[i]));}
        fixture_write<std::int16_t>(ram.data(),0x3b5150,enabled?-1:128);fixture_write(ram.data(),0x3b5160,base);
        fixture_write(ram.data(),0x10000,type);fixture_write(ram.data(),0x10004,id);fixture_write(ram.data(),0x10008,selector);
        fixture_write(ram.data(),0x75a4b8,owner);fixture_write(ram.data(),0x75a4c0,relation);
        vm::SavedControlRecords snapshots;
        for(unsigned bank=0;bank<3;++bank){check(snapshots.restore(bank,saved));const auto start=saved_base+bank*0x10000u;
            fixture_write(ram.data(),0x83e5ec+bank*164u,start);fixture_write<std::int32_t>(ram.data(),0x83e5e8+bank*164u,std::int32_t(saved.size()));
            std::fill(ram.begin()+start,ram.begin()+start+saved.size()*16,0x5a);
            for(std::size_t i=0;i<saved.size();++i){const auto at=start+i*16;ram[at]=saved[i].enabled;ram[at+1]=saved[i].type;ram[at+2]=saved[i].authored_id;ram[at+3]=saved[i].selector;}
        }
        std::copy(ram.begin()+base,ram.begin()+base+records.size()*stride,expected.begin()+base);
        for(unsigned bank=0;bank<3;++bank){const auto at=saved_base+bank*0x10000u;std::copy(ram.begin()+at,ram.begin()+at+saved.size()*16,expected.begin()+at);}
        call(functions[fn],ram);const bool enable=(fn&1)==0;
        if(fn<2||relation==0)check(live.apply_typed(enable,type,id,selector).status==vm::ControlStatus::completed);
        if(fn>=2&&(relation!=0||enabled))check(snapshots.apply(owner,enable,type,id,selector));
        for(std::size_t i=0;i<ids.size();++i)project(expected.data(),base+std::uint32_t(i)*stride,*live.get(ids[i]));
        for(unsigned bank=0;bank<3;++bank){const auto result=snapshots.get(bank);for(std::size_t i=0;i<result.size();++i)expected[saved_base+bank*0x10000u+i*16]=result[i].enabled;}
        check(std::memcmp(expected.data()+base,ram.data()+base,records.size()*stride)==0);
        for(unsigned bank=0;bank<3;++bank)check(std::memcmp(expected.data()+saved_base+bank*0x10000u,ram.data()+saved_base+bank*0x10000u,saved.size()*16)==0);
    }
    // Native identity/profile limits must refuse before any mutation.
    vm::SceneControls live;const auto valid=*live.append({42,0x81,vm::ControlTypeSix{42}});live.append({42,0x81,vm::ControlOther{6}});
    check(live.apply_typed(true,6,42,0).status==vm::ControlStatus::invalid_profile);check(live.get(valid)->enabled==0x81);
    vm::SavedControlRecords limits(1);check(!limits.restore(0,saved));check(limits.get(0).empty());check(!limits.restore(3,{}));check(!limits.apply(3,true,0,0,0));
    check(limits.restore(0,std::span(saved).first(1)));check(limits.get(0).size()==1);check(!limits.restore(0,saved));check(limits.get(0).size()==1);
    std::cout<<"{\"checks\":"<<checks<<",\"original_invocations\":"<<calls<<",\"status\":\"passed\"}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
