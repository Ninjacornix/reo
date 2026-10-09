#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013AC60
// Address: 0x13ac60 - 0x13adf0
void sub_0013AC60_0x13ac60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013AC60_0x13ac60");
#endif

    switch (ctx->pc) {
        case 0x13aca8u: goto label_13aca8;
        case 0x13acc0u: goto label_13acc0;
        case 0x13ace8u: goto label_13ace8;
        case 0x13ad4cu: goto label_13ad4c;
        case 0x13ad84u: goto label_13ad84;
        case 0x13ad90u: goto label_13ad90;
        case 0x13add8u: goto label_13add8;
        default: break;
    }

    ctx->pc = 0x13ac60u;

    // 0x13ac60: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x13ac60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13ac64: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x13ac64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x13ac68: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13ac68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13ac6c: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x13ac6cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ac70: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13ac70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13ac74: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x13ac74u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ac78: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13ac78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13ac7c: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x13ac7cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ac80: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ac80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ac84: 0x24061000  addiu       $a2, $zero, 0x1000
    ctx->pc = 0x13ac84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x13ac88: 0x244425c0  addiu       $a0, $v0, 0x25C0
    ctx->pc = 0x13ac88u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 9664));
    // 0x13ac8c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13ac8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13ac90: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x13ac90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x13ac94: 0x100a82d  daddu       $s5, $t0, $zero
    ctx->pc = 0x13ac94u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ac98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13ac98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13ac9c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x13ac9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x13aca0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13ACA0u;
    SET_GPR_U32(ctx, 31, 0x13ACA8u);
    ctx->pc = 0x13ACA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13ACA0u;
            // 0x13aca4: 0xe0882d  daddu       $s1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ACA8u; }
        if (ctx->pc != 0x13ACA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ACA8u; }
        if (ctx->pc != 0x13ACA8u) { return; }
    }
    ctx->pc = 0x13ACA8u;
label_13aca8:
    // 0x13aca8: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13aca8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13acac: 0x8c62d8d0  lw          $v0, -0x2730($v1)
    ctx->pc = 0x13acacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294957264)));
    // 0x13acb0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13ACB0u;
    {
        const bool branch_taken_0x13acb0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13acb0) {
            ctx->pc = 0x13ACC0u;
            goto label_13acc0;
        }
    }
    ctx->pc = 0x13ACB8u;
    // 0x13acb8: 0xc04ea76  jal         func_13A9D8
    ctx->pc = 0x13ACB8u;
    SET_GPR_U32(ctx, 31, 0x13ACC0u);
    ctx->pc = 0x13A9D8u;
    if (runtime->hasFunction(0x13A9D8u)) {
        auto targetFn = runtime->lookupFunction(0x13A9D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ACC0u; }
        if (ctx->pc != 0x13ACC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A9D8_0x13a9d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ACC0u; }
        if (ctx->pc != 0x13ACC0u) { return; }
    }
    ctx->pc = 0x13ACC0u;
label_13acc0:
    // 0x13acc0: 0x12800007  beqz        $s4, . + 4 + (0x7 << 2)
    ctx->pc = 0x13ACC0u;
    {
        const bool branch_taken_0x13acc0 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        if (branch_taken_0x13acc0) {
            ctx->pc = 0x13ACE0u;
            goto label_13ace0;
        }
    }
    ctx->pc = 0x13ACC8u;
    // 0x13acc8: 0x12400005  beqz        $s2, . + 4 + (0x5 << 2)
    ctx->pc = 0x13ACC8u;
    {
        const bool branch_taken_0x13acc8 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x13acc8) {
            ctx->pc = 0x13ACE0u;
            goto label_13ace0;
        }
    }
    ctx->pc = 0x13ACD0u;
    // 0x13acd0: 0x12600003  beqz        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x13ACD0u;
    {
        const bool branch_taken_0x13acd0 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        if (branch_taken_0x13acd0) {
            ctx->pc = 0x13ACE0u;
            goto label_13ace0;
        }
    }
    ctx->pc = 0x13ACD8u;
    // 0x13acd8: 0x16200003  bnez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x13ACD8u;
    {
        const bool branch_taken_0x13acd8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x13acd8) {
            ctx->pc = 0x13ACE8u;
            goto label_13ace8;
        }
    }
    ctx->pc = 0x13ACE0u;
