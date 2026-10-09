#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00105658
// Address: 0x105658 - 0x105734
void sub_00105658_0x105658(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00105658_0x105658");
#endif

    switch (ctx->pc) {
        case 0x105680u: goto label_105680;
        case 0x105694u: goto label_105694;
        case 0x1056b0u: goto label_1056b0;
        case 0x105718u: goto label_105718;
        default: break;
    }

    ctx->pc = 0x105658u;

    // 0x105658: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x105658u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x10565c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x10565cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x105660: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x105660u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105664: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x105664u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105668: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x105668u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10566c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x10566cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x105670: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x105670u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x105674: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x105674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x105678: 0xc041568  jal         func_1055A0
    ctx->pc = 0x105678u;
    SET_GPR_U32(ctx, 31, 0x105680u);
    ctx->pc = 0x10567Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105678u;
            // 0x10567c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1055A0u;
    if (runtime->hasFunction(0x1055A0u)) {
        auto targetFn = runtime->lookupFunction(0x1055A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105680u; }
        if (ctx->pc != 0x105680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001055A0_0x1055a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105680u; }
        if (ctx->pc != 0x105680u) { return; }
    }
    ctx->pc = 0x105680u;
label_105680:
    // 0x105680: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x105680u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105684: 0x12200025  beqz        $s1, . + 4 + (0x25 << 2)
    ctx->pc = 0x105684u;
    {
        const bool branch_taken_0x105684 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x105688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105684u;
            // 0x105688: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105684) {
            ctx->pc = 0x10571Cu;
            goto label_10571c;
        }
    }
    ctx->pc = 0x10568Cu;
    // 0x10568c: 0xc0414f6  jal         func_1053D8
    ctx->pc = 0x10568Cu;
    SET_GPR_U32(ctx, 31, 0x105694u);
    ctx->pc = 0x1053D8u;
    if (runtime->hasFunction(0x1053D8u)) {
        auto targetFn = runtime->lookupFunction(0x1053D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105694u; }
        if (ctx->pc != 0x105694u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001053D8_0x1053d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105694u; }
        if (ctx->pc != 0x105694u) { return; }
    }
    ctx->pc = 0x105694u;
label_105694:
    // 0x105694: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x105694u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105698: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x105698u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10569c: 0x1200001f  beqz        $s0, . + 4 + (0x1F << 2)
    ctx->pc = 0x10569Cu;
    {
        const bool branch_taken_0x10569c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1056A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10569Cu;
            // 0x1056a0: 0x240701b6  addiu       $a3, $zero, 0x1B6 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 438));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10569c) {
            ctx->pc = 0x10571Cu;
            goto label_10571c;
        }
    }
    ctx->pc = 0x1056A4u;
    // 0x1056a4: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x1056a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x1056a8: 0xc042384  jal         func_108E10
    ctx->pc = 0x1056A8u;
    SET_GPR_U32(ctx, 31, 0x1056B0u);
    ctx->pc = 0x1056ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1056A8u;
            // 0x1056ac: 0x8fa60000  lw          $a2, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108E10u;
    if (runtime->hasFunction(0x108E10u)) {
        auto targetFn = runtime->lookupFunction(0x108E10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1056B0u; }
        if (ctx->pc != 0x1056B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108E10_0x108e10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1056B0u; }
        if (ctx->pc != 0x1056B0u) { return; }
    }
    ctx->pc = 0x1056B0u;
