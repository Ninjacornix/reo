#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011BCF8
// Address: 0x11bcf8 - 0x11bd74
void sub_0011BCF8_0x11bcf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011BCF8_0x11bcf8");
#endif

    switch (ctx->pc) {
        case 0x11bd54u: goto label_11bd54;
        default: break;
    }

    ctx->pc = 0x11bcf8u;

    // 0x11bcf8: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11bcf8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11bcfc: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11bcfcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11bd00: 0x8c629df8  lw          $v0, -0x6208($v1)
    ctx->pc = 0x11bd00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942200)));
    // 0x11bd04: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x11bd04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bd08: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11bd08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11bd0c: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BD0Cu;
    {
        const bool branch_taken_0x11bd0c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11BD10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BD0Cu;
            // 0x11bd10: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bd0c) {
            ctx->pc = 0x11BD1Cu;
            goto label_11bd1c;
        }
    }
    ctx->pc = 0x11BD14u;
    // 0x11bd14: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x11BD14u;
    {
        const bool branch_taken_0x11bd14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BD18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BD14u;
            // 0x11bd18: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bd14) {
            ctx->pc = 0x11BD64u;
            goto label_11bd64;
        }
    }
    ctx->pc = 0x11BD1Cu;
label_11bd1c:
    // 0x11bd1c: 0x3c070026  lui         $a3, 0x26
    ctx->pc = 0x11bd1cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)38 << 16));
    // 0x11bd20: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11bd20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11bd24: 0xace5e2c0  sw          $a1, -0x1D40($a3)
    ctx->pc = 0x11bd24u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294959808), GPR_U32(ctx, 5));
    // 0x11bd28: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11bd28u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11bd2c: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11bd2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11bd30: 0x24e7e2c0  addiu       $a3, $a3, -0x1D40
    ctx->pc = 0x11bd30u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294959808));
    // 0x11bd34: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11bd34u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11bd38: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x11bd38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x11bd3c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11bd3cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bd40: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x11bd40u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bd44: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11bd44u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11bd48: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11bd48u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bd4c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11BD4Cu;
    SET_GPR_U32(ctx, 31, 0x11BD54u);
    ctx->pc = 0x11BD50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BD4Cu;
            // 0x11bd50: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BD54u; }
        if (ctx->pc != 0x11BD54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BD54u; }
        if (ctx->pc != 0x11BD54u) { return; }
    }
    ctx->pc = 0x11BD54u;
label_11bd54:
    // 0x11bd54: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BD54u;
    {
        const bool branch_taken_0x11bd54 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11bd54) {
            ctx->pc = 0x11BD58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BD54u;
            // 0x11bd58: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BD64u;
            goto label_11bd64;
        }
    }
    ctx->pc = 0x11BD5Cu;
    // 0x11bd5c: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11bd5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11bd60: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11bd60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11bd64:
    // 0x11bd64: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11bd64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11bd68: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11bd68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11bd6c: 0x3e00008  jr          $ra
    ctx->pc = 0x11BD6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BD70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BD6Cu;
            // 0x11bd70: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BD1Cu: goto label_11bd1c;
            case 0x11BD54u: goto label_11bd54;
            case 0x11BD64u: goto label_11bd64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BD74u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
