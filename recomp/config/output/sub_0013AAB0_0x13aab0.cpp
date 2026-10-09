#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013AAB0
// Address: 0x13aab0 - 0x13ac60
void sub_0013AAB0_0x13aab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013AAB0_0x13aab0");
#endif

    switch (ctx->pc) {
        case 0x13aaf0u: goto label_13aaf0;
        case 0x13ab08u: goto label_13ab08;
        case 0x13ab28u: goto label_13ab28;
        case 0x13ab54u: goto label_13ab54;
        case 0x13ab88u: goto label_13ab88;
        case 0x13aba0u: goto label_13aba0;
        case 0x13abacu: goto label_13abac;
        case 0x13abd4u: goto label_13abd4;
        case 0x13abe4u: goto label_13abe4;
        case 0x13ac1cu: goto label_13ac1c;
        case 0x13ac28u: goto label_13ac28;
        default: break;
    }

    ctx->pc = 0x13aab0u;

    // 0x13aab0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13aab0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13aab4: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13aab4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13aab8: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x13aab8u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x13aabc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13aabcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13aac0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13aac0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13aac4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13aac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13aac8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x13aac8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13aacc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13aaccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13aad0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x13aad0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13aad4: 0x24061000  addiu       $a2, $zero, 0x1000
    ctx->pc = 0x13aad4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x13aad8: 0x268425c0  addiu       $a0, $s4, 0x25C0
    ctx->pc = 0x13aad8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 9664));
    // 0x13aadc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13aadcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13aae0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13aae0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13aae4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x13aae4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x13aae8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13AAE8u;
    SET_GPR_U32(ctx, 31, 0x13AAF0u);
    ctx->pc = 0x13AAECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AAE8u;
            // 0x13aaec: 0xe0982d  daddu       $s3, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AAF0u; }
        if (ctx->pc != 0x13AAF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AAF0u; }
        if (ctx->pc != 0x13AAF0u) { return; }
    }
    ctx->pc = 0x13AAF0u;
label_13aaf0:
    // 0x13aaf0: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13aaf0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13aaf4: 0x8c62d8d0  lw          $v0, -0x2730($v1)
    ctx->pc = 0x13aaf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294957264)));
    // 0x13aaf8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13AAF8u;
    {
        const bool branch_taken_0x13aaf8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13aaf8) {
            ctx->pc = 0x13AB08u;
            goto label_13ab08;
        }
    }
    ctx->pc = 0x13AB00u;
    // 0x13ab00: 0xc04ea76  jal         func_13A9D8
    ctx->pc = 0x13AB00u;
    SET_GPR_U32(ctx, 31, 0x13AB08u);
    ctx->pc = 0x13A9D8u;
    if (runtime->hasFunction(0x13A9D8u)) {
        auto targetFn = runtime->lookupFunction(0x13A9D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AB08u; }
        if (ctx->pc != 0x13AB08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A9D8_0x13a9d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AB08u; }
        if (ctx->pc != 0x13AB08u) { return; }
    }
    ctx->pc = 0x13AB08u;
label_13ab08:
    // 0x13ab08: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13AB08u;
    {
        const bool branch_taken_0x13ab08 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x13ab08) {
            ctx->pc = 0x13AB20u;
            goto label_13ab20;
        }
    }
    ctx->pc = 0x13AB10u;
    // 0x13ab10: 0x12400003  beqz        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x13AB10u;
    {
        const bool branch_taken_0x13ab10 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x13ab10) {
            ctx->pc = 0x13AB20u;
            goto label_13ab20;
        }
    }
    ctx->pc = 0x13AB18u;
    // 0x13ab18: 0x16200003  bnez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x13AB18u;
    {
        const bool branch_taken_0x13ab18 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x13ab18) {
            ctx->pc = 0x13AB28u;
            goto label_13ab28;
        }
    }
    ctx->pc = 0x13AB20u;
label_13ab20:
    // 0x13ab20: 0xc04ea76  jal         func_13A9D8
    ctx->pc = 0x13AB20u;
    SET_GPR_U32(ctx, 31, 0x13AB28u);
    ctx->pc = 0x13A9D8u;
    if (runtime->hasFunction(0x13A9D8u)) {
        auto targetFn = runtime->lookupFunction(0x13A9D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AB28u; }
        if (ctx->pc != 0x13AB28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A9D8_0x13a9d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AB28u; }
        if (ctx->pc != 0x13AB28u) { return; }
    }
    ctx->pc = 0x13AB28u;
