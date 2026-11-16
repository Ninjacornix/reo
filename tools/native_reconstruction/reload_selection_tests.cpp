#include "game/native/gameplay_world/reload_selection.hpp"
#include <fstream>
#include <cstdio>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
namespace {
constexpr unsigned actor_at=0x10000,done=0x1234;
unsigned checks{},cases{},sample{},entry{};
void check(bool value){++checks;if(!value)throw std::runtime_error("reload check "+std::to_string(checks)+" sample "+std::to_string(sample)+" entry "+std::to_string(entry));}
}
PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{
    throw std::runtime_error("Unexpected reload dependency "+std::to_string(at));
}
int main(int argc,char** argv)try{
    check(argc==2);std::vector<std::uint8_t> ram(0x800000);
    std::ifstream image(argv[1],std::ios::binary);check(bool(image));
    image.read(reinterpret_cast<char*>(ram.data()+0x570000),0x800000-0x570000);check(image.gcount()>0x719a60-0x570000);
    w::animation_events::File1Metadata metadata;PS2Runtime runtime;
    constexpr std::array<std::int16_t,9> quantities{-32768,-1,0,1,5,10,20,21,32767};
    for(sample=0;sample<16384;++sample){
        s::SceneResources resources;s::ResourceTemplates templates;w::Actor actor;
        std::vector<std::byte> section(32+129*24+384*2);
        const auto write=[&]<class T>(unsigned at,T value){std::memcpy(section.data()+at,&value,sizeof value);};
        write(0,3u);write(4,129u);write(8,384u);write(12,0u);write(16,32u);write(28,32u+129u*24u);
        write(32+4,std::int16_t((sample%11)==0?-1:0));write(32+6,std::int16_t((sample%13)==0?0:4));
        write(32+8,std::int16_t(20));section[32+15]=std::byte(sample%32);
        const std::array<std::uint16_t,12> compatibility{
            std::uint16_t(sample%5),9,1,2,8,12,3,7,1,1,6,12};
        std::memcpy(section.data()+32+129*24,compatibility.data(),sizeof compatibility);
        check(templates.load(section));
        std::memcpy(ram.data()+0x74bb50,section.data()+32,129*24);
        std::memcpy(ram.data()+0x74c970,section.data()+32+129*24,384*2);
        actor.status=(sample&0x100u)?8u:0u;
        ref_write(ram.data(),actor_at+0xba0,actor.status);
        for(unsigned i=0;i<6;++i){
            s::SceneDescriptor item;item.active=std::uint8_t((sample+i)%5!=0);item.template_index=(sample+i)%7==0?255:0;
            item.parameter=quantities[(sample/(i+1)+i)%quantities.size()];item.attachment_id=std::uint16_t(i%4);
            check(bool(resources.load(i,item)));
            const auto at=0x3c5630+60*i;ram[at]=item.active;ram[at+0x2b]=item.template_index;
            ref_write(ram.data(),at+6,item.attachment_id);ref_write(ram.data(),at+0x24,item.parameter);
        }
        for(unsigned i=0;i<4;++i){actor.inventory.carried[i]=std::uint8_t((sample/(i+1)+i)%6);ram[actor_at+0xc84+i]=actor.inventory.carried[i];}
        const auto resource=std::uint8_t(sample%6);
        const auto invoke=[&](unsigned at,unsigned b,unsigned d){
            entry=at;++cases;R5900Context c{};c.g[4].lo=actor_at;c.g[5].lo=b;c.g[6].lo=d;c.g[29].lo=0x30000;c.g[31].lo=done;
            switch(at){case 0x586220:o2_00586220_0x586220(ram.data(),&c,&runtime);break;case 0x586310:o2_00586310_0x586310(ram.data(),&c,&runtime);break;case 0x586440:o2_00586440_0x586440(ram.data(),&c,&runtime);break;default:throw std::runtime_error("entry");}
            check(c.pc==done);return std::uint8_t(GPR_U32(&c,2));
        };
        for(unsigned mode=0;mode<3;++mode)check(invoke(0x586220,mode,sample%4)==w::select_inventory_quantity(actor,resources,std::uint8_t(mode),std::uint16_t(sample%4)));
        for(const auto mode:{1,12})check(invoke(0x586310,resource,unsigned(mode))==w::select_reload_source(actor,resources,templates,resource,std::int16_t(mode)));
        check(bool(invoke(0x586440,resource,0))==w::reload_available(actor,resources,templates,metadata,resource));
    }
    std::printf("{\"checks\":%u,\"cases\":%u,\"game_run\":false}\n",checks,cases);return 0;
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
