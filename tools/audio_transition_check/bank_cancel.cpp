#include "../audio_mixer_check/pcm_test_support.h"

namespace {
Snd repeating(const Snd& source) {
    Snd result = source;
    // Authored TQ: two independent, repeating menu-note sequences.
    result.tq.assign(0x60, 0);
    result.tq[14] = 2;
    result.tq[16] = 0x20;
    result.tq[20] = 0x40;
    for (unsigned at : {0x20u, 0x40u}) {
        const uint8_t commands[] = {0xE0,127,0xE2,0,0xB2,127,8,0,0xE5,8,0,
                                   0xF8,uint8_t(at + 4),0};
        std::copy(std::begin(commands), std::end(commands), result.tq.begin() + at);
    }
    return result;
}
void load(const Snd& source) {
    reset();
    check(ps2_reo_sound::submitBank(2,source.hd.data(),source.hd.size(),
        source.bd.data(),source.bd.size(),source.tq.data(),source.tq.size()),"Load repeating bank");
}
void packet(std::initializer_list<uint8_t> values) {
    const std::vector<uint8_t> data(values);
    check(ps2_reo_sound::submitPacket(nullptr,0,data.data(),data.size()),"Accept bank control packet");
}
bool active(unsigned index,unsigned group) { return ps2_reo_sound::seState(2,index,group)!=0; }
}
int main(int argc,char** argv) try {
    check(argc==2,"Usage: bank_cancel <owned File1 imported data>");
    std::ifstream f(std::filesystem::path(argv[1])/"NETBIO01.DAT",std::ios::binary);
    check(bool(f),"Open owned sound archive");
    auto [base,size]=member(f,0,"adxsnd.afs");
    const auto source=repeating(sound(f,base,"common.snd"));
    load(source);
    packet({0,2,0,3,0});
    check(signal(render(4096)),"Repeating sequence has audible output");
    check(active(0,3),"An in-sequence AllNotesOff must preserve its scheduler");
    packet({8,2,0,3});
    check(!active(0,3),"Cancel retires sequence immediately");
    render(48000); // Allow the accepted envelope release to finish.
    check(!signal(render(48000)),"Cancelled loop cannot schedule more notes");
    packet({8,2,0,3});
    check(!active(0,3)&&!signal(render(1024)),"Repeated cancel is harmless");
    packet({0,2,0,3,0});packet({0,2,1,4,0});render(2048);
    packet({8,2,0,3});
    check(!active(0,3)&&active(1,4),"Targeted cancellation preserves other sequence");
    check(signal(render(48000)),"Other sequence continues playing");
    packet({8,2,128,128});
    check(active(1,4),"High selector bits are masked, not wildcard cancellation");
    packet({8,2,129,132});
    check(!active(1,4),"Masked exact selectors retire their matching sequence");
    render(48000);check(!signal(render(48000)),"Cancelled matching sequence cannot restart");
    load(source);
    packet({0,130,0,3,0});render(2048);
    packet({0,130,1,4,0});
    check(!active(0,3)&&active(1,4),"Replace matching flagged request retires old sequence");
    packet({8,2,1,4});render(48000);
    check(!signal(render(48000)),"Replacement has no orphaned sequence");
    std::printf("PASS %u bank cancellation checks\n",checks);
    return 0;
} catch(const std::exception& e) {
    std::fprintf(stderr,"FAIL after %u checks: %s\n",checks,e.what());return 1;
}
