#pragma once
#include "source_instruction_origin.hpp"
#include <thread>
namespace reo_parent_natural {
class NativeTarget;
}
namespace reo_source_closure {
// A predicate over source history is not authority. Only the actual NativeTarget
// can create the private certificate after its completed immutable permits.
struct CompletedDelayFacts {
    const void* scope = nullptr;
    const R5900Context* context = nullptr;
    int32_t task = 0;
    std::thread::id thread{};
    uint64_t epoch = 0, gpuCalls = 0;
    uint32_t entryPc = 0, branchPc = 0, branchWord = 0;
    PS2Runtime::RecompiledFunction body = nullptr;
    uint64_t entryWriter = 0, enteredWriter = 0, branchWriter = 0;
};
inline bool sourceControlFlow(uint32_t word) noexcept {
    const uint32_t op = word >> 26, rs = (word >> 21) & 31u, fn = word & 63u;
    return (op == 0u && (fn == 8u || fn == 9u)) || op == 1u || (op >= 2u && op <= 7u) ||
           (op >= 0x14u && op <= 0x17u) || (op == 0x11u && rs == 8u);
}
inline bool completedDelayMatches(const CompletedDelayFacts& saved, const CompletedDelayFacts& live,
                                  uint64_t nextWriter, uint32_t sourcePc,
                                  const reo_source_instrumentation::InstructionOrigin& origin,
                                  bool delayBefore, uint32_t branchBefore,
                                  uint32_t actualBranchWord, bool retainedMetadata) noexcept {
    return saved.scope && saved.scope == live.scope && saved.context == live.context &&
           saved.task > 0 && saved.task == live.task && saved.thread == live.thread &&
           saved.epoch && saved.epoch == live.epoch && saved.gpuCalls == live.gpuCalls &&
           saved.entryPc && saved.entryPc == live.entryPc && saved.body &&
           saved.body == live.body && saved.entryWriter &&
           saved.entryWriter < saved.enteredWriter && saved.enteredWriter &&
           saved.branchWriter == saved.enteredWriter + 1u && saved.branchWriter < nextWriter &&
           saved.branchPc <= 0xfffffffbu && sourcePc == saved.branchPc + 4u &&
           origin.pc == sourcePc &&
           origin.intent == reo_source_instrumentation::ContextWriteIntent::GeneratedPcProgress &&
           sourceControlFlow(saved.branchWord) && actualBranchWord == saved.branchWord &&
           delayBefore && branchBefore == saved.branchPc && retainedMetadata;
}
class CompletedDelayControl final {
    friend class reo_parent_natural::NativeTarget;
    uint32_t sourcePc_, sourceWord_;
    CompletedDelayControl(uint32_t pc, uint32_t word) : sourcePc_(pc), sourceWord_(word) {}

  public:
    CompletedDelayControl(const CompletedDelayControl&) = delete;
    bool matches(uint32_t at, uint32_t bytes, const void* data, uint32_t pc,
                 const reo_source_instrumentation::InstructionOrigin& origin) const noexcept {
        return data && at == offsetof(R5900Context, in_delay_slot) && bytes == 1u &&
               *static_cast<const uint8_t*>(data) == 0u && pc == sourcePc_ &&
               origin.pc == sourcePc_ && origin.word == sourceWord_ &&
               origin.intent == reo_source_instrumentation::ContextWriteIntent::GeneratedPcProgress;
    }
};
} // namespace reo_source_closure
