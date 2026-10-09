#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015A860
// Address: 0x15a860 - 0x15a950
void sub_0015A860_0x15a860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015A860_0x15a860");
#endif

    switch (ctx->pc) {
        case 0x15a8a0u: goto label_15a8a0;
        case 0x15a8f8u: goto label_15a8f8;
        case 0x15a910u: goto label_15a910;
        case 0x15a928u: goto label_15a928;
        case 0x15a930u: goto label_15a930;
        default: break;
    }

    ctx->pc = 0x15a860u;

    // 0x15a860: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15a860u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15a864: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x15a864u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x15a868: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15a868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15a86c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15a86cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a870: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15a870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x15a874: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x15a874u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x15a878: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x15a878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x15a87c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x15a87cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a880: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x15a880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x15a884: 0x26510348  addiu       $s1, $s2, 0x348
    ctx->pc = 0x15a884u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 840));
    // 0x15a888: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15a888u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a88c: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x15a88cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a890: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x15a890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15a894: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x15a894u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x15a898: 0x60f809  jalr        $v1
    ctx->pc = 0x15A898u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x15A8A0u);
        ctx->pc = 0x15A89Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A898u;
            // 0x15a89c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15A8A0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A8A0u: goto label_15a8a0;
            case 0x15A8D4u: goto label_15a8d4;
            case 0x15A8F8u: goto label_15a8f8;
            case 0x15A910u: goto label_15a910;
            case 0x15A928u: goto label_15a928;
            case 0x15A930u: goto label_15a930;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15A8A0u; }
            if (ctx->pc != 0x15A8A0u) { return; }
        }
        }
    }
    ctx->pc = 0x15A8A0u;
label_15a8a0:
    // 0x15a8a0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15a8a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a8a4: 0x8e290000  lw          $t1, 0x0($s1)
    ctx->pc = 0x15a8a4u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15a8a8: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x15a8a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x15a8ac: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x15a8acu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a8b0: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x15a8b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a8b4: 0x1224024  and         $t0, $t1, $v0
    ctx->pc = 0x15a8b4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 9) & GPR_U64(ctx, 2));
    // 0x15a8b8: 0x1281823  subu        $v1, $t1, $t0
    ctx->pc = 0x15a8b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
    // 0x15a8bc: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x15a8bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x15a8c0: 0x28620020  slti        $v0, $v1, 0x20
    ctx->pc = 0x15a8c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x15a8c4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15A8C4u;
    {
        const bool branch_taken_0x15a8c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15A8C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A8C4u;
            // 0x15a8c8: 0x25080008  addiu       $t0, $t0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a8c4) {
            ctx->pc = 0x15A8D4u;
            goto label_15a8d4;
        }
    }
    ctx->pc = 0x15A8CCu;
    // 0x15a8cc: 0x2463ffe0  addiu       $v1, $v1, -0x20
    ctx->pc = 0x15a8ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967264));
    // 0x15a8d0: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x15a8d0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
label_15a8d4:
    // 0x15a8d4: 0x30620007  andi        $v0, $v1, 0x7
    ctx->pc = 0x15a8d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)7);
    // 0x15a8d8: 0x622823  subu        $a1, $v1, $v0
    ctx->pc = 0x15a8d8u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x15a8dc: 0xae420350  sw          $v0, 0x350($s2)
    ctx->pc = 0x15a8dcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 848), GPR_U32(ctx, 2));
    // 0x15a8e0: 0x24a50007  addiu       $a1, $a1, 0x7
    ctx->pc = 0x15a8e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7));
    // 0x15a8e4: 0x528c3  sra         $a1, $a1, 3
    ctx->pc = 0x15a8e4u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 3));
    // 0x15a8e8: 0x1052821  addu        $a1, $t0, $a1
    ctx->pc = 0x15a8e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x15a8ec: 0x24a5fffc  addiu       $a1, $a1, -0x4
    ctx->pc = 0x15a8ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967292));
    // 0x15a8f0: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x15A8F0u;
    SET_GPR_U32(ctx, 31, 0x15A8F8u);
    ctx->pc = 0x15A8F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15A8F0u;
            // 0x15a8f4: 0xa92823  subu        $a1, $a1, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15A8F8u; }
        if (ctx->pc != 0x15A8F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15A8F8u; }
        if (ctx->pc != 0x15A8F8u) { return; }
    }
    ctx->pc = 0x15A8F8u;
label_15a8f8:
    // 0x15a8f8: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15a8f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15a8fc: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x15a8fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a900: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15a900u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a904: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x15a904u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x15a908: 0x40f809  jalr        $v0
    ctx->pc = 0x15A908u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15A910u);
        ctx->pc = 0x15A90Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A908u;
            // 0x15a90c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15A910u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A8A0u: goto label_15a8a0;
            case 0x15A8D4u: goto label_15a8d4;
            case 0x15A8F8u: goto label_15a8f8;
            case 0x15A910u: goto label_15a910;
            case 0x15A928u: goto label_15a928;
            case 0x15A930u: goto label_15a930;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15A910u; }
            if (ctx->pc != 0x15A910u) { return; }
        }
        }
    }
    ctx->pc = 0x15A910u;
label_15a910:
    // 0x15a910: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15a910u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15a914: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15a914u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15a918: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x15a918u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a91c: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x15a91cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x15a920: 0x40f809  jalr        $v0
    ctx->pc = 0x15A920u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15A928u);
        ctx->pc = 0x15A924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A920u;
            // 0x15a924: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15A928u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A8A0u: goto label_15a8a0;
            case 0x15A8D4u: goto label_15a8d4;
            case 0x15A8F8u: goto label_15a8f8;
            case 0x15A910u: goto label_15a910;
            case 0x15A928u: goto label_15a928;
            case 0x15A930u: goto label_15a930;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15A928u; }
            if (ctx->pc != 0x15A928u) { return; }
        }
        }
    }
    ctx->pc = 0x15A928u;
label_15a928:
    // 0x15a928: 0xc056b7a  jal         func_15ADE8
    ctx->pc = 0x15A928u;
    SET_GPR_U32(ctx, 31, 0x15A930u);
    ctx->pc = 0x15A92Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15A928u;
            // 0x15a92c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15ADE8u;
    if (runtime->hasFunction(0x15ADE8u)) {
        auto targetFn = runtime->lookupFunction(0x15ADE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15A930u; }
        if (ctx->pc != 0x15A930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015ADE8_0x15ade8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15A930u; }
        if (ctx->pc != 0x15A930u) { return; }
    }
    ctx->pc = 0x15A930u;
label_15a930:
    // 0x15a930: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15a930u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a934: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15a934u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15a938: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15a938u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15a93c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x15a93cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15a940: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x15a940u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15a944: 0x3e00008  jr          $ra
    ctx->pc = 0x15A944u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15A948u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A944u;
            // 0x15a948: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A8A0u: goto label_15a8a0;
            case 0x15A8D4u: goto label_15a8d4;
            case 0x15A8F8u: goto label_15a8f8;
            case 0x15A910u: goto label_15a910;
            case 0x15A928u: goto label_15a928;
            case 0x15A930u: goto label_15a930;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15A94Cu;
    // 0x15a94c: 0x0  nop
    ctx->pc = 0x15a94cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
