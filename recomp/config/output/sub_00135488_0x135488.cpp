#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135488
// Address: 0x135488 - 0x135560
void sub_00135488_0x135488(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135488_0x135488");
#endif

    switch (ctx->pc) {
        case 0x1354a8u: goto label_1354a8;
        case 0x1354b0u: goto label_1354b0;
        case 0x1354c0u: goto label_1354c0;
        case 0x1354e0u: goto label_1354e0;
        case 0x135530u: goto label_135530;
        case 0x135540u: goto label_135540;
        default: break;
    }

    ctx->pc = 0x135488u;

    // 0x135488: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x135488u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13548c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13548cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135490: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x135490u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135494: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x135494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x135498: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x135498u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13549c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13549cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1354a0: 0xc04d57e  jal         func_1355F8
    ctx->pc = 0x1354A0u;
    SET_GPR_U32(ctx, 31, 0x1354A8u);
    ctx->pc = 0x1354A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1354A0u;
            // 0x1354a4: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1355F8u;
    if (runtime->hasFunction(0x1355F8u)) {
        auto targetFn = runtime->lookupFunction(0x1355F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1354A8u; }
        if (ctx->pc != 0x1354A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001355F8_0x1355f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1354A8u; }
        if (ctx->pc != 0x1354A8u) { return; }
    }
    ctx->pc = 0x1354A8u;
label_1354a8:
    // 0x1354a8: 0x200f809  jalr        $s0
    ctx->pc = 0x1354A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 16);
        SET_GPR_U32(ctx, 31, 0x1354B0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1354B0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1354A8u: goto label_1354a8;
            case 0x1354B0u: goto label_1354b0;
            case 0x1354C0u: goto label_1354c0;
            case 0x1354E0u: goto label_1354e0;
            case 0x135504u: goto label_135504;
            case 0x135530u: goto label_135530;
            case 0x135540u: goto label_135540;
            case 0x135544u: goto label_135544;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1354B0u; }
            if (ctx->pc != 0x1354B0u) { return; }
        }
        }
    }
    ctx->pc = 0x1354B0u;
label_1354b0:
    // 0x1354b0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1354b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1354b4: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1354b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1354b8: 0xc04d558  jal         func_135560
    ctx->pc = 0x1354B8u;
    SET_GPR_U32(ctx, 31, 0x1354C0u);
    ctx->pc = 0x1354BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1354B8u;
            // 0x1354bc: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1354C0u; }
        if (ctx->pc != 0x1354C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1354C0u; }
        if (ctx->pc != 0x1354C0u) { return; }
    }
    ctx->pc = 0x1354C0u;
label_1354c0:
    // 0x1354c0: 0x14400020  bnez        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1354C0u;
    {
        const bool branch_taken_0x1354c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1354C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1354C0u;
            // 0x1354c4: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1354c0) {
            ctx->pc = 0x135544u;
            goto label_135544;
        }
    }
    ctx->pc = 0x1354C8u;
    // 0x1354c8: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1354c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1354cc: 0x24832068  addiu       $v1, $a0, 0x2068
    ctx->pc = 0x1354ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 8296));
    // 0x1354d0: 0x80620004  lb          $v0, 0x4($v1)
    ctx->pc = 0x1354d0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1354d4: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1354D4u;
    {
        const bool branch_taken_0x1354d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1354D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1354D4u;
            // 0x1354d8: 0x24630004  addiu       $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1354d4) {
            ctx->pc = 0x135504u;
            goto label_135504;
        }
    }
    ctx->pc = 0x1354DCu;
    // 0x1354dc: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1354dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1354e0:
    // 0x1354e0: 0x2a020020  slti        $v0, $s0, 0x20
    ctx->pc = 0x1354e0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1354e4: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1354E4u;
    {
        const bool branch_taken_0x1354e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1354E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1354E4u;
            // 0x1354e8: 0x24630010  addiu       $v1, $v1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1354e4) {
            ctx->pc = 0x135504u;
            goto label_135504;
        }
    }
    ctx->pc = 0x1354ECu;
    // 0x1354ec: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x1354ecu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1354f0: 0x0  nop
    ctx->pc = 0x1354f0u;
    // NOP
    // 0x1354f4: 0x0  nop
    ctx->pc = 0x1354f4u;
    // NOP
    // 0x1354f8: 0x0  nop
    ctx->pc = 0x1354f8u;
    // NOP
    // 0x1354fc: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1354FCu;
    {
        const bool branch_taken_0x1354fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1354fc) {
            ctx->pc = 0x135500u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1354FCu;
            // 0x135500: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1354E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1354e0;
        }
    }
    ctx->pc = 0x135504u;
label_135504:
    // 0x135504: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x135504u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x135508: 0x1203000e  beq         $s0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x135508u;
    {
        const bool branch_taken_0x135508 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        ctx->pc = 0x13550Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135508u;
            // 0x13550c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135508) {
            ctx->pc = 0x135544u;
            goto label_135544;
        }
    }
    ctx->pc = 0x135510u;
    // 0x135510: 0x24822068  addiu       $v0, $a0, 0x2068
    ctx->pc = 0x135510u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 8296));
    // 0x135514: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x135514u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135518: 0x108100  sll         $s0, $s0, 4
    ctx->pc = 0x135518u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x13551c: 0x24430004  addiu       $v1, $v0, 0x4
    ctx->pc = 0x13551cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x135520: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x135520u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x135524: 0x2038021  addu        $s0, $s0, $v1
    ctx->pc = 0x135524u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x135528: 0xc042c56  jal         func_10B158
    ctx->pc = 0x135528u;
    SET_GPR_U32(ctx, 31, 0x135530u);
    ctx->pc = 0x13552Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135528u;
            // 0x13552c: 0xac520000  sw          $s2, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135530u; }
        if (ctx->pc != 0x135530u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135530u; }
        if (ctx->pc != 0x135530u) { return; }
    }
    ctx->pc = 0x135530u;
label_135530:
    // 0x135530: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x135530u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135534: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x135534u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135538: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x135538u;
    SET_GPR_U32(ctx, 31, 0x135540u);
    ctx->pc = 0x13553Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135538u;
            // 0x13553c: 0x24460001  addiu       $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135540u; }
        if (ctx->pc != 0x135540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135540u; }
        if (ctx->pc != 0x135540u) { return; }
    }
    ctx->pc = 0x135540u;
label_135540:
    // 0x135540: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x135540u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_135544:
    // 0x135544: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135544u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135548: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x135548u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13554c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13554cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x135550: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x135550u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x135554: 0x3e00008  jr          $ra
    ctx->pc = 0x135554u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135554u;
            // 0x135558: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1354A8u: goto label_1354a8;
            case 0x1354B0u: goto label_1354b0;
            case 0x1354C0u: goto label_1354c0;
            case 0x1354E0u: goto label_1354e0;
            case 0x135504u: goto label_135504;
            case 0x135530u: goto label_135530;
            case 0x135540u: goto label_135540;
            case 0x135544u: goto label_135544;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13555Cu;
    // 0x13555c: 0x0  nop
    ctx->pc = 0x13555cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
