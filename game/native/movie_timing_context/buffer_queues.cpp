#include "buffer_queues.hpp"
#include <bit>
#include <stdexcept>
#include <utility>
namespace reo::native::movie_timing_context {
namespace {
// Count is not a replacement for peek: fragmented SJUNI queues may contain
// more than two spans. Return order is observable even if lengths are zero.
template<class Chunk,class Count,class Get,class Unget>
bool peek(std::array<std::uint32_t,2>& output,Count count,Get get,Unget unget)noexcept {
    std::int32_t available{};if(!count(available))return false;
    Chunk first{},second{};if(!get(first))return false;
    bool admitted=true;bool second_taken=false;
    if(first.bytes<available){second_taken=get(second);admitted=second_taken;if(second_taken)admitted=unget(second);}
    const auto returned_first=unget(first);
    if(!admitted || !returned_first)return false;
    output={static_cast<std::uint32_t>(first.bytes),second_taken?static_cast<std::uint32_t>(second.bytes):0};return true;
}
struct RingChunk {sjrb::Chunk chunk;std::int32_t bytes{};};
}
RingBufferQueue::RingBufferQueue(std::shared_ptr<sjrb::Ring> queue):queue_(std::move(queue)){
    if(!queue_)throw std::invalid_argument("Owned ring queue required");
}
bool RingBufferQueue::available(std::uint32_t& output)noexcept {
    std::int32_t count{};if(queue_->count(1,count)!=sjrb::Status::completed)return false;
    output=static_cast<std::uint32_t>(count);return true;
}
bool RingBufferQueue::two_spans(std::array<std::uint32_t,2>& output)noexcept {
    const auto queue=queue_;
    return peek<RingChunk>(output,[&](std::int32_t& n){return queue->count(1,n)==sjrb::Status::completed;},
        [&](RingChunk& span){const auto result=queue->get(1,0x7FFFFFFF,span.chunk);span.bytes=span.chunk.bytes();return result==sjrb::Status::completed;},
        [&](RingChunk& span){return queue->unget(1,span.chunk)==sjrb::Status::completed;});
}
UniBufferQueue::UniBufferQueue(std::shared_ptr<sjuni::Pool> queue,std::shared_ptr<const void> regions):queue_(std::move(queue)),regions_(std::move(regions)){
    if(!queue_ || !regions_)throw std::invalid_argument("Owned SJUNI queue and regions required");
}
bool UniBufferQueue::available(std::uint32_t& output)noexcept {
    output=static_cast<std::uint32_t>(queue_->queued_bytes(1));return true;
}
bool UniBufferQueue::two_spans(std::array<std::uint32_t,2>& output)noexcept {
    const auto queue=queue_;
    return peek<sjuni::Span>(output,[&](std::int32_t& n){n=queue->queued_bytes(1);return true;},
        [&](sjuni::Span& span){return queue->get(1,0x7FFFFFFF,span)==sjuni::Result::completed;},
        [&](sjuni::Span& span){return queue->unget(1,span)==sjuni::Result::completed;});
}
}
