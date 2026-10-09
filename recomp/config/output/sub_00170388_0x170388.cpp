#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170388
// Address: 0x170388 - 0x170424
void sub_00170388_0x170388(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170388_0x170388");
#endif

    switch (ctx->pc) {
        case 0x1703a4u: goto label_1703a4;
        case 0x1703d4u: goto label_1703d4;
        case 0x1703ecu: goto label_1703ec;
        default: break;
    }

    ctx->pc = 0x170388u;

    // 0x170388: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x170388u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17038c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17038cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x170390: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x170390u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170394: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x170394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x170398: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x170398u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17039c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x17039Cu;
    SET_GPR_U32(ctx, 31, 0x1703A4u);
    ctx->pc = 0x1703A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17039Cu;
            // 0x1703a0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1703A4u; }
        if (ctx->pc != 0x1703A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1703A4u; }
        if (ctx->pc != 0x1703A4u) { return; }
    }
    ctx->pc = 0x1703A4u;
label_1703a4:
    // 0x1703a4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1703a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1703a8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1703A8u;
    {
        const bool branch_taken_0x1703a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1703ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1703A8u;
            // 0x1703ac: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1703a8) {
            ctx->pc = 0x1703C8u;
            goto label_1703c8;
        }
    }
    ctx->pc = 0x1703B0u;
    // 0x1703b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1703b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1703b4: 0x34a50188  ori         $a1, $a1, 0x188
    ctx->pc = 0x1703b4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)392);
    // 0x1703b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1703b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1703bc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1703bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1703c0: 0x805a704  j           func_169C10
    ctx->pc = 0x1703C0u;
    ctx->pc = 0x1703C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1703C0u;
            // 0x1703c4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1703C8u;
label_1703c8:
    // 0x1703c8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1703c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1703cc: 0xc05c134  jal         func_1704D0
    ctx->pc = 0x1703CCu;
    SET_GPR_U32(ctx, 31, 0x1703D4u);
    ctx->pc = 0x1703D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1703CCu;
            // 0x1703d0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1704D0u;
    if (runtime->hasFunction(0x1704D0u)) {
        auto targetFn = runtime->lookupFunction(0x1704D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1703D4u; }
        if (ctx->pc != 0x1703D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001704D0_0x1704d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1703D4u; }
        if (ctx->pc != 0x1703D4u) { return; }
    }
    ctx->pc = 0x1703D4u;
label_1703d4:
    // 0x1703d4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1703d4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1703d8: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1703d8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1703dc: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1703DCu;
    {
        const bool branch_taken_0x1703dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1703E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1703DCu;
            // 0x1703e0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1703dc) {
            ctx->pc = 0x1703F8u;
            goto label_1703f8;
        }
    }
    ctx->pc = 0x1703E4u;
    // 0x1703e4: 0xc05a704  jal         func_169C10
    ctx->pc = 0x1703E4u;
    SET_GPR_U32(ctx, 31, 0x1703ECu);
    ctx->pc = 0x1703E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1703E4u;
            // 0x1703e8: 0x34a50f30  ori         $a1, $a1, 0xF30 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3888);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1703ECu; }
        if (ctx->pc != 0x1703ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1703ECu; }
        if (ctx->pc != 0x1703ECu) { return; }
    }
    ctx->pc = 0x1703ECu;
label_1703ec:
    // 0x1703ec: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1703ECu;
    {
        const bool branch_taken_0x1703ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1703F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1703ECu;
            // 0x1703f0: 0x8e020974  lw          $v0, 0x974($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2420)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1703ec) {
            ctx->pc = 0x170408u;
            goto label_170408;
        }
    }
    ctx->pc = 0x1703F4u;
    // 0x1703f4: 0x0  nop
    ctx->pc = 0x1703f4u;
    // NOP
label_1703f8:
    // 0x1703f8: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x1703f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1703fc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1703fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x170400: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x170400u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x170404: 0x8e020974  lw          $v0, 0x974($s0)
    ctx->pc = 0x170404u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2420)));
label_170408:
    // 0x170408: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x170408u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17040c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x17040cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x170410: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x170410u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170414: 0xae020974  sw          $v0, 0x974($s0)
    ctx->pc = 0x170414u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2420), GPR_U32(ctx, 2));
    // 0x170418: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x170418u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17041c: 0x3e00008  jr          $ra
    ctx->pc = 0x17041Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17041Cu;
            // 0x170420: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1703A4u: goto label_1703a4;
            case 0x1703C8u: goto label_1703c8;
            case 0x1703D4u: goto label_1703d4;
            case 0x1703ECu: goto label_1703ec;
            case 0x1703F8u: goto label_1703f8;
            case 0x170408u: goto label_170408;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170424u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
