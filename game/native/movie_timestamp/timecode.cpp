#include "timecode.hpp"
#include <bit>
#include <cmath>
namespace reo::native::movie_timestamp {
namespace {
constexpr std::array<std::uint32_t,9> Rates{1,23976,24000,25000,29970,30000,50000,59940,60000};
constexpr std::array<std::uint32_t,9> Nominal{0,24,24,25,30,30,50,60,60};
std::int32_t s(std::uint32_t v)noexcept{return std::bit_cast<std::int32_t>(v);}
std::uint32_t quotient(std::uint32_t a,std::uint32_t b)noexcept{return static_cast<std::uint32_t>(s(a)/s(b));}
std::uint32_t remainder(std::uint32_t a,std::uint32_t b)noexcept{return static_cast<std::uint32_t>(s(a)%s(b));}
Record pack(const Picture& p)noexcept{return{1,p.rate,p.drop,p.hours,p.minutes,p.seconds,p.frames,p.reference,0,Rates[p.rate]};}
std::uint32_t value(const Record& r)noexcept {
    const auto nominal=Nominal[r.rate],rate=Rates[r.rate];
    if(r.drop && (r.rate==1 || r.rate==4 || r.rate==7)){
        // Original dispatch literals, including the unusual 59.94-hour/minute
        // coefficients and literal two-frame decade correction.
        const auto hour=r.rate==1?86292u:r.rate==4?107892u:215892u;
        const auto minute=r.rate==1?1438u:r.rate==4?1798u:3598u;
        return (r.hours*hour+r.minutes*minute+r.seconds*nominal+2u*quotient(r.minutes,10)+r.frames+r.reference)*1000u;
    }
    const auto effective=(r.rate==1 || r.rate==4 || r.rate==7)?nominal*1000u:rate;
    return r.hours*3600u*effective+r.minutes*60u*effective+r.seconds*effective+(r.frames+r.reference)*1000u;
}
void reconstruct(Picture& p,std::uint32_t stamp)noexcept {
    // The original finite helper converts through software double, adds 0.5,
    // floors, then converts to int32. Admitted nonnegative stamps/rates stay
    // finite and within int32 here; each integer product is exact in binary64.
    const auto rounded=static_cast<std::uint32_t>(std::floor((double(s(stamp))*double(Rates[p.rate]))/22500000.0+0.5));
    auto count=rounded-p.reference;if(s(count)<0)count=0;
    if(p.drop && (p.rate==4 || p.rate==7)){
        constexpr std::array<std::uint32_t,8> thirty{107891,17981,1800,1798,28,30,10,2};
        constexpr std::array<std::uint32_t,8> sixty{215783,35963,3600,3596,56,60,10,4};
        const auto& table=p.rate==4?thirty:sixty;
        p.hours=count/table[0];auto rest=count%table[0];const auto block=rest/table[1];rest%=table[1];std::uint32_t minute{};
        if(rest<table[2]){p.seconds=rest/table[5];p.frames=rest%table[5];}
        else{rest-=table[2];minute=rest/table[3]+1;rest%=table[3];if(rest<table[4]){p.seconds=0;p.frames=rest+table[7];}else{rest-=table[4];p.seconds=rest/table[5]+1;p.frames=rest%table[5];}}
        p.minutes=block*table[6]+minute;
    }else{const auto fps=Nominal[p.rate];p.frames=count%fps;count/=fps;p.seconds=count%60;count/=60;p.minutes=count%60;p.hours=count/60;}
}
void advance(Picture& p,const Record& cached)noexcept {
    const auto frames=cached.frames+cached.reference+1u;
    const auto seconds=cached.seconds+quotient(frames,Nominal[p.rate]);p.frames=remainder(frames,Nominal[p.rate]);
    const auto minutes=cached.minutes+quotient(seconds,60);p.seconds=remainder(seconds,60);p.minutes=remainder(minutes,60);p.hours=cached.hours+quotient(minutes,60);
    if(p.drop && !p.seconds && remainder(p.minutes,10)!=0 && s(p.frames)<2)p.frames=2;
}
void copy_components(Picture& p,const Record& cached)noexcept{p.hours=cached.hours;p.minutes=cached.minutes;p.seconds=cached.seconds;p.frames=cached.frames;}
}
Publication publish(FlowState& state,const FlowInput& input)noexcept {
    Publication out;out.picture=input.picture;auto& p=out.picture;
    if(p.rate<1 || p.rate>=Rates.size() || p.drop>1)return out;
    if(input.accounting){const auto r=reconcile(state.temporal,{p.rate,p.reference,p.kind,input.changed,*input.accounting});if(!r.admitted)return out;out.stamp=r.value;}
    if(!state.mode){
        bool enable=s(out.stamp)>=0 || !p.gop;
        if(!enable && input.changed && state.latest.valid){const auto fresh=pack(p);const auto now=value(fresh),old=value(state.latest);enable=s(old)>=s(now) || s(now)>=s(old+state.jump_tolerance*state.latest.scale);}
        if(enable)state.mode=1;
    }
    if(state.mode==1){
        if(input.changed && s(out.stamp)>=0)reconstruct(p,out.stamp);
        else if(!state.latest.valid){p.drop=0;p.hours=p.minutes=p.seconds=p.frames=0;}
        else if(input.changed)advance(p,state.latest);
        else{copy_components(p,state.latest);p.reference+=static_cast<std::uint32_t>(s(state.latest.reference-p.reference+0x337u)/1024)*1024u;}
    }
    if(!state.first.valid){state.first=pack(p);state.first.reference=0;state.first.value=value(state.first);}
    state.current=pack(p);state.current.value=value(state.current)-state.first.value;
    if(s(state.current.value)>=s(state.latest.value))state.latest=state.current;
    out.value=state.current.value;out.scale=state.current.scale;out.admitted=true;return out;
}
}
