#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011BC78
// Address: 0x11bc78 - 0x11bcf4
void sub_0011BC78_0x11bc78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011BC78_0x11bc78");
#endif

    switch (ctx->pc) {
        case 0x11bcd4u: goto label_11bcd4;
        default: break;
    }

    ctx->pc = 0x11bc78u;

    // 0x11bc78: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11bc78u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11bc7c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11bc7cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11bc80: 0x8c629df8  lw          $v0, -0x6208($v1)
    ctx->pc = 0x11bc80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942200)));
    // 0x11bc84: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x11bc84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bc88: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11bc88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11bc8c: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BC8Cu;
    {
        const bool branch_taken_0x11bc8c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11BC90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC8Cu;
            // 0x11bc90: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bc8c) {
            ctx->pc = 0x11BC9Cu;
            goto label_11bc9c;
        }
    }
    ctx->pc = 0x11BC94u;
    // 0x11bc94: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x11BC94u;
    {
        const bool branch_taken_0x11bc94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BC98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC94u;
            // 0x11bc98: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bc94) {
            ctx->pc = 0x11BCE4u;
            goto label_11bce4;
        }
    }
    ctx->pc = 0x11BC9Cu;
label_11bc9c:
    // 0x11bc9c: 0x3c070026  lui         $a3, 0x26
    ctx->pc = 0x11bc9cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)38 << 16));
    // 0x11bca0: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11bca0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11bca4: 0xace5e2c0  sw          $a1, -0x1D40($a3)
    ctx->pc = 0x11bca4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294959808), GPR_U32(ctx, 5));
    // 0x11bca8: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11bca8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11bcac: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11bcacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11bcb0: 0x24e7e2c0  addiu       $a3, $a3, -0x1D40
    ctx->pc = 0x11bcb0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294959808));
    // 0x11bcb4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11bcb4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11bcb8: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x11bcb8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x11bcbc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11bcbcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bcc0: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x11bcc0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bcc4: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11bcc4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11bcc8: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11bcc8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bccc: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11BCCCu;
    SET_GPR_U32(ctx, 31, 0x11BCD4u);
    ctx->pc = 0x11BCD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BCCCu;
            // 0x11bcd0: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BCD4u; }
        if (ctx->pc != 0x11BCD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BCD4u; }
        if (ctx->pc != 0x11BCD4u) { return; }
    }
    ctx->pc = 0x11BCD4u;
label_11bcd4:
    // 0x11bcd4: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BCD4u;
    {
        const bool branch_taken_0x11bcd4 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11bcd4) {
            ctx->pc = 0x11BCD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BCD4u;
            // 0x11bcd8: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BCE4u;
            goto label_11bce4;
        }
    }
    ctx->pc = 0x11BCDCu;
    // 0x11bcdc: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11bcdcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11bce0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11bce0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11bce4:
    // 0x11bce4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11bce4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11bce8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11bce8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11bcec: 0x3e00008  jr          $ra
    ctx->pc = 0x11BCECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BCF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BCECu;
            // 0x11bcf0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BC9Cu: goto label_11bc9c;
            case 0x11BCD4u: goto label_11bcd4;
            case 0x11BCE4u: goto label_11bce4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BCF4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
