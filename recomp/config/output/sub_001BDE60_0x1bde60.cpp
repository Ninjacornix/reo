#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BDE60
// Address: 0x1bde60 - 0x1bdf70
void sub_001BDE60_0x1bde60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BDE60_0x1bde60");
#endif

    switch (ctx->pc) {
        case 0x1bde94u: goto label_1bde94;
        case 0x1bdea0u: goto label_1bdea0;
        case 0x1bdeacu: goto label_1bdeac;
        case 0x1bdeb4u: goto label_1bdeb4;
        case 0x1bded0u: goto label_1bded0;
        case 0x1bdef8u: goto label_1bdef8;
        case 0x1bdf08u: goto label_1bdf08;
        case 0x1bdf28u: goto label_1bdf28;
        case 0x1bdf30u: goto label_1bdf30;
        default: break;
    }

    ctx->pc = 0x1bde60u;

    // 0x1bde60: 0x27bdff10  addiu       $sp, $sp, -0xF0
    ctx->pc = 0x1bde60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967056));
    // 0x1bde64: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1bde64u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1bde68: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1bde68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1bde6c: 0x24a50468  addiu       $a1, $a1, 0x468
    ctx->pc = 0x1bde6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1128));
    // 0x1bde70: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1bde70u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1bde74: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1bde74u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1bde78: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1bde78u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bde7c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1bde7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1bde80: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1bde80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1bde84: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1bde84u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1bde88: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1bde88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1bde8c: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1BDE8Cu;
    SET_GPR_U32(ctx, 31, 0x1BDE94u);
    ctx->pc = 0x1BDE90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDE8Cu;
            // 0x1bde90: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDE94u; }
        if (ctx->pc != 0x1BDE94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDE94u; }
        if (ctx->pc != 0x1BDE94u) { return; }
    }
    ctx->pc = 0x1BDE94u;
label_1bde94:
    // 0x1bde94: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1bde94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1bde98: 0xc04673c  jal         func_119CF0
    ctx->pc = 0x1BDE98u;
    SET_GPR_U32(ctx, 31, 0x1BDEA0u);
    ctx->pc = 0x1BDE9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDE98u;
            // 0x1bde9c: 0x240501ff  addiu       $a1, $zero, 0x1FF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 511));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119CF0u;
    if (runtime->hasFunction(0x119CF0u)) {
        auto targetFn = runtime->lookupFunction(0x119CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDEA0u; }
        if (ctx->pc != 0x1BDEA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119CF0_0x119cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDEA0u; }
        if (ctx->pc != 0x1BDEA0u) { return; }
    }
    ctx->pc = 0x1BDEA0u;
label_1bdea0:
    // 0x1bdea0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1bdea0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdea4: 0x4a10005  bgez        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BDEA4u;
    {
        const bool branch_taken_0x1bdea4 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x1bdea4) {
            ctx->pc = 0x1BDEBCu;
            goto label_1bdebc;
        }
    }
    ctx->pc = 0x1BDEACu;
label_1bdeac:
    // 0x1bdeac: 0xc06f660  jal         func_1BD980
    ctx->pc = 0x1BDEACu;
    SET_GPR_U32(ctx, 31, 0x1BDEB4u);
    ctx->pc = 0x1BDEB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDEACu;
            // 0x1bdeb0: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD980u;
    if (runtime->hasFunction(0x1BD980u)) {
        auto targetFn = runtime->lookupFunction(0x1BD980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDEB4u; }
        if (ctx->pc != 0x1BDEB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD980_0x1bd980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDEB4u; }
        if (ctx->pc != 0x1BDEB4u) { return; }
    }
    ctx->pc = 0x1BDEB4u;
label_1bdeb4:
    // 0x1bdeb4: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1BDEB4u;
    {
        const bool branch_taken_0x1bdeb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDEB4u;
            // 0x1bdeb8: 0xdfbf0060  ld          $ra, 0x60($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdeb4) {
            ctx->pc = 0x1BDF50u;
            goto label_1bdf50;
        }
    }
    ctx->pc = 0x1BDEBCu;
label_1bdebc:
    // 0x1bdebc: 0x8eb0003c  lw          $s0, 0x3C($s5)
    ctx->pc = 0x1bdebcu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 60)));
    // 0x1bdec0: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1bdec0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdec4: 0x8e130004  lw          $s3, 0x4($s0)
    ctx->pc = 0x1bdec4u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bdec8: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1BDEC8u;
    {
        const bool branch_taken_0x1bdec8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDEC8u;
            // 0x1bdecc: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdec8) {
            ctx->pc = 0x1BDF34u;
            goto label_1bdf34;
        }
    }
    ctx->pc = 0x1BDED0u;
label_1bded0:
    // 0x1bded0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1bded0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1bded4: 0x141880  sll         $v1, $s4, 2
    ctx->pc = 0x1bded4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 2));
    // 0x1bded8: 0x24424ff8  addiu       $v0, $v0, 0x4FF8
    ctx->pc = 0x1bded8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20472));
    // 0x1bdedc: 0x8e120000  lw          $s2, 0x0($s0)
    ctx->pc = 0x1bdedcu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bdee0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bdee0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bdee4: 0x8e110004  lw          $s1, 0x4($s0)
    ctx->pc = 0x1bdee4u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bdee8: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1bdee8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bdeec: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1bdeecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1bdef0: 0xc06f914  jal         func_1BE450
    ctx->pc = 0x1BDEF0u;
    SET_GPR_U32(ctx, 31, 0x1BDEF8u);
    ctx->pc = 0x1BDEF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDEF0u;
            // 0x1bdef4: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE450u;
    if (runtime->hasFunction(0x1BE450u)) {
        auto targetFn = runtime->lookupFunction(0x1BE450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDEF8u; }
        if (ctx->pc != 0x1BDEF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE450_0x1be450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDEF8u; }
        if (ctx->pc != 0x1BDEF8u) { return; }
    }
    ctx->pc = 0x1BDEF8u;
