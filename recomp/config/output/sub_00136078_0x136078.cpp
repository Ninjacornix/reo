#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136078
// Address: 0x136078 - 0x136144
void sub_00136078_0x136078(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136078_0x136078");
#endif

    switch (ctx->pc) {
        case 0x1360bcu: goto label_1360bc;
        case 0x1360e4u: goto label_1360e4;
        case 0x1360fcu: goto label_1360fc;
        case 0x136110u: goto label_136110;
        case 0x136128u: goto label_136128;
        default: break;
    }

    ctx->pc = 0x136078u;

    // 0x136078: 0x27bdfd80  addiu       $sp, $sp, -0x280
    ctx->pc = 0x136078u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966656));
    // 0x13607c: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x13607cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x136080: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x136080u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136084: 0xffb20270  sd          $s2, 0x270($sp)
    ctx->pc = 0x136084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 18));
    // 0x136088: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x136088u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13608c: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x13608cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x136090: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136090u;
    {
        const bool branch_taken_0x136090 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x136094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136090u;
            // 0x136094: 0xffbf0278  sd          $ra, 0x278($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 632), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136090) {
            ctx->pc = 0x1360A8u;
            goto label_1360a8;
        }
    }
    ctx->pc = 0x136098u;
    // 0x136098: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136098u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13609c: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x13609Cu;
    {
        const bool branch_taken_0x13609c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1360A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13609Cu;
            // 0x1360a0: 0x2484bb88  addiu       $a0, $a0, -0x4478 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13609c) {
            ctx->pc = 0x136120u;
            goto label_136120;
        }
    }
    ctx->pc = 0x1360A4u;
    // 0x1360a4: 0x0  nop
    ctx->pc = 0x1360a4u;
    // NOP
label_1360a8:
    // 0x1360a8: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x1360a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x1360ac: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1360acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1360b0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1360b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1360b4: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x1360B4u;
    SET_GPR_U32(ctx, 31, 0x1360BCu);
    ctx->pc = 0x1360B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1360B4u;
            // 0x1360b8: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1360BCu; }
        if (ctx->pc != 0x1360BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1360BCu; }
        if (ctx->pc != 0x1360BCu) { return; }
    }
    ctx->pc = 0x1360BCu;
label_1360bc:
    // 0x1360bc: 0x83a20130  lb          $v0, 0x130($sp)
    ctx->pc = 0x1360bcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x1360c0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1360C0u;
    {
        const bool branch_taken_0x1360c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1360C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1360C0u;
            // 0x1360c4: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1360c0) {
            ctx->pc = 0x1360D8u;
            goto label_1360d8;
        }
    }
    ctx->pc = 0x1360C8u;
    // 0x1360c8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1360c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1360cc: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1360CCu;
    {
        const bool branch_taken_0x1360cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1360D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1360CCu;
            // 0x1360d0: 0x2484bb88  addiu       $a0, $a0, -0x4478 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1360cc) {
            ctx->pc = 0x136120u;
            goto label_136120;
        }
    }
    ctx->pc = 0x1360D4u;
    // 0x1360d4: 0x0  nop
    ctx->pc = 0x1360d4u;
    // NOP
label_1360d8:
    // 0x1360d8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1360d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1360dc: 0xc04d622  jal         func_135888
    ctx->pc = 0x1360DCu;
    SET_GPR_U32(ctx, 31, 0x1360E4u);
    ctx->pc = 0x1360E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1360DCu;
            // 0x1360e0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1360E4u; }
        if (ctx->pc != 0x1360E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1360E4u; }
        if (ctx->pc != 0x1360E4u) { return; }
    }
    ctx->pc = 0x1360E4u;
label_1360e4:
    // 0x1360e4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1360e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1360e8: 0x56000005  bnel        $s0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1360E8u;
    {
        const bool branch_taken_0x1360e8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1360e8) {
            ctx->pc = 0x1360ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1360E8u;
            // 0x1360ec: 0x8e02005c  lw          $v0, 0x5C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 92)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136100u;
            goto label_136100;
        }
    }
    ctx->pc = 0x1360F0u;
    // 0x1360f0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1360f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1360f4: 0xc04d480  jal         func_135200
    ctx->pc = 0x1360F4u;
    SET_GPR_U32(ctx, 31, 0x1360FCu);
    ctx->pc = 0x1360F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1360F4u;
            // 0x1360f8: 0x2484bbe0  addiu       $a0, $a0, -0x4420 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949856));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1360FCu; }
        if (ctx->pc != 0x1360FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1360FCu; }
        if (ctx->pc != 0x1360FCu) { return; }
    }
    ctx->pc = 0x1360FCu;
label_1360fc:
    // 0x1360fc: 0x8e02005c  lw          $v0, 0x5C($s0)
    ctx->pc = 0x1360fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 92)));
label_136100:
    // 0x136100: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136100u;
    {
        const bool branch_taken_0x136100 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136100u;
            // 0x136104: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136100) {
            ctx->pc = 0x136118u;
            goto label_136118;
        }
    }
    ctx->pc = 0x136108u;
    // 0x136108: 0x40f809  jalr        $v0
    ctx->pc = 0x136108u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136110u);
        ctx->pc = 0x13610Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136108u;
            // 0x13610c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136110u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136110u; }
            if (ctx->pc != 0x136110u) { return; }
        }
        }
    }
    ctx->pc = 0x136110u;
label_136110:
    // 0x136110: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x136110u;
    {
        const bool branch_taken_0x136110 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136110u;
            // 0x136114: 0xdfb00260  ld          $s0, 0x260($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136110) {
            ctx->pc = 0x136130u;
            goto label_136130;
        }
    }
    ctx->pc = 0x136118u;
label_136118:
    // 0x136118: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136118u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13611c: 0x2484bc08  addiu       $a0, $a0, -0x43F8
    ctx->pc = 0x13611cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949896));
label_136120:
    // 0x136120: 0xc04d480  jal         func_135200
    ctx->pc = 0x136120u;
    SET_GPR_U32(ctx, 31, 0x136128u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136128u; }
        if (ctx->pc != 0x136128u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136128u; }
        if (ctx->pc != 0x136128u) { return; }
    }
    ctx->pc = 0x136128u;
label_136128:
    // 0x136128: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x136128u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13612c: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x13612cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
label_136130:
    // 0x136130: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x136130u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x136134: 0xdfb20270  ld          $s2, 0x270($sp)
    ctx->pc = 0x136134u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x136138: 0xdfbf0278  ld          $ra, 0x278($sp)
    ctx->pc = 0x136138u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 632)));
    // 0x13613c: 0x3e00008  jr          $ra
    ctx->pc = 0x13613Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13613Cu;
            // 0x136140: 0x27bd0280  addiu       $sp, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136144u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
