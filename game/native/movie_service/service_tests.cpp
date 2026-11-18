#include "service.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>
namespace n=reo::native::movie_service;
void require(bool value){if(!value)throw std::runtime_error("Movie service contract");}
struct Ports final:n::Ports {
    std::vector<n::Action> events;
    unsigned mode{},counters{};std::uint64_t elapsed{};
    std::uint64_t call(n::Action action,std::uint64_t argument,n::State& state)noexcept override{
        events.push_back(action);
        if(action==n::Action::counter)return counters++?2:std::numeric_limits<std::uint64_t>::max()-2;
        if(action==n::Action::statistics)elapsed=argument;
        if(action==n::Action::extent)return 4096;
        if(mode==1 && action==n::Action::shared){state.actual=1;state.requested=6;state.pending=1;}
        if(mode==2 && action==n::Action::end_transition){state.actual=6;return 1;}
        if(action==n::Action::start)return 17; // Original handler ignores this status.
        return 0;
    }
};
int main(){try{
    n::State s;s.actual=1;s.requested=4;Ports p;n::service(s,p);require(p.events.empty());
    s.pending=1;n::service(s,p);require(s.actual==2 && !s.pending && p.elapsed==5 && p.events.size()==3);
    s.pending=1;p.mode=1;p.events.clear();n::service(s,p);require(s.actual==2 && s.pending==1 && p.events.size()==5);
    p.mode=0;s={};s.actual=2;s.requested=4;s.pending=1;s.properties[5]=1;s.properties[6]=1;s.cached={0,0,1,0};n::service(s,p);require(s.actual==2);
    s.pending=1;s.cached={0,1,1,0};s.properties[14]=1;s.properties[45]=1;n::service(s,p);require(s.actual==3);
    s.pending=1;s.cached[3]=1;n::service(s,p);require(s.actual==4);
    s.pending=1;p.mode=2;n::service(s,p);require(s.actual==6);
    const auto before=p.events.size();s.pending=1;n::service(s,p);require(p.events.size()==before && s.pending==1);
    std::cout<<"Movie service callback and transition checks passed\n";return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
