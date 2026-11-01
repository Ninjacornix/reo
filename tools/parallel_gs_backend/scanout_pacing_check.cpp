// GPU integration: omitting obsolete progressive presentations must preserve
// the pixels produced by every guest drawing command and mode transition.
#include "parallel_backend.h"
#include "gs_registers.hpp"
#include "thread_id.hpp"
#include <array>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <atomic>
// This standalone GPU fixture has no IPU decoder or audio/runtime instance.
namespace ps2_ipu { std::atomic<uint32_t> g_dbgCsc{0}; }
namespace reo_parent_natural {
void setActualFirstEntryEnrollmentRequested(bool enabled) noexcept {
    if(enabled) std::terminate();
}
}
namespace reo_resident_live { uint64_t currentGsEpoch() {return 1;} }
namespace reo_movie_owner {
class Target;
void installActualOwner(const std::shared_ptr<Target>&) {
    throw std::logic_error("Fixture must not open a movie owner");
}
void retireActualOwner(const std::shared_ptr<Target>&) noexcept {std::terminate();}
bool onActualOwnerThread() noexcept {return false;}
}
namespace reo_gpu_movie {
std::shared_ptr<reo_movie_owner::Target> makeMovieOwnerService(
    Vulkan::Device&, ParallelGS::GSInterface&, uint64_t, std::function<void(uint32_t)>) {
    throw std::logic_error("Fixture must not create a movie decoder");
}
}
using namespace gs_backend_bridge;
using namespace reo_parallel_backend;
using namespace ParallelGS;
static unsigned checks = 0;
static void require(bool value, const char* message) {
    ++checks;
    if (!value) throw std::runtime_error(message);
}
static Privileged display() {
    Reg64<SMODE1Bits> clock{};
    clock.desc.LC = SMODE1Bits::LC_ANALOG;
    clock.desc.CMOD = SMODE1Bits::CMOD_NTSC;
    clock.desc.SPML = 4;
    Privileged p{};
    p[0] = 1; p[1] = clock.bits; p[2] = 1;
    p[7] = 8ull << 9;
    p[8] = 636ull | (50ull << 12) | (4ull << 23) | (2559ull << 32) | (447ull << 44);
    p[15] = 0x551B4000; p[16] = 0x7F00;
    return p;
}
static void setup(Backend& b) {
    const std::pair<uint8_t,uint64_t> state[] = {
        {0x1a,1},{0x4c,8ull<<16},{0x4d,8ull<<16},
        {0x4e,224ull|(1ull<<32)},{0x4f,224ull|(1ull<<32)},
        {0x40,(511ull<<16)|(447ull<<48)},{0x41,(511ull<<16)|(447ull<<48)},
        {0x47,0x30000},{0x48,0x30000},{0x18,0},{0x19,0},{0x46,1}};
    for (auto [address,value]:state) b.directRegister(address,value);
}
static void draw(Backend& b, unsigned frame) {
    // Use both raw GIF packets and direct writes. Neither may be discarded
    // with a presentation marker; each changes the final triangle colour.
    const std::array<std::pair<uint8_t,uint64_t>,5> commands{{
        {0,3},{1,(0xff000000ull | (frame*0x392713u & 0xffffffu)) | (0x3f800000ull<<32)},
        {5,1ull<<32},{5,(2ull<<32)|(64ull*16)},{5,(3ull<<32)|((64ull*16)<<16)}}};
    if (frame & 1) {
        std::vector<uint64_t> packet{commands.size() | (1ull<<15) | (1ull<<60),14};
        for (auto [address,value]:commands) {packet.push_back(value);packet.push_back(address);}
        b.rawGif(1,reinterpret_cast<const uint8_t*>(packet.data()),packet.size()*8);
    } else for(auto [address,value]:commands) b.directRegister(address,value);
}
static std::vector<Frame> run(bool paced, bool interlaced) {
    Config config;
    config.validatedDrawing = true; config.forceProgressive = true; config.antiBlur = true;
    config.publishPrivilegedReset = [](const Privileged&) {};
    config.publishStatusAck = [](uint64_t) {};
    config.diagnosticOutputRequested = [](uint64_t tick) {return tick==105;};
    if(const char* cache=std::getenv("REO_PIPELINE_CACHE_FILE")) {
        config.persistentPipelineCache=true;
        config.pipelineCacheFile=cache;
    }
    uint64_t now = 100;
    if (paced) config.currentVsyncTick = [&] {return now;};
    auto backend = makeFactory(config)();
    std::vector<uint8_t> vram(4*1024*1024);
    Init init; init.vram=vram.data(); init.vramSize=vram.size(); init.registers=display();
    std::string error;
    require(backend->init(init,error),error.c_str());
    setup(*backend);
    std::vector<Frame> frames;
    for(unsigned i=0;i<24;++i) {
        if(i==16) {backend->reset();setup(*backend);}
        draw(*backend,i+1);
        Capture capture{display(),100+i};
        capture.registers[15] ^= uint64_t(i&1)<<13;
        // Enter interlaced mode, then return to progressive. The first
        // progressive picture must run, retiring the old field history.
        if(interlaced || (i>=8 && i<12)) capture.registers[2]=3;
        if(i==20) capture.registers[0]=0; // A real blank picture must still be available.
        capture.forceHostReadback = i==6 || i==20;
        now = i==0 ? capture.tick : capture.tick+8;
        frames.push_back(backend->capture(capture));
        if(paced && (i==0 || i==5 || i==6 || i==12 || i==16 || i==20 || interlaced || (i>=8 && i<12)))
            require(frames.back().width!=0,"Required scanout was discarded");
    }
    backend->close();
    return frames;
}
int main() try {
    _putenv_s("REO_GPU_MOVIE","0");
    Util::register_thread_index(4);
    for(bool interlaced:{false,true}) {
        const auto reference=run(false,interlaced), candidate=run(true,interlaced);
        uint64_t digest=14695981039346656037ull;
        for(const auto& frame:reference)
            for(auto value:frame.rgba) {digest^=value;digest*=1099511628211ull;}
        std::cout<<"REFERENCE interlaced="<<interlaced<<" pixels_fnv64="<<digest<<'\n';
        unsigned skipped=0, consecutive=0;
        for(size_t i=0;i<reference.size();++i) {
            const auto& a=reference[i]; const auto& b=candidate[i];
            require(!a.rgba.empty(),"Missing reference GPU pixels");
            if(i==1) require(a.rgba!=reference[0].rgba,"Fixture did not change guest pixels");
            if(!b.width && !b.height) {
                ++skipped; ++consecutive;
                require(!interlaced,"Interlaced field discarded");
                require(consecutive<=2,"Presentation starved");
            } else {
                consecutive=0;
                require(a.width==b.width && a.height==b.height && a.rgba==b.rgba,
                        "Guest draws or field history changed after discarded presentation");
            }
        }
        require(interlaced ? skipped==0 : skipped>=6,"Pacing path was not exercised");
    }
    std::cout<<"PASS "<<checks<<" real GPU scanout pacing checks\n";
    return 0;
} catch(const std::exception& error) {std::cerr<<error.what()<<'\n';return 1;}