label_13ace0:
    // 0x13ace0: 0xc04ea76  jal         func_13A9D8
    ctx->pc = 0x13ACE0u;
    SET_GPR_U32(ctx, 31, 0x13ACE8u);
    ctx->pc = 0x13A9D8u;
    if (runtime->hasFunction(0x13A9D8u)) {
        auto targetFn = runtime->lookupFunction(0x13A9D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ACE8u; }
        if (ctx->pc != 0x13ACE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A9D8_0x13a9d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ACE8u; }
        if (ctx->pc != 0x13ACE8u) { return; }
    }
    ctx->pc = 0x13ACE8u;
label_13ace8:
    // 0x13ace8: 0x1280002e  beqz        $s4, . + 4 + (0x2E << 2)
    ctx->pc = 0x13ACE8u;
    {
        const bool branch_taken_0x13ace8 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x13ACECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ACE8u;
            // 0x13acec: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ace8) {
            ctx->pc = 0x13ADA4u;
            goto label_13ada4;
        }
    }
    ctx->pc = 0x13ACF0u;
    // 0x13acf0: 0x16400009  bnez        $s2, . + 4 + (0x9 << 2)
    ctx->pc = 0x13ACF0u;
    {
        const bool branch_taken_0x13acf0 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x13ACF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ACF0u;
            // 0x13acf4: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13acf0) {
            ctx->pc = 0x13AD18u;
            goto label_13ad18;
        }
    }
    ctx->pc = 0x13ACF8u;
    // 0x13acf8: 0x8c43d8e8  lw          $v1, -0x2718($v0)
    ctx->pc = 0x13acf8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957288)));
    // 0x13acfc: 0x14600029  bnez        $v1, . + 4 + (0x29 << 2)
    ctx->pc = 0x13ACFCu;
    {
        const bool branch_taken_0x13acfc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13AD00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ACFCu;
            // 0x13ad00: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13acfc) {
            ctx->pc = 0x13ADA4u;
            goto label_13ada4;
        }
    }
    ctx->pc = 0x13AD04u;
    // 0x13ad04: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13ad04u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13ad08: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ad08u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ad0c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x13AD0Cu;
    {
        const bool branch_taken_0x13ad0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13AD10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AD0Cu;
            // 0x13ad10: 0x2484cd30  addiu       $a0, $a0, -0x32D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954288));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ad0c) {
            ctx->pc = 0x13AD44u;
            goto label_13ad44;
        }
    }
    ctx->pc = 0x13AD14u;
    // 0x13ad14: 0x0  nop
    ctx->pc = 0x13ad14u;
    // NOP
label_13ad18:
    // 0x13ad18: 0x12600005  beqz        $s3, . + 4 + (0x5 << 2)
    ctx->pc = 0x13AD18u;
    {
        const bool branch_taken_0x13ad18 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x13AD1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AD18u;
            // 0x13ad1c: 0x8c43d8e8  lw          $v1, -0x2718($v0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957288)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ad18) {
            ctx->pc = 0x13AD30u;
            goto label_13ad30;
        }
    }
    ctx->pc = 0x13AD20u;
    // 0x13ad20: 0x1620000d  bnez        $s1, . + 4 + (0xD << 2)
    ctx->pc = 0x13AD20u;
    {
        const bool branch_taken_0x13ad20 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x13AD24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AD20u;
            // 0x13ad24: 0x26b00009  addiu       $s0, $s5, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ad20) {
            ctx->pc = 0x13AD58u;
            goto label_13ad58;
        }
    }
    ctx->pc = 0x13AD28u;
    // 0x13ad28: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13ad28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13ad2c: 0x8c43d8e8  lw          $v1, -0x2718($v0)
    ctx->pc = 0x13ad2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957288)));
