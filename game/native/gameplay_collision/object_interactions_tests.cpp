#include "object_interactions.hpp"
#include "ownership_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <random>
#include <sstream>
namespace c=reo::native::gameplay_collision;
namespace r=c::room_objects;
unsigned checks{},rooms{},actions{},synthetic_variants{},alias_transfers{},request_wraps{};
std::vector<std::uint8_t> memory(0x800000);
void check(bool value,const char* why){++checks;if(!value){std::fprintf(stderr,"object interaction check%u failed: %s\n",checks,why);std::exit(1);}}
std::vector<std::byte> load(const char* path){std::ifstream f(path,std::ios::binary);const std::vector<char> bytes{std::istreambuf_iterator<char>(f),{}};const auto span=std::as_bytes(std::span(bytes));return{span.begin(),span.end()};}
std::uint32_t invoke(std::uint32_t pc,std::uint32_t a0=0,std::uint32_t a1=0){R5900Context ctx;ctx.pc=pc;ctx.g[29].lo=0x7f0000;ctx.g[31].lo=0x1234;ctx.g[4].lo=a0;ctx.g[5].lo=a1;PS2Runtime runtime;runtime.lookupFunction(pc)(memory.data(),&ctx,&runtime);return std::uint32_t(ctx.g[2].lo);}
void compare(const r::Owner& owner,const r::InteractionOwner& interactions){for(const auto& id:owner.objects()){const auto slot=interactions.source_ordinal(id);check(slot.has_value(),"owned opaque ID resolves checked authored physical ordinal");const auto* o=owner.get(id);const auto at=0x3c4580+60*unsigned(*slot);check(o->count==std::bit_cast<std::int8_t>(memory[at+0x1b])&&o->requests==std::bit_cast<std::int8_t>(memory[at+0x1c]),"actual canonical count/request signed-byte mutations");check(o->direction==memory[at+0x1d]&&o->secondary_direction==memory[at+0x1e]&&o->control_flags==ref_read<std::uint32_t>(memory.data(),at+0x24),"original transition/direction mutation order");}}
void room(const char* type_path,const char* sto_path,unsigned variant){
    auto types=load(type_path),sto=load(sto_path);auto* type_bytes=reinterpret_cast<std::uint8_t*>(types.data());auto* sto_bytes=reinterpret_cast<std::uint8_t*>(sto.data());const auto type_count=ref_read<std::uint32_t>(type_bytes,4),type_offset=ref_read<std::uint32_t>(type_bytes,8),model_offset=ref_read<std::uint32_t>(type_bytes,12);const auto count=ref_read<std::uint32_t>(sto_bytes,4);
    if(variant){for(unsigned i=0;i<type_count;++i){type_bytes[type_offset+8*i+1]=std::uint8_t(3+i);type_bytes[type_offset+8*i+2]=std::uint8_t(1+i);type_bytes[type_offset+8*i+4]=std::uint8_t(0x80+i);type_bytes[type_offset+8*i+5]=std::uint8_t(250-i);ref_write(type_bytes,type_offset+8*i+6,std::uint16_t((i%3)*0x10));}for(unsigned i=0;i<count;++i)sto_bytes[8+16*i+6]=std::uint8_t((i*5+variant)&15);++synthetic_variants;}
    auto owner=r::Owner::import(types,sto);r::InteractionOwner interactions(owner);invoke(0x6acf80);std::memset(memory.data()+0x74b1c0,0,256);std::memcpy(memory.data()+0x74b1c0,type_bytes+type_offset,type_count*8);if(model_offset)std::memcpy(memory.data()+0x74b180,type_bytes+model_offset,type_count*2);for(unsigned i=0;i<count;++i){std::memcpy(memory.data()+0x1000,sto_bytes+8+16*i,16);check(invoke(0x6ad0f0,0x1000)!=0,"original imported object allocation");}
    const auto ids=owner.objects();check(!ids.empty(),"owned object set admitted");std::mt19937 random(0x6b0510+variant);
    for(unsigned i=0;i<3000;++i){const auto id=ids[random()%ids.size()];const auto slot=*interactions.source_ordinal(id);const auto token=std::uint8_t(slot|(std::uint8_t(random()%8)<<5));const auto heading=std::uint16_t(random());const auto action=i%8;const bool gate=i%3!=0;memory[80]=gate;
        if(action==0){interactions.increment(id);invoke(0x6af380,token);}
        else if(action==1){interactions.decrement(id);invoke(0x6af3e0,token);}
        else if(action==2){check(interactions.below_capacity(id)==bool(invoke(0x6af430,token)),"original below-capacity/transition predicate");}
        else if(action==3){check(interactions.claim_secondary(id,heading,gate)==bool(invoke(0x6b0410,token,heading)),"original input-gated direction claim");}
        else if(action==4){interactions.request_primary(id,heading);invoke(0x6b0510,token,heading);}
        else if(action==5){interactions.clear_secondary(id);invoke(0x6b05b0,token);}
        else if(action==6){interactions.decay(id);invoke(0x6b05f0,token);}
        else{const auto old=std::uint8_t(random()),next=std::uint8_t(random());interactions.transfer(std::bit_cast<std::int8_t>(old),std::bit_cast<std::int8_t>(next));invoke(0x6afae0,old,next);}
        check(interactions.masked(token)==std::optional<r::ObjectId>(id),"masked adapter preserves native owner identity");const auto selector=std::uint8_t(random());const auto p=interactions.parameters(selector);check(std::uint8_t(p.request_threshold)==std::uint8_t(invoke(0x6b0f20,selector))&&std::uint8_t(p.parameter4)==std::uint8_t(invoke(0x6b0f70,selector))&&p.parameter5==std::uint8_t(invoke(0x6b0fc0,selector)),"original full-byte/fallback-record31 type parameters");compare(owner,interactions);++actions;
    }
    // Select the existing direction if present, otherwise retain the zero/first
    // direction path, so signed requests necessarily pass127to-128.
    for(unsigned i=0;i<260;++i){const auto id=ids.back();const auto slot=*interactions.source_ordinal(id);const auto* o=owner.get(id);const auto d=o->direction;const auto old=o->requests;const auto heading=std::uint16_t(d==2?0x4000:d==4?0x8000:d==8?0xc000:0);interactions.request_primary(id,heading);invoke(0x6b0510,slot,heading);compare(owner,interactions);if(old==127&&owner.get(id)->requests==-128)++request_wraps;++actions;}
    if(variant){const auto id=ids.front();const auto slot=*interactions.source_ordinal(id);for(unsigned i=0;i<20;++i){interactions.increment(id);invoke(0x6af380,slot);}const auto at_capacity=owner.get(id)->count;interactions.transfer(std::int8_t(slot+32),std::int8_t(slot));invoke(0x6afae0,slot+32,slot);compare(owner,interactions);check(owner.get(id)->count==at_capacity-1,"source alias equality is tested before physical slot masking");++alias_transfers;}
    auto foreign=r::Owner::import(types,sto);r::InteractionOwner other(foreign);const auto before=owner.get(ids[0])->count;other.increment(ids[0]);check(owner.get(ids[0])->count==before&&!other.source_ordinal(ids[0]),"foreign object identity cannot mutate or disclose another owner");++rooms;
}
int main(int argc,char** argv){check(argc==3,"owned room manifest/profile arguments");const auto profiles=load(argv[2]);check(profiles.size()==200,"ten owned footprint profiles");std::memcpy(memory.data()+0x723740,profiles.data(),200);for(unsigned i=0;i<4;++i)memory[0x719900+i]=std::uint8_t(i*2);std::ifstream manifest(argv[1]);std::string line;while(std::getline(manifest,line)){std::istringstream fields(line);std::string types,sto;std::getline(fields,types,'\t');std::getline(fields,sto,'\t');if(types.empty())continue;room(types.c_str(),sto.c_str(),0);room(types.c_str(),sto.c_str(),1);}check(alias_transfers==7&&request_wraps>0,"source alias and signed request wrap coverage");check(rooms==14,"seven retail room resource sets and seven synthetic state variants");std::printf("{\"checks\":%u,\"rooms\":%u,\"actions\":%u,\"synthetic_variants\":%u,\"alias_transfers\":%u,\"request_wraps\":%u,\"game_launched\":false}\n",checks,rooms,actions,synthetic_variants,alias_transfers,request_wraps);}
