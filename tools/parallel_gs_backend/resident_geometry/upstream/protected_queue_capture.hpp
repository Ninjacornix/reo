#pragma once
#include "queue_resolver_binding.hpp"
#include "../protected_scalar_capture.hpp"
namespace reo_gpu_upstream {
class ProtectedQueueCapture final {
    friend class reo_parent_natural::NativeTarget;
    friend class reo_parent_install::Service;
    friend class ProtectedQueueSnapshot;
    friend class QueueHeaderMetadataPipeline;
    const void* issuer_;
    CallHandle call_;
    QueueResolverBindingHandle resolver_;
    reo_parent_natural::ProtectedScalarCaptureHandle frontier_;
    struct CodeWord {
        uint32_t sourcePc, address, bits;
    };
    std::vector<CodeWord> jumpTable_, writeCode_, lookup_;
    uint32_t resolvedRing_;
    ProtectedQueueCapture(const void* issuer, CallHandle call, QueueResolverBindingHandle resolver,
                          reo_parent_natural::ProtectedScalarCaptureHandle frontier,
                          std::vector<CodeWord> table, std::vector<CodeWord> writeCode,
                          std::vector<CodeWord> lookup, uint32_t resolvedRing)
        : issuer_(issuer), call_(std::move(call)), resolver_(std::move(resolver)),
          frontier_(std::move(frontier)), jumpTable_(std::move(table)),
          writeCode_(std::move(writeCode)), lookup_(std::move(lookup)),
          resolvedRing_(resolvedRing) {}

  public:
    ProtectedQueueCapture(const ProtectedQueueCapture&) = delete;
};
using ProtectedQueueCaptureHandle = std::shared_ptr<const ProtectedQueueCapture>;
constexpr bool CompleteQueueNativeWriterAndIrqPauseCoverage = false;
} // namespace reo_gpu_upstream
