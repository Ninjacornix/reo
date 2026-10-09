#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015DEA8
// Address: 0x15dea8 - 0x15df48
void sub_0015DEA8_0x15dea8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015DEA8_0x15dea8");
#endif

    switch (ctx->pc) {
        case 0x15dee8u: goto label_15dee8;
        case 0x15df14u: goto label_15df14;
        case 0x15df2cu: goto label_15df2c;
        case 0x15df34u: goto label_15df34;
        default: break;
    }

    ctx->pc = 0x15dea8u;

    // 0x15dea8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15dea8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15deac: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15deacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x15deb0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x15deb0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15deb4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15deb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15deb8: 0x262300b4  addiu       $v1, $s1, 0xB4
    ctx->pc = 0x15deb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 180));
    // 0x15debc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x15debcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15dec0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x15dec0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15dec4: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x15dec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x15dec8: 0x5044001b  beql        $v0, $a0, . + 4 + (0x1B << 2)
    ctx->pc = 0x15DEC8u;
    {
        const bool branch_taken_0x15dec8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x15dec8) {
            ctx->pc = 0x15DECCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15DEC8u;
            // 0x15decc: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15DF38u;
            goto label_15df38;
        }
    }
    ctx->pc = 0x15DED0u;
    // 0x15ded0: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x15ded0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x15ded4: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15ded4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ded8: 0xac600004  sw          $zero, 0x4($v1)
    ctx->pc = 0x15ded8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
    // 0x15dedc: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x15dedcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x15dee0: 0xc05d668  jal         func_1759A0
    ctx->pc = 0x15DEE0u;
    SET_GPR_U32(ctx, 31, 0x15DEE8u);
    ctx->pc = 0x15DEE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DEE0u;
            // 0x15dee4: 0x8e240040  lw          $a0, 0x40($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1759A0u;
    if (runtime->hasFunction(0x1759A0u)) {
        auto targetFn = runtime->lookupFunction(0x1759A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DEE8u; }
        if (ctx->pc != 0x15DEE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001759A0_0x1759a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DEE8u; }
        if (ctx->pc != 0x15DEE8u) { return; }
    }
    ctx->pc = 0x15DEE8u;
label_15dee8:
    // 0x15dee8: 0x54400013  bnel        $v0, $zero, . + 4 + (0x13 << 2)
    ctx->pc = 0x15DEE8u;
    {
        const bool branch_taken_0x15dee8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15dee8) {
            ctx->pc = 0x15DEECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15DEE8u;
            // 0x15deec: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15DF38u;
            goto label_15df38;
        }
    }
    ctx->pc = 0x15DEF0u;
    // 0x15def0: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x15def0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15def4: 0x2ca20800  sltiu       $v0, $a1, 0x800
    ctx->pc = 0x15def4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)2048) ? 1 : 0);
    // 0x15def8: 0x5440000f  bnel        $v0, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x15DEF8u;
    {
        const bool branch_taken_0x15def8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15def8) {
            ctx->pc = 0x15DEFCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15DEF8u;
            // 0x15defc: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15DF38u;
            goto label_15df38;
        }
    }
    ctx->pc = 0x15DF00u;
    // 0x15df00: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x15df00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15df04: 0x5080000c  beql        $a0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x15DF04u;
    {
        const bool branch_taken_0x15df04 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x15df04) {
            ctx->pc = 0x15DF08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15DF04u;
            // 0x15df08: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15DF38u;
            goto label_15df38;
        }
    }
    ctx->pc = 0x15DF0Cu;
    // 0x15df0c: 0xc05e43c  jal         func_1790F0
    ctx->pc = 0x15DF0Cu;
    SET_GPR_U32(ctx, 31, 0x15DF14u);
    ctx->pc = 0x1790F0u;
    if (runtime->hasFunction(0x1790F0u)) {
        auto targetFn = runtime->lookupFunction(0x1790F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DF14u; }
        if (ctx->pc != 0x15DF14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001790F0_0x1790f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DF14u; }
        if (ctx->pc != 0x15DF14u) { return; }
    }
    ctx->pc = 0x15DF14u;
label_15df14:
    // 0x15df14: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15df14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15df18: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15df18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15df1c: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x15DF1Cu;
    {
        const bool branch_taken_0x15df1c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DF20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DF1Cu;
            // 0x15df20: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15df1c) {
            ctx->pc = 0x15DF34u;
            goto label_15df34;
        }
    }
    ctx->pc = 0x15DF24u;
    // 0x15df24: 0xc0577d2  jal         func_15DF48
    ctx->pc = 0x15DF24u;
    SET_GPR_U32(ctx, 31, 0x15DF2Cu);
    ctx->pc = 0x15DF48u;
    if (runtime->hasFunction(0x15DF48u)) {
        auto targetFn = runtime->lookupFunction(0x15DF48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DF2Cu; }
        if (ctx->pc != 0x15DF2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015DF48_0x15df48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DF2Cu; }
        if (ctx->pc != 0x15DF2Cu) { return; }
    }
    ctx->pc = 0x15DF2Cu;
label_15df2c:
    // 0x15df2c: 0xc05e46e  jal         func_1791B8
    ctx->pc = 0x15DF2Cu;
    SET_GPR_U32(ctx, 31, 0x15DF34u);
    ctx->pc = 0x15DF30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DF2Cu;
            // 0x15df30: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1791B8u;
    if (runtime->hasFunction(0x1791B8u)) {
        auto targetFn = runtime->lookupFunction(0x1791B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DF34u; }
        if (ctx->pc != 0x15DF34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001791B8_0x1791b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DF34u; }
        if (ctx->pc != 0x15DF34u) { return; }
    }
    ctx->pc = 0x15DF34u;
label_15df34:
    // 0x15df34: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15df34u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_15df38:
    // 0x15df38: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15df38u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15df3c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15df3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15df40: 0x3e00008  jr          $ra
    ctx->pc = 0x15DF40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15DF44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DF40u;
            // 0x15df44: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15DEE8u: goto label_15dee8;
            case 0x15DF14u: goto label_15df14;
            case 0x15DF2Cu: goto label_15df2c;
            case 0x15DF34u: goto label_15df34;
            case 0x15DF38u: goto label_15df38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15DF48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
