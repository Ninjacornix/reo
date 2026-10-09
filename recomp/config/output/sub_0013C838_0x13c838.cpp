#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013C838
// Address: 0x13c838 - 0x13c9e8
void sub_0013C838_0x13c838(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013C838_0x13c838");
#endif

    switch (ctx->pc) {
        case 0x13c87cu: goto label_13c87c;
        case 0x13c894u: goto label_13c894;
        case 0x13c89cu: goto label_13c89c;
        case 0x13c8c8u: goto label_13c8c8;
        case 0x13c8f8u: goto label_13c8f8;
        case 0x13c90cu: goto label_13c90c;
        case 0x13c918u: goto label_13c918;
        case 0x13c940u: goto label_13c940;
        case 0x13c950u: goto label_13c950;
        case 0x13c984u: goto label_13c984;
        case 0x13c990u: goto label_13c990;
        case 0x13c9d0u: goto label_13c9d0;
        default: break;
    }

    ctx->pc = 0x13c838u;

    // 0x13c838: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13c838u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13c83c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x13c83cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x13c840: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13c840u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13c844: 0x245435c0  addiu       $s4, $v0, 0x35C0
    ctx->pc = 0x13c844u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 13760));
    // 0x13c848: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13c848u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13c84c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13c84cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c850: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13c850u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13c854: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x13c854u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c858: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13c858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13c85c: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x13c85cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c860: 0x24061000  addiu       $a2, $zero, 0x1000
    ctx->pc = 0x13c860u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x13c864: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x13c864u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c868: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13c868u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c86c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13c86cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13c870: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x13c870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x13c874: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13C874u;
    SET_GPR_U32(ctx, 31, 0x13C87Cu);
    ctx->pc = 0x13C878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C874u;
            // 0x13c878: 0xe0902d  daddu       $s2, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C87Cu; }
        if (ctx->pc != 0x13C87Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C87Cu; }
        if (ctx->pc != 0x13C87Cu) { return; }
    }
    ctx->pc = 0x13C87Cu;
label_13c87c:
    // 0x13c87c: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13c87cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13c880: 0x8c62de90  lw          $v0, -0x2170($v1)
    ctx->pc = 0x13c880u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294958736)));
    // 0x13c884: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13C884u;
    {
        const bool branch_taken_0x13c884 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13c884) {
            ctx->pc = 0x13C894u;
            goto label_13c894;
        }
    }
    ctx->pc = 0x13C88Cu;
    // 0x13c88c: 0xc04f1f0  jal         func_13C7C0
    ctx->pc = 0x13C88Cu;
    SET_GPR_U32(ctx, 31, 0x13C894u);
    ctx->pc = 0x13C7C0u;
    if (runtime->hasFunction(0x13C7C0u)) {
        auto targetFn = runtime->lookupFunction(0x13C7C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C894u; }
        if (ctx->pc != 0x13C894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C7C0_0x13c7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C894u; }
        if (ctx->pc != 0x13C894u) { return; }
    }
    ctx->pc = 0x13C894u;
label_13c894:
    // 0x13c894: 0xc04f164  jal         func_13C590
    ctx->pc = 0x13C894u;
    SET_GPR_U32(ctx, 31, 0x13C89Cu);
    ctx->pc = 0x13C590u;
    if (runtime->hasFunction(0x13C590u)) {
        auto targetFn = runtime->lookupFunction(0x13C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C89Cu; }
        if (ctx->pc != 0x13C89Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C590_0x13c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C89Cu; }
        if (ctx->pc != 0x13C89Cu) { return; }
    }
    ctx->pc = 0x13C89Cu;
