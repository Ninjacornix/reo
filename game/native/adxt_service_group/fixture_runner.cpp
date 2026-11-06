#include "service_group.hpp"
#include <bit>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace group=reo::native::adxt_service_group;
namespace clock_ns=reo::native::adxt_estimated_clock;
struct Action {std::string event,table,field;int slot{},target{},value{};bool reenter{},done{};};
struct Event {std::string event;int slot{},cri{},rna{};std::uint32_t busy{};};
struct World;
struct ModelGuards final:group::Guards {
    World& w;explicit ModelGuards(World& world):w(world){}
    void enter(group::Domain)noexcept override;void leave(group::Domain)noexcept override;
};
struct ModelWork final:group::ActiveWork {
    World& w;std::string event;int slot;std::int8_t activity{};
    ModelWork(World& world,std::string e,int i):w(world),event(std::move(e)),slot(i){}
    std::int8_t active()const noexcept override{return activity;}
    void service()noexcept override;
};
struct ModelStream final:group::Stream {
    World& w;int slot;std::int8_t activity{},state{};
    ModelStream(World& world,int i):w(world),slot(i){}
    std::int8_t active()const noexcept override{return activity;}
    std::int8_t phase()const noexcept override{return state;}
    void service_phase(group::Phase)noexcept override;
    void propagate_input_end()noexcept override;void propagate_error()noexcept override;
};
struct World {
    std::shared_ptr<clock_ns::Shared> clock=std::make_shared<clock_ns::Shared>();
    int cri{},rna{};std::vector<Event> events;std::vector<Action> actions;
    std::shared_ptr<ModelGuards> guards=std::make_shared<ModelGuards>(*this);
    std::shared_ptr<ModelWork> dtr=std::make_shared<ModelWork>(*this,"dtr",-1),dtx=std::make_shared<ModelWork>(*this,"dtx",-1);
    group::Group owner{clock,guards,dtr,dtx};
    std::array<std::shared_ptr<ModelWork>,16> decoders,rnas;
    std::array<std::shared_ptr<ModelStream>,16> streams;
    World(){events.reserve(4096);for(int i=0;i<16;++i){
        decoders[i]=std::make_shared<ModelWork>(*this,"decode",i);rnas[i]=std::make_shared<ModelWork>(*this,"rna",i);streams[i]=std::make_shared<ModelStream>(*this,i);
        if(!owner.set_decoder(i,decoders[i]) || !owner.set_rna(i,rnas[i]) || !owner.set_stream(i,streams[i]))std::terminate();}}
    void observe(const std::string& event,int slot=-1)noexcept{events.push_back({event,slot,cri,rna,clock->service_busy});}
    void child(const std::string& event,int slot)noexcept {
        observe(event,slot);
        for(auto& action:actions){
            if(action.done || action.event!=event || action.slot!=slot)continue;
            action.done=true;
            if(action.reenter){if(owner.service()!=group::Status::busy)std::terminate();continue;}
            const auto value=std::bit_cast<std::int8_t>(static_cast<std::uint8_t>(action.value));
            if(action.table=="decoder")decoders[action.target]->activity=value;
            else if(action.table=="rna")rnas[action.target]->activity=value;
            else if(action.field=="phase")streams[action.target]->state=value;
            else streams[action.target]->activity=value;
        }
    }
};
void ModelGuards::enter(group::Domain d)noexcept{if(d==group::Domain::cri){++w.cri;w.observe("cri_enter");}else{++w.rna;w.observe("rna_enter");}}
void ModelGuards::leave(group::Domain d)noexcept{if(d==group::Domain::cri){--w.cri;w.observe("cri_leave");}else{--w.rna;w.observe("rna_leave");}}
void ModelWork::service()noexcept{w.child(event,slot);}
void ModelStream::service_phase(group::Phase p)noexcept{w.child(p==group::Phase::ready?"ready":p==group::Phase::buffering?"buffer":p==group::Phase::playing?"play":"drain",slot);}
void ModelStream::propagate_input_end()noexcept{w.child("input_end",slot);}
void ModelStream::propagate_error()noexcept{w.child("error",slot);}
template<class F>void array_json(std::ostream& out,F f){out<<'[';for(int i=0;i<16;++i){if(i)out<<',';out<<unsigned(static_cast<std::uint8_t>(f(i)));}out<<']';}
int main(int argc,char** argv){
    if(argc!=3)return 2;
    std::ifstream in(argv[1]);std::ofstream out(argv[2]);std::string name;
    while(in>>name){
        World w;in>>w.clock->service_busy;unsigned value{},count{};
        for(auto& v:w.decoders){in>>value;v->activity=std::bit_cast<std::int8_t>(static_cast<std::uint8_t>(value));}
        for(auto& v:w.streams){in>>value;v->activity=std::bit_cast<std::int8_t>(static_cast<std::uint8_t>(value));}
        for(auto& v:w.rnas){in>>value;v->activity=std::bit_cast<std::int8_t>(static_cast<std::uint8_t>(value));}
        for(auto& v:w.streams){in>>value;v->state=std::bit_cast<std::int8_t>(static_cast<std::uint8_t>(value));}
        in>>count;for(unsigned i=0;i<count;++i){Action a;in>>a.event>>a.slot>>a.reenter>>a.table>>a.target>>a.field>>a.value;w.actions.push_back(std::move(a));}
        if(!in)return 3;
        const auto before=w.clock->service_busy;const auto status=w.owner.service();
        if(status!=(before?group::Status::busy:group::Status::completed) || w.cri || w.rna)return 4;
        for(const auto& a:w.actions)if(!a.done)return 5;
        out<<"{\"name\":\""<<name<<"\",\"projection\":{\"events\":[";
        for(std::size_t i=0;i<w.events.size();++i){const auto& e=w.events[i];if(i)out<<',';out<<"{\"event\":\""<<e.event<<"\",\"slot\":"<<e.slot<<",\"busy\":"<<e.busy<<",\"cri_depth\":"<<e.cri<<",\"rna_depth\":"<<e.rna<<'}';}
        out<<"],\"after\":{\"busy\":"<<w.clock->service_busy<<",\"decoder\":";array_json(out,[&](int i){return w.decoders[i]->activity;});
        out<<",\"stream\":";array_json(out,[&](int i){return w.streams[i]->activity;});out<<",\"rna\":";array_json(out,[&](int i){return w.rnas[i]->activity;});
        out<<",\"phase\":";array_json(out,[&](int i){return w.streams[i]->state;});out<<"}}}\n";
    }
    return in.eof() && out?0:6;
}
