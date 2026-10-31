// SPDX-License-Identifier: GPL-3.0-only
#include "../../network/native/native_netcode.h"
#include "../../network/native/game_netcode.h"
#include <cmath>
#include <cstdio>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <random>
using namespace reo_network::native;
namespace {
unsigned checks=0;
void check(bool b,const char* why) { ++checks; if(!b) throw std::runtime_error(why); }
std::vector<uint8_t> snap(uint8_t cmd,uint32_t sid) {
    return {0x80,0x10,0,cmd,uint8_t(sid>>24),uint8_t(sid>>16),uint8_t(sid>>8),uint8_t(sid),
            0,0,0,1,0,0,0,0,0xba,0x47,0x66,0x11};
}
void consume(Channel& c,const std::vector<uint8_t>& p,uint64_t now) { check(c.consume(p.data(),p.size(),now),"extension consumed"); }
std::vector<uint8_t> status(uint8_t mode,uint32_t epoch=7,uint32_t seq=1) {
    return encode(2,42,5,epoch,seq,1000000,
        {0,0,0,0,0,0,0,9,0,0,0,3,0,0,0,mode,0,0,0,42,0,0,0,43,0,0,0,0,0,0,0,0});
}
void impairments() {
    struct Arrival { uint64_t at,sent; uint32_t sequence; Motion motion; };
    for(const auto profile:std::array<std::array<int,2>,4>{{{50,1},{100,3},{150,5},{200,5}}}) {
        State state;
        Status st{42,5,7,3,Mode::Enhanced,{42,43,44,45},1000000000}; state.status(st);
        Motion self{0,10,0,{0,0,0}}; state.local(&self,1000000000);
        std::mt19937 rng(27813); std::uniform_int_distribution<int> jitter(-15000,15000),chance(0,9999);
        std::vector<Arrival> arrivals;
        for(uint32_t tick=1;tick<=1200;++tick) for(uint8_t slot=1;slot<4;++slot) {
            if(chance(rng)<profile[1]*100) continue;
            Motion m{slot,10,0,{float(tick*5),0,float(slot*10)}};
            const uint64_t delay=uint64_t(profile[0]*500+jitter(rng));
            arrivals.push_back({1000000000+uint64_t(tick)*50000+delay,1000000+uint64_t(tick)*50000,tick,m});
            if(chance(rng)<500) { auto duplicate=arrivals.back(); duplicate.at+=30000; arrivals.push_back(duplicate); }
        }
        std::stable_sort(arrivals.begin(),arrivals.end(),[](const auto& a,const auto& b){return a.at<b.at;});
        size_t cursor=0; std::vector<double> lag; unsigned missing=0;
        for(uint64_t elapsed=200000;elapsed<60000000;elapsed+=33333) {
            const uint64_t now=1000000000+elapsed;
            while(cursor<arrivals.size() && arrivals[cursor].at<=now) {
                const auto& a=arrivals[cursor++]; state.receive(42+a.motion.slot,a.sequence,a.sent,a.at,a.motion);
            }
            if(now-st.received>=500000) { st.received=now; state.status(st); }
            for(uint8_t slot=1;slot<4;++slot) {
                Motion target;
                if(state.target(slot,10,now,target)) {
                    const double age=(double(elapsed)*.0001-target.xyz[0])*10;
                    check(age>=-0.1,"interpolation never predicts a future location");
                    lag.push_back(age);
                } else ++missing;
            }
        }
        std::sort(lag.begin(),lag.end());
        check(!lag.empty(),"impairment scenario delivered snapshots");
        const double p95=lag[lag.size()*95/100];
        check(p95<profile[0]/2.0+200,"bounded p95 motion age under simulated Internet impairment");
        check(missing<30,"loss does not strand the motion stream");
        std::printf("impairment RTT=%dms jitter=+-15ms loss=%d%% duplicate=5%% p95_age=%.1fms missing=%u\n",profile[0],profile[1],p95,missing);
    }
}
}
int main() {
try {
    State s; Channel c(s,9);
    const auto golden=encode(1,0x01020304,0,0,1,1000000,std::vector<uint8_t>(16));
    check(golden.size()==48 && golden[0]=='R' && golden[6]==0 && golden[7]==16 && golden[8]==1 && golden[11]==4 && golden[29]==15 && golden[30]==66 && golden[31]==64,"big-endian protocol golden vector");
    check(c.poll(1000000).empty(),"no unauthenticated probe");
    auto login=snap(1,0x107d0); c.observeSend(login.data(),login.size(),1000000);
    check(c.poll(1000000).empty(),"placeholder request SID cannot authorize native traffic");
    const auto accepted=snap(0x29,42); c.observeReceive(accepted.data(),accepted.size(),1000000);
    check(c.session()==42,"native negotiation binds canonical SID from game login result");
    check(c.poll(1000000).size()==1,"probe starts after real KICS login");
    check(c.poll(1200000).empty(),"probe bounded cadence");
    c.poll(1500000); c.poll(2000000);
    check(c.poll(2500000).empty(),"old server fallback stops after three probes");
    consume(c,status(1),1100000);
    check(!s.enhanced(1100000),"lobby agreement never enables gameplay");
    auto hello=c.poll(3000000);
    check(hello.size()==1 && hello[0][47]==7,"acknowledges exact room epoch");
    consume(c,status(2,7,2),3100000);
    check(s.enhanced(3100000),"all-native room enabled");
    consume(c,status(0,7,1),3200000);
    check(s.enhanced(3200000),"reordered status cannot change mode");
    Motion local{0,10,0,{0,0,0}}; s.local(&local,3200000);
    auto motion=c.poll(3200000);
    check(motion.size()==1 && motion[0][5]==3,"motion uses independent latest-wins lane");
    check(c.poll(3250001).size()==1,"motion sends at 20 Hz");
    check(c.poll(3350000).empty(),"stalled guest does not resend frozen actor forever");
    Motion remote{1,10,100,{0,0,0}};
    check(s.receive(43,10,1000000,4000000,remote),"authorized motion accepted across different clock origins");
    check(!s.receive(99,11,1050000,4050000,remote),"non-member rejected");
    check(!s.receive(42,11,1050000,4050000,remote),"local authority protected");
    check(!s.receive(43,9,950000,4050000,remote),"out-of-order stale snapshot dropped");
    check(!s.receive(43,10,1000000,4050000,remote),"duplicate snapshot dropped");
    remote.xyz[0]=10;
    check(s.receive(43,11,1100000,4100000,remote),"next snapshot accepted");
    Motion target;
    check(s.target(1,10,4100000,target) && std::abs(target.xyz[0]-5)<0.001,"50 ms interpolation uses source timeline");
    check(!s.target(1,11,4100000,target),"room isolation");
    check(!s.target(1,10,4400001,target),"stale stream returns to original correction");
    remote.xyz[0]=std::numeric_limits<float>::quiet_NaN();
    check(!s.receive(43,12,1200000,4200000,remote),"NaN rejected");
    consume(c,status(2,8,3),4500000);
    check(!s.target(1,10,4500000,target),"new scenario epoch clears old samples");
    check(!s.enhanced(7000001),"server silence falls back");
    check(!c.consume(login.data(),login.size(),4500000),"original SN@P payload passes through");
    std::vector<uint8_t> voice(585); voice[0]='R';voice[1]='E';voice[2]='O';voice[3]='2';
    voice[581]=0xba;voice[582]=0x47;voice[583]=0x66;voice[584]=0x11;
    check(!c.consume(voice.data(),voice.size(),4500000),"valid original header coinciding with native magic is preserved");
    for(size_t n=4;n<64;++n) {
        auto malformed=status(2); malformed.resize(n);
        check(c.consume(malformed.data(),malformed.size(),4500000),"truncated extension is isolated from guest decoder");
    }
    std::vector<uint8_t> ram(32*1024*1024);
    {
        std::vector<uint8_t> records(96*2);
        records[0]=0; records[96]=1;
        records[0x22]=10; records[96+0x22]=11;
        records[0x1c]=100; records[0x1e]=100;
        WorldDigest a,b;
        check(worldDigestRecords(records.data(),records.size(),10,0,a) && a.count==1,"digest scopes initialized records to current room");
        records[1]=42; records[0x10]=99;
        check(worldDigestRecords(records.data(),records.size(),10,0,b) && a.hash==b.hash,"local renderer slot and movement excluded from world digest");
        records[0x1c]=90;
        check(worldDigestRecords(records.data(),records.size(),10,0,b) && a.hash!=b.hash,"persistent HP divergence changes checksum");
        records[96]=0;
        check(!worldDigestRecords(records.data(),records.size(),10,0,b),"uninitialized record identity rejected");
        check(!worldDigestRecords(records.data(),records.size()-1,10,0,b),"partial record rejected");
    }
    {
        const auto now=nowUs();
        auto& state=runtime(); state.reset();
        state.status({42,5,7,15,Mode::Enhanced,{42,43,0,0},now});
        Motion own{0,10,0,{0,0,0}}; state.local(&own,now);
        WorldDigest ownDigest{10,1,123,2}, authoritative{10,1,124,2};
        state.worldLocal(&ownDigest,now);
        state.worldReceive(43,1,authoritative,now);
        state.worldReceive(43,2,authoritative,now);
        uint16_t room; uint8_t owner;
        check(!state.worldOutgoingRequest(room,owner),"transient world divergence does not immediately request repair");
        state.worldReceive(43,3,authoritative,now);
        check(state.worldOutgoingRequest(room,owner) && room==10 && owner==1,"persistent divergence requests actual room authority");
        state.worldReceive(43,3,authoritative,now);
        check(!state.worldOutgoingRequest(room,owner),"duplicate world digest cannot retrigger repair");
        ownDigest.authoritySlot=0; state.worldLocal(&ownDigest,now);
        state.worldIncomingRequest(99,10,0,now);
        check(!state.worldPendingRequest(room,owner),"non-member cannot request original game execution");
        state.worldIncomingRequest(43,10,0,now);
        check(state.worldPendingRequest(room,owner) && owner==0,"authenticated request passed to guest owner");
        const uint32_t record=0x100000; ram[record]=8; ram[record+1]=6;
        check(eventReliability(ram.data(),File1,8,record,2)==4,"known enemy HP event uses original reliable queue");
        ram[record]=0x2a;
        check(eventReliability(ram.data(),File1,8,record,2)==2,"large kinematic variants keep original lane");
        check(eventReliability(ram.data(),File1,5,record,3)==4,"world item and door events use original reliable queue");
        ram[record]=0x54;
        check(eventReliability(ram.data(),File1,8,record,3)==4 && eventReliability(ram.data(),File2,8,record,3)==3,"edition-specific death subtype coverage");
        check(eventReliability(ram.data(),File1,1,record,3)==3,"original player coalescing untouched");
        state.reset();
        check(eventReliability(ram.data(),File1,5,record,3)==3,"legacy event routing unchanged");
    }
    for(const auto& layout:{File1,File2}) {
        write<uint32_t>(ram.data(),layout.interval,0x3f000000);
        cadence(ram.data(),layout,true);
        check(read<uint32_t>(ram.data(),layout.interval)==0x3dcccccd,"negotiated 100 ms batch interval");
        cadence(ram.data(),layout,false);
        check(read<uint32_t>(ram.data(),layout.interval)==0x3f000000,"legacy interval restored");
        write<uint32_t>(ram.data(),layout.interval,0x3e800000);
        cadence(ram.data(),layout,true);
        check(read<uint32_t>(ram.data(),layout.interval)==0x3e800000,"server nondefault tuning retained");
    }
    c.reset(); check(c.poll(9000000).empty() && !s.enhanced(9000000),"socket reset removes native state");
    impairments();
    std::printf("PASS native_netcode checks=%u\n",checks); return 0;
} catch(const std::exception& e) { std::fprintf(stderr,"FAIL %u: %s\n",checks,e.what()); return 1; }
}
