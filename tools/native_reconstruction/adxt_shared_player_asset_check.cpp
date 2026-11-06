// Offline integration harness: actual owned file bytes, no game/audio device.
#include "game/native/afs_source_range/afs_source_range.hpp"
#include "game/native/adxt_shared_player/player.hpp"
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

namespace a=reo::native::afs_source_range;
namespace p=reo::native::adxt_shared_player;
namespace o=reo::native::adxt_output_session;
namespace r=reo::native::resources;
class File final:public r::ByteView {
public:
    explicit File(const std::filesystem::path& path):stream_(path,std::ios::binary),size_(std::filesystem::file_size(path)) {
        if(!stream_)throw std::runtime_error("owned file open failed");
    }
    std::uint64_t size()const noexcept override{return size_;}
    r::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override {
        if(at>size_||out.size()>size_-at)return{r::Status::invalid_range,0};
        std::lock_guard lock(mutex_);stream_.clear();stream_.seekg(static_cast<std::streamoff>(at));
        stream_.read(reinterpret_cast<char*>(out.data()),static_cast<std::streamsize>(out.size()));
        return stream_?r::ReadResult{r::Status::ok,out.size()}:r::ReadResult{r::Status::source_failure,0};
    }
private:
    mutable std::ifstream stream_;std::uint64_t size_;mutable std::mutex mutex_;
};
void require(bool value,const char* message) {if(!value)throw std::runtime_error(message);}
int main(int argc,char**argv) {
    if(argc!=4)return 2;
    try {
        auto file=std::make_shared<File>(argv[1]);std::ifstream plan(argv[2]);std::ofstream report(argv[3]);
        require(bool(plan)&&bool(report),"plan/report open failed");
        std::map<std::uint64_t,std::shared_ptr<const a::Archive>> archives;
        std::string name;std::uint64_t base,extent;std::uint32_t index,logical,channels,rate,total,decode;
        auto slot=std::make_shared<reo::audio_output::CallbackSlot>();
        auto provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
        o::Session output({2},slot,provider);
        require(output.start()==o::Status::completed,"shared model provider start failed");
        unsigned done=0;
        while(plan>>name>>base>>extent>>index>>logical>>channels>>rate>>total>>decode) {
            report<<"{\"member\":\""<<name<<"\",\"decode_requested\":"<<decode;
            try {
                auto& archive=archives[base];
                if(!archive){auto opened=a::Archive::open(file,base,extent);require(opened.status==a::Status::completed,"actual AFS admission failed");archive=std::move(opened.archive);}
                auto member=archive->member(index);require(member.status==a::Status::completed&&member.entry.logical_bytes==logical,"actual member geometry differs");
                report<<",\"source_bytes\":"<<member.view->size();
                if(decode) {
                    auto keys=std::make_shared<reo::native::adx_header::KeyContext>();p::Config config;
                    config.decoder.channels=channels;config.decoder.source_config.byte_length=static_cast<std::int32_t>(member.view->size());
                    auto opened=output.open(channels);require(opened.status==o::Status::completed,"shared producer open failed");
                    p::Player player(config,std::move(opened.producer),member.view,reo::native::adxt_refill::make_async_backend(8192),keys);
                    bool finished=false;const auto deadline=std::chrono::steady_clock::now()+std::chrono::minutes(4);
                    while(std::chrono::steady_clock::now()<deadline) {
                        const auto before=player.snapshot().decoder.outer.decoded_samples;
                        const auto result=player.service(0);const auto state=player.snapshot();
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
                    require(finished,"bounded actual player did not end");const auto ended=player.snapshot();
                    require(ended.first_payload_samples==total,"native player omitted payload samples");
                    require(output.snapshot().statistics.underrun_frames==0 && ended.output.voice.skipped_samples==0,"offline schedule starved player output");
                    require(ended.output.channel[0].consumed_bytes/2>=total,"native output did not consume complete payload");
                    player.request_stop();bool retired=false;
                    for(unsigned i=0;i<10000;++i){const auto result=player.retire_on_control_thread();
                        if(result==p::Status::completed){retired=true;break;}
                        require(result==p::Status::pending,"actual player retirement failed");std::this_thread::sleep_for(std::chrono::milliseconds(1));}
                    const auto final=player.snapshot();require(retired && final.decoder.source.joined && final.output_retired && !provider->unloaded,"actual source/model-provider fence missing");
                    report<<",\"samples\":["<<ended.first_payload_samples<<','<<(channels==2?ended.first_payload_samples:0)
                          <<"],\"byte_digest\":["<<ended.first_payload_digest[0]<<','<<ended.first_payload_digest[1]
                          <<"],\"copied_samples_including_padding\":"<<ended.copied_samples
                          <<",\"consumed_bytes_including_padding\":"<<ended.output.channel[0].consumed_bytes
                          <<",\"underrun_frames\":"<<output.snapshot().statistics.underrun_frames
                          <<",\"skipped_samples\":"<<ended.output.voice.skipped_samples
                          <<",\"joined\":true,\"stream_retired\":true";

                }
                report<<",\"status\":\"passed\"}\n";
            }catch(const std::exception& error){report<<",\"status\":\"failed\",\"error\":\""<<error.what()<<"\"}\n";report.flush();throw;}
            report.flush();++done;if(done%100==0)std::cout<<done<<" shared player asset references checked\n"<<std::flush;
        }
        require(plan.eof(),"malformed plan");
        require(output.join()==o::Status::completed && output.snapshot().provider_joined && output.snapshot().occupied==0,"final shared provider join failed");
        require(provider->detaches==1 && provider->stops==1 && provider->unloads==1,"shared provider lifetime was not singular");
        std::ofstream summary(std::filesystem::path(argv[3]).parent_path()/"session.json");
        summary<<"{\"provider_joined\":true,\"occupied\":0,\"detach\":"<<provider->detaches
               <<",\"stop\":"<<provider->stops<<",\"unload\":"<<provider->unloads<<"}\n";
        require(bool(summary),"shared session summary write failed");
        std::cout<<done<<" shared player asset references completed; archives="<<archives.size()<<'\n';
    }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
}