label_13ab28:
    // 0x13ab28: 0x12000044  beqz        $s0, . + 4 + (0x44 << 2)
    ctx->pc = 0x13AB28u;
    {
        const bool branch_taken_0x13ab28 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x13AB2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AB28u;
            // 0x13ab2c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ab28) {
            ctx->pc = 0x13AC3Cu;
            goto label_13ac3c;
        }
    }
    ctx->pc = 0x13AB30u;
    // 0x13ab30: 0x1640000b  bnez        $s2, . + 4 + (0xB << 2)
    ctx->pc = 0x13AB30u;
    {
        const bool branch_taken_0x13ab30 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x13AB34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AB30u;
            // 0x13ab34: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ab30) {
            ctx->pc = 0x13AB60u;
            goto label_13ab60;
        }
    }
    ctx->pc = 0x13AB38u;
    // 0x13ab38: 0x8c43d8e8  lw          $v1, -0x2718($v0)
    ctx->pc = 0x13ab38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957288)));
    // 0x13ab3c: 0x5460003f  bnel        $v1, $zero, . + 4 + (0x3F << 2)
    ctx->pc = 0x13AB3Cu;
    {
        const bool branch_taken_0x13ab3c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x13ab3c) {
            ctx->pc = 0x13AB40u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13AB3Cu;
            // 0x13ab40: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13AC3Cu;
            goto label_13ac3c;
        }
    }
    ctx->pc = 0x13AB44u;
    // 0x13ab44: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13ab44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13ab48: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ab48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ab4c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13AB4Cu;
    SET_GPR_U32(ctx, 31, 0x13AB54u);
    ctx->pc = 0x13AB50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AB4Cu;
            // 0x13ab50: 0x2484cd30  addiu       $a0, $a0, -0x32D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AB54u; }
        if (ctx->pc != 0x13AB54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AB54u; }
        if (ctx->pc != 0x13AB54u) { return; }
    }
    ctx->pc = 0x13AB54u;
label_13ab54:
    // 0x13ab54: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x13AB54u;
    {
        const bool branch_taken_0x13ab54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13AB58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AB54u;
            // 0x13ab58: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ab54) {
            ctx->pc = 0x13AC3Cu;
            goto label_13ac3c;
        }
    }
    ctx->pc = 0x13AB5Cu;
    // 0x13ab5c: 0x0  nop
    ctx->pc = 0x13ab5cu;
    // NOP
label_13ab60:
    // 0x13ab60: 0x1620000b  bnez        $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x13AB60u;
    {
        const bool branch_taken_0x13ab60 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x13AB64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AB60u;
            // 0x13ab64: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ab60) {
            ctx->pc = 0x13AB90u;
            goto label_13ab90;
        }
    }
    ctx->pc = 0x13AB68u;
    // 0x13ab68: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13ab68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13ab6c: 0x8c43d8e8  lw          $v1, -0x2718($v0)
    ctx->pc = 0x13ab6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957288)));
    // 0x13ab70: 0x54600032  bnel        $v1, $zero, . + 4 + (0x32 << 2)
    ctx->pc = 0x13AB70u;
    {
        const bool branch_taken_0x13ab70 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x13ab70) {
            ctx->pc = 0x13AB74u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13AB70u;
            // 0x13ab74: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13AC3Cu;
            goto label_13ac3c;
        }
    }
    ctx->pc = 0x13AB78u;
    // 0x13ab78: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13ab78u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13ab7c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ab7cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ab80: 0xc045a12  jal         func_116848
    ctx->pc = 0x13AB80u;
    SET_GPR_U32(ctx, 31, 0x13AB88u);
    ctx->pc = 0x13AB84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AB80u;
            // 0x13ab84: 0x2484cd60  addiu       $a0, $a0, -0x32A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954336));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AB88u; }
        if (ctx->pc != 0x13AB88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AB88u; }
        if (ctx->pc != 0x13AB88u) { return; }
    }
    ctx->pc = 0x13AB88u;
label_13ab88:
    // 0x13ab88: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x13AB88u;
    {
        const bool branch_taken_0x13ab88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13AB8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AB88u;
            // 0x13ab8c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ab88) {
            ctx->pc = 0x13AC3Cu;
            goto label_13ac3c;
        }
    }
    ctx->pc = 0x13AB90u;
