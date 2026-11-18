#include "completion.hpp"
#include "../adxt_transfer_groups/transfer_groups.hpp"
#include <bit>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
namespace c=reo::native::adxt_serviced_clock;
namespace g=reo::native::adxt_service_group;
namespace t=reo::native::adxt_transfer_groups;
struct World;
struct Event{std::string event;int slot{},cri{},rna{},chunk{};std::uint32_t busy{};};
struct Update{std::string event,field;std::uint32_t value{};bool done{};};
struct Guards final:g::Guards,t::ChunkGuard {
    World& w;explicit Guards(World& v):w(v){}
    void enter(g::Domain)noexcept override;void leave(g::Domain)noexcept override;void enter()noexcept override;void leave()noexcept override;
};
struct Work final:g::ActiveWork {
    World& w;std::string event;Work(World& v,std::string e):w(v),event(std::move(e)){}
    std::int8_t active()const noexcept override{return 1;}void service()noexcept override;
};
struct Stream final:g::Stream {
    World& w;explicit Stream(World& v):w(v){}
    std::int8_t active()const noexcept override{return 1;}std::int8_t phase()const noexcept override;
    void service_phase(g::Phase)noexcept override;void propagate_input_end()noexcept override;void propagate_error()noexcept override;
};
struct World final:c::Service {
    std::shared_ptr<c::clock::Shared> shared=std::make_shared<c::clock::Shared>();
    c::clock::Stream state;c::clock::integer::Observation obs;
    int cri{},rna{},chunk{};unsigned diagnostics{};std::vector<Event> events;std::vector<Update> updates;
    std::shared_ptr<Guards> guards=std::make_shared<Guards>(*this);
    std::shared_ptr<t::DtxGroup> dtx=std::make_shared<t::DtxGroup>(guards);std::shared_ptr<t::DtrGroup> dtr=std::make_shared<t::DtrGroup>(dtx);
    g::Group group{shared,guards,dtr,dtx};
    World(){events.reserve(256);if(!group.set_decoder(0,std::make_shared<Work>(*this,"decode")) || !group.set_stream(0,std::make_shared<Stream>(*this)) || !group.set_rna(0,std::make_shared<Work>(*this,"rna")) || !dtr->set(0,std::make_shared<Work>(*this,"dtr")) || !dtx->set(0,std::make_shared<Work>(*this,"dtx")))std::terminate();}
    const c::clock::Shared* clock_identity()const noexcept override{return shared.get();}
    c::clock::integer::Observation observation()const noexcept override{return obs;}
    void discard_diagnostic()noexcept override{++diagnostics;}
    c::ServiceStatus run_and_refresh(c::clock::Stream& stream,c::clock::integer::Observation& observation)noexcept override{
        const auto result=group.service();stream=state;observation=obs;return result==g::Status::completed?c::ServiceStatus::completed:c::ServiceStatus::busy;
    }
    void observe(std::string event,int slot=-1)noexcept{events.push_back({std::move(event),slot,cri,rna,chunk,shared->service_busy});}
    void child(const std::string& event)noexcept{
        observe(event,0);for(auto& u:updates)if(!u.done && u.event==event){u.done=true;
            if(u.field=="decoded")obs.decoded=u.value;else if(u.field=="state")obs.state=static_cast<std::uint8_t>(u.value);else if(u.field=="output_bytes")obs.output_bytes=u.value;else if(u.field=="rna_free_bytes")obs.rna_free_bytes=u.value;else std::terminate();}
    }
};
void Guards::enter(g::Domain d)noexcept{if(d==g::Domain::cri){++w.cri;w.observe("cri_enter");}else{++w.rna;w.observe("rna_enter");}}
void Guards::leave(g::Domain d)noexcept{if(d==g::Domain::cri){--w.cri;w.observe("cri_leave");}else{--w.rna;w.observe("rna_leave");}}
void Guards::enter()noexcept{++w.chunk;w.observe("chunk_enter");}void Guards::leave()noexcept{--w.chunk;w.observe("chunk_leave");}
void Work::service()noexcept{w.child(event);}
std::int8_t Stream::phase()const noexcept{return std::bit_cast<std::int8_t>(w.obs.state);}
void Stream::service_phase(g::Phase p)noexcept{w.child(p==g::Phase::ready?"ready":p==g::Phase::buffering?"buffer":p==g::Phase::playing?"play":"drain");}
void Stream::propagate_input_end()noexcept{w.child("input_end");}void Stream::propagate_error()noexcept{w.child("error");}
int main(int argc,char** argv){
    if(argc!=3)return 2;
    std::ifstream in(argv[1]);std::ofstream out(argv[2]);std::string name;
    while(in>>name){
        auto w=std::make_shared<World>();std::array<std::uint32_t,22> f{};for(auto& v:f)in>>v;unsigned n{};in>>n;
        for(unsigned i=0;i<n;++i){Update u;in>>u.event>>u.field>>u.value;w->updates.push_back(std::move(u));}if(!in)return 3;
        w->obs={static_cast<std::uint8_t>(f[0]),f[1],f[2],f[3],f[6],f[7],static_cast<std::int16_t>(f[4]),static_cast<std::int16_t>(f[5]),bool(f[8]),f[9],f[10]};
        w->shared->mode={f[11],f[12],f[13]};w->shared->rebase_selector=f[14];w->shared->service_busy=f[15];w->shared->drift_bits=f[21];
        w->state={f[18],f[17],static_cast<std::uint8_t>(f[19]),static_cast<std::uint8_t>(f[20])};c::Completion owner(w->shared,w->state,w);
        const auto result=owner.discard(f[16]);const auto state=owner.snapshot();
        if(w->cri || w->rna || w->chunk || w->shared->in_call)return 4;
        out<<"{\"name\":\""<<name<<"\",\"status\":"<<static_cast<unsigned>(result)<<",\"projection\":{\"estimate_base_u32\":"<<state.estimate_base<<",\"tick_base_u32\":"<<state.tick_base
           <<",\"paused_byte\":"<<unsigned(state.paused)<<",\"rna_play_byte\":"<<unsigned(state.rna_play)<<",\"mode_u32\":"<<w->shared->mode.selection<<",\"counter_u32\":"<<w->shared->mode.resynchronizations<<",\"drift_bits_u32\":"<<w->shared->drift_bits<<"},\"service_busy\":"<<w->shared->service_busy<<",\"diagnostics\":"<<w->diagnostics<<",\"dispatch\":[";
        for(std::size_t i=0;i<w->events.size();++i){const auto& e=w->events[i];if(i)out<<',';out<<"{\"event\":\""<<e.event<<"\",\"slot\":"<<e.slot<<",\"busy\":"<<e.busy<<",\"cri\":"<<e.cri<<",\"rna\":"<<e.rna<<",\"chunk\":"<<e.chunk<<'}';}
        out<<"],\"queue_after\":{\"state\":"<<unsigned(w->obs.state)<<",\"decoded\":"<<w->obs.decoded<<",\"output_bytes\":"<<w->obs.output_bytes<<",\"rna_free_bytes\":"<<w->obs.rna_free_bytes<<"}}\n";
    }
    return in.eof() && out?0:5;
}
