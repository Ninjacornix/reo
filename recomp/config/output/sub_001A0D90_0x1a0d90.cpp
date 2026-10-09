#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A0D90
// Address: 0x1a0d90 - 0x1a0e10
void sub_001A0D90_0x1a0d90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A0D90_0x1a0d90");
#endif

    ctx->pc = 0x1a0d90u;

    // 0x1a0d90: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a0d90u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a0d94: 0x80684fc  j           func_1A13F0
    ctx->pc = 0x1A0D94u;
    ctx->pc = 0x1A0D98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0D94u;
            // 0x1a0d98: 0x2484fef0  addiu       $a0, $a0, -0x110 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A13F0u;
    if (runtime->hasFunction(0x1A13F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A13F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A13F0_0x1a13f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1A0D9Cu;
    // 0x1a0d9c: 0x0  nop
    ctx->pc = 0x1a0d9cu;
    // NOP
    // 0x1a0da0: 0xac860000  sw          $a2, 0x0($a0)
    ctx->pc = 0x1a0da0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 6));
    // 0x1a0da4: 0xac850008  sw          $a1, 0x8($a0)
    ctx->pc = 0x1a0da4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 5));
    // 0x1a0da8: 0xac880004  sw          $t0, 0x4($a0)
    ctx->pc = 0x1a0da8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 8));
    // 0x1a0dac: 0xac8a000c  sw          $t2, 0xC($a0)
    ctx->pc = 0x1a0dacu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 10));
    // 0x1a0db0: 0x11400008  beqz        $t2, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A0DB0u;
    {
        const bool branch_taken_0x1a0db0 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0DB0u;
            // 0x1a0db4: 0xac890018  sw          $t1, 0x18($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0db0) {
            ctx->pc = 0x1A0DD4u;
            goto label_1a0dd4;
        }
    }
    ctx->pc = 0x1A0DB8u;
    // 0x1a0db8: 0xe91021  addu        $v0, $a3, $t1
    ctx->pc = 0x1a0db8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x1a0dbc: 0x2523ffff  addiu       $v1, $t1, -0x1
    ctx->pc = 0x1a0dbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967295));
    // 0x1a0dc0: 0x601827  not         $v1, $v1
    ctx->pc = 0x1a0dc0u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 3) | GPR_U64(ctx, 0)));
    // 0x1a0dc4: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1a0dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1a0dc8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1a0dc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1a0dcc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A0DCCu;
    {
        const bool branch_taken_0x1a0dcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0DCCu;
            // 0x1a0dd0: 0xac820014  sw          $v0, 0x14($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0dcc) {
            ctx->pc = 0x1A0DE8u;
            goto label_1a0de8;
        }
    }
    ctx->pc = 0x1A0DD4u;
label_1a0dd4:
    // 0x1a0dd4: 0x2523ffff  addiu       $v1, $t1, -0x1
    ctx->pc = 0x1a0dd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967295));
    // 0x1a0dd8: 0xe81021  addu        $v0, $a3, $t0
    ctx->pc = 0x1a0dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x1a0ddc: 0x601827  not         $v1, $v1
    ctx->pc = 0x1a0ddcu;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 3) | GPR_U64(ctx, 0)));
    // 0x1a0de0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1a0de0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1a0de4: 0xac820014  sw          $v0, 0x14($a0)
    ctx->pc = 0x1a0de4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
label_1a0de8:
    // 0x1a0de8: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x1a0de8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1a0dec: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1a0decu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1a0df0: 0x63100  sll         $a2, $a2, 4
    ctx->pc = 0x1a0df0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x1a0df4: 0xac830010  sw          $v1, 0x10($a0)
    ctx->pc = 0x1a0df4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 3));
    // 0x1a0df8: 0xac80001c  sw          $zero, 0x1C($a0)
    ctx->pc = 0x1a0df8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
    // 0x1a0dfc: 0xac800020  sw          $zero, 0x20($a0)
    ctx->pc = 0x1a0dfcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 0));
    // 0x1a0e00: 0xac820024  sw          $v0, 0x24($a0)
    ctx->pc = 0x1a0e00u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 2));
    // 0x1a0e04: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1a0e04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0e08: 0x80696c4  j           func_1A5B10
    ctx->pc = 0x1A0E08u;
    ctx->pc = 0x1A0E0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0E08u;
            // 0x1a0e0c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5B10u;
    if (runtime->hasFunction(0x1A5B10u)) {
        auto targetFn = runtime->lookupFunction(0x1A5B10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A5B10_0x1a5b10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1A0E10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