label_13c89c:
    // 0x13c89c: 0x12000040  beqz        $s0, . + 4 + (0x40 << 2)
    ctx->pc = 0x13C89Cu;
    {
        const bool branch_taken_0x13c89c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C8A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C89Cu;
            // 0x13c8a0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c89c) {
            ctx->pc = 0x13C9A0u;
            goto label_13c9a0;
        }
    }
    ctx->pc = 0x13C8A4u;
    // 0x13c8a4: 0x1660000a  bnez        $s3, . + 4 + (0xA << 2)
    ctx->pc = 0x13C8A4u;
    {
        const bool branch_taken_0x13c8a4 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x13C8A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C8A4u;
            // 0x13c8a8: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c8a4) {
            ctx->pc = 0x13C8D0u;
            goto label_13c8d0;
        }
    }
    ctx->pc = 0x13C8ACu;
    // 0x13c8ac: 0x8c43dea4  lw          $v1, -0x215C($v0)
    ctx->pc = 0x13c8acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958756)));
    // 0x13c8b0: 0x5460003b  bnel        $v1, $zero, . + 4 + (0x3B << 2)
    ctx->pc = 0x13C8B0u;
    {
        const bool branch_taken_0x13c8b0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x13c8b0) {
            ctx->pc = 0x13C8B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13C8B0u;
            // 0x13c8b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13C9A0u;
            goto label_13c9a0;
        }
    }
    ctx->pc = 0x13C8B8u;
    // 0x13c8b8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13c8b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13c8bc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13c8bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c8c0: 0xc045a12  jal         func_116848
    ctx->pc = 0x13C8C0u;
    SET_GPR_U32(ctx, 31, 0x13C8C8u);
    ctx->pc = 0x13C8C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C8C0u;
            // 0x13c8c4: 0x2484d248  addiu       $a0, $a0, -0x2DB8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955592));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C8C8u; }
        if (ctx->pc != 0x13C8C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C8C8u; }
        if (ctx->pc != 0x13C8C8u) { return; }
    }
    ctx->pc = 0x13C8C8u;
label_13c8c8:
    // 0x13c8c8: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x13C8C8u;
    {
        const bool branch_taken_0x13c8c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C8CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C8C8u;
            // 0x13c8cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c8c8) {
            ctx->pc = 0x13C9A0u;
            goto label_13c9a0;
        }
    }
    ctx->pc = 0x13C8D0u;
label_13c8d0:
    // 0x13c8d0: 0x1620000b  bnez        $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x13C8D0u;
    {
        const bool branch_taken_0x13c8d0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x13C8D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C8D0u;
            // 0x13c8d4: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c8d0) {
            ctx->pc = 0x13C900u;
            goto label_13c900;
        }
    }
    ctx->pc = 0x13C8D8u;
    // 0x13c8d8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13c8d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13c8dc: 0x8c43dea4  lw          $v1, -0x215C($v0)
    ctx->pc = 0x13c8dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958756)));
    // 0x13c8e0: 0x5460002f  bnel        $v1, $zero, . + 4 + (0x2F << 2)
    ctx->pc = 0x13C8E0u;
    {
        const bool branch_taken_0x13c8e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x13c8e0) {
            ctx->pc = 0x13C8E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13C8E0u;
            // 0x13c8e4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13C9A0u;
            goto label_13c9a0;
        }
    }
    ctx->pc = 0x13C8E8u;
    // 0x13c8e8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13c8e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13c8ec: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13c8ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c8f0: 0xc045a12  jal         func_116848
    ctx->pc = 0x13C8F0u;
    SET_GPR_U32(ctx, 31, 0x13C8F8u);
    ctx->pc = 0x13C8F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C8F0u;
            // 0x13c8f4: 0x2484d278  addiu       $a0, $a0, -0x2D88 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955640));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C8F8u; }
        if (ctx->pc != 0x13C8F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C8F8u; }
        if (ctx->pc != 0x13C8F8u) { return; }
    }
    ctx->pc = 0x13C8F8u;
label_13c8f8:
    // 0x13c8f8: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x13C8F8u;
    {
        const bool branch_taken_0x13c8f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C8FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C8F8u;
            // 0x13c8fc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c8f8) {
            ctx->pc = 0x13C9A0u;
            goto label_13c9a0;
        }
    }
    ctx->pc = 0x13C900u;
label_13c900:
    // 0x13c900: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13c900u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c904: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13C904u;
    SET_GPR_U32(ctx, 31, 0x13C90Cu);
    ctx->pc = 0x13C908u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C904u;
            // 0x13c908: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C90Cu; }
        if (ctx->pc != 0x13C90Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C90Cu; }
        if (ctx->pc != 0x13C90Cu) { return; }
    }
    ctx->pc = 0x13C90Cu;
label_13c90c:
    // 0x13c90c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13c90cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c910: 0xc04f090  jal         func_13C240
    ctx->pc = 0x13C910u;
    SET_GPR_U32(ctx, 31, 0x13C918u);
    ctx->pc = 0x13C914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C910u;
            // 0x13c914: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C240u;
    if (runtime->hasFunction(0x13C240u)) {
        auto targetFn = runtime->lookupFunction(0x13C240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C918u; }
        if (ctx->pc != 0x13C918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C240_0x13c240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C918u; }
        if (ctx->pc != 0x13C918u) { return; }
    }
    ctx->pc = 0x13C918u;
