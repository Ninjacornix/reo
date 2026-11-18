#pragma once
#include "../movie_selected_clock/clock.hpp"
#include <array>
#include <memory>

namespace reo::native::movie_timing_context {
// Serialized queue observation. Implementations own the queue and its backing;
// callbacks may change that queue, never the movie facts or Context. A failed
// observation is a native refusal, not an empty queue or an original status.
class BufferQueue {
public:
    virtual ~BufferQueue()=default;
    virtual bool available(std::uint32_t&)noexcept=0;
    // Borrow at most two maximum-sized channel-1 spans; return the second then
    // the first before returning. Copy lengths only; no released pointer escapes.
    virtual bool two_spans(std::array<std::uint32_t,2>&)noexcept=0;
};
struct BufferStream {
    std::uint32_t enabled{1},ended{},capacity{};
    std::shared_ptr<BufferQueue> queue;
};
struct Buffering {
    std::uint32_t enabled{},video{},audio{},stalled{},component_one{},video_done{},audio_done{};
    std::uint32_t video_slot{},audio_slot{},pause_margin{},resume_margin{},absolute{};
    movie_selected_clock::Words latest;
    std::array<BufferStream,8> streams;
};
}
