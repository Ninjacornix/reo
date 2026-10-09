#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171D10
// Address: 0x171d10 - 0x171e58
void sub_00171D10_0x171d10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171D10_0x171d10");
#endif

    switch (ctx->pc) {
        case 0x171d4cu: goto label_171d4c;
        case 0x171d90u: goto label_171d90;
        case 0x171da8u: goto label_171da8;
        case 0x171db0u: goto label_171db0;
        case 0x171dfcu: goto label_171dfc;
        case 0x171e10u: goto label_171e10;
        case 0x171e1cu: goto label_171e1c;
        case 0x171e24u: goto label_171e24;
        default: break;
    }

    ctx->pc = 0x171d10u;

    // 0x171d10: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x171d10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x171d14: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x171d14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x171d18: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x171d18u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171d1c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x171d1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x171d20: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x171d20u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171d24: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x171d24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171d28: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x171d28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x171d2c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x171d2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x171d30: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x171d30u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171d34: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x171d34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x171d38: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x171d38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x171d3c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x171d3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x171d40: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x171d40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x171d44: 0xc05c54c  jal         func_171530
    ctx->pc = 0x171D44u;
    SET_GPR_U32(ctx, 31, 0x171D4Cu);
    ctx->pc = 0x171D48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171D44u;
            // 0x171d48: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171530u;
    if (runtime->hasFunction(0x171530u)) {
        auto targetFn = runtime->lookupFunction(0x171530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171D4Cu; }
        if (ctx->pc != 0x171D4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171530_0x171530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171D4Cu; }
        if (ctx->pc != 0x171D4Cu) { return; }
    }
    ctx->pc = 0x171D4Cu;
