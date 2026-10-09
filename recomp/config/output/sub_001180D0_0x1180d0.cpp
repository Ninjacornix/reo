#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001180D0
// Address: 0x1180d0 - 0x118110
void sub_001180D0_0x1180d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001180D0_0x1180d0");
#endif

    switch (ctx->pc) {
        case 0x1180e8u: goto label_1180e8;
        case 0x1180f0u: goto label_1180f0;
        case 0x1180f8u: goto label_1180f8;
        case 0x118108u: goto label_118108;
        default: break;
    }

    ctx->pc = 0x1180d0u;

    // 0x1180d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1180d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1180d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1180d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1180d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1180d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1180dc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1180DCu;
    {
        const bool branch_taken_0x1180dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1180E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1180DCu;
            // 0x1180e0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1180dc) {
            ctx->pc = 0x1180F0u;
            goto label_1180f0;
        }
    }
    ctx->pc = 0x1180E4u;
    // 0x1180e4: 0x0  nop
    ctx->pc = 0x1180e4u;
    // NOP
label_1180e8:
    // 0x1180e8: 0xc045fc2  jal         func_117F08
    ctx->pc = 0x1180E8u;
    SET_GPR_U32(ctx, 31, 0x1180F0u);
    ctx->pc = 0x117F08u;
    if (runtime->hasFunction(0x117F08u)) {
        auto targetFn = runtime->lookupFunction(0x117F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1180F0u; }
        if (ctx->pc != 0x1180F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117F08_0x117f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1180F0u; }
        if (ctx->pc != 0x1180F0u) { return; }
    }
    ctx->pc = 0x1180F0u;
label_1180f0:
    // 0x1180f0: 0xc045fac  jal         func_117EB0
    ctx->pc = 0x1180F0u;
    SET_GPR_U32(ctx, 31, 0x1180F8u);
    ctx->pc = 0x1180F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1180F0u;
            // 0x1180f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117EB0u;
    if (runtime->hasFunction(0x117EB0u)) {
        auto targetFn = runtime->lookupFunction(0x117EB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1180F8u; }
        if (ctx->pc != 0x1180F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117EB0_0x117eb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1180F8u; }
        if (ctx->pc != 0x1180F8u) { return; }
    }
    ctx->pc = 0x1180F8u;
label_1180f8:
    // 0x1180f8: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x1180F8u;
    {
        const bool branch_taken_0x1180f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1180FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1180F8u;
            // 0x1180fc: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1180f8) {
            ctx->pc = 0x1180E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1180e8;
        }
    }
    ctx->pc = 0x118100u;
    // 0x118100: 0xc045150  jal         func_114540
    ctx->pc = 0x118100u;
    SET_GPR_U32(ctx, 31, 0x118108u);
    ctx->pc = 0x114540u;
    if (runtime->hasFunction(0x114540u)) {
        auto targetFn = runtime->lookupFunction(0x114540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118108u; }
        if (ctx->pc != 0x118108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114540_0x114540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118108u; }
        if (ctx->pc != 0x118108u) { return; }
    }
    ctx->pc = 0x118108u;
label_118108:
    // 0x118108: 0x1000fff9  b           . + 4 + (-0x7 << 2)
    ctx->pc = 0x118108u;
    {
        const bool branch_taken_0x118108 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x118108) {
            ctx->pc = 0x1180F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1180f0;
        }
    }
    ctx->pc = 0x118110u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
