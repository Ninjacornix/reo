// SPDX-License-Identifier: GPL-3.0-only
#include "native_netcode.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstring>
#include <sstream>

namespace reo_network::native {
namespace {
uint16_t be16(const uint8_t* p) { return uint16_t(uint16_t(p[0]) << 8 | p[1]); }
uint32_t be32(const uint8_t* p) { return uint32_t(be16(p)) << 16 | be16(p + 2); }
uint64_t be64(const uint8_t* p) { return uint64_t(be32(p)) << 32 | be32(p + 4); }
void put16(std::vector<uint8_t>& b, size_t p, uint16_t v) { b[p] = uint8_t(v >> 8); b[p+1] = uint8_t(v); }
void put32(std::vector<uint8_t>& b, size_t p, uint32_t v) { put16(b,p,uint16_t(v>>16)); put16(b,p+2,uint16_t(v)); }
void put64(std::vector<uint8_t>& b, size_t p, uint64_t v) { put32(b,p,uint32_t(v>>32)); put32(b,p+4,uint32_t(v)); }
float beFloat(const uint8_t* p) { auto v = be32(p); float f; std::memcpy(&f,&v,4); return f; }
void putFloat(std::vector<uint8_t>& b,size_t p,float f) { uint32_t v; std::memcpy(&v,&f,4); put32(b,p,v); }
bool newer(uint32_t a, uint32_t b) { const auto d = a-b; return d && d < 0x80000000u; }
bool valid(const Motion& m) {
    return m.slot < 4 && std::all_of(m.xyz.begin(),m.xyz.end(),[](float v){ return std::isfinite(v) && std::abs(v) < 1e7f; });
}
bool snap(const uint8_t* b,size_t n) {
    return n >= 20 && (be32(b+n-4) == 0xba476611u || be32(b+n-4) == 0xba476610u);
}
bool completeSnap(const uint8_t* b,size_t n) {
    if(!snap(b,n)) return false;
    size_t offset=0;
    while(offset+16<=n-4) {
        const auto length=be16(b+offset)&0x3ffu;
        if(length<16 || offset+length>n-4) return false;
        offset+=length;
    }
    return offset==n-4;
}
double delay(double jitter) { return std::clamp(50000.0 + jitter*2,50000.0,150000.0); }
}
std::shared_ptr<State> sharedRuntime() {
    static auto value=std::make_shared<State>();
    return value;
}
State& runtime() { return *sharedRuntime(); }
uint64_t nowUs() { return uint64_t(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()); }
void State::reset() { std::lock_guard lock(mutex_); status_ = {}; validLocal_=false; tracks_={}; worldValid_=worldRequest_=false; worldPeers_={}; worldPending_.clear(); }
void State::status(const Status& value) {
    std::lock_guard lock(mutex_);
    if (status_.session != value.session || status_.room != value.room || status_.epoch != value.epoch || value.mode != Mode::Enhanced)
        { tracks_={}; worldValid_=worldRequest_=false; worldPeers_={}; worldPending_.clear(); }
    status_=value;
}
Status State::status() const { std::lock_guard lock(mutex_); return status_; }
bool State::enhanced(uint64_t now) const {
    const auto s=status();
    return s.mode == Mode::Enhanced && s.features & Batch && now >= s.received && now-s.received <= 2500000;
}
void State::local(const Motion* value,uint64_t now) {
    std::lock_guard lock(mutex_);
    if ((!value && validLocal_) || (value && valid(*value) &&
        (!validLocal_ || value->room!=local_.room || value->slot!=local_.slot))) {
        for(auto& track:tracks_) track.samples.clear();
    }
    validLocal_=value && valid(*value);
    if (validLocal_) { local_=*value; localAt_=now; }
}
bool State::local(Motion& value,uint64_t now) const { std::lock_guard lock(mutex_); value=local_; return validLocal_ && now>=localAt_ && now-localAt_<=100000; }
bool State::receive(uint32_t source,uint32_t sequence,uint64_t sent,uint64_t now,const Motion& value) {
    std::lock_guard lock(mutex_);
    if (!valid(value) || !sent || source == status_.session ||
        std::find(status_.members.begin(),status_.members.end(),source) == status_.members.end() || !source ||
        status_.mode != Mode::Enhanced || !(status_.features & MotionStream) ||
        now < status_.received || now-status_.received > 2500000 || (validLocal_ && value.slot==local_.slot)) return false;
    auto& t=tracks_[value.slot];
    if (t.source && t.source != source) return false;
    if (t.numbered && !newer(sequence,t.sequence)) return false;
    if (!t.samples.empty() && sent <= t.samples.back().sent) return false;
    if (!t.samples.empty()) {
        const auto& p=t.samples.back();
        const double spacing=double(now-p.arrived)-double(sent-p.sent);
        t.jitter+=(std::abs(spacing)-t.jitter)/16;
        // Reset interpolation at a door; never blend coordinates from different rooms.
        float distance=0;
        for(size_t i=0;i<3;++i) distance+=(p.motion.xyz[i]-value.xyz[i])*(p.motion.xyz[i]-value.xyz[i]);
        if (p.motion.room != value.room || now-p.arrived > 1000000 || distance>250000) t.samples.clear();
    }
    const double offset=double(now)-double(sent);
    t.offset=t.samples.empty() ? offset : std::min(offset,t.offset+100.0);
    t.source=source; t.sequence=sequence; t.numbered=true;
    t.samples.push_back({value,sent,now});
    while (t.samples.size()>32) t.samples.pop_front();
    return true;
}
bool State::target(uint8_t slot,uint16_t room,uint64_t now,Motion& value) const {
    std::lock_guard lock(mutex_);
    if (slot>=4 || status_.mode!=Mode::Enhanced || now<status_.received || now-status_.received>2500000) return false;
    const auto& t=tracks_[slot];
    if (t.samples.empty() || now<t.samples.back().arrived || now-t.samples.back().arrived>300000 || t.samples.back().motion.room!=room) return false;
    const double target=double(now)-t.offset-delay(t.jitter);
    const Sample* a=&t.samples.front();
    const Sample* b=a;
    for (const auto& s:t.samples) { b=&s; if (double(s.sent)>=target) break; a=&s; }
    value=b->motion;
    if (a!=b && a->motion.room==room && b->sent>a->sent) {
        const double alpha=std::clamp((target-double(a->sent))/double(b->sent-a->sent),0.0,1.0);
        for (size_t i=0;i<3;++i) value.xyz[i]=float(a->motion.xyz[i]+(b->motion.xyz[i]-a->motion.xyz[i])*alpha);
        const int delta=int16_t(uint16_t(b->motion.yaw-a->motion.yaw));
        value.yaw=uint16_t(int(a->motion.yaw)+int(std::lround(delta*alpha)));
    }
    return true;
}
double State::jitterMs() const { std::lock_guard lock(mutex_); double v=0; for (const auto& t:tracks_) v=std::max(v,t.jitter); return v/1000; }
double State::bufferMs() const { return delay(jitterMs()*1000)/1000; }
void State::promoted() { std::lock_guard lock(mutex_); ++promoted_; }
uint64_t State::promotedCount() const { std::lock_guard lock(mutex_); return promoted_; }
void State::worldLocal(const WorldDigest* value,uint64_t now) {
    std::lock_guard lock(mutex_);
    if (!value || !worldValid_ || value->room!=world_.room || value->authoritySlot!=world_.authoritySlot) {
        worldPeers_={}; worldRequest_=false;
    }
    worldValid_=value && value->room<128 && value->authoritySlot<4;
    if(worldValid_) { world_=*value; worldAt_=now; }
}
bool State::worldLocal(WorldDigest& value,uint64_t now) const {
    std::lock_guard lock(mutex_); value=world_;
    return worldValid_ && now>=worldAt_ && now-worldAt_<=2500000 && validLocal_ && local_.slot==world_.authoritySlot;
}
bool State::worldReceive(uint32_t source,uint32_t sequence,const WorldDigest& value,uint64_t now) {
    std::lock_guard lock(mutex_);
    if(!worldValid_ || !validLocal_ || !(status_.features&WorldChecks) || status_.mode!=Mode::Enhanced ||
        source==status_.session || !source || value.authoritySlot>=4 || value.authoritySlot==local_.slot ||
        value.room!=world_.room || value.authoritySlot!=world_.authoritySlot || now<worldAt_ || now-worldAt_>2500000 ||
        std::find(status_.members.begin(),status_.members.end(),source)==status_.members.end()) return false;
    auto& p=worldPeers_[value.authoritySlot];
    if(p.numbered && !newer(sequence,p.sequence)) return false;
    p.sequence=sequence; p.numbered=true;
    if(value.hash==world_.hash && value.count==world_.count) { p.differences=0; return true; }
    ++worldMismatches_;
    if(++p.differences>=3 && (!worldRequestAt_ || now-worldRequestAt_>=5000000)) {
        worldRequest_=true; worldRequestAt_=now; ++worldRequests_; p.differences=0;
    }
    return true;
}
bool State::worldOutgoingRequest(uint16_t& room,uint8_t& authority) {
    std::lock_guard lock(mutex_);
    if(!worldRequest_ || !worldValid_) return false;
    room=world_.room; authority=world_.authoritySlot; worldRequest_=false; return true;
}
void State::worldIncomingRequest(uint32_t source,uint16_t room,uint8_t authority,uint64_t now) {
    std::lock_guard lock(mutex_);
    if(!worldValid_ || !validLocal_ || room!=world_.room || authority!=world_.authoritySlot || authority!=local_.slot ||
        !source || source==status_.session || status_.mode!=Mode::Enhanced || !(status_.features&WorldChecks) ||
        now<worldAt_ || now-worldAt_>2500000 ||
        std::find(status_.members.begin(),status_.members.end(),source)==status_.members.end()) return;
    const auto request=std::make_pair(room,authority);
    if(worldPending_.size()<8 && std::find(worldPending_.begin(),worldPending_.end(),request)==worldPending_.end()) worldPending_.push_back(request);
}
bool State::worldPendingRequest(uint16_t& room,uint8_t& authority) {
    std::lock_guard lock(mutex_);
    if(worldPending_.empty()) return false;
    room=worldPending_.front().first; authority=worldPending_.front().second; worldPending_.pop_front(); return true;
}
void State::worldStats(const WorldStats& stats) { std::lock_guard lock(mutex_); worldStats_=stats; }
std::vector<uint8_t> encode(uint8_t kind,uint32_t sid,uint32_t room,uint32_t epoch,uint32_t sequence,uint64_t stamp,const std::vector<uint8_t>& body) {
    if (body.size()>MaxPacket-WireHeader) return {};
    std::vector<uint8_t> b(WireHeader+body.size());
    std::memcpy(b.data(),"REO2",4); b[4]=1; b[5]=kind;
    put16(b,6,uint16_t(body.size())); put32(b,8,sid); put32(b,12,room); put32(b,16,epoch); put32(b,20,sequence); put64(b,24,stamp);
    std::copy(body.begin(),body.end(),b.begin()+WireHeader); return b;
}
Channel::Channel(State& state,uint64_t nonce):state_(state),nonce_(nonce ? nonce : 1) {}
void Channel::reset() { session_=0; sequence_=0; statusSequence_=0; statusNumbered_=false; loginPending_=false; attempts_=0; helloAt_=motionAt_=worldAt_=0; pending_.clear(); state_.reset(); }
void Channel::observeSend(const uint8_t* b,size_t n,uint64_t now) {
    if (!snap(b,n)) return;
    // The original SDK sends a placeholder SID (e.g. 0x000107d0). The
    // authenticated canonical SID is in the server's KICS result, not this request.
    if (b[3]==1) { reset(); loginPending_=true; return; }
    if (!session_) return;
    if (b[3]==2) { reset(); return; }
    if (b[3]==6 && !(be16(b)&0x1000)) attempts_=0;
    if (be16(b)&0x8000) {
        auto [it,inserted]=pending_.try_emplace(be32(b+8),Pending{now,now,false});
        if (!inserted) { it->second.last=now; it->second.retried=true; ++retries_; }
        if (pending_.size()>128) pending_.erase(pending_.begin());
    }
}
void Channel::observeReceive(const uint8_t* b,size_t n,uint64_t now) {
    if(snap(b,n) && b[3]==0x29 && loginPending_ && be32(b+4)) {
        session_=be32(b+4); loginPending_=false; attempts_=0;
    }
    if (!snap(b,n) || !(be16(b)&0x4000)) return;
    const auto it=pending_.find(be32(b+12));
    if (it!=pending_.end()) {
        if (!it->second.retried && now>=it->second.first) rtt_=double(now-it->second.first)/1000;
        pending_.erase(it);
    }
}
bool Channel::consume(const uint8_t* b,size_t n,uint64_t now) {
    if (n<4 || std::memcmp(b,"REO2",4)) return false;
    if(completeSnap(b,n)) return false;
    if (n<WireHeader || n>MaxPacket || b[4]!=1 || be16(b+6)!=n-WireHeader || !session_) return true;
    const uint32_t sid=be32(b+8),room=be32(b+12),epoch=be32(b+16),seq=be32(b+20);
    if (b[5]==2 && n==64 && sid==session_ && be64(b+32)==nonce_ && be32(b+44)<=2) {
        if (statusNumbered_ && !newer(seq,statusSequence_)) { ++stale_; return true; }
        statusNumbered_=true; statusSequence_=seq;
        Status s{sid,room,epoch,be32(b+40),Mode(be32(b+44)),{},now};
        for (size_t i=0;i<4;++i) s.members[i]=be32(b+48+i*4);
        const uint64_t stamp=be64(b+24);
        if (now>=stamp && now-stamp<5000000) rtt_=double(now-stamp)/1000;
        state_.status(s);
    } else if (b[5]==3 && n==50) {
        const auto s=state_.status();
        if (room!=s.room || epoch!=s.epoch || b[33]) { ++stale_; return true; }
        Motion m; m.slot=b[32]; m.room=be16(b+34); m.yaw=be16(b+48);
        for (size_t i=0;i<3;++i) m.xyz[i]=beFloat(b+36+i*4);
        if (state_.receive(sid,seq,be64(b+24),now,m)) ++received_; else ++stale_;
    } else if ((b[5]==6 && n==48) || (b[5]==7 && n==36)) {
        const auto s=state_.status();
        if(room!=s.room || epoch!=s.epoch || !state_.enhanced(now) || b[35]) return true;
        if(b[5]==6) {
            WorldDigest d{be16(b+32),b[34],be64(b+36),be16(b+44)};
            if(!be16(b+46) && state_.worldReceive(sid,seq,d,now)) ++worldReceived_;
        } else state_.worldIncomingRequest(sid,be16(b+32),b[34],now);
    }
    return true;
}
std::vector<std::vector<uint8_t>> Channel::poll(uint64_t now) {
    std::vector<std::vector<uint8_t>> out;
    if (!session_) return out;
    const auto s=state_.status();
    const bool supported=statusNumbered_;
    if ((!helloAt_ || now-helloAt_>=500000) && (supported || attempts_<3)) {
        std::vector<uint8_t> body(16);
        put64(body,0,nonce_); put32(body,8,Batch|MotionStream|CriticalEvents|WorldChecks); put32(body,12,s.epoch);
        out.push_back(encode(1,session_,s.room,s.epoch,++sequence_,now,body));
        helloAt_=now; ++attempts_;
    }
    Motion m;
    if (state_.enhanced(now) && s.features&MotionStream && state_.local(m,now) && (!motionAt_ || now>=motionAt_)) {
        std::vector<uint8_t> body(18); body[0]=m.slot; put16(body,2,m.room);
        for (size_t i=0;i<3;++i) putFloat(body,4+i*4,m.xyz[i]);
        put16(body,16,m.yaw);
        out.push_back(encode(3,session_,s.room,s.epoch,++sequence_,now,body));
        // Preserve the phase when a 30 Hz guest polls a 20 Hz channel; restarting
        // the interval at each send would quantize the stream down to 15 Hz.
        motionAt_=motionAt_ && motionAt_+50000>now ? motionAt_+50000 : now+50000;
        ++sent_;
    }
    if(state_.enhanced(now) && s.features&WorldChecks) {
        WorldDigest d;
        if((!worldAt_ || now-worldAt_>=1000000) && state_.worldLocal(d,now)) {
            std::vector<uint8_t> body(16); put16(body,0,d.room); body[2]=d.authoritySlot;
            put64(body,4,d.hash); put16(body,12,d.count);
            out.push_back(encode(6,session_,s.room,s.epoch,++sequence_,now,body)); worldAt_=now; ++worldSent_;
        }
        uint16_t room; uint8_t authority;
        if(state_.worldOutgoingRequest(room,authority)) {
            std::vector<uint8_t> body(4); put16(body,0,room); body[2]=authority;
            out.push_back(encode(7,session_,s.room,s.epoch,++sequence_,now,body));
        }
    }
    return out;
}
std::string Channel::metrics(uint64_t now) const {
    double oldest=0;
    for (const auto& [seq,p]:pending_) { (void)seq; if(now>=p.first) oldest=std::max(oldest,double(now-p.first)/1000); }
    const auto s=state_.status();
    std::ostringstream out;
    out<<"{\"t_us\":"<<now<<",\"mode\":"<<uint32_t(state_.enhanced(now)?Mode::Enhanced:Mode::Legacy)
       <<",\"room\":"<<s.room<<",\"epoch\":"<<s.epoch<<",\"rtt_ms\":"<<rtt_<<",\"jitter_ms\":"<<state_.jitterMs()
       <<",\"interpolation_ms\":"<<state_.bufferMs()<<",\"motion_sent\":"<<sent_<<",\"motion_received\":"<<received_
       <<",\"motion_rejected\":"<<stale_<<",\"reliable_pending\":"<<pending_.size()<<",\"oldest_unacked_ms\":"<<oldest
       <<",\"reliable_retries\":"<<retries_<<",\"reliable_promoted\":"<<state_.promotedCount();
    {
        std::lock_guard lock(state_.mutex_);
        out<<",\"world_mismatches\":"<<state_.worldMismatches_<<",\"world_requests\":"<<state_.worldRequests_
           <<",\"world_entities\":"<<(state_.worldValid_?state_.world_.count:0)
           <<",\"world_digests_sent\":"<<worldSent_<<",\"world_digests_received\":"<<worldReceived_
           <<",\"world_refresh_completed\":"<<state_.worldStats_.completed<<",\"world_actors_refreshed\":"<<state_.worldStats_.actors
           <<",\"world_refresh_packets\":"<<state_.worldStats_.packets<<",\"world_refresh_skipped\":"<<state_.worldStats_.skipped;
    }
    out<<"}\n";
    return out.str();
}
} // namespace reo_network::native
