// Real retained imported bytes/native workers; declared runtime/bridge test ports.
#include "ps2_runtime.h"
#include "reo_hw_bridge.h"
#include "recomp/overrides/native_resource_reads/runtime_adapter.h"
#include "game/native/afs_hierarchy/hierarchy.hpp"
#include "game/native/resources_windows/mounted_resources.hpp"
#include "game/native/adxt_instances/instances.hpp"
#include <chrono>
#include <cstring>
#include <fstream>
#include <iostream>
#include <thread>

namespace api=reo_native_resource_reads;
namespace n=reo::native::adxt_instances;
namespace a=reo::native::afs_hierarchy;
namespace m=reo::native::resources::win32;
namespace p=reo::native::adxt_phased_player;
void require(bool ok,const char* why){if(!ok)throw std::runtime_error(why);}
std::string hex(const auto& bytes){constexpr char d[]="0123456789abcdef";std::string s;for(auto b:bytes){s+=d[b>>4];s+=d[b&15];}return s;}
void seed(PS2Runtime& runtime,const char* path){
    std::ifstream input(path,std::ios::binary);require(bool(input),"identity fixture open");
    for(unsigned i=0;i<3;++i){std::array<std::uint32_t,2> range{};input.read(reinterpret_cast<char*>(range.data()),sizeof(range));
        require(bool(input) && range[0]<PS2_RAM_SIZE && range[1]<=PS2_RAM_SIZE-range[0],"identity fixture range");
        input.read(reinterpret_cast<char*>(runtime.memory().getRDRAM()+range[0]),range[1]);require(bool(input),"identity fixture bytes");}
}
struct Case {
    std::string name,root,root_hash;std::uint64_t root_bytes{},offset{};std::uint32_t depth{},logical{},channels{},frequency{},total{};
    std::array<std::uint32_t,a::maximum_depth> path{};n::Key key;
    std::uint64_t source_bytes{};p::Snapshot ended;bool done{};
};
int main(int argc,char**argv)try{
    require(argc==5 || argc==6,"data/identity/plan/report and optional attenuation table arguments required");
    _putenv_s("REO_NATIVE_RESOURCE_READS","1");_putenv_s("REO_GAME_PAK","1");_putenv_s("REO_CD_ASYNC","0");
    _putenv_s("REO_CRI_SERVER_SLOW_MS","0");_wputenv_s(L"REO_ASSET_OVERLAY",L"");
    api::SharedMount retained;
    {
        PS2Runtime runtime;ReoHwBridge bridge;seed(runtime,argv[2]);
        api::configure("SLUS-20765",runtime.memory().getRDRAM(),PS2_RAM_SIZE,runtime,std::filesystem::path(argv[1]));
        retained=api::retain_mount_before_run(runtime,runtime.memory().getRDRAM(),PS2_RAM_SIZE);
        require(bool(retained) && runtime.registrations==1 && runtime.setup_leases==0,"same configured mount handoff");
        runtime.requestStop();require(runtime.joinWorkers(),"resource worker fence");
        require(!api::retain_mount_before_run(runtime,runtime.memory().getRDRAM(),PS2_RAM_SIZE),"late mount handoff refused");
    } // Actual native reader/mount remain; the declared test runtime/RAM are gone.
    require(retained->identity().import_version==1 && retained->routes().size()==85 && !retained->identity().overlay_plan_sha256,"retained actual import profile");
    const auto route_hash=hex(retained->identity().route_sha256),manifest_hash=hex(retained->identity().manifest_sha256);
    std::shared_ptr<const reo::native::adxt_attenuation::Table> attenuation;
    if(argc==6){std::array<std::uint32_t,reo::native::adxt_attenuation::table_words> words{};std::ifstream input(argv[5],std::ios::binary);
        input.read(reinterpret_cast<char*>(words.data()),sizeof(words));require(bool(input) && input.peek()==std::char_traits<char>::eof(),"exact owned attenuation table");
        attenuation=reo::native::adxt_attenuation::Table::from_words(words).table;require(bool(attenuation),"owned attenuation table admission");}
    const bool attenuation_profile=bool(attenuation);
    std::array<Case,2> cases;std::ifstream plan(argv[3]);require(bool(plan),"case plan open");
    n::Instances players(n::control::Config{{2},{}});auto render=players.submix();require(players.start_output()==n::Status::completed,"native private output start");
    for(unsigned index=0;index<cases.size();++index){auto& c=cases[index];
        plan>>c.name>>c.root>>c.root_hash>>c.root_bytes>>c.offset>>c.depth;
        require(bool(plan) && c.depth && c.depth<=c.path.size(),"bounded planned path");
        for(unsigned j=0;j<c.depth;++j)plan>>c.path[j];plan>>c.logical>>c.channels>>c.frequency>>c.total;
        require(bool(plan) && c.channels==index+1,"distinct mono/stereo plans");
        const auto root=retained->find_file(c.root);require(root && !root->overlay && root->bytes==c.root_bytes,"actual root identity/length");
        bool matched=false;for(const auto& entry:retained->identity().sources)
            if(entry.kind==m::MountSourceKind::imported && entry.key==c.root && hex(entry.file.sha256)==c.root_hash)matched=true;
        require(matched,"actual root matches owned inventory");
        a::Resolved resolved;
        {a::Tree tree(root->view);resolved=tree.resolve(std::span(c.path).first(c.depth));}
        require(resolved.status==a::Status::completed && resolved.logical_bytes==c.logical && resolved.hops[c.depth-1].root_byte_offset==c.offset,"native hierarchy agrees with independent inventory");
        c.source_bytes=resolved.view->size();
        auto made=players.create({c.channels,{index,index,index,index},attenuation});require(made.status==n::Status::completed,"native instance create");c.key=made.key;
        if(attenuation_profile)require(players.attenuation(c.key,index?0xffffff38u:0xffffff9cu)==n::Status::completed,"original-unit volume latch");
        n::Source source;source.input=std::move(resolved.view);source.player.decoder.channels=c.channels;source.player.decoder.source_config.byte_length=static_cast<std::int32_t>(c.source_bytes);
        require(players.start(c.key,std::move(source))==n::Status::completed,"retained source start");
    }
    std::string excess;require(!(plan>>excess) && plan.eof(),"exact two-source plan");
    retained.reset();attenuation.reset(); // Instances/views own required table/files.
    const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(90);
    std::array<float,1024> samples{};unsigned finished{};
    while(finished<cases.size()){
        require(std::chrono::steady_clock::now()<deadline,"bounded actual worker completion");
        const auto work=players.service(0);require(work==n::Status::completed || work==n::Status::pending,"native service");bool ready=true;
        for(auto& c:cases){if(c.done)continue;const auto observed=players.inspect(c.key);require(observed.source && observed.status==n::Status::completed && !observed.source->fault,"live source state");const auto& s=*observed.source;
            if(s.configured){require(s.decoder.header.base.frequency==c.frequency && s.decoder.header.base.total_samples==c.total,"actual native header");
                if(s.playback.phase==reo::native::adxt_playback::Phase::ended){
                    const auto clock=players.estimate(c.key,0);require(clock.status==n::control::Status::completed && clock.value.result.ratio.numerator==c.total && clock.value.result.ratio.denominator==c.frequency,"terminal clock");
                    require(s.first_payload_samples==c.total && s.output.voice.skipped_samples==0,"complete payload and unskipped output");
                    c.ended=s;c.done=true;++finished;const auto stopped=players.stop(c.key);require(stopped==n::Status::completed || stopped==n::Status::pending,"individual source retirement");continue;
                }}
            ready=ready && s.output.voice.playing && s.output.channel[0].samples>=512;
        }
        if(ready && finished<cases.size()){
            samples.fill(0);require(render->render_add(samples.data(),512)==n::control::output::Status::completed,"actual private PCM callback");
        }else std::this_thread::yield();
    }
    while(players.join()==n::Status::pending){require(std::chrono::steady_clock::now()<deadline,"bounded actual source join");std::this_thread::yield();}
    const auto final=players.snapshot();require(final.session.joined && !final.session.records && !final.instances &&
        final.session.output.submix_fenced && !final.session.output.provider_joined && !final.session.output.render_fault && !final.session.output.statistics.underrun_frames,"private sources and output actually fenced");
    std::ofstream report(argv[4]);require(bool(report),"report open");
    report<<"{\"manifest_sha256\":\""<<manifest_hash<<"\",\"route_sha256\":\""<<route_hash<<"\",\"runtime_destroyed_before_source_start\":true,\"mount_released_before_service\":true,\"private_fenced\":true,\"provider_joined\":false,\"attenuation_profile\":"<<(attenuation_profile?"true":"false")<<",\"output_frames\":"<<final.session.output.statistics.output_frames<<",\"underrun_frames\":0,\"members\":[";
    for(unsigned i=0;i<cases.size();++i){const auto& c=cases[i];if(i)report<<',';report<<"{\"member\":\""<<c.name<<"\",\"source_bytes\":"<<c.source_bytes<<",\"samples\":["<<c.ended.first_payload_samples<<','<<(c.channels==2?c.ended.first_payload_samples:0)<<"],\"byte_digest\":["<<c.ended.first_payload_digest[0]<<','<<c.ended.first_payload_digest[1]<<"],\"raw_volume\":"<<c.ended.output.voice.volume<<",\"requested_attenuation\":";
        if(c.ended.attenuation)report<<c.ended.attenuation->requested;else report<<"null";report<<'}';}
    report<<"]}\n";require(bool(report),"complete report write");
    std::cout<<"Two actual imported native sources completed after test runtime, mount and trees retired; no device\n";
    return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
