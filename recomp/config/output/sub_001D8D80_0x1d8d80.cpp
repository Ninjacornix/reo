#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8D80
// Address: 0x1d8d80 - 0x1d8e10
void sub_001D8D80_0x1d8d80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8D80_0x1d8d80");
#endif

    switch (ctx->pc) {
        case 0x1d8da4u: goto label_1d8da4;
        case 0x1d8dc4u: goto label_1d8dc4;
        case 0x1d8dd8u: goto label_1d8dd8;
        case 0x1d8df4u: goto label_1d8df4;
        default: break;
    }

    ctx->pc = 0x1d8d80u;

    // 0x1d8d80: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1d8d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1d8d84: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d8d84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d8d88: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d8d88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d8d8c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d8d8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d8d90: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1d8d90u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8d94: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d8d94u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d8d98: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1d8d98u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8d9c: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8D9Cu;
    SET_GPR_U32(ctx, 31, 0x1D8DA4u);
    ctx->pc = 0x1D8DA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8D9Cu;
            // 0x1d8da0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8DA4u; }
        if (ctx->pc != 0x1D8DA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8DA4u; }
        if (ctx->pc != 0x1D8DA4u) { return; }
    }
    ctx->pc = 0x1D8DA4u;
label_1d8da4:
    // 0x1d8da4: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d8da4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d8da8: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d8da8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d8dac: 0x2404002d  addiu       $a0, $zero, 0x2D
    ctx->pc = 0x1d8dacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x1d8db0: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d8db0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d8db4: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1d8db4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d8db8: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d8db8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d8dbc: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D8DBCu;
    SET_GPR_U32(ctx, 31, 0x1D8DC4u);
    ctx->pc = 0x1D8DC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8DBCu;
            // 0x1d8dc0: 0x24080128  addiu       $t0, $zero, 0x128 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 296));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8DC4u; }
        if (ctx->pc != 0x1D8DC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8DC4u; }
        if (ctx->pc != 0x1D8DC4u) { return; }
    }
    ctx->pc = 0x1D8DC4u;
label_1d8dc4:
    // 0x1d8dc4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d8dc4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8dc8: 0x3c100034  lui         $s0, 0x34
    ctx->pc = 0x1d8dc8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)52 << 16));
    // 0x1d8dcc: 0x2610629c  addiu       $s0, $s0, 0x629C
    ctx->pc = 0x1d8dccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 25244));
    // 0x1d8dd0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1D8DD0u;
    SET_GPR_U32(ctx, 31, 0x1D8DD8u);
    ctx->pc = 0x1D8DD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8DD0u;
            // 0x1d8dd4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8DD8u; }
        if (ctx->pc != 0x1D8DD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8DD8u; }
        if (ctx->pc != 0x1D8DD8u) { return; }
    }
    ctx->pc = 0x1D8DD8u;
label_1d8dd8:
    // 0x1d8dd8: 0x8e020100  lw          $v0, 0x100($s0)
    ctx->pc = 0x1d8dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 256)));
    // 0x1d8ddc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8ddcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8de0: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x1d8de0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1d8de4: 0x8e020104  lw          $v0, 0x104($s0)
    ctx->pc = 0x1d8de4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 260)));
    // 0x1d8de8: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1d8de8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1d8dec: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D8DECu;
    SET_GPR_U32(ctx, 31, 0x1D8DF4u);
    ctx->pc = 0x1D8DF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8DECu;
            // 0x1d8df0: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8DF4u; }
        if (ctx->pc != 0x1D8DF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8DF4u; }
        if (ctx->pc != 0x1D8DF4u) { return; }
    }
    ctx->pc = 0x1D8DF4u;
label_1d8df4:
    // 0x1d8df4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d8df4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8df8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d8df8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d8dfc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d8dfcu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d8e00: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d8e00u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8e04: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d8e04u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8e08: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8E08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D8E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8E08u;
            // 0x1d8e0c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D8DA4u: goto label_1d8da4;
            case 0x1D8DC4u: goto label_1d8dc4;
            case 0x1D8DD8u: goto label_1d8dd8;
            case 0x1D8DF4u: goto label_1d8df4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D8E10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