label_1056b0:
    // 0x1056b0: 0x3c030011  lui         $v1, 0x11
    ctx->pc = 0x1056b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17 << 16));
    // 0x1056b4: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1056b4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1056b8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1056b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1056bc: 0x3c040011  lui         $a0, 0x11
    ctx->pc = 0x1056bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)17 << 16));
    // 0x1056c0: 0x3c050011  lui         $a1, 0x11
    ctx->pc = 0x1056c0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)17 << 16));
    // 0x1056c4: 0x3c060011  lui         $a2, 0x11
    ctx->pc = 0x1056c4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)17 << 16));
    // 0x1056c8: 0x2463a970  addiu       $v1, $v1, -0x5690
    ctx->pc = 0x1056c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294945136));
    // 0x1056cc: 0x2484a9d8  addiu       $a0, $a0, -0x5628
    ctx->pc = 0x1056ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294945240));
    // 0x1056d0: 0x24a5aa58  addiu       $a1, $a1, -0x55A8
    ctx->pc = 0x1056d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294945368));
    // 0x1056d4: 0x24c6aac0  addiu       $a2, $a2, -0x5540
    ctx->pc = 0x1056d4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294945472));
    // 0x1056d8: 0x4e10003  bgez        $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1056D8u;
    {
        const bool branch_taken_0x1056d8 = (GPR_S64(ctx, 7) >= 0);
        ctx->pc = 0x1056DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1056D8u;
            // 0x1056dc: 0x32280100  andi        $t0, $s1, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)256);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1056d8) {
            ctx->pc = 0x1056E8u;
            goto label_1056e8;
        }
    }
    ctx->pc = 0x1056E0u;
    // 0x1056e0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1056E0u;
    {
        const bool branch_taken_0x1056e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1056E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1056E0u;
            // 0x1056e4: 0xa600000c  sh          $zero, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1056e0) {
            ctx->pc = 0x10571Cu;
            goto label_10571c;
        }
    }
    ctx->pc = 0x1056E8u;
label_1056e8:
    // 0x1056e8: 0xa607000e  sh          $a3, 0xE($s0)
    ctx->pc = 0x1056e8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 14), (uint16_t)GPR_U32(ctx, 7));
    // 0x1056ec: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1056ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1056f0: 0xae040024  sw          $a0, 0x24($s0)
    ctx->pc = 0x1056f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 4));
    // 0x1056f4: 0xae050028  sw          $a1, 0x28($s0)
    ctx->pc = 0x1056f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 5));
    // 0x1056f8: 0xae06002c  sw          $a2, 0x2C($s0)
    ctx->pc = 0x1056f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 6));
    // 0x1056fc: 0xa611000c  sh          $s1, 0xC($s0)
    ctx->pc = 0x1056fcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 17));
    // 0x105700: 0x11000005  beqz        $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x105700u;
    {
        const bool branch_taken_0x105700 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        ctx->pc = 0x105704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105700u;
            // 0x105704: 0xae10001c  sw          $s0, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105700) {
            ctx->pc = 0x105718u;
            goto label_105718;
        }
    }
    ctx->pc = 0x105708u;
    // 0x105708: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x105708u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10570c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x10570cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105710: 0xc041750  jal         func_105D40
    ctx->pc = 0x105710u;
    SET_GPR_U32(ctx, 31, 0x105718u);
    ctx->pc = 0x105714u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105710u;
            // 0x105714: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105D40u;
    if (runtime->hasFunction(0x105D40u)) {
        auto targetFn = runtime->lookupFunction(0x105D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105718u; }
        if (ctx->pc != 0x105718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105D40_0x105d40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105718u; }
        if (ctx->pc != 0x105718u) { return; }
    }
    ctx->pc = 0x105718u;
label_105718:
    // 0x105718: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x105718u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_10571c:
    // 0x10571c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x10571cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x105720: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x105720u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x105724: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x105724u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x105728: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x105728u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x10572c: 0x3e00008  jr          $ra
    ctx->pc = 0x10572Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x105730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10572Cu;
            // 0x105730: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x105680u: goto label_105680;
            case 0x105694u: goto label_105694;
            case 0x1056B0u: goto label_1056b0;
            case 0x1056E8u: goto label_1056e8;
            case 0x105718u: goto label_105718;
            case 0x10571Cu: goto label_10571c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x105734u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
