#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138650
// Address: 0x138650 - 0x1389d0
void sub_00138650_0x138650(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138650_0x138650");
#endif

    switch (ctx->pc) {
        case 0x138690u: goto label_138690;
        case 0x1386b8u: goto label_1386b8;
        case 0x1386d8u: goto label_1386d8;
        case 0x138704u: goto label_138704;
        case 0x138708u: goto label_138708;
        case 0x138754u: goto label_138754;
        case 0x138778u: goto label_138778;
        case 0x1387b8u: goto label_1387b8;
        case 0x1387d0u: goto label_1387d0;
        case 0x1387e8u: goto label_1387e8;
        case 0x138800u: goto label_138800;
        case 0x138820u: goto label_138820;
        case 0x138838u: goto label_138838;
        case 0x138874u: goto label_138874;
        case 0x13888cu: goto label_13888c;
        case 0x138890u: goto label_138890;
        case 0x1388c8u: goto label_1388c8;
        case 0x1388e0u: goto label_1388e0;
        case 0x138908u: goto label_138908;
        case 0x13893cu: goto label_13893c;
        case 0x138950u: goto label_138950;
        case 0x138968u: goto label_138968;
        case 0x138980u: goto label_138980;
        default: break;
    }

    ctx->pc = 0x138650u;

    // 0x138650: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x138650u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x138654: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x138654u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x138658: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x138658u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x13865c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x13865cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138660: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x138660u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x138664: 0xffb10048  sd          $s1, 0x48($sp)
    ctx->pc = 0x138664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
    // 0x138668: 0xffb30058  sd          $s3, 0x58($sp)
    ctx->pc = 0x138668u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 19));
    // 0x13866c: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x13866cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x138670: 0x82440001  lb          $a0, 0x1($s2)
    ctx->pc = 0x138670u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 1)));
    // 0x138674: 0x548200cf  bnel        $a0, $v0, . + 4 + (0xCF << 2)
    ctx->pc = 0x138674u;
    {
        const bool branch_taken_0x138674 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x138674) {
            ctx->pc = 0x138678u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x138674u;
            // 0x138678: 0xdfb00040  ld          $s0, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1389B4u;
            goto label_1389b4;
        }
    }
    ctx->pc = 0x13867Cu;
    // 0x13867c: 0x82420002  lb          $v0, 0x2($s2)
    ctx->pc = 0x13867cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 2)));
    // 0x138680: 0x1444002a  bne         $v0, $a0, . + 4 + (0x2A << 2)
    ctx->pc = 0x138680u;
    {
        const bool branch_taken_0x138680 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x138684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138680u;
            // 0x138684: 0x92430002  lbu         $v1, 0x2($s2) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138680) {
            ctx->pc = 0x13872Cu;
            goto label_13872c;
        }
    }
    ctx->pc = 0x138688u;
    // 0x138688: 0xc045270  jal         func_1149C0
    ctx->pc = 0x138688u;
    SET_GPR_U32(ctx, 31, 0x138690u);
    ctx->pc = 0x13868Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138688u;
            // 0x13868c: 0x8e44002c  lw          $a0, 0x2C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 44)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1149C0u;
    if (runtime->hasFunction(0x1149C0u)) {
        auto targetFn = runtime->lookupFunction(0x1149C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138690u; }
        if (ctx->pc != 0x138690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001149C0_0x1149c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138690u; }
        if (ctx->pc != 0x138690u) { return; }
    }
    ctx->pc = 0x138690u;
label_138690:
    // 0x138690: 0x4430026  bgezl       $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x138690u;
    {
        const bool branch_taken_0x138690 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x138690) {
            ctx->pc = 0x138694u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x138690u;
            // 0x138694: 0x92430002  lbu         $v1, 0x2($s2) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 2)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13872Cu;
            goto label_13872c;
        }
    }
    ctx->pc = 0x138698u;
    // 0x138698: 0x8e440004  lw          $a0, 0x4($s2)
    ctx->pc = 0x138698u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x13869c: 0x2650000c  addiu       $s0, $s2, 0xC
    ctx->pc = 0x13869cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 12));
    // 0x1386a0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1386a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1386a4: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1386a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1386a8: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1386a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1386ac: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x1386acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1386b0: 0x40f809  jalr        $v0
    ctx->pc = 0x1386B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1386B8u);
        ctx->pc = 0x1386B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1386B0u;
            // 0x1386b4: 0x26510014  addiu       $s1, $s2, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 20));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1386B8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138690u: goto label_138690;
            case 0x1386B8u: goto label_1386b8;
            case 0x1386D8u: goto label_1386d8;
            case 0x138704u: goto label_138704;
            case 0x138708u: goto label_138708;
            case 0x138728u: goto label_138728;
            case 0x13872Cu: goto label_13872c;
            case 0x138754u: goto label_138754;
            case 0x138778u: goto label_138778;
            case 0x1387A0u: goto label_1387a0;
            case 0x1387B8u: goto label_1387b8;
            case 0x1387D0u: goto label_1387d0;
            case 0x1387E8u: goto label_1387e8;
            case 0x138800u: goto label_138800;
            case 0x138820u: goto label_138820;
            case 0x138838u: goto label_138838;
            case 0x138858u: goto label_138858;
            case 0x138874u: goto label_138874;
            case 0x13888Cu: goto label_13888c;
            case 0x138890u: goto label_138890;
            case 0x1388B0u: goto label_1388b0;
            case 0x1388C8u: goto label_1388c8;
            case 0x1388E0u: goto label_1388e0;
            case 0x138900u: goto label_138900;
            case 0x138908u: goto label_138908;
            case 0x13893Cu: goto label_13893c;
            case 0x138950u: goto label_138950;
            case 0x138968u: goto label_138968;
            case 0x138980u: goto label_138980;
            case 0x138988u: goto label_138988;
            case 0x1389B4u: goto label_1389b4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1386B8u; }
            if (ctx->pc != 0x1386B8u) { return; }
        }
        }
    }
    ctx->pc = 0x1386B8u;
