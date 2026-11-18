#include "game/native/host_movie/session.hpp"
#include "recomp/overrides/native_host_movie/render_bridge.h"
#include <chrono>
#include <cstdio>
#include <stdexcept>
#include <thread>

namespace movies=reo::native::host_movie;
namespace assets=reo::native::movie_assets;
namespace {
using Clock=std::chrono::steady_clock;
void check(bool value,const char* why){if(!value)throw std::runtime_error(why);}
template<class F>void until(F&& fn,const char* why){const auto end=Clock::now()+std::chrono::seconds(20);while(!fn()){check(Clock::now()<end,why);std::this_thread::sleep_for(std::chrono::milliseconds(1));}}
void bridge_check(){
    movies::CpuFrame frame;frame.width=32;frame.height=48;frame.pitch=128;frame.bgra.resize(6144);
    for(unsigned y=0;y<48;++y)for(unsigned x=0;x<32;++x){const auto at=y*128+x*4;frame.bgra[at]=87;frame.bgra[at+1]=static_cast<std::uint8_t>(x);frame.bgra[at+2]=static_cast<std::uint8_t>(y*4);}
    std::vector<std::uint8_t> out(4096);reo::native::host_movie_binding::copy_for_legacy_renderer(frame,32,32,out);
    // Independent landmarks exercise channels, resampling and column tile order.
    check(out[0]==1&&out[1]==0&&out[2]==87&&out[3]==128,"Bridge first sample");
    check(out[1024]==97&&out[1025]==0,"Bridge second tile must be below first");
    check(out[2048]==1&&out[2049]==16,"Bridge third tile must start second column");
    check(out[4092]==187&&out[4093]==31&&out[4094]==87&&out[4095]==128,"Bridge last sample");
    const auto before=out;bool rejected=false;try{reo::native::host_movie_binding::copy_for_legacy_renderer(frame,32,31,out);}catch(const std::invalid_argument&){rejected=true;}
    check(rejected&&out==before,"Malformed renderer destination changed output");
}
}
int wmain(int argc,wchar_t** argv)try {
    check(argc==3,"Prepared native cache and invalid-source test cache required");bridge_check();const auto catalogue=assets::Catalogue::open(argv[1]);
    const auto clip=catalogue->find_label("adxsnd.afs/PS2continue.sfd");check(bool(clip),"Owned native movie key");
    movies::Session session;until([&]{const auto s=session.snapshot();check(s.error.empty(),s.error.c_str());return s.device_ready;},"Native owner readiness");
    auto generation=session.start({clip,clip});std::uint64_t last{},seen{},ordinal{};bool paused=false,resumed=false;double drift{};auto start=Clock::now();auto last_frame_time=start;double transition_gap{};
    std::size_t previous_clip{};
    until([&]{
        auto s=session.snapshot();check(s.error.empty(),s.error.c_str());
        if(auto frame=session.frame(generation);frame&&frame->serial!=last){check(frame->generation==generation&&frame->serial>last&&frame->bgra.size()==std::size_t(frame->pitch)*frame->height,"Immutable native frame shape/identity");check(!seen||frame->ordinal>ordinal,"Ordered native sequence frame index");
            const auto now=Clock::now();if(s.clip_index!=previous_clip){transition_gap=std::chrono::duration<double>(now-last_frame_time).count();previous_clip=s.clip_index;}last_frame_time=now;last=frame->serial;ordinal=frame->ordinal;++seen;}
        if(!paused&&s.position_seconds>=0.4){check(session.pause(generation,true),"Pause command admission");paused=true;until([&]{return session.snapshot().paused;},"Pause command application");
            std::this_thread::sleep_for(std::chrono::milliseconds(30));const auto before=session.snapshot();std::this_thread::sleep_for(std::chrono::milliseconds(200));drift=session.snapshot().position_seconds-before.position_seconds;check(drift==0,"Native worker clock changed while paused");check(session.pause(generation,false),"Resume command admission");resumed=true;}
        return s.state==movies::State::ended&&last==s.frames;
    },"Native playlist completion");
    check(paused&&resumed&&seen>=385&&seen<=390,"Expected complete two-clip native playback");
    const auto first_generation=generation;generation=session.start({clip},true);check(!session.pause(first_generation,true)&&!session.frame(first_generation),"Replaced worker generation admitted");
    until([&]{auto s=session.snapshot();check(s.error.empty(),s.error.c_str());return s.frames>3;},"Replacement progress");
    auto held=session.frame(generation);check(bool(held),"Retained immutable frame");const auto first_byte=held->bgra.front();
    check(session.stop(generation),"Source stop admission");check(!session.frame(generation)&&!session.pause(generation,false)&&session.snapshot().state==movies::State::closed,"Stopped source resurrected through late controls");
    check(held->bgra.front()==first_byte,"Borrowed native frame changed after stop");
    const auto bad=assets::Catalogue::open(argv[2],false);generation=session.start({bad->entries().front().asset});
    until([&]{return session.snapshot().state==movies::State::error;},"Source error not reported");check(!session.snapshot().joined,"A bad source terminated the native owner");
    check(session.stop(generation),"Failed source could not stop");generation=session.start({clip});
    until([&]{auto s=session.snapshot();check(s.error.empty(),s.error.c_str());return s.frames>=4;},"Native owner did not recover from source failure");
    std::vector<std::shared_ptr<const movies::CpuFrame>> retained;
    until([&]{auto f=session.frame(generation);if(f&&(retained.empty()||f->serial!=retained.back()->serial))retained.push_back(std::move(f));return retained.size()==3;},"Three independent renderer leases");
    const auto frozen=session.snapshot().frames;until([&]{return session.snapshot().backpressure>0;},"Retained renderer frames did not bound memory");
    check(session.snapshot().frames==frozen,"Worker overwrote a retained renderer frame");retained.clear();
    until([&]{return session.snapshot().frames>frozen;},"Native owner failed to resume after renderer backpressure");
    check(session.stop(generation),"Recovered source stop");
    generation=session.start({clip});check(session.stop(generation),"Stop immediately after start");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));check(!session.frame(generation)&&session.snapshot().state==movies::State::closed,"Pending start resurrected stopped source");
    session.join();check(session.snapshot().joined,"Native worker did not join");
    std::printf("{\"status\":\"native movie worker playlist and lifecycle passed\",\"observed_frames\":%llu,\"last_ordinal\":%llu,\"pause_drift_seconds\":%.9f,\"clip_transition_gap_seconds\":%.6f,\"source_error_recovery\":true,\"bounded_renderer_leases\":true,\"renderer_bridge_landmarks\":true,\"elapsed_seconds\":%.6f,\"game_run\":false}\n",static_cast<unsigned long long>(seen),static_cast<unsigned long long>(ordinal),drift,transition_gap,std::chrono::duration<double>(Clock::now()-start).count());return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}
