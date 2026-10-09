#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016D5C8
// Address: 0x16d5c8 - 0x16d5e8
void sub_0016D5C8_0x16d5c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016D5C8_0x16d5c8");
#endif

    ctx->pc = 0x16d5c8u;

    // 0x16d5c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16d5c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16d5cc: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x16d5ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d5d0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16d5d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16d5d4: 0x8c851b38  lw          $a1, 0x1B38($a0)
    ctx->pc = 0x16d5d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6968)));
    // 0x16d5d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16d5d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16d5dc: 0x8059d92  j           func_167648
    ctx->pc = 0x16D5DCu;
    ctx->pc = 0x16D5E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D5DCu;
            // 0x16d5e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167648u;
    if (runtime->hasFunction(0x167648u)) {
        auto targetFn = runtime->lookupFunction(0x167648u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00167648_0x167648(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16D5E4u;
    // 0x16d5e4: 0x0  nop
    ctx->pc = 0x16d5e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
