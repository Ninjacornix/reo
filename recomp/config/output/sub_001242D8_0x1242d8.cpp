#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001242D8
// Address: 0x1242d8 - 0x124480
void sub_001242D8_0x1242d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001242D8_0x1242d8");
#endif

    switch (ctx->pc) {
        case 0x12430cu: goto label_12430c;
        case 0x12432cu: goto label_12432c;
        case 0x124390u: goto label_124390;
        case 0x1243f8u: goto label_1243f8;
        case 0x124460u: goto label_124460;
        default: break;
    }

    ctx->pc = 0x1242d8u;

    // 0x1242d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1242d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1242dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1242dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1242e0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1242e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1242e4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1242e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1242e8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1242e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1242ec: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x1242ecu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x1242f0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1242f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1242f4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1242f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1242f8: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1242f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1242fc: 0x14620050  bne         $v1, $v0, . + 4 + (0x50 << 2)
    ctx->pc = 0x1242FCu;
    {
        const bool branch_taken_0x1242fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x124300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1242FCu;
            // 0x124300: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1242fc) {
            ctx->pc = 0x124440u;
            goto label_124440;
        }
    }
    ctx->pc = 0x124304u;
    // 0x124304: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x124304u;
    SET_GPR_U32(ctx, 31, 0x12430Cu);
    ctx->pc = 0x124308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124304u;
            // 0x124308: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12430Cu; }
        if (ctx->pc != 0x12430Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12430Cu; }
        if (ctx->pc != 0x12430Cu) { return; }
    }
    ctx->pc = 0x12430Cu;
label_12430c:
    // 0x12430c: 0x5440004c  bnel        $v0, $zero, . + 4 + (0x4C << 2)
    ctx->pc = 0x12430Cu;
    {
        const bool branch_taken_0x12430c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12430c) {
            ctx->pc = 0x124310u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12430Cu;
            // 0x124310: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x124440u;
            goto label_124440;
        }
    }
    ctx->pc = 0x124314u;
    // 0x124314: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x124314u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x124318: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x124318u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x12431c: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x12431cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x124320: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x124320u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x124324: 0x40f809  jalr        $v0
    ctx->pc = 0x124324u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12432Cu);
        ctx->pc = 0x124328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124324u;
            // 0x124328: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12432Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12432Cu; }
            if (ctx->pc != 0x12432Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12432Cu;
label_12432c:
    // 0x12432c: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x12432cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x124330: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x124330u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x124334: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x124334u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124338: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x124338u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x12433c: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x12433cu;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x124340: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x124340u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x124344: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x124344u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x124348: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x124348u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x12434c: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x12434cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x124350: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x124350u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x124354: 0x8e2a0014  lw          $t2, 0x14($s1)
    ctx->pc = 0x124354u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x124358: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x124358u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x12435c: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x12435cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x124360: 0x1435821  addu        $t3, $t2, $v1
    ctx->pc = 0x124360u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
    // 0x124364: 0x1486001e  bne         $a0, $a2, . + 4 + (0x1E << 2)
    ctx->pc = 0x124364u;
    {
        const bool branch_taken_0x124364 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x124368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124364u;
            // 0x124368: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124364) {
            ctx->pc = 0x1243E0u;
            goto label_1243e0;
        }
    }
    ctx->pc = 0x12436Cu;
    // 0x12436c: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x12436cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x124370: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x124370u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124374: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x124374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x124378: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x124378u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x12437c: 0x19200029  blez        $t1, . + 4 + (0x29 << 2)
    ctx->pc = 0x12437Cu;
    {
        const bool branch_taken_0x12437c = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x124380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12437Cu;
            // 0x124380: 0x1426021  addu        $t4, $t2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12437c) {
            ctx->pc = 0x124424u;
            goto label_124424;
        }
    }
    ctx->pc = 0x124384u;
    // 0x124384: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x124384u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x124388: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x124388u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12438c: 0x244ab738  addiu       $t2, $v0, -0x48C8
    ctx->pc = 0x12438cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), 4294948664));