label_1386b8:
    // 0x1386b8: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1386b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1386bc: 0x8e440008  lw          $a0, 0x8($s2)
    ctx->pc = 0x1386bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1386c0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1386c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1386c4: 0xae400010  sw          $zero, 0x10($s2)
    ctx->pc = 0x1386c4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 0));
    // 0x1386c8: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1386c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1386cc: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x1386ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1386d0: 0x40f809  jalr        $v0
    ctx->pc = 0x1386D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1386D8u);
        ctx->pc = 0x1386D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1386D0u;
            // 0x1386d4: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1386D8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138690u: goto label_138690;
            case 0x1386B8u: goto label_1386b8;
            case 0x1386D8u: goto label_1386d8;
            case 0x138704u: goto label_138704;
            case 0x138708u: goto label_138708;
            case 0x138728u: goto label_138728;
            case 0x13872Cu: goto label_13872c;
            case 0x138754u: goto label_138754;
            case 0x138778u: goto label_138778;
            case 0x1387A0u: goto label_1387a0;
            case 0x1387B8u: goto label_1387b8;
            case 0x1387D0u: goto label_1387d0;
            case 0x1387E8u: goto label_1387e8;
            case 0x138800u: goto label_138800;
            case 0x138820u: goto label_138820;
            case 0x138838u: goto label_138838;
            case 0x138858u: goto label_138858;
            case 0x138874u: goto label_138874;
            case 0x13888Cu: goto label_13888c;
            case 0x138890u: goto label_138890;
            case 0x1388B0u: goto label_1388b0;
            case 0x1388C8u: goto label_1388c8;
            case 0x1388E0u: goto label_1388e0;
            case 0x138900u: goto label_138900;
            case 0x138908u: goto label_138908;
            case 0x13893Cu: goto label_13893c;
            case 0x138950u: goto label_138950;
            case 0x138968u: goto label_138968;
            case 0x138980u: goto label_138980;
            case 0x138988u: goto label_138988;
            case 0x1389B4u: goto label_1389b4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1386D8u; }
            if (ctx->pc != 0x1386D8u) { return; }
        }
        }
    }
    ctx->pc = 0x1386D8u;
label_1386d8:
    // 0x1386d8: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1386d8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1386dc: 0x8e42003c  lw          $v0, 0x3C($s2)
    ctx->pc = 0x1386dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
    // 0x1386e0: 0x8e430010  lw          $v1, 0x10($s2)
    ctx->pc = 0x1386e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1386e4: 0xae400018  sw          $zero, 0x18($s2)
    ctx->pc = 0x1386e4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 0));
    // 0x1386e8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1386e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1386ec: 0xa2400002  sb          $zero, 0x2($s2)
    ctx->pc = 0x1386ecu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1386f0: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1386F0u;
    {
        const bool branch_taken_0x1386f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1386F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1386F0u;
            // 0x1386f4: 0xae42003c  sw          $v0, 0x3C($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 60), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1386f0) {
            ctx->pc = 0x138728u;
            goto label_138728;
        }
    }
    ctx->pc = 0x1386F8u;
    // 0x1386f8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1386f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1386fc: 0xc045a12  jal         func_116848
    ctx->pc = 0x1386FCu;
    SET_GPR_U32(ctx, 31, 0x138704u);
    ctx->pc = 0x138700u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1386FCu;
            // 0x138700: 0x2484c7f0  addiu       $a0, $a0, -0x3810 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952944));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138704u; }
        if (ctx->pc != 0x138704u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138704u; }
        if (ctx->pc != 0x138704u) { return; }
    }
    ctx->pc = 0x138704u;
label_138704:
    // 0x138704: 0x0  nop
    ctx->pc = 0x138704u;
    // NOP
