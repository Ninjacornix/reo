#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3EE0
// Address: 0x1a3ee0 - 0x1a3f70
void sub_001A3EE0_0x1a3ee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3EE0_0x1a3ee0");
#endif

    switch (ctx->pc) {
        case 0x1a3ef8u: goto label_1a3ef8;
        case 0x1a3f04u: goto label_1a3f04;
        case 0x1a3f10u: goto label_1a3f10;
        case 0x1a3f18u: goto label_1a3f18;
        case 0x1a3f24u: goto label_1a3f24;
        case 0x1a3f30u: goto label_1a3f30;
        default: break;
    }

    ctx->pc = 0x1a3ee0u;

    // 0x1a3ee0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a3ee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a3ee4: 0x80c82d  daddu       $t9, $a0, $zero
    ctx->pc = 0x1a3ee4u;
    SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3ee8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a3ee8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a3eec: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a3eecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3ef0: 0xc068e20  jal         func_1A3880
    ctx->pc = 0x1A3EF0u;
    SET_GPR_U32(ctx, 31, 0x1A3EF8u);
    ctx->pc = 0x1A3EF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3EF0u;
            // 0x1a3ef4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3880u;
    if (runtime->hasFunction(0x1A3880u)) {
        auto targetFn = runtime->lookupFunction(0x1A3880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3EF8u; }
        if (ctx->pc != 0x1A3EF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3880_0x1a3880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3EF8u; }
        if (ctx->pc != 0x1A3EF8u) { return; }
    }
    ctx->pc = 0x1A3EF8u;
label_1a3ef8:
    // 0x1a3ef8: 0x40602d  daddu       $t4, $v0, $zero
    ctx->pc = 0x1a3ef8u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3efc: 0xc068da8  jal         func_1A36A0
    ctx->pc = 0x1A3EFCu;
    SET_GPR_U32(ctx, 31, 0x1A3F04u);
    ctx->pc = 0x1A3F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3EFCu;
            // 0x1a3f00: 0x320202d  daddu       $a0, $t9, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A36A0u;
    if (runtime->hasFunction(0x1A36A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A36A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3F04u; }
        if (ctx->pc != 0x1A3F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A36A0_0x1a36a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3F04u; }
        if (ctx->pc != 0x1A3F04u) { return; }
    }
    ctx->pc = 0x1A3F04u;
label_1a3f04:
    // 0x1a3f04: 0x40702d  daddu       $t6, $v0, $zero
    ctx->pc = 0x1a3f04u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3f08: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1A3F08u;
    {
        const bool branch_taken_0x1a3f08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3F0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3F08u;
            // 0x1a3f0c: 0xc02d  daddu       $t8, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3f08) {
            ctx->pc = 0x1A3F54u;
            goto label_1a3f54;
        }
    }
    ctx->pc = 0x1A3F10u;
label_1a3f10:
    // 0x1a3f10: 0xc068dd8  jal         func_1A3760
    ctx->pc = 0x1A3F10u;
    SET_GPR_U32(ctx, 31, 0x1A3F18u);
    ctx->pc = 0x1A3F14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3F10u;
            // 0x1a3f14: 0x300282d  daddu       $a1, $t8, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 24) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3760u;
    if (runtime->hasFunction(0x1A3760u)) {
        auto targetFn = runtime->lookupFunction(0x1A3760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3F18u; }
        if (ctx->pc != 0x1A3F18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3760_0x1a3760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3F18u; }
        if (ctx->pc != 0x1A3F18u) { return; }
    }
    ctx->pc = 0x1A3F18u;
label_1a3f18:
    // 0x1a3f18: 0x40682d  daddu       $t5, $v0, $zero
    ctx->pc = 0x1a3f18u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3f1c: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1A3F1Cu;
    {
        const bool branch_taken_0x1a3f1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3F1Cu;
            // 0x1a3f20: 0x782d  daddu       $t7, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3f1c) {
            ctx->pc = 0x1A3F44u;
            goto label_1a3f44;
        }
    }
    ctx->pc = 0x1A3F24u;
