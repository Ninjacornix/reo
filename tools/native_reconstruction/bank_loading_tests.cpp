#include "game/native/gameplay_bank_loading/loader.hpp"
#include "game/native/gameplay_bank_loading/aliases.hpp"
#include "game/native/resources/virtual_file_view.hpp"
#include "game/native/resources_windows/pinned_file.hpp"
#include "reference.hpp"
#include "owned_iso.hpp"
#include <chrono>
#include <condition_variable>
#include <fstream>
#include <future>
#include <iostream>
#include <source_location>
#include <thread>
namespace l=reo::native::gameplay_bank_loading;
namespace a=reo::native::gameplay_audio;
namespace b=reo::native::audio_banks::v2;
namespace r=reo::native::resources;
namespace af=reo::native::afs_source_range;
using namespace std::chrono_literals;
std::uint64_t checks{},lookup_cases{},original_calls{},stock_banks{},stock_commands{},stock_mixed{},signal_samples{},contract_cases{};
std::string active_case;
void check(bool yes,const std::source_location where=std::source_location::current()){
    ++checks;if(!yes)throw std::runtime_error(active_case+" line "+std::to_string(where.line()));
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++original_calls;
    switch(context->pc){
#include "original_dispatch.inc"
        default:throw std::runtime_error("Unexpected original alias helper "+std::to_string(context->pc));
    }
}
void aliases(std::vector<std::uint8_t>& memory,const char* path){
    std::ifstream file(path,std::ios::binary);unsigned segments{};file.read(reinterpret_cast<char*>(&segments),4);check(segments>0&&segments<500);
    for(unsigned i=0;i<segments;++i){unsigned at{},count{};file.read(reinterpret_cast<char*>(&at),4);file.read(reinterpret_cast<char*>(&count),4);check(at<memory.size()&&count<=memory.size()-at);file.read(reinterpret_cast<char*>(memory.data()+at),count);check(bool(file));}
    const auto compare=[&](const std::string& name){
        active_case="alias "+name;std::fill_n(memory.data()+0x500000,1024,0);std::copy(name.begin(),name.end(),memory.begin()+0x500000);
        R5900Context ctx{};ctx.pc=0x1ab310;SET_GPR_U32(&ctx,4,0x500000);SET_GPR_U32(&ctx,29,0x1e00000);SET_GPR_U32(&ctx,31,0x1234);PS2Runtime runtime;sub_001AB310_0x1ab310(memory.data(),&ctx,&runtime);check(ctx.pc==0x1234);
        const auto member=l::sound_member(name);check((member?std::int64_t(*member):-1)==GPR_S64(&ctx,2));
        const auto normalized=l::normalize_sound_name(name);check(normalized&&*normalized==reinterpret_cast<const char*>(memory.data()+0x1e00000-0x350+0x150));++lookup_cases;
    };
    for(const auto name:l::sound_aliases()){
        std::string lower(name);for(auto& c:lower)if(c>='A'&&c<='Z')c=char(c-'A'+'a');
        for(const auto& input:std::array<std::string,6>{std::string(name),lower,"cdrom0:\\ROM\\"+lower,"q/RDT/"+lower,"someEDIT/"+lower,lower+";1"})compare(input);
        for(const auto separator:{'-','.','\\','/'}){auto input=lower;std::replace(input.begin(),input.end(),'_',separator);compare(input);}
    }
    for(unsigned i=1;i<128;++i)compare(std::string(1,char(i)));
    for(const auto& input:std::array<std::string,9>{"","ROM/","RDT\\","EDIT/","ROMX/COMMON.SND","aROM/common.snd","aEDIT/common.snd",std::string(255,'x'),"rdt/a-rom/common.snd"})compare(input);
    check(!l::sound_member(std::string(256,'x'))&&!l::normalize_sound_name(std::string(1,char(128))));
}
struct Gains final:b::GainProvider {float gain(unsigned,unsigned,std::uint64_t)noexcept override{return 1;}};
l::LoadResult wait(l::Loader& loader,const l::LoadTicket& ticket){
    const auto deadline=std::chrono::steady_clock::now()+10s;
    for(;;){loader.service();const auto result=loader.poll(ticket);if(result.status!=l::LoadStatus::pending)return result;if(std::chrono::steady_clock::now()>=deadline)throw std::runtime_error("Native bank loading timeout");std::this_thread::yield();}
}
struct Gate final:r::ByteView {
    std::shared_ptr<const r::ByteView> base;
    mutable std::mutex mutex;
    mutable std::condition_variable cv;
    mutable bool armed{},entered{},released{},fail{};
    mutable unsigned reads{};
    std::thread::id control=std::this_thread::get_id();
    explicit Gate(std::shared_ptr<const r::ByteView> value):base(std::move(value)){}
    std::uint64_t size()const noexcept override{return base->size();}
    r::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override{
        bool failure{};{std::unique_lock lock(mutex);if(armed){if(std::this_thread::get_id()==control)throw std::runtime_error("Bank payload read on control owner");++reads;entered=true;cv.notify_all();cv.wait(lock,[&]{return released;});failure=fail;}}
        if(failure){std::fill(out.begin(),out.end(),std::byte(0x45));return {r::Status::source_failure,0};}
        return base->read(at,out);
    }
    void arm(){std::lock_guard lock(mutex);armed=true;entered=released=fail=false;}
    void release(){std::lock_guard lock(mutex);released=true;cv.notify_all();}
    void await(){std::unique_lock lock(mutex);check(cv.wait_for(lock,5s,[&]{return entered;}));}
};
struct Release {std::shared_ptr<Gate> value;~Release(){value->release();}};
std::shared_ptr<const af::Archive> open_archive(std::shared_ptr<const r::ByteView> bytes){
    const auto opened=af::Archive::open(bytes,0,bytes->size());check(opened.status==af::Status::completed&&opened.archive->count()==422);return opened.archive;
}
void contracts(std::shared_ptr<const r::ByteView> original){
    active_case="named bank owner contracts";
    const auto original_archive=open_archive(original);const auto common=original_archive->member(297);check(common.status==af::Status::completed);std::vector<std::uint8_t> common_bytes(common.view->size());check(common.view->read(0,{reinterpret_cast<std::byte*>(common_bytes.data()),common_bytes.size()}).status==r::Status::ok);
    auto gate=std::make_shared<Gate>(original);auto archive=open_archive(gate);reo::native::gameplay_session::Random random;
    auto engine=std::make_shared<b::Session>();auto owner=std::make_shared<a::Owner>(engine,random);l::Loader loader(owner,archive);Release release{gate};
    gate->arm();const auto active=loader.enqueue("common",0);check(active.status==l::LoadStatus::accepted);loader.service();loader.service();gate->await();check(owner->state(0)==a::Status::pending);++contract_cases;
    // Eight queued requests plus an active read; ignored ready results also
    // retain their fixed slots. No unbounded history/completion allocation.
    std::array<l::LoadTicket,8> queued;
    for(auto& ticket:queued){const auto result=loader.enqueue("common",1);check(result.status==l::LoadStatus::accepted);ticket=result.ticket;}
    check(loader.enqueue("common",2).status==l::LoadStatus::full);check(loader.cancel(queued[3]));check(loader.poll(queued[3]).status==l::LoadStatus::stale);const auto replacement=loader.enqueue("common",1);check(replacement.status==l::LoadStatus::accepted);++contract_cases;
    check(loader.cancel(active.ticket));check(owner->state(0)!=a::Status::pending);check(loader.poll(active.ticket).status==l::LoadStatus::stale);loader.service();loader.service();check(loader.poll(queued[0]).status==l::LoadStatus::pending);gate->release();check(wait(loader,queued[0]).status==l::LoadStatus::completed);++contract_cases;
    const auto extra_one=loader.enqueue("common",1);check(extra_one.status==l::LoadStatus::accepted);loader.service();const auto extra_two=loader.enqueue("common",1);check(extra_two.status==l::LoadStatus::accepted);
    for(unsigned i=0;i<9;++i){loader.service();}check(loader.enqueue("common",1).status==l::LoadStatus::full);++contract_cases;
    for(unsigned i=1;i<queued.size();++i){if(i!=3)check(wait(loader,queued[i]).status==l::LoadStatus::cached);}check(wait(loader,replacement.ticket).status==l::LoadStatus::cached);check(wait(loader,extra_one.ticket).status==l::LoadStatus::cached&&wait(loader,extra_two.ticket).status==l::LoadStatus::cached);
    const auto cached=loader.enqueue("common",1);check(wait(loader,cached.ticket).status==l::LoadStatus::cached);check(loader.poll(cached.ticket).status==l::LoadStatus::stale);++contract_cases;
    check(owner->request({1,0}).commands>0);const auto before=engine->snapshot();const auto keep=loader.enqueue("common",1);check(wait(loader,keep.ticket).status==l::LoadStatus::cached);const auto after=engine->snapshot();unsigned active_voices{};for(unsigned i=0;i<16;++i){check(before.ports[1].requests[i].sequence.active==after.ports[1].requests[i].sequence.active);active_voices+=before.ports[1].requests[i].sequence.active;}check(active_voices>0);++contract_cases;
    const auto pending=owner->begin_bank(1);check(bool(pending)&&!owner->current(pending));check(owner->cancel(pending).status==a::Status::completed&&!owner->current(pending));check(owner->install(pending,common_bytes).status==a::Status::stale);const auto reload=loader.enqueue("common",1);check(wait(loader,reload.ticket).status==l::LoadStatus::completed);++contract_cases;
    const auto external=owner->begin_bank(1);check(owner->install(external,common_bytes).status==a::Status::completed&&owner->current(external));const auto refreshed=loader.enqueue("common",1);check(wait(loader,refreshed.ticket).status==l::LoadStatus::completed&&!owner->current(external));++contract_cases;
    const auto missing=loader.enqueue("not-an-asset",1);check(wait(loader,missing.ticket).status==l::LoadStatus::not_found&&owner->state(1)==a::Status::completed);check(loader.enqueue("common",14).status==l::LoadStatus::invalid_input);++contract_cases;
    // Active failed reads never publish a partial/old buffer as a loaded bank.
    gate->arm();const auto bad=loader.enqueue("start",2);loader.service();loader.service();gate->await();{std::lock_guard lock(gate->mutex);gate->fail=true;}gate->release();check(wait(loader,bad.ticket).status==l::LoadStatus::source_failure&&owner->state(2)!=a::Status::pending);++contract_cases;
    gate->arm();const auto stopped=loader.enqueue("common",3);loader.service();loader.service();gate->await();loader.shutdown();check(loader.enqueue("common",0).status==l::LoadStatus::closed&&loader.poll(stopped.ticket).status==l::LoadStatus::closed);auto joined=std::async(std::launch::async,[&]{return loader.join();});check(joined.wait_for(0s)==std::future_status::timeout);gate->release();check(joined.get());++contract_cases;
    l::Loader other(owner,archive);check(other.poll(active.ticket).status==l::LoadStatus::stale);other.shutdown();check(other.join());++contract_cases;
}
void stock(std::shared_ptr<const af::Archive> archive,const char* list){
    reo::native::gameplay_session::Random random,reference_random;auto engine=std::make_shared<b::Session>(),reference=std::make_shared<b::Session>();auto owner=std::make_shared<a::Owner>(engine,random);a::Owner direct(reference,reference_random);l::Loader loader(owner,archive);Gains gains;
    std::ifstream metadata(list);unsigned count{};metadata>>count;check(count==104);
    for(unsigned n=0;n<count;++n){unsigned member{};std::string name;metadata>>member>>name;check(bool(metadata));active_case="owned bank "+name;const unsigned port=n%14;
        const auto view=archive->member(member);check(view.status==af::Status::completed);std::vector<std::uint8_t> bytes(view.view->size());const auto read=view.view->read(0,{reinterpret_cast<std::byte*>(bytes.data()),bytes.size()});check(read.status==r::Status::ok&&read.bytes==bytes.size());
        const auto requested=loader.enqueue(name.substr(0,name.size()-4),port);check(requested.status==l::LoadStatus::accepted);const auto loaded=wait(loader,requested.ticket);check(loaded.member==member);const auto installed=direct.install(direct.begin_bank(port),bytes);
        if(name=="test.snd"){check(loaded.status==l::LoadStatus::bank_failure&&installed.status==a::Status::invalid_asset);continue;}
        check(loaded.status==l::LoadStatus::completed&&installed.status==a::Status::completed);++stock_banks;
        const auto again=loader.enqueue(name.substr(0,name.size()-4),port);check(wait(loader,again.ticket).status==l::LoadStatus::cached);
        const auto description=a::import_snd(bytes,port);check(description.status==a::Status::completed);
        for(unsigned cue=0;cue<128;++cue){const auto& row=description.value.descriptors[cue];if(row.type!=0||row.next!=255)continue;
            const b::Command stop=b::StopAll{false};check(engine->apply({&stop,1}).status==b::Status::ok&&reference->apply({&stop,1}).status==b::Status::ok);random.restore({31,217,0});reference_random.restore({31,217,0});
            const auto actual=owner->request({port,cue}),expected=direct.request({port,cue});check(actual.status==expected.status&&actual.commands==expected.commands&&random.state()==reference_random.state());stock_commands+=actual.commands;
            std::array<float,256> pcm{},expected_pcm{};check(engine->mix_add(pcm.data(),128,gains)==b::Status::ok&&reference->mix_add(expected_pcm.data(),128,gains)==b::Status::ok);check(pcm==expected_pcm);for(const auto sample:pcm)if(sample!=0)++signal_samples;stock_mixed+=128;
        }
    }
    check(stock_banks==103&&stock_commands>0&&signal_samples>0);loader.shutdown();check(loader.join());
}
int main(int argc,char** argv)try{
    check(argc==4);std::vector<std::uint8_t> memory(0x2000000);aliases(memory,argv[1]);
    const auto pinned=r::win32::PinnedFile::open_verified(std::filesystem::path(argv[3]),owned_iso_bytes,owned_iso_sha);check(pinned.status==r::win32::PinnedStatus::ok);
    reo::assets::VirtualFile file;file.size=1062582272;file.segments.push_back({0,file.size,924106752,std::make_shared<reo::assets::Source>(pinned.file->identity().final_path,pinned.file),{}});
    const auto view=r::VirtualFileView::create(file);check(view.status==r::Status::ok);contracts(view.view);stock(open_archive(view.view),argv[2]);
    std::cout<<"{\"checks\":"<<checks<<",\"lookup_cases\":"<<lookup_cases<<",\"original_calls\":"<<original_calls<<",\"stock_banks\":"<<stock_banks<<",\"stock_commands\":"<<stock_commands<<",\"mixed_frames\":"<<stock_mixed<<",\"signal_samples\":"<<signal_samples<<",\"contract_cases\":"<<contract_cases<<",\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
