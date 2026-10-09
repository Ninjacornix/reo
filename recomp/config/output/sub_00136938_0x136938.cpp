#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136938
// Address: 0x136938 - 0x1369f4
void sub_00136938_0x136938(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136938_0x136938");
#endif

    switch (ctx->pc) {
        case 0x136974u: goto label_136974;
        case 0x13699cu: goto label_13699c;
        case 0x1369b4u: goto label_1369b4;
        case 0x1369c8u: goto label_1369c8;
        case 0x1369dcu: goto label_1369dc;
        default: break;
    }

    ctx->pc = 0x136938u;

    // 0x136938: 0x27bdfd80  addiu       $sp, $sp, -0x280
    ctx->pc = 0x136938u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966656));
    // 0x13693c: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x13693cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x136940: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x136940u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136944: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x136944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x136948: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136948u;
    {
        const bool branch_taken_0x136948 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x13694Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136948u;
            // 0x13694c: 0xffbf0270  sd          $ra, 0x270($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136948) {
            ctx->pc = 0x136960u;
            goto label_136960;
        }
    }
    ctx->pc = 0x136950u;
    // 0x136950: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136950u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136954: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x136954u;
    {
        const bool branch_taken_0x136954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136954u;
            // 0x136958: 0x2484c008  addiu       $a0, $a0, -0x3FF8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950920));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136954) {
            ctx->pc = 0x1369D4u;
            goto label_1369d4;
        }
    }
    ctx->pc = 0x13695Cu;
    // 0x13695c: 0x0  nop
    ctx->pc = 0x13695cu;
    // NOP
label_136960:
    // 0x136960: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x136960u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x136964: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136964u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136968: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x136968u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13696c: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x13696Cu;
    SET_GPR_U32(ctx, 31, 0x136974u);
    ctx->pc = 0x136970u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13696Cu;
            // 0x136970: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136974u; }
        if (ctx->pc != 0x136974u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136974u; }
        if (ctx->pc != 0x136974u) { return; }
    }
    ctx->pc = 0x136974u;
label_136974:
    // 0x136974: 0x83a20130  lb          $v0, 0x130($sp)
    ctx->pc = 0x136974u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x136978: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136978u;
    {
        const bool branch_taken_0x136978 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13697Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136978u;
            // 0x13697c: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136978) {
            ctx->pc = 0x136990u;
            goto label_136990;
        }
    }
    ctx->pc = 0x136980u;
    // 0x136980: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136980u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136984: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x136984u;
    {
        const bool branch_taken_0x136984 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136984u;
            // 0x136988: 0x2484c008  addiu       $a0, $a0, -0x3FF8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950920));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136984) {
            ctx->pc = 0x1369D4u;
            goto label_1369d4;
        }
    }
    ctx->pc = 0x13698Cu;
    // 0x13698c: 0x0  nop
    ctx->pc = 0x13698cu;
    // NOP
label_136990:
    // 0x136990: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136990u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136994: 0xc04d622  jal         func_135888
    ctx->pc = 0x136994u;
    SET_GPR_U32(ctx, 31, 0x13699Cu);
    ctx->pc = 0x136998u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136994u;
            // 0x136998: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13699Cu; }
        if (ctx->pc != 0x13699Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13699Cu; }
        if (ctx->pc != 0x13699Cu) { return; }
    }
    ctx->pc = 0x13699Cu;
label_13699c:
    // 0x13699c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x13699cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1369a0: 0x56000005  bnel        $s0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1369A0u;
    {
        const bool branch_taken_0x1369a0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1369a0) {
            ctx->pc = 0x1369A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1369A0u;
            // 0x1369a4: 0x8e020058  lw          $v0, 0x58($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 88)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1369B8u;
            goto label_1369b8;
        }
    }
    ctx->pc = 0x1369A8u;
    // 0x1369a8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1369a8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1369ac: 0xc04d480  jal         func_135200
    ctx->pc = 0x1369ACu;
    SET_GPR_U32(ctx, 31, 0x1369B4u);
    ctx->pc = 0x1369B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1369ACu;
            // 0x1369b0: 0x2484c058  addiu       $a0, $a0, -0x3FA8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951000));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1369B4u; }
        if (ctx->pc != 0x1369B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1369B4u; }
        if (ctx->pc != 0x1369B4u) { return; }
    }
    ctx->pc = 0x1369B4u;
label_1369b4:
    // 0x1369b4: 0x8e020058  lw          $v0, 0x58($s0)
    ctx->pc = 0x1369b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 88)));
label_1369b8:
    // 0x1369b8: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1369B8u;
    {
        const bool branch_taken_0x1369b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1369b8) {
            ctx->pc = 0x1369BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1369B8u;
            // 0x1369bc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1369D0u;
            goto label_1369d0;
        }
    }
    ctx->pc = 0x1369C0u;
    // 0x1369c0: 0x40f809  jalr        $v0
    ctx->pc = 0x1369C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1369C8u);
        ctx->pc = 0x1369C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1369C0u;
            // 0x1369c4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1369C8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1369C8u; }
            if (ctx->pc != 0x1369C8u) { return; }
        }
        }
    }
    ctx->pc = 0x1369C8u;
label_1369c8:
    // 0x1369c8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1369C8u;
    {
        const bool branch_taken_0x1369c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1369CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1369C8u;
            // 0x1369cc: 0xdfb00260  ld          $s0, 0x260($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1369c8) {
            ctx->pc = 0x1369E4u;
            goto label_1369e4;
        }
    }
    ctx->pc = 0x1369D0u;
label_1369d0:
    // 0x1369d0: 0x2484c080  addiu       $a0, $a0, -0x3F80
    ctx->pc = 0x1369d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951040));
label_1369d4:
    // 0x1369d4: 0xc04d480  jal         func_135200
    ctx->pc = 0x1369D4u;
    SET_GPR_U32(ctx, 31, 0x1369DCu);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1369DCu; }
        if (ctx->pc != 0x1369DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1369DCu; }
        if (ctx->pc != 0x1369DCu) { return; }
    }
    ctx->pc = 0x1369DCu;
label_1369dc:
    // 0x1369dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1369dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1369e0: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x1369e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
label_1369e4:
    // 0x1369e4: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x1369e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x1369e8: 0xdfbf0270  ld          $ra, 0x270($sp)
    ctx->pc = 0x1369e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x1369ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1369ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1369F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1369ECu;
            // 0x1369f0: 0x27bd0280  addiu       $sp, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1369F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
