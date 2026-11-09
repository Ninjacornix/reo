#include "original_fixture.hpp"
#include "original_declarations.inc"
#include "game/native/gameplay_scenario/scene_controls.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <type_traits>
#include <vector>
namespace vm=reo::native::gameplay_scenario;
namespace {
std::size_t checks{},invocations{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Scene control check "+std::to_string(checks));}
constexpr std::uint32_t first_node=0x500000,stride=0x100;
std::vector<std::pair<unsigned,std::uint32_t>> effects;
void done(R5900Context* c){c->pc=GPR_U32(c,31);}
void reset_body(vm::SceneControl& record){
    auto& five=std::get<vm::ControlTypeFive>(record.body);record.enabled=0x81;five.selector=0x9191;five.duration=0x8282;five.countdown=0x7373;five.completion=0xabcdefff;five.byte_parameter=0x64;five.secondary_parameter=0x5555;
}
void export_record(std::uint8_t* ram,std::uint32_t at,const vm::SceneControl& record){
    fixture_write(ram,at+0x40,record.authored_id);ram[at+0x3c]=record.enabled;
    std::visit([&](const auto& v){using T=std::decay_t<decltype(v)>;
        if constexpr(std::is_same_v<T,vm::ControlTypeZero>){ram[at+0x30]=0;fixture_write(ram,at+0x6c,v.parameter);fixture_write(ram,at+0x68,v.half_parameter);ram[at+0x72]=v.byte_parameter;ram[at+0x71]=v.refresh_parameter;}
        else if constexpr(std::is_same_v<T,vm::ControlTypeOne>){ram[at+0x30]=1;fixture_write(ram,at+0x86,v.parameter);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeTwo>){ram[at+0x30]=2;fixture_write(ram,at+0x50,v.selector);fixture_write(ram,at+0x6c,v.parameter);fixture_write(ram,at+0x68,v.half_parameter);ram[at+0x72]=v.byte_parameter;ram[at+0x71]=v.refresh_parameter;}
        else if constexpr(std::is_same_v<T,vm::ControlTypeThree>){ram[at+0x30]=3;fixture_write(ram,at+0x44,v.mode);fixture_write(ram,at+0x58,v.parameter);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeFour>){ram[at+0x30]=4;fixture_write(ram,at+0x64,v.mode);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeFive>){ram[at+0x30]=5;fixture_write(ram,at+0x50,v.selector);fixture_write(ram,at+0x6a,v.duration);fixture_write(ram,at+0x6c,v.countdown);fixture_write(ram,at+0x74,v.completion);ram[at+0x58]=v.byte_parameter;fixture_write(ram,at+0x56,v.secondary_parameter);
            fixture_write(ram,at+0x52,v.reset_sentinel);ram[at+0x59]=v.reset_byte_a;ram[at+0x6e]=v.reset_byte_b;}
        else if constexpr(std::is_same_v<T,vm::ControlTypeNine>){ram[at+0x30]=9;fixture_write(ram,at+0x44,v.parameter);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeThirteen>){ram[at+0x30]=13;fixture_write(ram,at+0x44,v.selector);fixture_write(ram,at+0x62,v.parameter);}
        else ram[at+0x30]=v.type;
    },record.body);
}
struct FixtureEffects final:vm::ControlEffects{
    const std::vector<vm::SceneControlId>* ids{};std::vector<std::pair<unsigned,std::uint32_t>> calls;
    bool skip_next{};
    void reset(vm::SceneControls& owner,const vm::SceneControlId& id)noexcept override{
        const auto found=std::find(ids->begin(),ids->end(),id);if(found==ids->end())std::terminate();const auto index=std::uint32_t(found-ids->begin());
        calls.emplace_back(0,index);auto record=*owner.get(id);reset_body(record);owner.replace(id,record);
        if(skip_next&&index==0)owner.erase((*ids)[1]);
    }
    void refresh(vm::SceneControls&,const vm::SceneControlId&,std::uint8_t id)noexcept override{calls.emplace_back(1,id);}
};
std::vector<vm::SceneControl> initial_records(){
    std::vector<vm::SceneControl> result;
    const auto add=[&](vm::SceneControlBody body,std::uint32_t id=42){result.push_back({id,0x80,std::move(body)});};
    add(vm::ControlTypeZero{0x12345678,0xabcd,0x56,0x78});add(vm::ControlTypeZero{0xffffffff,1,0xff,0x80},43);
    add(vm::ControlTypeOne{0xbeef});
    for(auto selector:{0u,7u,0xffffffffu})add(vm::ControlTypeTwo{selector,0x87654321,0xfedc,0x98,0xa9});
    for(unsigned mode=0;mode<5;++mode)add(vm::ControlTypeThree{mode,0x8172});
    for(unsigned mode=0;mode<3;++mode)add(vm::ControlTypeFour{mode});
    add(vm::ControlTypeFive{1,2,3,4,0x11223344,0x55});add(vm::ControlTypeFive{6,7,8,9,0x88776655,0x44});
    add(vm::ControlTypeNine{0x12345678});add(vm::ControlTypeThirteen{42,0xcafe},43);add(vm::ControlOther{6});
    return result;
}
std::uint32_t call(PS2Runtime::Function fn,std::vector<std::uint8_t>& ram){
    R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,4,0x10000);SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);
    fn(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++invocations;return GPR_U32(&c,2);
}
bool skip_original_next{};
}
void o2_005C45C0_0x5c45c0(std::uint8_t* r,R5900Context* c,PS2Runtime*){
    const auto at=GPR_U32(c,4),index=(at-first_node)/stride;effects.emplace_back(0,index);
    r[at+0x3c]=0x81;fixture_write<std::uint16_t>(r,at+0x50,0x9191);fixture_write<std::uint16_t>(r,at+0x6a,0x8282);fixture_write<std::uint16_t>(r,at+0x6c,0x7373);
    fixture_write<std::uint32_t>(r,at+0x74,0xabcdefff);r[at+0x58]=0x64;fixture_write<std::uint16_t>(r,at+0x56,0x5555);
    if(skip_original_next&&index==0)fixture_write<std::uint32_t>(r,at+0x28,first_node+2*stride);
    done(c);
}
void o2_006B5E10_0x6b5e10(std::uint8_t*,R5900Context* c,PS2Runtime*){effects.emplace_back(1,GPR_U32(c,4));done(c);}
int main()try{
    constexpr std::array<PS2Runtime::Function,18> originals{o2_0068E630_0x68e630,o2_0068E6D0_0x68e6d0,o2_0068E730_0x68e730,o2_0068E800_0x68e800,o2_0068E8B0_0x68e8b0,
        o2_0068E920_0x68e920,o2_0068E9E0_0x68e9e0,o2_0068EA70_0x68ea70,o2_0068EB30_0x68eb30,o2_0068EBF0_0x68ebf0,
        o2_0068ECC0_0x68ecc0,o2_0068ED30_0x68ed30,o2_0068EDA0_0x68eda0,o2_0068EE30_0x68ee30,o2_0068EEC0_0x68eec0,o2_0068F5C0_0x68f5c0,o2_00691F00_0x691f00,o2_00690810_0x690810};
    std::vector<std::uint8_t> ram(0x800000),expected(0x800000);const auto initial=initial_records();
    for(unsigned command=0;command<originals.size();++command)for(const auto parameter:{0u,1u,0x8000u,0x12345678u,0xffffffffu})for(const auto selector:{0u,7u,0xffffffffu})for(bool disabled:{false,true})for(const auto id:{42u,43u,99u}){
        vm::SceneControls native;native.enabled(!disabled);std::vector<vm::SceneControlId> ids;
        std::fill(ram.begin()+first_node,ram.begin()+first_node+initial.size()*stride,0xa5);
        for(std::size_t i=0;i<initial.size();++i){ids.push_back(*native.append(initial[i]));export_record(ram.data(),first_node+std::uint32_t(i)*stride,initial[i]);fixture_write<std::uint32_t>(ram.data(),first_node+std::uint32_t(i)*stride+0x28,i+1<initial.size()?first_node+std::uint32_t(i+1)*stride:0u);}
        fixture_write<std::uint32_t>(ram.data(),0x3b5160,first_node);fixture_write<std::int16_t>(ram.data(),0x3b5150,disabled?128:-1);
        fixture_write(ram.data(),0x10000,id);fixture_write(ram.data(),0x10004,parameter);fixture_write(ram.data(),0x10008,selector);fixture_write<std::uint16_t>(ram.data(),0x1000c,0x87fe);
        std::copy(ram.begin()+first_node,ram.begin()+first_node+initial.size()*stride,expected.begin()+first_node);effects.clear();
        check(call(originals[command],ram)==0);FixtureEffects provider;provider.ids=&ids;provider.calls.reserve(128);
        const auto result=native.apply(vm::ControlCommand(command),{id,parameter,selector,0x87fe},&provider);check(result.status==vm::ControlStatus::completed);
        check(result.visited==(disabled?0:initial.size()));check(provider.calls==effects);
        for(std::size_t i=0;i<ids.size();++i){export_record(expected.data(),first_node+std::uint32_t(i)*stride,*native.get(ids[i]));check(std::memcmp(expected.data()+first_node+i*stride,ram.data()+first_node+i*stride,stride)==0);}
    }
    // Actual type-five reset is now native. Refresh still requires its actual
    // scene-program effect provider before any record in the operation mutates.
    vm::SceneControls native;const auto id=*native.append({42,0,vm::ControlTypeFive{}});const auto before=*native.get(id);
    check(native.apply(vm::ControlCommand::restart_five,{42,1,2,3},nullptr).status==vm::ControlStatus::completed);check(native.get(id)->enabled==1);
    const auto zero=*native.append({42,0,vm::ControlTypeZero{}});const auto zero_before=*native.get(zero);
    check(native.apply(vm::ControlCommand::refresh_zero_two,{42,1,2,3},nullptr).status==vm::ControlStatus::provider_unavailable);check(native.get(zero)->enabled==zero_before.enabled);
    check(std::get<vm::ControlTypeZero>(native.get(zero)->body).refresh_parameter==std::get<vm::ControlTypeZero>(zero_before.body).refresh_parameter);
    check(before.enabled==0);
    check(native.apply(vm::ControlCommand::restart_five,{99,1,2,3},nullptr).status==vm::ControlStatus::completed);
    native.enabled(false);check(native.apply(vm::ControlCommand::restart_five,{42,1,2,3},nullptr).status==vm::ControlStatus::completed);native.enabled(true);
    // Post-callback traversal follows the current node's updated next link.
    vm::SceneControls traversal;std::vector<vm::SceneControlId> ids;
    std::fill(ram.begin()+first_node,ram.begin()+first_node+3*stride,0);
    for(unsigned i=0;i<3;++i){vm::SceneControl record{42,0,vm::ControlTypeFive{}};ids.push_back(*traversal.append(record));export_record(ram.data(),first_node+i*stride,record);fixture_write<std::uint32_t>(ram.data(),first_node+i*stride+0x28,i<2?first_node+(i+1)*stride:0u);}
    fixture_write<std::uint32_t>(ram.data(),0x3b5160,first_node);fixture_write<std::int16_t>(ram.data(),0x3b5150,0);fixture_write<std::uint32_t>(ram.data(),0x10000,42);
    skip_original_next=true;effects.clear();call(o2_0068E9E0_0x68e9e0,ram);skip_original_next=false;
    FixtureEffects provider;provider.ids=&ids;provider.skip_next=true;provider.calls.reserve(128);
    check(traversal.apply(vm::ControlCommand::reset_five,{42,0,0,0},&provider).status==vm::ControlStatus::completed);check(effects==provider.calls);check(provider.calls.size()==2);check(!traversal.get(ids[1]));
    const auto stale=id;native.erase(id);check(!native.get(stale));check(*native.append({42,0,vm::ControlTypeFive{}})!=stale);
    vm::SceneControls other;check(!other.get(stale));check(!native.get({}));native.clear();check(native.size()==0);
    vm::SceneControls bounded(1);check(bool(bounded.append({})));check(!bounded.append({}));bounded.clear();check(bool(bounded.append({})));
    vm::SceneControls limited;limited.append({42,0,vm::ControlTypeOne{}});limited.append({42,0,vm::ControlTypeOne{}});
    const auto limited_result=limited.apply(vm::ControlCommand::enable_one,{42,0,0,0},nullptr,1);check(limited_result.status==vm::ControlStatus::budget_exhausted);check(limited_result.visited==1);check(limited_result.matched==1);
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_invocations\":"<<invocations<<",\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
