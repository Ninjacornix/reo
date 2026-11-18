#include "clock.hpp"
#include <iostream>
#include <string>
namespace n=reo::native::movie_selected_clock;
struct Script final:n::Query {n::Reply reply;unsigned calls{};n::Reply query(n::State,n::Words) noexcept override{++calls;return reply;}};
struct Hooks final:n::GuardHooks {
    unsigned enters{},leaves{};bool valid{true};
    void enter(std::uint32_t value) noexcept override{++enters;valid&=value==0x11223344;}
    void leave(std::uint32_t value) noexcept override{++leaves;valid&=value==0x55667788;}
};
struct Record {n::Event event;n::Snapshot snapshot;n::Words prior;};
struct Probe final:n::Probe {
    std::array<Record,16> records{};unsigned count{};bool overflow{};
    void event(n::Event kind,const n::Snapshot& snapshot,n::Words words) noexcept override{
        if(count==records.size()){overflow=true;return;}records[count++]={kind,snapshot,words};
    }
};
void print(const n::Snapshot& snap){
    const auto& s=snap.state;const auto& c=s.counter;
    for(auto value:{c.actual,c.requested,c.pause,c.buffering_pause,c.property_47,c.active_counter,c.increment,c.elapsed_counter,c.elapsed_origin,c.external_accumulator,
                    s.selector,s.pending,s.cached.numerator,s.cached.denominator,s.previous_sample,s.external_denominator,std::uint32_t(snap.external_present)})std::cout<<' '<<value;
    for(auto kind:snap.slots)std::cout<<' '<<unsigned(kind);
    std::cout<<' '<<snap.guard_depth<<' '<<snap.guard_tag;
}
int main(){std::string operation;
    while(std::cin>>operation){
        n::Config config;auto& s=config.state;auto& c=s.counter;std::uint32_t hooks{},slot_kind{},external{},mask{},fact_mask{},remove{};
        n::Words prior;n::Scratch scratch;auto script=std::make_shared<Script>();std::array<std::uint32_t,4> facts{};
        if(!(std::cin>>c.actual>>c.requested>>c.pause>>c.buffering_pause>>c.property_47>>c.active_counter>>c.increment>>c.elapsed_counter>>c.elapsed_origin>>c.external_accumulator
             >>s.selector>>s.pending>>s.cached.numerator>>s.cached.denominator>>s.previous_sample>>s.external_denominator>>config.frequency>>hooks>>config.guard_depth>>config.guard_tag>>slot_kind>>external
             >>prior.numerator>>prior.denominator>>scratch.refresh.numerator>>scratch.refresh.denominator>>scratch.external.numerator>>scratch.external.denominator
             >>mask>>script->reply.words.numerator>>script->reply.words.denominator>>script->reply.status>>fact_mask>>facts[0]>>facts[1]>>facts[2]>>facts[3]>>remove))return 2;
        script->reply.numerator=mask&1;script->reply.denominator=mask&2;script->reply.remove_selected_slot=remove;
        if(fact_mask&1)script->reply.facts.actual=facts[0];
        if(fact_mask&2)script->reply.facts.pause=facts[1];
        if(fact_mask&4)script->reply.facts.buffering_pause=facts[2];
        if(fact_mask&8)script->reply.facts.property_47=facts[3];
        auto probe=std::make_shared<Probe>();auto hook=std::make_shared<Hooks>();config.probe=probe;if(hooks)config.guard=hook;n::Clock clock(config);
        if(slot_kind && clock.set_callback(s.selector,slot_kind==1?script:nullptr)!=n::Status::completed)return 3;
        if(external && clock.set_external(script)!=n::Status::completed)return 4;
        n::Operation op;
        if(operation=="selected")op=n::Operation::selected;else if(operation=="cached")op=n::Operation::cached;
        else if(operation=="external")op=n::Operation::external;else if(operation=="refresh")op=n::Operation::refresh;else if(operation=="tick")op=n::Operation::tick;else return 5;
        const auto result=clock.execute(op,prior,scratch);if(result.status!=n::Status::completed || probe->overflow)return 6;
        unsigned enters=0,leaves=0,queries=0;
        for(unsigned k=0;k<probe->count;++k){const auto kind=probe->records[k].event;enters+=kind==n::Event::hook_enter;leaves+=kind==n::Event::hook_leave;queries+=kind==n::Event::query;}
        if(!hook->valid || hook->enters!=enters || hook->leaves!=leaves || script->calls!=queries)return 8;
        std::cout<<"row";print(clock.snapshot());std::cout<<' '<<result.words.numerator<<' '<<result.words.denominator<<' '<<result.query_status_defined<<' '<<result.query_status<<' '<<probe->count;
        for(unsigned k=0;k<probe->count;++k){const auto& record=probe->records[k];std::cout<<' '<<unsigned(record.event)<<' '<<record.prior.numerator<<' '<<record.prior.denominator;print(record.snapshot);}
        std::cout<<'\n';
    }
    return std::cin.eof()?0:7;
}
