#include "packet_adapter.h"
#include "test_capture.h"
#include "../../../game/native/audio_banks/v2/test_inputs.hpp"
#include <atomic>
#include <iostream>
#include <thread>

namespace p=reo::native::bank_packets;
namespace b=p::banks;
namespace t=packet_test;
std::atomic<unsigned> assertions{};
void check(bool value){auto n=++assertions;if(!value)throw std::runtime_error("packet adapter assertion "+std::to_string(n));}
void ok(p::Status status){check(status==p::Status::ok);}
template<class T>T take(p::Result<T> result){ok(result.status);return std::move(result.value);}
struct Gains final:b::GainProvider {float gain(unsigned,unsigned,std::uint64_t)noexcept override{return 1;}};
struct GatedGains final:b::GainProvider {bool first=true;t::Event entered,resume;float gain(unsigned,unsigned,std::uint64_t)noexcept override{if(first){first=false;entered.signal();resume.wait();}return 1;}};
struct Wire {
    InputBank input=bank();std::vector<std::uint8_t> packet,ram;
    Wire(){for(auto* part:{&input.hd,&input.bd,&input.tq})part->resize((part->size()+15)&~std::size_t(15));
        ram.resize(0x2200);std::copy(input.hd.begin(),input.hd.end(),ram.begin()+0x100);std::copy(input.bd.begin(),input.bd.end(),ram.begin()+0x2000);std::copy(input.tq.begin(),input.tq.end(),ram.begin()+0x2100);load(0x4d,0);}
    void load(unsigned op,unsigned port){packet.assign(21,0);packet[0]=std::uint8_t(op);packet[1]=std::uint8_t(port>>8);packet[2]=std::uint8_t(port);
        const std::array<std::size_t,3> offsets{0x100,0x2000,0x2100},sizes{input.hd.size(),input.bd.size(),input.tq.size()};
        for(unsigned n=0;n<3;++n){auto* d=packet.data()+3+n*6;auto a=offsets[n],s=sizes[n];d[0]=a>>24;d[1]=a>>16;d[2]=a>>8;d[3]=std::uint8_t((a&0xf0)|((s>>20)&15));d[4]=s>>12;d[5]=s>>4;}}
    void bind(t::Capture& source){source.packet=packet;source.ram=ram;source.bank={input.hd,input.bd,input.tq};}
};
p::PacketResult packet(p::PacketAdapter& adapter,t::Capture& source){auto call=take(adapter.begin_call());return adapter.submit_packet(call,source);}
void mix(p::PacketAdapter& adapter,unsigned frames){std::array<float,400> out{};Gains gain;ok(adapter.mix_add(out.data(),frames,gain));}
void tests(){
    {
        auto session=std::make_shared<b::Session>();auto control=std::make_shared<t::GateAllocation>();p::Config cfg;cfg.max_calls=2;cfg.max_packet_bytes=64;cfg.control_allocation_source=control;
        p::PacketAdapter adapter(session,t::identity(),cfg);const auto reserved=adapter.control_budget();check(reserved.bytes==control->live_bytes&&reserved.assets==0);
        auto first=take(adapter.begin_call()),second=take(adapter.begin_call());check(adapter.begin_call().status==p::Status::capacity);
        t::Capture source;std::array<std::uint8_t,1> end{255};source.packet=end;ok(adapter.submit_packet(first,source).status);
        check(adapter.control_budget().allocations==reserved.allocations&&adapter.control_budget().bytes==reserved.bytes);first={};second={};adapter.join();
        check(adapter.begin_call().status==p::Status::closed);check(session->begin_submission().status==b::Status::ok);
        auto secondSource=std::make_shared<t::GateAllocation>();cfg.control_byte_budget=reserved.bytes-1;cfg.control_allocation_source=secondSource;bool partial=false;
        try{p::PacketAdapter candidate(session,t::identity(),cfg);}catch(const b::BudgetExceeded&){partial=true;}check(partial&&secondSource->allocations>0&&secondSource->live_bytes==0);
    }
    {
        auto session=std::make_shared<b::Session>();auto control=std::make_shared<t::GateAllocation>();p::Config cfg;cfg.control_byte_budget=1;cfg.control_allocation_source=control;bool refused=false;
        try{p::PacketAdapter adapter(session,t::identity(),cfg);}catch(const b::BudgetExceeded&){refused=true;}check(refused&&control->allocations==0&&control->live_bytes==0);
    }
    {
        auto session=std::make_shared<b::Session>();p::PacketAdapter adapter(session,t::identity());Wire wire;t::Capture source;wire.bind(source);
        auto loaded=packet(adapter,source);ok(loaded.status);check(loaded.parser_accepted&&source.ram_reads==3);
        const auto bytes=session->budget_observer()->snapshot().bytes,allocations=session->budget_observer()->snapshot().allocations;
        wire.packet.assign(21,255);wire.packet[0]=0x4e;wire.packet[1]=wire.packet[2]=0;source.packet=wire.packet;source.has_ram=false;source.ram_extent=64u*1024u*1024u;
        auto skipped=packet(adapter,source);ok(skipped.status);check(skipped.parser_accepted&&source.ram_reads==3);
        check(session->budget_observer()->snapshot().bytes==bytes&&session->budget_observer()->snapshot().allocations==allocations);
        source.packet=std::span<const std::uint8_t>(wire.packet.data(),20);check(!packet(adapter,source).parser_accepted&&session->snapshot().diagnostics.unsupported==1);
        adapter.join();
    }
    {
        auto session=std::make_shared<b::Session>();p::Config cfg;cfg.max_packet_bytes=32;p::PacketAdapter adapter(session,t::identity(),cfg);t::Capture source;
        std::vector<std::uint8_t> bytes(33,255);bytes[0]=0x29;bytes[1]=2;bytes[2]=0;source.packet=bytes;
        auto oversized=packet(adapter,source);check(oversized.status==p::Status::capacity&&!oversized.parser_accepted&&source.packet_reads==0&&session->snapshot().ports[0].volume==256);
        const std::array<std::uint8_t,8> prefix{0x29,2,0,0x4c,255,1,0,0x77};source.packet=prefix;auto result=packet(adapter,source);
        check(result.status==p::Status::invalid_input&&!result.parser_accepted&&result.commands_applied==2&&result.consumed==7);
        check(session->snapshot().ports[0].volume==512&&session->snapshot().diagnostics.unsupported==1);
        const std::array<std::uint8_t,3> stop{0x47,255,255};source.packet=stop;check(packet(adapter,source).parser_accepted&&session->snapshot().diagnostics.unsupported==2);
        const std::array<std::uint8_t,4> terminated{255,0x29,0,0};source.packet=terminated;check(packet(adapter,source).parser_accepted&&session->snapshot().ports[0].volume==512);
        source.present=false;check(!packet(adapter,source).parser_accepted);source.present=true;source.packet={};check(!packet(adapter,source).parser_accepted);adapter.join();
    }
    {
        auto session=std::make_shared<b::Session>();p::PacketAdapter adapter(session,t::identity());Wire wire;t::Capture source;wire.bind(source);source.profile.ram_incarnation=2;
        check(packet(adapter,source).status==p::Status::foreign_runtime&&source.packet_reads==0);source.profile=t::identity();source.change_after_packet=true;
        check(packet(adapter,source).status==p::Status::foreign_runtime&&source.ram_reads==0&&!session->snapshot().ports[0].loaded);source.change_after_packet=false;source.changed=false;
        source.fail_packet=true;check(packet(adapter,source).status==p::Status::capture_failed);source.fail_packet=false;
        source.has_ram=false;check(packet(adapter,source).status==p::Status::invalid_input&&session->budget_observer()->snapshot().assets==0);source.has_ram=true;
        wire.packet[3]=0xff;source.packet=wire.packet;check(packet(adapter,source).status==p::Status::invalid_input&&source.ram_reads==0);adapter.join();
    }
    {
        auto session=std::make_shared<b::Session>();p::PacketAdapter adapter(session,t::identity());Wire wire;t::Capture source;wire.bind(source);source.ram_extent=0x2110;
        wire.packet.insert(wire.packet.begin(),{0x29,2,0});source.packet=wire.packet;auto invalid=packet(adapter,source);
        check(invalid.status==p::Status::invalid_input&&source.ram_reads==0&&session->budget_observer()->snapshot().allocations==0&&session->snapshot().ports[0].volume==512);
        wire.load(0x4d,0);wire.packet[3]|=0xe0;source.packet=wire.packet;source.ram_extent=wire.ram.size();check(packet(adapter,source).parser_accepted&&session->snapshot().ports[0].loaded);adapter.join();
    }
    {
        auto session=std::make_shared<b::Session>();p::PacketAdapter adapter(session,t::identity()),other(session,t::identity());auto foreign=take(other.begin_call());t::Capture source;
        std::uint32_t count=777;check(adapter.port_state(foreign,0,count).status==p::Status::rejected&&count==777);
        check(adapter.submit_packet(foreign,source).status==p::Status::rejected&&source.packet_reads==0);foreign={};other.join();adapter.join();
    }
    {
        auto session=std::make_shared<b::Session>();p::PacketAdapter adapter(session,t::identity());Wire wire;t::Capture source;wire.bind(source);auto call=take(adapter.begin_call());
        check(adapter.submit_bank(call,14,source)==p::Status::invalid_input&&source.bank_reads==0);ok(adapter.submit_bank(call,3,source));const auto fingerprint=session->snapshot().ports[3].fingerprint;
        source.fail_bank=true;check(adapter.submit_bank(call,3,source)==p::Status::capture_failed&&session->snapshot().ports[3].fingerprint==fingerprint);
        std::uint32_t count=999;auto state=adapter.port_state(call,3,count);ok(state.status);check(state.value==1&&count==1);check(adapter.pending_loads(call).value==0);
        ok(adapter.reset(call));check(session->snapshot().frame_clock==0&&!session->snapshot().ports[3].loaded);call={};adapter.join();
    }
    // Prefix mutation survives a failed/stale later load. No later command or
    // stale decoded asset publishes after a reset during real capture work.
    for(bool pausePrepare:{false,true}){
        auto allocation=std::make_shared<t::GateAllocation>();b::Config bc;bc.allocation_source=allocation;auto session=std::make_shared<b::Session>(bc);p::PacketAdapter adapter(session,t::identity());
        Wire wire;wire.packet.insert(wire.packet.begin(),{0x29,2,0});wire.packet.insert(wire.packet.end(),{0x42,0});t::Capture source;wire.bind(source);
        if(pausePrepare)source.pause_prepare=allocation;else source.pause_ram=true;p::PacketResult result;
        std::thread producer([&]{auto call=take(adapter.begin_call());result=adapter.submit_packet(call,source);});
        if(pausePrepare)allocation->entered.wait();else source.entered.wait();check(session->snapshot().ports[0].volume==512);
        auto reset=take(adapter.begin_call());ok(adapter.reset(reset));reset={};if(pausePrepare)allocation->resume.signal();else source.resume.signal();producer.join();
        check(result.status==p::Status::stale_generation&&!result.parser_accepted&&!session->snapshot().ports[0].loaded&&!session->snapshot().mono);
        check(session->budget_observer()->snapshot().assets==0);adapter.join();
    }
    {
        auto session=std::make_shared<b::Session>();p::PacketAdapter adapter(session,t::identity());const std::array<std::uint8_t,3> volume{0x29,2,0};t::Capture source;source.packet=volume;source.pause_packet=true;p::PacketResult result;
        std::thread producer([&]{auto call=take(adapter.begin_call());result=adapter.submit_packet(call,source);});source.entered.wait();auto reset=take(adapter.begin_call());ok(adapter.reset(reset));reset={};source.resume.signal();producer.join();
        check(result.status==p::Status::stale_generation&&session->snapshot().ports[0].volume==256);adapter.join();
    }
    {
        auto session=std::make_shared<b::Session>();p::PacketAdapter adapter(session,t::identity());Wire wire;wire.packet.insert(wire.packet.begin(),{0x29,2,0});t::Capture source;wire.bind(source);source.pause_ram=true;
        p::PacketResult result;std::thread producer([&]{auto call=take(adapter.begin_call());result=adapter.submit_packet(call,source);});source.entered.wait();adapter.request_stop();check(adapter.begin_call().status==p::Status::closed);
        std::atomic<bool> joined{};t::Event entering;std::thread joiner([&]{entering.signal();adapter.join();joined=true;});entering.wait();check(!joined);
        source.resume.signal();producer.join();joiner.join();check(joined&&result.status==p::Status::closed&&!session->snapshot().ports[0].loaded&&session->snapshot().ports[0].volume==512);
        check(session->budget_observer()->snapshot().assets==0);mix(adapter,1);check(session->snapshot().frame_clock==1);
    }
    // A last clip free pauses control parsing between two prefix commands.
    // Bank render must wait the complete prefix, not observe that gap.
    {
        auto allocation=std::make_shared<t::GateAllocation>();b::Config cfg;cfg.allocation_source=allocation;auto session=std::make_shared<b::Session>(cfg);p::PacketAdapter adapter(session,t::identity());Wire wire;t::Capture source;wire.bind(source);
        {auto call=take(adapter.begin_call());ok(adapter.submit_bank(call,0,source));}
        const std::array<std::uint8_t,5> note{0,0,0,0,0};source.packet=note;check(packet(adapter,source).parser_accepted);mix(adapter,1);
        {auto call=take(adapter.begin_call());ok(adapter.submit_bank(call,0,source));}mix(adapter,199);check(session->snapshot().retired_clips==1);
        const std::array<std::uint8_t,4> controls{0x41,1,0x42,0};source.packet=controls;allocation->pause_free=true;
        std::thread producer([&]{check(packet(adapter,source).parser_accepted);});allocation->entered.wait();check(session->snapshot().muted&&!session->snapshot().mono);
        std::atomic<bool> mixed{};t::Event entering;std::thread renderer([&]{entering.signal();mix(adapter,1);mixed=true;});entering.wait();check(!mixed);
        allocation->resume.signal();producer.join();renderer.join();check(mixed&&session->snapshot().mono);adapter.join();
    }
    // Copy completes while an existing render holds transaction serialization.
    // Later mutation of caller bytes cannot alter the already-owned packet.
    {
        auto session=std::make_shared<b::Session>();p::PacketAdapter adapter(session,t::identity());GatedGains gains;std::array<float,2> out{};
        std::thread renderer([&]{ok(adapter.mix_add(out.data(),1,gains));});gains.entered.wait();std::array<std::uint8_t,3> volume{0x29,2,0};t::Capture source;source.packet=volume;source.notify_packet_copy=true;
        std::thread producer([&]{check(packet(adapter,source).parser_accepted);});source.packet_copied.wait();volume[1]=4;gains.resume.signal();renderer.join();producer.join();
        check(session->snapshot().ports[0].volume==512&&source.packet_reads==1);adapter.join();
    }
    // Source relocks even after an invalid bank load. Stage invalid decoding
    // outside transaction, enter a paused render, then finish failure cleanup.
    // Its return must wait for that render, preserving the already-applied
    // volume prefix and suppressing the command following the failed load.
    {
        auto allocation=std::make_shared<t::GateAllocation>();b::Config cfg;cfg.allocation_source=allocation;auto session=std::make_shared<b::Session>(cfg);p::PacketAdapter adapter(session,t::identity());Wire wire;
        wire.ram[0x100]=0;wire.packet.insert(wire.packet.begin(),{0x29,2,0});wire.packet.insert(wire.packet.end(),{0x42,0});t::Capture source;wire.bind(source);source.pause_prepare=allocation;
        p::PacketResult result;t::Event returned;std::thread producer([&]{auto call=take(adapter.begin_call());result=adapter.submit_packet(call,source);returned.signal();});allocation->entered.wait();check(session->snapshot().ports[0].volume==512);
        GatedGains gains;std::array<float,2> out{};std::thread renderer([&]{ok(adapter.mix_add(out.data(),1,gains));});gains.entered.wait();allocation->notify_empty=true;allocation->resume.signal();allocation->empty.wait();
        const bool waited=!returned.wait_for(std::chrono::milliseconds(100));gains.resume.signal();renderer.join();producer.join();check(waited);
        check(returned.wait_for(std::chrono::milliseconds(100))&&result.status==p::Status::invalid_asset&&!result.parser_accepted&&result.commands_applied==1);
        check(session->snapshot().ports[0].volume==512&&!session->snapshot().mono&&!session->snapshot().ports[0].loaded);adapter.join();
    }
    {
        auto session=std::make_shared<b::Session>();auto control=std::make_shared<t::GateAllocation>();p::Config cfg;cfg.control_allocation_source=control;p::Call retained;
        {p::PacketAdapter adapter(session,t::identity(),cfg);retained=take(adapter.begin_call());}
        check(control->live_bytes>0);retained={};check(control->live_bytes==0);
    }
}
int main()try{tests();std::cout<<"packet_adapter assertions="<<assertions.load()<<"\n";return 0;}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
