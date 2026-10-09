#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011BB98
// Address: 0x11bb98 - 0x11bc08
void sub_0011BB98_0x11bb98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011BB98_0x11bb98");
#endif

    switch (ctx->pc) {
        case 0x11bbe8u: goto label_11bbe8;
        default: break;
    }

    ctx->pc = 0x11bb98u;

    // 0x11bb98: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11bb98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11bb9c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11bb9cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11bba0: 0x8c439df8  lw          $v1, -0x6208($v0)
    ctx->pc = 0x11bba0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942200)));
    // 0x11bba4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11bba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11bba8: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BBA8u;
    {
        const bool branch_taken_0x11bba8 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x11BBACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BBA8u;
            // 0x11bbac: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bba8) {
            ctx->pc = 0x11BBB8u;
            goto label_11bbb8;
        }
    }
    ctx->pc = 0x11BBB0u;
    // 0x11bbb0: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x11BBB0u;
    {
        const bool branch_taken_0x11bbb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BBB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BBB0u;
            // 0x11bbb4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bbb0) {
            ctx->pc = 0x11BBF8u;
            goto label_11bbf8;
        }
    }
    ctx->pc = 0x11BBB8u;
label_11bbb8:
    // 0x11bbb8: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11bbb8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11bbbc: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11bbbcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11bbc0: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11bbc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11bbc4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11bbc4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11bbc8: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x11bbc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x11bbcc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11bbccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bbd0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x11bbd0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bbd4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x11bbd4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bbd8: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11bbd8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11bbdc: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11bbdcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bbe0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11BBE0u;
    SET_GPR_U32(ctx, 31, 0x11BBE8u);
    ctx->pc = 0x11BBE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BBE0u;
            // 0x11bbe4: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BBE8u; }
        if (ctx->pc != 0x11BBE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BBE8u; }
        if (ctx->pc != 0x11BBE8u) { return; }
    }
    ctx->pc = 0x11BBE8u;
label_11bbe8:
    // 0x11bbe8: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BBE8u;
    {
        const bool branch_taken_0x11bbe8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11bbe8) {
            ctx->pc = 0x11BBECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BBE8u;
            // 0x11bbec: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BBF8u;
            goto label_11bbf8;
        }
    }
    ctx->pc = 0x11BBF0u;
    // 0x11bbf0: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11bbf0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11bbf4: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11bbf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11bbf8:
    // 0x11bbf8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11bbf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11bbfc: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11bbfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11bc00: 0x3e00008  jr          $ra
    ctx->pc = 0x11BC00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BC04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC00u;
            // 0x11bc04: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BBB8u: goto label_11bbb8;
            case 0x11BBE8u: goto label_11bbe8;
            case 0x11BBF8u: goto label_11bbf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BC08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
