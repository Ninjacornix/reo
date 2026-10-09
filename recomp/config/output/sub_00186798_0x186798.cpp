#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00186798
// Address: 0x186798 - 0x1868c8
void sub_00186798_0x186798(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00186798_0x186798");
#endif

    switch (ctx->pc) {
        case 0x1867bcu: goto label_1867bc;
        case 0x1867fcu: goto label_1867fc;
        case 0x18680cu: goto label_18680c;
        case 0x186828u: goto label_186828;
        case 0x186858u: goto label_186858;
        case 0x186890u: goto label_186890;
        case 0x1868a0u: goto label_1868a0;
        default: break;
    }

    ctx->pc = 0x186798u;

    // 0x186798: 0x27bdfd50  addiu       $sp, $sp, -0x2B0
    ctx->pc = 0x186798u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966608));
    // 0x18679c: 0xffb00290  sd          $s0, 0x290($sp)
    ctx->pc = 0x18679cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 656), GPR_U64(ctx, 16));
    // 0x1867a0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1867a0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1867a4: 0xffb10298  sd          $s1, 0x298($sp)
    ctx->pc = 0x1867a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 664), GPR_U64(ctx, 17));
    // 0x1867a8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1867a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1867ac: 0xffb202a0  sd          $s2, 0x2A0($sp)
    ctx->pc = 0x1867acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 672), GPR_U64(ctx, 18));
    // 0x1867b0: 0xffbf02a8  sd          $ra, 0x2A8($sp)
    ctx->pc = 0x1867b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 680), GPR_U64(ctx, 31));
    // 0x1867b4: 0xc062210  jal         func_188840
    ctx->pc = 0x1867B4u;
    SET_GPR_U32(ctx, 31, 0x1867BCu);
    ctx->pc = 0x1867B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1867B4u;
            // 0x1867b8: 0x30d2ffff  andi        $s2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x188840u;
    if (runtime->hasFunction(0x188840u)) {
        auto targetFn = runtime->lookupFunction(0x188840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1867BCu; }
        if (ctx->pc != 0x1867BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188840_0x188840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1867BCu; }
        if (ctx->pc != 0x1867BCu) { return; }
    }
    ctx->pc = 0x1867BCu;
label_1867bc:
    // 0x1867bc: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1867BCu;
    {
        const bool branch_taken_0x1867bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1867C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1867BCu;
            // 0x1867c0: 0x24030898  addiu       $v1, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1867bc) {
            ctx->pc = 0x1867D0u;
            goto label_1867d0;
        }
    }
    ctx->pc = 0x1867C4u;
    // 0x1867c4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1867c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1867c8: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x1867C8u;
    {
        const bool branch_taken_0x1867c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1867CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1867C8u;
            // 0x1867cc: 0x34420013  ori         $v0, $v0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1867c8) {
            ctx->pc = 0x1868B0u;
            goto label_1868b0;
        }
    }
    ctx->pc = 0x1867D0u;
label_1867d0:
    // 0x1867d0: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1867d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1867d4: 0x2031818  mult        $v1, $s0, $v1
    ctx->pc = 0x1867d4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1867d8: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x1867d8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x1867dc: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x1867dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1867e0: 0x8c8463d4  lw          $a0, 0x63D4($a0)
    ctx->pc = 0x1867e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 25556)));
    // 0x1867e4: 0x10800032  beqz        $a0, . + 4 + (0x32 << 2)
    ctx->pc = 0x1867E4u;
    {
        const bool branch_taken_0x1867e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1867E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1867E4u;
            // 0x1867e8: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1867e4) {
            ctx->pc = 0x1868B0u;
            goto label_1868b0;
        }
    }
    ctx->pc = 0x1867ECu;
    // 0x1867ec: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1867ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1867f0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1867f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1867f4: 0xc0609a2  jal         func_182688
    ctx->pc = 0x1867F4u;
    SET_GPR_U32(ctx, 31, 0x1867FCu);
    ctx->pc = 0x1867F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1867F4u;
            // 0x1867f8: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182688u;
    if (runtime->hasFunction(0x182688u)) {
        auto targetFn = runtime->lookupFunction(0x182688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1867FCu; }
        if (ctx->pc != 0x1867FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182688_0x182688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1867FCu; }
        if (ctx->pc != 0x1867FCu) { return; }
    }
    ctx->pc = 0x1867FCu;
