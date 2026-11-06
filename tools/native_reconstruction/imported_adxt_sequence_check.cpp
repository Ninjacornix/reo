// Offline actual import -> prepared immutable sequence -> accepted PCM copies.
#include "game/native/afs_hierarchy/hierarchy.hpp"
#include "game/native/resources_windows/mounted_resources.hpp"
#include "game/native/adxt_control_session/control_session.hpp"
#include "game/native/adxt_player/test_provider.hpp"
#include <algorithm>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <thread>

namespace a=reo::native::afs_hierarchy;
namespace m=reo::native::resources::win32;
namespace p=reo::native::adxt_phased_player;
namespace c=reo::native::adxt_control_session;
namespace q=reo::native::adx_sequence;
namespace r=reo::native::resources;
void require(bool value,const char* message){if(!value)throw std::runtime_error(message);}
std::string hex(const auto& bytes){constexpr char d[]="0123456789abcdef";std::string text;for(auto b:bytes){text+=d[b>>4];text+=d[b&15];}return text;}
struct Member{std::string name;unsigned channels{},rate{},total{};std::shared_ptr<const r::ByteView> view;};
struct Meter{
    std::span<const Member> members;std::uint64_t copied{};bool fault{};
    std::array<std::array<std::uint64_t,2>,16> samples{},digest{};
    explicit Meter(std::span<const Member> entries):members(entries){for(auto& d:digest)d={1469598103934665603ull,1469598103934665603ull};}
    void accept(std::span<const std::byte> left,std::span<const std::byte> right,const p::window::Snapshot& before)noexcept{
        const auto channels=members.front().channels;
        if(left.empty() || left.size()%64 || (channels==2?right.size()!=left.size():!right.empty()) || before.header.active_channels!=static_cast<int>(channels)){fault=true;return;}
        const auto count=left.size()/2;std::uint64_t begin=0;
        for(std::size_t i=0;i<members.size();++i){const auto end=begin+members[i].total,first=std::max(begin,copied),last=std::min(end,copied+count);
            if(first<last)for(unsigned ch=0;ch<channels;++ch){const auto bytes=(ch?right:left).subspan(static_cast<std::size_t>((first-copied)*2),static_cast<std::size_t>((last-first)*2));
                for(const auto byte:bytes){digest[i][ch]^=std::to_integer<std::uint8_t>(byte);digest[i][ch]*=1099511628211ull;}samples[i][ch]+=last-first;}
            begin=end;
        }
        copied+=count;
    }
};
static Meter* observer{};
// Declared/called only by the derived verification source after output copy.
void test_after_accepted_sequence_copy(std::span<const std::byte> left,std::span<const std::byte> right,const p::window::Snapshot& before)noexcept{if(observer)observer->accept(left,right,before);}
int main(int argc,char**argv){if(argc!=4)return 2;try{
    auto mounted=m::MountedResources::open_file1_windows(std::filesystem::path(argv[1]));
    require(mounted.status==m::MountStatus::ok,"actual verified import mount failed");auto mount=std::move(mounted.mount);
    require(mount->identity().import_version==1 && !mount->identity().overlay_plan_sha256 && mount->routes().size()==85,"unexpected imported profile");
    std::ifstream plan(argv[2]);std::ofstream report(argv[3]);require(bool(plan)&&bool(report),"plan/report open failed");
    std::ofstream groups(std::filesystem::path(argv[3]).parent_path()/"groups.jsonl");require(bool(groups),"group report open failed");
    std::map<std::string,std::unique_ptr<a::Tree>> trees;
    auto slot=std::make_shared<reo::audio_output::CallbackSlot>();auto provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
    c::Session output({},slot,provider);require(output.start()==c::Status::completed,"model output start failed");
    std::string id;unsigned count,done=0,references=0;
    while(plan>>id>>count){
        require(count>=2 && count<=q::maximum_segments,"sequence count outside native bound");
        std::vector<Member> members;std::vector<std::shared_ptr<const r::ByteView>> views;members.reserve(count);views.reserve(count);
        for(unsigned i=0;i<count;++i){
            std::string name,root,root_hash;std::uint64_t root_bytes,expected_offset;unsigned depth,logical,channels,rate,total;
            plan>>name>>root>>root_hash>>root_bytes>>expected_offset>>depth;require(bool(plan)&&depth && depth<=a::maximum_depth,"incomplete hierarchy plan");
            std::array<std::uint32_t,a::maximum_depth> indices{};for(unsigned n=0;n<depth;++n)plan>>indices[n];
            plan>>logical>>channels>>rate>>total;require(bool(plan),"incomplete member plan");auto& tree=trees[root];
            if(!tree){auto route=mount->find_file(root);require(bool(route)&&!route->overlay && route->bytes==root_bytes,"actual import route differs");bool identity=false;
                for(const auto& source:mount->identity().sources)if(source.kind==m::MountSourceKind::imported && source.key==root && hex(source.file.sha256)==root_hash)identity=true;
                require(identity,"retained root identity differs from owned inventory");tree=std::make_unique<a::Tree>(route->view);}
            auto member=tree->resolve(std::span(indices).first(depth));require(member.status==a::Status::completed && member.logical_bytes==logical && member.hops[depth-1].root_byte_offset==expected_offset,"actual hierarchy range differs");
            members.push_back({name,channels,rate,total,member.view});views.push_back(member.view);
        }
        groups<<"{\"sequence\":\""<<id<<"\",\"segments\":"<<count;
        try{
            const auto prepared=q::Sequence::prepare(views);
            if(prepared.status!=q::Status::completed){groups<<",\"prepare_status\":"<<int(prepared.status);throw std::runtime_error("actual sequence preparation refused");}
            for(unsigned i=0;i<count;++i)require(prepared.sequence->segments()[i].header.base.total_samples==members[i].total && prepared.sequence->channels()==members[i].channels && prepared.sequence->frequency()==members[i].rate,"prepared native header differs from inventory");
            p::Config config;config.decoder.channels=prepared.sequence->channels();config.decoder.seamless_enabled=true;config.sequence=prepared.sequence;config.decoder.source_config.byte_length=static_cast<std::int32_t>(prepared.sequence->size());
            const auto opened=output.open(config,prepared.sequence,{15,3,11,31});require(opened.status==c::Status::completed,"prepared sequence owner open failed");
            Meter meter(members);observer=&meter;struct Clear{~Clear(){observer=nullptr;}}clear;
            bool ended=false;const auto deadline=std::chrono::steady_clock::now()+std::chrono::minutes(4);
            while(std::chrono::steady_clock::now()<deadline){
                const auto result=output.service(0);const auto state=output.inspect(opened.key).evidence;
                if(result!=c::Status::completed || state.fault){groups<<",\"owner_error\":"<<int(state.decoder.last_error)<<",\"source_error\":"<<int(state.decoder.source.last_error);throw std::runtime_error("actual seamless data plane failed");}
                require(!meter.fault && meter.copied==state.copied_samples,"accepted copy observer/credit differs");
                if(state.configured && state.playback.phase==reo::native::adxt_playback::Phase::ended){ended=true;break;}
                if(state.output.channel[0].samples>=512)provider->step(512);
                if(state.decoder.source.in_flight)std::this_thread::yield();
            }
            require(ended,"bounded sequence did not end");observer=nullptr;const auto state=output.inspect(opened.key).evidence;
            const auto position=output.estimate(opened.key,0);require(position.status==c::Status::completed && position.value.result.ratio.numerator==prepared.sequence->total_samples() && position.value.result.ratio.denominator==prepared.sequence->frequency(),"terminal accumulated clock differs");
            require(state.first_payload_samples==prepared.sequence->total_samples() && state.decoder.loop.seamless_samples==static_cast<std::int32_t>(prepared.sequence->segments().back().sample_offset),"seamless decoded accumulation/prefix differs");
            require(!output.snapshot().output.statistics.underrun_frames && !state.output.voice.skipped_samples,"buffered model starved");
            bool retired=false;for(unsigned i=0;i<10000;++i){auto retirement=output.retire(opened.key);if(retirement.status==c::Status::completed){require(retirement.source_joined && retirement.evidence.output_retired,"source/output fence missing");retired=true;break;}require(retirement.status==c::Status::pending,"source retirement failed");std::this_thread::sleep_for(std::chrono::milliseconds(1));}
            require(retired && !provider->unloaded,"per-sequence retirement/provider lifetime failed");
            for(unsigned i=0;i<count;++i){for(unsigned ch=0;ch<members[i].channels;++ch)require(meter.samples[i][ch]==members[i].total,"complete accepted clip extent differs");
                report<<"{\"sequence\":\""<<id<<"\",\"member\":\""<<members[i].name<<"\",\"source_bytes\":"<<members[i].view->size()<<",\"samples\":["<<meter.samples[i][0]<<','<<meter.samples[i][1]<<"],\"byte_digest\":["<<meter.digest[i][0]<<','<<meter.digest[i][1]<<"],\"source_joined\":true,\"stream_retired\":true,\"status\":\"passed\"}\n";++references;}
            report.flush();groups<<",\"total_samples\":"<<prepared.sequence->total_samples()<<",\"source_bytes\":"<<prepared.sequence->size()<<",\"copied_samples_including_padding\":"<<meter.copied<<",\"consumed_bytes_including_padding\":"<<state.output.channel[0].consumed_bytes<<",\"seamless_samples\":"<<state.decoder.loop.seamless_samples<<",\"underrun_frames\":0,\"skipped_samples\":0,\"source_joined\":true,\"stream_retired\":true,\"status\":\"passed\"}\n";groups.flush();
        }catch(const std::exception& error){groups<<",\"status\":\"failed\",\"error\":\""<<error.what()<<"\"}\n";groups.flush();throw;}
        if(++done%25==0)std::cout<<done<<" actual immutable sequences checked\n"<<std::flush;
    }
    require(plan.eof(),"malformed sequence plan");require(output.join()==c::Status::completed,"shared provider join failed");const auto state=output.snapshot();
    require(state.output.provider_joined && !state.output.occupied && !state.service_busy && !state.guard_fault && !state.records && state.joined && provider->detaches==1 && provider->stops==1 && provider->unloads==1,"shared provider/group final fence failed");
    std::ofstream summary(std::filesystem::path(argv[3]).parent_path()/"session.json");summary<<"{\"import_version\":1,\"routes\":85,\"manifest_sha256\":\""<<hex(mount->identity().manifest_sha256)<<"\",\"groups\":"<<done<<",\"references\":"<<references<<",\"group_dtx_scans\":"<<state.dtx_scans<<",\"group_visits\":"<<state.group_visits<<",\"provider_joined\":true,\"occupied\":0,\"detach\":1,\"stop\":1,\"unload\":1}\n";
    require(bool(summary),"session summary write failed");std::cout<<done<<" actual sequences / "<<references<<" clip copies completed\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
