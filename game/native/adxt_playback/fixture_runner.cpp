#include "playback.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace p=reo::native::adxt_playback;
namespace pcm=reo::native::adx_pcm::v2;
struct Output final : p::Output {
    std::uint32_t queued{}; bool playing{},transfer{},seen{},thru{};
    p::Status queued_samples(std::uint32_t& n) noexcept override { n=queued; return p::Status::completed; }
    p::Status free_samples(std::uint32_t& n) noexcept override { n=8192-queued; return p::Status::completed; }
    p::Status play(bool value) noexcept override { playing=value; return p::Status::completed; }
    p::Status stop_transfer() noexcept override { transfer=false; seen=true; return p::Status::completed; }
    p::Status through() noexcept override { thru=true; return p::Status::completed; }
};
int main(int argc,char** argv) {
    if (argc!=2) return 2;
    std::ifstream file(argv[1]); if (!file) return 2;
    std::string name; unsigned phase{},channels{},decoder{},inhibit{},paused{},started{},play{},transfer{},thru{};
    std::uint32_t request{},queued{},occupied{},padding{},base{},tick_base{},tick{},cursor{};
    while (file>>name>>phase>>channels>>request>>queued>>occupied>>decoder>>inhibit>>paused>>started
           >>padding>>base>>tick_base>>tick>>cursor>>play>>transfer>>thru) {
        pcm::Store store({channels,static_cast<std::int32_t>(cursor),static_cast<std::int32_t>(occupied)},{},0xA5);
        p::StorePcm port(store,channels); Output output;
        output.queued=queued;output.playing=bool(play);output.transfer=bool(transfer);output.thru=bool(thru);
        p::State state; state.phase=static_cast<p::Phase>(phase);state.request_samples=static_cast<std::int32_t>(request);
        state.estimate_base=base;state.tick_base=tick_base;state.padding_samples=padding;
        state.inhibit=bool(inhibit);state.paused=bool(paused);state.started=bool(started);
        p::Playback control(state);
        const auto status=control.service({decoder==3,channels,32,tick},port,output);
        const auto& s=control.state();const auto ps=store.snapshot();
        std::cout<<"{\"name\":\""<<name<<"\",\"status\":"<<static_cast<int>(status)
            <<",\"phase\":"<<static_cast<unsigned>(s.phase)<<",\"started\":"<<s.started
            <<",\"base\":"<<s.estimate_base<<",\"tick_base\":"<<s.tick_base
            <<",\"padding\":"<<s.padding_samples<<",\"play\":"<<output.playing
            <<",\"transfer\":"<<output.transfer<<",\"stop_seen\":"<<output.seen<<",\"thru\":"<<output.thru
            <<",\"rings\":[";
        for (unsigned c=0;c<channels;++c) {
            const auto r=ps.rings[c];if(c)std::cout<<',';
            std::cout<<'['<<r.data<<','<<r.free<<','<<r.write<<','<<r.read;
            for (auto total:r.totals)std::cout<<','<<total;
            std::cout<<']';
        }
        std::cout<<"],\"backings\":[";
        for (unsigned c=0;c<channels;++c) {
            std::array<std::uint8_t,pcm::capacity+pcm::extension> bytes{};
            if(store.read_backing(c,bytes)!=pcm::Status::completed)return 3;
            if(c)std::cout<<',';
            std::cout<<'"';
            constexpr char hex[]="0123456789abcdef";
            for (auto b:bytes)std::cout<<hex[b>>4]<<hex[b&15];
            std::cout<<'"';
        }
        std::cout<<"]}\n";
    }
    return file.eof()?0:4;
}