label_124390:
    // 0x124390: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x124390u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x124394: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x124394u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x124398: 0x8b2821  addu        $a1, $a0, $t3
    ctx->pc = 0x124398u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x12439c: 0x8c2021  addu        $a0, $a0, $t4
    ctx->pc = 0x12439cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 12)));
    // 0x1243a0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1243a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1243a4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1243a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1243a8: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x1243a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x1243ac: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x1243acu;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1243b0: 0x94430000  lhu         $v1, 0x0($v0)
    ctx->pc = 0x1243b0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1243b4: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x1243b4u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1243b8: 0x90e20001  lbu         $v0, 0x1($a3)
    ctx->pc = 0x1243b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x1243bc: 0x24e70002  addiu       $a3, $a3, 0x2
    ctx->pc = 0x1243bcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 2));
    // 0x1243c0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1243c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1243c4: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x1243c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x1243c8: 0x94430000  lhu         $v1, 0x0($v0)
    ctx->pc = 0x1243c8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1243cc: 0x14c0fff0  bnez        $a2, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1243CCu;
    {
        const bool branch_taken_0x1243cc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1243D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1243CCu;
            // 0x1243d0: 0xa4830000  sh          $v1, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1243cc) {
            ctx->pc = 0x124390u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_124390;
        }
    }
    ctx->pc = 0x1243D4u;
    // 0x1243d4: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1243D4u;
    {
        const bool branch_taken_0x1243d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1243D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1243D4u;
            // 0x1243d8: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1243d4) {
            ctx->pc = 0x124424u;
            goto label_124424;
        }
    }
    ctx->pc = 0x1243DCu;
    // 0x1243dc: 0x0  nop
    ctx->pc = 0x1243dcu;
    // NOP
label_1243e0:
    // 0x1243e0: 0x19200010  blez        $t1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1243E0u;
    {
        const bool branch_taken_0x1243e0 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x1243E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1243E0u;
            // 0x1243e4: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1243e0) {
            ctx->pc = 0x124424u;
            goto label_124424;
        }
    }
    ctx->pc = 0x1243E8u;
    // 0x1243e8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1243e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1243ec: 0x160282d  daddu       $a1, $t3, $zero
    ctx->pc = 0x1243ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1243f0: 0x2446b738  addiu       $a2, $v0, -0x48C8
    ctx->pc = 0x1243f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294948664));
    // 0x1243f4: 0x0  nop
    ctx->pc = 0x1243f4u;
    // NOP
label_1243f8:
    // 0x1243f8: 0x2481821  addu        $v1, $s2, $t0
    ctx->pc = 0x1243f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 8)));
    // 0x1243fc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1243fcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x124400: 0x90620000  lbu         $v0, 0x0($v1)
    ctx->pc = 0x124400u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x124404: 0x109202a  slt         $a0, $t0, $t1
    ctx->pc = 0x124404u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x124408: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x124408u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x12440c: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x12440cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x124410: 0x94430000  lhu         $v1, 0x0($v0)
    ctx->pc = 0x124410u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x124414: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x124414u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x124418: 0x1480fff7  bnez        $a0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x124418u;
    {
        const bool branch_taken_0x124418 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x12441Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124418u;
            // 0x12441c: 0x24a50002  addiu       $a1, $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124418) {
            ctx->pc = 0x1243F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1243f8;
        }
    }
    ctx->pc = 0x124420u;
    // 0x124420: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x124420u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_124424:
    // 0x124424: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x124424u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x124428: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x124428u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12442c: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x12442cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x124430: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x124430u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x124434: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x124434u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x124438: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x124438u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x12443c: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x12443cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_124440:
    // 0x124440: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x124440u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124444: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x124444u;
    {
        const bool branch_taken_0x124444 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x124444) {
            ctx->pc = 0x124448u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x124444u;
            // 0x124448: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12446Cu;
            goto label_12446c;
        }
    }
    ctx->pc = 0x12444Cu;
    // 0x12444c: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x12444cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x124450: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x124450u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x124454: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x124454u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x124458: 0x60f809  jalr        $v1
    ctx->pc = 0x124458u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x124460u);
        ctx->pc = 0x12445Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124458u;
            // 0x12445c: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x124460u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124460u; }
            if (ctx->pc != 0x124460u) { return; }
        }
        }
    }
    ctx->pc = 0x124460u;
label_124460:
    // 0x124460: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x124460u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x124464: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x124464u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x124468: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124468u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_12446c:
    // 0x12446c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12446cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124470: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x124470u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x124474: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x124474u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124478: 0x3e00008  jr          $ra
    ctx->pc = 0x124478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12447Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124478u;
            // 0x12447c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124480u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
