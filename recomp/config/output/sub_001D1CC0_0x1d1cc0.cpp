#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D1CC0
// Address: 0x1d1cc0 - 0x1d1dfc
void sub_001D1CC0_0x1d1cc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D1CC0_0x1d1cc0");
#endif

    switch (ctx->pc) {
        case 0x1d1d08u: goto label_1d1d08;
        case 0x1d1d20u: goto label_1d1d20;
        case 0x1d1d44u: goto label_1d1d44;
        case 0x1d1d5cu: goto label_1d1d5c;
        case 0x1d1d70u: goto label_1d1d70;
        case 0x1d1d94u: goto label_1d1d94;
        case 0x1d1dacu: goto label_1d1dac;
        case 0x1d1dc0u: goto label_1d1dc0;
        case 0x1d1de0u: goto label_1d1de0;
        default: break;
    }

    ctx->pc = 0x1d1cc0u;

    // 0x1d1cc0: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x1d1cc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x1d1cc4: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1d1cc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1d1cc8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d1cc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d1ccc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d1cccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d1cd0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d1cd0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d1cd4: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1d1cd4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1cd8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d1cd8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d1cdc: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1d1cdcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1ce0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d1ce0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d1ce4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1ce4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1ce8: 0xa020ae0f  sb          $zero, -0x51F1($at)
    ctx->pc = 0x1d1ce8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946319), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d1cec: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1d1cecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d1cf0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1cf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1cf4: 0x24a56430  addiu       $a1, $a1, 0x6430
    ctx->pc = 0x1d1cf4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25648));
    // 0x1d1cf8: 0x8c31440c  lw          $s1, 0x440C($at)
    ctx->pc = 0x1d1cf8u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1cfc: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1d1cfcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d00: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1D00u;
    SET_GPR_U32(ctx, 31, 0x1D1D08u);
    ctx->pc = 0x1D1D04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1D00u;
            // 0x1d1d04: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D08u; }
        if (ctx->pc != 0x1D1D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D08u; }
        if (ctx->pc != 0x1D1D08u) { return; }
    }
    ctx->pc = 0x1D1D08u;
label_1d1d08:
    // 0x1d1d08: 0x27b00050  addiu       $s0, $sp, 0x50
    ctx->pc = 0x1d1d08u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d1d0c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d1d0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d10: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d1d10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d14: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d1d14u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1d18: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1D18u;
    SET_GPR_U32(ctx, 31, 0x1D1D20u);
    ctx->pc = 0x1D1D1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1D18u;
            // 0x1d1d1c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D20u; }
        if (ctx->pc != 0x1D1D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D20u; }
        if (ctx->pc != 0x1D1D20u) { return; }
    }
    ctx->pc = 0x1D1D20u;
label_1d1d20:
    // 0x1d1d20: 0x18400008  blez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D1D20u;
    {
        const bool branch_taken_0x1d1d20 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1d1d20) {
            ctx->pc = 0x1D1D44u;
            goto label_1d1d44;
        }
    }
    ctx->pc = 0x1D1D28u;
    // 0x1d1d28: 0x3c05004c  lui         $a1, 0x4C
    ctx->pc = 0x1d1d28u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)76 << 16));
    // 0x1d1d2c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d1d2cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d30: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d1d30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d34: 0x24a5c810  addiu       $a1, $a1, -0x37F0
    ctx->pc = 0x1d1d34u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294952976));
    // 0x1d1d38: 0x240700c8  addiu       $a3, $zero, 0xC8
    ctx->pc = 0x1d1d38u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
    // 0x1d1d3c: 0xc074658  jal         func_1D1960
    ctx->pc = 0x1D1D3Cu;
    SET_GPR_U32(ctx, 31, 0x1D1D44u);
    ctx->pc = 0x1D1D40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1D3Cu;
            // 0x1d1d40: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1960u;
    if (runtime->hasFunction(0x1D1960u)) {
        auto targetFn = runtime->lookupFunction(0x1D1960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D44u; }
        if (ctx->pc != 0x1D1D44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1960_0x1d1960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D44u; }
        if (ctx->pc != 0x1D1D44u) { return; }
    }
    ctx->pc = 0x1D1D44u;
label_1d1d44:
    // 0x1d1d44: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1d44u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1d48: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1d1d48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d1d4c: 0x24a56460  addiu       $a1, $a1, 0x6460
    ctx->pc = 0x1d1d4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25696));
    // 0x1d1d50: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1d1d50u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d54: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1D54u;
    SET_GPR_U32(ctx, 31, 0x1D1D5Cu);
    ctx->pc = 0x1D1D58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1D54u;
            // 0x1d1d58: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D5Cu; }
        if (ctx->pc != 0x1D1D5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D5Cu; }
        if (ctx->pc != 0x1D1D5Cu) { return; }
    }
    ctx->pc = 0x1D1D5Cu;
label_1d1d5c:
    // 0x1d1d5c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d1d5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d60: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d1d60u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d64: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d1d64u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1d68: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1D68u;
    SET_GPR_U32(ctx, 31, 0x1D1D70u);
    ctx->pc = 0x1D1D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1D68u;
            // 0x1d1d6c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D70u; }
        if (ctx->pc != 0x1D1D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D70u; }
        if (ctx->pc != 0x1D1D70u) { return; }
    }
    ctx->pc = 0x1D1D70u;
