#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001725E0
// Address: 0x1725e0 - 0x1726f8
void sub_001725E0_0x1725e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001725E0_0x1725e0");
#endif

    switch (ctx->pc) {
        case 0x172624u: goto label_172624;
        case 0x172640u: goto label_172640;
        case 0x172670u: goto label_172670;
        case 0x172680u: goto label_172680;
        case 0x172690u: goto label_172690;
        case 0x1726a0u: goto label_1726a0;
        case 0x1726b0u: goto label_1726b0;
        case 0x1726c0u: goto label_1726c0;
        default: break;
    }

    ctx->pc = 0x1725e0u;

    // 0x1725e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1725e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1725e4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1725e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1725e8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1725e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1725ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1725ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1725f0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1725f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1725f4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1725f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1725f8: 0x8e300048  lw          $s0, 0x48($s1)
    ctx->pc = 0x1725f8u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x1725fc: 0x2602ffff  addiu       $v0, $s0, -0x1
    ctx->pc = 0x1725fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x172600: 0x2c420004  sltiu       $v0, $v0, 0x4
    ctx->pc = 0x172600u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x172604: 0x50400036  beql        $v0, $zero, . + 4 + (0x36 << 2)
    ctx->pc = 0x172604u;
    {
        const bool branch_taken_0x172604 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x172604) {
            ctx->pc = 0x172608u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172604u;
            // 0x172608: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1726E0u;
            goto label_1726e0;
        }
    }
    ctx->pc = 0x17260Cu;
    // 0x17260c: 0x8e220044  lw          $v0, 0x44($s1)
    ctx->pc = 0x17260cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x172610: 0x50400033  beql        $v0, $zero, . + 4 + (0x33 << 2)
    ctx->pc = 0x172610u;
    {
        const bool branch_taken_0x172610 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x172610) {
            ctx->pc = 0x172614u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172610u;
            // 0x172614: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1726E0u;
            goto label_1726e0;
        }
    }
    ctx->pc = 0x172618u;
    // 0x172618: 0xae200044  sw          $zero, 0x44($s1)
    ctx->pc = 0x172618u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 68), GPR_U32(ctx, 0));
    // 0x17261c: 0xc05fa1c  jal         func_17E870
    ctx->pc = 0x17261Cu;
    SET_GPR_U32(ctx, 31, 0x172624u);
    ctx->pc = 0x17E870u;
    if (runtime->hasFunction(0x17E870u)) {
        auto targetFn = runtime->lookupFunction(0x17E870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172624u; }
        if (ctx->pc != 0x172624u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E870_0x17e870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172624u; }
        if (ctx->pc != 0x172624u) { return; }
    }
    ctx->pc = 0x172624u;
label_172624:
    // 0x172624: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x172624u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172628: 0x2602fffe  addiu       $v0, $s0, -0x2
    ctx->pc = 0x172628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967294));
    // 0x17262c: 0x2c420003  sltiu       $v0, $v0, 0x3
    ctx->pc = 0x17262cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x172630: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x172630u;
    {
        const bool branch_taken_0x172630 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x172630) {
            ctx->pc = 0x172634u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172630u;
            // 0x172634: 0x8e300048  lw          $s0, 0x48($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172644u;
            goto label_172644;
        }
    }
    ctx->pc = 0x172638u;
    // 0x172638: 0xc05c9be  jal         func_1726F8
    ctx->pc = 0x172638u;
    SET_GPR_U32(ctx, 31, 0x172640u);
    ctx->pc = 0x17263Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172638u;
            // 0x17263c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1726F8u;
    if (runtime->hasFunction(0x1726F8u)) {
        auto targetFn = runtime->lookupFunction(0x1726F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172640u; }
        if (ctx->pc != 0x172640u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001726F8_0x1726f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172640u; }
        if (ctx->pc != 0x172640u) { return; }
    }
    ctx->pc = 0x172640u;
label_172640:
    // 0x172640: 0x8e300048  lw          $s0, 0x48($s1)
    ctx->pc = 0x172640u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
