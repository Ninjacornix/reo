#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B820
// Address: 0x15b820 - 0x15b838
void sub_0015B820_0x15b820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B820_0x15b820");
#endif

    ctx->pc = 0x15b820u;

    // 0x15b820: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15b820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15b824: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15b824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15b828: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15b828u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b82c: 0x80540b0  j           func_1502C0
    ctx->pc = 0x15B82Cu;
    ctx->pc = 0x15B830u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B82Cu;
            // 0x15b830: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1502C0u;
    if (runtime->hasFunction(0x1502C0u)) {
        auto targetFn = runtime->lookupFunction(0x1502C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001502C0_0x1502c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15B834u;
    // 0x15b834: 0x0  nop
    ctx->pc = 0x15b834u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
