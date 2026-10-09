#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001670C8
// Address: 0x1670c8 - 0x1670e0
void sub_001670C8_0x1670c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001670C8_0x1670c8");
#endif

    ctx->pc = 0x1670c8u;

    // 0x1670c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1670c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1670cc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1670ccu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1670d0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1670d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1670d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1670d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1670d8: 0x8059c3e  j           func_1670F8
    ctx->pc = 0x1670D8u;
    ctx->pc = 0x1670DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1670D8u;
            // 0x1670dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1670F8u;
    if (runtime->hasFunction(0x1670F8u)) {
        auto targetFn = runtime->lookupFunction(0x1670F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001670F8_0x1670f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1670E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
