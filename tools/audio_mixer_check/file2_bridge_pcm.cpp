#include "CriAudio.h"
#include "../../runtime/audio/host_bridge.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <stdexcept>
#include <vector>

unsigned checks=0;
void check(bool ok,const char* message) { ++checks;if(!ok) throw std::runtime_error(message); }
std::vector<float> render(unsigned master) {
    ps2_cri_audio::reset();
    reo::audio::publish({master,0,0,0,0});
    ps2_cri_audio::render(nullptr,0);
    std::vector<int16_t> input(1024,4096);uint64_t end=0;
    check(ps2_cri_audio::queue(0x101,reinterpret_cast<const uint8_t*>(input.data()),2048,end),"Queue native PCM");
    ps2_cri_audio::configure(0x100,0x101,0,1,48000,256,true);
    std::vector<float> output(2048);ps2_cri_audio::render(output.data(),1024);
    check(ps2_cri_audio::consumed(0x101)==2048&&ps2_cri_audio::queuedSamples(0x101)==0,"Master mute preserves native PCM consumption");
    return output;
}
int main() {
    try {
        reo::audio::initialize();
        const auto full=render(100),half=render(50),mute=render(0);
        check(std::any_of(full.begin(),full.end(),[](float value){return value!=0;}),"File2 uncategorized PCM audible despite category zeroes");
        for(size_t i=0;i<full.size();++i) {
            check(std::abs(half[i]-full[i]*.5f)<2e-7f,"File2 master halves actual PCM");
            check(mute[i]==0,"File2 master mutes actual PCM");
        }
        std::printf("PASS %u File2 actual PCM bridge checks\n",checks);return 0;
    } catch(const std::exception& e) { std::fprintf(stderr,"FAIL after %u: %s\n",checks,e.what());return 1; }
}
