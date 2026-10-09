#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100648
// Address: 0x100648 - 0x1006e8
void sub_00100648_0x100648(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100648_0x100648");
#endif

    switch (ctx->pc) {
        case 0x100678u: goto label_100678;
        case 0x100690u: goto label_100690;
        case 0x10069cu: goto label_10069c;
        case 0x1006a8u: goto label_1006a8;
        case 0x1006b0u: goto label_1006b0;
        case 0x1006b8u: goto label_1006b8;
        case 0x1006c8u: goto label_1006c8;
        default: break;
    }

    ctx->pc = 0x100648u;

    // 0x100648: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100648u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x10064c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10064cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x100650: 0x8c437914  lw          $v1, 0x7914($v0)
    ctx->pc = 0x100650u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 30996)));
    // 0x100654: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x100654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x100658: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x100658u;
    {
        const bool branch_taken_0x100658 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10065Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100658u;
            // 0x10065c: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100658) {
            ctx->pc = 0x100680u;
            goto label_100680;
        }
    }
    ctx->pc = 0x100660u;
    // 0x100660: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x100660u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x100664: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x100664u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x100668: 0xac627958  sw          $v0, 0x7958($v1)
    ctx->pc = 0x100668u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 31064), GPR_U32(ctx, 2));
    // 0x10066c: 0x3c100020  lui         $s0, 0x20
    ctx->pc = 0x10066cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32 << 16));
    // 0x100670: 0xc045190  jal         func_114640
    ctx->pc = 0x100670u;
    SET_GPR_U32(ctx, 31, 0x100678u);
    ctx->pc = 0x100674u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100670u;
            // 0x100674: 0x8e047920  lw          $a0, 0x7920($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31008)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100678u; }
        if (ctx->pc != 0x100678u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100678u; }
        if (ctx->pc != 0x100678u) { return; }
    }
    ctx->pc = 0x100678u;
label_100678:
    // 0x100678: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x100678u;
    {
        const bool branch_taken_0x100678 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10067Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100678u;
            // 0x10067c: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100678) {
            ctx->pc = 0x100688u;
            goto label_100688;
        }
    }
    ctx->pc = 0x100680u;
label_100680:
    // 0x100680: 0x3c100020  lui         $s0, 0x20
    ctx->pc = 0x100680u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32 << 16));
    // 0x100684: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100684u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
label_100688:
    // 0x100688: 0xc04518c  jal         func_114630
    ctx->pc = 0x100688u;
    SET_GPR_U32(ctx, 31, 0x100690u);
    ctx->pc = 0x10068Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100688u;
            // 0x10068c: 0x8c447928  lw          $a0, 0x7928($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31016)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100690u; }
        if (ctx->pc != 0x100690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100690u; }
        if (ctx->pc != 0x100690u) { return; }
    }
    ctx->pc = 0x100690u;
label_100690:
    // 0x100690: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x100690u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x100694: 0xc04518c  jal         func_114630
    ctx->pc = 0x100694u;
    SET_GPR_U32(ctx, 31, 0x10069Cu);
    ctx->pc = 0x100698u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100694u;
            // 0x100698: 0x8c64792c  lw          $a0, 0x792C($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 31020)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10069Cu; }
        if (ctx->pc != 0x10069Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10069Cu; }
        if (ctx->pc != 0x10069Cu) { return; }
    }
    ctx->pc = 0x10069Cu;
label_10069c:
    // 0x10069c: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x10069cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x1006a0: 0xc04518c  jal         func_114630
    ctx->pc = 0x1006A0u;
    SET_GPR_U32(ctx, 31, 0x1006A8u);
    ctx->pc = 0x1006A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1006A0u;
            // 0x1006a4: 0x8c647930  lw          $a0, 0x7930($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 31024)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1006A8u; }
        if (ctx->pc != 0x1006A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1006A8u; }
        if (ctx->pc != 0x1006A8u) { return; }
    }
    ctx->pc = 0x1006A8u;
label_1006a8:
    // 0x1006a8: 0xc04518c  jal         func_114630
    ctx->pc = 0x1006A8u;
    SET_GPR_U32(ctx, 31, 0x1006B0u);
    ctx->pc = 0x1006ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1006A8u;
            // 0x1006ac: 0x8e047920  lw          $a0, 0x7920($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31008)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1006B0u; }
        if (ctx->pc != 0x1006B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1006B0u; }
        if (ctx->pc != 0x1006B0u) { return; }
    }
    ctx->pc = 0x1006B0u;
label_1006b0:
    // 0x1006b0: 0xc047598  jal         func_11D660
    ctx->pc = 0x1006B0u;
    SET_GPR_U32(ctx, 31, 0x1006B8u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1006B8u; }
        if (ctx->pc != 0x1006B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1006B8u; }
        if (ctx->pc != 0x1006B8u) { return; }
    }
    ctx->pc = 0x1006B8u;
label_1006b8:
    // 0x1006b8: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x1006b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x1006bc: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1006bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1006c0: 0xc045b20  jal         func_116C80
    ctx->pc = 0x1006C0u;
    SET_GPR_U32(ctx, 31, 0x1006C8u);
    ctx->pc = 0x1006C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1006C0u;
            // 0x1006c4: 0x34840012  ori         $a0, $a0, 0x12 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)18);
        ctx->in_delay_slot = false;
    ctx->pc = 0x116C80u;
    if (runtime->hasFunction(0x116C80u)) {
        auto targetFn = runtime->lookupFunction(0x116C80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1006C8u; }
        if (ctx->pc != 0x1006C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116C80_0x116c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1006C8u; }
        if (ctx->pc != 0x1006C8u) { return; }
    }
    ctx->pc = 0x1006C8u;
label_1006c8:
    // 0x1006c8: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1006C8u;
    {
        const bool branch_taken_0x1006c8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1006CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1006C8u;
            // 0x1006cc: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1006c8) {
            ctx->pc = 0x1006DCu;
            goto label_1006dc;
        }
    }
    ctx->pc = 0x1006D0u;
    // 0x1006d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1006d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1006d4: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x1006D4u;
    ctx->pc = 0x1006D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1006D4u;
            // 0x1006d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1006DCu;
label_1006dc:
    // 0x1006dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1006dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1006e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1006E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1006E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1006E0u;
            // 0x1006e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100678u: goto label_100678;
            case 0x100680u: goto label_100680;
            case 0x100688u: goto label_100688;
            case 0x100690u: goto label_100690;
            case 0x10069Cu: goto label_10069c;
            case 0x1006A8u: goto label_1006a8;
            case 0x1006B0u: goto label_1006b0;
            case 0x1006B8u: goto label_1006b8;
            case 0x1006C8u: goto label_1006c8;
            case 0x1006DCu: goto label_1006dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1006E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
