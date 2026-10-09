#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D6B0
// Address: 0x15d6b0 - 0x15d700
void sub_0015D6B0_0x15d6b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D6B0_0x15d6b0");
#endif

    switch (ctx->pc) {
        case 0x15d6d4u: goto label_15d6d4;
        case 0x15d6e8u: goto label_15d6e8;
        default: break;
    }

    ctx->pc = 0x15d6b0u;

    // 0x15d6b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15d6b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15d6b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15d6b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d6b8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15d6b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d6bc: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15d6bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15d6c0: 0x8e020158  lw          $v0, 0x158($s0)
    ctx->pc = 0x15d6c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 344)));
    // 0x15d6c4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15D6C4u;
    {
        const bool branch_taken_0x15d6c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D6C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D6C4u;
            // 0x15d6c8: 0xa0182d  daddu       $v1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d6c4) {
            ctx->pc = 0x15D6E0u;
            goto label_15d6e0;
        }
    }
    ctx->pc = 0x15D6CCu;
    // 0x15d6cc: 0xc0575c0  jal         func_15D700
    ctx->pc = 0x15D6CCu;
    SET_GPR_U32(ctx, 31, 0x15D6D4u);
    ctx->pc = 0x15D700u;
    if (runtime->hasFunction(0x15D700u)) {
        auto targetFn = runtime->lookupFunction(0x15D700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D6D4u; }
        if (ctx->pc != 0x15D6D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D700_0x15d700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D6D4u; }
        if (ctx->pc != 0x15D6D4u) { return; }
    }
    ctx->pc = 0x15D6D4u;
label_15d6d4:
    // 0x15d6d4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15D6D4u;
    {
        const bool branch_taken_0x15d6d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D6D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D6D4u;
            // 0x15d6d8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d6d4) {
            ctx->pc = 0x15D6ECu;
            goto label_15d6ec;
        }
    }
    ctx->pc = 0x15D6DCu;
    // 0x15d6dc: 0x0  nop
    ctx->pc = 0x15d6dcu;
    // NOP
label_15d6e0:
    // 0x15d6e0: 0xc0575c2  jal         func_15D708
    ctx->pc = 0x15D6E0u;
    SET_GPR_U32(ctx, 31, 0x15D6E8u);
    ctx->pc = 0x15D6E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D6E0u;
            // 0x15d6e4: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D708u;
    if (runtime->hasFunction(0x15D708u)) {
        auto targetFn = runtime->lookupFunction(0x15D708u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D6E8u; }
        if (ctx->pc != 0x15D6E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D708_0x15d708(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D6E8u; }
        if (ctx->pc != 0x15D6E8u) { return; }
    }
    ctx->pc = 0x15D6E8u;
label_15d6e8:
    // 0x15d6e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15d6e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_15d6ec:
    // 0x15d6ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d6ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d6f0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15d6f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d6f4: 0x80575ec  j           func_15D7B0
    ctx->pc = 0x15D6F4u;
    ctx->pc = 0x15D6F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D6F4u;
            // 0x15d6f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D7B0u;
    if (runtime->hasFunction(0x15D7B0u)) {
        auto targetFn = runtime->lookupFunction(0x15D7B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015D7B0_0x15d7b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15D6FCu;
    // 0x15d6fc: 0x0  nop
    ctx->pc = 0x15d6fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
