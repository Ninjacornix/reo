#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136878
// Address: 0x136878 - 0x136934
void sub_00136878_0x136878(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136878_0x136878");
#endif

    switch (ctx->pc) {
        case 0x1368b4u: goto label_1368b4;
        case 0x1368dcu: goto label_1368dc;
        case 0x1368f4u: goto label_1368f4;
        case 0x136908u: goto label_136908;
        case 0x13691cu: goto label_13691c;
        default: break;
    }

    ctx->pc = 0x136878u;

    // 0x136878: 0x27bdfd80  addiu       $sp, $sp, -0x280
    ctx->pc = 0x136878u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966656));
    // 0x13687c: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x13687cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x136880: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x136880u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136884: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x136884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x136888: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136888u;
    {
        const bool branch_taken_0x136888 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x13688Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136888u;
            // 0x13688c: 0xffbf0270  sd          $ra, 0x270($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136888) {
            ctx->pc = 0x1368A0u;
            goto label_1368a0;
        }
    }
    ctx->pc = 0x136890u;
    // 0x136890: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136890u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136894: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x136894u;
    {
        const bool branch_taken_0x136894 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136894u;
            // 0x136898: 0x2484bf70  addiu       $a0, $a0, -0x4090 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136894) {
            ctx->pc = 0x136914u;
            goto label_136914;
        }
    }
    ctx->pc = 0x13689Cu;
    // 0x13689c: 0x0  nop
    ctx->pc = 0x13689cu;
    // NOP
label_1368a0:
    // 0x1368a0: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x1368a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x1368a4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1368a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1368a8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1368a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1368ac: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x1368ACu;
    SET_GPR_U32(ctx, 31, 0x1368B4u);
    ctx->pc = 0x1368B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1368ACu;
            // 0x1368b0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1368B4u; }
        if (ctx->pc != 0x1368B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1368B4u; }
        if (ctx->pc != 0x1368B4u) { return; }
    }
    ctx->pc = 0x1368B4u;
label_1368b4:
    // 0x1368b4: 0x83a20130  lb          $v0, 0x130($sp)
    ctx->pc = 0x1368b4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x1368b8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1368B8u;
    {
        const bool branch_taken_0x1368b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1368BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1368B8u;
            // 0x1368bc: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1368b8) {
            ctx->pc = 0x1368D0u;
            goto label_1368d0;
        }
    }
    ctx->pc = 0x1368C0u;
    // 0x1368c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1368c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1368c4: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1368C4u;
    {
        const bool branch_taken_0x1368c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1368C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1368C4u;
            // 0x1368c8: 0x2484bf70  addiu       $a0, $a0, -0x4090 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1368c4) {
            ctx->pc = 0x136914u;
            goto label_136914;
        }
    }
    ctx->pc = 0x1368CCu;
    // 0x1368cc: 0x0  nop
    ctx->pc = 0x1368ccu;
    // NOP
label_1368d0:
    // 0x1368d0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1368d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1368d4: 0xc04d622  jal         func_135888
    ctx->pc = 0x1368D4u;
    SET_GPR_U32(ctx, 31, 0x1368DCu);
    ctx->pc = 0x1368D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1368D4u;
            // 0x1368d8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1368DCu; }
        if (ctx->pc != 0x1368DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1368DCu; }
        if (ctx->pc != 0x1368DCu) { return; }
    }
    ctx->pc = 0x1368DCu;
label_1368dc:
    // 0x1368dc: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1368dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1368e0: 0x56000005  bnel        $s0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1368E0u;
    {
        const bool branch_taken_0x1368e0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1368e0) {
            ctx->pc = 0x1368E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1368E0u;
            // 0x1368e4: 0x8e020054  lw          $v0, 0x54($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1368F8u;
            goto label_1368f8;
        }
    }
    ctx->pc = 0x1368E8u;
    // 0x1368e8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1368e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1368ec: 0xc04d480  jal         func_135200
    ctx->pc = 0x1368ECu;
    SET_GPR_U32(ctx, 31, 0x1368F4u);
    ctx->pc = 0x1368F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1368ECu;
            // 0x1368f0: 0x2484bfc0  addiu       $a0, $a0, -0x4040 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950848));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1368F4u; }
        if (ctx->pc != 0x1368F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1368F4u; }
        if (ctx->pc != 0x1368F4u) { return; }
    }
    ctx->pc = 0x1368F4u;
label_1368f4:
    // 0x1368f4: 0x8e020054  lw          $v0, 0x54($s0)
    ctx->pc = 0x1368f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
label_1368f8:
    // 0x1368f8: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1368F8u;
    {
        const bool branch_taken_0x1368f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1368f8) {
            ctx->pc = 0x1368FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1368F8u;
            // 0x1368fc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136910u;
            goto label_136910;
        }
    }
    ctx->pc = 0x136900u;
    // 0x136900: 0x40f809  jalr        $v0
    ctx->pc = 0x136900u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136908u);
        ctx->pc = 0x136904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136900u;
            // 0x136904: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136908u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136908u; }
            if (ctx->pc != 0x136908u) { return; }
        }
        }
    }
    ctx->pc = 0x136908u;
label_136908:
    // 0x136908: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x136908u;
    {
        const bool branch_taken_0x136908 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13690Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136908u;
            // 0x13690c: 0xdfb00260  ld          $s0, 0x260($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136908) {
            ctx->pc = 0x136924u;
            goto label_136924;
        }
    }
    ctx->pc = 0x136910u;
label_136910:
    // 0x136910: 0x2484bfe8  addiu       $a0, $a0, -0x4018
    ctx->pc = 0x136910u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950888));
label_136914:
    // 0x136914: 0xc04d480  jal         func_135200
    ctx->pc = 0x136914u;
    SET_GPR_U32(ctx, 31, 0x13691Cu);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13691Cu; }
        if (ctx->pc != 0x13691Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13691Cu; }
        if (ctx->pc != 0x13691Cu) { return; }
    }
    ctx->pc = 0x13691Cu;
label_13691c:
    // 0x13691c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x13691cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x136920: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x136920u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
label_136924:
    // 0x136924: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x136924u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x136928: 0xdfbf0270  ld          $ra, 0x270($sp)
    ctx->pc = 0x136928u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x13692c: 0x3e00008  jr          $ra
    ctx->pc = 0x13692Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13692Cu;
            // 0x136930: 0x27bd0280  addiu       $sp, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136934u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