label_13ad30:
    // 0x13ad30: 0x1460001c  bnez        $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x13AD30u;
    {
        const bool branch_taken_0x13ad30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13AD34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AD30u;
            // 0x13ad34: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ad30) {
            ctx->pc = 0x13ADA4u;
            goto label_13ada4;
        }
    }
    ctx->pc = 0x13AD38u;
    // 0x13ad38: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13ad38u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13ad3c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ad3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ad40: 0x2484cd60  addiu       $a0, $a0, -0x32A0
    ctx->pc = 0x13ad40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954336));
label_13ad44:
    // 0x13ad44: 0xc045a12  jal         func_116848
    ctx->pc = 0x13AD44u;
    SET_GPR_U32(ctx, 31, 0x13AD4Cu);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AD4Cu; }
        if (ctx->pc != 0x13AD4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AD4Cu; }
        if (ctx->pc != 0x13AD4Cu) { return; }
    }
    ctx->pc = 0x13AD4Cu;
label_13ad4c:
    // 0x13ad4c: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x13AD4Cu;
    {
        const bool branch_taken_0x13ad4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13AD50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AD4Cu;
            // 0x13ad50: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ad4c) {
            ctx->pc = 0x13ADA4u;
            goto label_13ada4;
        }
    }
    ctx->pc = 0x13AD54u;
    // 0x13ad54: 0x0  nop
    ctx->pc = 0x13ad54u;
    // NOP
label_13ad58:
    // 0x13ad58: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x13ad58u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ad5c: 0x230001b  divu        $zero, $s1, $s0
    ctx->pc = 0x13ad5cu;
    { uint32_t divisor = GPR_U32(ctx, 16); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 17) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 17) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,17); } }
    // 0x13ad60: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x13ad60u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ad64: 0x2a0402d  daddu       $t0, $s5, $zero
    ctx->pc = 0x13ad64u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ad68: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13ad68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ad6c: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13AD6Cu;
    {
        const bool branch_taken_0x13ad6c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x13ad6c) {
            ctx->pc = 0x13AD70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13AD6Cu;
            // 0x13ad70: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13AD74u;
            goto label_13ad74;
        }
    }
    ctx->pc = 0x13AD74u;
