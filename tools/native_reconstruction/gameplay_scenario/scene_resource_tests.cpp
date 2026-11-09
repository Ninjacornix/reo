#include "original_fixture.hpp"
#include "original_declarations.inc"
#include "game/native/gameplay_scenario/scene_resources.hpp"
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <vector>
namespace vm=reo::native::gameplay_scenario;
namespace {
std::size_t checks=0,invocations=0;
void check(bool value){++checks;if(!value)throw std::runtime_error("Scene resource check "+std::to_string(checks));}
constexpr std::uint32_t descriptor=0x3c5630+60*100,live=0x500000;
std::vector<std::tuple<vm::SceneEffect,std::uint8_t>> original_effects;
bool mutate_instance_indices{};
void done(R5900Context* c){c->pc=GPR_U32(c,31);}
struct Attachment final:vm::SceneAttachment{
    std::uint32_t flags{};
    void flag(std::uint32_t mask,bool set)noexcept override{flags=set?flags|mask:flags&~mask;}
};
struct Effects final:vm::SceneEffects{
    std::vector<std::tuple<vm::SceneEffect,std::uint8_t>> events;
    void apply(vm::SceneResources& resources,const vm::SceneResourceId& id,vm::SceneEffect effect,std::uint8_t index)noexcept override{
        events.emplace_back(effect,index);auto d=*resources.get(id);d.flags^=0x40000000u;
        if(mutate_instance_indices&&effect==vm::SceneEffect::release)d.instance_index=17;
        resources.replace(id,d);
    }
};
void effect(std::uint8_t* ram,R5900Context* c,vm::SceneEffect kind){
    const auto at=GPR_U32(c,4);const auto index=(kind==vm::SceneEffect::release||kind==vm::SceneEffect::retire_instance)?std::uint8_t(at):ram[at+2];
    original_effects.emplace_back(kind,index);
    const auto flags=fixture_read<std::uint32_t>(ram,descriptor+24);fixture_write(ram,descriptor+24,flags^0x40000000u);done(c);
    if(mutate_instance_indices&&kind==vm::SceneEffect::release)ram[descriptor+2]=17;
}
std::uint32_t call(PS2Runtime::Function fn,std::vector<std::uint8_t>& ram,std::int32_t id,std::int8_t value=0){
    R5900Context c;PS2Runtime runtime;SET_GPR_S32(&c,4,id);SET_GPR_S32(&c,5,value);SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);
    fn(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++invocations;return GPR_U32(&c,2);
}
void export_descriptor(std::vector<std::uint8_t>& ram,const vm::SceneDescriptor& d){
    std::fill(ram.begin()+descriptor,ram.begin()+descriptor+60,0);ram[descriptor]=d.active;ram[descriptor+1]=d.room;ram[descriptor+2]=d.instance_index;ram[descriptor+3]=d.kind;
    fixture_write(ram.data(),descriptor+4,d.authored_id);fixture_write(ram.data(),descriptor+24,d.flags);fixture_write(ram.data(),descriptor+28,d.primary?live:0u);
    fixture_write(ram.data(),descriptor+32,d.secondary?live+0x1000:0u);fixture_write(ram.data(),descriptor+40,d.ownership_tag);
    fixture_write(ram.data(),descriptor+6,d.attachment_id);fixture_write(ram.data(),descriptor+36,d.parameter);
}
}
void o2_00591620_0x591620(std::uint8_t* r,R5900Context* c,PS2Runtime*){effect(r,c,vm::SceneEffect::construct_primary);}
void o2_00591860_0x591860(std::uint8_t* r,R5900Context* c,PS2Runtime*){effect(r,c,vm::SceneEffect::construct_alternate);}
void o2_005B1850_0x5b1850(std::uint8_t* r,R5900Context* c,PS2Runtime*){effect(r,c,vm::SceneEffect::release);}
#include "scene_resource_attachment_tests.inc"
int main()try{
    std::vector<std::uint8_t> ram(0x800000);vm::SceneResources resources;vm::SceneDescriptor d;d.authored_id=42;d.instance_index=255;
    auto identity=resources.load(100,d);check(bool(identity));
    // Exact signed positive lookup and all256 slots, including inactive matches
    // and duplicate IDs: search never skips a descriptor just because inactive.
    for(const auto id:{-32768,-1,0,1,42,32767}){
        export_descriptor(ram,d);const auto address=call(o2_00592900_0x592900,ram,std::int16_t(id));const auto found=resources.lookup(std::int16_t(id));
        check(bool(found)==(address!=0));if(found)check(*found==*identity&&address==descriptor);
    }
    vm::SceneDescriptor duplicate=d;duplicate.active=0;const auto early=resources.load(0,duplicate);fixture_write<std::uint16_t>(ram.data(),0x3c5634,42);
    check(resources.lookup(42)==early);check(call(o2_00592900_0x592900,ram,42)==0x3c5630);resources.load(0,{});fixture_write<std::uint16_t>(ram.data(),0x3c5634,0);
    vm::SceneDescriptor last;last.authored_id=32767;const auto final=resources.load(255,last);fixture_write<std::uint16_t>(ram.data(),0x3c5630+255*60+4,32767);
    check(resources.lookup(32767)==final);check(call(o2_00592900_0x592900,ram,32767)==0x3c5630+255*60);
    constexpr std::array<PS2Runtime::Function,4> original_commands{o2_00592960_0x592960,o2_00592A10_0x592a10,o2_00592B00_0x592b00,o2_00592B90_0x592b90};
    for(const auto active:{0u,128u})for(const auto kind:{0u,255u})for(const auto room:{7u,263u})for(const auto owner:{0u,65535u})for(unsigned pointers=0;pointers<4;++pointers)for(const auto flags:{0u,0xffffffffu,0x20000000u}){
        d.active=std::uint8_t(active);d.kind=std::uint8_t(kind);d.room=7;d.ownership_tag=std::uint16_t(owner);d.flags=flags;
        const auto primary=std::make_shared<Attachment>(),secondary=std::make_shared<Attachment>();
        d.primary=(pointers&1)?primary:nullptr;d.secondary=(pointers&2)?secondary:nullptr;
        for(unsigned command=0;command<4;++command){
            check(resources.replace(*identity,d)==vm::SceneStatus::completed);export_descriptor(ram,d);fixture_write<std::uint16_t>(ram.data(),0x3243dc,std::uint16_t(room));original_effects.clear();
            call(original_commands[command],ram,42);Effects effects;effects.events.reserve(2);
            check(resources.command(*identity,vm::SceneCommand(command),std::uint16_t(room),&effects)==vm::SceneStatus::completed);
            check(resources.get(*identity)->flags==fixture_read<std::uint32_t>(ram.data(),descriptor+24));check(effects.events==original_effects);
        }
        resources.replace(*identity,d);export_descriptor(ram,d);
        check(*resources.inactive_or_flag29(*identity)==(call(o2_00592C20_0x592c20,ram,42)!=0));
        for(const auto value:{-128,-1,0,1,127}){
            resources.replace(*identity,d);export_descriptor(ram,d);primary->flags=0xa5a50800;fixture_write(ram.data(),live+0x23c,primary->flags);
            call(o2_00592D50_0x592d50,ram,42,std::int8_t(value));check(resources.flag800(*identity,std::int8_t(value))==vm::SceneStatus::completed);
            check(resources.get(*identity)->flags==fixture_read<std::uint32_t>(ram.data(),descriptor+24));check(primary->flags==fixture_read<std::uint32_t>(ram.data(),live+0x23c));
        }
    }
    // No hidden constructor fallback: a required capability refuses before
    // this operation mutates state. A no-effect command needs no provider.
    d.active=1;d.kind=1;d.room=7;d.ownership_tag=0;d.primary.reset();d.secondary.reset();d.flags=0x12345678;resources.replace(*identity,d);
    check(resources.command(*identity,vm::SceneCommand::enable,7,nullptr)==vm::SceneStatus::provider_unavailable);check(resources.get(*identity)->flags==d.flags);
    check(resources.command(*identity,vm::SceneCommand::enable,8,nullptr)==vm::SceneStatus::completed);
    // Generation and world identity distinguish retirement, reuse and an ID
    // retained after its world has been destroyed.
    const auto stale=*identity;identity=resources.load(100,d);check(bool(identity));check(stale!=*identity);check(!resources.get(stale));
    vm::SceneResources another;check(!another.get(*identity));check(!resources.get({}));check(!resources.load(256,d));
    check(resources.flag800(stale,1)==vm::SceneStatus::invalid_identity);check(!resources.inactive_or_flag29(stale));
    attachment_tests();
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_invocations\":"<<invocations<<",\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
