#include "CriAudio.h"
#include "ReoSoundBanks.h"
#include "../../runtime/audio/mixer.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

float reoAudioMasterGain() { return reo::audio::gain(reo::audio::Master); }
void reoAudioPoll() {} // Fixture publishes validated controls directly; no launcher MMF.
float reoAudioStreamGain(uint32_t h) { return reo::audio::streamGain(h); }
float reoAudioBankGain(unsigned p,unsigned s,uint64_t f) {
    return reo::audio::gain(reo::audio::bankBus(p,s,f));
}
void reoAudioResetStreams() { for(auto& entry:reo::audio::streamRoutes) entry.store(0); }

namespace {
unsigned checks=0;
void check(bool ok,const char* message) { ++checks;if(!ok) throw std::runtime_error(message); }
uint32_t word(const uint8_t* p) { uint32_t x;std::memcpy(&x,p,4);return x; }
std::vector<uint8_t> bytes(std::ifstream& f,uint64_t at,size_t n) {
    std::vector<uint8_t> result(n);f.seekg(at);f.read(reinterpret_cast<char*>(result.data()),n);
    if(!f) throw std::runtime_error("Owned archive read failed");return result;
}
std::pair<uint64_t,uint32_t> member(std::ifstream& f,uint64_t base,const char* wanted) {
    auto head=bytes(f,base,8);check(std::memcmp(head.data(),"AFS\0",4)==0,"AFS signature");
    auto n=word(head.data()+4);check(n<10000,"AFS member count");
    auto table=bytes(f,base+8,n*8+8);auto names=word(table.data()+n*8);
    auto list=bytes(f,base+names,n*48);
    for(unsigned i=0;i<n;++i) if(std::string(reinterpret_cast<char*>(list.data()+i*48),
        strnlen(reinterpret_cast<char*>(list.data()+i*48),32))==wanted)
        return {base+word(table.data()+i*8),word(table.data()+i*8+4)};
    throw std::runtime_error(std::string("Missing owned archive member ")+wanted);
}
struct Snd { std::vector<uint8_t> hd,bd,tq; };
Snd sound(std::ifstream& f,uint64_t base,const char* name) {
    auto [offset,size]=member(f,base,name);auto data=bytes(f,offset,size);
    check(data.size()>=40 && std::memcmp(data.data(),"MOMO",4)==0,"MOMO source header");
    auto chunk=[&](unsigned at) { auto off=word(data.data()+at),len=word(data.data()+at+4);
        check(off<=size && len<=size-off,"MOMO source chunk range");
        return std::vector<uint8_t>(data.begin()+off,data.begin()+off+len); };
    return {chunk(8),chunk(16),chunk(24)};
}
void reset(const reo::audio::Levels& levels=reo::audio::defaults) {
    ps2_cri_audio::reset();ps2_reo_sound::reset();reo::audio::publish(levels);
    ps2_cri_audio::render(nullptr,0); // Select exact callback clock before queueing.
}
void queue(unsigned handle,unsigned bus,int16_t value=4096,unsigned n=1024) {
    std::vector<int16_t> data(n,value);uint64_t end=0;
    check(ps2_cri_audio::queue(handle+1,reinterpret_cast<const uint8_t*>(data.data()),n*2,end),"Queue PCM");
    ps2_cri_audio::configure(handle,handle+1,0,1,48000,256,true);
    reo::audio::routeStream(handle,bus);
}
std::vector<float> render(unsigned n=1024) {
    std::vector<float> result(n*2);ps2_cri_audio::render(result.data(),n);return result;
}
bool scaled(const std::vector<float>& a,const std::vector<float>& b,float factor) {
    if(a.size()!=b.size())return false;
    for(size_t i=0;i<a.size();++i)if(!std::isfinite(b[i])||std::abs(b[i]-a[i]*factor)>2e-7f)return false;
    return true;
}
bool signal(const std::vector<float>& pcm) { return std::any_of(pcm.begin(),pcm.end(),[](float v){return v!=0;}); }
std::vector<float> stream(unsigned bus,const reo::audio::Levels& levels) {
    reset(levels);queue(0x100,bus);auto out=render();
    check(ps2_cri_audio::consumed(0x101)==2048 && ps2_cri_audio::queuedSamples(0x101)==0,"PCM duration/consumption unchanged");
    return out;
}
std::vector<float> bank(const Snd& snd,unsigned port,unsigned seq,const reo::audio::Levels& levels) {
    reset(levels);
    check(ps2_reo_sound::submitBank(port,snd.hd.data(),snd.hd.size(),snd.bd.data(),snd.bd.size(),snd.tq.data(),snd.tq.size()),"Submit owned bank");
    const uint8_t request[]={0,uint8_t(port),uint8_t(seq),0,0};
    check(ps2_reo_sound::submitPacket(nullptr,0,request,sizeof(request)),"Original SE request");
    auto result=render(48000*3);
    check(ps2_reo_sound::seState(port,seq,0)==0,"Bank duration ends even when muted");
    return result;
}
void controls() {
    using namespace reo::audio;
    reset();for(unsigned b=0;b<Count;++b)check(gain(b)==1,"Default gain100");
    for(unsigned b=0;b<Count;++b)for(unsigned value:{0u,1u,50u,99u,100u}){
        auto levels=defaults;levels[b]=value;publish(levels);
        for(unsigned c=0;c<Count;++c)check(std::abs(gain(c)-(c==b?value/100.f:1.f))<1e-7f,"Packed fields independent");
    }
    std::array<uint32_t,8> words{magic,version,2,50,25,75,0,100};
    check(accept(words,2) && gain(Master)==.5f && gain(Voice)==0,"Valid completed IPC frame");
    auto unchanged=current.load();
    for(unsigned field=0;field<8;++field){auto bad=words;bad[field]=field<3?words[field]+1:101;
        check(!accept(bad,2) && current.load()==unchanged,"Malformed IPC cannot partially publish");}
    check(!accept(words,4) && current.load()==unchanged,"Changed seqlock rejected");
    for(unsigned afs=0;afs<12;++afs){unsigned expected=afs==0?Music:afs==1||(afs>=5&&afs<=8)?Voice:afs==4?Sfx:Count;
        check(streamBus(afs)==expected,"AFS source classification");}
    for(unsigned p=4;p<=7;++p)check(bankBus(p,0,0)==Voice,"Player voice bank routing");
    for(unsigned p=8;p<=11;++p)check(bankBus(p,0,0)==Sfx,"Weapon bank routing");
    check(bankBus(0,2,0)==Ui && bankBus(12,8,startVoiceBank)==Voice && bankBus(12,8,0)==Sfx,"Shared port12 bank identity");
    for(unsigned s:{6u,8u,9u})check(bankBus(13,s,0)==Sfx,"NPC weapon exceptions");
    check(bankBus(13,2,0)==Voice,"NPC vocal sequence");
    reset();routeStream(123,Music);auto levels=defaults;levels[Music]=0;publish(levels);
    check(streamGain(123)==0,"Route applied");ps2_cri_audio::reset();
    check(streamGain(123)==1,"IOP audio reset clears stale handle routing");
    routeStream(123,Music);routeStream(123,Voice);levels[Voice]=50;publish(levels);
    check(streamGain(123)==.5f,"Reused handle retagged");
    for(unsigned h=1;h<=100;++h)routeStream(h,Music);
    check(streamGain(100)==0,"Bounded route overflow retains latest handle");
}
void pcm() {
    using namespace reo::audio;
    for(unsigned bus:{Music,Sfx,Voice,Ui}) {
        auto baseline=stream(bus,defaults);check(signal(baseline),"Stream baseline audible");
        for(unsigned value:{0u,50u,100u}){auto l=defaults;l[bus]=value;
            check(scaled(baseline,stream(bus,l),value/100.f),"Actual CRI category PCM ratio");}
        auto l=defaults;l[Master]=50;l[bus]=50;
        check(scaled(baseline,stream(bus,l),.25f),"Actual CRI master/category multiply");
        l=defaults;l[(bus==Music)?Voice:Music]=0;
        check(scaled(baseline,stream(bus,l),1),"Other category isolated");
    }
    auto mixed=stream(Count,defaults);auto l=Levels{100,0,0,0,0};
    check(scaled(mixed,stream(Count,l),1),"Premixed movie unaffected by category sliders");
    l[Master]=0;check(scaled(mixed,stream(Count,l),0),"Master mutes premixed movie");
    reset();queue(0x100,Music);queue(0x200,Voice,2048);l=defaults;l[Music]=0;publish(l);
    auto out=render();check(std::all_of(out.begin(),out.end(),[](float v){return v==.0625f;}),"Concurrent voices remain independently controlled");
    reset();queue(0x100,Music);auto first=render(256);l=defaults;l[Music]=50;publish(l);auto half=render(256);
    l[Music]=0;publish(l);auto silent=render(256);l[Music]=100;publish(l);auto restored=render(256);
    check(scaled(first,half,.5f)&&scaled(first,silent,0)&&scaled(first,restored,1),"Live slider changes take effect next render block");
    check(ps2_cri_audio::consumed(0x101)==2048 && ps2_cri_audio::queuedSamples(0x101)==0,"Live mute preserves stream timeline");
    reset();queue(0x100,Music,4096);queue(0x200,Voice,2048);
    ps2_cri_audio::configure(0x200,0,0,0,48000,256,false);
    ps2_cri_audio::configure(0x100,0x101,0x201,2,48000,256,true);
    l=defaults;l[Music]=50;publish(l);out=render();
    bool stereo=true;for(unsigned i=0;i<1024;++i)stereo&=out[i*2]==.0625f&&out[i*2+1]==.03125f;
    check(stereo,"Planar stereo channels receive identical category gain without collapse");
    check(ps2_cri_audio::consumed(0x101)==2048&&ps2_cri_audio::consumed(0x201)==2048,"Stereo consumption remains paired");
}
void banks(const Snd& menu,const Snd& speech) {
    using namespace reo::audio;
    uint64_t fingerprint=14695981039346656037ull;for(auto v:speech.hd)fingerprint=(fingerprint^v)*1099511628211ull;
    check(fingerprint==startVoiceBank,"Owned start.snd fingerprint matches production route");
    struct Case { const Snd* snd;unsigned port,seq,bus; };
    for(auto c:{Case{&menu,0,2,Ui},Case{&speech,4,8,Voice},Case{&speech,7,8,Voice},
        Case{&speech,12,8,Voice},Case{&menu,12,2,Sfx},Case{&speech,13,8,Sfx},Case{&menu,13,2,Voice}}) {
        auto base=bank(*c.snd,c.port,c.seq,defaults);check(signal(base),"Owned bank baseline has signal");
        for(unsigned value:{0u,50u,100u}){auto l=defaults;l[c.bus]=value;
            check(scaled(base,bank(*c.snd,c.port,c.seq,l),value/100.f),"Actual bank category PCM ratio");}
        auto l=defaults;l[Master]=50;l[c.bus]=50;
        check(scaled(base,bank(*c.snd,c.port,c.seq,l),.25f),"Actual bank master/category multiply");
        l=defaults;l[c.bus==Voice?Sfx:Voice]=0;
        check(scaled(base,bank(*c.snd,c.port,c.seq,l),1),"Other bank category isolated");
        reset();
        check(ps2_reo_sound::submitBank(c.port,c.snd->hd.data(),c.snd->hd.size(),c.snd->bd.data(),c.snd->bd.size(),c.snd->tq.data(),c.snd->tq.size()),"Live bank submit");
        const uint8_t request[]={0,uint8_t(c.port),uint8_t(c.seq),0,0};
        check(ps2_reo_sound::submitPacket(nullptr,0,request,sizeof(request)),"Live bank request");
        auto first=render(512);l=defaults;l[c.bus]=50;publish(l);auto half=render(512);
        l[c.bus]=0;publish(l);auto silent=render(512);l[c.bus]=100;publish(l);auto restored=render(512);
        auto part=[&](unsigned block){return std::vector<float>(base.begin()+block*1024,base.begin()+(block+1)*1024);};
        check(scaled(part(0),first,1)&&scaled(part(1),half,.5f)&&scaled(part(2),silent,0)&&scaled(part(3),restored,1),"Bank live changes preserve sample cursor and next-block gain");
    }
}
}
int main(int argc,char** argv) {
    try {
        check(argc==2,"Usage: audio_mixer_check.exe <owned imported data directory>");
        std::ifstream f(std::filesystem::path(argv[1])/"NETBIO01.DAT",std::ios::binary);
        check(bool(f),"Open owned NETBIO01.DAT");auto [base,size]=member(f,0,"adxsnd.afs");
        auto menu=sound(f,base,"common.snd"),speech=sound(f,base,"start.snd");
        controls();pcm();banks(menu,speech);
        std::printf("PASS %u checks: actual CRI/bank PCM100/50/0, multiplicative master, isolation, live updates, mute timeline, reused/reset handles, source categories and IPC validation.\n",checks);
        return 0;
    }catch(const std::exception& e){std::fprintf(stderr,"FAIL after %u checks: %s\n",checks,e.what());return 1;}
}
