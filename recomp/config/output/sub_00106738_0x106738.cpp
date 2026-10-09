#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106738
// Address: 0x106738 - 0x1068a8
void sub_00106738_0x106738(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106738_0x106738");
#endif

    switch (ctx->pc) {
        case 0x106768u: goto label_106768;
        case 0x106778u: goto label_106778;
        case 0x10678cu: goto label_10678c;
        case 0x106818u: goto label_106818;
        case 0x10689cu: goto label_10689c;
        default: break;
    }

    ctx->pc = 0x106738u;

    // 0x106738: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x106738u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x10673c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x10673cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x106740: 0x249201d8  addiu       $s2, $a0, 0x1D8
    ctx->pc = 0x106740u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), 472));
    // 0x106744: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x106744u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x106748: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x106748u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10674c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x10674cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x106750: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x106750u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106754: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x106754u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x106758: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x106758u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10675c: 0x12400012  beqz        $s2, . + 4 + (0x12 << 2)
    ctx->pc = 0x10675Cu;
    {
        const bool branch_taken_0x10675c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x106760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10675Cu;
            // 0x106760: 0xffbf0028  sd          $ra, 0x28($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10675c) {
            ctx->pc = 0x1067A8u;
            goto label_1067a8;
        }
    }
    ctx->pc = 0x106764u;
    // 0x106764: 0x8e500004  lw          $s0, 0x4($s2)
    ctx->pc = 0x106764u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_106768:
    // 0x106768: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x106768u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x10676c: 0x600000b  bltz        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x10676Cu;
    {
        const bool branch_taken_0x10676c = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x106770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10676Cu;
            // 0x106770: 0x8e510008  lw          $s1, 0x8($s2) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10676c) {
            ctx->pc = 0x10679Cu;
            goto label_10679c;
        }
    }
    ctx->pc = 0x106774u;
    // 0x106774: 0x0  nop
    ctx->pc = 0x106774u;
    // NOP
label_106778:
    // 0x106778: 0x8622000c  lh          $v0, 0xC($s1)
    ctx->pc = 0x106778u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x10677c: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x10677Cu;
    {
        const bool branch_taken_0x10677c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10677c) {
            ctx->pc = 0x106780u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10677Cu;
            // 0x106780: 0x2610ffff  addiu       $s0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106794u;
            goto label_106794;
        }
    }
    ctx->pc = 0x106784u;
    // 0x106784: 0x280f809  jalr        $s4
    ctx->pc = 0x106784u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 20);
        SET_GPR_U32(ctx, 31, 0x10678Cu);
        ctx->pc = 0x106788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106784u;
            // 0x106788: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x10678Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x106768u: goto label_106768;
            case 0x106778u: goto label_106778;
            case 0x10678Cu: goto label_10678c;
            case 0x106794u: goto label_106794;
            case 0x10679Cu: goto label_10679c;
            case 0x1067A8u: goto label_1067a8;
            case 0x106818u: goto label_106818;
            case 0x106828u: goto label_106828;
            case 0x106830u: goto label_106830;
            case 0x10683Cu: goto label_10683c;
            case 0x10689Cu: goto label_10689c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x10678Cu; }
            if (ctx->pc != 0x10678Cu) { return; }
        }
        }
    }
    ctx->pc = 0x10678Cu;
label_10678c:
    // 0x10678c: 0x2629825  or          $s3, $s3, $v0
    ctx->pc = 0x10678cu;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | GPR_U64(ctx, 2));
    // 0x106790: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x106790u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
label_106794:
    // 0x106794: 0x601fff8  bgez        $s0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x106794u;
    {
        const bool branch_taken_0x106794 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x106798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106794u;
            // 0x106798: 0x26310058  addiu       $s1, $s1, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 88));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106794) {
            ctx->pc = 0x106778u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_106778;
        }
    }
    ctx->pc = 0x10679Cu;
label_10679c:
    // 0x10679c: 0x8e520000  lw          $s2, 0x0($s2)
    ctx->pc = 0x10679cu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1067a0: 0x5640fff1  bnel        $s2, $zero, . + 4 + (-0xF << 2)
    ctx->pc = 0x1067A0u;
    {
        const bool branch_taken_0x1067a0 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x1067a0) {
            ctx->pc = 0x1067A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1067A0u;
            // 0x1067a4: 0x8e500004  lw          $s0, 0x4($s2) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106768u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_106768;
        }
    }
    ctx->pc = 0x1067A8u;
