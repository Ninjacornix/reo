#include "pcm_test_support.h"
namespace {
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
