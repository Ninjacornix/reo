#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D1C50
// Address: 0x1d1c50 - 0x1d1cb8
void sub_001D1C50_0x1d1c50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D1C50_0x1d1c50");
#endif

    switch (ctx->pc) {
        case 0x1d1c78u: goto label_1d1c78;
        case 0x1d1c90u: goto label_1d1c90;
        case 0x1d1ca8u: goto label_1d1ca8;
        default: break;
    }

    ctx->pc = 0x1d1c50u;

    // 0x1d1c50: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1d1c50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d1c54: 0x308600ff  andi        $a2, $a0, 0xFF
    ctx->pc = 0x1d1c54u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1d1c58: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d1c58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d1c5c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1c5cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1c60: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d1c60u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d1c64: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1c64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1c68: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1d1c68u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1c6c: 0x24a56410  addiu       $a1, $a1, 0x6410
    ctx->pc = 0x1d1c6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25616));
    // 0x1d1c70: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1C70u;
    SET_GPR_U32(ctx, 31, 0x1D1C78u);
    ctx->pc = 0x1D1C74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1C70u;
            // 0x1d1c74: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1C78u; }
        if (ctx->pc != 0x1D1C78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1C78u; }
        if (ctx->pc != 0x1D1C78u) { return; }
    }
    ctx->pc = 0x1D1C78u;
label_1d1c78:
    // 0x1d1c78: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x1d1c78u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x1d1c7c: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d1c7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d1c80: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d1c80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1c84: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d1c84u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1c88: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1C88u;
    SET_GPR_U32(ctx, 31, 0x1D1C90u);
    ctx->pc = 0x1D1C8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1C88u;
            // 0x1d1c8c: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1C90u; }
        if (ctx->pc != 0x1D1C90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1C90u; }
        if (ctx->pc != 0x1D1C90u) { return; }
    }
    ctx->pc = 0x1D1C90u;
label_1d1c90:
    // 0x1d1c90: 0x3c05004c  lui         $a1, 0x4C
    ctx->pc = 0x1d1c90u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)76 << 16));
    // 0x1d1c94: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d1c94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1c98: 0x24a53750  addiu       $a1, $a1, 0x3750
    ctx->pc = 0x1d1c98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 14160));
    // 0x1d1c9c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d1c9cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1ca0: 0xc074650  jal         func_1D1940
    ctx->pc = 0x1D1CA0u;
    SET_GPR_U32(ctx, 31, 0x1D1CA8u);
    ctx->pc = 0x1D1CA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1CA0u;
            // 0x1d1ca4: 0x24070002  addiu       $a3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1940u;
    if (runtime->hasFunction(0x1D1940u)) {
        auto targetFn = runtime->lookupFunction(0x1D1940u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1CA8u; }
        if (ctx->pc != 0x1D1CA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1940_0x1d1940(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1CA8u; }
        if (ctx->pc != 0x1D1CA8u) { return; }
    }
    ctx->pc = 0x1D1CA8u;
label_1d1ca8:
    // 0x1d1ca8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d1ca8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1cac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1cacu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1cb0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1CB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1CB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1CB0u;
            // 0x1d1cb4: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1C78u: goto label_1d1c78;
            case 0x1D1C90u: goto label_1d1c90;
            case 0x1D1CA8u: goto label_1d1ca8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1CB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
