// Isolated source-oracle transport, never a runtime adapter. Operations use the
// public typed Session API; private access below is observation-only. See the
// comparison receipt for the frozen source and original observer identities.
#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <span>
#include <variant>
#include <vector>
#define private public
#include "session.hpp"
#undef private
#include "session.cpp"
#include "algorithms.cpp"

float reoAudioBankGain(unsigned,unsigned,uint64_t);
namespace native_transport {
namespace n=reo::native::audio_banks;
using n::detail::Bank;using n::detail::Sample;using n::detail::DecodedSample;
using n::detail::Sequence;using n::detail::Event;
inline n::Session session;
inline auto& voices=session.state_->voices;
inline auto& frameClock=session.state_->frameClock;
inline auto& requestAge=session.state_->requestAge;
inline auto& muted=session.state_->muted;
inline auto& mono=session.state_->mono;
inline auto& unsupportedReports=session.state_->diagnostics.unsupported;
inline void check(n::Status status){if(status!=n::Status::ok)throw std::runtime_error("native transport status "+std::to_string(int(status)));}
struct BankProxy {
    unsigned port;
    const Bank& get()const {const auto& asset=session.state_->ports[port].asset;static const Bank empty;return asset?asset->bank:empty;}
    unsigned sequenceCount()const{return get().sequenceCount();}
    bool resolve(unsigned p,uint8_t note,uint8_t velocity,std::vector<Sample>& out)const{return get().resolve(p,note,velocity,out);}
    auto decoded(const Sample& s)const{return get().decoded(s);}
};
using Requests=decltype(session.state_->ports[0].requests);
struct PortProxy {const bool& loaded;const uint64_t& fingerprint;const unsigned& volume;const Requests& requests;BankProxy bank;};
template<size_t...I>auto observePorts(std::index_sequence<I...>){return std::array<PortProxy,sizeof...(I)>{PortProxy{session.state_->ports[I].loaded,session.state_->ports[I].fingerprint,session.state_->ports[I].volume,session.state_->ports[I].requests,{unsigned(I)}}...};}
inline auto ports=observePorts(std::make_index_sequence<n::port_count>{});
inline unsigned pendingLoads(){auto r=session.pending_loads();check(r.status);return r.value;}
inline unsigned portState(unsigned port,uint32_t& count){auto r=session.port_state(port,count);check(r.status);return r.value;}
inline unsigned seState(unsigned port,unsigned index,unsigned group){auto r=session.sequence_state(port,index,group);check(r.status);return r.value;}
inline void reset(){check(session.reset());}
inline bool load(const n::Submission& token,unsigned port,const uint8_t* hd,size_t hn,const uint8_t* bd,size_t bn,const uint8_t* tq,size_t tn){
    n::OwnedBankBytes bytes;
    if(hn)bytes.hd.assign(hd,hd+hn);if(bn)bytes.bd.assign(bd,bd+bn);if(tn)bytes.tq.assign(tq,tq+tn);
    auto asset=session.prepare(token,std::move(bytes));
    if(asset.status==n::Status::invalid_asset)return false;
    check(asset.status);check(session.install(token,port,asset.value));return true;
}
inline bool submitBank(unsigned port,const uint8_t* hd,size_t hn,const uint8_t* bd,size_t bn,const uint8_t* tq,size_t tn){
    if(port>=n::port_count)return false;
    auto token=session.begin_submission();check(token.status);return load(token.value,port,hd,hn,bd,bn,tq,tn);
}
// Parser translation is deliberately outside Session. It follows qualified124
// submitPacket's validated prefix and wire fields, not any expected snapshots.
// Full-call Admission spans packet parsing and bank prepare/install here.
inline bool submitPacket(const uint8_t* ram,size_t ramBytes,const uint8_t* packet,size_t bytes){
    if(!packet||!bytes)return false;
    auto token=session.begin_submission();check(token.status);
    auto apply=[&](n::Command c){auto r=session.apply(token.value,std::span<const n::Command>(&c,1));check(r.status);if(r.applied!=1)throw std::runtime_error("native command not applied");};
    auto report=[&](unsigned value){apply(n::UnsupportedControl{n::DiagnosticKind::global_control,value});};
    for(size_t at=0;at<bytes&&packet[at]!=255;){
        const auto* cmd=packet+at;const uint8_t op=*cmd;size_t length=0;
        if((op&0xF0)==0)length=op==8?4:5+((op&1)?1:0)+((op&2)?1:0)+((op&4)?2:0);
        else if(op==0x28||op==0x40||op==0x43)length=1;
        else if(op==0x29||op==0x4B)length=3;
        else if(op==0x41||op==0x42||(op>=0x47&&op<=0x4A))length=2;
        else if(op==0x44)length=6;
        else if(op==0x45||op==0x4C)length=4;
        else if(op==0x4D||op==0x4E)length=21;
        if(!length||length>bytes-at){report(op);return false;}
        if((op&0xF0)==0){
            size_t pos=4;bool change=(op&8)!=0;uint8_t volume=change?255:127,pan=change?255:64;uint16_t pitch=change?65535:0x2000;
            if(op!=8){if(op&1)volume=cmd[pos++];if(op&2)pan=cmd[pos++];if(op&4){pitch=uint16_t(cmd[pos])<<8|cmd[pos+1];pos+=2;}}
            if(op==8)apply(n::CancelRequest{cmd[1],cmd[2],cmd[3]});
            else if(change)apply(n::ChangeRequest{cmd[1],cmd[2],cmd[3],volume,pan,pitch});
            else apply(n::StartRequest{cmd[1],cmd[2],cmd[3],volume,pan,pitch,cmd[pos]});
        }else if(op==0x4D||op==0x4E){
            unsigned port=unsigned(cmd[1])<<8|cmd[2];if(port>=n::port_count){report(port);return false;}
            if(op==0x4D||!session.state_->ports[port].loaded){
                const uint8_t* data[3];size_t sizes[3];
                for(unsigned i=0;i<3;++i){const auto* p=cmd+3+i*6;uint32_t address=(uint32_t(p[0])<<24|uint32_t(p[1])<<16|uint32_t(p[2])<<8|(p[3]&240))&0x1FFFFFF;
                    sizes[i]=size_t(p[3]&15)<<20|size_t(p[4])<<12|size_t(p[5])<<4;
                    if(!ram||address>ramBytes||sizes[i]>ramBytes-address)return false;data[i]=ram+address;}
                if(!load(token.value,port,data[0],sizes[0],data[1],sizes[1],data[2],sizes[2]))return false;
            }
        }else if(op==0x29)apply(n::SetAllVolumes{uint16_t(unsigned(cmd[1])<<8|cmd[2])});
        else if(op==0x41)apply(n::SetMuted{cmd[1]!=0});
        else if(op==0x42)apply(n::SetMono{cmd[1]==0});
        else if(op==0x4C){if(cmd[1]<n::port_count)apply(n::SetPortVolume{cmd[1],uint16_t(unsigned(cmd[2])<<8|cmd[3])});}
        else if(op==0x28||op==0x40||op==0x43)apply(n::StopAll{op==0x43});
        else if(op>=0x47&&op<=0x4A&&cmd[1]<n::port_count)apply(n::StopPort{cmd[1],op<0x4A});
        else if(op==0x44)apply(n::UnsupportedControl{n::DiagnosticKind::reverb,cmd[1]});
        else report(op);
        at+=length;
    }return true;
}
struct Gain final:n::GainProvider {float gain(unsigned p,unsigned q,uint64_t fp)noexcept override{return reoAudioBankGain(p,q,fp);}};
inline void mix(float* out,unsigned frames){Gain gain;check(session.mix_add(out,frames,gain));}
} // namespace native_transport