label_138708:
    // 0x138708: 0x0  nop
    ctx->pc = 0x138708u;
    // NOP
    // 0x13870c: 0x0  nop
    ctx->pc = 0x13870cu;
    // NOP
    // 0x138710: 0x0  nop
    ctx->pc = 0x138710u;
    // NOP
    // 0x138714: 0x0  nop
    ctx->pc = 0x138714u;
    // NOP
    // 0x138718: 0x0  nop
    ctx->pc = 0x138718u;
    // NOP
    // 0x13871c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13871Cu;
    {
        const bool branch_taken_0x13871c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13871c) {
            ctx->pc = 0x138708u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_138708;
        }
    }
    ctx->pc = 0x138724u;
    // 0x138724: 0x0  nop
    ctx->pc = 0x138724u;
    // NOP
label_138728:
    // 0x138728: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x138728u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_13872c:
    // 0x13872c: 0x146000a1  bnez        $v1, . + 4 + (0xA1 << 2)
    ctx->pc = 0x13872Cu;
    {
        const bool branch_taken_0x13872c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x138730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13872Cu;
            // 0x138730: 0xdfb00040  ld          $s0, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13872c) {
            ctx->pc = 0x1389B4u;
            goto label_1389b4;
        }
    }
    ctx->pc = 0x138734u;
    // 0x138734: 0x8e440004  lw          $a0, 0x4($s2)
    ctx->pc = 0x138734u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x138738: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x138738u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x13873c: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x13873cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138740: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x138740u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x138744: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x138744u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x138748: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x138748u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x13874c: 0x40f809  jalr        $v0
    ctx->pc = 0x13874Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x138754u);
        ctx->pc = 0x138750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13874Cu;
            // 0x138750: 0x34c6ffff  ori         $a2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x138754u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138690u: goto label_138690;
            case 0x1386B8u: goto label_1386b8;
            case 0x1386D8u: goto label_1386d8;
            case 0x138704u: goto label_138704;
            case 0x138708u: goto label_138708;
            case 0x138728u: goto label_138728;
            case 0x13872Cu: goto label_13872c;
            case 0x138754u: goto label_138754;
            case 0x138778u: goto label_138778;
            case 0x1387A0u: goto label_1387a0;
            case 0x1387B8u: goto label_1387b8;
            case 0x1387D0u: goto label_1387d0;
            case 0x1387E8u: goto label_1387e8;
            case 0x138800u: goto label_138800;
            case 0x138820u: goto label_138820;
            case 0x138838u: goto label_138838;
            case 0x138858u: goto label_138858;
            case 0x138874u: goto label_138874;
            case 0x13888Cu: goto label_13888c;
            case 0x138890u: goto label_138890;
            case 0x1388B0u: goto label_1388b0;
            case 0x1388C8u: goto label_1388c8;
            case 0x1388E0u: goto label_1388e0;
            case 0x138900u: goto label_138900;
            case 0x138908u: goto label_138908;
            case 0x13893Cu: goto label_13893c;
            case 0x138950u: goto label_138950;
            case 0x138968u: goto label_138968;
            case 0x138980u: goto label_138980;
            case 0x138988u: goto label_138988;
            case 0x1389B4u: goto label_1389b4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x138754u; }
            if (ctx->pc != 0x138754u) { return; }
        }
        }
    }
    ctx->pc = 0x138754u;
label_138754:
    // 0x138754: 0x8e440008  lw          $a0, 0x8($s2)
    ctx->pc = 0x138754u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x138758: 0x27b30020  addiu       $s3, $sp, 0x20
    ctx->pc = 0x138758u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x13875c: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x13875cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x138760: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x138760u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x138764: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x138764u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138768: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x138768u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x13876c: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x13876cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x138770: 0x40f809  jalr        $v0
    ctx->pc = 0x138770u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x138778u);
        ctx->pc = 0x138774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138770u;
            // 0x138774: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x138778u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138690u: goto label_138690;
            case 0x1386B8u: goto label_1386b8;
            case 0x1386D8u: goto label_1386d8;
            case 0x138704u: goto label_138704;
            case 0x138708u: goto label_138708;
            case 0x138728u: goto label_138728;
            case 0x13872Cu: goto label_13872c;
            case 0x138754u: goto label_138754;
            case 0x138778u: goto label_138778;
            case 0x1387A0u: goto label_1387a0;
            case 0x1387B8u: goto label_1387b8;
            case 0x1387D0u: goto label_1387d0;
            case 0x1387E8u: goto label_1387e8;
            case 0x138800u: goto label_138800;
            case 0x138820u: goto label_138820;
            case 0x138838u: goto label_138838;
            case 0x138858u: goto label_138858;
            case 0x138874u: goto label_138874;
            case 0x13888Cu: goto label_13888c;
            case 0x138890u: goto label_138890;
            case 0x1388B0u: goto label_1388b0;
            case 0x1388C8u: goto label_1388c8;
            case 0x1388E0u: goto label_1388e0;
            case 0x138900u: goto label_138900;
            case 0x138908u: goto label_138908;
            case 0x13893Cu: goto label_13893c;
            case 0x138950u: goto label_138950;
            case 0x138968u: goto label_138968;
            case 0x138980u: goto label_138980;
            case 0x138988u: goto label_138988;
            case 0x1389B4u: goto label_1389b4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x138778u; }
            if (ctx->pc != 0x138778u) { return; }
        }
        }
    }
    ctx->pc = 0x138778u;
