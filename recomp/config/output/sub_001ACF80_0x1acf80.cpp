#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ACF80
// Address: 0x1acf80 - 0x1acfa0
void sub_001ACF80_0x1acf80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ACF80_0x1acf80");
#endif

    ctx->pc = 0x1acf80u;

    // 0x1acf80: 0x6343c  dsll32      $a2, $a2, 16
    ctx->pc = 0x1acf80u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 16));
    // 0x1acf84: 0x30e700ff  andi        $a3, $a3, 0xFF
    ctx->pc = 0x1acf84u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x1acf88: 0x6343f  dsra32      $a2, $a2, 16
    ctx->pc = 0x1acf88u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
    // 0x1acf8c: 0x8069f3c  j           func_1A7CF0
    ctx->pc = 0x1ACF8Cu;
    ctx->pc = 0x1ACF90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACF8Cu;
            // 0x1acf90: 0x310800ff  andi        $t0, $t0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7CF0u;
    if (runtime->hasFunction(0x1A7CF0u)) {
        auto targetFn = runtime->lookupFunction(0x1A7CF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A7CF0_0x1a7cf0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1ACF94u;
    // 0x1acf94: 0x0  nop
    ctx->pc = 0x1acf94u;
    // NOP
    // 0x1acf98: 0x0  nop
    ctx->pc = 0x1acf98u;
    // NOP
    // 0x1acf9c: 0x0  nop
    ctx->pc = 0x1acf9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
