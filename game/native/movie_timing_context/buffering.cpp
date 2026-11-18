#include "context.hpp"
#include <bit>
#include <utility>
namespace reo::native::movie_timing_context {
namespace {
std::int32_t signed_word(std::uint32_t value)noexcept{return std::bit_cast<std::int32_t>(value);}
bool less_equal(Words first,Words second)noexcept{
    return std::int64_t{signed_word(first.numerator)}*signed_word(second.denominator)
        <=std::int64_t{signed_word(second.numerator)}*signed_word(first.denominator);
}
}
Status Context::observe_buffering(Buffering value)noexcept {
    if(busy_)return Status::busy;
    if(detached_)return Status::detached;
    buffering_=std::move(value);return Status::completed;
}
bool Context::buffer_end()const noexcept {
    const auto& value=*buffering_;
    if(value.video && value.video_done)return true;
    if(value.audio && value.audio_done)return true;
    for(const auto& stream:value.streams)if(stream.ended)return true;
    return false;
}
bool Context::buffer_refill(bool video,bool& decision)noexcept {
    const auto& value=*buffering_;const auto slot=video?value.video_slot:value.audio_slot;
    if(slot>=value.streams.size())return false;
    const auto& stream=value.streams[slot];const auto queue=stream.queue;
    if(!queue)return false;
    std::uint32_t available{};if(!queue->available(available))return false;
    // The original multiplies in 32 bits before its signed divide by 100.
    const auto threshold=signed_word(stream.capacity*80u)/100;
    decision=signed_word(available)>=threshold;
    if(video && !decision)decision=signed_word(available)>=signed_word(value.absolute);
    return true;
}
bool Context::buffer_peek(std::uint32_t slot,std::uint32_t& length)noexcept {
    const auto& stream=buffering_->streams[slot];length=0;
    const auto queue=stream.queue;if(!stream.enabled || !queue)return true;
    if(hooks_){hooks_->enter(0x11223344);if(!guard_->depth)guard_->tag=1;++guard_->depth;}
    std::array<std::uint32_t,2> lengths{};const auto admitted=queue->two_spans(lengths);
    if(hooks_){--guard_->depth;if(!guard_->depth)guard_->tag=0;hooks_->leave(0x55667788);}
    if(admitted)length=lengths[0]+lengths[1];
    return admitted;
}
pause::Reply Context::buffer_predicate(bool resume)noexcept {
    const auto done=[](bool decision){return pause::Reply{pause::ProviderStatus::completed,decision?1u:0u,{}};};
    const auto failed=[](){return pause::Reply{pause::ProviderStatus::failed,0,{}};};
    const auto& value=*buffering_;
    if(!resume){
        if(!value.enabled || !facts_.selector || facts_.pause || facts_.actual!=4 || buffer_end())return done(false);
        if(value.video==1 && !value.stalled)return done(false);
        std::uint32_t length{};
        if(value.audio==1){if(!buffer_peek(2,length))return failed();if(signed_word(length)>0)return done(false);}
        if(value.component_one){if(!buffer_peek(0,length))return failed();if(signed_word(length)>0)return done(false);}
        if(value.video==1){bool ready{};if(!buffer_refill(true,ready))return failed();if(ready)return done(false);}
    }else{
        if(buffer_end())return done(true);
        if(value.video==1){bool ready{};if(!buffer_refill(true,ready))return failed();if(ready)return done(true);}
        if(value.audio==1){bool ready{};if(!buffer_refill(false,ready))return failed();if(ready)return done(true);}
    }
    const auto current=query(Operation::cached,{});if(current.status!=Status::completed)return failed();
    // Latest horizon and margin are observed after the cached query, matching
    // the original call order. This profile prohibits fact-changing callbacks.
    auto horizon=value.latest;const auto margin=resume?value.resume_margin:value.pause_margin;
    const auto correction=std::int64_t{signed_word(margin)}*signed_word(horizon.denominator)/1000000;
    horizon.numerator-=static_cast<std::uint32_t>(correction);
    if(!resume && (signed_word(current.words.numerator)<=0 || signed_word(horizon.numerator)<=0))return done(false);
    const auto ahead=less_equal(current.words,horizon);return done(resume?ahead:!ahead);
}
}