label_138778:
    // 0x138778: 0x8e450038  lw          $a1, 0x38($s2)
    ctx->pc = 0x138778u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 56)));
    // 0x13877c: 0x8fb10024  lw          $s1, 0x24($sp)
    ctx->pc = 0x13877cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x138780: 0x27b00010  addiu       $s0, $sp, 0x10
    ctx->pc = 0x138780u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x138784: 0x8fa80004  lw          $t0, 0x4($sp)
    ctx->pc = 0x138784u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x138788: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x138788u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13878c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x13878cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138790: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x138790u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138794: 0x111182a  slt         $v1, $t0, $s1
    ctx->pc = 0x138794u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x138798: 0x50a00001  beql        $a1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x138798u;
    {
        const bool branch_taken_0x138798 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x138798) {
            ctx->pc = 0x13879Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x138798u;
            // 0x13879c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1387A0u;
            goto label_1387a0;
        }
    }
    ctx->pc = 0x1387A0u;
label_1387a0:
    // 0x1387a0: 0x103880b  movn        $s1, $t0, $v1
    ctx->pc = 0x1387a0u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 8));
    // 0x1387a4: 0x225001a  div         $zero, $s1, $a1
    ctx->pc = 0x1387a4u;
    { int32_t divisor = GPR_S32(ctx, 5);    int32_t dividend = GPR_S32(ctx, 17);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1387a8: 0x1012  mflo        $v0
    ctx->pc = 0x1387a8u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1387ac: 0x458818  mult        $s1, $v0, $a1
    ctx->pc = 0x1387acu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 17, (int32_t)result); }
    // 0x1387b0: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x1387B0u;
    SET_GPR_U32(ctx, 31, 0x1387B8u);
    ctx->pc = 0x1387B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1387B0u;
            // 0x1387b4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1387B8u; }
        if (ctx->pc != 0x1387B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1387B8u; }
        if (ctx->pc != 0x1387B8u) { return; }
    }
    ctx->pc = 0x1387B8u;
label_1387b8:
    // 0x1387b8: 0x8e440004  lw          $a0, 0x4($s2)
    ctx->pc = 0x1387b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1387bc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1387bcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1387c0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1387c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1387c4: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x1387c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1387c8: 0x40f809  jalr        $v0
    ctx->pc = 0x1387C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1387D0u);
        ctx->pc = 0x1387CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1387C8u;
            // 0x1387cc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1387D0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138690u: goto label_138690;
            case 0x1386B8u: goto label_1386b8;
            case 0x1386D8u: goto label_1386d8;
            case 0x138704u: goto label_138704;
            case 0x138708u: goto label_138708;
            case 0x138728u: goto label_138728;
            case 0x13872Cu: goto label_13872c;
            case 0x138754u: goto label_138754;
            case 0x138778u: goto label_138778;
            case 0x1387A0u: goto label_1387a0;
            case 0x1387B8u: goto label_1387b8;
            case 0x1387D0u: goto label_1387d0;
            case 0x1387E8u: goto label_1387e8;
            case 0x138800u: goto label_138800;
            case 0x138820u: goto label_138820;
            case 0x138838u: goto label_138838;
            case 0x138858u: goto label_138858;
            case 0x138874u: goto label_138874;
            case 0x13888Cu: goto label_13888c;
            case 0x138890u: goto label_138890;
            case 0x1388B0u: goto label_1388b0;
            case 0x1388C8u: goto label_1388c8;
            case 0x1388E0u: goto label_1388e0;
            case 0x138900u: goto label_138900;
            case 0x138908u: goto label_138908;
            case 0x13893Cu: goto label_13893c;
            case 0x138950u: goto label_138950;
            case 0x138968u: goto label_138968;
            case 0x138980u: goto label_138980;
            case 0x138988u: goto label_138988;
            case 0x1389B4u: goto label_1389b4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1387D0u; }
            if (ctx->pc != 0x1387D0u) { return; }
        }
        }
    }
    ctx->pc = 0x1387D0u;
label_1387d0:
    // 0x1387d0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1387d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1387d4: 0x27b00030  addiu       $s0, $sp, 0x30
    ctx->pc = 0x1387d4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1387d8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1387d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1387dc: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1387dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1387e0: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x1387E0u;
    SET_GPR_U32(ctx, 31, 0x1387E8u);
    ctx->pc = 0x1387E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1387E0u;
            // 0x1387e4: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1387E8u; }
        if (ctx->pc != 0x1387E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1387E8u; }
        if (ctx->pc != 0x1387E8u) { return; }
    }
    ctx->pc = 0x1387E8u;
