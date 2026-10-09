#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C9F8
// Address: 0x11c9f8 - 0x11cad4
void sub_0011C9F8_0x11c9f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C9F8_0x11c9f8");
#endif

    switch (ctx->pc) {
        case 0x11ca1cu: goto label_11ca1c;
        case 0x11caa4u: goto label_11caa4;
        default: break;
    }

    ctx->pc = 0x11c9f8u;

    // 0x11c9f8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11c9f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11c9fc: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x11c9fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x11ca00: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x11ca00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x11ca04: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x11ca04u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ca08: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x11ca08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11ca0c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x11ca0cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ca10: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x11ca10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11ca14: 0xc046f5e  jal         func_11BD78
    ctx->pc = 0x11CA14u;
    SET_GPR_U32(ctx, 31, 0x11CA1Cu);
    ctx->pc = 0x11CA18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA14u;
            // 0x11ca18: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BD78u;
    if (runtime->hasFunction(0x11BD78u)) {
        auto targetFn = runtime->lookupFunction(0x11BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CA1Cu; }
        if (ctx->pc != 0x11CA1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BD78_0x11bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CA1Cu; }
        if (ctx->pc != 0x11CA1Cu) { return; }
    }
    ctx->pc = 0x11CA1Cu;
label_11ca1c:
    // 0x11ca1c: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11CA1Cu;
    {
        const bool branch_taken_0x11ca1c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11CA20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA1Cu;
            // 0x11ca20: 0x3c070026  lui         $a3, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca1c) {
            ctx->pc = 0x11CA2Cu;
            goto label_11ca2c;
        }
    }
    ctx->pc = 0x11CA24u;
    // 0x11ca24: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x11CA24u;
    {
        const bool branch_taken_0x11ca24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CA28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA24u;
            // 0x11ca28: 0x3c02ffff  lui         $v0, 0xFFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca24) {
            ctx->pc = 0x11CABCu;
            goto label_11cabc;
        }
    }
    ctx->pc = 0x11CA2Cu;
label_11ca2c:
    // 0x11ca2c: 0x24e3e400  addiu       $v1, $a3, -0x1C00
    ctx->pc = 0x11ca2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294960128));
    // 0x11ca30: 0xacf2e400  sw          $s2, -0x1C00($a3)
    ctx->pc = 0x11ca30u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294960128), GPR_U32(ctx, 18));
    // 0x11ca34: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11CA34u;
    {
        const bool branch_taken_0x11ca34 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x11CA38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA34u;
            // 0x11ca38: 0xac700004  sw          $s0, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca34) {
            ctx->pc = 0x11CA48u;
            goto label_11ca48;
        }
    }
    ctx->pc = 0x11CA3Cu;
    // 0x11ca3c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x11ca3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11ca40: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x11CA40u;
    {
        const bool branch_taken_0x11ca40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CA44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA40u;
            // 0x11ca44: 0xa0620008  sb          $v0, 0x8($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 8), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca40) {
            ctx->pc = 0x11CA78u;
            goto label_11ca78;
        }
    }
    ctx->pc = 0x11CA48u;
label_11ca48:
    // 0x11ca48: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11ca48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11ca4c: 0x16020004  bne         $s0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11CA4Cu;
    {
        const bool branch_taken_0x11ca4c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x11CA50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA4Cu;
            // 0x11ca50: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca4c) {
            ctx->pc = 0x11CA60u;
            goto label_11ca60;
        }
    }
    ctx->pc = 0x11CA54u;
    // 0x11ca54: 0x96220000  lhu         $v0, 0x0($s1)
    ctx->pc = 0x11ca54u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11ca58: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x11CA58u;
    {
        const bool branch_taken_0x11ca58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA58u;
            // 0x11ca5c: 0xa4620008  sh          $v0, 0x8($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 8), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca58) {
            ctx->pc = 0x11CA78u;
            goto label_11ca78;
        }
    }
    ctx->pc = 0x11CA60u;
label_11ca60:
    // 0x11ca60: 0x52020004  beql        $s0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11CA60u;
    {
        const bool branch_taken_0x11ca60 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x11ca60) {
            ctx->pc = 0x11CA64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA60u;
            // 0x11ca64: 0x8e220000  lw          $v0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11CA74u;
            goto label_11ca74;
        }
    }
    ctx->pc = 0x11CA68u;
    // 0x11ca68: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11ca68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11ca6c: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x11CA6Cu;
    {
        const bool branch_taken_0x11ca6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CA70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA6Cu;
            // 0x11ca70: 0x3442fffe  ori         $v0, $v0, 0xFFFE (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65534);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca6c) {
            ctx->pc = 0x11CABCu;
            goto label_11cabc;
        }
    }
    ctx->pc = 0x11CA74u;
label_11ca74:
    // 0x11ca74: 0xac620008  sw          $v0, 0x8($v1)
    ctx->pc = 0x11ca74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
label_11ca78:
    // 0x11ca78: 0x24e7e400  addiu       $a3, $a3, -0x1C00
    ctx->pc = 0x11ca78u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294960128));
    // 0x11ca7c: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11ca7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11ca80: 0x2484e600  addiu       $a0, $a0, -0x1A00
    ctx->pc = 0x11ca80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294960640));
    // 0x11ca84: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11ca84u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11ca88: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x11ca88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x11ca8c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11ca8cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ca90: 0x24080020  addiu       $t0, $zero, 0x20
    ctx->pc = 0x11ca90u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x11ca94: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x11ca94u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ca98: 0x240a0010  addiu       $t2, $zero, 0x10
    ctx->pc = 0x11ca98u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x11ca9c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11CA9Cu;
    SET_GPR_U32(ctx, 31, 0x11CAA4u);
    ctx->pc = 0x11CAA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA9Cu;
            // 0x11caa0: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CAA4u; }
        if (ctx->pc != 0x11CAA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CAA4u; }
        if (ctx->pc != 0x11CAA4u) { return; }
    }
    ctx->pc = 0x11CAA4u;
label_11caa4:
    // 0x11caa4: 0x3c04fffe  lui         $a0, 0xFFFE
    ctx->pc = 0x11caa4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65534 << 16));
    // 0x11caa8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x11caa8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11caac: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x11caacu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x11cab0: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    ctx->pc = 0x11cab0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x11cab4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x11cab4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cab8: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x11cab8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
label_11cabc:
    // 0x11cabc: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11cabcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11cac0: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x11cac0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11cac4: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x11cac4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11cac8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11cac8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11cacc: 0x3e00008  jr          $ra
    ctx->pc = 0x11CACCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CAD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CACCu;
            // 0x11cad0: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CA1Cu: goto label_11ca1c;
            case 0x11CA2Cu: goto label_11ca2c;
            case 0x11CA48u: goto label_11ca48;
            case 0x11CA60u: goto label_11ca60;
            case 0x11CA74u: goto label_11ca74;
            case 0x11CA78u: goto label_11ca78;
            case 0x11CAA4u: goto label_11caa4;
            case 0x11CABCu: goto label_11cabc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CAD4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
