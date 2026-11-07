#include "projection.hpp"
#include <array>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
namespace n=reo::native::movie_timing_context;
constexpr std::uint32_t n::Facts::* facts[]{&n::Facts::actual,&n::Facts::requested,&n::Facts::pause,&n::Facts::depth,&n::Facts::pending,&n::Facts::buffering,&n::Facts::episodes,&n::Facts::rate,&n::Facts::property_e,&n::Facts::selector,&n::Facts::property_47,&n::Facts::tolerance,&n::Facts::admit_slack,&n::Facts::requested_slack};
constexpr std::optional<std::uint32_t> n::Updates::* updates[]{&n::Updates::actual,&n::Updates::requested,&n::Updates::pause,&n::Updates::depth,&n::Updates::pending,&n::Updates::buffering,&n::Updates::episodes,&n::Updates::rate,&n::Updates::property_e,&n::Updates::selector,&n::Updates::property_47,&n::Updates::tolerance,&n::Updates::admit_slack,&n::Updates::requested_slack};
void print(const n::View& view){for(auto word:n::testing::project(view))std::cout<<' '<<word;}
struct Event {unsigned kind{},nesting{};std::array<std::uint32_t,4> arguments{};n::View view;bool nested{};n::Words words;std::uint32_t returned{};};
struct Data {
    std::weak_ptr<n::Context> owner;std::vector<Event> events;
    n::Words sample,nested_words{0x5A5A5A5Au,0x5A5A5A5Au};std::uint64_t counter{},frequency{};
    std::uint32_t status{},predicate{},command_status{},error_status{},nesting{};bool nested_query{};n::Updates command_updates;
    void event(unsigned kind,std::array<std::uint32_t,4> arguments={})noexcept{events.push_back({kind,nesting,arguments,owner.lock()->snapshot(),false,{},0});}
};
struct Audio final:n::audio::AudioSource {
    Data& data;explicit Audio(Data& value):data(value){}
    n::audio::ProviderStatus status(std::uint8_t& value)noexcept override{value=static_cast<std::uint8_t>(data.status);return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus estimate(n::Words& value)noexcept override{data.event(0);value=data.sample;return n::audio::ProviderStatus::completed;}
};
struct Helper final:n::audio::HelperClock {
    Data& data;explicit Helper(Data& value):data(value){}
    n::audio::ProviderStatus counter(std::uint64_t& value)noexcept override{data.event(1);value=data.counter;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus frequency(std::uint64_t& value)noexcept override{value=data.frequency;return n::audio::ProviderStatus::completed;}
};
struct Hooks final:n::selected::GuardHooks {
    Data& data;explicit Hooks(Data& value):data(value){}
    void enter(std::uint32_t value)noexcept override{data.event(6,{0,0,value,0});}
    void leave(std::uint32_t value)noexcept override{data.event(7,{0,0,value,0});}
};
struct Ports final:n::Ports {
    Data& data;explicit Ports(Data& value):data(value){}
    n::Reply call(n::pause::Call call,const n::View&)noexcept override{
        const auto kind=call.kind==n::pause::Kind::command?2u:call.kind==n::pause::Kind::pause_predicate?3u:call.kind==n::pause::Kind::resume_predicate?4u:5u;
        const auto index=data.events.size();data.event(kind,kind==2 || kind==5?std::array<std::uint32_t,4>{call.target,call.command,call.argument,call.extra}:std::array<std::uint32_t,4>{});
        n::Reply reply;
        if(kind==2){
            if(data.nested_query){++data.nesting;n::Input input;input.prior=data.nested_words;const auto value=data.owner.lock()->execute(n::Operation::selected,input);--data.nesting;
                if(value.words_written)data.nested_words=value.words;
                data.events[index].nested=true;data.events[index].words=data.nested_words;data.events[index].returned=value.returned;
            }
            reply.status=data.command_status;reply.updates=data.command_updates;
        }else reply.status=kind==5?data.error_status:data.predicate;
        return reply;
    }
};
bool read_updates(n::Updates& value){
    value={};std::uint32_t mask{};if(!(std::cin>>mask))return false;
    for(unsigned n=0;n<14;++n){std::uint32_t word{};if(!(std::cin>>word))return false;if(mask&(1u<<n))value.*updates[n]=word;}
    return true;
}
#ifndef REO_TIMING_FIXTURE_SUPPORT_ONLY
int main(){
    Data data;data.events.reserve(64);std::shared_ptr<n::Context> owner;unsigned identity{},index{};std::string command;
    n::Words caller{0x5A5A5A5Au,0x5A5A5A5Au};std::uint32_t decision=0x5A5A5A5Au;
    const auto row=[&](int operation,const n::Result& result){
        std::cout<<"row "<<identity<<' '<<operation;print(owner->snapshot());
        std::cout<<' '<<caller.numerator<<' '<<caller.denominator<<' '<<decision<<' '<<result.return_defined<<' '<<result.returned<<' '<<unsigned(result.status)<<' '<<data.events.size();
        for(const auto& event:data.events){std::cout<<' '<<event.kind<<' '<<event.nesting;for(auto value:event.arguments)std::cout<<' '<<value;print(event.view);std::cout<<' '<<event.nested;if(event.nested)std::cout<<' '<<event.words.numerator<<' '<<event.words.denominator<<' '<<event.returned;}
        std::cout<<'\n';
    };
    while(std::cin>>command){
        if(command=="begin"){
            n::Config config;std::uint32_t hooks{};auto guard=std::make_shared<n::selected::GuardState>();
            if(!(std::cin>>identity))return 2;
            for(auto field:facts)if(!(std::cin>>config.facts.*field))return 3;
            if(!(std::cin>>config.frequency>>hooks>>guard->depth>>guard->tag))return 4;
            config.guard=guard;config.audio=std::make_shared<Audio>(data);config.helper=std::make_shared<Helper>(data);config.ports=std::make_shared<Ports>(data);if(hooks)config.hooks=std::make_shared<Hooks>(data);
            owner=n::Context::create(std::move(config));data.owner=owner;data.events.clear();data.nesting=0;data.nested_words={0x5A5A5A5Au,0x5A5A5A5Au};caller={0x5A5A5A5Au,0x5A5A5A5Au};decision=0x5A5A5A5Au;index=0;
            n::Result result;result.status=n::Status::completed;row(-1,result);continue;
        }
        constexpr std::pair<const char*,n::Operation> operations[]{{"selected",n::Operation::selected},{"cached",n::Operation::cached},{"refresh",n::Operation::refresh},{"tick",n::Operation::tick},{"pause",n::Operation::pause},{"buffer",n::Operation::buffer},{"admit",n::Operation::admit},{"requested_admit",n::Operation::requested_admit},{"picture_request",n::Operation::picture_request}};
        std::optional<n::Operation> operation;for(const auto& value:operations)if(command==value.first)operation=value.second;if(!operation)return 5;
        n::Input input;input.prior=caller;std::uint32_t nested{};
        if(!(std::cin>>input.value>>input.query.numerator>>input.query.denominator>>data.sample.numerator>>data.sample.denominator>>data.counter>>data.frequency>>data.status>>data.predicate>>nested>>data.command_status>>data.error_status))return 6;
        data.nested_query=nested!=0;n::Updates observed;if(!read_updates(observed) || !read_updates(data.command_updates))return 7;
        if(owner->observe(observed)!=n::Status::completed)return 8;
        data.events.clear();const auto result=owner->execute(*operation,input);
        if(result.words_written)caller=result.words;
        if(result.decision_written)decision=result.decision;
        row(static_cast<int>(index++),result);
    }
    return std::cin.eof()?0:9;
}
#endif