label_1387e8:
    // 0x1387e8: 0x8e440008  lw          $a0, 0x8($s2)
    ctx->pc = 0x1387e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1387ec: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1387ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1387f0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1387f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1387f4: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x1387f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1387f8: 0x40f809  jalr        $v0
    ctx->pc = 0x1387F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x138800u);
        ctx->pc = 0x1387FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1387F8u;
            // 0x1387fc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x138800u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138690u: goto label_138690;
            case 0x1386B8u: goto label_1386b8;
            case 0x1386D8u: goto label_1386d8;
            case 0x138704u: goto label_138704;
            case 0x138708u: goto label_138708;
            case 0x138728u: goto label_138728;
            case 0x13872Cu: goto label_13872c;
            case 0x138754u: goto label_138754;
            case 0x138778u: goto label_138778;
            case 0x1387A0u: goto label_1387a0;
            case 0x1387B8u: goto label_1387b8;
            case 0x1387D0u: goto label_1387d0;
            case 0x1387E8u: goto label_1387e8;
            case 0x138800u: goto label_138800;
            case 0x138820u: goto label_138820;
            case 0x138838u: goto label_138838;
            case 0x138858u: goto label_138858;
            case 0x138874u: goto label_138874;
            case 0x13888Cu: goto label_13888c;
            case 0x138890u: goto label_138890;
            case 0x1388B0u: goto label_1388b0;
            case 0x1388C8u: goto label_1388c8;
            case 0x1388E0u: goto label_1388e0;
            case 0x138900u: goto label_138900;
            case 0x138908u: goto label_138908;
            case 0x13893Cu: goto label_13893c;
            case 0x138950u: goto label_138950;
            case 0x138968u: goto label_138968;
            case 0x138980u: goto label_138980;
            case 0x138988u: goto label_138988;
            case 0x1389B4u: goto label_1389b4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x138800u; }
            if (ctx->pc != 0x138800u) { return; }
        }
        }
    }
    ctx->pc = 0x138800u;
label_138800:
    // 0x138800: 0x5a20006c  blezl       $s1, . + 4 + (0x6C << 2)
    ctx->pc = 0x138800u;
    {
        const bool branch_taken_0x138800 = (GPR_S64(ctx, 17) <= 0);
        if (branch_taken_0x138800) {
            ctx->pc = 0x138804u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x138800u;
            // 0x138804: 0xdfb00040  ld          $s0, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1389B4u;
            goto label_1389b4;
        }
    }
    ctx->pc = 0x138808u;
    // 0x138808: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x138808u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13880c: 0x3062003f  andi        $v0, $v1, 0x3F
    ctx->pc = 0x13880cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)63);
    // 0x138810: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x138810u;
    {
        const bool branch_taken_0x138810 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x138814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138810u;
            // 0x138814: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138810) {
            ctx->pc = 0x138858u;
            goto label_138858;
        }
    }
    ctx->pc = 0x138818u;
    // 0x138818: 0xc045a12  jal         func_116848
    ctx->pc = 0x138818u;
    SET_GPR_U32(ctx, 31, 0x138820u);
    ctx->pc = 0x13881Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138818u;
            // 0x13881c: 0x2484c810  addiu       $a0, $a0, -0x37F0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138820u; }
        if (ctx->pc != 0x138820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138820u; }
        if (ctx->pc != 0x138820u) { return; }
    }
    ctx->pc = 0x138820u;
label_138820:
    // 0x138820: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138820u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138824: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x138824u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138828: 0x2484c838  addiu       $a0, $a0, -0x37C8
    ctx->pc = 0x138828u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953016));
    // 0x13882c: 0x8fa60020  lw          $a2, 0x20($sp)
    ctx->pc = 0x13882cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x138830: 0xc045a12  jal         func_116848
    ctx->pc = 0x138830u;
    SET_GPR_U32(ctx, 31, 0x138838u);
    ctx->pc = 0x138834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138830u;
            // 0x138834: 0x8fa70004  lw          $a3, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138838u; }
        if (ctx->pc != 0x138838u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138838u; }
        if (ctx->pc != 0x138838u) { return; }
    }
    ctx->pc = 0x138838u;
label_138838:
    // 0x138838: 0x0  nop
    ctx->pc = 0x138838u;
    // NOP
    // 0x13883c: 0x0  nop
    ctx->pc = 0x13883cu;
    // NOP
    // 0x138840: 0x0  nop
    ctx->pc = 0x138840u;
    // NOP
    // 0x138844: 0x0  nop
    ctx->pc = 0x138844u;
    // NOP
    // 0x138848: 0x0  nop
    ctx->pc = 0x138848u;
    // NOP
    // 0x13884c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13884Cu;
    {
        const bool branch_taken_0x13884c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13884c) {
            ctx->pc = 0x138838u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_138838;
        }
    }
    ctx->pc = 0x138854u;
    // 0x138854: 0x0  nop
    ctx->pc = 0x138854u;
    // NOP
label_138858:
    // 0x138858: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x138858u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13885c: 0x3082003f  andi        $v0, $a0, 0x3F
    ctx->pc = 0x13885cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)63);
    // 0x138860: 0x50400013  beql        $v0, $zero, . + 4 + (0x13 << 2)
    ctx->pc = 0x138860u;
    {
        const bool branch_taken_0x138860 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x138860) {
            ctx->pc = 0x138864u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x138860u;
            // 0x138864: 0x8fa20020  lw          $v0, 0x20($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1388B0u;
            goto label_1388b0;
        }
    }
    ctx->pc = 0x138868u;
    // 0x138868: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138868u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13886c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13886Cu;
    SET_GPR_U32(ctx, 31, 0x138874u);
    ctx->pc = 0x138870u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13886Cu;
            // 0x138870: 0x2484c868  addiu       $a0, $a0, -0x3798 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138874u; }
        if (ctx->pc != 0x138874u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138874u; }
        if (ctx->pc != 0x138874u) { return; }
    }
    ctx->pc = 0x138874u;
