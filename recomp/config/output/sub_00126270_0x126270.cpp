#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00126270
// Address: 0x126270 - 0x12640c
void sub_00126270_0x126270(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00126270_0x126270");
#endif

    switch (ctx->pc) {
        case 0x1262a4u: goto label_1262a4;
        case 0x1262c4u: goto label_1262c4;
        case 0x126320u: goto label_126320;
        case 0x126380u: goto label_126380;
        case 0x1263ecu: goto label_1263ec;
        default: break;
    }

    ctx->pc = 0x126270u;

    // 0x126270: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x126270u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x126274: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x126274u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x126278: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x126278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12627c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12627cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126280: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x126280u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x126284: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x126284u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x126288: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x126288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12628c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x12628cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x126290: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x126290u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x126294: 0x1462004d  bne         $v1, $v0, . + 4 + (0x4D << 2)
    ctx->pc = 0x126294u;
    {
        const bool branch_taken_0x126294 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x126298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126294u;
            // 0x126298: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126294) {
            ctx->pc = 0x1263CCu;
            goto label_1263cc;
        }
    }
    ctx->pc = 0x12629Cu;
    // 0x12629c: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x12629Cu;
    SET_GPR_U32(ctx, 31, 0x1262A4u);
    ctx->pc = 0x1262A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12629Cu;
            // 0x1262a0: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1262A4u; }
        if (ctx->pc != 0x1262A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1262A4u; }
        if (ctx->pc != 0x1262A4u) { return; }
    }
    ctx->pc = 0x1262A4u;
label_1262a4:
    // 0x1262a4: 0x54400049  bnel        $v0, $zero, . + 4 + (0x49 << 2)
    ctx->pc = 0x1262A4u;
    {
        const bool branch_taken_0x1262a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1262a4) {
            ctx->pc = 0x1262A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1262A4u;
            // 0x1262a8: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1263CCu;
            goto label_1263cc;
        }
    }
    ctx->pc = 0x1262ACu;
    // 0x1262ac: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x1262acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x1262b0: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x1262b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x1262b4: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x1262b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x1262b8: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x1262b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x1262bc: 0x40f809  jalr        $v0
    ctx->pc = 0x1262BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1262C4u);
        ctx->pc = 0x1262C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1262BCu;
            // 0x1262c0: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1262C4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1262C4u; }
            if (ctx->pc != 0x1262C4u) { return; }
        }
        }
    }
    ctx->pc = 0x1262C4u;
label_1262c4:
    // 0x1262c4: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x1262c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1262c8: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x1262c8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x1262cc: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1262ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1262d0: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x1262d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x1262d4: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x1262d4u;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1262d8: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x1262d8u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x1262dc: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x1262dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1262e0: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x1262e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1262e4: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x1262e4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x1262e8: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x1262e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1262ec: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x1262ecu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1262f0: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x1262f0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1262f4: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x1262f4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x1262f8: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x1262f8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x1262fc: 0x1486001c  bne         $a0, $a2, . + 4 + (0x1C << 2)
    ctx->pc = 0x1262FCu;
    {
        const bool branch_taken_0x1262fc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x126300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1262FCu;
            // 0x126300: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1262fc) {
            ctx->pc = 0x126370u;
            goto label_126370;
        }
    }
    ctx->pc = 0x126304u;
    // 0x126304: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x126304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x126308: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x126308u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12630c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x12630cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x126310: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x126310u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x126314: 0x19200025  blez        $t1, . + 4 + (0x25 << 2)
    ctx->pc = 0x126314u;
    {
        const bool branch_taken_0x126314 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x126318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126314u;
            // 0x126318: 0x1625821  addu        $t3, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126314) {
            ctx->pc = 0x1263ACu;
            goto label_1263ac;
        }
    }
    ctx->pc = 0x12631Cu;
    // 0x12631c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x12631cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_126320:
    // 0x126320: 0x90e20002  lbu         $v0, 0x2($a3)
    ctx->pc = 0x126320u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x126324: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x126324u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x126328: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x126328u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x12632c: 0x8a2821  addu        $a1, $a0, $t2
    ctx->pc = 0x12632cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
    // 0x126330: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x126330u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x126334: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x126334u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x126338: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x126338u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x12633c: 0x8b2021  addu        $a0, $a0, $t3
    ctx->pc = 0x12633cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x126340: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x126340u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x126344: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x126344u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x126348: 0x90e20003  lbu         $v0, 0x3($a3)
    ctx->pc = 0x126348u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 3)));
    // 0x12634c: 0x90e30001  lbu         $v1, 0x1($a3)
    ctx->pc = 0x12634cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x126350: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x126350u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x126354: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x126354u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x126358: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x126358u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x12635c: 0x14c0fff0  bnez        $a2, . + 4 + (-0x10 << 2)
    ctx->pc = 0x12635Cu;
    {
        const bool branch_taken_0x12635c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x126360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12635Cu;
            // 0x126360: 0xa4830000  sh          $v1, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12635c) {
            ctx->pc = 0x126320u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_126320;
        }
    }
    ctx->pc = 0x126364u;
    // 0x126364: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x126364u;
    {
        const bool branch_taken_0x126364 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x126368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126364u;
            // 0x126368: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126364) {
            ctx->pc = 0x1263ACu;
            goto label_1263ac;
        }
    }
    ctx->pc = 0x12636Cu;
    // 0x12636c: 0x0  nop
    ctx->pc = 0x12636cu;
    // NOP