label_1a3f24:
    // 0x1a3f24: 0x300282d  daddu       $a1, $t8, $zero
    ctx->pc = 0x1a3f24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 24) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3f28: 0xc068e20  jal         func_1A3880
    ctx->pc = 0x1A3F28u;
    SET_GPR_U32(ctx, 31, 0x1A3F30u);
    ctx->pc = 0x1A3F2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3F28u;
            // 0x1a3f2c: 0x1e0302d  daddu       $a2, $t7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 15) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3880u;
    if (runtime->hasFunction(0x1A3880u)) {
        auto targetFn = runtime->lookupFunction(0x1A3880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3F30u; }
        if (ctx->pc != 0x1A3F30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3880_0x1a3880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3F30u; }
        if (ctx->pc != 0x1A3F30u) { return; }
    }
    ctx->pc = 0x1A3F30u;
label_1a3f30:
    // 0x1a3f30: 0x11820003  beq         $t4, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3F30u;
    {
        const bool branch_taken_0x1a3f30 = (GPR_U64(ctx, 12) == GPR_U64(ctx, 2));
        if (branch_taken_0x1a3f30) {
            ctx->pc = 0x1A3F40u;
            goto label_1a3f40;
        }
    }
    ctx->pc = 0x1A3F38u;
    // 0x1a3f38: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1A3F38u;
    {
        const bool branch_taken_0x1a3f38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3F3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3F38u;
            // 0x1a3f3c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3f38) {
            ctx->pc = 0x1A3F64u;
            goto label_1a3f64;
        }
    }
    ctx->pc = 0x1A3F40u;
label_1a3f40:
    // 0x1a3f40: 0x25ef0001  addiu       $t7, $t7, 0x1
    ctx->pc = 0x1a3f40u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 1));
label_1a3f44:
    // 0x1a3f44: 0x1ed102a  slt         $v0, $t7, $t5
    ctx->pc = 0x1a3f44u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 15) < (int64_t)GPR_S64(ctx, 13)) ? 1 : 0);
    // 0x1a3f48: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1A3F48u;
    {
        const bool branch_taken_0x1a3f48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3F48u;
            // 0x1a3f4c: 0x320202d  daddu       $a0, $t9, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3f48) {
            ctx->pc = 0x1A3F24u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3f24;
        }
    }
    ctx->pc = 0x1A3F50u;
    // 0x1a3f50: 0x27180001  addiu       $t8, $t8, 0x1
    ctx->pc = 0x1a3f50u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 1));
label_1a3f54:
    // 0x1a3f54: 0x30e102a  slt         $v0, $t8, $t6
    ctx->pc = 0x1a3f54u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 24) < (int64_t)GPR_S64(ctx, 14)) ? 1 : 0);
    // 0x1a3f58: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1A3F58u;
    {
        const bool branch_taken_0x1a3f58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3F5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3F58u;
            // 0x1a3f5c: 0x320202d  daddu       $a0, $t9, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3f58) {
            ctx->pc = 0x1A3F10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3f10;
        }
    }
    ctx->pc = 0x1A3F60u;
    // 0x1a3f60: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a3f60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a3f64:
    // 0x1a3f64: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a3f64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3f68: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3F68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3F68u;
            // 0x1a3f6c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3EF8u: goto label_1a3ef8;
            case 0x1A3F04u: goto label_1a3f04;
            case 0x1A3F10u: goto label_1a3f10;
            case 0x1A3F18u: goto label_1a3f18;
            case 0x1A3F24u: goto label_1a3f24;
            case 0x1A3F30u: goto label_1a3f30;
            case 0x1A3F40u: goto label_1a3f40;
            case 0x1A3F44u: goto label_1a3f44;
            case 0x1A3F54u: goto label_1a3f54;
            case 0x1A3F64u: goto label_1a3f64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3F70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
