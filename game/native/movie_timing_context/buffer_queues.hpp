#pragma once
#include "buffering.hpp"
#include "../sjrb/sjrb.hpp"
#include "../sjuni/sjuni.hpp"
namespace reo::native::movie_timing_context {
// All accesses, including external producers, require the same serialization.
// Pure/noexcept queue hooks only. These adapters never expose payload bytes.
class RingBufferQueue final:public BufferQueue {
public:
    explicit RingBufferQueue(std::shared_ptr<sjrb::Ring>);
    bool available(std::uint32_t&)noexcept override;
    bool two_spans(std::array<std::uint32_t,2>&)noexcept override;
private:
    std::shared_ptr<sjrb::Ring> queue_;
};
class UniBufferQueue final:public BufferQueue {
public:
    // Retain the region catalogue/source owner as well as numeric SJUNI nodes.
    // The supplied owner must cover all queued regions for the adapter lifetime.
    UniBufferQueue(std::shared_ptr<sjuni::Pool>,std::shared_ptr<const void> regions);
    bool available(std::uint32_t&)noexcept override;
    bool two_spans(std::array<std::uint32_t,2>&)noexcept override;
private:
    std::shared_ptr<sjuni::Pool> queue_;
    std::shared_ptr<const void> regions_;
};
}
