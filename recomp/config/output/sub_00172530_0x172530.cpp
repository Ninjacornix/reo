#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172530
// Address: 0x172530 - 0x1725e0
void sub_00172530_0x172530(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172530_0x172530");
#endif

    switch (ctx->pc) {
        case 0x172544u: goto label_172544;
        case 0x172574u: goto label_172574;
        case 0x1725a8u: goto label_1725a8;
        case 0x1725bcu: goto label_1725bc;
        default: break;
    }

    ctx->pc = 0x172530u;

    // 0x172530: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172530u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x172534: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x172534u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172538: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x172538u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17253c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x17253Cu;
    SET_GPR_U32(ctx, 31, 0x172544u);
    ctx->pc = 0x172540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17253Cu;
            // 0x172540: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172544u; }
        if (ctx->pc != 0x172544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172544u; }
        if (ctx->pc != 0x172544u) { return; }
    }
    ctx->pc = 0x172544u;
label_172544:
    // 0x172544: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x172544u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x172548: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172548u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17254c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17254Cu;
    {
        const bool branch_taken_0x17254c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x172550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17254Cu;
            // 0x172550: 0x34a50138  ori         $a1, $a1, 0x138 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)312);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17254c) {
            ctx->pc = 0x172568u;
            goto label_172568;
        }
    }
    ctx->pc = 0x172554u;
    // 0x172554: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172554u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172558: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x172558u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17255c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17255cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172560: 0x805a704  j           func_169C10
    ctx->pc = 0x172560u;
    ctx->pc = 0x172564u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172560u;
            // 0x172564: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x172568u;
label_172568:
    // 0x172568: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x172568u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17256c: 0xc05c978  jal         func_1725E0
    ctx->pc = 0x17256Cu;
    SET_GPR_U32(ctx, 31, 0x172574u);
    ctx->pc = 0x172570u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17256Cu;
            // 0x172570: 0xae020044  sw          $v0, 0x44($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1725E0u;
    if (runtime->hasFunction(0x1725E0u)) {
        auto targetFn = runtime->lookupFunction(0x1725E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172574u; }
        if (ctx->pc != 0x172574u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001725E0_0x1725e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172574u; }
        if (ctx->pc != 0x172574u) { return; }
    }
    ctx->pc = 0x172574u;
label_172574:
    // 0x172574: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x172574u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172578: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172578u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17257c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17257cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172580: 0x3e00008  jr          $ra
    ctx->pc = 0x172580u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172580u;
            // 0x172584: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x172544u: goto label_172544;
            case 0x172568u: goto label_172568;
            case 0x172574u: goto label_172574;
            case 0x1725A8u: goto label_1725a8;
            case 0x1725BCu: goto label_1725bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172588u;
    // 0x172588: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x172588u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17258c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17258cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x172590: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x172590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x172594: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x172594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172598: 0x2450f18c  addiu       $s0, $v0, -0xE74
    ctx->pc = 0x172598u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963596));
    // 0x17259c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17259cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1725a0: 0x24110007  addiu       $s1, $zero, 0x7
    ctx->pc = 0x1725a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1725a4: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1725a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_1725a8:
    // 0x1725a8: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x1725a8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1725ac: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1725ACu;
    {
        const bool branch_taken_0x1725ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1725B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1725ACu;
            // 0x1725b0: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1725ac) {
            ctx->pc = 0x1725BCu;
            goto label_1725bc;
        }
    }
    ctx->pc = 0x1725B4u;
    // 0x1725b4: 0xc05c978  jal         func_1725E0
    ctx->pc = 0x1725B4u;
    SET_GPR_U32(ctx, 31, 0x1725BCu);
    ctx->pc = 0x1725E0u;
    if (runtime->hasFunction(0x1725E0u)) {
        auto targetFn = runtime->lookupFunction(0x1725E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1725BCu; }
        if (ctx->pc != 0x1725BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001725E0_0x1725e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1725BCu; }
        if (ctx->pc != 0x1725BCu) { return; }
    }
    ctx->pc = 0x1725BCu;
label_1725bc:
    // 0x1725bc: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x1725bcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x1725c0: 0x623fff9  bgezl       $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1725C0u;
    {
        const bool branch_taken_0x1725c0 = (GPR_S64(ctx, 17) >= 0);
        if (branch_taken_0x1725c0) {
            ctx->pc = 0x1725C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1725C0u;
            // 0x1725c4: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1725A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1725a8;
        }
    }
    ctx->pc = 0x1725C8u;
    // 0x1725c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1725c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1725cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1725ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1725d0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1725d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1725d4: 0x805ccfe  j           func_1733F8
    ctx->pc = 0x1725D4u;
    ctx->pc = 0x1725D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1725D4u;
            // 0x1725d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1733F8u;
    if (runtime->hasFunction(0x1733F8u)) {
        auto targetFn = runtime->lookupFunction(0x1733F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001733F8_0x1733f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1725DCu;
    // 0x1725dc: 0x0  nop
    ctx->pc = 0x1725dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