label_1bdef8:
    // 0x1bdef8: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1bdef8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1bdefc: 0x24050602  addiu       $a1, $zero, 0x602
    ctx->pc = 0x1bdefcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1538));
    // 0x1bdf00: 0xc04629c  jal         func_118A70
    ctx->pc = 0x1BDF00u;
    SET_GPR_U32(ctx, 31, 0x1BDF08u);
    ctx->pc = 0x1BDF04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDF00u;
            // 0x1bdf04: 0x240601b6  addiu       $a2, $zero, 0x1B6 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 438));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDF08u; }
        if (ctx->pc != 0x1BDF08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDF08u; }
        if (ctx->pc != 0x1BDF08u) { return; }
    }
    ctx->pc = 0x1BDF08u;
label_1bdf08:
    // 0x1bdf08: 0x440ffe8  bltz        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1BDF08u;
    {
        const bool branch_taken_0x1bdf08 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1BDF0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDF08u;
            // 0x1bdf0c: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdf08) {
            ctx->pc = 0x1BDEACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bdeac;
        }
    }
    ctx->pc = 0x1BDF10u;
    // 0x1bdf10: 0xaea5002c  sw          $a1, 0x2C($s5)
    ctx->pc = 0x1bdf10u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 44), GPR_U32(ctx, 5));
    // 0x1bdf14: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1bdf14u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdf18: 0x8ea2003c  lw          $v0, 0x3C($s5)
    ctx->pc = 0x1bdf18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 60)));
    // 0x1bdf1c: 0x8ea4002c  lw          $a0, 0x2C($s5)
    ctx->pc = 0x1bdf1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 44)));
    // 0x1bdf20: 0xc0464c4  jal         func_119310
    ctx->pc = 0x1BDF20u;
    SET_GPR_U32(ctx, 31, 0x1BDF28u);
    ctx->pc = 0x1BDF24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDF20u;
            // 0x1bdf24: 0x522821  addu        $a1, $v0, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119310u;
    if (runtime->hasFunction(0x119310u)) {
        auto targetFn = runtime->lookupFunction(0x119310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDF28u; }
        if (ctx->pc != 0x1BDF28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119310_0x119310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDF28u; }
        if (ctx->pc != 0x1BDF28u) { return; }
    }
    ctx->pc = 0x1BDF28u;
label_1bdf28:
    // 0x1bdf28: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1BDF28u;
    SET_GPR_U32(ctx, 31, 0x1BDF30u);
    ctx->pc = 0x1BDF2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDF28u;
            // 0x1bdf2c: 0x8ea4002c  lw          $a0, 0x2C($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 44)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDF30u; }
        if (ctx->pc != 0x1BDF30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDF30u; }
        if (ctx->pc != 0x1BDF30u) { return; }
    }
    ctx->pc = 0x1BDF30u;
label_1bdf30:
    // 0x1bdf30: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x1bdf30u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
label_1bdf34:
    // 0x1bdf34: 0x293182a  slt         $v1, $s4, $s3
    ctx->pc = 0x1bdf34u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x1bdf38: 0x1460ffe5  bnez        $v1, . + 4 + (-0x1B << 2)
    ctx->pc = 0x1BDF38u;
    {
        const bool branch_taken_0x1bdf38 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bdf38) {
            ctx->pc = 0x1BDED0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bded0;
        }
    }
    ctx->pc = 0x1BDF40u;
    // 0x1bdf40: 0x8ea30000  lw          $v1, 0x0($s5)
    ctx->pc = 0x1bdf40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1bdf44: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bdf44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bdf48: 0xaea30000  sw          $v1, 0x0($s5)
    ctx->pc = 0x1bdf48u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
    // 0x1bdf4c: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1bdf4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_1bdf50:
    // 0x1bdf50: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1bdf50u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1bdf54: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1bdf54u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1bdf58: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1bdf58u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1bdf5c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1bdf5cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bdf60: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1bdf60u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bdf64: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bdf64u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bdf68: 0x3e00008  jr          $ra
    ctx->pc = 0x1BDF68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BDF6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDF68u;
            // 0x1bdf6c: 0x27bd00f0  addiu       $sp, $sp, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BDE94u: goto label_1bde94;
            case 0x1BDEA0u: goto label_1bdea0;
            case 0x1BDEACu: goto label_1bdeac;
            case 0x1BDEB4u: goto label_1bdeb4;
            case 0x1BDEBCu: goto label_1bdebc;
            case 0x1BDED0u: goto label_1bded0;
            case 0x1BDEF8u: goto label_1bdef8;
            case 0x1BDF08u: goto label_1bdf08;
            case 0x1BDF28u: goto label_1bdf28;
            case 0x1BDF30u: goto label_1bdf30;
            case 0x1BDF34u: goto label_1bdf34;
            case 0x1BDF50u: goto label_1bdf50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BDF70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
