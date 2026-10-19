#pragma once
#include "queue_journal_pipeline.hpp"
#include "../protected_scalar_capture.hpp"
namespace reo_parent_natural {
// A single original queue call's completed GPU event. These are only pointer
// and counter stores; graphics packet link words remain in the actual GPU bank.
class CertifiedQueueCommit final {
    friend class reo_parent_install::Service;
    friend class NativeTarget;
    struct Store {
        uint32_t sourcePc, sourceWord, address, before, after;
        bool blind;
    };
    const void* issuer_;
    reo_gpu_upstream::QueueJournalPipeline::OutputHandle output_;
    reo_gpu_upstream::QueueControlCallHandle call_;
    ProtectedScalarCaptureHandle frontier_;
    uint64_t actualTimeline_;
    std::vector<Store> stores_;
    CertifiedQueueCommit(const void* issuer,
                         reo_gpu_upstream::QueueJournalPipeline::OutputHandle output,
                         reo_gpu_upstream::QueueControlCallHandle call,
                         ProtectedScalarCaptureHandle frontier, uint64_t timeline,
                         std::vector<Store> stores)
        : issuer_(issuer), output_(std::move(output)), call_(std::move(call)),
          frontier_(std::move(frontier)), actualTimeline_(timeline), stores_(std::move(stores)) {}

  public:
    CertifiedQueueCommit(const CertifiedQueueCommit&) = delete;
};
using CertifiedQueueCommitHandle = std::shared_ptr<const CertifiedQueueCommit>;
} // namespace reo_parent_natural
