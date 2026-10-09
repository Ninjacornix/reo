#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001186B0
// Address: 0x1186b0 - 0x1187a0
void sub_001186B0_0x1186b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001186B0_0x1186b0");
#endif

    switch (ctx->pc) {
        case 0x1186e4u: goto label_1186e4;
        case 0x1186fcu: goto label_1186fc;
        case 0x118704u: goto label_118704;
        case 0x118728u: goto label_118728;
        case 0x118730u: goto label_118730;
        case 0x118780u: goto label_118780;
        default: break;
    }

    ctx->pc = 0x1186b0u;

    // 0x1186b0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1186b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1186b4: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x1186b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x1186b8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1186b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1186bc: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1186bcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1186c0: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x1186c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x1186c4: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1186c4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1186c8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1186c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1186cc: 0x2404001b  addiu       $a0, $zero, 0x1B
    ctx->pc = 0x1186ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 27));
    // 0x1186d0: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1186d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1186d4: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x1186d4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x1186d8: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1186d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1186dc: 0xc04619c  jal         func_118670
    ctx->pc = 0x1186DCu;
    SET_GPR_U32(ctx, 31, 0x1186E4u);
    ctx->pc = 0x1186E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1186DCu;
            // 0x1186e0: 0x2614e1c0  addiu       $s4, $s0, -0x1E40 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959552));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1186E4u; }
        if (ctx->pc != 0x1186E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1186E4u; }
        if (ctx->pc != 0x1186E4u) { return; }
    }
    ctx->pc = 0x1186E4u;
label_1186e4:
    // 0x1186e4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1186e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1186e8: 0x8c439ddc  lw          $v1, -0x6224($v0)
    ctx->pc = 0x1186e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942172)));
    // 0x1186ec: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1186ECu;
    {
        const bool branch_taken_0x1186ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1186ec) {
            ctx->pc = 0x1186FCu;
            goto label_1186fc;
        }
    }
    ctx->pc = 0x1186F4u;
    // 0x1186f4: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x1186F4u;
    SET_GPR_U32(ctx, 31, 0x1186FCu);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1186FCu; }
        if (ctx->pc != 0x1186FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1186FCu; }
        if (ctx->pc != 0x1186FCu) { return; }
    }
    ctx->pc = 0x1186FCu;
label_1186fc:
    // 0x1186fc: 0xc047598  jal         func_11D660
    ctx->pc = 0x1186FCu;
    SET_GPR_U32(ctx, 31, 0x118704u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118704u; }
        if (ctx->pc != 0x118704u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118704u; }
        if (ctx->pc != 0x118704u) { return; }
    }
    ctx->pc = 0x118704u;
label_118704:
    // 0x118704: 0x8e11e1c0  lw          $s1, -0x1E40($s0)
    ctx->pc = 0x118704u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959552)));
    // 0x118708: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x118708u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11870c: 0xae920004  sw          $s2, 0x4($s4)
    ctx->pc = 0x11870cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 4), GPR_U32(ctx, 18));
    // 0x118710: 0xae13e1c0  sw          $s3, -0x1E40($s0)
    ctx->pc = 0x118710u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294959552), GPR_U32(ctx, 19));
    // 0x118714: 0xac7ce200  sw          $gp, -0x1E00($v1)
    ctx->pc = 0x118714u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294959616), GPR_U32(ctx, 28));
    // 0x118718: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x118718u;
    {
        const bool branch_taken_0x118718 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x118718) {
            ctx->pc = 0x118728u;
            goto label_118728;
        }
    }
    ctx->pc = 0x118720u;
    // 0x118720: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x118720u;
    SET_GPR_U32(ctx, 31, 0x118728u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118728u; }
        if (ctx->pc != 0x118728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118728u; }
        if (ctx->pc != 0x118728u) { return; }
    }
    ctx->pc = 0x118728u;
label_118728:
    // 0x118728: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x118728u;
    SET_GPR_U32(ctx, 31, 0x118730u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118730u; }
        if (ctx->pc != 0x118730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118730u; }
        if (ctx->pc != 0x118730u) { return; }
    }
    ctx->pc = 0x118730u;
label_118730:
    // 0x118730: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x118730u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118734: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x118734u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x118738: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x118738u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11873c: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11873cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x118740: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x118740u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x118744: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x118744u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x118748: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x118748u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11874c: 0x3e00008  jr          $ra
    ctx->pc = 0x11874Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11874Cu;
            // 0x118750: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1186E4u: goto label_1186e4;
            case 0x1186FCu: goto label_1186fc;
            case 0x118704u: goto label_118704;
            case 0x118728u: goto label_118728;
            case 0x118730u: goto label_118730;
            case 0x118780u: goto label_118780;
            case 0x118784u: goto label_118784;
            default: break;
        }
        return;
    }
    ctx->pc = 0x118754u;
    // 0x118754: 0x0  nop
    ctx->pc = 0x118754u;
    // NOP
    // 0x118758: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x118758u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11875c: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x11875cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x118760: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x118760u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x118764: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x118764u;
    {
        const bool branch_taken_0x118764 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x118768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118764u;
            // 0x118768: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118764) {
            ctx->pc = 0x118784u;
            goto label_118784;
        }
    }
    ctx->pc = 0x11876Cu;
    // 0x11876c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11876cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x118770: 0x380802d  daddu       $s0, $gp, $zero
    ctx->pc = 0x118770u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118774: 0x8c5ce200  lw          $gp, -0x1E00($v0)
    ctx->pc = 0x118774u;
    SET_GPR_S32(ctx, 28, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294959616)));
    // 0x118778: 0x60f809  jalr        $v1
    ctx->pc = 0x118778u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x118780u);
        ctx->pc = 0x11877Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118778u;
            // 0x11877c: 0x8ca40004  lw          $a0, 0x4($a1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x118780u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1186E4u: goto label_1186e4;
            case 0x1186FCu: goto label_1186fc;
            case 0x118704u: goto label_118704;
            case 0x118728u: goto label_118728;
            case 0x118730u: goto label_118730;
            case 0x118780u: goto label_118780;
            case 0x118784u: goto label_118784;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x118780u; }
            if (ctx->pc != 0x118780u) { return; }
        }
        }
    }
    ctx->pc = 0x118780u;
label_118780:
    // 0x118780: 0x200e02d  daddu       $gp, $s0, $zero
    ctx->pc = 0x118780u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_118784:
    // 0x118784: 0xf  sync
    ctx->pc = 0x118784u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x118788: 0x42000038  ei
    ctx->pc = 0x118788u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x11878c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11878cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x118790: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x118790u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x118794: 0x3e00008  jr          $ra
    ctx->pc = 0x118794u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118794u;
            // 0x118798: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1186E4u: goto label_1186e4;
            case 0x1186FCu: goto label_1186fc;
            case 0x118704u: goto label_118704;
            case 0x118728u: goto label_118728;
            case 0x118730u: goto label_118730;
            case 0x118780u: goto label_118780;
            case 0x118784u: goto label_118784;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11879Cu;
    // 0x11879c: 0x0  nop
    ctx->pc = 0x11879cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