label_171d4c:
    // 0x171d4c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x171d4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171d50: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x171d50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171d54: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x171D54u;
    {
        const bool branch_taken_0x171d54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x171D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171D54u;
            // 0x171d58: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171d54) {
            ctx->pc = 0x171D88u;
            goto label_171d88;
        }
    }
    ctx->pc = 0x171D5Cu;
    // 0x171d5c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x171d5cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171d60: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x171d60u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171d64: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x171d64u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x171d68: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x171d68u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x171d6c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x171d6cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x171d70: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x171d70u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x171d74: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x171d74u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x171d78: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x171d78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x171d7c: 0x805644a  j           func_159128
    ctx->pc = 0x171D7Cu;
    ctx->pc = 0x171D80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171D7Cu;
            // 0x171d80: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x159128u;
    if (runtime->hasFunction(0x159128u)) {
        auto targetFn = runtime->lookupFunction(0x159128u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00159128_0x159128(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x171D84u;
    // 0x171d84: 0x0  nop
    ctx->pc = 0x171d84u;
    // NOP
label_171d88:
    // 0x171d88: 0xc05644c  jal         func_159130
    ctx->pc = 0x171D88u;
    SET_GPR_U32(ctx, 31, 0x171D90u);
    ctx->pc = 0x171D8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171D88u;
            // 0x171d8c: 0x8eb21b30  lw          $s2, 0x1B30($s5) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 6960)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x159130u;
    if (runtime->hasFunction(0x159130u)) {
        auto targetFn = runtime->lookupFunction(0x159130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171D90u; }
        if (ctx->pc != 0x171D90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159130_0x159130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171D90u; }
        if (ctx->pc != 0x171D90u) { return; }
    }
    ctx->pc = 0x171D90u;
label_171d90:
    // 0x171d90: 0x40b02d  daddu       $s6, $v0, $zero
    ctx->pc = 0x171d90u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171d94: 0x26500a48  addiu       $s0, $s2, 0xA48
    ctx->pc = 0x171d94u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 2632));
    // 0x171d98: 0x265309d8  addiu       $s3, $s2, 0x9D8
    ctx->pc = 0x171d98u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), 2520));
    // 0x171d9c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x171d9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171da0: 0xc05c458  jal         func_171160
    ctx->pc = 0x171DA0u;
    SET_GPR_U32(ctx, 31, 0x171DA8u);
    ctx->pc = 0x171DA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171DA0u;
            // 0x171da4: 0x26510004  addiu       $s1, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171160u;
    if (runtime->hasFunction(0x171160u)) {
        auto targetFn = runtime->lookupFunction(0x171160u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171DA8u; }
        if (ctx->pc != 0x171DA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171160_0x171160(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171DA8u; }
        if (ctx->pc != 0x171DA8u) { return; }
    }
    ctx->pc = 0x171DA8u;
label_171da8:
    // 0x171da8: 0xc05c398  jal         func_170E60
    ctx->pc = 0x171DA8u;
    SET_GPR_U32(ctx, 31, 0x171DB0u);
    ctx->pc = 0x171DACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171DA8u;
            // 0x171dac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170E60u;
    if (runtime->hasFunction(0x170E60u)) {
        auto targetFn = runtime->lookupFunction(0x170E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171DB0u; }
        if (ctx->pc != 0x171DB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170E60_0x170e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171DB0u; }
        if (ctx->pc != 0x171DB0u) { return; }
    }
    ctx->pc = 0x171DB0u;
label_171db0:
    // 0x171db0: 0x26440a00  addiu       $a0, $s2, 0xA00
    ctx->pc = 0x171db0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 2560));
    // 0x171db4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x171db4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x171db8: 0x8eaa0038  lw          $t2, 0x38($s5)
    ctx->pc = 0x171db8u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 56)));
    // 0x171dbc: 0xae620014  sw          $v0, 0x14($s3)
    ctx->pc = 0x171dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 20), GPR_U32(ctx, 2));
    // 0x171dc0: 0x24090002  addiu       $t1, $zero, 0x2
    ctx->pc = 0x171dc0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x171dc4: 0x8e23000c  lw          $v1, 0xC($s1)
    ctx->pc = 0x171dc4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x171dc8: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x171dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x171dcc: 0x2468000f  addiu       $t0, $v1, 0xF
    ctx->pc = 0x171dccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x171dd0: 0x28670000  slti        $a3, $v1, 0x0
    ctx->pc = 0x171dd0u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x171dd4: 0x2446000f  addiu       $a2, $v0, 0xF
    ctx->pc = 0x171dd4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 15));
    // 0x171dd8: 0x28450000  slti        $a1, $v0, 0x0
    ctx->pc = 0x171dd8u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x171ddc: 0xc5100b  movn        $v0, $a2, $a1
    ctx->pc = 0x171ddcu;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x171de0: 0x107180b  movn        $v1, $t0, $a3
    ctx->pc = 0x171de0u;
    if (GPR_U64(ctx, 7) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 8));
    // 0x171de4: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x171de4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x171de8: 0x31903  sra         $v1, $v1, 4
    ctx->pc = 0x171de8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 4));
    // 0x171dec: 0x15490006  bne         $t2, $t1, . + 4 + (0x6 << 2)
    ctx->pc = 0x171DECu;
    {
        const bool branch_taken_0x171dec = (GPR_U64(ctx, 10) != GPR_U64(ctx, 9));
        ctx->pc = 0x171DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171DECu;
            // 0x171df0: 0x433018  mult        $a2, $v0, $v1 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x171dec) {
            ctx->pc = 0x171E08u;
            goto label_171e08;
        }
    }
    ctx->pc = 0x171DF4u;
    // 0x171df4: 0xc051f4c  jal         func_147D30
    ctx->pc = 0x171DF4u;
    SET_GPR_U32(ctx, 31, 0x171DFCu);
    ctx->pc = 0x171DF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171DF4u;
            // 0x171df8: 0x8e850020  lw          $a1, 0x20($s4) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 32)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147D30u;
    if (runtime->hasFunction(0x147D30u)) {
        auto targetFn = runtime->lookupFunction(0x147D30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171DFCu; }
        if (ctx->pc != 0x171DFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147D30_0x147d30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171DFCu; }
        if (ctx->pc != 0x171DFCu) { return; }
    }
    ctx->pc = 0x171DFCu;
