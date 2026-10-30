#include <windows.h>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <map>
#include <stdexcept>
#include <vector>
#if defined(REO_GAME_FILE1)
struct R5900Context { uint32_t r[32]{},pc=0; };
struct PS2Runtime {
    using Function=void(*)(uint8_t*,R5900Context*,PS2Runtime*);
    std::map<uint32_t,Function> functions;
    std::vector<uint32_t> registrations;
    Function lookupFunction(uint32_t pc) { return functions[pc]; }
    void registerFunction(uint32_t pc,Function f) { functions[pc]=f;registrations.push_back(pc); }
};
constexpr uint32_t PS2_RAM_SIZE=32u*1024u*1024u;
#define GPR_U32(ctx,n) ((ctx)->r[n])
#include "../../recomp/overrides/reo_audio.h"
unsigned frameCalls=0,streamCalls=0;
void originalFrame(uint8_t*,R5900Context*,PS2Runtime*) { ++frameCalls; }
void sub_00133490_0x133490(uint8_t*,R5900Context*,PS2Runtime*) { ++streamCalls; }
#else
#include "../../runtime/audio/host_bridge.h"
#endif

unsigned checks=0;
float bridgeApiRoundtrip();
void check(bool ok,const char* message) { ++checks;if(!ok) throw std::runtime_error(message); }
bool equal(float a,float b) { return std::abs(a-b)<.00001f; }
int main() {
    try {
        using namespace reo::audio;
        publish(defaults);
        for(const char* text:{"", "100,100,100,100", "100,100,100,100,100,1", "100,100,100,100,101",
                             "100,100,100,100,-1", "100, 20,30,40,50", "100,20,30,40,50x",
                             "4294967296,20,30,40,50", "+1,20,30,40,50"}) {
            check(!applyEnvironmentLevels(text),"Malformed environment accepted");
            check(current.load()==pack(defaults),"Malformed environment partially published");
        }
        check(!applyEnvironmentLevels(nullptr),"Missing environment accepted");
        check(applyEnvironmentLevels("80,10,20,30,40"),"Valid environment rejected");
        check(equal(reoAudioMasterGain(),.8f),"Master environment gain");
        char name[80];std::snprintf(name,sizeof(name),"Local\\REO-audio-bridge-test-%lu",GetCurrentProcessId());
        HANDLE mapping=CreateFileMappingA(INVALID_HANDLE_VALUE,nullptr,PAGE_READWRITE,0,32,name);
        check(mapping!=nullptr,"Create owned test mapping");
        auto* words=static_cast<uint32_t*>(MapViewOfFile(mapping,FILE_MAP_ALL_ACCESS,0,0,32));
        check(words!=nullptr,"Map owned test mapping");
        std::memset(words,0,32);
        _putenv_s("REO_AUDIO_MAP",name);
        _putenv_s("REO_AUDIO_LEVELS","70,11,22,33,44");
        initialize();check(equal(reoAudioMasterGain(),.7f),"Initialize environment before IPC");
        auto update=[&](const std::array<uint32_t,8>& snapshot) {
            __atomic_store_n(words+2,1u,__ATOMIC_RELEASE);
            for(unsigned i=0;i<8;++i) if(i!=2) __atomic_store_n(words+i,snapshot[i],__ATOMIC_RELAXED);
            __atomic_store_n(words+2,snapshot[2],__ATOMIC_RELEASE);
        };
        const std::array<uint32_t,8> good{magic,version,2,40,10,20,30,60};
        update(good);reoAudioPoll();
        for(unsigned bus=0;bus<Count;++bus) check(equal(gain(bus),float(good[3+bus])/100),"IPC category gain");
        const auto accepted=current.load();
        for(unsigned invalid=0;invalid<4;++invalid) {
            auto bad=good;
            if(invalid==0)bad[0]^=1;
            if(invalid==1)++bad[1];
            if(invalid==2)bad[2]=3;
            if(invalid==3)bad[6]=101;
            update(bad);reoAudioPoll();check(current.load()==accepted,"Invalid or pending IPC changed levels");
        }
        update(good);reoAudioPoll();
        routeStream(0x1234,Music);check(equal(reoAudioStreamGain(0x1234),.1f),"Routed stream gain");
        check(equal(reoAudioStreamGain(0x9876),1.f),"Unknown stream follows master only");
        reoAudioResetStreams();check(equal(reoAudioStreamGain(0x1234),1.f),"Reset stream handle route");
#if defined(REO_GAME_FILE1)
        check(equal(bridgeApiRoundtrip(),2.f),"File1 all five external SDK audio symbols link and run");
        check(equal(reoAudioBankGain(0,0,0),.6f),"File1 UI bank classification");
        check(equal(reoAudioBankGain(4,0,0),.3f),"File1 voice bank classification");
        check(equal(reoAudioBankGain(1,0,0),.2f),"File1 SFX bank classification");
        PS2Runtime runtime;runtime.functions[0x19f6c0]=::originalFrame;
        reo::audio::install(runtime);
        check(runtime.registrations==std::vector<uint32_t>({0x19f6c0,0x133490}),"File1 exact hook registrations");
        std::vector<uint8_t> ram(PS2_RAM_SIZE);R5900Context ctx;
        ctx.pc=0x19f6c0;runtime.functions.at(ctx.pc)(ram.data(),&ctx,&runtime);
        check(frameCalls==1,"File1 forwards original frame once");
        uint32_t rna=0x2000,handle=0x3000;
        std::memcpy(ram.data()+0x100c,&rna,4);std::memcpy(ram.data()+rna+0x20,&handle,4);
        ctx.pc=0x133490;ctx.r[4]=0x1000;ctx.r[5]=1;ctx.r[6]=7;
        runtime.functions.at(ctx.pc)(ram.data(),&ctx,&runtime);
        check(streamCalls==1,"File1 forwards original stream once");
        check(equal(reoAudioStreamGain(handle),.3f),"File1 actual ADXT/RNA routing");
        ctx.pc=0;ctx.r[5]=0;reo::audio::startStream(ram.data(),&ctx,&runtime);
        check(streamCalls==2&&equal(reoAudioStreamGain(handle),.3f),"File1 PC guard and continuation");
#else
        check(equal(bridgeApiRoundtrip(),2.4f),"File2 all five external SDK audio symbols link and run");
        for(unsigned port=0;port<16;++port)
            check(equal(reoAudioBankGain(port,6,startVoiceBank),1.f),"File2 imported File1 bank categories");
        // No guest runtime object or function registration is needed by this build.
#endif
        update({magic,version,4,0,100,100,100,100});reoAudioPoll();
        check(reoAudioMasterGain()==0,"Live master mute");
        update({magic,version,6,100,100,100,100,100});reoAudioPoll();
        check(reoAudioMasterGain()==1,"Live master restore");
        UnmapViewOfFile(words);CloseHandle(mapping);
        std::printf("PASS %u host bridge checks\n",checks);return 0;
    } catch(const std::exception& e) { std::fprintf(stderr,"FAIL after %u: %s\n",checks,e.what());return 1; }
}
