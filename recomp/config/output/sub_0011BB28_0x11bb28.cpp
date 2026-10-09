#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011BB28
// Address: 0x11bb28 - 0x11bb98
void sub_0011BB28_0x11bb28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011BB28_0x11bb28");
#endif

    switch (ctx->pc) {
        case 0x11bb78u: goto label_11bb78;
        default: break;
    }

    ctx->pc = 0x11bb28u;

    // 0x11bb28: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11bb28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11bb2c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11bb2cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11bb30: 0x8c439df8  lw          $v1, -0x6208($v0)
    ctx->pc = 0x11bb30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942200)));
    // 0x11bb34: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11bb34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11bb38: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BB38u;
    {
        const bool branch_taken_0x11bb38 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x11BB3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB38u;
            // 0x11bb3c: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bb38) {
            ctx->pc = 0x11BB48u;
            goto label_11bb48;
        }
    }
    ctx->pc = 0x11BB40u;
    // 0x11bb40: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x11BB40u;
    {
        const bool branch_taken_0x11bb40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BB44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB40u;
            // 0x11bb44: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bb40) {
            ctx->pc = 0x11BB88u;
            goto label_11bb88;
        }
    }
    ctx->pc = 0x11BB48u;
label_11bb48:
    // 0x11bb48: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11bb48u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11bb4c: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11bb4cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11bb50: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11bb50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11bb54: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11bb54u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11bb58: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x11bb58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x11bb5c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11bb5cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bb60: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x11bb60u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bb64: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x11bb64u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bb68: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11bb68u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11bb6c: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11bb6cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bb70: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11BB70u;
    SET_GPR_U32(ctx, 31, 0x11BB78u);
    ctx->pc = 0x11BB74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB70u;
            // 0x11bb74: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BB78u; }
        if (ctx->pc != 0x11BB78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BB78u; }
        if (ctx->pc != 0x11BB78u) { return; }
    }
    ctx->pc = 0x11BB78u;
label_11bb78:
    // 0x11bb78: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BB78u;
    {
        const bool branch_taken_0x11bb78 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11bb78) {
            ctx->pc = 0x11BB7Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB78u;
            // 0x11bb7c: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BB88u;
            goto label_11bb88;
        }
    }
    ctx->pc = 0x11BB80u;
    // 0x11bb80: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11bb80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11bb84: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11bb84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11bb88:
    // 0x11bb88: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11bb88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11bb8c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11bb8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11bb90: 0x3e00008  jr          $ra
    ctx->pc = 0x11BB90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BB94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB90u;
            // 0x11bb94: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BB48u: goto label_11bb48;
            case 0x11BB78u: goto label_11bb78;
            case 0x11BB88u: goto label_11bb88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BB98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