label_138874:
    // 0x138874: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138874u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138878: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x138878u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13887c: 0x2484c838  addiu       $a0, $a0, -0x37C8
    ctx->pc = 0x13887cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953016));
    // 0x138880: 0x8fa60020  lw          $a2, 0x20($sp)
    ctx->pc = 0x138880u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x138884: 0xc045a12  jal         func_116848
    ctx->pc = 0x138884u;
    SET_GPR_U32(ctx, 31, 0x13888Cu);
    ctx->pc = 0x138888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138884u;
            // 0x138888: 0x8fa70004  lw          $a3, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13888Cu; }
        if (ctx->pc != 0x13888Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13888Cu; }
        if (ctx->pc != 0x13888Cu) { return; }
    }
    ctx->pc = 0x13888Cu;
label_13888c:
    // 0x13888c: 0x0  nop
    ctx->pc = 0x13888cu;
    // NOP
label_138890:
    // 0x138890: 0x0  nop
    ctx->pc = 0x138890u;
    // NOP
    // 0x138894: 0x0  nop
    ctx->pc = 0x138894u;
    // NOP
    // 0x138898: 0x0  nop
    ctx->pc = 0x138898u;
    // NOP
    // 0x13889c: 0x0  nop
    ctx->pc = 0x13889cu;
    // NOP
    // 0x1388a0: 0x0  nop
    ctx->pc = 0x1388a0u;
    // NOP
    // 0x1388a4: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x1388A4u;
    {
        const bool branch_taken_0x1388a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1388a4) {
            ctx->pc = 0x138890u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_138890;
        }
    }
    ctx->pc = 0x1388ACu;
    // 0x1388ac: 0x0  nop
    ctx->pc = 0x1388acu;
    // NOP
label_1388b0:
    // 0x1388b0: 0x3042003f  andi        $v0, $v0, 0x3F
    ctx->pc = 0x1388b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)63);
    // 0x1388b4: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1388B4u;
    {
        const bool branch_taken_0x1388b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1388B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1388B4u;
            // 0x1388b8: 0x832821  addu        $a1, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1388b4) {
            ctx->pc = 0x138900u;
            goto label_138900;
        }
    }
    ctx->pc = 0x1388BCu;
    // 0x1388bc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1388bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1388c0: 0xc045a12  jal         func_116848
    ctx->pc = 0x1388C0u;
    SET_GPR_U32(ctx, 31, 0x1388C8u);
    ctx->pc = 0x1388C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1388C0u;
            // 0x1388c4: 0x2484c890  addiu       $a0, $a0, -0x3770 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1388C8u; }
        if (ctx->pc != 0x1388C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1388C8u; }
        if (ctx->pc != 0x1388C8u) { return; }
    }
    ctx->pc = 0x1388C8u;
label_1388c8:
    // 0x1388c8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1388c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1388cc: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x1388ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1388d0: 0x2484c838  addiu       $a0, $a0, -0x37C8
    ctx->pc = 0x1388d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953016));
    // 0x1388d4: 0x8fa60020  lw          $a2, 0x20($sp)
    ctx->pc = 0x1388d4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1388d8: 0xc045a12  jal         func_116848
    ctx->pc = 0x1388D8u;
    SET_GPR_U32(ctx, 31, 0x1388E0u);
    ctx->pc = 0x1388DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1388D8u;
            // 0x1388dc: 0x8fa70004  lw          $a3, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1388E0u; }
        if (ctx->pc != 0x1388E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1388E0u; }
        if (ctx->pc != 0x1388E0u) { return; }
    }
    ctx->pc = 0x1388E0u;
label_1388e0:
    // 0x1388e0: 0x0  nop
    ctx->pc = 0x1388e0u;
    // NOP
    // 0x1388e4: 0x0  nop
    ctx->pc = 0x1388e4u;
    // NOP
    // 0x1388e8: 0x0  nop
    ctx->pc = 0x1388e8u;
    // NOP
    // 0x1388ec: 0x0  nop
    ctx->pc = 0x1388ecu;
    // NOP
    // 0x1388f0: 0x0  nop
    ctx->pc = 0x1388f0u;
    // NOP
    // 0x1388f4: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x1388F4u;
    {
        const bool branch_taken_0x1388f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1388f4) {
            ctx->pc = 0x1388E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1388e0;
        }
    }
    ctx->pc = 0x1388FCu;
    // 0x1388fc: 0x0  nop
    ctx->pc = 0x1388fcu;
    // NOP
