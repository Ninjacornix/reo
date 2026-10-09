#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137668
// Address: 0x137668 - 0x137738
void sub_00137668_0x137668(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137668_0x137668");
#endif

    switch (ctx->pc) {
        case 0x1376b0u: goto label_1376b0;
        case 0x1376c0u: goto label_1376c0;
        case 0x1376d0u: goto label_1376d0;
        case 0x1376dcu: goto label_1376dc;
        case 0x1376f8u: goto label_1376f8;
        case 0x13770cu: goto label_13770c;
        default: break;
    }

    ctx->pc = 0x137668u;

    // 0x137668: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x137668u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x13766c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13766cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137670: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x137670u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x137674: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x137674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x137678: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x137678u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x13767c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13767cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x137680: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x137680u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137684: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x137684u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x137688: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x137688u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13768c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x13768cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x137690: 0x34139000  ori         $s3, $zero, 0x9000
    ctx->pc = 0x137690u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36864);
    // 0x137694: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x137694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x137698: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x137698u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13769c: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x13769cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x1376a0: 0x3c150024  lui         $s5, 0x24
    ctx->pc = 0x1376a0u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)36 << 16));
    // 0x1376a4: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x1376a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x1376a8: 0x24160009  addiu       $s6, $zero, 0x9
    ctx->pc = 0x1376a8u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1376ac: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1376acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_1376b0:
    // 0x1376b0: 0x14540017  bne         $v0, $s4, . + 4 + (0x17 << 2)
    ctx->pc = 0x1376B0u;
    {
        const bool branch_taken_0x1376b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 20));
        ctx->pc = 0x1376B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1376B0u;
            // 0x1376b4: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1376b0) {
            ctx->pc = 0x137710u;
            goto label_137710;
        }
    }
    ctx->pc = 0x1376B8u;
    // 0x1376b8: 0xc04e082  jal         func_138208
    ctx->pc = 0x1376B8u;
    SET_GPR_U32(ctx, 31, 0x1376C0u);
    ctx->pc = 0x1376BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1376B8u;
            // 0x1376bc: 0x24041100  addiu       $a0, $zero, 0x1100 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1376C0u; }
        if (ctx->pc != 0x1376C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1376C0u; }
        if (ctx->pc != 0x1376C0u) { return; }
    }
    ctx->pc = 0x1376C0u;
label_1376c0:
    // 0x1376c0: 0x8e240030  lw          $a0, 0x30($s1)
    ctx->pc = 0x1376c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x1376c4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1376c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1376c8: 0xc04e128  jal         func_1384A0
    ctx->pc = 0x1376C8u;
    SET_GPR_U32(ctx, 31, 0x1376D0u);
    ctx->pc = 0x1376CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1376C8u;
            // 0x1376cc: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1384A0u;
    if (runtime->hasFunction(0x1384A0u)) {
        auto targetFn = runtime->lookupFunction(0x1384A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1376D0u; }
        if (ctx->pc != 0x1376D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001384A0_0x1384a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1376D0u; }
        if (ctx->pc != 0x1376D0u) { return; }
    }
    ctx->pc = 0x1376D0u;
label_1376d0:
    // 0x1376d0: 0x24041101  addiu       $a0, $zero, 0x1101
    ctx->pc = 0x1376d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4353));
    // 0x1376d4: 0xc04e082  jal         func_138208
    ctx->pc = 0x1376D4u;
    SET_GPR_U32(ctx, 31, 0x1376DCu);
    ctx->pc = 0x1376D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1376D4u;
            // 0x1376d8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1376DCu; }
        if (ctx->pc != 0x1376DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1376DCu; }
        if (ctx->pc != 0x1376DCu) { return; }
    }
    ctx->pc = 0x1376DCu;
label_1376dc:
    // 0x1376dc: 0x6010004  bgez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1376DCu;
    {
        const bool branch_taken_0x1376dc = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x1376dc) {
            ctx->pc = 0x1376F0u;
            goto label_1376f0;
        }
    }
    ctx->pc = 0x1376E4u;
    // 0x1376e4: 0xae300034  sw          $s0, 0x34($s1)
    ctx->pc = 0x1376e4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 16));
    // 0x1376e8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1376E8u;
    {
        const bool branch_taken_0x1376e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1376ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1376E8u;
            // 0x1376ec: 0xa2360002  sb          $s6, 0x2($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1376e8) {
            ctx->pc = 0x13770Cu;
            goto label_13770c;
        }
    }
    ctx->pc = 0x1376F0u;
label_1376f0:
    // 0x1376f0: 0xc04dd84  jal         func_137610
    ctx->pc = 0x1376F0u;
    SET_GPR_U32(ctx, 31, 0x1376F8u);
    ctx->pc = 0x1376F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1376F0u;
            // 0x1376f4: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137610u;
    if (runtime->hasFunction(0x137610u)) {
        auto targetFn = runtime->lookupFunction(0x137610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1376F8u; }
        if (ctx->pc != 0x1376F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137610_0x137610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1376F8u; }
        if (ctx->pc != 0x1376F8u) { return; }
    }
    ctx->pc = 0x1376F8u;
label_1376f8:
    // 0x1376f8: 0x272102a  slt         $v0, $s3, $s2
    ctx->pc = 0x1376f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1376fc: 0x5040ffec  beql        $v0, $zero, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1376FCu;
    {
        const bool branch_taken_0x1376fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1376fc) {
            ctx->pc = 0x137700u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1376FCu;
            // 0x137700: 0x8fa20000  lw          $v0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1376B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1376b0;
        }
    }
    ctx->pc = 0x137704u;
    // 0x137704: 0xc045a12  jal         func_116848
    ctx->pc = 0x137704u;
    SET_GPR_U32(ctx, 31, 0x13770Cu);
    ctx->pc = 0x137708u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137704u;
            // 0x137708: 0x26a4c4c8  addiu       $a0, $s5, -0x3B38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294952136));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13770Cu; }
        if (ctx->pc != 0x13770Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13770Cu; }
        if (ctx->pc != 0x13770Cu) { return; }
    }
    ctx->pc = 0x13770Cu;
label_13770c:
    // 0x13770c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x13770cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_137710:
    // 0x137710: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x137710u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x137714: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x137714u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x137718: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x137718u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13771c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x13771cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x137720: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x137720u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x137724: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x137724u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x137728: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x137728u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x13772c: 0x3e00008  jr          $ra
    ctx->pc = 0x13772Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13772Cu;
            // 0x137730: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1376B0u: goto label_1376b0;
            case 0x1376C0u: goto label_1376c0;
            case 0x1376D0u: goto label_1376d0;
            case 0x1376DCu: goto label_1376dc;
            case 0x1376F0u: goto label_1376f0;
            case 0x1376F8u: goto label_1376f8;
            case 0x13770Cu: goto label_13770c;
            case 0x137710u: goto label_137710;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137734u;
    // 0x137734: 0x0  nop
    ctx->pc = 0x137734u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