label_1067a8:
    // 0x1067a8: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x1067a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1067ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1067acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1067b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1067b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1067b4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1067b4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1067b8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1067b8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1067bc: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1067bcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1067c0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1067c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1067c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1067C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1067C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1067C4u;
            // 0x1067c8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x106768u: goto label_106768;
            case 0x106778u: goto label_106778;
            case 0x10678Cu: goto label_10678c;
            case 0x106794u: goto label_106794;
            case 0x10679Cu: goto label_10679c;
            case 0x1067A8u: goto label_1067a8;
            case 0x106818u: goto label_106818;
            case 0x106828u: goto label_106828;
            case 0x106830u: goto label_106830;
            case 0x10683Cu: goto label_10683c;
            case 0x10689Cu: goto label_10689c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1067CCu;
    // 0x1067cc: 0x0  nop
    ctx->pc = 0x1067ccu;
    // NOP
    // 0x1067d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1067d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1067d4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1067d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1067d8: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x1067d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x1067dc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1067dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1067e0: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1067e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1067e4: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1067e4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1067e8: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x1067e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1067ec: 0x2518018  mult        $s0, $s2, $s1
    ctx->pc = 0x1067ecu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 16, (int32_t)result); }
    // 0x1067f0: 0xafa40010  sw          $a0, 0x10($sp)
    ctx->pc = 0x1067f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 4));
    // 0x1067f4: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x1067f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1067f8: 0x27a20010  addiu       $v0, $sp, 0x10
    ctx->pc = 0x1067f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1067fc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1067fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106800: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x106800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x106804: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x106804u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x106808: 0xafa30004  sw          $v1, 0x4($sp)
    ctx->pc = 0x106808u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    // 0x10680c: 0xafb00014  sw          $s0, 0x14($sp)
    ctx->pc = 0x10680cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 16));
    // 0x106810: 0xc0418d6  jal         func_106358
    ctx->pc = 0x106810u;
    SET_GPR_U32(ctx, 31, 0x106818u);
    ctx->pc = 0x106814u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106810u;
            // 0x106814: 0xafb00008  sw          $s0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106358u;
    if (runtime->hasFunction(0x106358u)) {
        auto targetFn = runtime->lookupFunction(0x106358u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106818u; }
        if (ctx->pc != 0x106818u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106358_0x106358(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106818u; }
        if (ctx->pc != 0x106818u) { return; }
    }
    ctx->pc = 0x106818u;
label_106818:
    // 0x106818: 0x54400003  bnel        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x106818u;
    {
        const bool branch_taken_0x106818 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x106818) {
            ctx->pc = 0x10681Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106818u;
            // 0x10681c: 0x8fa20008  lw          $v0, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106828u;
            goto label_106828;
        }
    }
    ctx->pc = 0x106820u;
    // 0x106820: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x106820u;
    {
        const bool branch_taken_0x106820 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106820u;
            // 0x106824: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106820) {
            ctx->pc = 0x10683Cu;
            goto label_10683c;
        }
    }
    ctx->pc = 0x106828u;
label_106828:
    // 0x106828: 0x52200001  beql        $s1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x106828u;
    {
        const bool branch_taken_0x106828 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x106828) {
            ctx->pc = 0x10682Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106828u;
            // 0x10682c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x106830u;
            goto label_106830;
        }
    }
    ctx->pc = 0x106830u;
label_106830:
    // 0x106830: 0x2021023  subu        $v0, $s0, $v0
    ctx->pc = 0x106830u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x106834: 0x51001b  divu        $zero, $v0, $s1
    ctx->pc = 0x106834u;
    { uint32_t divisor = GPR_U32(ctx, 17); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
    // 0x106838: 0x1012  mflo        $v0
    ctx->pc = 0x106838u;
    SET_GPR_U64(ctx, 2, ctx->lo);
label_10683c:
    // 0x10683c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x10683cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x106840: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x106840u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x106844: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x106844u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x106848: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x106848u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x10684c: 0x3e00008  jr          $ra
    ctx->pc = 0x10684Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10684Cu;
            // 0x106850: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x106768u: goto label_106768;
            case 0x106778u: goto label_106778;
            case 0x10678Cu: goto label_10678c;
            case 0x106794u: goto label_106794;
            case 0x10679Cu: goto label_10679c;
            case 0x1067A8u: goto label_1067a8;
            case 0x106818u: goto label_106818;
            case 0x106828u: goto label_106828;
            case 0x106830u: goto label_106830;
            case 0x10683Cu: goto label_10683c;
            case 0x10689Cu: goto label_10689c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106854u;
    // 0x106854: 0x0  nop
    ctx->pc = 0x106854u;
    // NOP
    // 0x106858: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x106858u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10685c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x10685cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x106860: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x106860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x106864: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x106864u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106868: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x106868u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10686c: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x10686cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x106870: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x106870u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106874: 0x8041a2a  j           func_1068A8
    ctx->pc = 0x106874u;
    ctx->pc = 0x106878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106874u;
            // 0x106878: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1068A8u;
    if (runtime->hasFunction(0x1068A8u)) {
        auto targetFn = runtime->lookupFunction(0x1068A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001068A8_0x1068a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10687Cu;
    // 0x10687c: 0x0  nop
    ctx->pc = 0x10687cu;
    // NOP
    // 0x106880: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x106880u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x106884: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x106884u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x106888: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x106888u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10688c: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x10688cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x106890: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x106890u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x106894: 0xc041a2a  jal         func_1068A8
    ctx->pc = 0x106894u;
    SET_GPR_U32(ctx, 31, 0x10689Cu);
    ctx->pc = 0x106898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106894u;
            // 0x106898: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1068A8u;
    if (runtime->hasFunction(0x1068A8u)) {
        auto targetFn = runtime->lookupFunction(0x1068A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10689Cu; }
        if (ctx->pc != 0x10689Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001068A8_0x1068a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10689Cu; }
        if (ctx->pc != 0x10689Cu) { return; }
    }
    ctx->pc = 0x10689Cu;
label_10689c:
    // 0x10689c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x10689cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1068a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1068A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1068A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1068A0u;
            // 0x1068a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x106768u: goto label_106768;
            case 0x106778u: goto label_106778;
            case 0x10678Cu: goto label_10678c;
            case 0x106794u: goto label_106794;
            case 0x10679Cu: goto label_10679c;
            case 0x1067A8u: goto label_1067a8;
            case 0x106818u: goto label_106818;
            case 0x106828u: goto label_106828;
            case 0x106830u: goto label_106830;
            case 0x10683Cu: goto label_10683c;
            case 0x10689Cu: goto label_10689c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1068A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
