#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1E20
// Address: 0x1b1e20 - 0x1b1ec0
void sub_001B1E20_0x1b1e20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1E20_0x1b1e20");
#endif

    switch (ctx->pc) {
        case 0x1b1e30u: goto label_1b1e30;
        case 0x1b1e38u: goto label_1b1e38;
        case 0x1b1e60u: goto label_1b1e60;
        case 0x1b1e68u: goto label_1b1e68;
        case 0x1b1e98u: goto label_1b1e98;
        default: break;
    }

    ctx->pc = 0x1b1e20u;

label_1b1e20:
    // 0x1b1e20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b1e20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b1e24: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b1e24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b1e28: 0xc06c72c  jal         func_1B1CB0
    ctx->pc = 0x1B1E28u;
    SET_GPR_U32(ctx, 31, 0x1B1E30u);
    ctx->pc = 0x1B1E2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1E28u;
            // 0x1b1e2c: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1CB0u;
    if (runtime->hasFunction(0x1B1CB0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1CB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1E30u; }
        if (ctx->pc != 0x1B1E30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1CB0_0x1b1cb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1E30u; }
        if (ctx->pc != 0x1B1E30u) { return; }
    }
    ctx->pc = 0x1B1E30u;
label_1b1e30:
    // 0x1b1e30: 0xc06c72c  jal         func_1B1CB0
    ctx->pc = 0x1B1E30u;
    SET_GPR_U32(ctx, 31, 0x1B1E38u);
    ctx->pc = 0x1B1E34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1E30u;
            // 0x1b1e34: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1CB0u;
    if (runtime->hasFunction(0x1B1CB0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1CB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1E38u; }
        if (ctx->pc != 0x1B1E38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1CB0_0x1b1cb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1E38u; }
        if (ctx->pc != 0x1B1E38u) { return; }
    }
    ctx->pc = 0x1B1E38u;
label_1b1e38:
    // 0x1b1e38: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b1e38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1e3c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1E3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1E40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1E3Cu;
            // 0x1b1e40: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1E20u: goto label_1b1e20;
            case 0x1B1E30u: goto label_1b1e30;
            case 0x1B1E38u: goto label_1b1e38;
            case 0x1B1E60u: goto label_1b1e60;
            case 0x1B1E68u: goto label_1b1e68;
            case 0x1B1E98u: goto label_1b1e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1E44u;
    // 0x1b1e44: 0x0  nop
    ctx->pc = 0x1b1e44u;
    // NOP
    // 0x1b1e48: 0x0  nop
    ctx->pc = 0x1b1e48u;
    // NOP
    // 0x1b1e4c: 0x0  nop
    ctx->pc = 0x1b1e4cu;
    // NOP
    // 0x1b1e50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b1e50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b1e54: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b1e54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b1e58: 0xc06c77c  jal         func_1B1DF0
    ctx->pc = 0x1B1E58u;
    SET_GPR_U32(ctx, 31, 0x1B1E60u);
    ctx->pc = 0x1B1DF0u;
    if (runtime->hasFunction(0x1B1DF0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1E60u; }
        if (ctx->pc != 0x1B1E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1DF0_0x1b1df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1E60u; }
        if (ctx->pc != 0x1B1E60u) { return; }
    }
    ctx->pc = 0x1B1E60u;
label_1b1e60:
    // 0x1b1e60: 0xc06c788  jal         func_1B1E20
    ctx->pc = 0x1B1E60u;
    SET_GPR_U32(ctx, 31, 0x1B1E68u);
    ctx->pc = 0x1B1E20u;
    goto label_1b1e20;
    ctx->pc = 0x1B1E68u;
label_1b1e68:
    // 0x1b1e68: 0x3c01004e  lui         $at, 0x4E
    ctx->pc = 0x1b1e68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)78 << 16));
    // 0x1b1e6c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1b1e6cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1e70: 0xa0206a21  sb          $zero, 0x6A21($at)
    ctx->pc = 0x1b1e70u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 27169), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1e74: 0x3c01004e  lui         $at, 0x4E
    ctx->pc = 0x1b1e74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)78 << 16));
    // 0x1b1e78: 0xa0206a20  sb          $zero, 0x6A20($at)
    ctx->pc = 0x1b1e78u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 27168), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1e7c: 0x3c01004f  lui         $at, 0x4F
    ctx->pc = 0x1b1e7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)79 << 16));
    // 0x1b1e80: 0xa0208971  sb          $zero, -0x768F($at)
    ctx->pc = 0x1b1e80u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294936945), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1e84: 0x3c01004f  lui         $at, 0x4F
    ctx->pc = 0x1b1e84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)79 << 16));
    // 0x1b1e88: 0xa0208970  sb          $zero, -0x7690($at)
    ctx->pc = 0x1b1e88u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294936944), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1e8c: 0x3c04004d  lui         $a0, 0x4D
    ctx->pc = 0x1b1e8cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)77 << 16));
    // 0x1b1e90: 0x24051f44  addiu       $a1, $zero, 0x1F44
    ctx->pc = 0x1b1e90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8004));
    // 0x1b1e94: 0x24847000  addiu       $a0, $a0, 0x7000
    ctx->pc = 0x1b1e94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28672));
label_1b1e98:
    // 0x1b1e98: 0xe51818  mult        $v1, $a3, $a1
    ctx->pc = 0x1b1e98u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1b1e9c: 0x833021  addu        $a2, $a0, $v1
    ctx->pc = 0x1b1e9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b1ea0: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1b1ea0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1b1ea4: 0xa0c00000  sb          $zero, 0x0($a2)
    ctx->pc = 0x1b1ea4u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1ea8: 0x2ce30008  sltiu       $v1, $a3, 0x8
    ctx->pc = 0x1b1ea8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x1b1eac: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B1EACu;
    {
        const bool branch_taken_0x1b1eac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B1EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1EACu;
            // 0x1b1eb0: 0xa0c00001  sb          $zero, 0x1($a2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1eac) {
            ctx->pc = 0x1B1E98u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1e98;
        }
    }
    ctx->pc = 0x1B1EB4u;
    // 0x1b1eb4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b1eb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1eb8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1EB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1EBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1EB8u;
            // 0x1b1ebc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1E20u: goto label_1b1e20;
            case 0x1B1E30u: goto label_1b1e30;
            case 0x1B1E38u: goto label_1b1e38;
            case 0x1B1E60u: goto label_1b1e60;
            case 0x1B1E68u: goto label_1b1e68;
            case 0x1B1E98u: goto label_1b1e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1EC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
