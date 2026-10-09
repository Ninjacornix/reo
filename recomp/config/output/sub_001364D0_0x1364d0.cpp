#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001364D0
// Address: 0x1364d0 - 0x136574
void sub_001364D0_0x1364d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001364D0_0x1364d0");
#endif

    switch (ctx->pc) {
        case 0x1364f8u: goto label_1364f8;
        case 0x136518u: goto label_136518;
        case 0x136530u: goto label_136530;
        case 0x136544u: goto label_136544;
        case 0x13655cu: goto label_13655c;
        default: break;
    }

    ctx->pc = 0x1364d0u;

    // 0x1364d0: 0x27bdfd80  addiu       $sp, $sp, -0x280
    ctx->pc = 0x1364d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966656));
    // 0x1364d4: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x1364d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x1364d8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1364d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1364dc: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x1364dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x1364e0: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x1364e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x1364e4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1364e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1364e8: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1364e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1364ec: 0xffbf0270  sd          $ra, 0x270($sp)
    ctx->pc = 0x1364ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 31));
    // 0x1364f0: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x1364F0u;
    SET_GPR_U32(ctx, 31, 0x1364F8u);
    ctx->pc = 0x1364F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1364F0u;
            // 0x1364f4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1364F8u; }
        if (ctx->pc != 0x1364F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1364F8u; }
        if (ctx->pc != 0x1364F8u) { return; }
    }
    ctx->pc = 0x1364F8u;
label_1364f8:
    // 0x1364f8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1364f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1364fc: 0x83a20130  lb          $v0, 0x130($sp)
    ctx->pc = 0x1364fcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x136500: 0x2484bdf8  addiu       $a0, $a0, -0x4208
    ctx->pc = 0x136500u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950392));
    // 0x136504: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x136504u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136508: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x136508u;
    {
        const bool branch_taken_0x136508 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13650Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136508u;
            // 0x13650c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136508) {
            ctx->pc = 0x136554u;
            goto label_136554;
        }
    }
    ctx->pc = 0x136510u;
    // 0x136510: 0xc04d622  jal         func_135888
    ctx->pc = 0x136510u;
    SET_GPR_U32(ctx, 31, 0x136518u);
    ctx->pc = 0x136514u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136510u;
            // 0x136514: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136518u; }
        if (ctx->pc != 0x136518u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136518u; }
        if (ctx->pc != 0x136518u) { return; }
    }
    ctx->pc = 0x136518u;
label_136518:
    // 0x136518: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136518u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13651c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x13651cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136520: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x136520u;
    {
        const bool branch_taken_0x136520 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x136524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136520u;
            // 0x136524: 0x2484be48  addiu       $a0, $a0, -0x41B8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950472));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136520) {
            ctx->pc = 0x136530u;
            goto label_136530;
        }
    }
    ctx->pc = 0x136528u;
    // 0x136528: 0xc04d480  jal         func_135200
    ctx->pc = 0x136528u;
    SET_GPR_U32(ctx, 31, 0x136530u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136530u; }
        if (ctx->pc != 0x136530u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136530u; }
        if (ctx->pc != 0x136530u) { return; }
    }
    ctx->pc = 0x136530u;
label_136530:
    // 0x136530: 0x8e020040  lw          $v0, 0x40($s0)
    ctx->pc = 0x136530u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x136534: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x136534u;
    {
        const bool branch_taken_0x136534 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136534) {
            ctx->pc = 0x136538u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136534u;
            // 0x136538: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136550u;
            goto label_136550;
        }
    }
    ctx->pc = 0x13653Cu;
    // 0x13653c: 0x40f809  jalr        $v0
    ctx->pc = 0x13653Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136544u);
        ctx->pc = 0x136540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13653Cu;
            // 0x136540: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136544u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136544u; }
            if (ctx->pc != 0x136544u) { return; }
        }
        }
    }
    ctx->pc = 0x136544u;
label_136544:
    // 0x136544: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x136544u;
    {
        const bool branch_taken_0x136544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136544u;
            // 0x136548: 0xdfb00260  ld          $s0, 0x260($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136544) {
            ctx->pc = 0x136564u;
            goto label_136564;
        }
    }
    ctx->pc = 0x13654Cu;
    // 0x13654c: 0x0  nop
    ctx->pc = 0x13654cu;
    // NOP
label_136550:
    // 0x136550: 0x2484be70  addiu       $a0, $a0, -0x4190
    ctx->pc = 0x136550u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950512));
label_136554:
    // 0x136554: 0xc04d480  jal         func_135200
    ctx->pc = 0x136554u;
    SET_GPR_U32(ctx, 31, 0x13655Cu);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13655Cu; }
        if (ctx->pc != 0x13655Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13655Cu; }
        if (ctx->pc != 0x13655Cu) { return; }
    }
    ctx->pc = 0x13655Cu;
label_13655c:
    // 0x13655c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13655cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136560: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x136560u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
label_136564:
    // 0x136564: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x136564u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x136568: 0xdfbf0270  ld          $ra, 0x270($sp)
    ctx->pc = 0x136568u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x13656c: 0x3e00008  jr          $ra
    ctx->pc = 0x13656Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13656Cu;
            // 0x136570: 0x27bd0280  addiu       $sp, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136574u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