label_171dfc:
    // 0x171dfc: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x171DFCu;
    {
        const bool branch_taken_0x171dfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x171E00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171DFCu;
            // 0x171e00: 0xae600014  sw          $zero, 0x14($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171dfc) {
            ctx->pc = 0x171E14u;
            goto label_171e14;
        }
    }
    ctx->pc = 0x171E04u;
    // 0x171e04: 0x0  nop
    ctx->pc = 0x171e04u;
    // NOP
label_171e08:
    // 0x171e08: 0xc051f5e  jal         func_147D78
    ctx->pc = 0x171E08u;
    SET_GPR_U32(ctx, 31, 0x171E10u);
    ctx->pc = 0x171E0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171E08u;
            // 0x171e0c: 0x8e850020  lw          $a1, 0x20($s4) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 32)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147D78u;
    if (runtime->hasFunction(0x147D78u)) {
        auto targetFn = runtime->lookupFunction(0x147D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171E10u; }
        if (ctx->pc != 0x171E10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147D78_0x147d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171E10u; }
        if (ctx->pc != 0x171E10u) { return; }
    }
    ctx->pc = 0x171E10u;
label_171e10:
    // 0x171e10: 0xae600014  sw          $zero, 0x14($s3)
    ctx->pc = 0x171e10u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 20), GPR_U32(ctx, 0));
label_171e14:
    // 0x171e14: 0xc05c418  jal         func_171060
    ctx->pc = 0x171E14u;
    SET_GPR_U32(ctx, 31, 0x171E1Cu);
    ctx->pc = 0x171E18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171E14u;
            // 0x171e18: 0x26640070  addiu       $a0, $s3, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171060u;
    if (runtime->hasFunction(0x171060u)) {
        auto targetFn = runtime->lookupFunction(0x171060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171E1Cu; }
        if (ctx->pc != 0x171E1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171060_0x171060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171E1Cu; }
        if (ctx->pc != 0x171E1Cu) { return; }
    }
    ctx->pc = 0x171E1Cu;
label_171e1c:
    // 0x171e1c: 0xc05c800  jal         func_172000
    ctx->pc = 0x171E1Cu;
    SET_GPR_U32(ctx, 31, 0x171E24u);
    ctx->pc = 0x171E20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171E1Cu;
            // 0x171e20: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172000u;
    if (runtime->hasFunction(0x172000u)) {
        auto targetFn = runtime->lookupFunction(0x172000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171E24u; }
        if (ctx->pc != 0x171E24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172000_0x172000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171E24u; }
        if (ctx->pc != 0x171E24u) { return; }
    }
    ctx->pc = 0x171E24u;
label_171e24:
    // 0x171e24: 0x8e630018  lw          $v1, 0x18($s3)
    ctx->pc = 0x171e24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x171e28: 0x2402fffd  addiu       $v0, $zero, -0x3
    ctx->pc = 0x171e28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x171e2c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x171e2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171e30: 0x2c3100a  movz        $v0, $s6, $v1
    ctx->pc = 0x171e30u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 22));
    // 0x171e34: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x171e34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171e38: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x171e38u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x171e3c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x171e3cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x171e40: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x171e40u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x171e44: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x171e44u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x171e48: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x171e48u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x171e4c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x171e4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x171e50: 0x3e00008  jr          $ra
    ctx->pc = 0x171E50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171E50u;
            // 0x171e54: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171D4Cu: goto label_171d4c;
            case 0x171D88u: goto label_171d88;
            case 0x171D90u: goto label_171d90;
            case 0x171DA8u: goto label_171da8;
            case 0x171DB0u: goto label_171db0;
            case 0x171DFCu: goto label_171dfc;
            case 0x171E08u: goto label_171e08;
            case 0x171E10u: goto label_171e10;
            case 0x171E14u: goto label_171e14;
            case 0x171E1Cu: goto label_171e1c;
            case 0x171E24u: goto label_171e24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x171E58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
