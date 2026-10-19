#pragma once
#include "device.hpp"
#include "fence.hpp"
#include <array>
#include <stdexcept>
namespace reo_gpu_present {
// Owner-only image/fence ring. No GPU allocation escapes in UI metadata.
// Waits cover actual draw completion when retiring a live slot, epoch or device.
class ResidentOwnerImages {
    struct Slot {
        Vulkan::ImageHandle image;
        Vulkan::Fence complete;
    };
    std::array<Slot, 4> slots_{};
    uint64_t epoch_ = 0, serial_ = 0, waits_ = 0;
    bool stopped_ = false;

  public:
    ~ResidentOwnerImages() {
        for (auto& s : slots_)
            if (s.image)
                std::terminate();
    }
    void beginSession() {
        for (auto& s : slots_)
            if (s.image)
                throw std::logic_error("Resident session still owns images");
        epoch_ = serial_ = waits_ = 0;
        stopped_ = false;
    }
    uint64_t retain(const Vulkan::ImageHandle& image, Vulkan::Fence complete, uint64_t epoch) {
        if (stopped_ || !image || !complete)
            throw std::invalid_argument("Missing genuine resident image/draw fence");
        if (epoch_ && epoch_ != epoch)
            retireEpoch();
        epoch_ = epoch;
        auto& slot = slots_[serial_ % slots_.size()];
        if (slot.complete) {
            slot.complete->wait();
            ++waits_;
        }
        slot.image.reset();
        slot.complete.reset();
        slot.image = image;
        slot.complete = std::move(complete);
        return ++serial_;
    }
    void retireEpoch() {
        for (auto& s : slots_) {
            if (s.complete) {
                s.complete->wait();
                ++waits_;
            }
            s.image.reset();
            s.complete.reset();
        }
        epoch_ = 0;
    }
    void shutdown() {
        retireEpoch();
        stopped_ = true;
    }
    uint64_t serial() const {
        return serial_;
    }
    uint64_t fenceWaits() const {
        return waits_;
    }
    unsigned liveImages() const {
        unsigned n = 0;
        for (auto& s : slots_)
            n += bool(s.image);
        return n;
    }
};
} // namespace reo_gpu_present
