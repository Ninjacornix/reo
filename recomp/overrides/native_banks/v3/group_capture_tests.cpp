#include "packet_adapter.h"
#include "test_capture.h"
#include "../../../../game/native/audio_banks/v2/test_inputs.hpp"
#include "../../../../game/native/ram_capture/cpu_authority_gate.hpp"
#include <future>
#include <iostream>
#include <thread>
namespace p=reo::native::bank_packets::v3;
namespace b=p::banks;
namespace g=reo::native::ram_capture;
namespace t=packet_test;
using namespace std::chrono_literals;
std::atomic<unsigned> checks{};
void check(bool value){auto n=++checks;if(!value)throw std::runtime_error("group capture assertion "+std::to_string(n));}
template<class T>T take(p::Result<T> r){check(r.status==p::Status::ok);return std::move(r.value);}
template<class Predicate>void until(Predicate f){auto end=std::chrono::steady_clock::now()+2s;while(!f()&&std::chrono::steady_clock::now()<end)std::this_thread::yield();check(f());}
struct Source:p::CaptureSource {
    InputBank input=bank();
    std::vector<std::uint8_t> packet,ram;
    mutable unsigned helpers{},groups{};
    mutable std::array<std::vector<std::uint8_t>,3> observed;
    p::MemoryIdentity profile=t::identity();
    Source(){for(auto* v:{&input.hd,&input.bd,&input.tq})v->resize((v->size()+15)&~std::size_t(15));
        ram.resize(0x2200);std::copy(input.hd.begin(),input.hd.end(),ram.begin()+0x100);std::copy(input.bd.begin(),input.bd.end(),ram.begin()+0x2000);std::copy(input.tq.begin(),input.tq.end(),ram.begin()+0x2100);
        packet.assign(21,0);packet[0]=0x4d;std::array<std::size_t,3> off{0x100,0x2000,0x2100},sizes{input.hd.size(),input.bd.size(),input.tq.size()};
        for(unsigned n=0;n<3;++n){auto*d=packet.data()+3+n*6;auto a=off[n],s=sizes[n];d[0]=a>>24;d[1]=a>>16;d[2]=a>>8;d[3]=(a&240)|((s>>20)&15);d[4]=s>>12;d[5]=s>>4;observed[n].resize(s);}}
    p::MemoryIdentity identity()const noexcept override{return profile;}
    bool packet_present()const noexcept override{return true;}
    std::size_t packet_bytes()const noexcept override{return packet.size();}
    std::size_t ram_view_bytes()const noexcept override{return ram.size();}
    bool ram_present()const noexcept override{return true;}
    bool copy_packet(std::span<std::uint8_t> out)const noexcept override{if(out.size()!=packet.size())return false;std::copy(packet.begin(),packet.end(),out.begin());return true;}
    bool copy_ram(std::size_t,std::span<std::uint8_t>)const noexcept override{++helpers;return true;}
    b::BankSizes direct_bank_sizes()const noexcept override{return {input.hd.size(),input.bd.size(),input.tq.size()};}
    bool copy_bank(p::Part,std::span<std::uint8_t>)const noexcept override{++helpers;return true;}
};
struct GroupSource final:Source {
    mutable g::Coordinator gate;
    mutable t::Event first,resume;
    bool paused{},fail{},change_identity{};
    std::shared_ptr<t::GateAllocation> pause_prepare;
    mutable std::atomic<bool> changed{};
    p::MemoryIdentity identity()const noexcept override{auto id=profile;if(changed)++id.ram_incarnation;return id;}
    p::Status copy_parts_v1(std::span<const p::PartCopyV1> parts)const noexcept override {
        ++groups;
        if(parts.size()!=3)return p::Status::invalid_input;
        auto group=gate.try_cpu_group(this);if(group.status!=g::Status::ok)return p::Status::capture_failed;
        for(unsigned n=0;n<3;++n){
            const auto& part=parts[n];std::span<const std::uint8_t> bytes;
            if(part.source==p::CopySourceV1::ram){if(part.offset>ram.size()||part.destination.size()>ram.size()-part.offset)return p::Status::capture_failed;bytes=std::span<const std::uint8_t>(ram).subspan(part.offset,part.destination.size());}
            else {if(part.offset||unsigned(part.source)!=unsigned(p::CopySourceV1::direct_hd)+n)return p::Status::invalid_input;
                bytes=n==0?std::span<const std::uint8_t>(input.hd):n==1?std::span<const std::uint8_t>(input.bd):std::span<const std::uint8_t>(input.tq);}
            if(bytes.size()!=part.destination.size()||observed[n].size()!=bytes.size())return p::Status::invalid_input;
            std::copy(bytes.begin(),bytes.end(),part.destination.begin());std::copy(bytes.begin(),bytes.end(),observed[n].begin());
            if(n==0&&paused){first.signal();resume.wait();}
            if(n==1&&fail)return p::Status::capture_failed;
        }
        if(change_identity)changed=true;
        if(pause_prepare)pause_prepare->pause_allocate=true;
        return p::Status::ok; // Local CpuGroup dies BEFORE adapter decode begins.
    }
};
void no_fallback_and_one_group(){
    for(bool packed:{false,true}){
        auto session=std::make_shared<b::Session>();p::PacketAdapter adapter(session,t::identity());Source source;auto call=take(adapter.begin_call());
        auto status=packed?adapter.submit_packet(call,source).status:adapter.submit_bank(call,0,source);
        check(status==p::Status::unsupported&&source.helpers==0&&source.groups==0);
        check(session->budget_observer()->snapshot().assets==0&&!session->snapshot().ports[0].loaded);
        GroupSource good;status=packed?adapter.submit_packet(call,good).status:adapter.submit_bank(call,0,good);
        check(status==p::Status::ok&&good.groups==1&&good.helpers==0&&session->snapshot().ports[0].loaded);
        if(packed){good.packet[0]=0x4e;good.packet[3]=255;good.ram.clear();check(adapter.submit_packet(call,good).status==p::Status::ok&&good.groups==1);}
        call={};adapter.join();
    }
}
void coherent_group_and_release(){
    for(bool packed:{false,true}){
        auto alloc=std::make_shared<t::GateAllocation>();b::Config bc;bc.allocation_source=alloc;auto session=std::make_shared<b::Session>(bc);p::PacketAdapter adapter(session,t::identity());GroupSource source;source.paused=true;source.pause_prepare=alloc;
        const auto old=source.input; p::Status result{};
        auto producer=std::async(std::launch::async,[&]{auto call=take(adapter.begin_call());return packed?adapter.submit_packet(call,source).status:adapter.submit_bank(call,0,source);});
        source.first.wait();check(source.gate.observe(&source).cpu_groups==1);
        auto graphics=std::async(std::launch::async,[&]{auto activity=source.gate.begin_graphics(&source);if(activity.status!=g::Status::ok)throw std::runtime_error("graphics admission");
            std::fill(source.input.hd.begin(),source.input.hd.end(),9);std::fill(source.input.bd.begin(),source.input.bd.end(),9);std::fill(source.input.tq.begin(),source.input.tq.end(),9);std::fill(source.ram.begin(),source.ram.end(),9);});
        until([&]{return source.gate.observe(&source).graphics_waiting==1;});
        check(graphics.wait_for(20ms)==std::future_status::timeout);source.resume.signal();alloc->entered.wait();
        // Decode's allocator is paused. Graphics can already acquire and finish:
        // this detects retaining the group into prepare/decode/install.
        const bool released=graphics.wait_for(1s)==std::future_status::ready;
        alloc->resume.signal();result=producer.get();graphics.get();
        check(released&&source.gate.observe(&source).cpu_groups==0);
        check(result==p::Status::ok&&source.groups==1&&source.helpers==0);
        check(source.observed[0]==old.hd&&source.observed[1]==old.bd&&source.observed[2]==old.tq);
        check(source.input.hd[0]==9&&session->snapshot().ports[0].loaded);adapter.join();
    }
}
void refusal_and_identity(){
    {b::Config bc;bc.max_asset_bytes=1;auto session=std::make_shared<b::Session>(bc);p::PacketAdapter adapter(session,t::identity());GroupSource source;auto call=take(adapter.begin_call());
        check(adapter.submit_bank(call,0,source)==p::Status::capacity&&source.groups==0&&source.helpers==0);call={};adapter.join();}
    for(bool identity_change:{false,true}){
        auto session=std::make_shared<b::Session>();p::PacketAdapter adapter(session,t::identity());GroupSource source;source.fail=!identity_change;source.change_identity=identity_change;auto call=take(adapter.begin_call());
        check(adapter.submit_bank(call,0,source)==(identity_change?p::Status::foreign_runtime:p::Status::capture_failed));
        check(source.groups==1&&source.helpers==0&&session->budget_observer()->snapshot().assets==0&&source.gate.observe(&source).cpu_groups==0);
        check(!session->snapshot().ports[0].loaded);call={};adapter.join();
    }
}
struct GatedGain final:b::GainProvider {t::Event entered,resume;bool first=true;float gain(unsigned,unsigned,std::uint64_t)noexcept override{if(first){first=false;entered.signal();resume.wait();}return 1;}};
void failed_group_frees_and_relocks(){
    auto alloc=std::make_shared<t::GateAllocation>();b::Config bc;bc.allocation_source=alloc;auto session=std::make_shared<b::Session>(bc);p::PacketAdapter adapter(session,t::identity());GroupSource source;
    source.paused=source.fail=true;source.packet.insert(source.packet.begin(),{0x29,2,0});source.packet.insert(source.packet.end(),{0x42,0});
    auto producer=std::async(std::launch::async,[&]{auto call=take(adapter.begin_call());return adapter.submit_packet(call,source);});source.first.wait();
    GatedGain gain;std::array<float,2> output{};auto renderer=std::async(std::launch::async,[&]{return adapter.mix_add(output.data(),1,gain);});gain.entered.wait();
    alloc->notify_empty=true;source.resume.signal();alloc->empty.wait();
    const bool relocked=producer.wait_for(100ms)==std::future_status::timeout;gain.resume.signal();check(renderer.get()==p::Status::ok);auto result=producer.get();
    check(relocked&&result.status==p::Status::capture_failed&&!result.parser_accepted&&result.commands_applied==1);
    check(source.groups==1&&session->budget_observer()->snapshot().assets==0&&session->snapshot().ports[0].volume==512&&!session->snapshot().mono);adapter.join();
}
int main()try{no_fallback_and_one_group();coherent_group_and_release();refusal_and_identity();failed_group_frees_and_relocks();std::cout<<"group_capture checks="<<checks.load()<<'\n';return 0;}catch(const std::exception&e){std::cerr<<e.what()<<'\n';return 1;}
