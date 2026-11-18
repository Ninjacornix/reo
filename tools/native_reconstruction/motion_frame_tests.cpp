#include "game/native/gameplay_world/animation.hpp"
#include <cstdio>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace {
unsigned checks{},cases{};
constexpr unsigned actor_at=0x10000,bank_at=0x40000,descriptor_at=0x50000,header_at=0x60000,done=0x1234;
a::PackedMotion packed; a::DecodedMotion decoded;bool present=true;
void check(bool v){++checks;if(!v)throw std::runtime_error("motion frame check "+std::to_string(checks)+" case "+std::to_string(cases));}
template<class Buffer,class T>void put(Buffer& b,unsigned at,T v){check(at+sizeof(T)<=b.size());std::memcpy(b.data()+at,&v,sizeof v);}
struct Prelude final:w::MotionPrelude{void run(w::World&,w::Actor&,float)override{throw std::runtime_error("Unexpected frame query prelude");}};
void port(std::uint8_t* ram,R5900Context* c,PS2Runtime*){
    switch(c->pc){
    case 0x5d46c0:std::memcpy(ram+descriptor_at,packed.bytes.data(),8);SET_GPR_U32(c,2,descriptor_at);break;
    case 0x5d4570:{const auto at=GPR_U32(c,5);ram[at]=decoded.family;ref_write(ram,at+8,decoded.channel_one);ref_write(ram,at+10,decoded.channel_zero);break;}
    case 0x5d4810:SET_GPR_U32(c,2,present?bank_at:0);break;
    case 0x18dca0:check(GPR_U32(c,4)==1);SET_GPR_U32(c,2,header_at);break;
    case 0x192d80:sub_00192D80_0x192d80(ram,c,nullptr);return;
    default:throw std::runtime_error("Unexpected frame query port "+std::to_string(c->pc));
    }c->pc=GPR_U32(c,31);
}
std::shared_ptr<a::MotionBank> bank(std::vector<std::uint8_t>& ram,unsigned variant){
    // Independent raw asset fixture: first key differs from loop restart.
    std::vector<std::byte> raw(168);put(raw,4,2u);put(raw,12,168u);
    const auto zero=decoded.channel_zero&0x7fffu,one=decoded.channel_one&0x7fffu;
    check(zero<2000&&one<2000);
    std::vector<unsigned> offsets;
    for(unsigned group=0;group<20;++group){unsigned count=0;if(zero/100==group)count=std::max(count,(zero%100+1)*2);if(one/100==group)count=std::max(count,(one%100+1)*2);
        const auto start=unsigned(raw.size());put(raw,8+group*8,count);put(raw,12+group*8,start);raw.resize(raw.size()+count*4,std::byte{255});
        for(const auto key:{zero,one})if(key/100==group)for(unsigned track=0;track<2;++track)offsets.push_back(start+4*((key%100)*2+track));
    }
    const auto clip_at=unsigned(raw.size());raw.resize(raw.size()+60);
    for(const auto at:offsets)put(raw,at,clip_at);
    put(raw,clip_at,1u);put(raw,clip_at+4,1u);put(raw,clip_at+8,60u);put(raw,clip_at+12,variant%2);put(raw,clip_at+16,float(int(variant%7)-2));
    put(raw,clip_at+24,1u);put(raw,clip_at+28,40u);put(raw,clip_at+32,0x80210001u);put(raw,clip_at+36,2u);put(raw,clip_at+40,28u);
    put(raw,clip_at+44,1.f);put(raw,clip_at+48,2.f);put(raw,clip_at+52,2.f);put(raw,clip_at+56,20.f);
    auto result=std::make_shared<a::MotionBank>();result->load_sparse(raw,8,0,"frame-query-fixture");
    for(unsigned row=0;row<2000;++row)put(ram,bank_at+0xfa4+2*row,result->rows()[row]);
    for(unsigned slot=0;slot<2000;++slot)put(ram,bank_at+4+2*slot,std::uint16_t(result->slots()[slot]?1:0));
    put(ram,header_at,std::uint16_t(variant%2?0x8000:0));put(ram,header_at+8,20.f);put(ram,header_at+12,float(int(variant%7)-2));
    return result;
}
}
PS2Runtime::Fn PS2Runtime::lookupFunction(unsigned at)const{
    if(at==0x192d80)return sub_00192D80_0x192d80;
    if(at==0x192da0)return sub_00192DA0_0x192da0;
    if(at==0x18dca0||at==0x5d46c0||at==0x5d4570||at==0x5d4810)return port;
    throw std::runtime_error("Unexpected frame query dependency "+std::to_string(at));
}
int main()try{
    std::vector<std::uint8_t> ram(0x800000);std::vector<std::byte> skeleton(112);put(skeleton,4,2u);put(skeleton,8,112u);put(skeleton,16,1u);put(skeleton,20,16u);
    put(skeleton,28,1u);put(skeleton,32,1u);put(skeleton,36,84u);put(skeleton,48,-1);put(skeleton,52,-1);
    auto definition=a::Skeleton::import_raw(skeleton);w::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<w::Session>());
    auto owned=std::make_unique<w::Actor>();owned->model=std::make_shared<a::Instance>(definition);owned->animation=std::make_shared<a::Playback>(owned->model);owned->animation->resources_known=true;
    const auto id=world.spawn_primary(0,std::move(owned)).id;auto actor=world.resolve(id);check(bool(actor));
    w::WorldMotionResources resources(world);w::File1MotionProfiles profiles;Prelude prelude;w::WorldAnimation motion(world,resources,profiles,prelude);a::File1MotionDescriptors descriptors;PS2Runtime runtime;
    for(const auto key:{0x2003u,0x2005u,0x2010u,0x2013u}){
        packed=descriptors.resolve({},key);decoded=descriptors.unpack({},packed);
        for(unsigned variant=0;variant<14;++variant){const auto value=bank(ram,variant);for(auto& bound:actor->animation->resources)bound=value;
            for(unsigned track=0;track<2;++track)for(unsigned frame=0;frame<32;++frame){++cases;
                auto& timing=actor->animation->channel(a::ModelBank::primary,track).timing;timing.frame=float(frame);timing.restart=5;timing.end=variant<2?4.f:25.f;
                const auto at=actor_at+0x1e4+32*track;put(ram,at,timing.frame);put(ram,at+4,timing.end);put(ram,at+8,timing.restart);
                for(const auto entry:{0x5d4a10u,0x5d4930u,0x5d4b10u}){R5900Context c{};c.g[4].lo=actor_at;c.g[5].lo=key;c.g[6].lo=track;c.g[29].lo=0x30000;c.g[31].lo=done;
                    float native{};
                    if(entry==0x5d4a10){o2_005D4A10_0x5d4a10(ram.data(),&c,&runtime);native=motion.first_frame(id,key,std::uint16_t(track));}
                    else if(entry==0x5d4930){o2_005D4930_0x5d4930(ram.data(),&c,&runtime);native=motion.last_frame(id,key,std::uint16_t(track));}
                    else{o2_005D4B10_0x5d4b10(ram.data(),&c,&runtime);native=motion.matched_frame(id,key,std::uint16_t(track));}
                    check(c.pc==done);check(std::bit_cast<unsigned>(c.f[0])==std::bit_cast<unsigned>(native));
                }
            }
        }
    }
    std::printf("{\"checks\":%u,\"cases\":%u,\"game_run\":false}\n",checks,cases);return 0;
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
