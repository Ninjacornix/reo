// Offline integration harness: actual owned file bytes, no game/audio device.
#include "game/native/afs_source_range/afs_source_range.hpp"
#include "game/native/adx_window/v2/stream_window.hpp"
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
namespace w=reo::native::adx_window::v2;
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
        unsigned done=0;
        while(plan>>name>>base>>extent>>index>>logical>>channels>>rate>>total>>decode) {
            report<<"{\"member\":\""<<name<<"\",\"decode_requested\":"<<decode;
            try {
                auto& archive=archives[base];
                if(!archive){auto opened=a::Archive::open(file,base,extent);require(opened.status==a::Status::completed,"actual AFS admission failed");archive=std::move(opened.archive);}
                auto member=archive->member(index);require(member.status==a::Status::completed&&member.entry.logical_bytes==logical,"actual member geometry differs");
                report<<",\"source_bytes\":"<<member.view->size();
                if(decode) {
                    auto keys=std::make_shared<reo::native::adx_header::KeyContext>();w::Config config;
                    config.channels=channels;config.source_config.byte_length=static_cast<std::int32_t>(member.view->size());
                    w::StreamWindowOwner owner(config,member.view,reo::native::adxt_refill::make_async_backend(8192),keys);
                    auto request=owner.request();std::array<std::uint64_t,2> samples{},digest{1469598103934665603ull,1469598103934665603ull};
                    std::array<std::uint8_t,16384> bytes{};bool configured=false,finished=false;
                    const auto deadline=std::chrono::steady_clock::now()+std::chrono::minutes(4);
                    auto drain=[&] {
                        while(owner.snapshot().pcm.rings[0].data) {
                            auto lease=owner.borrow_pcm(16384);require(lease.status==w::pcm::Status::completed,"actual PCM read admission failed");
                            for(std::uint32_t ch=0;ch<channels;++ch) {
                                const auto n=lease.lease.grant(ch).bytes;require(n>=0&&n<=16384,"PCM extent outside buffer");
                                require(lease.lease.read_into(ch,std::span(bytes).first(static_cast<std::size_t>(n)))==w::pcm::Status::completed,"PCM read failed");
                                samples[ch]+=static_cast<unsigned>(n)/2;
                                for(int i=0;i<n;++i){digest[ch]^=bytes[static_cast<std::size_t>(i)];digest[ch]*=1099511628211ull;}
                            }
                            require(owner.finish_pcm(lease.lease)==w::Status::completed,"PCM credit return failed");
                        }
                    };
                    while(std::chrono::steady_clock::now()<deadline) {
                        const auto before=owner.snapshot();
                        require(owner.service_source().status==w::source::Status::completed,"actual asynchronous source failed");
                        const auto result=owner.service(request);
                        if(result!=w::Status::completed&&result!=w::Status::inactive&&result!=w::Status::backpressure) {
                            report<<",\"owner_error\":"<<int(result)<<",\"last_error\":"<<int(owner.snapshot().last_error);
                            throw std::runtime_error("actual asset owner refused");
                        }
                        if(!configured&&owner.snapshot().outer.phase==w::OuterPhase::decoding) {
                            require(owner.snapshot().header.base.frequency==rate&&owner.snapshot().header.base.total_samples==total,"actual header differs from pinned metadata");
                            require(owner.configure_ready()==w::Status::completed,"actual ready admission failed");configured=true;
                        }
                        drain();const auto state=owner.snapshot();
                        if(state.outer.phase==w::OuterPhase::ended){finished=true;break;}
                        if(state.outer.decoded_samples==before.outer.decoded_samples&&state.source.in_flight)std::this_thread::sleep_for(std::chrono::milliseconds(1));
                    }
                    require(finished&&configured,"bounded asset decode did not end");
                    for(std::uint32_t ch=0;ch<channels;++ch)require(samples[ch]==total,"published actual sample count differs");
                    require(owner.stop_decode()==w::Status::completed,"asset decoder stop failed");
                    bool joined=false;
                    for(unsigned i=0;i<10000;++i) {
                        const auto result=owner.retire_on_control_thread();
                        if(result==w::Status::completed){joined=owner.snapshot().source.joined;break;}
                        require(result==w::Status::retirement_pending,"asset source retirement failed");std::this_thread::sleep_for(std::chrono::milliseconds(1));
                    }
                    require(joined,"actual provider fence missing");
                    report<<",\"samples\":["<<samples[0]<<','<<samples[1]<<"],\"byte_digest\":["<<digest[0]<<','<<digest[1]<<"],\"joined\":true";
                }
                report<<",\"status\":\"passed\"}\n";
            }catch(const std::exception& error){report<<",\"status\":\"failed\",\"error\":\""<<error.what()<<"\"}\n";report.flush();throw;}
            report.flush();++done;if(done%100==0)std::cout<<done<<" asset references checked\n"<<std::flush;
        }
        require(plan.eof(),"malformed plan");std::cout<<done<<" asset references completed; archives="<<archives.size()<<'\n';
    }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
}
