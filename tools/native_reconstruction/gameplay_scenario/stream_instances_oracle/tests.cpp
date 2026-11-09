#include "game/native/gameplay_scenario/stream_instances.hpp"
#include "game/native/adxt_shared_player/test_sources.hpp"
#include <algorithm>
#include <atomic>
#include <bit>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <fstream>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
namespace vm=reo::native::gameplay_scenario;
namespace n=reo::native;
using namespace std::chrono_literals;
namespace {
std::size_t checks{};
void check(bool ok,const char* why){++checks;if(!ok)throw std::runtime_error(why);}
struct ArchiveView final:n::resources::ByteView {
    std::vector<std::uint8_t> bytes;mutable std::atomic<unsigned> body_reads{};
    mutable std::mutex mutex;mutable std::condition_variable cv;mutable bool entered{},released{};bool gated{};
    std::thread::id controller=std::this_thread::get_id();mutable std::atomic<bool> body_on_controller{};
    std::uint64_t size()const noexcept override{return bytes.size();}
    n::resources::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override{
        if(at>bytes.size()||out.size()>bytes.size()-at)return{n::resources::Status::invalid_range,0};
        if(at>=2048){++body_reads;if(std::this_thread::get_id()==controller)body_on_controller=true;
            if(gated){std::unique_lock lock(mutex);entered=true;cv.notify_all();cv.wait(lock,[&]{return released;});}}
        std::memcpy(out.data(),bytes.data()+at,out.size());return{n::resources::Status::ok,out.size()};
    }
    bool did_enter(){std::lock_guard lock(mutex);return entered;}
    void release(){std::lock_guard lock(mutex);released=true;cv.notify_all();}
};
void word(std::vector<std::uint8_t>& b,std::size_t at,std::uint32_t v){for(unsigned i=0;i<4;++i)b.at(at+i)=std::uint8_t(v>>(8*i));}
std::shared_ptr<ArchiveView> archive(std::span<const std::uint8_t> asset,unsigned slot,bool gated){
    auto view=std::make_shared<ArchiveView>();view->gated=gated;view->bytes.resize(2048+((asset.size()+2047)/2048)*2048);word(view->bytes,0,0x00534641);word(view->bytes,4,slot+1);
    for(unsigned i=0;i<=slot;++i){word(view->bytes,8+8*i,2048);word(view->bytes,12+8*i,i==slot?std::uint32_t(asset.size()):0);}
    std::copy(asset.begin(),asset.end(),view->bytes.begin()+2048);return view;
}
std::shared_ptr<const n::afs_source_range::Archive> index(std::shared_ptr<ArchiveView> view){const auto opened=n::afs_source_range::Archive::open(view,0,view->size());check(opened.status==n::afs_source_range::Status::completed&&bool(opened.archive),"bounded fixture AFS index");return opened.archive;}
std::vector<std::uint8_t> load(const char* name){std::ifstream file(name,std::ios::binary);check(bool(file),"input exists");file.seekg(0,std::ios::end);const auto size=file.tellg();check(size>0&&size<32*1024*1024,"bounded input");std::vector<std::uint8_t> b(static_cast<std::size_t>(size));file.seekg(0);file.read(reinterpret_cast<char*>(b.data()),std::streamsize(b.size()));check(std::size_t(file.gcount())==b.size(),"input exact read");return b;}
template<class F>void until(F predicate,const char* why){const auto end=std::chrono::steady_clock::now()+10s;while(!predicate()){check(std::chrono::steady_clock::now()<end,why);std::this_thread::yield();}}
template<class F>struct Operation final:n::adxt_control_owner::Operation {F callback;explicit Operation(F f):callback(std::move(f)){}void run(n::adxt_instances::Instances& value)noexcept override{callback(value);}};
}
int main(int argc,char** argv)try{
    check(argc==3,"asset/table arguments");const auto asset=load(argv[1]),table_bytes=load(argv[2]);check(table_bytes.size()==4000,"owned attenuation words");std::array<std::uint32_t,1000> table_words{};std::memcpy(table_words.data(),table_bytes.data(),4000);
    const auto table=n::adxt_attenuation::Table::from_words(table_words);check(table.status==n::adxt_attenuation::Status::completed,"real attenuation table");
    auto view=archive(asset,69,true);const auto mono=n::adxt_shared_player::testing::file(1,48000,48000);auto mono_view=archive(mono->bytes,0,false);
    auto catalog=std::make_shared<vm::StreamAssetCatalog>();check(catalog->add(0,index(view),"owned-file1-bgm69-fixture-f6fc3d25"),"catalog installs indexed asset");check(catalog->add(1,index(mono_view),"synthetic-mono-fixture"),"catalog installs mono fixture");
    check(catalog->resolve({0,69}).status==vm::StreamStatus::unsupported_profile,"unsealed catalog refuses");catalog->seal();check(!catalog->add(2,index(mono_view),"late"),"sealed catalog immutable");check(catalog->resolve({9,0}).status==vm::StreamStatus::missing_asset,"unknown archive explicit");check(catalog->resolve({0,-1}).status==vm::StreamStatus::missing_asset,"negative member explicit");check(catalog->resolve({0,0}).status==vm::StreamStatus::missing_asset,"empty member explicit");check(view->body_reads==0,"catalog metadata does not read body");
    {auto other=std::make_shared<vm::StreamAssetCatalog>();check(other->add(0,index(view),"owned-file1-bgm69-fixture-f6fc3d25"),"independent same-label catalog");other->seal();const auto a=catalog->resolve({0,69}),b=other->resolve({0,69});check(a.status==vm::StreamStatus::completed&&b.status==vm::StreamStatus::completed&&a.view!=b.view,"catalog domain prevents cross-owner cache alias");check(view->body_reads==0,"scoped lazy residency remains metadata-only");}
    std::array<vm::StreamInstanceConfig,3> config;
    for(unsigned i=0;i<3;++i){config[i].construction={i==2?1u:2u,{i,i,i,i},table.table};config[i].player.decoder.channels=config[i].construction.channels;config[i].player.decoder.loop_enabled=false;config[i].player.decoder.service_divisor=30;}
    auto owner=std::make_shared<n::adxt_control_owner::Owner>(n::adxt_instances::control::Config{{3},{}});
    check(vm::StreamInstances::create(owner,config,catalog,{0,0,2}).status==vm::StreamStatus::unsupported_profile,"invalid mixer permutation refuses");
    auto opened=vm::StreamInstances::create(owner,config,catalog,{0,1,2});check(opened.status==vm::StreamStatus::completed&&bool(opened.value),"three actual native instances created");auto adapter=std::move(opened.value);
    check(vm::StreamInstances::create(owner,config,catalog,{0,1,2}).status==vm::StreamStatus::unsupported_profile,"factory refuses occupied native owner");check(adapter->phase(0).value==0,"idle phase");
    vm::StreamChannels engine(vm::file1_stream_gain_curve());vm::StreamChannelSnapshot state;for(unsigned i=0;i<3;++i){state.channels[i].maximum=127;state.channels[i].current=127;state.channels[i].level=127;state.channels[i].type=i==2?1:2;}check(engine.restore(state)==vm::StreamStatus::completed,"canonical initial levels");
    auto result=engine.request(0,69,0,1000,*adapter);check(vm::stream_accepted(result.status)&&result.original_return==0,"real owned source requested");
    until([&]{check(vm::stream_accepted(adapter->service(1000)),"initial native source service");return view->did_enter();},"source worker enters gated full-body read");
    check(!view->body_on_controller,"full body loads off controller");check(adapter->phase(0).value==1,"reading native source reports preparing");
    auto stopped=std::async(std::launch::async,[&]{return engine.stop(0,*adapter);});const auto bounded=stopped.wait_for(500ms)==std::future_status::ready;if(!bounded)view->release();const auto stop_status=stopped.get();check(bounded,"stop request does not wait for provider I/O");check(vm::stream_accepted(stop_status),"stop accepted while body in flight");view->release();
    until([&]{check(vm::stream_accepted(adapter->service(1000)),"native drain service");const auto s=adapter->inspect(0);return s.status==n::adxt_instances::Status::completed&&s.phase==n::adxt_instances::Phase::idle&&s.completed_stops==1&&s.source&&s.source->retired;},"canceled native source retires");check(adapter->phase(0).value==0,"stopped phase hides retained decoder retirement");
    result=engine.request(0,69,0,1000,*adapter);check(vm::stream_accepted(result.status),"stopped same-ID source restarts");result=engine.request(1,69,0,1000,*adapter);check(vm::stream_accepted(result.status),"stereo peer starts");result=engine.request(2,0,1,1000,*adapter);check(vm::stream_accepted(result.status),"mono peer starts");
    until([&]{check(vm::stream_accepted(engine.service(1000,*adapter)),"native source/engine service");for(unsigned i=0;i<3;++i){const auto o=adapter->inspect(std::uint8_t(i));if(!o.source||o.source->fault||o.source->output.channel[0].samples<4096||!o.source->output.voice.playing)return false;}return true;},"three actual sources prime");
    const auto before=adapter->inspect(0);check(before.source&&before.source->copied_samples>=4096,"owned content decoded/copied");const auto starts=before.starts;check(vm::stream_accepted(engine.pause(0,1000,*adapter)),"native pause accepted");check(engine.snapshot().channels[0].paused==1,"canonical pause state");
    result=engine.request(0,69,0,1000,*adapter);check(vm::stream_accepted(result.status)&&result.original_return==1,"same-ID paused active channel takes actual transition branch");check(adapter->inspect(0).starts==starts,"transition does not replace source");check(engine.snapshot().channels[0].paused==0,"transition unpauses canonical channel");
    check(vm::stream_accepted(engine.pause(1,1000,*adapter))&&vm::stream_accepted(engine.pause(2,1000,*adapter)),"peers pause independently");check(!adapter->inspect(1).source->output.voice.playing&&!adapter->inspect(2).source->output.voice.playing,"only owned BGM channel remains audible in native submix");
    check(engine.ramp(0,63,60)==vm::StreamStatus::completed,"nonzero engine-only ramp prepared");const auto step=engine.snapshot().channels[0].step;check(step<0,"ramp is nonzero before withholding engine updates");
    const auto prior_level=engine.snapshot().channels[0].level;std::atomic<unsigned> visits{};std::atomic<bool> pump_fault{};
    std::jthread pump([&](std::stop_token stop){while(!stop.stop_requested()){Operation work([&](auto& instances){const auto s=instances.service(1000);if(s!=n::adxt_instances::Status::completed&&s!=n::adxt_instances::Status::pending)pump_fault=true;});if(owner->run(work)!=n::adxt_control_owner::Admission::accepted)pump_fault=true;++visits;std::this_thread::sleep_for(1ms);}});
    std::array<float,1024> samples{};bool signal=false;const auto end=std::chrono::steady_clock::now()+2s;
    while(std::chrono::steady_clock::now()<end){samples.fill(0);check(owner->submix()->render_add(samples.data(),480)==n::adxt_output_session::Status::completed,"render bounded native submix");signal|=std::any_of(samples.begin(),samples.end(),[](float x){return x!=0;});std::this_thread::sleep_for(10ms);}
    pump.request_stop();pump.join();check(visits>0&&!pump_fault,"independent same-tick native service visits");check(signal,"actual owned decoder produces signal");check(std::bit_cast<std::uint32_t>(engine.snapshot().channels[0].step)==std::bit_cast<std::uint32_t>(step),"background source service does not advance engine ramp");
    check(engine.snapshot().channels[0].level==prior_level,"background pump does not advance canonical level");check(vm::stream_accepted(engine.service(1000,*adapter)),"one real engine service advances ramp");check(engine.snapshot().channels[0].level<prior_level&&engine.snapshot().channels[0].current<127,"explicit engine service alone advances call-based ramp");
    check(adapter->inspect(0).starts==starts,"background pump retains current source identity");check(!view->body_on_controller,"replacements retain off-controller body ownership");
    n::adxt_instances::Snapshot observed;Operation snapshot([&](auto& instances){observed=instances.snapshot();});check(owner->run(snapshot)==n::adxt_control_owner::Admission::accepted,"native output snapshot");check(observed.session.output.statistics.output_frames>0&&observed.session.output.statistics.underrun_frames==0,"withheld engine service loses no native output frames");
    const auto failed=adapter->start(0,{7,69},1000);check(failed==vm::StreamStatus::missing_asset,"bad source refuses before replacement");check(adapter->inspect(0).starts==starts,"refused source preserves active instance");check(adapter->phase(3).status==vm::StreamStatus::invalid_channel,"bad channel explicit");
    check(vm::stream_accepted(adapter->close()),"native child destruction requested");check(adapter->service(1000)==vm::StreamStatus::closed,"closed adapter refuses");adapter.reset();owner->request_stop();check(owner->join()==n::adxt_control_owner::Join::completed,"canonical owner joins actual sources");check(owner->report().joined&&owner->report().final->instances==0,"no leaked native instances");
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"background_visits\":"<<visits<<",\"body_reads\":"<<view->body_reads<<",\"output_frames\":"<<observed.session.output.statistics.output_frames<<",\"underrun_frames\":"<<observed.session.output.statistics.underrun_frames<<",\"game_tick\":1000,\"game_launched\":false,\"hardware_output\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
