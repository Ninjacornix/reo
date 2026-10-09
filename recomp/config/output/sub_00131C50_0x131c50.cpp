#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131C50
// Address: 0x131c50 - 0x131d18
void sub_00131C50_0x131c50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131C50_0x131c50");
#endif

    switch (ctx->pc) {
        case 0x131c98u: goto label_131c98;
        case 0x131ca4u: goto label_131ca4;
        case 0x131cb4u: goto label_131cb4;
        case 0x131cc0u: goto label_131cc0;
        case 0x131cc8u: goto label_131cc8;
        case 0x131cd0u: goto label_131cd0;
        case 0x131ce8u: goto label_131ce8;
        case 0x131cf0u: goto label_131cf0;
        default: break;
    }

    ctx->pc = 0x131c50u;

    // 0x131c50: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x131c50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x131c54: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131c54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131c58: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x131c58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131c5c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x131c5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x131c60: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x131c60u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131c64: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x131c64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x131c68: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x131c68u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131c6c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x131c6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x131c70: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x131c70u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131c74: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x131c74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x131c78: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x131c78u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131c7c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x131c7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x131c80: 0x8605003e  lh          $a1, 0x3E($s0)
    ctx->pc = 0x131c80u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x131c84: 0x8606003c  lh          $a2, 0x3C($s0)
    ctx->pc = 0x131c84u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x131c88: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x131c88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x131c8c: 0x52ac0  sll         $a1, $a1, 11
    ctx->pc = 0x131c8cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 11));
    // 0x131c90: 0xc04c386  jal         func_130E18
    ctx->pc = 0x131C90u;
    SET_GPR_U32(ctx, 31, 0x131C98u);
    ctx->pc = 0x131C94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131C90u;
            // 0x131c94: 0x632c0  sll         $a2, $a2, 11 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130E18u;
    if (runtime->hasFunction(0x130E18u)) {
        auto targetFn = runtime->lookupFunction(0x130E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131C98u; }
        if (ctx->pc != 0x131C98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130E18_0x130e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131C98u; }
        if (ctx->pc != 0x131C98u) { return; }
    }
    ctx->pc = 0x131C98u;
label_131c98:
    // 0x131c98: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x131c98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x131c9c: 0xc04c1ea  jal         func_1307A8
    ctx->pc = 0x131C9Cu;
    SET_GPR_U32(ctx, 31, 0x131CA4u);
    ctx->pc = 0x131CA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131C9Cu;
            // 0x131ca0: 0x24050019  addiu       $a1, $zero, 0x19 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1307A8u;
    if (runtime->hasFunction(0x1307A8u)) {
        auto targetFn = runtime->lookupFunction(0x1307A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CA4u; }
        if (ctx->pc != 0x131CA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001307A8_0x1307a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CA4u; }
        if (ctx->pc != 0x131CA4u) { return; }
    }
    ctx->pc = 0x131CA4u;
label_131ca4:
    // 0x131ca4: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x131ca4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x131ca8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x131ca8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131cac: 0xc04c1e6  jal         func_130798
    ctx->pc = 0x131CACu;
    SET_GPR_U32(ctx, 31, 0x131CB4u);
    ctx->pc = 0x131CB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131CACu;
            // 0x131cb0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130798u;
    if (runtime->hasFunction(0x130798u)) {
        auto targetFn = runtime->lookupFunction(0x130798u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CB4u; }
        if (ctx->pc != 0x131CB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130798_0x130798(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CB4u; }
        if (ctx->pc != 0x131CB4u) { return; }
    }
    ctx->pc = 0x131CB4u;
label_131cb4:
    // 0x131cb4: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x131cb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x131cb8: 0xc04c170  jal         func_1305C0
    ctx->pc = 0x131CB8u;
    SET_GPR_U32(ctx, 31, 0x131CC0u);
    ctx->pc = 0x131CBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131CB8u;
            // 0x131cbc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305C0u;
    if (runtime->hasFunction(0x1305C0u)) {
        auto targetFn = runtime->lookupFunction(0x1305C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CC0u; }
        if (ctx->pc != 0x131CC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305C0_0x1305c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CC0u; }
        if (ctx->pc != 0x131CC0u) { return; }
    }
    ctx->pc = 0x131CC0u;
label_131cc0:
    // 0x131cc0: 0xc04c1b8  jal         func_1306E0
    ctx->pc = 0x131CC0u;
    SET_GPR_U32(ctx, 31, 0x131CC8u);
    ctx->pc = 0x131CC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131CC0u;
            // 0x131cc4: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1306E0u;
    if (runtime->hasFunction(0x1306E0u)) {
        auto targetFn = runtime->lookupFunction(0x1306E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CC8u; }
        if (ctx->pc != 0x131CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001306E0_0x1306e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CC8u; }
        if (ctx->pc != 0x131CC8u) { return; }
    }
    ctx->pc = 0x131CC8u;
label_131cc8:
    // 0x131cc8: 0xc04c148  jal         func_130520
    ctx->pc = 0x131CC8u;
    SET_GPR_U32(ctx, 31, 0x131CD0u);
    ctx->pc = 0x131CCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131CC8u;
            // 0x131ccc: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130520u;
    if (runtime->hasFunction(0x130520u)) {
        auto targetFn = runtime->lookupFunction(0x130520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CD0u; }
        if (ctx->pc != 0x131CD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130520_0x130520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CD0u; }
        if (ctx->pc != 0x131CD0u) { return; }
    }
    ctx->pc = 0x131CD0u;
label_131cd0:
    // 0x131cd0: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x131cd0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x131cd4: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x131cd4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131cd8: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x131cd8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131cdc: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x131cdcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131ce0: 0xc04c11e  jal         func_130478
    ctx->pc = 0x131CE0u;
    SET_GPR_U32(ctx, 31, 0x131CE8u);
    ctx->pc = 0x131CE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131CE0u;
            // 0x131ce4: 0x220402d  daddu       $t0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130478u;
    if (runtime->hasFunction(0x130478u)) {
        auto targetFn = runtime->lookupFunction(0x130478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CE8u; }
        if (ctx->pc != 0x131CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130478_0x130478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CE8u; }
        if (ctx->pc != 0x131CE8u) { return; }
    }
    ctx->pc = 0x131CE8u;
label_131ce8:
    // 0x131ce8: 0xc04c196  jal         func_130658
    ctx->pc = 0x131CE8u;
    SET_GPR_U32(ctx, 31, 0x131CF0u);
    ctx->pc = 0x131CECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131CE8u;
            // 0x131cec: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130658u;
    if (runtime->hasFunction(0x130658u)) {
        auto targetFn = runtime->lookupFunction(0x130658u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CF0u; }
        if (ctx->pc != 0x131CF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130658_0x130658(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131CF0u; }
        if (ctx->pc != 0x131CF0u) { return; }
    }
    ctx->pc = 0x131CF0u;
label_131cf0:
    // 0x131cf0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x131cf0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131cf4: 0x8c850010  lw          $a1, 0x10($a0)
    ctx->pc = 0x131cf4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x131cf8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131cf8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131cfc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x131cfcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131d00: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x131d00u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x131d04: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x131d04u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x131d08: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x131d08u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x131d0c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x131d0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x131d10: 0x804c6d8  j           func_131B60
    ctx->pc = 0x131D10u;
    ctx->pc = 0x131D14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131D10u;
            // 0x131d14: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131B60u;
    if (runtime->hasFunction(0x131B60u)) {
        auto targetFn = runtime->lookupFunction(0x131B60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00131B60_0x131b60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131D18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
