#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CBC60
// Address: 0x1cbc60 - 0x1cbd00
void sub_001CBC60_0x1cbc60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CBC60_0x1cbc60");
#endif

    switch (ctx->pc) {
        case 0x1cbca4u: goto label_1cbca4;
        case 0x1cbcbcu: goto label_1cbcbc;
        case 0x1cbcc8u: goto label_1cbcc8;
        case 0x1cbce0u: goto label_1cbce0;
        default: break;
    }

    ctx->pc = 0x1cbc60u;

    // 0x1cbc60: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1cbc60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1cbc64: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbc64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbc68: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1cbc68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1cbc6c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cbc6cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cbc70: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cbc70u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cbc74: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1cbc74u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cbc78: 0x8c22d9f8  lw          $v0, -0x2608($at)
    ctx->pc = 0x1cbc78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957560)));
    // 0x1cbc7c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CBC7Cu;
    {
        const bool branch_taken_0x1cbc7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CBC80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBC7Cu;
            // 0x1cbc80: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbc7c) {
            ctx->pc = 0x1CBC94u;
            goto label_1cbc94;
        }
    }
    ctx->pc = 0x1CBC84u;
    // 0x1cbc84: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbc84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbc88: 0x8c22da00  lw          $v0, -0x2600($at)
    ctx->pc = 0x1cbc88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957568)));
    // 0x1cbc8c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CBC8Cu;
    {
        const bool branch_taken_0x1cbc8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbc8c) {
            ctx->pc = 0x1CBC9Cu;
            goto label_1cbc9c;
        }
    }
    ctx->pc = 0x1CBC94u;
label_1cbc94:
    // 0x1cbc94: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1CBC94u;
    {
        const bool branch_taken_0x1cbc94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CBC98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBC94u;
            // 0x1cbc98: 0x2402fff0  addiu       $v0, $zero, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbc94) {
            ctx->pc = 0x1CBCE8u;
            goto label_1cbce8;
        }
    }
    ctx->pc = 0x1CBC9Cu;
label_1cbc9c:
    // 0x1cbc9c: 0xc072f78  jal         func_1CBDE0
    ctx->pc = 0x1CBC9Cu;
    SET_GPR_U32(ctx, 31, 0x1CBCA4u);
    ctx->pc = 0x1CBDE0u;
    if (runtime->hasFunction(0x1CBDE0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBCA4u; }
        if (ctx->pc != 0x1CBCA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDE0_0x1cbde0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBCA4u; }
        if (ctx->pc != 0x1CBCA4u) { return; }
    }
    ctx->pc = 0x1CBCA4u;
label_1cbca4:
    // 0x1cbca4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbca4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbca8: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1cbca8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cbcac: 0x8c24c7f0  lw          $a0, -0x3810($at)
    ctx->pc = 0x1cbcacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952944)));
    // 0x1cbcb0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cbcb0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cbcb4: 0xc079402  jal         func_1E5008
    ctx->pc = 0x1CBCB4u;
    SET_GPR_U32(ctx, 31, 0x1CBCBCu);
    ctx->pc = 0x1CBCB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBCB4u;
            // 0x1cbcb8: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1E5008u;
    if (runtime->hasFunction(0x1E5008u)) {
        auto targetFn = runtime->lookupFunction(0x1E5008u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBCBCu; }
        if (ctx->pc != 0x1CBCBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E5008_0x1e5008(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBCBCu; }
        if (ctx->pc != 0x1CBCBCu) { return; }
    }
    ctx->pc = 0x1CBCBCu;
label_1cbcbc:
    // 0x1cbcbc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbcbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbcc0: 0xc072f7c  jal         func_1CBDF0
    ctx->pc = 0x1CBCC0u;
    SET_GPR_U32(ctx, 31, 0x1CBCC8u);
    ctx->pc = 0x1CBCC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBCC0u;
            // 0x1cbcc4: 0xac22da00  sw          $v0, -0x2600($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294957568), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CBDF0u;
    if (runtime->hasFunction(0x1CBDF0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBCC8u; }
        if (ctx->pc != 0x1CBCC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDF0_0x1cbdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBCC8u; }
        if (ctx->pc != 0x1CBCC8u) { return; }
    }
    ctx->pc = 0x1CBCC8u;
label_1cbcc8:
    // 0x1cbcc8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbcc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbccc: 0x8c22da00  lw          $v0, -0x2600($at)
    ctx->pc = 0x1cbcccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957568)));
    // 0x1cbcd0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CBCD0u;
    {
        const bool branch_taken_0x1cbcd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CBCD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBCD0u;
            // 0x1cbcd4: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbcd0) {
            ctx->pc = 0x1CBCE8u;
            goto label_1cbce8;
        }
    }
    ctx->pc = 0x1CBCD8u;
    // 0x1cbcd8: 0xc072ed8  jal         func_1CBB60
    ctx->pc = 0x1CBCD8u;
    SET_GPR_U32(ctx, 31, 0x1CBCE0u);
    ctx->pc = 0x1CBB60u;
    if (runtime->hasFunction(0x1CBB60u)) {
        auto targetFn = runtime->lookupFunction(0x1CBB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBCE0u; }
        if (ctx->pc != 0x1CBCE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBB60_0x1cbb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBCE0u; }
        if (ctx->pc != 0x1CBCE0u) { return; }
    }
    ctx->pc = 0x1CBCE0u;
label_1cbce0:
    // 0x1cbce0: 0x10000001  b           . + 4 + (0x1 << 2)
    ctx->pc = 0x1CBCE0u;
    {
        const bool branch_taken_0x1cbce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbce0) {
            ctx->pc = 0x1CBCE8u;
            goto label_1cbce8;
        }
    }
    ctx->pc = 0x1CBCE8u;
label_1cbce8:
    // 0x1cbce8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1cbce8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cbcec: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cbcecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cbcf0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cbcf0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cbcf4: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBCF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBCF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBCF4u;
            // 0x1cbcf8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CBC94u: goto label_1cbc94;
            case 0x1CBC9Cu: goto label_1cbc9c;
            case 0x1CBCA4u: goto label_1cbca4;
            case 0x1CBCBCu: goto label_1cbcbc;
            case 0x1CBCC8u: goto label_1cbcc8;
            case 0x1CBCE0u: goto label_1cbce0;
            case 0x1CBCE8u: goto label_1cbce8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBCFCu;
    // 0x1cbcfc: 0x0  nop
    ctx->pc = 0x1cbcfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
