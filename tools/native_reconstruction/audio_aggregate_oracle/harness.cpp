// Complete unchanged PCM and bank implementations, deterministic host only.
#include <algorithm>
#include <array>
#include <bit>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <mutex>
#include <set>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "ps2_host_backend.h"
#include "source/vblank_music_diag.h"
#include "source/Kernel/Syscalls/Helpers/CriAudioDispatch.h"
#include "source/Kernel/Syscalls/Helpers/ReoSoundBanks.cpp"
namespace controlled_clock { inline std::int64_t nanoseconds=0; }
namespace pcm_test_std {
using namespace std;
namespace chrono {
using namespace std::chrono;
struct steady_clock {
    using duration=std::chrono::nanoseconds;
    using rep=duration::rep; using period=duration::period;
    using time_point=std::chrono::time_point<steady_clock>;
    static constexpr bool is_steady=true;
    static time_point now() noexcept { return time_point(duration(controlled_clock::nanoseconds)); }
};
}
}
#define std pcm_test_std
#include "source/Kernel/Syscalls/Helpers/CriAudio.cpp"
#undef std

namespace a=ps2_cri_audio;
namespace s=ps2_reo_sound;
struct Hook { unsigned kind,key,index; std::uint64_t fingerprint; std::uint32_t bits; };
std::vector<Hook> hooks;
float masterGain=1,streamGain=1; unsigned bankMode=0;
float reoAudioMasterGain() { hooks.push_back({0,0,0,0,std::bit_cast<std::uint32_t>(masterGain)}); return masterGain; }
float reoAudioStreamGain(std::uint32_t key) { hooks.push_back({1,key,0,0,std::bit_cast<std::uint32_t>(streamGain)}); return streamGain; }
float reoAudioBankGain(unsigned port,unsigned index,std::uint64_t fingerprint) {
    const float gain=bankMode?float((port+index+unsigned(fingerprint&3))%5)*0.25f:1.0f;
    hooks.push_back({2,port,index,fingerprint,std::bit_cast<std::uint32_t>(gain)}); return gain;
}
void reoAudioPoll() { hooks.push_back({3,0,0,0,0}); }
void reoAudioResetStreams() { hooks.push_back({4,0,0,0,0}); }
void require(bool value,const char* why) { if(!value)throw std::runtime_error(why); }
struct Input {
    std::ifstream f;
    explicit Input(const char* path):f(path,std::ios::binary) { require(bool(f),"input open"); }
    std::uint32_t word() { std::uint8_t b[4]; f.read(reinterpret_cast<char*>(b),4); require(bool(f),"input word");
        return std::uint32_t(b[0])|(std::uint32_t(b[1])<<8)|(std::uint32_t(b[2])<<16)|(std::uint32_t(b[3])<<24); }
    std::vector<std::uint8_t> blob() { auto n=word(); require(n<=65536,"blob bound"); std::vector<std::uint8_t>b(n);
        if(n)f.read(reinterpret_cast<char*>(b.data()),n);require(bool(f),"input blob");return b; }
};
struct Asset { std::vector<std::uint8_t>hd,bd,tq; };
std::set<std::uint32_t> channelKeys,voiceKeys;
template<class T> void numbers(const T& values) { std::cout<<'[';bool comma=false;for(auto v:values){if(comma)std::cout<<',';comma=true;std::cout<<+v;}std::cout<<']'; }
void snapshot() {
    std::cout<<"{\"clock_ns\":"<<controlled_clock::nanoseconds<<",\"channels\":[";
    bool comma=false;
    for(auto key:channelKeys) {
        if(comma)std::cout<<',';comma=true;auto i=a::channels.find(key);
        std::cout<<"{\"key\":"<<key<<",\"visible\":"<<(i!=a::channels.end());
        if(i!=a::channels.end()) { const auto& c=i->second;
            std::cout<<",\"queued_bytes\":"<<c.queued<<",\"consumed_bytes\":"<<c.consumed<<",\"pcm\":";numbers(c.pcm); }
        std::cout<<'}';
    }
    std::cout<<"],\"voices\":[";comma=false;
    for(auto key:voiceKeys) {
        if(comma)std::cout<<',';comma=true;auto i=a::voices.find(key);
        std::cout<<"{\"key\":"<<key<<",\"visible\":"<<(i!=a::voices.end());
        if(i!=a::voices.end()) { const auto& v=i->second;
            std::cout<<",\"left\":"<<v.left<<",\"right\":"<<v.right<<",\"channels\":"<<v.channels<<",\"frequency\":"<<v.frequency
                <<",\"volume\":"<<v.volume<<",\"playing\":"<<v.playing<<",\"draining\":"<<v.draining
                <<",\"phase_bits\":"<<std::bit_cast<std::uint64_t>(v.phase)<<",\"late\":"<<v.lateSamples<<",\"skipped\":"<<v.skippedSamples; }
        std::cout<<'}';
    }
    std::cout<<"],\"output_frames\":"<<a::outputFrames<<",\"signal_frames\":"<<a::signalFrames<<",\"underrun_frames\":"<<a::underrunFrames
        <<",\"external_clock\":"<<a::externalClock<<",\"last_tick_ns\":"<<a::lastTick.time_since_epoch().count()
        <<",\"bank\":{\"clock\":"<<s::frameClock<<",\"age\":"<<s::requestAge<<",\"muted\":"<<s::muted<<",\"mono\":"<<s::mono
        <<",\"voice_count\":"<<s::voices.size()<<",\"ports\":[";
    for(unsigned p=0;p<14;++p) {
        if(p)std::cout<<',';std::uint32_t count=999;auto state=s::portState(p,count);
        std::cout<<'['<<s::ports[p].loaded<<','<<s::ports[p].volume<<','<<state<<','<<count<<','<<s::ports[p].fingerprint<<']';
    }
    std::cout<<"]}}";
}
int main(int argc,char** argv) try {
    require(argc==2,"input argument");Input in(argv[1]);char magic[8];in.f.read(magic,8);
    require(std::memcmp(magic,"AAGO1\0\0\0",8)==0,"input signature");
    auto count=in.word();require(count<=32,"asset bound");std::vector<Asset>assets;
    for(unsigned i=0;i<count;++i)assets.push_back({in.blob(),in.blob(),in.blob()});
    auto name=in.blob();std::cout<<std::boolalpha<<"{\"name\":\""<<std::string(name.begin(),name.end())<<"\",\"actions\":[";
    auto actions=in.word();require(actions<=128,"action bound");
    for(unsigned at=0;at<actions;++at) {
        if(at)std::cout<<',';hooks.clear();auto kind=in.word(),n=in.word();require(n<=16,"word bound");
        std::vector<std::uint32_t>w(n);for(auto& v:w)v=in.word();auto blob=in.blob();
        bool result=true;std::uint64_t number=0;std::vector<float>out;
        switch(kind) {
        case 0:a::reset();break;
        case 1: { const auto& b=assets.at(w.at(1));result=s::submitBank(w.at(0),b.hd.data(),b.hd.size(),b.bd.data(),b.bd.size(),b.tq.data(),b.tq.size());break; }
        case 2:result=s::submitPacket(nullptr,0,blob.data(),blob.size());break;
        case 3: {auto frames=w.at(0);require(frames<=1200,"render bound");out.resize(frames*2,123.0f);a::render(w.at(1)?nullptr:out.data(),frames);if(w.at(1))out.clear();break;}
        case 4:masterGain=std::bit_cast<float>(w.at(0));streamGain=std::bit_cast<float>(w.at(1));bankMode=w.at(2);break;
        case 5:number=0xABCDEF;result=a::queue(w.at(0),blob.data(),blob.size(),number);channelKeys.insert(w.at(0));break;
        case 6:a::configure(w.at(0),w.at(1),w.at(2),w.at(3),w.at(4),w.at(5),w.at(6)!=0);voiceKeys.insert(w.at(0));if(w.at(1))channelKeys.insert(w.at(1));if(w.at(2))channelKeys.insert(w.at(2));break;
        case 7:a::discard(w.at(0));break;
        case 8:a::drain(w.at(0));break;
        case 9:a::release(w.at(0));break;
        case 10:number=a::consumed(w.at(0));break;
        case 11:number=a::queuedSamples(w.at(0));break;
        case 12:s::reset();break;
        case 13:controlled_clock::nanoseconds=std::bit_cast<std::int64_t>((std::uint64_t(w.at(1))<<32)|w.at(0));break;
        case 14:a::ensureHostOutput();break;
        case 15:a::shutdown();break;
        case 16: {std::uint32_t count=999;auto state=s::portState(w.at(0),count);std::cout<<"{\"query\":["<<state<<','<<count<<','<<s::seState(w.at(0),w.at(1),w.at(2))<<"],";break;}
        default:throw std::runtime_error("unknown action");
        }
        if(kind!=16)std::cout<<'{';std::cout<<"\"kind\":"<<kind<<",\"returned\":"<<result<<",\"number\":"<<number<<",\"pcm_bits\":[";
        for(std::size_t i=0;i<out.size();++i){if(i)std::cout<<',';std::cout<<std::bit_cast<std::uint32_t>(out[i]);}
        std::cout<<"],\"hooks\":[";
        for(std::size_t i=0;i<hooks.size();++i){if(i)std::cout<<',';const auto& h=hooks[i];std::cout<<'['<<h.kind<<','<<h.key<<','<<h.index<<','<<h.fingerprint<<','<<h.bits<<']';}
        std::cout<<"],\"state\":";snapshot();std::cout<<'}';
    }
    std::cout<<"]}\n";char extra;require(!in.f.read(&extra,1),"trailing input");return 0;
} catch(const std::exception& e) { std::cerr<<e.what()<<'\n';return 1; }