label_13ab90:
    // 0x13ab90: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ab90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ab94: 0x269425c0  addiu       $s4, $s4, 0x25C0
    ctx->pc = 0x13ab94u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 9664));
    // 0x13ab98: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13AB98u;
    SET_GPR_U32(ctx, 31, 0x13ABA0u);
    ctx->pc = 0x13AB9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AB98u;
            // 0x13ab9c: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ABA0u; }
        if (ctx->pc != 0x13ABA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ABA0u; }
        if (ctx->pc != 0x13ABA0u) { return; }
    }
    ctx->pc = 0x13ABA0u;
label_13aba0:
    // 0x13aba0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13aba0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13aba4: 0xc04e96c  jal         func_13A5B0
    ctx->pc = 0x13ABA4u;
    SET_GPR_U32(ctx, 31, 0x13ABACu);
    ctx->pc = 0x13ABA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13ABA4u;
            // 0x13aba8: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A5B0u;
    if (runtime->hasFunction(0x13A5B0u)) {
        auto targetFn = runtime->lookupFunction(0x13A5B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ABACu; }
        if (ctx->pc != 0x13ABACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A5B0_0x13a5b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ABACu; }
        if (ctx->pc != 0x13ABACu) { return; }
    }
    ctx->pc = 0x13ABACu;
label_13abac:
    // 0x13abac: 0x54400010  bnel        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x13ABACu;
    {
        const bool branch_taken_0x13abac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13abac) {
            ctx->pc = 0x13ABB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13ABACu;
            // 0x13abb0: 0x26700009  addiu       $s0, $s3, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 9));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13ABF0u;
            goto label_13abf0;
        }
    }
    ctx->pc = 0x13ABB4u;
    // 0x13abb4: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13abb4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13abb8: 0x8c43d8e8  lw          $v1, -0x2718($v0)
    ctx->pc = 0x13abb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957288)));
    // 0x13abbc: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x13ABBCu;
    {
        const bool branch_taken_0x13abbc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13ABC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ABBCu;
            // 0x13abc0: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13abbc) {
            ctx->pc = 0x13ABD8u;
            goto label_13abd8;
        }
    }
    ctx->pc = 0x13ABC4u;
    // 0x13abc4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13abc4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13abc8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x13abc8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13abcc: 0xc045a12  jal         func_116848
    ctx->pc = 0x13ABCCu;
    SET_GPR_U32(ctx, 31, 0x13ABD4u);
    ctx->pc = 0x13ABD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13ABCCu;
            // 0x13abd0: 0x2484cd90  addiu       $a0, $a0, -0x3270 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ABD4u; }
        if (ctx->pc != 0x13ABD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ABD4u; }
        if (ctx->pc != 0x13ABD4u) { return; }
    }
    ctx->pc = 0x13ABD4u;
label_13abd4:
    // 0x13abd4: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13abd4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
label_13abd8:
    // 0x13abd8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x13abd8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13abdc: 0xc04e57e  jal         func_1395F8
    ctx->pc = 0x13ABDCu;
    SET_GPR_U32(ctx, 31, 0x13ABE4u);
    ctx->pc = 0x13ABE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13ABDCu;
            // 0x13abe0: 0x24a5cdb8  addiu       $a1, $a1, -0x3248 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954424));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1395F8u;
    if (runtime->hasFunction(0x1395F8u)) {
        auto targetFn = runtime->lookupFunction(0x1395F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ABE4u; }
        if (ctx->pc != 0x13ABE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001395F8_0x1395f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ABE4u; }
        if (ctx->pc != 0x13ABE4u) { return; }
    }
    ctx->pc = 0x13ABE4u;
label_13abe4:
    // 0x13abe4: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x13ABE4u;
    {
        const bool branch_taken_0x13abe4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13ABE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ABE4u;
            // 0x13abe8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13abe4) {
            ctx->pc = 0x13AC3Cu;
            goto label_13ac3c;
        }
    }
    ctx->pc = 0x13ABECu;
    // 0x13abec: 0x0  nop
    ctx->pc = 0x13abecu;
    // NOP
