#include "mixer.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>

namespace reo::native::audio_mix_tail {
namespace {
banks::Config checked(banks::Config c) {
    if(c.max_render_frames<512)throw std::invalid_argument("Full bounded output callback required");
    return c;
}
}
Mixer::Mixer(banks::Config c,std::shared_ptr<banks::GainProvider> gains,std::shared_ptr<MasterGain> master,std::optional<PacketProfile> profile)
    :banks_(std::make_shared<banks::Session>(checked(c))),bank_gains_(std::move(gains)),master_(std::move(master)) {
    if(!bank_gains_ || !master_)throw std::invalid_argument("Owned pure gain providers required");
    if(profile)packets_=std::make_unique<packets::PacketAdapter>(banks_,profile->identity,profile->config);
}
banks::Result<banks::Submission> Mixer::begin_submission() noexcept{if(packets_)return{banks::Status::invalid_submission,{}};return banks_->begin_submission();}
banks::Result<banks::CapturedBank> Mixer::capture(const banks::Submission& token,banks::BankSizes sizes) noexcept{if(packets_)return{banks::Status::invalid_submission,{}};return banks_->capture(token,sizes);}
banks::Result<banks::PreparedBank> Mixer::prepare(const banks::Submission& token,banks::CapturedBank data) noexcept{if(packets_)return{banks::Status::invalid_submission,{}};return banks_->prepare(token,std::move(data));}
banks::Status Mixer::install(const banks::Submission& token,unsigned port,const banks::PreparedBank& asset,banks::LoadPolicy policy) noexcept{if(packets_)return banks::Status::invalid_submission;return banks_->install(token,port,asset,policy);}
banks::ApplyResult Mixer::apply(std::span<const banks::Command> commands) noexcept{if(packets_)return{banks::Status::invalid_submission,0};return banks_->apply(commands);}
banks::Status Mixer::reset() noexcept{if(packets_)return banks::Status::invalid_submission;return banks_->reset();}
banks::Status Mixer::drain_retired() noexcept{return banks_->drain_retired();}
std::shared_ptr<const banks::Budget> Mixer::budget_observer() const noexcept{return banks_->budget_observer();}
packets::Result<packets::Call> Mixer::begin_call() noexcept{if(!packets_)return{packets::Status::unsupported,{}};return packets_->begin_call();}
packets::PacketResult Mixer::submit_packet(packets::Call& call,const packets::CaptureSource& source) noexcept{if(!packets_)return{packets::Status::unsupported,false,0,0};return packets_->submit_packet(call,source);}
packets::Status Mixer::submit_bank(packets::Call& call,unsigned port,const packets::CaptureSource& source) noexcept{if(!packets_)return packets::Status::unsupported;return packets_->submit_bank(call,port,source);}
packets::Status Mixer::reset(packets::Call& call) noexcept{if(!packets_)return packets::Status::unsupported;return packets_->reset(call);}
bool Mixer::bind() noexcept {
    if(stopping_.load(std::memory_order_acquire))return false;
    bool expected=false;return bound_.compare_exchange_strong(expected,true,std::memory_order_acq_rel);
}
Status Mixer::render(float* output,std::uint32_t count) noexcept {
    if(stopping_.load(std::memory_order_acquire))return Status::closed;
    ++render_calls_;
    const auto accepted=packets_?packets_->mix_add(output,count,*bank_gains_)==packets::Status::ok:
        banks_->mix_add(output,count,*bank_gains_)==banks::Status::ok;
    if(!accepted){
        ++bank_failures_;last_status_=Status::bank_failure;return Status::bank_failure;
    }
    const auto gain=master_->gain();
    if(!std::isfinite(gain) || gain<0 || gain>8){
        ++master_failures_;last_status_=Status::invalid_master_gain;return Status::invalid_master_gain;
    }
    for(std::size_t n=0;n<std::size_t(count)*2;++n)output[n]=std::clamp(output[n]*gain,-1.0f,1.0f);
    frames_.fetch_add(count,std::memory_order_relaxed);last_status_=Status::completed;return Status::completed;
}
void Mixer::request_stop() noexcept {
    stopping_.store(true,std::memory_order_release);
    if(packets_)packets_->request_stop();else banks_->request_stop();
}
bool Mixer::join() noexcept {
    request_stop();if(packets_)packets_->join();
    if(!banks_->join())return false;
    joined_.store(true,std::memory_order_release);return true;
}
Snapshot Mixer::snapshot() const noexcept {
    Snapshot out;out.banks=banks_->snapshot();out.render_calls=render_calls_;out.completed_frames=frames_;
    out.bank_failures=bank_failures_;out.master_failures=master_failures_;out.last_status=last_status_;
    out.bound=bound_;out.stopping=stopping_;out.joined=joined_;return out;
}
}