label_1867fc:
    // 0x1867fc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1867FCu;
    {
        const bool branch_taken_0x1867fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1867fc) {
            ctx->pc = 0x186814u;
            goto label_186814;
        }
    }
    ctx->pc = 0x186804u;
    // 0x186804: 0xc06089c  jal         func_182270
    ctx->pc = 0x186804u;
    SET_GPR_U32(ctx, 31, 0x18680Cu);
    ctx->pc = 0x186808u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186804u;
            // 0x186808: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182270u;
    if (runtime->hasFunction(0x182270u)) {
        auto targetFn = runtime->lookupFunction(0x182270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18680Cu; }
        if (ctx->pc != 0x18680Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182270_0x182270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18680Cu; }
        if (ctx->pc != 0x18680Cu) { return; }
    }
    ctx->pc = 0x18680Cu;
label_18680c:
    // 0x18680c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18680Cu;
    {
        const bool branch_taken_0x18680c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18680c) {
            ctx->pc = 0x186820u;
            goto label_186820;
        }
    }
    ctx->pc = 0x186814u;
label_186814:
    // 0x186814: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186814u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186818: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x186818u;
    {
        const bool branch_taken_0x186818 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18681Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186818u;
            // 0x18681c: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186818) {
            ctx->pc = 0x1868B0u;
            goto label_1868b0;
        }
    }
    ctx->pc = 0x186820u;
label_186820:
    // 0x186820: 0xc060880  jal         func_182200
    ctx->pc = 0x186820u;
    SET_GPR_U32(ctx, 31, 0x186828u);
    ctx->pc = 0x186824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186820u;
            // 0x186824: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182200u;
    if (runtime->hasFunction(0x182200u)) {
        auto targetFn = runtime->lookupFunction(0x182200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186828u; }
        if (ctx->pc != 0x186828u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182200_0x182200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186828u; }
        if (ctx->pc != 0x186828u) { return; }
    }
    ctx->pc = 0x186828u;
label_186828:
    // 0x186828: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x186828u;
    {
        const bool branch_taken_0x186828 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18682Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186828u;
            // 0x18682c: 0x27b10080  addiu       $s1, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186828) {
            ctx->pc = 0x186840u;
            goto label_186840;
        }
    }
    ctx->pc = 0x186830u;
    // 0x186830: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186830u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186834: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x186834u;
    {
        const bool branch_taken_0x186834 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x186838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186834u;
            // 0x186838: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186834) {
            ctx->pc = 0x1868B0u;
            goto label_1868b0;
        }
    }
    ctx->pc = 0x18683Cu;
    // 0x18683c: 0x0  nop
    ctx->pc = 0x18683cu;
    // NOP
label_186840:
    // 0x186840: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x186840u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186844: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x186844u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186848: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x186848u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18684c: 0x27a70280  addiu       $a3, $sp, 0x280
    ctx->pc = 0x18684cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
    // 0x186850: 0xc0610d8  jal         func_184360
    ctx->pc = 0x186850u;
    SET_GPR_U32(ctx, 31, 0x186858u);
    ctx->pc = 0x186854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186850u;
            // 0x186854: 0x27a80284  addiu       $t0, $sp, 0x284 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 644));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184360u;
    if (runtime->hasFunction(0x184360u)) {
        auto targetFn = runtime->lookupFunction(0x184360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186858u; }
        if (ctx->pc != 0x186858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184360_0x184360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186858u; }
        if (ctx->pc != 0x186858u) { return; }
    }
    ctx->pc = 0x186858u;