label_13c918:
    // 0x13c918: 0x5440000f  bnel        $v0, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x13C918u;
    {
        const bool branch_taken_0x13c918 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13c918) {
            ctx->pc = 0x13C91Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13C918u;
            // 0x13c91c: 0x26500009  addiu       $s0, $s2, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 9));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13C958u;
            goto label_13c958;
        }
    }
    ctx->pc = 0x13C920u;
    // 0x13c920: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13c920u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13c924: 0x8c43dea4  lw          $v1, -0x215C($v0)
    ctx->pc = 0x13c924u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958756)));
    // 0x13c928: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x13C928u;
    {
        const bool branch_taken_0x13c928 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13C92Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C928u;
            // 0x13c92c: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c928) {
            ctx->pc = 0x13C944u;
            goto label_13c944;
        }
    }
    ctx->pc = 0x13C930u;
    // 0x13c930: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13c930u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13c934: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x13c934u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c938: 0xc045a12  jal         func_116848
    ctx->pc = 0x13C938u;
    SET_GPR_U32(ctx, 31, 0x13C940u);
    ctx->pc = 0x13C93Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C938u;
            // 0x13c93c: 0x2484d2a8  addiu       $a0, $a0, -0x2D58 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955688));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C940u; }
        if (ctx->pc != 0x13C940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C940u; }
        if (ctx->pc != 0x13C940u) { return; }
    }
    ctx->pc = 0x13C940u;
label_13c940:
    // 0x13c940: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13c940u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
label_13c944:
    // 0x13c944: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x13c944u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c948: 0xc04ebf2  jal         func_13AFC8
    ctx->pc = 0x13C948u;
    SET_GPR_U32(ctx, 31, 0x13C950u);
    ctx->pc = 0x13C94Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C948u;
            // 0x13c94c: 0x24a5d2d0  addiu       $a1, $a1, -0x2D30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955728));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AFC8u;
    if (runtime->hasFunction(0x13AFC8u)) {
        auto targetFn = runtime->lookupFunction(0x13AFC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C950u; }
        if (ctx->pc != 0x13C950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AFC8_0x13afc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C950u; }
        if (ctx->pc != 0x13C950u) { return; }
    }
    ctx->pc = 0x13C950u;
label_13c950:
    // 0x13c950: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x13C950u;
    {
        const bool branch_taken_0x13c950 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C950u;
            // 0x13c954: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c950) {
            ctx->pc = 0x13C9A0u;
            goto label_13c9a0;
        }
    }
    ctx->pc = 0x13C958u;
label_13c958:
    // 0x13c958: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x13c958u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c95c: 0x230001b  divu        $zero, $s1, $s0
    ctx->pc = 0x13c95cu;
    { uint32_t divisor = GPR_U32(ctx, 16); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 17) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 17) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,17); } }
    // 0x13c960: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x13c960u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c964: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x13c964u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c968: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13C968u;
    {
        const bool branch_taken_0x13c968 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x13c968) {
            ctx->pc = 0x13C96Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13C968u;
            // 0x13c96c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13C970u;
            goto label_13c970;
        }
    }
    ctx->pc = 0x13C970u;
label_13c970:
    // 0x13c970: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x13c970u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x13c974: 0x8812  mflo        $s1
    ctx->pc = 0x13c974u;
    SET_GPR_U64(ctx, 17, ctx->lo);
    // 0x13c978: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x13c978u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c97c: 0xc04f028  jal         func_13C0A0
    ctx->pc = 0x13C97Cu;
    SET_GPR_U32(ctx, 31, 0x13C984u);
    ctx->pc = 0x13C980u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C97Cu;
            // 0x13c980: 0x1188c0  sll         $s1, $s1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C0A0u;
    if (runtime->hasFunction(0x13C0A0u)) {
        auto targetFn = runtime->lookupFunction(0x13C0A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C984u; }
        if (ctx->pc != 0x13C984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C0A0_0x13c0a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C984u; }
        if (ctx->pc != 0x13C984u) { return; }
    }
    ctx->pc = 0x13C984u;
