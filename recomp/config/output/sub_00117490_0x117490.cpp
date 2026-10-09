#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117490
// Address: 0x117490 - 0x117560
void sub_00117490_0x117490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117490_0x117490");
#endif

    switch (ctx->pc) {
        case 0x1174c0u: goto label_1174c0;
        case 0x1174d0u: goto label_1174d0;
        case 0x117528u: goto label_117528;
        default: break;
    }

    ctx->pc = 0x117490u;

    // 0x117490: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x117490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x117494: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x117494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x117498: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x117498u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11749c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11749cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1174a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1174a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1174a4: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1174a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1174a8: 0x8e250010  lw          $a1, 0x10($s1)
    ctx->pc = 0x1174a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1174ac: 0x30a20004  andi        $v0, $a1, 0x4
    ctx->pc = 0x1174acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4);
    // 0x1174b0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1174B0u;
    {
        const bool branch_taken_0x1174b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1174b0) {
            ctx->pc = 0x1174C8u;
            goto label_1174c8;
        }
    }
    ctx->pc = 0x1174B8u;
    // 0x1174b8: 0xc045cd0  jal         func_117340
    ctx->pc = 0x1174B8u;
    SET_GPR_U32(ctx, 31, 0x1174C0u);
    ctx->pc = 0x1174BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1174B8u;
            // 0x1174bc: 0x52c02  srl         $a1, $a1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117340u;
    if (runtime->hasFunction(0x117340u)) {
        auto targetFn = runtime->lookupFunction(0x117340u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1174C0u; }
        if (ctx->pc != 0x1174C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117340_0x117340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1174C0u; }
        if (ctx->pc != 0x1174C0u) { return; }
    }
    ctx->pc = 0x1174C0u;
label_1174c0:
    // 0x1174c0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1174C0u;
    {
        const bool branch_taken_0x1174c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1174C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1174C0u;
            // 0x1174c4: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1174c0) {
            ctx->pc = 0x1174D4u;
            goto label_1174d4;
        }
    }
    ctx->pc = 0x1174C8u;
label_1174c8:
    // 0x1174c8: 0xc045cc4  jal         func_117310
    ctx->pc = 0x1174C8u;
    SET_GPR_U32(ctx, 31, 0x1174D0u);
    ctx->pc = 0x117310u;
    if (runtime->hasFunction(0x117310u)) {
        auto targetFn = runtime->lookupFunction(0x117310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1174D0u; }
        if (ctx->pc != 0x1174D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117310_0x117310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1174D0u; }
        if (ctx->pc != 0x1174D0u) { return; }
    }
    ctx->pc = 0x1174D0u;
label_1174d0:
    // 0x1174d0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1174d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1174d4:
    // 0x1174d4: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x1174d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1174d8: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1174d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1174dc: 0x8e25001c  lw          $a1, 0x1C($s1)
    ctx->pc = 0x1174dcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1174e0: 0x3442000c  ori         $v0, $v0, 0xC
    ctx->pc = 0x1174e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)12);
    // 0x1174e4: 0xae030014  sw          $v1, 0x14($s0)
    ctx->pc = 0x1174e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x1174e8: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x1174e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x1174ec: 0xae05001c  sw          $a1, 0x1C($s0)
    ctx->pc = 0x1174ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 5));
    // 0x1174f0: 0x34840008  ori         $a0, $a0, 0x8
    ctx->pc = 0x1174f0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8);
    // 0x1174f4: 0xae020020  sw          $v0, 0x20($s0)
    ctx->pc = 0x1174f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
    // 0x1174f8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1174f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1174fc: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x1174fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x117500: 0x8e220020  lw          $v0, 0x20($s1)
    ctx->pc = 0x117500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x117504: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x117504u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
    // 0x117508: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x117508u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x11750c: 0xae030028  sw          $v1, 0x28($s0)
    ctx->pc = 0x11750cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 3));
    // 0x117510: 0x8e220028  lw          $v0, 0x28($s1)
    ctx->pc = 0x117510u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x117514: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x117514u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x117518: 0x8e290028  lw          $t1, 0x28($s1)
    ctx->pc = 0x117518u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x11751c: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x11751cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x117520: 0xc045b92  jal         func_116E48
    ctx->pc = 0x117520u;
    SET_GPR_U32(ctx, 31, 0x117528u);
    ctx->pc = 0x117524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117520u;
            // 0x117524: 0x8e280024  lw          $t0, 0x24($s1) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E48u;
    if (runtime->hasFunction(0x116E48u)) {
        auto targetFn = runtime->lookupFunction(0x116E48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117528u; }
        if (ctx->pc != 0x117528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116E48_0x116e48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117528u; }
        if (ctx->pc != 0x117528u) { return; }
    }
    ctx->pc = 0x117528u;
label_117528:
    // 0x117528: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x117528u;
    {
        const bool branch_taken_0x117528 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11752Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117528u;
            // 0x11752c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117528) {
            ctx->pc = 0x117550u;
            goto label_117550;
        }
    }
    ctx->pc = 0x117530u;
    // 0x117530: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x117530u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117534: 0x3c050011  lui         $a1, 0x11
    ctx->pc = 0x117534u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)17 << 16));
    // 0x117538: 0x24a57450  addiu       $a1, $a1, 0x7450
    ctx->pc = 0x117538u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29776));
    // 0x11753c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11753cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117540: 0x24040800  addiu       $a0, $zero, 0x800
    ctx->pc = 0x117540u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x117544: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117544u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117548: 0x8047d02  j           func_11F408
    ctx->pc = 0x117548u;
    ctx->pc = 0x11754Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117548u;
            // 0x11754c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F408u;
    if (runtime->hasFunction(0x11F408u)) {
        auto targetFn = runtime->lookupFunction(0x11F408u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011F408_0x11f408(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x117550u;
label_117550:
    // 0x117550: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x117550u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117554: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117554u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117558: 0x3e00008  jr          $ra
    ctx->pc = 0x117558u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11755Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117558u;
            // 0x11755c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1174C0u: goto label_1174c0;
            case 0x1174C8u: goto label_1174c8;
            case 0x1174D0u: goto label_1174d0;
            case 0x1174D4u: goto label_1174d4;
            case 0x117528u: goto label_117528;
            case 0x117550u: goto label_117550;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117560u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
