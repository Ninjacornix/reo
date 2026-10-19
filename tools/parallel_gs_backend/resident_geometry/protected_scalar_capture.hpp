#pragma once
#include "explicit_source_write.hpp"
#include <array>
namespace reo_parent_natural {
class ProtectedScalarCapture final {
    friend class NativeTarget;
    const NativeTarget* issuer_;
    PS2Runtime* runtime_;
    R5900Context* context_;
    int32_t task_;
    uint64_t epoch_, captureOrdinal_, completedSequence_;
    std::thread::id hostThread_;
    struct Word {
        uint32_t address, value;
        uint64_t completedWriter;
    };
    std::vector<Word> words_;
    ProtectedScalarCapture(const NativeTarget* issuer, PS2Runtime* runtime, R5900Context* ctx,
                           int32_t task, uint64_t epoch, uint64_t ordinal, uint64_t completed,
                           std::vector<Word> words)
        : issuer_(issuer), runtime_(runtime), context_(ctx), task_(task), epoch_(epoch),
          captureOrdinal_(ordinal), completedSequence_(completed),
          hostThread_(std::this_thread::get_id()), words_(std::move(words)) {}

  public:
    ProtectedScalarCapture(const ProtectedScalarCapture&) = delete;
    PS2Runtime* runtime() const noexcept {
        return runtime_;
    }
    R5900Context* context() const noexcept {
        return context_;
    }
    int32_t task() const noexcept {
        return task_;
    }
    uint64_t epoch() const noexcept {
        return epoch_;
    }
    uint64_t captureOrdinal() const noexcept {
        return captureOrdinal_;
    }
    uint64_t completedSequence() const noexcept {
        return completedSequence_;
    }
    uint32_t word(uint32_t address) const {
        for (const auto& w : words_)
            if (w.address == address)
                return w.value;
        throw std::invalid_argument("Protected scalar not included in actual capture");
    }
    uint64_t completedWriter(uint32_t address) const {
        for (const auto& w : words_)
            if (w.address == address)
                return w.completedWriter;
        throw std::invalid_argument("Protected scalar lacks actual writer witness");
    }
};
using ProtectedScalarCaptureHandle = std::shared_ptr<const ProtectedScalarCapture>;
class CertifiedControlCommit;
using CertifiedControlCommitHandle = std::shared_ptr<const CertifiedControlCommit>;
class CertifiedControlCommitTarget {
  public:
    virtual ~CertifiedControlCommitTarget() = default;
    virtual void commitCertifiedControlOnEe(const CertifiedControlCommitHandle&, R5900Context*) = 0;
};
class ProtectedScalarCaptureTarget {
  public:
    virtual ~ProtectedScalarCaptureTarget() = default;
    virtual ProtectedScalarCaptureHandle captureProtectedScalars(R5900Context*,
                                                                 const std::vector<uint32_t>&) = 0;
    virtual void validateProtectedScalars(const ProtectedScalarCaptureHandle&,
                                          R5900Context*) const = 0;
    virtual void releaseProtectedScalars(const ProtectedScalarCaptureHandle&, R5900Context*) = 0;
};
// Ordinary permits use actual ctx.pc. A GPU scalar commit needs a distinct
// private Service issuer retaining its source event, exact output and fence.
// No caller-supplied site/receipt/fence flag can authorize that commit.
constexpr bool CertifiedControlCommitIssuerImplemented = false;
constexpr bool CompleteProtectedScalarWriterCoverage = false;
} // namespace reo_parent_natural