label_13ad74:
    // 0x13ad74: 0x8812  mflo        $s1
    ctx->pc = 0x13ad74u;
    SET_GPR_U64(ctx, 17, ctx->lo);
    // 0x13ad78: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x13ad78u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ad7c: 0xc04e906  jal         func_13A418
    ctx->pc = 0x13AD7Cu;
    SET_GPR_U32(ctx, 31, 0x13AD84u);
    ctx->pc = 0x13AD80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AD7Cu;
            // 0x13ad80: 0x1188c0  sll         $s1, $s1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A418u;
    if (runtime->hasFunction(0x13A418u)) {
        auto targetFn = runtime->lookupFunction(0x13A418u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AD84u; }
        if (ctx->pc != 0x13AD84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A418_0x13a418(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AD84u; }
        if (ctx->pc != 0x13AD84u) { return; }
    }
    ctx->pc = 0x13AD84u;
label_13ad84:
    // 0x13ad84: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13ad84u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ad88: 0xc04e9ce  jal         func_13A738
    ctx->pc = 0x13AD88u;
    SET_GPR_U32(ctx, 31, 0x13AD90u);
    ctx->pc = 0x13AD8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AD88u;
            // 0x13ad8c: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A738u;
    if (runtime->hasFunction(0x13A738u)) {
        auto targetFn = runtime->lookupFunction(0x13A738u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AD90u; }
        if (ctx->pc != 0x13AD90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A738_0x13a738(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AD90u; }
        if (ctx->pc != 0x13AD90u) { return; }
    }
    ctx->pc = 0x13AD90u;
label_13ad90:
    // 0x13ad90: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13AD90u;
    {
        const bool branch_taken_0x13ad90 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x13ad90) {
            ctx->pc = 0x13AD94u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13AD90u;
            // 0x13ad94: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13AD98u;
            goto label_13ad98;
        }
    }
    ctx->pc = 0x13AD98u;
label_13ad98:
    // 0x13ad98: 0x26a30001  addiu       $v1, $s5, 0x1
    ctx->pc = 0x13ad98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x13ad9c: 0x431018  mult        $v0, $v0, $v1
    ctx->pc = 0x13ad9cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x13ada0: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x13ada0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
label_13ada4:
    // 0x13ada4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13ada4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ada8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13ada8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13adac: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13adacu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13adb0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13adb0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13adb4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13adb4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13adb8: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x13adb8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13adbc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x13adbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13adc0: 0x3e00008  jr          $ra
    ctx->pc = 0x13ADC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13ADC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ADC0u;
            // 0x13adc4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ACA8u: goto label_13aca8;
            case 0x13ACC0u: goto label_13acc0;
            case 0x13ACE0u: goto label_13ace0;
            case 0x13ACE8u: goto label_13ace8;
            case 0x13AD18u: goto label_13ad18;
            case 0x13AD30u: goto label_13ad30;
            case 0x13AD44u: goto label_13ad44;
            case 0x13AD4Cu: goto label_13ad4c;
            case 0x13AD58u: goto label_13ad58;
            case 0x13AD74u: goto label_13ad74;
            case 0x13AD84u: goto label_13ad84;
            case 0x13AD90u: goto label_13ad90;
            case 0x13AD98u: goto label_13ad98;
            case 0x13ADA4u: goto label_13ada4;
            case 0x13ADD8u: goto label_13add8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13ADC8u;
    // 0x13adc8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x13adc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13adcc: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x13adccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x13add0: 0xc04ea80  jal         func_13AA00
    ctx->pc = 0x13ADD0u;
    SET_GPR_U32(ctx, 31, 0x13ADD8u);
    ctx->pc = 0x13ADD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13ADD0u;
            // 0x13add4: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AA00u;
    if (runtime->hasFunction(0x13AA00u)) {
        auto targetFn = runtime->lookupFunction(0x13AA00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ADD8u; }
        if (ctx->pc != 0x13ADD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AA00_0x13aa00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ADD8u; }
        if (ctx->pc != 0x13ADD8u) { return; }
    }
    ctx->pc = 0x13ADD8u;
label_13add8:
    // 0x13add8: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x13add8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13addc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x13addcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13ade0: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x13ade0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x13ade4: 0x3e00008  jr          $ra
    ctx->pc = 0x13ADE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13ADE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ADE4u;
            // 0x13ade8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ACA8u: goto label_13aca8;
            case 0x13ACC0u: goto label_13acc0;
            case 0x13ACE0u: goto label_13ace0;
            case 0x13ACE8u: goto label_13ace8;
            case 0x13AD18u: goto label_13ad18;
            case 0x13AD30u: goto label_13ad30;
            case 0x13AD44u: goto label_13ad44;
            case 0x13AD4Cu: goto label_13ad4c;
            case 0x13AD58u: goto label_13ad58;
            case 0x13AD74u: goto label_13ad74;
            case 0x13AD84u: goto label_13ad84;
            case 0x13AD90u: goto label_13ad90;
            case 0x13AD98u: goto label_13ad98;
            case 0x13ADA4u: goto label_13ada4;
            case 0x13ADD8u: goto label_13add8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13ADECu;
    // 0x13adec: 0x0  nop
    ctx->pc = 0x13adecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
