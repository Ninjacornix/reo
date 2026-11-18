#include "game/native/gameplay_world/action_notices.hpp"
#include <cstdio>
#include <stdexcept>
#include <vector>
namespace w=reo::native::gameplay_world;
int main()try{
    std::vector<std::uint8_t> ram(0x800000);w::Actor actor;PS2Runtime runtime;
    constexpr std::uint32_t base=0x10000,done=0x1234;unsigned cases{};
    auto compare=[&](unsigned primary,unsigned secondary,unsigned old_primary,unsigned old_secondary,std::int16_t quantity){
        actor.primary=std::uint8_t(primary);actor.secondary=std::uint8_t(secondary);
        actor.selected_resource=std::uint8_t(secondary^old_secondary);
        ram[base+8]=actor.primary;ram[base+9]=actor.secondary;ram[base+0xc7c]=actor.selected_resource;
        ref_write(ram.data(),0x3c5654+60*actor.selected_resource,quantity);
        R5900Context c{};c.g[4].lo=base;c.g[5].lo=old_primary;c.g[6].lo=old_secondary;c.g[31].lo=done;
        o2_006651F0_0x6651f0(ram.data(),&c,&runtime);
        const auto result=w::suppress_action_notice(actor,old_primary,old_secondary,quantity);
        ++cases;
        if(c.pc!=done||!result||*result!=(c.g[2].lo!=0)){
            std::fprintf(stderr,"notice mismatch p=%u s=%u old=%u/%u quantity=%d original=%llu native=%d\n",primary,secondary,old_primary,old_secondary,int(quantity),static_cast<unsigned long long>(c.g[2].lo),result?int(*result):-1);
            throw std::runtime_error("action notice comparison");
        }
        const auto unknown=w::suppress_action_notice(actor,old_primary,old_secondary,{});
        if((primary==2&&secondary==2)?bool(unknown):unknown!=result)throw std::runtime_error("notice resource dependency");
    };
    for(unsigned p=0;p<256;++p)for(unsigned s=0;s<256;++s)compare(p,s,0,0,0);
    for(unsigned oldp:{0u,1u,2u,255u,0x102u})
        for(unsigned olds=0;olds<256;++olds)for(unsigned s=0;s<256;++s)
            for(std::int16_t quantity:{std::int16_t(0),std::int16_t(1),std::int16_t(-1),std::int16_t(-32768)})
                compare(2,s,oldp,olds|0x100u,quantity);
    std::printf("{\"cases\":%u,\"original_calls\":%u,\"game_run\":false}\n",cases,cases);
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
