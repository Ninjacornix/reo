// Standalone array-owner checks only. There is no EE, scheduler or parent
// producer in this executable. Any attempt to execute one aborts the check;
// numerical VU work, graphics, fences and receipts use the real GPU code.
#include "ps2_runtime.h"
#include "runtime/ps2_memory.h"
#include "parent_natural_runtime.h"
#include "pre_entry_control_journal.h"
#include "irq_cpu_control.h"
#include <cstdio>
#include <cstdlib>

namespace {
[[noreturn]] void isolatedGuestCall() noexcept {
    std::fputs("FAIL: standalone GPU owner attempted a guest/parent runtime operation\n", stderr);
    std::abort();
}
} // namespace
uint32_t PS2Memory::translateAddress(uint32_t) {
    isolatedGuestCall();
}
bool PS2Memory::isScratchpad(uint32_t) const {
    isolatedGuestCall();
}
PS2Runtime::GuestExecutionReleaseScope::GuestExecutionReleaseScope(PS2Runtime*) noexcept {
    isolatedGuestCall();
}
PS2Runtime::GuestExecutionReleaseScope::~GuestExecutionReleaseScope() {
    isolatedGuestCall();
}
PS2Runtime::RecompiledFunction PS2Runtime::lookupFunction(uint32_t) {
    isolatedGuestCall();
}
bool PS2Runtime::hasFunction(uint32_t) const {
    isolatedGuestCall();
}
void PS2Runtime::requestStop() {
    isolatedGuestCall();
}
bool PS2Runtime::isStopRequested() const {
    isolatedGuestCall();
}
namespace reo_parent_natural {
std::shared_ptr<OwnerRequest>
requestActualOwnerControl(uint64_t, const std::function<void(ControlTarget&)>&) {
    isolatedGuestCall();
}
void runActualOwnerControl(uint64_t, const std::function<void(ControlTarget&)>&) {
    isolatedGuestCall();
}
void installActualOwnerTarget(const std::shared_ptr<ControlTarget>&) {
    isolatedGuestCall();
}
uint64_t issueActualColdSession() {
    isolatedGuestCall();
}
void stopActualOwnerTarget(const std::shared_ptr<ControlTarget>&) {
    isolatedGuestCall();
}
std::shared_ptr<ControlTarget> findActualOwnerTarget(const void*) {
    return {};
}
uint64_t actualOwnerBindingGeneration() noexcept {
    return 0;
}
AccessScope::AccessScope(PS2Runtime*, R5900Context*) {
    isolatedGuestCall();
}
AccessScope::~AccessScope() {
    isolatedGuestCall();
}
PS2Runtime* currentRuntime() noexcept {
    return nullptr;
}
R5900Context* currentContext() noexcept {
    return nullptr;
}
void PreEntryControlSnapshot::requireAuthenticColdOwner(PS2Runtime&, R5900Context&, const void*,
                                                        const std::shared_ptr<const void>&) const {
    isolatedGuestCall();
}
} // namespace reo_parent_natural
namespace ps2_sched {
int currentThread() {
    isolatedGuestCall();
}
} // namespace ps2_sched
uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*) noexcept {
    isolatedGuestCall();
}
PS2Runtime::RecompiledFunction reoActualPoolResolverPassthroughIdentity() {
    isolatedGuestCall();
}
namespace reo_irq_integer {
bool integerField(uint32_t, uint32_t) noexcept {
    isolatedGuestCall();
}
bool integerWriteShape(uint32_t, uint32_t,
                       const reo_source_instrumentation::InstructionOrigin&) noexcept {
    isolatedGuestCall();
}
bool exactNativeReturn(uint32_t, const void*, uint32_t) noexcept {
    isolatedGuestCall();
}
bool nativeScopeActive() noexcept {
    isolatedGuestCall();
}
} // namespace reo_irq_integer
uint32_t ps2IoRegLockDepth() noexcept {
    isolatedGuestCall();
}
#define ISOLATED_BODY(name)                                                                        \
    void name(uint8_t*, R5900Context*, PS2Runtime*) {                                              \
        isolatedGuestCall();                                                                       \
    }
ISOLATED_BODY(sub_0018DCA0_0x18dca0)
ISOLATED_BODY(sub_001A0D70_0x1a0d70)
ISOLATED_BODY(sub_001A1330_0x1a1330)
ISOLATED_BODY(sub_0018DCE0_0x18dce0)
ISOLATED_BODY(sub_0018DD40_0x18dd40)
ISOLATED_BODY(sub_0018DDD0_0x18ddd0)
ISOLATED_BODY(sub_001A0D10_0x1a0d10)
ISOLATED_BODY(sub_001A5B40_0x1a5b40)
ISOLATED_BODY(sub_001A1600_0x1a1600)
ISOLATED_BODY(sub_00124E50_0x124e50)
#undef ISOLATED_BODY
