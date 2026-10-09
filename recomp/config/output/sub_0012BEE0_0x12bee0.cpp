#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012BEE0
// Address: 0x12bee0 - 0x12bef8
void sub_0012BEE0_0x12bee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012BEE0_0x12bee0");
#endif

    ctx->pc = 0x12bee0u;

    // 0x12bee0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12bee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12bee4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12bee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12bee8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12bee8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12beec: 0x804af6e  j           func_12BDB8
    ctx->pc = 0x12BEECu;
    ctx->pc = 0x12BEF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BEECu;
            // 0x12bef0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12BDB8u;
    if (runtime->hasFunction(0x12BDB8u)) {
        auto targetFn = runtime->lookupFunction(0x12BDB8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012BDB8_0x12bdb8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12BEF4u;
    // 0x12bef4: 0x0  nop
    ctx->pc = 0x12bef4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
