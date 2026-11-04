#include "pcm_test_support.h"

namespace {
void banks2(const char* imported) {
    using namespace reo::audio;
    std::ifstream file(std::filesystem::path(imported)/"NETBIO00.DAT",std::ios::binary);
    check(bool(file),"Open owned File2 NETBIO00.DAT");auto outer=bytes(file,0,16);
    check(std::memcmp(outer.data(),"AFS\0",4)==0,"Outer AFS signature");const auto rom=word(outer.data()+8);
    auto menu=sound(file,rom,"common.snd"),speech=sound(file,rom,"pl00_voi.snd"),
         selection=sound(file,rom,"start.snd"),npc=sound(file,rom,"pl00_npc.snd"),weapon=sound(file,rom,"weapon01.snd");
    uint64_t fingerprint=14695981039346656037ull;for(auto byte:selection.hd)fingerprint=(fingerprint^byte)*1099511628211ull;
    check(fingerprint==file2StartVoiceBank,"Original File2 selection header matches the production fingerprint");
    struct Case { const Snd* snd;unsigned port,seq,bus; };
    for(auto c:{Case{&menu,0,2,Ui},Case{&speech,4,1,Voice},Case{&speech,7,1,Voice},
        Case{&selection,12,8,Voice},Case{&menu,12,2,Sfx},Case{&npc,13,0,Voice},
        Case{&npc,13,6,Sfx},Case{&weapon,8,0,Sfx},Case{&weapon,11,0,Sfx}}) {
        const auto full=bank(*c.snd,c.port,c.seq,defaults);check(signal(full),"Owned sequence produces PCM");
        auto levels=defaults;levels[c.bus]=50;check(scaled(full,bank(*c.snd,c.port,c.seq,levels),.5f),"Owned bank category halves actual PCM");
        levels[c.bus]=0;check(scaled(full,bank(*c.snd,c.port,c.seq,levels),0),"Owned bank category mutes actual PCM");
        levels[c.bus]=50;levels[Master]=50;check(scaled(full,bank(*c.snd,c.port,c.seq,levels),.25f),"Bank and master gains multiply once");
        levels=defaults;levels[c.bus==Voice?Sfx:Voice]=0;
        check(scaled(full,bank(*c.snd,c.port,c.seq,levels),1),"Muting another category preserves the original bank PCM");
        reset();
        check(ps2_reo_sound::submitBank(c.port,c.snd->hd.data(),c.snd->hd.size(),c.snd->bd.data(),c.snd->bd.size(),c.snd->tq.data(),c.snd->tq.size()),"Live bank submit");
        const uint8_t request[]={0,uint8_t(c.port),uint8_t(c.seq),0,0};
        check(ps2_reo_sound::submitPacket(nullptr,0,request,sizeof(request)),"Live bank request");
        auto first=render(512);levels=defaults;levels[c.bus]=50;publish(levels);auto half=render(512);
        levels[c.bus]=0;publish(levels);auto mute=render(512);levels[c.bus]=100;publish(levels);auto restored=render(512);
        auto part=[&](unsigned n){return std::vector<float>(full.begin()+n*1024,full.begin()+(n+1)*1024);};
        check(scaled(part(0),first,1)&&scaled(part(1),half,.5f)&&scaled(part(2),mute,0)&&scaled(part(3),restored,1),
              "Live bank controls retain the original playback cursor through mute and restore");
    }
}
}
int main(int argc,char** argv) {
    try {
        reo::audio::initialize();
        pcm();
        if(argc>1&&argv[1][0])banks2(argv[1]);
        else std::puts("SKIP owned File2 banks: supply the imported File2 data directory");
        std::printf("PASS %u File2 actual PCM bridge checks\n",checks);return 0;
    } catch(const std::exception& e) { std::fprintf(stderr,"FAIL after %u: %s\n",checks,e.what());return 1; }
}