label_138900:
    // 0x138900: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x138900u;
    SET_GPR_U32(ctx, 31, 0x138908u);
    ctx->pc = 0x138904u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138900u;
            // 0x138904: 0x24a5ffff  addiu       $a1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138908u; }
        if (ctx->pc != 0x138908u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138908u; }
        if (ctx->pc != 0x138908u) { return; }
    }
    ctx->pc = 0x138908u;
label_138908:
    // 0x138908: 0x3c020fff  lui         $v0, 0xFFF
    ctx->pc = 0x138908u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
    // 0x13890c: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x13890cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138910: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x138910u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x138914: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x138914u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x138918: 0x2644001c  addiu       $a0, $s2, 0x1C
    ctx->pc = 0x138918u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 28));
    // 0x13891c: 0x8fa70020  lw          $a3, 0x20($sp)
    ctx->pc = 0x13891cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x138920: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x138920u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x138924: 0xae43001c  sw          $v1, 0x1C($s2)
    ctx->pc = 0x138924u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 28), GPR_U32(ctx, 3));
    // 0x138928: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x138928u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13892c: 0xae470020  sw          $a3, 0x20($s2)
    ctx->pc = 0x13892cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 32), GPR_U32(ctx, 7));
    // 0x138930: 0xae460024  sw          $a2, 0x24($s2)
    ctx->pc = 0x138930u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 6));
    // 0x138934: 0xc045278  jal         func_1149E0
    ctx->pc = 0x138934u;
    SET_GPR_U32(ctx, 31, 0x13893Cu);
    ctx->pc = 0x138938u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138934u;
            // 0x138938: 0xae400028  sw          $zero, 0x28($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 40), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1149E0u;
    if (runtime->hasFunction(0x1149E0u)) {
        auto targetFn = runtime->lookupFunction(0x1149E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13893Cu; }
        if (ctx->pc != 0x13893Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001149E0_0x1149e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13893Cu; }
        if (ctx->pc != 0x13893Cu) { return; }
    }
    ctx->pc = 0x13893Cu;
label_13893c:
    // 0x13893c: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x13893Cu;
    {
        const bool branch_taken_0x13893c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x138940u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13893Cu;
            // 0x138940: 0xae42002c  sw          $v0, 0x2C($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13893c) {
            ctx->pc = 0x138988u;
            goto label_138988;
        }
    }
    ctx->pc = 0x138944u;
    // 0x138944: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138944u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138948: 0xc045a12  jal         func_116848
    ctx->pc = 0x138948u;
    SET_GPR_U32(ctx, 31, 0x138950u);
    ctx->pc = 0x13894Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138948u;
            // 0x13894c: 0x2484c8b8  addiu       $a0, $a0, -0x3748 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138950u; }
        if (ctx->pc != 0x138950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138950u; }
        if (ctx->pc != 0x138950u) { return; }
    }
    ctx->pc = 0x138950u;
label_138950:
    // 0x138950: 0x8e440004  lw          $a0, 0x4($s2)
    ctx->pc = 0x138950u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x138954: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x138954u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x138958: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x138958u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13895c: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x13895cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x138960: 0x40f809  jalr        $v0
    ctx->pc = 0x138960u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x138968u);
        ctx->pc = 0x138964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138960u;
            // 0x138964: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x138968u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138690u: goto label_138690;
            case 0x1386B8u: goto label_1386b8;
            case 0x1386D8u: goto label_1386d8;
            case 0x138704u: goto label_138704;
            case 0x138708u: goto label_138708;
            case 0x138728u: goto label_138728;
            case 0x13872Cu: goto label_13872c;
            case 0x138754u: goto label_138754;
            case 0x138778u: goto label_138778;
            case 0x1387A0u: goto label_1387a0;
            case 0x1387B8u: goto label_1387b8;
            case 0x1387D0u: goto label_1387d0;
            case 0x1387E8u: goto label_1387e8;
            case 0x138800u: goto label_138800;
            case 0x138820u: goto label_138820;
            case 0x138838u: goto label_138838;
            case 0x138858u: goto label_138858;
            case 0x138874u: goto label_138874;
            case 0x13888Cu: goto label_13888c;
            case 0x138890u: goto label_138890;
            case 0x1388B0u: goto label_1388b0;
            case 0x1388C8u: goto label_1388c8;
            case 0x1388E0u: goto label_1388e0;
            case 0x138900u: goto label_138900;
            case 0x138908u: goto label_138908;
            case 0x13893Cu: goto label_13893c;
            case 0x138950u: goto label_138950;
            case 0x138968u: goto label_138968;
            case 0x138980u: goto label_138980;
            case 0x138988u: goto label_138988;
            case 0x1389B4u: goto label_1389b4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x138968u; }
            if (ctx->pc != 0x138968u) { return; }
        }
        }
    }
    ctx->pc = 0x138968u;
