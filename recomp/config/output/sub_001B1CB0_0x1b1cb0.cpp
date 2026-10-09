#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1CB0
// Address: 0x1b1cb0 - 0x1b1d60
void sub_001B1CB0_0x1b1cb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1CB0_0x1b1cb0");
#endif

    switch (ctx->pc) {
        case 0x1b1cdcu: goto label_1b1cdc;
        case 0x1b1cecu: goto label_1b1cec;
        case 0x1b1cf8u: goto label_1b1cf8;
        case 0x1b1d14u: goto label_1b1d14;
        case 0x1b1d28u: goto label_1b1d28;
        default: break;
    }

    ctx->pc = 0x1b1cb0u;

    // 0x1b1cb0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1b1cb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1b1cb4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1b1cb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1b1cb8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b1cb8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b1cbc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b1cbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b1cc0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1b1cc0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1cc4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b1cc4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b1cc8: 0x3c04004f  lui         $a0, 0x4F
    ctx->pc = 0x1b1cc8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)79 << 16));
    // 0x1b1ccc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1b1cccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1cd0: 0x24848970  addiu       $a0, $a0, -0x7690
    ctx->pc = 0x1b1cd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936944));
    // 0x1b1cd4: 0xc06c708  jal         func_1B1C20
    ctx->pc = 0x1B1CD4u;
    SET_GPR_U32(ctx, 31, 0x1B1CDCu);
    ctx->pc = 0x1B1CD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1CD4u;
            // 0x1b1cd8: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1C20u;
    if (runtime->hasFunction(0x1B1C20u)) {
        auto targetFn = runtime->lookupFunction(0x1B1C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1CDCu; }
        if (ctx->pc != 0x1B1CDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1C20_0x1b1c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1CDCu; }
        if (ctx->pc != 0x1B1CDCu) { return; }
    }
    ctx->pc = 0x1B1CDCu;
label_1b1cdc:
    // 0x1b1cdc: 0x3c04004e  lui         $a0, 0x4E
    ctx->pc = 0x1b1cdcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)78 << 16));
    // 0x1b1ce0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1b1ce0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1ce4: 0xc06c708  jal         func_1B1C20
    ctx->pc = 0x1B1CE4u;
    SET_GPR_U32(ctx, 31, 0x1B1CECu);
    ctx->pc = 0x1B1CE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1CE4u;
            // 0x1b1ce8: 0x24846a20  addiu       $a0, $a0, 0x6A20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1C20u;
    if (runtime->hasFunction(0x1B1C20u)) {
        auto targetFn = runtime->lookupFunction(0x1B1C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1CECu; }
        if (ctx->pc != 0x1B1CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1C20_0x1b1c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1CECu; }
        if (ctx->pc != 0x1B1CECu) { return; }
    }
    ctx->pc = 0x1B1CECu;
label_1b1cec:
    // 0x1b1cec: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b1cecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1cf0: 0x325000ff  andi        $s0, $s2, 0xFF
    ctx->pc = 0x1b1cf0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1b1cf4: 0x24031f44  addiu       $v1, $zero, 0x1F44
    ctx->pc = 0x1b1cf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8004));
label_1b1cf8:
    // 0x1b1cf8: 0x3c02004d  lui         $v0, 0x4D
    ctx->pc = 0x1b1cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)77 << 16));
    // 0x1b1cfc: 0x2231818  mult        $v1, $s1, $v1
    ctx->pc = 0x1b1cfcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1b1d00: 0x24427000  addiu       $v0, $v0, 0x7000
    ctx->pc = 0x1b1d00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 28672));
    // 0x1b1d04: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1b1d04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1d08: 0x439821  addu        $s3, $v0, $v1
    ctx->pc = 0x1b1d08u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b1d0c: 0xc06c708  jal         func_1B1C20
    ctx->pc = 0x1B1D0Cu;
    SET_GPR_U32(ctx, 31, 0x1B1D14u);
    ctx->pc = 0x1B1D10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1D0Cu;
            // 0x1b1d10: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1C20u;
    if (runtime->hasFunction(0x1B1C20u)) {
        auto targetFn = runtime->lookupFunction(0x1B1C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1D14u; }
        if (ctx->pc != 0x1B1D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1C20_0x1b1c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1D14u; }
        if (ctx->pc != 0x1B1D14u) { return; }
    }
    ctx->pc = 0x1B1D14u;
label_1b1d14:
    // 0x1b1d14: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b1d14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b1d18: 0x16030003  bne         $s0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B1D18u;
    {
        const bool branch_taken_0x1b1d18 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B1D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1D18u;
            // 0x1b1d1c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1d18) {
            ctx->pc = 0x1B1D28u;
            goto label_1b1d28;
        }
    }
    ctx->pc = 0x1B1D20u;
    // 0x1b1d20: 0xc06c708  jal         func_1B1C20
    ctx->pc = 0x1B1D20u;
    SET_GPR_U32(ctx, 31, 0x1B1D28u);
    ctx->pc = 0x1B1D24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1D20u;
            // 0x1b1d24: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1C20u;
    if (runtime->hasFunction(0x1B1C20u)) {
        auto targetFn = runtime->lookupFunction(0x1B1C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1D28u; }
        if (ctx->pc != 0x1B1D28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1C20_0x1b1c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1D28u; }
        if (ctx->pc != 0x1B1D28u) { return; }
    }
    ctx->pc = 0x1B1D28u;
label_1b1d28:
    // 0x1b1d28: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b1d28u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1b1d2c: 0x2a230008  slti        $v1, $s1, 0x8
    ctx->pc = 0x1b1d2cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1b1d30: 0x1460fff1  bnez        $v1, . + 4 + (-0xF << 2)
    ctx->pc = 0x1B1D30u;
    {
        const bool branch_taken_0x1b1d30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B1D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1D30u;
            // 0x1b1d34: 0x24031f44  addiu       $v1, $zero, 0x1F44 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8004));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1d30) {
            ctx->pc = 0x1B1CF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1cf8;
        }
    }
    ctx->pc = 0x1B1D38u;
    // 0x1b1d38: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1b1d38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b1d3c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b1d3cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b1d40: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b1d40u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b1d44: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b1d44u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b1d48: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b1d48u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1d4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1D4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1D50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1D4Cu;
            // 0x1b1d50: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1CDCu: goto label_1b1cdc;
            case 0x1B1CECu: goto label_1b1cec;
            case 0x1B1CF8u: goto label_1b1cf8;
            case 0x1B1D14u: goto label_1b1d14;
            case 0x1B1D28u: goto label_1b1d28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1D54u;
    // 0x1b1d54: 0x0  nop
    ctx->pc = 0x1b1d54u;
    // NOP
    // 0x1b1d58: 0x0  nop
    ctx->pc = 0x1b1d58u;
    // NOP
    // 0x1b1d5c: 0x0  nop
    ctx->pc = 0x1b1d5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
