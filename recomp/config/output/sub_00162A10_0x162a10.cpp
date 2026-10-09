#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162A10
// Address: 0x162a10 - 0x162a70
void sub_00162A10_0x162a10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162A10_0x162a10");
#endif

    ctx->pc = 0x162a10u;

    // 0x162a10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162a10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162a14: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162a14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162a18: 0x8c84004c  lw          $a0, 0x4C($a0)
    ctx->pc = 0x162a18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x162a1c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162a1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162a20: 0x804f440  j           func_13D100
    ctx->pc = 0x162A20u;
    ctx->pc = 0x162A24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162A20u;
            // 0x162a24: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D100u;
    if (runtime->hasFunction(0x13D100u)) {
        auto targetFn = runtime->lookupFunction(0x13D100u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D100_0x13d100(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162A28u;
    // 0x162a28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162a28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162a2c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162a30: 0x8c84004c  lw          $a0, 0x4C($a0)
    ctx->pc = 0x162a30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x162a34: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162a34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162a38: 0x804f464  j           func_13D190
    ctx->pc = 0x162A38u;
    ctx->pc = 0x162A3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162A38u;
            // 0x162a3c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D190u;
    if (runtime->hasFunction(0x13D190u)) {
        auto targetFn = runtime->lookupFunction(0x13D190u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D190_0x13d190(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162A40u;
    // 0x162a40: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162a40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162a44: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162a48: 0x8c84004c  lw          $a0, 0x4C($a0)
    ctx->pc = 0x162a48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x162a4c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162a4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162a50: 0x804f48a  j           func_13D228
    ctx->pc = 0x162A50u;
    ctx->pc = 0x162A54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162A50u;
            // 0x162a54: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D228u;
    if (runtime->hasFunction(0x13D228u)) {
        auto targetFn = runtime->lookupFunction(0x13D228u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D228_0x13d228(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162A58u;
    // 0x162a58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162a58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162a5c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162a5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162a60: 0x8c84004c  lw          $a0, 0x4C($a0)
    ctx->pc = 0x162a60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x162a64: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162a64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162a68: 0x804f4b0  j           func_13D2C0
    ctx->pc = 0x162A68u;
    ctx->pc = 0x162A6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162A68u;
            // 0x162a6c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D2C0u;
    if (runtime->hasFunction(0x13D2C0u)) {
        auto targetFn = runtime->lookupFunction(0x13D2C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D2C0_0x13d2c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162A70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
