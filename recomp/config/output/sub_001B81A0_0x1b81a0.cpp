#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B81A0
// Address: 0x1b81a0 - 0x1b8200
void sub_001B81A0_0x1b81a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B81A0_0x1b81a0");
#endif

    switch (ctx->pc) {
        case 0x1b81b0u: goto label_1b81b0;
        case 0x1b81c4u: goto label_1b81c4;
        case 0x1b81d8u: goto label_1b81d8;
        case 0x1b81f0u: goto label_1b81f0;
        default: break;
    }

    ctx->pc = 0x1b81a0u;

    // 0x1b81a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b81a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b81a4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b81a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b81a8: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B81A8u;
    SET_GPR_U32(ctx, 31, 0x1B81B0u);
    ctx->pc = 0x1B81ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81A8u;
            // 0x1b81ac: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81B0u; }
        if (ctx->pc != 0x1B81B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81B0u; }
        if (ctx->pc != 0x1B81B0u) { return; }
    }
    ctx->pc = 0x1B81B0u;
label_1b81b0:
    // 0x1b81b0: 0x3c040060  lui         $a0, 0x60
    ctx->pc = 0x1b81b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)96 << 16));
    // 0x1b81b4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1b81b4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b81b8: 0x2484e360  addiu       $a0, $a0, -0x1CA0
    ctx->pc = 0x1b81b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959968));
    // 0x1b81bc: 0xc06dfd0  jal         func_1B7F40
    ctx->pc = 0x1B81BCu;
    SET_GPR_U32(ctx, 31, 0x1B81C4u);
    ctx->pc = 0x1B81C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81BCu;
            // 0x1b81c0: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7F40u;
    if (runtime->hasFunction(0x1B7F40u)) {
        auto targetFn = runtime->lookupFunction(0x1B7F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81C4u; }
        if (ctx->pc != 0x1B81C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7F40_0x1b7f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81C4u; }
        if (ctx->pc != 0x1B81C4u) { return; }
    }
    ctx->pc = 0x1B81C4u;
label_1b81c4:
    // 0x1b81c4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b81c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b81c8: 0x16030005  bne         $s0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B81C8u;
    {
        const bool branch_taken_0x1b81c8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B81CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81C8u;
            // 0x1b81cc: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b81c8) {
            ctx->pc = 0x1B81E0u;
            goto label_1b81e0;
        }
    }
    ctx->pc = 0x1B81D0u;
    // 0x1b81d0: 0xc06e034  jal         func_1B80D0
    ctx->pc = 0x1B81D0u;
    SET_GPR_U32(ctx, 31, 0x1B81D8u);
    ctx->pc = 0x1B81D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81D0u;
            // 0x1b81d4: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B80D0u;
    if (runtime->hasFunction(0x1B80D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B80D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81D8u; }
        if (ctx->pc != 0x1B81D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B80D0_0x1b80d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81D8u; }
        if (ctx->pc != 0x1B81D8u) { return; }
    }
    ctx->pc = 0x1B81D8u;
label_1b81d8:
    // 0x1b81d8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B81D8u;
    {
        const bool branch_taken_0x1b81d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B81DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81D8u;
            // 0x1b81dc: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b81d8) {
            ctx->pc = 0x1B81F4u;
            goto label_1b81f4;
        }
    }
    ctx->pc = 0x1B81E0u;
label_1b81e0:
    // 0x1b81e0: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B81E0u;
    {
        const bool branch_taken_0x1b81e0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B81E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81E0u;
            // 0x1b81e4: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b81e0) {
            ctx->pc = 0x1B81F0u;
            goto label_1b81f0;
        }
    }
    ctx->pc = 0x1B81E8u;
    // 0x1b81e8: 0xc06e034  jal         func_1B80D0
    ctx->pc = 0x1B81E8u;
    SET_GPR_U32(ctx, 31, 0x1B81F0u);
    ctx->pc = 0x1B81ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81E8u;
            // 0x1b81ec: 0x24050009  addiu       $a1, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B80D0u;
    if (runtime->hasFunction(0x1B80D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B80D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81F0u; }
        if (ctx->pc != 0x1B81F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B80D0_0x1b80d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B81F0u; }
        if (ctx->pc != 0x1B81F0u) { return; }
    }
    ctx->pc = 0x1B81F0u;
label_1b81f0:
    // 0x1b81f0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b81f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b81f4:
    // 0x1b81f4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b81f4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b81f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B81F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B81FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B81F8u;
            // 0x1b81fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B81B0u: goto label_1b81b0;
            case 0x1B81C4u: goto label_1b81c4;
            case 0x1B81D8u: goto label_1b81d8;
            case 0x1B81E0u: goto label_1b81e0;
            case 0x1B81F0u: goto label_1b81f0;
            case 0x1B81F4u: goto label_1b81f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8200u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