label_186858:
    // 0x186858: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x186858u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x18685c: 0x34630011  ori         $v1, $v1, 0x11
    ctx->pc = 0x18685cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17);
    // 0x186860: 0x54430014  bnel        $v0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x186860u;
    {
        const bool branch_taken_0x186860 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x186860) {
            ctx->pc = 0x186864u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x186860u;
            // 0x186864: 0xdfb00290  ld          $s0, 0x290($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1868B4u;
            goto label_1868b4;
        }
    }
    ctx->pc = 0x186868u;
    // 0x186868: 0x97a20080  lhu         $v0, 0x80($sp)
    ctx->pc = 0x186868u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x18686c: 0x3243180f  andi        $v1, $s2, 0x180F
    ctx->pc = 0x18686cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)6159);
    // 0x186870: 0x8fa60280  lw          $a2, 0x280($sp)
    ctx->pc = 0x186870u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x186874: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x186874u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186878: 0x3042e7f0  andi        $v0, $v0, 0xE7F0
    ctx->pc = 0x186878u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)59376);
    // 0x18687c: 0x8fa70284  lw          $a3, 0x284($sp)
    ctx->pc = 0x18687cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 644)));
    // 0x186880: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x186880u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x186884: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x186884u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186888: 0xc0612a8  jal         func_184AA0
    ctx->pc = 0x186888u;
    SET_GPR_U32(ctx, 31, 0x186890u);
    ctx->pc = 0x18688Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186888u;
            // 0x18688c: 0xa7a20080  sh          $v0, 0x80($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 128), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184AA0u;
    if (runtime->hasFunction(0x184AA0u)) {
        auto targetFn = runtime->lookupFunction(0x184AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186890u; }
        if (ctx->pc != 0x186890u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184AA0_0x184aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186890u; }
        if (ctx->pc != 0x186890u) { return; }
    }
    ctx->pc = 0x186890u;
label_186890:
    // 0x186890: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x186890u;
    {
        const bool branch_taken_0x186890 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x186890) {
            ctx->pc = 0x186894u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x186890u;
            // 0x186894: 0xdfb00290  ld          $s0, 0x290($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1868B4u;
            goto label_1868b4;
        }
    }
    ctx->pc = 0x186898u;
    // 0x186898: 0xc061bbc  jal         func_186EF0
    ctx->pc = 0x186898u;
    SET_GPR_U32(ctx, 31, 0x1868A0u);
    ctx->pc = 0x18689Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186898u;
            // 0x18689c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186EF0u;
    if (runtime->hasFunction(0x186EF0u)) {
        auto targetFn = runtime->lookupFunction(0x186EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1868A0u; }
        if (ctx->pc != 0x1868A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186EF0_0x186ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1868A0u; }
        if (ctx->pc != 0x1868A0u) { return; }
    }
    ctx->pc = 0x1868A0u;
label_1868a0:
    // 0x1868a0: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x1868a0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x1868a4: 0x3463006f  ori         $v1, $v1, 0x6F
    ctx->pc = 0x1868a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)111);
    // 0x1868a8: 0x2180b  movn        $v1, $zero, $v0
    ctx->pc = 0x1868a8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x1868ac: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1868acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_1868b0:
    // 0x1868b0: 0xdfb00290  ld          $s0, 0x290($sp)
    ctx->pc = 0x1868b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 656)));
label_1868b4:
    // 0x1868b4: 0xdfb10298  ld          $s1, 0x298($sp)
    ctx->pc = 0x1868b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 664)));
    // 0x1868b8: 0xdfb202a0  ld          $s2, 0x2A0($sp)
    ctx->pc = 0x1868b8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 672)));
    // 0x1868bc: 0xdfbf02a8  ld          $ra, 0x2A8($sp)
    ctx->pc = 0x1868bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 680)));
    // 0x1868c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1868C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1868C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1868C0u;
            // 0x1868c4: 0x27bd02b0  addiu       $sp, $sp, 0x2B0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 688));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1867BCu: goto label_1867bc;
            case 0x1867D0u: goto label_1867d0;
            case 0x1867FCu: goto label_1867fc;
            case 0x18680Cu: goto label_18680c;
            case 0x186814u: goto label_186814;
            case 0x186820u: goto label_186820;
            case 0x186828u: goto label_186828;
            case 0x186840u: goto label_186840;
            case 0x186858u: goto label_186858;
            case 0x186890u: goto label_186890;
            case 0x1868A0u: goto label_1868a0;
            case 0x1868B0u: goto label_1868b0;
            case 0x1868B4u: goto label_1868b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1868C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
