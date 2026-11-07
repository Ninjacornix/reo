#include "timecode.hpp"
#include <iostream>
namespace n=reo::native::movie_timestamp;
void emit_record(const n::Record& r){for(auto v:{r.valid,r.rate,r.drop,r.hours,r.minutes,r.seconds,r.frames,r.reference,r.value,r.scale})std::cout<<' '<<v;}
void emit(const n::FlowState& s,const n::Picture& p){const auto& t=s.temporal;for(auto v:{t.baseline,t.origin,t.base,t.maximum,t.cached.value,t.cached.begin,t.cached.bytes,s.mode})std::cout<<' '<<v;emit_record(s.first);emit_record(s.latest);emit_record(s.current);std::cout<<" 0 0 0 0";for(auto v:{p.rate,p.reference,p.kind,p.drop,p.hours,p.minutes,p.seconds,p.frames,p.gop})std::cout<<' '<<v;std::cout<<" 0 0 0";}
int main(){unsigned identity{},operations{};while(std::cin>>identity){n::FlowState state;auto& t=state.temporal;std::cin>>t.baseline>>t.origin>>t.base>>t.maximum>>t.cached.value>>t.cached.begin>>t.cached.bytes>>operations;
    std::cout<<"row "<<identity<<" -1 4294967295";emit(state,{});std::cout<<'\n';
    for(unsigned i=0;i<operations;++i){n::FlowInput in;bool stamp{};std::uint32_t value{},begin{},bytes{};auto& p=in.picture;std::cin>>p.rate>>p.reference>>p.kind>>p.drop>>p.hours>>p.minutes>>p.seconds>>p.frames>>p.gop>>in.changed>>stamp>>value>>begin>>bytes;
        if(stamp)in.accounting=n::Stamp{value,begin,bytes};
        const auto out=n::publish(state,in);if(!out.admitted)return 2;std::cout<<"row "<<identity<<' '<<i<<' '<<out.stamp;emit(state,out.picture);std::cout<<'\n';}
}return std::cin.eof()?0:1;}