label_1d1d70:
    // 0x1d1d70: 0x18400008  blez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D1D70u;
    {
        const bool branch_taken_0x1d1d70 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1d1d70) {
            ctx->pc = 0x1D1D94u;
            goto label_1d1d94;
        }
    }
    ctx->pc = 0x1D1D78u;
    // 0x1d1d78: 0x3c05004c  lui         $a1, 0x4C
    ctx->pc = 0x1d1d78u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)76 << 16));
    // 0x1d1d7c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d1d7cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d80: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d1d80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d84: 0x24a5bb80  addiu       $a1, $a1, -0x4480
    ctx->pc = 0x1d1d84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294949760));
    // 0x1d1d88: 0x240700c8  addiu       $a3, $zero, 0xC8
    ctx->pc = 0x1d1d88u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
    // 0x1d1d8c: 0xc074658  jal         func_1D1960
    ctx->pc = 0x1D1D8Cu;
    SET_GPR_U32(ctx, 31, 0x1D1D94u);
    ctx->pc = 0x1D1D90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1D8Cu;
            // 0x1d1d90: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1960u;
    if (runtime->hasFunction(0x1D1960u)) {
        auto targetFn = runtime->lookupFunction(0x1D1960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D94u; }
        if (ctx->pc != 0x1D1D94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1960_0x1d1960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1D94u; }
        if (ctx->pc != 0x1D1D94u) { return; }
    }
    ctx->pc = 0x1D1D94u;
label_1d1d94:
    // 0x1d1d94: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1d94u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1d98: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1d1d98u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1d9c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x1d1d9cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1da0: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1d1da0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1d1da4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1DA4u;
    SET_GPR_U32(ctx, 31, 0x1D1DACu);
    ctx->pc = 0x1D1DA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1DA4u;
            // 0x1d1da8: 0x24a56490  addiu       $a1, $a1, 0x6490 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25744));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1DACu; }
        if (ctx->pc != 0x1D1DACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1DACu; }
        if (ctx->pc != 0x1D1DACu) { return; }
    }
    ctx->pc = 0x1D1DACu;
label_1d1dac:
    // 0x1d1dac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d1dacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1db0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d1db0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1db4: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d1db4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1db8: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1DB8u;
    SET_GPR_U32(ctx, 31, 0x1D1DC0u);
    ctx->pc = 0x1D1DBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1DB8u;
            // 0x1d1dbc: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1DC0u; }
        if (ctx->pc != 0x1D1DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1DC0u; }
        if (ctx->pc != 0x1D1DC0u) { return; }
    }
    ctx->pc = 0x1D1DC0u;
label_1d1dc0:
    // 0x1d1dc0: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d1dc0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1dc4: 0x18c00006  blez        $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D1DC4u;
    {
        const bool branch_taken_0x1d1dc4 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x1D1DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1DC4u;
            // 0x1d1dc8: 0x3c05004f  lui         $a1, 0x4F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)79 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1dc4) {
            ctx->pc = 0x1D1DE0u;
            goto label_1d1de0;
        }
    }
    ctx->pc = 0x1D1DCCu;
    // 0x1d1dcc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d1dccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1dd0: 0x24a58970  addiu       $a1, $a1, -0x7690
    ctx->pc = 0x1d1dd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294936944));
    // 0x1d1dd4: 0x240700c8  addiu       $a3, $zero, 0xC8
    ctx->pc = 0x1d1dd4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
    // 0x1d1dd8: 0xc074658  jal         func_1D1960
    ctx->pc = 0x1D1DD8u;
    SET_GPR_U32(ctx, 31, 0x1D1DE0u);
    ctx->pc = 0x1D1DDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1DD8u;
            // 0x1d1ddc: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1960u;
    if (runtime->hasFunction(0x1D1960u)) {
        auto targetFn = runtime->lookupFunction(0x1D1960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1DE0u; }
        if (ctx->pc != 0x1D1DE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1960_0x1d1960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1DE0u; }
        if (ctx->pc != 0x1D1DE0u) { return; }
    }
    ctx->pc = 0x1D1DE0u;
label_1d1de0:
    // 0x1d1de0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d1de0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d1de4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d1de4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d1de8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d1de8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d1dec: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d1decu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1df0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1df0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1df4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1DF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1DF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1DF4u;
            // 0x1d1df8: 0x27bd00d0  addiu       $sp, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1D08u: goto label_1d1d08;
            case 0x1D1D20u: goto label_1d1d20;
            case 0x1D1D44u: goto label_1d1d44;
            case 0x1D1D5Cu: goto label_1d1d5c;
            case 0x1D1D70u: goto label_1d1d70;
            case 0x1D1D94u: goto label_1d1d94;
            case 0x1D1DACu: goto label_1d1dac;
            case 0x1D1DC0u: goto label_1d1dc0;
            case 0x1D1DE0u: goto label_1d1de0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1DFCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
