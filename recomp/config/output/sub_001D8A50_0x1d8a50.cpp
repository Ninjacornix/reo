#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8A50
// Address: 0x1d8a50 - 0x1d8ab0
void sub_001D8A50_0x1d8a50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8A50_0x1d8a50");
#endif

    switch (ctx->pc) {
        case 0x1d8a64u: goto label_1d8a64;
        case 0x1d8a84u: goto label_1d8a84;
        case 0x1d8a9cu: goto label_1d8a9c;
        default: break;
    }

    ctx->pc = 0x1d8a50u;

    // 0x1d8a50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d8a50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d8a54: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d8a54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d8a58: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d8a58u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d8a5c: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8A5Cu;
    SET_GPR_U32(ctx, 31, 0x1D8A64u);
    ctx->pc = 0x1D8A60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8A5Cu;
            // 0x1d8a60: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8A64u; }
        if (ctx->pc != 0x1D8A64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8A64u; }
        if (ctx->pc != 0x1D8A64u) { return; }
    }
    ctx->pc = 0x1D8A64u;
label_1d8a64:
    // 0x1d8a64: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d8a64u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d8a68: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d8a68u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d8a6c: 0x24040024  addiu       $a0, $zero, 0x24
    ctx->pc = 0x1d8a6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x1d8a70: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d8a70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d8a74: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1d8a74u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d8a78: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d8a78u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d8a7c: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D8A7Cu;
    SET_GPR_U32(ctx, 31, 0x1D8A84u);
    ctx->pc = 0x1D8A80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8A7Cu;
            // 0x1d8a80: 0x2408004c  addiu       $t0, $zero, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 76));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8A84u; }
        if (ctx->pc != 0x1D8A84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8A84u; }
        if (ctx->pc != 0x1D8A84u) { return; }
    }
    ctx->pc = 0x1D8A84u;
label_1d8a84:
    // 0x1d8a84: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8a84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8a88: 0x8c22629c  lw          $v0, 0x629C($at)
    ctx->pc = 0x1d8a88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 25244)));
    // 0x1d8a8c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1d8a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1d8a90: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8a90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8a94: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D8A94u;
    SET_GPR_U32(ctx, 31, 0x1D8A9Cu);
    ctx->pc = 0x1D8A98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8A94u;
            // 0x1d8a98: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8A9Cu; }
        if (ctx->pc != 0x1D8A9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8A9Cu; }
        if (ctx->pc != 0x1D8A9Cu) { return; }
    }
    ctx->pc = 0x1D8A9Cu;
label_1d8a9c:
    // 0x1d8a9c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d8a9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8aa0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d8aa0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8aa4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d8aa4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8aa8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8AA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D8AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8AA8u;
            // 0x1d8aac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D8A64u: goto label_1d8a64;
            case 0x1D8A84u: goto label_1d8a84;
            case 0x1D8A9Cu: goto label_1d8a9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D8AB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
