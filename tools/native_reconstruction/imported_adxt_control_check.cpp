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
        std::string name,root,root_hash;std::uint64_t root_bytes,expected_offset;std::uint32_t depth,logical,channels,rate,total,decode;
        auto slot=std::make_shared<reo::audio_output::CallbackSlot>();
        auto provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
        c::Config session_config;session_config.output.streams=2;c::Session output(session_config,slot,provider);
        require(output.start()==c::Status::completed,"shared model provider start failed");
        unsigned done=0;
        while(plan>>name>>root>>root_hash>>root_bytes>>expected_offset>>depth) {
            require(depth>0 && depth<=a::maximum_depth,"planned path depth exceeds native profile");
            std::array<std::uint32_t,a::maximum_depth> indices{};for(unsigned i=0;i<depth;++i)plan>>indices[i];
            plan>>logical>>channels>>rate>>total>>decode;require(bool(plan),"incomplete planned native member");
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
                    auto keys=std::make_shared<reo::native::adx_header::KeyContext>();p::Config config;
                    config.decoder.channels=channels;config.decoder.source_config.byte_length=static_cast<std::int32_t>(member.view->size());
                    auto opened=output.open(config,member.view,{15,3,11,31});require(opened.status==c::Status::completed,"native control open failed");
                    const auto key=opened.key;
                    bool finished=false;const auto deadline=std::chrono::steady_clock::now()+std::chrono::minutes(4);
                    while(std::chrono::steady_clock::now()<deadline) {
                        const auto before=output.inspect(key).evidence.decoder.outer.decoded_samples;
                        require(output.service(0)==c::Status::completed,"native control service failed");
                        const auto state=output.inspect(key).evidence;const auto result=state.configured && state.playback.phase==reo::native::adxt_playback::Phase::ended?p::Status::ended:state.configured?p::Status::completed:p::Status::waiting_header;
                        require(!state.fault,"actual native player fault");
                        require(result==p::Status::completed || result==p::Status::waiting_header || result==p::Status::ended,"actual player refused profile");
                        if(state.configured)require(state.decoder.header.base.frequency==rate && state.decoder.header.base.total_samples==total,"actual player header differs");
                        if(result==p::Status::ended){finished=true;break;}
                        // A deterministic offline consumer, never a wall-time or
                        // performance test. Render only with sufficient queued
                        // input; do not manufacture skips from test scheduling.
                        if(state.output.channel[0].samples>=512)provider->step(512);
                        if(result==p::Status::waiting_header ||
                           (state.decoder.outer.decoded_samples==before && state.decoder.source.in_flight && state.output.channel[0].samples<512))
                            std::this_thread::yield();
                    }
                    require(finished,"bounded actual player did not end");const auto ended=output.inspect(key).evidence;
                    const auto position=output.estimate(key,0).value;
                    require(position.status==p::Status::completed && position.result.ratio.numerator==total && position.result.ratio.denominator==rate,"terminal live native raw clock differs");
                    require(ended.first_payload_samples==total,"native player omitted payload samples");
                    require(output.snapshot().output.statistics.underrun_frames==0 && ended.output.voice.skipped_samples==0,"offline schedule starved player output");
                    require(ended.output.channel[0].consumed_bytes/2>=total,"native output did not consume complete payload");
                    bool retired=false;c::Retirement retired_state;
                    for(unsigned i=0;i<10000;++i){retired_state=output.retire(key);const auto result=retired_state.status;
                        if(result==c::Status::completed){retired=true;break;}
                        require(result==c::Status::pending,"actual player retirement failed");std::this_thread::sleep_for(std::chrono::milliseconds(1));}
                    const auto final=retired_state.evidence;require(retired && final.decoder.source.joined && final.output_retired && !provider->unloaded,"actual source/model-provider fence missing");
                    report<<",\"samples\":["<<ended.first_payload_samples<<','<<(channels==2?ended.first_payload_samples:0)
                          <<"],\"byte_digest\":["<<ended.first_payload_digest[0]<<','<<ended.first_payload_digest[1]
                          <<"],\"copied_samples_including_padding\":"<<ended.copied_samples
                          <<",\"consumed_bytes_including_padding\":"<<ended.output.channel[0].consumed_bytes
                          <<",\"underrun_frames\":"<<output.snapshot().output.statistics.underrun_frames
                          <<",\"skipped_samples\":"<<ended.output.voice.skipped_samples
                          <<",\"joined\":true,\"stream_retired\":true";

                }
                report<<",\"status\":\"passed\"}\n";
            }catch(const std::exception& error){report<<",\"status\":\"failed\",\"error\":\""<<error.what()<<"\"}\n";report.flush();throw;}
            report.flush();++done;if(done%100==0)std::cout<<done<<" imported player asset references checked\n"<<std::flush;
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
        std::cout<<done<<" imported player asset references completed; cached_archives="<<cached_archives<<'\n';
    }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
}
