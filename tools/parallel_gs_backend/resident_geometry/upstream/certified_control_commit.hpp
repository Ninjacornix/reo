#pragma once
#include "allocator18ddd0.hpp"
#include "../protected_scalar_capture.hpp"
namespace reo_parent_natural {
// An actual GPU scalar-control event, separate from ordinary ctx.pc permits.
// Only the Service that waited the genuine allocator output can issue it.
class CertifiedControlCommit final {
    friend class reo_parent_install::Service;
    friend class NativeTarget;
    const void* issuer_;
    reo_gpu_upstream::Allocator18DDD0::OutputHandle output_;
    ProtectedScalarCaptureHandle capture_;
    uint64_t realTimeline_;
    uint32_t sourcePc_, sourceWord_, address_, before_, after_;
    CertifiedControlCommit(const void* issuer,
                           reo_gpu_upstream::Allocator18DDD0::OutputHandle output,
                           ProtectedScalarCaptureHandle capture, uint64_t timeline,
                           uint32_t sourcePc, uint32_t sourceWord, uint32_t address,
                           uint32_t before, uint32_t after)
        : issuer_(issuer), output_(std::move(output)), capture_(std::move(capture)),
          realTimeline_(timeline), sourcePc_(sourcePc), sourceWord_(sourceWord), address_(address),
          before_(before), after_(after) {}

  public:
    CertifiedControlCommit(const CertifiedControlCommit&) = delete;
};
// The peer protected-scalar header declares the strongly typed handle and
// trusted single-call target interface. This definition supplies its private
// genuine output/fence event; it does not add an ordinary source permit.
} // namespace reo_parent_natural
