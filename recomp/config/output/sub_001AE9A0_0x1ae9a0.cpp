#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE9A0
// Address: 0x1ae9a0 - 0x1ae9f0
void sub_001AE9A0_0x1ae9a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE9A0_0x1ae9a0");
#endif

    switch (ctx->pc) {
        case 0x1ae9b8u: goto label_1ae9b8;
        case 0x1ae9e0u: goto label_1ae9e0;
        default: break;
    }

    ctx->pc = 0x1ae9a0u;

    // 0x1ae9a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ae9a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ae9a4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ae9a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ae9a8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ae9a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ae9ac: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1ae9acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae9b0: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AE9B0u;
    SET_GPR_U32(ctx, 31, 0x1AE9B8u);
    ctx->pc = 0x1AE9B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE9B0u;
            // 0x1ae9b4: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE9B8u; }
        if (ctx->pc != 0x1AE9B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE9B8u; }
        if (ctx->pc != 0x1AE9B8u) { return; }
    }
    ctx->pc = 0x1AE9B8u;
label_1ae9b8:
    // 0x1ae9b8: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AE9B8u;
    {
        const bool branch_taken_0x1ae9b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE9BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE9B8u;
            // 0x1ae9bc: 0x3c03002c  lui         $v1, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae9b8) {
            ctx->pc = 0x1AE9E0u;
            goto label_1ae9e0;
        }
    }
    ctx->pc = 0x1AE9C0u;
    // 0x1ae9c0: 0x102080  sll         $a0, $s0, 2
    ctx->pc = 0x1ae9c0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1ae9c4: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1ae9c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1ae9c8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1ae9c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ae9cc: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1ae9ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1ae9d0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE9D0u;
    {
        const bool branch_taken_0x1ae9d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE9D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE9D0u;
            // 0x1ae9d4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae9d0) {
            ctx->pc = 0x1AE9E0u;
            goto label_1ae9e0;
        }
    }
    ctx->pc = 0x1AE9D8u;
    // 0x1ae9d8: 0xc06b9d0  jal         func_1AE740
    ctx->pc = 0x1AE9D8u;
    SET_GPR_U32(ctx, 31, 0x1AE9E0u);
    ctx->pc = 0x1AE740u;
    if (runtime->hasFunction(0x1AE740u)) {
        auto targetFn = runtime->lookupFunction(0x1AE740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE9E0u; }
        if (ctx->pc != 0x1AE9E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE740_0x1ae740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE9E0u; }
        if (ctx->pc != 0x1AE9E0u) { return; }
    }
    ctx->pc = 0x1AE9E0u;
label_1ae9e0:
    // 0x1ae9e0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ae9e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae9e4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae9e4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae9e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE9E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE9ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE9E8u;
            // 0x1ae9ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE9B8u: goto label_1ae9b8;
            case 0x1AE9E0u: goto label_1ae9e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE9F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
