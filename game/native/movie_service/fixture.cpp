#include "service.hpp"
#include <iostream>
#include <vector>
namespace n=reo::native::movie_service;
void read(n::State& s){std::cin>>s.actual>>s.requested>>s.pending>>s.buffered>>s.threshold;for(auto& v:s.properties)std::cin>>v;for(auto& v:s.cached)std::cin>>v;for(auto& v:s.shared)std::cin>>v;}
void emit(const n::State& s){for(auto v:{s.actual,s.requested,s.pending,s.buffered,s.threshold})std::cout<<' '<<v;for(auto v:s.properties)std::cout<<' '<<v;for(auto v:s.cached)std::cout<<' '<<v;for(auto v:s.shared)std::cout<<' '<<v;}
bool patch(n::State& s,unsigned at,std::uint32_t value){switch(at){case 0:s.actual=value;return true;case 1:s.requested=value;return true;case 2:s.pending=value;return true;case 3:s.buffered=value;return true;case 4:s.threshold=value;return true;default:break;}if(at<105){s.properties[at-5]=value;return true;}if(at<109){s.cached[at-105]=value;return true;}if(at<111){s.shared[at-109]=value;return true;}return false;}
struct Event {n::Action kind;std::uint64_t argument,result;n::State before,after;};
struct Ports final:n::Ports {
    std::vector<Event> events;unsigned index{};bool mismatch{};
    std::uint64_t call(n::Action kind,std::uint64_t argument,n::State& state)noexcept override{
        if(index>=events.size()){mismatch=true;return 0;}
        const auto& expected=events[index++];
        std::cout<<"event "<<unsigned(kind)<<' '<<argument;emit(state);std::cout<<'\n';
        if(kind!=expected.kind || argument!=expected.argument)mismatch=true;
        state=expected.after;return expected.result;
    }
};
int main(){unsigned identity{},operations{};while(std::cin>>identity>>operations){n::State state;read(state);
    for(unsigned op=0;op<operations;++op){unsigned patches{};std::cin>>patches;for(unsigned i=0;i<patches;++i){unsigned at{};std::uint32_t value{};std::cin>>at>>value;if(!patch(state,at,value))return 4;}unsigned count{};std::cin>>count;Ports ports;
        for(unsigned i=0;i<count;++i){unsigned kind{};Event e;std::cin>>kind>>e.argument>>e.result;e.kind=static_cast<n::Action>(kind);read(e.before);read(e.after);ports.events.push_back(e);}
        std::cout<<"begin "<<identity<<' '<<op;emit(state);std::cout<<'\n';n::service(state,ports);
        std::cout<<"end "<<identity<<' '<<op;emit(state);std::cout<<'\n';
        if(ports.mismatch || ports.index!=ports.events.size())return 3;
    }
}return std::cin.eof()?0:2;}
