#include "controller.hpp"
#include <array>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
namespace n=reo::native::movie_pause;
constexpr std::pair<const char*,std::uint32_t n::State::*> fields[]{
    {"actual",&n::State::actual},{"requested",&n::State::requested},{"pause",&n::State::pause},{"depth",&n::State::depth},{"pending",&n::State::pending},{"buffering",&n::State::buffering},{"episodes",&n::State::episodes},{"rate",&n::State::rate},
    {"active_counter",&n::State::active_counter},{"elapsed_counter",&n::State::elapsed_counter},{"external_accumulator",&n::State::external_accumulator},{"external_denominator",&n::State::external_denominator}};
constexpr std::optional<std::uint32_t> n::Updates::* updates[]{
    &n::Updates::actual,&n::Updates::requested,&n::Updates::pause,&n::Updates::depth,&n::Updates::pending,&n::Updates::buffering,&n::Updates::episodes,&n::Updates::rate,
    &n::Updates::active_counter,&n::Updates::elapsed_counter,&n::Updates::external_accumulator,&n::Updates::external_denominator};
void print(n::View view){
    for(const auto& item:fields)std::cout<<' '<<view.state.*item.second;
    std::cout<<' '<<view.state.validation_seen<<' '<<view.guard.depth<<' '<<view.guard.tag;
}
struct Event {unsigned kind{};std::uint32_t target{},command{},argument{},extra{};n::View view;};
struct Data {std::array<n::Reply,4> replies;std::vector<Event> events;n::Controller* owner{};};
struct Ports final:n::Ports {
    Data& data;explicit Ports(Data& value):data(value){}
    n::Reply call(n::Call call,n::View view)noexcept override{
        data.events.push_back({unsigned(call.kind),call.target,call.command,call.argument,call.extra,view});return data.replies[unsigned(call.kind)];
    }
};
struct Hooks final:reo::native::movie_selected_clock::GuardHooks {
    Data& data;explicit Hooks(Data& value):data(value){}
    void enter(std::uint32_t argument)noexcept override{data.events.push_back({4,0,0,argument,0,data.owner->snapshot().view});}
    void leave(std::uint32_t argument)noexcept override{data.events.push_back({5,0,0,argument,0,data.owner->snapshot().view});}
};
int main(){
    Data data;data.events.reserve(8);auto ports=std::make_shared<Ports>(data);auto hooks=std::make_shared<Hooks>(data);
    std::unique_ptr<n::Controller> owner;unsigned identity{},index{};std::string command;
    while(std::cin>>command){
        if(command=="begin"){
            n::Config config;std::uint32_t enabled{};
            if(!(std::cin>>identity))return 2;
            for(const auto& field:fields)if(!(std::cin>>config.state.*field.second))return 3;
            if(!(std::cin>>config.frequency>>enabled>>config.guard.depth>>config.guard.tag))return 4;
            config.ports=ports;if(enabled)config.hooks=hooks;
            owner=std::make_unique<n::Controller>(config);data.owner=owner.get();index=0;continue;
        }
        const auto operation=command=="pause"?n::Operation::pause:command=="nested"?n::Operation::nested:command=="forward"?n::Operation::forward:command=="buffer"?n::Operation::buffer:n::Operation::step;
        if(command!="pause" && command!="nested" && command!="forward" && command!="buffer" && command!="step")return 5;
        std::uint32_t argument{};if(!(std::cin>>argument))return 6;
        for(auto& reply:data.replies){
            reply={};std::uint32_t mask{};
            if(!(std::cin>>reply.status>>mask))return 7;
            for(unsigned field=0;field<12;++field){std::uint32_t value{};if(!(std::cin>>value))return 8;if(mask&(1u<<field))reply.updates.*updates[field]=value;}
        }
        data.events.clear();const auto result=owner->execute(operation,argument);
        std::cout<<"row "<<identity<<' '<<index++;print(owner->snapshot().view);
        std::cout<<' '<<unsigned(result.status)<<' '<<result.returned<<' '<<result.return_defined<<' '<<data.events.size();
        for(const auto& event:data.events){std::cout<<' '<<event.kind<<' '<<event.target<<' '<<event.command<<' '<<event.argument<<' '<<event.extra;print(event.view);}
        std::cout<<'\n';
    }
    return std::cin.eof()?0:9;
}