label_172644:
    // 0x172644: 0x2e020007  sltiu       $v0, $s0, 0x7
    ctx->pc = 0x172644u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)7) ? 1 : 0);
    // 0x172648: 0x5040001b  beql        $v0, $zero, . + 4 + (0x1B << 2)
    ctx->pc = 0x172648u;
    {
        const bool branch_taken_0x172648 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x172648) {
            ctx->pc = 0x17264Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172648u;
            // 0x17264c: 0xae300048  sw          $s0, 0x48($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 72), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1726B8u;
            goto label_1726b8;
        }
    }
    ctx->pc = 0x172650u;
    // 0x172650: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x172650u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x172654: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x172654u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x172658: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x172658u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17265c: 0x8c630ad0  lw          $v1, 0xAD0($v1)
    ctx->pc = 0x17265cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 2768)));
    // 0x172660: 0x600008  jr          $v1
    ctx->pc = 0x172660u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x172668u: goto label_172668;
            case 0x172678u: goto label_172678;
            case 0x172688u: goto label_172688;
            case 0x172698u: goto label_172698;
            case 0x1726A8u: goto label_1726a8;
            case 0x1726B4u: goto label_1726b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172668u;
label_172668:
    // 0x172668: 0xc05c9ce  jal         func_172738
    ctx->pc = 0x172668u;
    SET_GPR_U32(ctx, 31, 0x172670u);
    ctx->pc = 0x17266Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172668u;
            // 0x17266c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172738u;
    if (runtime->hasFunction(0x172738u)) {
        auto targetFn = runtime->lookupFunction(0x172738u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172670u; }
        if (ctx->pc != 0x172670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172738_0x172738(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172670u; }
        if (ctx->pc != 0x172670u) { return; }
    }
    ctx->pc = 0x172670u;
label_172670:
    // 0x172670: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x172670u;
    {
        const bool branch_taken_0x172670 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172670u;
            // 0x172674: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172670) {
            ctx->pc = 0x1726B4u;
            goto label_1726b4;
        }
    }
    ctx->pc = 0x172678u;
label_172678:
    // 0x172678: 0xc05c9da  jal         func_172768
    ctx->pc = 0x172678u;
    SET_GPR_U32(ctx, 31, 0x172680u);
    ctx->pc = 0x17267Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172678u;
            // 0x17267c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172768u;
    if (runtime->hasFunction(0x172768u)) {
        auto targetFn = runtime->lookupFunction(0x172768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172680u; }
        if (ctx->pc != 0x172680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172768_0x172768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172680u; }
        if (ctx->pc != 0x172680u) { return; }
    }
    ctx->pc = 0x172680u;
label_172680:
    // 0x172680: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x172680u;
    {
        const bool branch_taken_0x172680 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172680u;
            // 0x172684: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172680) {
            ctx->pc = 0x1726B4u;
            goto label_1726b4;
        }
    }
    ctx->pc = 0x172688u;
label_172688:
    // 0x172688: 0xc05cab2  jal         func_172AC8
    ctx->pc = 0x172688u;
    SET_GPR_U32(ctx, 31, 0x172690u);
    ctx->pc = 0x17268Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172688u;
            // 0x17268c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172AC8u;
    if (runtime->hasFunction(0x172AC8u)) {
        auto targetFn = runtime->lookupFunction(0x172AC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172690u; }
        if (ctx->pc != 0x172690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172AC8_0x172ac8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172690u; }
        if (ctx->pc != 0x172690u) { return; }
    }
    ctx->pc = 0x172690u;
label_172690:
    // 0x172690: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x172690u;
    {
        const bool branch_taken_0x172690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172690u;
            // 0x172694: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172690) {
            ctx->pc = 0x1726B4u;
            goto label_1726b4;
        }
    }
    ctx->pc = 0x172698u;
