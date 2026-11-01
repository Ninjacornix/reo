#include "ps2_runtime.h"
#include "ps2_syscalls.h"
#include "RPC.h"
#include "Helpers/CriAudio.h"
#include "../../runtime/audio/host_bridge.h"
#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>
namespace {
unsigned checks=0;
void check(bool ok,const char* why){++checks;if(!ok)throw std::runtime_error(why);}
struct Session {
    std::vector<uint8_t> ram=std::vector<uint8_t>(PS2_RAM_SIZE);
    R5900Context ctx{};
    PS2Runtime runtime;
    static constexpr uint32_t client=0x20000,send=0x21000,recv=0x22000,work=0x23000;
    void word(uint32_t at,uint32_t value){std::memcpy(ram.data()+at,&value,4);}
    uint32_t word(uint32_t at){uint32_t value;std::memcpy(&value,ram.data()+at,4);return value;}
    void reg(unsigned i,uint32_t value){ctx.r[i]=_mm_set_epi64x(0,value);}
    uint32_t rpc(uint32_t command,std::initializer_list<uint32_t> words){
        unsigned i=0;for(auto v:words)word(send+4*i++,v);
        reg(4,client);reg(5,command);reg(6,0);reg(7,send);reg(8,words.size()*4);
        reg(9,recv);reg(10,16);reg(11,0);
        ps2_syscalls::SifCallRpc(ram.data(),&ctx,&runtime);
        check(::getRegU32(&ctx,2)==0,"RPC transport succeeds");return word(recv);
    }
    Session(){
        runtime.memory().initialize();
        ps2_syscalls::clearDtxCompatLayout();
        PS2DtxCompatLayout layout{};layout.rpcSid=0x7d000000;layout.urpcObjBase=0x1f18000;
        layout.urpcObjLimit=0x1f1ff00;layout.urpcObjStride=0x20;layout.urpcFnTableBase=0x34fed0;
        layout.urpcObjTableBase=0x34ffd0;layout.dispatcherFuncAddr=0x2fabc0;
        ps2_syscalls::setDtxCompatLayout(layout);
        ps2_syscalls::SifInitRpc(ram.data(),&ctx,&runtime);ps2_cri_audio::render(nullptr,0);
        reg(4,client);reg(5,layout.rpcSid);reg(6,0);ps2_syscalls::SifBindRpc(ram.data(),&ctx,&runtime);
        check(::getRegU32(&ctx,2)==0,"Bind real DTX RPC");
        rpc(2,{1,work,work+0x400,0x100});
    }
    void playing(uint32_t voice,bool enabled){
        std::memset(ram.data()+work,0,0x100);word(work,1);word(work+0x10,2);
        word(work+0x14,voice);word(work+0x18,enabled?1:0);word(work+0xfc,1);
        ps2_syscalls::noteDtxSifDmaTransfer(ram.data(),work,work+0x400,0x100);
    }
    std::pair<uint32_t,uint32_t> stream(uint32_t buffer,int16_t value){
        const uint32_t ring=rpc(0x422,{1,buffer,0x4000});check(ring!=0,"Create ring");
        const uint32_t voice=rpc(0x408,{1,0,ring,0});check(voice!=0,"Create RNA voice");
        std::array<int16_t,512> pcm;pcm.fill(value);uint64_t end=0;
        check(ps2_cri_audio::queue(ring,reinterpret_cast<uint8_t*>(pcm.data()),sizeof(pcm),end),"Queue synthetic PCM");
        playing(voice,true);return {voice,ring};
    }
};
std::vector<float> render(unsigned n){std::vector<float> out(n*2);ps2_cri_audio::render(out.data(),n);return out;}
bool constant(const std::vector<float>& out,float value){return std::all_of(out.begin(),out.end(),[&](float v){return v==value;});}
}
int main() try {
    Session s;
    auto [music,musicRing]=s.stream(0x30000,4096);
    auto [speech,speechRing]=s.stream(0x40000,2048);
    check(constant(render(64),.1875f),"Music and speech audible before destroy");
    s.rpc(0x409,{music});
    check(constant(render(64),.0625f),"Destroy silences only the destroyed host voice");
    check(ps2_cri_audio::queuedSamples(musicRing)==448,"Destroyed voice stops consuming PCM");
    s.rpc(0x409,{music});
    check(constant(render(64),.0625f),"Repeated destroy preserves another voice");
    // A destroyed voice must not resume if its old ring later receives PCM.
    ps2_cri_audio::discard(musicRing);
    std::array<int16_t,256> pcm;pcm.fill(8192);uint64_t end=0;
    check(ps2_cri_audio::queue(musicRing,reinterpret_cast<uint8_t*>(pcm.data()),sizeof(pcm),end),"Refill old ring");
    check(constant(render(64),.0625f),"Old ring refill cannot resurrect destroyed voice");
    ps2_cri_audio::drain(speech);s.playing(speech,false);
    check(constant(render(256),.0625f),"Natural-end drain preserves accepted speech tail");
    check(constant(render(64),0),"Drained speech ends");
    auto [other,otherRing]=s.stream(0x50000,4096);
    ps2_cri_audio::drain(other);s.playing(other,false);s.rpc(0x409,{other});
    check(constant(render(64),0),"Destroy cancels a pending drain");
    check(ps2_cri_audio::queuedSamples(otherRing)==512,"Destroy does not consume a drained queue");
    std::cout<<"PASS "<<checks<<" RPC/audio transition checks\n";
    return 0;
} catch(const std::exception& e){std::cerr<<"FAIL after "<<checks<<" checks: "<<e.what()<<'\n';return 1;}