label_13c984:
    // 0x13c984: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x13c984u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c988: 0xc04f0e8  jal         func_13C3A0
    ctx->pc = 0x13C988u;
    SET_GPR_U32(ctx, 31, 0x13C990u);
    ctx->pc = 0x13C98Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C988u;
            // 0x13c98c: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C3A0u;
    if (runtime->hasFunction(0x13C3A0u)) {
        auto targetFn = runtime->lookupFunction(0x13C3A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C990u; }
        if (ctx->pc != 0x13C990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C3A0_0x13c3a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C990u; }
        if (ctx->pc != 0x13C990u) { return; }
    }
    ctx->pc = 0x13C990u;
label_13c990:
    // 0x13c990: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13C990u;
    {
        const bool branch_taken_0x13c990 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x13c990) {
            ctx->pc = 0x13C994u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13C990u;
            // 0x13c994: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13C998u;
            goto label_13c998;
        }
    }
    ctx->pc = 0x13C998u;
label_13c998:
    // 0x13c998: 0x521018  mult        $v0, $v0, $s2
    ctx->pc = 0x13c998u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 18); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x13c99c: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x13c99cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
label_13c9a0:
    // 0x13c9a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13c9a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13c9a4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13c9a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13c9a8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13c9a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13c9ac: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13c9acu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13c9b0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13c9b0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13c9b4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x13c9b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13c9b8: 0x3e00008  jr          $ra
    ctx->pc = 0x13C9B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13C9BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C9B8u;
            // 0x13c9bc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13C87Cu: goto label_13c87c;
            case 0x13C894u: goto label_13c894;
            case 0x13C89Cu: goto label_13c89c;
            case 0x13C8C8u: goto label_13c8c8;
            case 0x13C8D0u: goto label_13c8d0;
            case 0x13C8F8u: goto label_13c8f8;
            case 0x13C900u: goto label_13c900;
            case 0x13C90Cu: goto label_13c90c;
            case 0x13C918u: goto label_13c918;
            case 0x13C940u: goto label_13c940;
            case 0x13C944u: goto label_13c944;
            case 0x13C950u: goto label_13c950;
            case 0x13C958u: goto label_13c958;
            case 0x13C970u: goto label_13c970;
            case 0x13C984u: goto label_13c984;
            case 0x13C990u: goto label_13c990;
            case 0x13C998u: goto label_13c998;
            case 0x13C9A0u: goto label_13c9a0;
            case 0x13C9D0u: goto label_13c9d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13C9C0u;
    // 0x13c9c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13c9c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13c9c4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13c9c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13c9c8: 0xc04f1fa  jal         func_13C7E8
    ctx->pc = 0x13C9C8u;
    SET_GPR_U32(ctx, 31, 0x13C9D0u);
    ctx->pc = 0x13C9CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C9C8u;
            // 0x13c9cc: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C7E8u;
    if (runtime->hasFunction(0x13C7E8u)) {
        auto targetFn = runtime->lookupFunction(0x13C7E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C9D0u; }
        if (ctx->pc != 0x13C9D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C7E8_0x13c7e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C9D0u; }
        if (ctx->pc != 0x13C9D0u) { return; }
    }
    ctx->pc = 0x13C9D0u;
label_13c9d0:
    // 0x13c9d0: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x13c9d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13c9d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13c9d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13c9d8: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x13c9d8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x13c9dc: 0x3e00008  jr          $ra
    ctx->pc = 0x13C9DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13C9E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C9DCu;
            // 0x13c9e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13C87Cu: goto label_13c87c;
            case 0x13C894u: goto label_13c894;
            case 0x13C89Cu: goto label_13c89c;
            case 0x13C8C8u: goto label_13c8c8;
            case 0x13C8D0u: goto label_13c8d0;
            case 0x13C8F8u: goto label_13c8f8;
            case 0x13C900u: goto label_13c900;
            case 0x13C90Cu: goto label_13c90c;
            case 0x13C918u: goto label_13c918;
            case 0x13C940u: goto label_13c940;
            case 0x13C944u: goto label_13c944;
            case 0x13C950u: goto label_13c950;
            case 0x13C958u: goto label_13c958;
            case 0x13C970u: goto label_13c970;
            case 0x13C984u: goto label_13c984;
            case 0x13C990u: goto label_13c990;
            case 0x13C998u: goto label_13c998;
            case 0x13C9A0u: goto label_13c9a0;
            case 0x13C9D0u: goto label_13c9d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13C9E4u;
    // 0x13c9e4: 0x0  nop
    ctx->pc = 0x13c9e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