label_172698:
    // 0x172698: 0xc05cada  jal         func_172B68
    ctx->pc = 0x172698u;
    SET_GPR_U32(ctx, 31, 0x1726A0u);
    ctx->pc = 0x17269Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172698u;
            // 0x17269c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172B68u;
    if (runtime->hasFunction(0x172B68u)) {
        auto targetFn = runtime->lookupFunction(0x172B68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1726A0u; }
        if (ctx->pc != 0x1726A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172B68_0x172b68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1726A0u; }
        if (ctx->pc != 0x1726A0u) { return; }
    }
    ctx->pc = 0x1726A0u;
label_1726a0:
    // 0x1726a0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1726A0u;
    {
        const bool branch_taken_0x1726a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1726A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1726A0u;
            // 0x1726a4: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1726a0) {
            ctx->pc = 0x1726B4u;
            goto label_1726b4;
        }
    }
    ctx->pc = 0x1726A8u;
label_1726a8:
    // 0x1726a8: 0xc05caf6  jal         func_172BD8
    ctx->pc = 0x1726A8u;
    SET_GPR_U32(ctx, 31, 0x1726B0u);
    ctx->pc = 0x1726ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1726A8u;
            // 0x1726ac: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172BD8u;
    if (runtime->hasFunction(0x172BD8u)) {
        auto targetFn = runtime->lookupFunction(0x172BD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1726B0u; }
        if (ctx->pc != 0x1726B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172BD8_0x172bd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1726B0u; }
        if (ctx->pc != 0x1726B0u) { return; }
    }
    ctx->pc = 0x1726B0u;
label_1726b0:
    // 0x1726b0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1726b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1726b4:
    // 0x1726b4: 0xae300048  sw          $s0, 0x48($s1)
    ctx->pc = 0x1726b4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 72), GPR_U32(ctx, 16));
label_1726b8:
    // 0x1726b8: 0xc05fa1c  jal         func_17E870
    ctx->pc = 0x1726B8u;
    SET_GPR_U32(ctx, 31, 0x1726C0u);
    ctx->pc = 0x1726BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1726B8u;
            // 0x1726bc: 0x26302b60  addiu       $s0, $s1, 0x2B60 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 11104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E870u;
    if (runtime->hasFunction(0x17E870u)) {
        auto targetFn = runtime->lookupFunction(0x17E870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1726C0u; }
        if (ctx->pc != 0x1726C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E870_0x17e870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1726C0u; }
        if (ctx->pc != 0x1726C0u) { return; }
    }
    ctx->pc = 0x1726C0u;
label_1726c0:
    // 0x1726c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1726c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1726c4: 0x52282f  dsubu       $a1, $v0, $s2
    ctx->pc = 0x1726c4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) - GPR_U64(ctx, 18));
    // 0x1726c8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1726c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1726cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1726ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1726d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1726d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1726d4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1726d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1726d8: 0x805dd1c  j           func_177470
    ctx->pc = 0x1726D8u;
    ctx->pc = 0x1726DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1726D8u;
            // 0x1726dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177470u;
    if (runtime->hasFunction(0x177470u)) {
        auto targetFn = runtime->lookupFunction(0x177470u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177470_0x177470(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1726E0u;
label_1726e0:
    // 0x1726e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1726e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1726e4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1726e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1726e8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1726e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1726ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1726ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1726F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1726ECu;
            // 0x1726f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x172624u: goto label_172624;
            case 0x172640u: goto label_172640;
            case 0x172644u: goto label_172644;
            case 0x172668u: goto label_172668;
            case 0x172670u: goto label_172670;
            case 0x172678u: goto label_172678;
            case 0x172680u: goto label_172680;
            case 0x172688u: goto label_172688;
            case 0x172690u: goto label_172690;
            case 0x172698u: goto label_172698;
            case 0x1726A0u: goto label_1726a0;
            case 0x1726A8u: goto label_1726a8;
            case 0x1726B0u: goto label_1726b0;
            case 0x1726B4u: goto label_1726b4;
            case 0x1726B8u: goto label_1726b8;
            case 0x1726C0u: goto label_1726c0;
            case 0x1726E0u: goto label_1726e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1726F4u;
    // 0x1726f4: 0x0  nop
    ctx->pc = 0x1726f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
