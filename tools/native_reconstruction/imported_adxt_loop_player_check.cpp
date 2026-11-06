// Offline integration harness: actual owned file bytes, no game/audio device.
#include "game/native/afs_hierarchy/hierarchy.hpp"
#include "game/native/resources_windows/mounted_resources.hpp"
#include "game/native/adxt_control_session/control_session.hpp"
#include "game/native/adxt_player/test_provider.hpp"
#include <array>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <mutex>
#include <stdexcept>
#include <thread>

namespace a=reo::native::afs_hierarchy;
namespace m=reo::native::resources::win32;
namespace p=reo::native::adxt_phased_player;
namespace c=reo::native::adxt_control_session;
namespace o=reo::native::adxt_output_session;
namespace r=reo::native::resources;
void require(bool value,const char* message) {if(!value)throw std::runtime_error(message);}
struct CycleMeter {
    unsigned channels{};std::uint64_t start{},span{},copied{};bool fault{};
    std::array<std::array<std::uint64_t,2>,2> samples{},digest{{{1469598103934665603ull,1469598103934665603ull},{1469598103934665603ull,1469598103934665603ull}}};
    void accept(std::span<const std::byte> left,std::span<const std::byte> right,const p::window::Snapshot& before)noexcept{
        if(left.empty() || left.size()%64 || (channels==2?right.size()!=left.size():!right.empty()) || before.header.loop.enabled!=1 || before.header.loop.positions[0]!=start || before.header.loop.positions[2]-before.header.loop.positions[0]!=span || !span){fault=true;return;}
        const auto count=left.size()/2;std::uint64_t at=copied,remaining=count;
        while(remaining){
            if(at<start){const auto skip=std::min(remaining,start-at);at+=skip;remaining-=skip;continue;}
            if(at>=start+2*span)break;
            const auto cycle=(at-start)/span,n=std::min(remaining,start+(cycle+1)*span-at),offset=at-copied;
            for(unsigned channel=0;channel<channels;++channel){const auto bytes=(channel?right:left).subspan(static_cast<std::size_t>(offset*2),static_cast<std::size_t>(n*2));
                for(const auto byte:bytes){digest[cycle][channel]^=std::to_integer<std::uint8_t>(byte);digest[cycle][channel]*=1099511628211ull;}samples[cycle][channel]+=n;}
            at+=n;remaining-=n;
        }
        copied+=count;
    }
    bool complete()const noexcept{return copied>=start+2*span && !fault;}
};
static CycleMeter* observer{};
// Called only by the derived verification source, after actual output acceptance.
void test_after_accepted_loop_copy(std::span<const std::byte> left,std::span<const std::byte> right,const p::window::Snapshot& before)noexcept{
    if(observer)observer->accept(left,right,before);
}
int main(int argc,char**argv) {
    if(argc!=4)return 2;
    try {
        auto mounted=m::MountedResources::open_file1_windows(std::filesystem::path(argv[1]));
        require(mounted.status==m::MountStatus::ok,"actual verified import mount failed");
        auto mount=std::move(mounted.mount);
        require(mount->identity().import_version==1 && !mount->identity().overlay_plan_sha256 && mount->routes().size()==85,"unexpected imported profile");
        auto hex=[](const auto& bytes){constexpr char d[]="0123456789abcdef";std::string text;for(auto b:bytes){text+=d[b>>4];text+=d[b&15];}return text;};
        std::ifstream plan(argv[2]);std::ofstream report(argv[3]);
        require(bool(plan)&&bool(report),"plan/report open failed");
        std::map<std::string,std::unique_ptr<a::Tree>> trees;
        std::string name,root,root_hash;std::uint64_t root_bytes,expected_offset;std::uint32_t depth,logical,channels,rate,total,decode,start,end;
        auto slot=std::make_shared<reo::audio_output::CallbackSlot>();
        auto provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
        c::Config session_config;session_config.output.streams=2;c::Session output(session_config,slot,provider);
        require(output.start()==c::Status::completed,"shared model provider start failed");
        unsigned done=0;
        while(plan>>name>>root>>root_hash>>root_bytes>>expected_offset>>depth) {
            require(depth>0 && depth<=a::maximum_depth,"planned path depth exceeds native profile");
            std::array<std::uint32_t,a::maximum_depth> indices{};for(unsigned i=0;i<depth;++i)plan>>indices[i];
            plan>>logical>>channels>>rate>>total>>decode>>start>>end;require(bool(plan),"incomplete planned native member");
            report<<"{\"member\":\""<<name<<"\",\"decode_requested\":"<<decode;
            try {
                auto& tree=trees[root];
                if(!tree){auto route=mount->find_file(root);require(bool(route) && !route->overlay && route->bytes==root_bytes,"actual imported root route differs");
                    bool identity=false;for(const auto& source:mount->identity().sources)
                        if(source.kind==m::MountSourceKind::imported && source.key==root && hex(source.file.sha256)==root_hash)identity=true;
                    require(identity,"retained imported root does not match owned inventory");
                    tree=std::make_unique<a::Tree>(route->view);}
                auto member=tree->resolve(std::span(indices).first(depth));
                require(member.status==a::Status::completed && member.logical_bytes==logical && member.hops[depth-1].root_byte_offset==expected_offset,"actual hierarchy/range differs from independent inventory");
                report<<",\"source_bytes\":"<<member.view->size();
                if(decode) {
                    p::Config config;config.decoder.channels=channels;config.decoder.loop_enabled=true;
                    config.decoder.source_config.byte_length=static_cast<std::int32_t>(member.view->size());
                    const auto opened=output.open(config,member.view,{15,3,11,31});require(opened.status==c::Status::completed,"regular loop control open failed");const auto key=opened.key;
                    CycleMeter meter;meter.channels=channels;meter.start=start;meter.span=end-start;observer=&meter;
                    struct Clear{~Clear(){observer=nullptr;}}clear;
                    bool finished=false;const auto deadline=std::chrono::steady_clock::now()+std::chrono::minutes(4);std::int32_t decoded{};
                    while(std::chrono::steady_clock::now()<deadline){
                        const auto result=output.service(0);const auto state=output.inspect(key).evidence;
                        if(result!=c::Status::completed || state.fault){report<<",\"owner_error\":"<<int(state.decoder.last_error)<<",\"source_error\":"<<int(state.decoder.source.last_error)
                            <<",\"decoder_phase\":"<<int(state.decoder.phase)<<",\"pcm_phase\":"<<int(state.decoder.pcm.phase)
                            <<",\"loop_iterations\":"<<state.decoder.loop.iterations<<",\"copied_samples\":"<<state.copied_samples
                            <<",\"engine\":["<<state.decoder.engine.sample_offset<<','<<state.decoder.engine.available_samples<<','<<state.decoder.engine.remaining_samples<<','<<state.decoder.engine.produced_samples<<','<<state.decoder.engine.consumed_bytes<<"]"
                            <<",\"pcm\":["<<state.decoder.pcm.rings[0].read<<','<<state.decoder.pcm.rings[0].write<<','<<state.decoder.pcm.rings[0].data<<','<<state.decoder.pcm.rings[0].free<<','<<state.decoder.pcm.producer[0].offset<<','<<state.decoder.pcm.producer[0].bytes<<"]";throw std::runtime_error("regular loop data plane fault");}
                        require(!meter.fault && state.copied_samples==meter.copied,"copied loop observation differs from actual accepted credit");
                        require(state.decoder.outer.decoded_samples>=decoded,"regular loop cumulative sample count reset");decoded=state.decoder.outer.decoded_samples;
                        if(state.configured)require(state.decoder.header.base.frequency==rate && state.decoder.header.base.total_samples==total,"actual loop header differs");
                        if(meter.complete() && state.decoder.loop.iterations>=2){finished=true;break;}
                        require(state.playback.phase!=reo::native::adxt_playback::Phase::ended || !state.configured,"loop unexpectedly entered ended phase");
                        if(state.output.channel[0].samples>=512)provider->step(512);
                        if(state.decoder.source.in_flight)std::this_thread::yield();
                    }
                    require(finished,"bounded regular loop did not copy two cycles");observer=nullptr;
                    const auto state=output.inspect(key).evidence;require(state.playback.phase==reo::native::adxt_playback::Phase::playing && state.decoder.source.loop.enabled,"regular loop stopped or changed its runtime flag");
                    for(unsigned ch=0;ch<channels;++ch)require(meter.samples[0][ch]==meter.span && meter.samples[1][ch]==meter.span && meter.digest[0][ch]==meter.digest[1][ch],"complete copied loop cycles differ");
                    const auto position=output.estimate(key,0);require(position.status==c::Status::completed && position.value.result.ratio.numerator==state.output.channel[0].consumed_bytes/2 && position.value.result.ratio.denominator==rate && state.clock_observation.offset==0,"regular loop raw clock differs from actual consumed ledger");
                    require(output.snapshot().output.statistics.underrun_frames==0 && !state.output.voice.skipped_samples,"buffered loop model starved");
                    bool retired=false;c::Retirement retirement;
                    for(unsigned i=0;i<10000;++i){retirement=output.retire(key);if(retirement.status==c::Status::completed){retired=true;break;}require(retirement.status==c::Status::pending,"loop source retirement failed");std::this_thread::sleep_for(std::chrono::milliseconds(1));}
                    require(retired && retirement.source_joined && retirement.evidence.output_retired && !provider->unloaded,"regular loop source/output fence missing");
                    report<<",\"loop_span\":"<<meter.span<<",\"loop_iterations\":"<<state.decoder.loop.iterations
                          <<",\"cycle_samples\":[["<<meter.samples[0][0]<<','<<meter.samples[0][1]<<"],["<<meter.samples[1][0]<<','<<meter.samples[1][1]<<"]]"
                          <<",\"cycle_digest\":[["<<meter.digest[0][0]<<','<<meter.digest[0][1]<<"],["<<meter.digest[1][0]<<','<<meter.digest[1][1]<<"]]"
                          <<",\"copied_samples\":"<<meter.copied<<",\"consumed_bytes\":"<<state.output.channel[0].consumed_bytes<<",\"decoded_samples\":"<<state.decoder.outer.decoded_samples
                          <<",\"underrun_frames\":"<<output.snapshot().output.statistics.underrun_frames<<",\"skipped_samples\":"<<state.output.voice.skipped_samples<<",\"joined\":true,\"stream_retired\":true";

                }
                report<<",\"status\":\"passed\"}\n";
            }catch(const std::exception& error){report<<",\"status\":\"failed\",\"error\":\""<<error.what()<<"\"}\n";report.flush();throw;}
            report.flush();++done;if(done%100==0)std::cout<<done<<" imported regular loop references checked\n"<<std::flush;
        }
        require(plan.eof(),"malformed plan");
        require(output.join()==c::Status::completed && output.snapshot().output.provider_joined && output.snapshot().output.occupied==0,"final shared provider join failed");
        require(provider->detaches==1 && provider->stops==1 && provider->unloads==1,"shared provider lifetime was not singular");
        require(!output.snapshot().service_busy && !output.snapshot().guard_fault && output.snapshot().records==0 && output.snapshot().joined,"native group guard/state leak");
        std::ofstream summary(std::filesystem::path(argv[3]).parent_path()/"session.json");
        std::uint64_t metadata_entries=0;unsigned cached_archives=0;
        for(const auto& item:trees){const auto snapshot=item.second->snapshot();metadata_entries+=snapshot.entries;cached_archives+=snapshot.archives;}
        summary<<"{\"import_version\":1,\"routes\":85,\"manifest_sha256\":\""<<hex(mount->identity().manifest_sha256)
               <<"\",\"route_sha256\":\""<<hex(mount->identity().route_sha256)<<"\",\"root_archives\":"<<trees.size()
               <<",\"cached_archives\":"<<cached_archives<<",\"metadata_entries\":"<<metadata_entries<<",\"group_dtx_scans\":"<<output.snapshot().dtx_scans<<",\"group_visits\":"<<output.snapshot().group_visits<<",\"provider_joined\":true,\"occupied\":0,\"detach\":"<<provider->detaches
               <<",\"stop\":"<<provider->stops<<",\"unload\":"<<provider->unloads<<"}\n";
        require(bool(summary),"shared session summary write failed");
        std::cout<<done<<" imported regular loop references completed; cached_archives="<<cached_archives<<'\n';
    }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
}
