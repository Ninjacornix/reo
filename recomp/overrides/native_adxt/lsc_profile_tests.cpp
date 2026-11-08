#include "lsc_profile.h"
#include "handle_fixture.hpp"
struct LscFixture:Fixture {
    std::uint32_t child{};
    LscFixture(unsigned parent=5,unsigned channels=2,unsigned child_slot=9,unsigned ring_slot=255,unsigned capacity=272384):Fixture(parent,channels){
        input=at(n::source_rings,ring_slot);child=at(n::lsc_children,child_slot);
        store(ram,handle+0x10,input);store(ram,decoder+8,input);store(ram,file+4,input);store(ram,handle+0x94,child);
        store(ram,input,0x224c28u);store(ram,input+4,1u);store(ram,input+0x10,capacity);store(ram,input+0x1c,0x1800000u);
        store(ram,input+0x20,capacity);store(ram,input+0x24,36u);store(ram,0x224c4c,0x13fa38u);
        ram[child]=1;store(ram,child+8,input);store(ram,child+0x14,capacity*8/10);store(ram,child+0x18,capacity);store(ram,child+0x28,file);
    }
    n::LscResult inspect_lsc(){return n::inspect_lsc(ram,handle);}
};
template<class F>void lsc_refuse(n::LscStatus status,F&& mutate){LscFixture f;mutate(f);const auto before=f.ram;const auto result=f.inspect_lsc();check(result.status==status && !result.value.address && f.ram==before);}
int main()try{
    for(unsigned parent=0;parent<16;++parent)for(unsigned channels:{1u,2u})for(unsigned child:{0u,15u}){
        const auto capacity=channels==1?53248u:272384u;LscFixture f(parent,channels,child,parent==15?255:0,capacity);const auto before=f.ram;auto result=f.inspect_lsc();
        check(result.status==n::LscStatus::ready && result.value.empty_history && result.value.slot==child && result.value.parent.slot==parent);
        check(result.value.capacity==capacity && result.value.minimum==capacity*8/10 && f.ram==before);
    }
    lsc_refuse(n::LscStatus::parent,[](auto& f){f.ram.pop_back();});
    for(auto child:{0u,0x21e111u,0x220490u,0xffffffffu})lsc_refuse(n::LscStatus::child,[=](auto& f){store(f.ram,f.handle+0x94,child);});
    lsc_refuse(n::LscStatus::inactive,[](auto& f){f.ram[f.child]=0;});
    lsc_refuse(n::LscStatus::links,[](auto& f){store(f.ram,f.child+8,f.input-0x40);});
    lsc_refuse(n::LscStatus::links,[](auto& f){store(f.ram,f.child+0x28,f.file+0x5c);});
    lsc_refuse(n::LscStatus::ring,[](auto& f){store(f.ram,f.input,0x23da58u);});
    lsc_refuse(n::LscStatus::ring,[](auto& f){store(f.ram,0x224c4c,0x13fa3cu);});
    lsc_refuse(n::LscStatus::ring,[](auto& f){store(f.ram,f.input+4,2u);});
    for(auto capacity:{0u,2049u,1048576u+2048u,0xffffffffu})lsc_refuse(n::LscStatus::geometry,[=](auto& f){store(f.ram,f.child+0x18,capacity);});
    lsc_refuse(n::LscStatus::geometry,[](auto& f){store(f.ram,f.child+0x14,272385u);});
    lsc_refuse(n::LscStatus::geometry,[](auto& f){store(f.ram,f.input+0x20,8192u);});
    lsc_refuse(n::LscStatus::geometry,[](auto& f){store(f.ram,f.input+0x24,35u);});
    lsc_refuse(n::LscStatus::ring,[](auto& f){store(f.ram,f.input+0xc,1u);});
    lsc_refuse(n::LscStatus::ring,[](auto& f){store(f.ram,f.input+0x10,0xffffffffu);});
    lsc_refuse(n::LscStatus::ring,[](auto& f){store(f.ram,f.input+0x1c,n::ram_bytes-272384u-32u);});
    for(unsigned offset:{1u,2u,4u})lsc_refuse(n::LscStatus::queue,[=](auto& f){f.ram[f.child+offset]=offset==1?3:2;});
    for(unsigned offset:{0x1cu,0x20u,0x24u})lsc_refuse(n::LscStatus::queue,[=](auto& f){store(f.ram,f.child+offset,offset==0x24?17u:16u);});
    lsc_refuse(n::LscStatus::callback,[](auto& f){store(f.ram,0x21dfd8,0x100100u);});
    LscFixture controls;controls.ram[controls.child+3]=255;controls.ram[controls.child+4]=1;store(controls.ram,controls.child+0x14,51200u);
    const auto changed=controls.inspect_lsc();check(changed.status==n::LscStatus::ready && changed.value.empty_history && changed.value.repeat==255 && changed.value.paused==1 && changed.value.minimum==51200);
    // Metadata is copied without chasing a queued filename or granting access.
    store(controls.ram,controls.child+0x3c,0xffffff00u);const auto history=controls.inspect_lsc();check(history.status==n::LscStatus::ready && !history.value.empty_history);
    std::cout<<"LSC profile checks="<<checks<<"; declared read-only RAM, no runtime/source authority\n";return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