label_13abf0:
    // 0x13abf0: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x13abf0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13abf4: 0x230001b  divu        $zero, $s1, $s0
    ctx->pc = 0x13abf4u;
    { uint32_t divisor = GPR_U32(ctx, 16); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 17) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 17) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,17); } }
    // 0x13abf8: 0x24061000  addiu       $a2, $zero, 0x1000
    ctx->pc = 0x13abf8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x13abfc: 0x260402d  daddu       $t0, $s3, $zero
    ctx->pc = 0x13abfcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ac00: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13ac00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ac04: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13AC04u;
    {
        const bool branch_taken_0x13ac04 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x13ac04) {
            ctx->pc = 0x13AC08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13AC04u;
            // 0x13ac08: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13AC0Cu;
            goto label_13ac0c;
        }
    }
    ctx->pc = 0x13AC0Cu;
label_13ac0c:
    // 0x13ac0c: 0x8812  mflo        $s1
    ctx->pc = 0x13ac0cu;
    SET_GPR_U64(ctx, 17, ctx->lo);
    // 0x13ac10: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x13ac10u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ac14: 0xc04e906  jal         func_13A418
    ctx->pc = 0x13AC14u;
    SET_GPR_U32(ctx, 31, 0x13AC1Cu);
    ctx->pc = 0x13AC18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AC14u;
            // 0x13ac18: 0x1188c0  sll         $s1, $s1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A418u;
    if (runtime->hasFunction(0x13A418u)) {
        auto targetFn = runtime->lookupFunction(0x13A418u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AC1Cu; }
        if (ctx->pc != 0x13AC1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A418_0x13a418(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AC1Cu; }
        if (ctx->pc != 0x13AC1Cu) { return; }
    }
    ctx->pc = 0x13AC1Cu;
label_13ac1c:
    // 0x13ac1c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13ac1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ac20: 0xc04e9ce  jal         func_13A738
    ctx->pc = 0x13AC20u;
    SET_GPR_U32(ctx, 31, 0x13AC28u);
    ctx->pc = 0x13AC24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AC20u;
            // 0x13ac24: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A738u;
    if (runtime->hasFunction(0x13A738u)) {
        auto targetFn = runtime->lookupFunction(0x13A738u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AC28u; }
        if (ctx->pc != 0x13AC28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A738_0x13a738(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AC28u; }
        if (ctx->pc != 0x13AC28u) { return; }
    }
    ctx->pc = 0x13AC28u;
label_13ac28:
    // 0x13ac28: 0x52000001  beql        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13AC28u;
    {
        const bool branch_taken_0x13ac28 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x13ac28) {
            ctx->pc = 0x13AC2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13AC28u;
            // 0x13ac2c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13AC30u;
            goto label_13ac30;
        }
    }
    ctx->pc = 0x13AC30u;
label_13ac30:
    // 0x13ac30: 0x26630001  addiu       $v1, $s3, 0x1
    ctx->pc = 0x13ac30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x13ac34: 0x431018  mult        $v0, $v0, $v1
    ctx->pc = 0x13ac34u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x13ac38: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x13ac38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
label_13ac3c:
    // 0x13ac3c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13ac3cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ac40: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13ac40u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13ac44: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13ac44u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13ac48: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13ac48u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13ac4c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13ac4cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13ac50: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x13ac50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13ac54: 0x3e00008  jr          $ra
    ctx->pc = 0x13AC54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13AC58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AC54u;
            // 0x13ac58: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13AAF0u: goto label_13aaf0;
            case 0x13AB08u: goto label_13ab08;
            case 0x13AB20u: goto label_13ab20;
            case 0x13AB28u: goto label_13ab28;
            case 0x13AB54u: goto label_13ab54;
            case 0x13AB60u: goto label_13ab60;
            case 0x13AB88u: goto label_13ab88;
            case 0x13AB90u: goto label_13ab90;
            case 0x13ABA0u: goto label_13aba0;
            case 0x13ABACu: goto label_13abac;
            case 0x13ABD4u: goto label_13abd4;
            case 0x13ABD8u: goto label_13abd8;
            case 0x13ABE4u: goto label_13abe4;
            case 0x13ABF0u: goto label_13abf0;
            case 0x13AC0Cu: goto label_13ac0c;
            case 0x13AC1Cu: goto label_13ac1c;
            case 0x13AC28u: goto label_13ac28;
            case 0x13AC30u: goto label_13ac30;
            case 0x13AC3Cu: goto label_13ac3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13AC5Cu;
    // 0x13ac5c: 0x0  nop
    ctx->pc = 0x13ac5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
