#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A0D10
// Address: 0x1a0d10 - 0x1a0d40
void sub_001A0D10_0x1a0d10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A0D10_0x1a0d10");
#endif

    ctx->pc = 0x1a0d10u;

    // 0x1a0d10: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1a0d10u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0d14: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1a0d14u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0d18: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x1a0d18u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0d1c: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a0d1cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a0d20: 0x3c05002a  lui         $a1, 0x2A
    ctx->pc = 0x1a0d20u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)42 << 16));
    // 0x1a0d24: 0x2484fef0  addiu       $a0, $a0, -0x110
    ctx->pc = 0x1a0d24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967024));
    // 0x1a0d28: 0x24a5fef0  addiu       $a1, $a1, -0x110
    ctx->pc = 0x1a0d28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967024));
    // 0x1a0d2c: 0x24061000  addiu       $a2, $zero, 0x1000
    ctx->pc = 0x1a0d2cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1a0d30: 0x8068368  j           func_1A0DA0
    ctx->pc = 0x1A0D30u;
    ctx->pc = 0x1A0D34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0D30u;
            // 0x1a0d34: 0x240a0001  addiu       $t2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0DA0u;
    if (runtime->hasFunction(0x1A0DA0u)) {
        auto targetFn = runtime->lookupFunction(0x1A0DA0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A0DA0_0x1a0da0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1A0D38u;
    // 0x1a0d38: 0x0  nop
    ctx->pc = 0x1a0d38u;
    // NOP
    // 0x1a0d3c: 0x0  nop
    ctx->pc = 0x1a0d3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