label_138968:
    // 0x138968: 0x8e440008  lw          $a0, 0x8($s2)
    ctx->pc = 0x138968u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x13896c: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x13896cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138970: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x138970u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x138974: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x138974u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x138978: 0x40f809  jalr        $v0
    ctx->pc = 0x138978u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x138980u);
        ctx->pc = 0x13897Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138978u;
            // 0x13897c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x138980u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138690u: goto label_138690;
            case 0x1386B8u: goto label_1386b8;
            case 0x1386D8u: goto label_1386d8;
            case 0x138704u: goto label_138704;
            case 0x138708u: goto label_138708;
            case 0x138728u: goto label_138728;
            case 0x13872Cu: goto label_13872c;
            case 0x138754u: goto label_138754;
            case 0x138778u: goto label_138778;
            case 0x1387A0u: goto label_1387a0;
            case 0x1387B8u: goto label_1387b8;
            case 0x1387D0u: goto label_1387d0;
            case 0x1387E8u: goto label_1387e8;
            case 0x138800u: goto label_138800;
            case 0x138820u: goto label_138820;
            case 0x138838u: goto label_138838;
            case 0x138858u: goto label_138858;
            case 0x138874u: goto label_138874;
            case 0x13888Cu: goto label_13888c;
            case 0x138890u: goto label_138890;
            case 0x1388B0u: goto label_1388b0;
            case 0x1388C8u: goto label_1388c8;
            case 0x1388E0u: goto label_1388e0;
            case 0x138900u: goto label_138900;
            case 0x138908u: goto label_138908;
            case 0x13893Cu: goto label_13893c;
            case 0x138950u: goto label_138950;
            case 0x138968u: goto label_138968;
            case 0x138980u: goto label_138980;
            case 0x138988u: goto label_138988;
            case 0x1389B4u: goto label_1389b4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x138980u; }
            if (ctx->pc != 0x138980u) { return; }
        }
        }
    }
    ctx->pc = 0x138980u;
label_138980:
    // 0x138980: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x138980u;
    {
        const bool branch_taken_0x138980 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x138984u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138980u;
            // 0x138984: 0xdfb00040  ld          $s0, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138980) {
            ctx->pc = 0x1389B4u;
            goto label_1389b4;
        }
    }
    ctx->pc = 0x138988u;
label_138988:
    // 0x138988: 0x6ba40007  ldl         $a0, 0x7($sp)
    ctx->pc = 0x138988u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x13898c: 0x6fa40000  ldr         $a0, 0x0($sp)
    ctx->pc = 0x13898cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x138990: 0xb2440013  sdl         $a0, 0x13($s2)
    ctx->pc = 0x138990u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 19); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x138994: 0xb644000c  sdr         $a0, 0xC($s2)
    ctx->pc = 0x138994u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 12); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x138998: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x138998u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13899c: 0x6a640007  ldl         $a0, 0x7($s3)
    ctx->pc = 0x13899cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1389a0: 0x6e640000  ldr         $a0, 0x0($s3)
    ctx->pc = 0x1389a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1389a4: 0xb244001b  sdl         $a0, 0x1B($s2)
    ctx->pc = 0x1389a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 27); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1389a8: 0xb6440014  sdr         $a0, 0x14($s2)
    ctx->pc = 0x1389a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 20); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1389ac: 0xa2420002  sb          $v0, 0x2($s2)
    ctx->pc = 0x1389acu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1389b0: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x1389b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1389b4:
    // 0x1389b4: 0xdfb10048  ld          $s1, 0x48($sp)
    ctx->pc = 0x1389b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1389b8: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x1389b8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1389bc: 0xdfb30058  ld          $s3, 0x58($sp)
    ctx->pc = 0x1389bcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x1389c0: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1389c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1389c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1389C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1389C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1389C4u;
            // 0x1389c8: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138690u: goto label_138690;
            case 0x1386B8u: goto label_1386b8;
            case 0x1386D8u: goto label_1386d8;
            case 0x138704u: goto label_138704;
            case 0x138708u: goto label_138708;
            case 0x138728u: goto label_138728;
            case 0x13872Cu: goto label_13872c;
            case 0x138754u: goto label_138754;
            case 0x138778u: goto label_138778;
            case 0x1387A0u: goto label_1387a0;
            case 0x1387B8u: goto label_1387b8;
            case 0x1387D0u: goto label_1387d0;
            case 0x1387E8u: goto label_1387e8;
            case 0x138800u: goto label_138800;
            case 0x138820u: goto label_138820;
            case 0x138838u: goto label_138838;
            case 0x138858u: goto label_138858;
            case 0x138874u: goto label_138874;
            case 0x13888Cu: goto label_13888c;
            case 0x138890u: goto label_138890;
            case 0x1388B0u: goto label_1388b0;
            case 0x1388C8u: goto label_1388c8;
            case 0x1388E0u: goto label_1388e0;
            case 0x138900u: goto label_138900;
            case 0x138908u: goto label_138908;
            case 0x13893Cu: goto label_13893c;
            case 0x138950u: goto label_138950;
            case 0x138968u: goto label_138968;
            case 0x138980u: goto label_138980;
            case 0x138988u: goto label_138988;
            case 0x1389B4u: goto label_1389b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1389CCu;
    // 0x1389cc: 0x0  nop
    ctx->pc = 0x1389ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
