#pragma once
#include "parent_natural_runtime.h"
#include <cstring>
#include <vector>
#include <thread>
#include <functional>
// Implementation-only accessor beside the runtime's real guest-depth TLS.
// No caller-owned boolean or test-only environment switch supplies authority.
uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*) noexcept;
namespace reo_parent_natural {
class NativeTarget;
class PreparedSourceWrite final {
    friend class NativeTarget;
    const void* issuer_;
    SourceSpace space_;
    uint32_t at_, bytes_, pc_, afterPc_;
    uint64_t epoch_, sequence_;
    R5900Context* context_;
    int32_t task_;
    std::vector<uint8_t> value_;
    std::thread::id hostThread_;
    std::unique_lock<std::recursive_mutex> sourceLease_;
    bool deferredControl_ = false;
    uint8_t deferredControlRole_ = 0;
    std::function<void()> validateActualIssuer_, completeActualIssuer_;
    bool reviewed_, mirrored_ = false, authorized_ = false, completed_ = false;
    PreparedSourceWrite(const void* issuer, SourceSpace space, uint32_t at, const void* data,
                        uint32_t bytes, uint32_t pc, uint64_t epoch, uint64_t sequence,
                        R5900Context* context, int32_t task, bool reviewed,
                        std::unique_lock<std::recursive_mutex> lease)
        : issuer_(issuer), space_(space), at_(at), bytes_(bytes), pc_(pc), afterPc_(pc),
          epoch_(epoch), sequence_(sequence), context_(context), task_(task),
          value_(static_cast<const uint8_t*>(data), static_cast<const uint8_t*>(data) + bytes),
          hostThread_(std::this_thread::get_id()), sourceLease_(std::move(lease)),
          reviewed_(reviewed) {
        if (space == SourceSpace::Context)
            for (unsigned byte = 0; byte < 4; ++byte) {
                const uint32_t offset = offsetof(R5900Context, pc) + byte;
                if (offset >= at && offset - at < bytes)
                    reinterpret_cast<uint8_t*>(&afterPc_)[byte] = value_[offset - at];
            }
    }

  public:
    PreparedSourceWrite(const PreparedSourceWrite&) = delete;
    const void* data() const noexcept {
        return value_.data();
    }
    uint32_t bytes() const noexcept {
        return bytes_;
    }
};
using SourceWritePermit = std::shared_ptr<const PreparedSourceWrite>;
class ExplicitSourceWriteTarget {
  public:
    virtual ~ExplicitSourceWriteTarget() = default;
    virtual SourceWritePermit beginSourceWrite(SourceSpace, uint32_t, const void*, uint32_t,
                                               R5900Context*, uint32_t) = 0;
    virtual void authorizeSourceWrite(const SourceWritePermit&, SourceSpace, uint32_t, const void*,
                                      uint32_t, R5900Context*, uint32_t) = 0;
    virtual void finishSourceWrite(const SourceWritePermit&, SourceSpace, uint32_t, R5900Context*,
                                   uint32_t) = 0;
    virtual void abandonSourceWrite(const SourceWritePermit&) noexcept = 0;
};
// No public/raw-site shortcut can mint or consume this permit. The genuine
// NativeTarget alone associates value/range/site/task/epoch and real mirror.
constexpr bool CompletePublicAndNativeCoverage = false;
} // namespace reo_parent_natural