label_126370:
    // 0x126370: 0x1920000e  blez        $t1, . + 4 + (0xE << 2)
    ctx->pc = 0x126370u;
    {
        const bool branch_taken_0x126370 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x126374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126370u;
            // 0x126374: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126370) {
            ctx->pc = 0x1263ACu;
            goto label_1263ac;
        }
    }
    ctx->pc = 0x126378u;
    // 0x126378: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x126378u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12637c: 0x140302d  daddu       $a2, $t2, $zero
    ctx->pc = 0x12637cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
label_126380:
    // 0x126380: 0x90a20001  lbu         $v0, 0x1($a1)
    ctx->pc = 0x126380u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x126384: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x126384u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x126388: 0x90a30000  lbu         $v1, 0x0($a1)
    ctx->pc = 0x126388u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12638c: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x12638cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
    // 0x126390: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x126390u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x126394: 0x109202a  slt         $a0, $t0, $t1
    ctx->pc = 0x126394u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x126398: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x126398u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x12639c: 0xa4c30000  sh          $v1, 0x0($a2)
    ctx->pc = 0x12639cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1263a0: 0x1480fff7  bnez        $a0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1263A0u;
    {
        const bool branch_taken_0x1263a0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1263A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1263A0u;
            // 0x1263a4: 0x24c60002  addiu       $a2, $a2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1263a0) {
            ctx->pc = 0x126380u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_126380;
        }
    }
    ctx->pc = 0x1263A8u;
    // 0x1263a8: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x1263a8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_1263ac:
    // 0x1263ac: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x1263acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1263b0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1263b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1263b4: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x1263b4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x1263b8: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1263b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x1263bc: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x1263bcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1263c0: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x1263c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x1263c4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1263c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1263c8: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x1263c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_1263cc:
    // 0x1263cc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1263ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1263d0: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1263D0u;
    {
        const bool branch_taken_0x1263d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1263d0) {
            ctx->pc = 0x1263D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1263D0u;
            // 0x1263d4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1263F8u;
            goto label_1263f8;
        }
    }
    ctx->pc = 0x1263D8u;
    // 0x1263d8: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x1263d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x1263dc: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x1263dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x1263e0: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x1263e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x1263e4: 0x60f809  jalr        $v1
    ctx->pc = 0x1263E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1263ECu);
        ctx->pc = 0x1263E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1263E4u;
            // 0x1263e8: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1263ECu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1263ECu; }
            if (ctx->pc != 0x1263ECu) { return; }
        }
        }
    }
    ctx->pc = 0x1263ECu;
label_1263ec:
    // 0x1263ec: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1263ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1263f0: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1263f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1263f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1263f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1263f8:
    // 0x1263f8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1263f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1263fc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1263fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x126400: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x126400u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x126404: 0x3e00008  jr          $ra
    ctx->pc = 0x126404u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126404u;
            // 0x126408: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12640Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
