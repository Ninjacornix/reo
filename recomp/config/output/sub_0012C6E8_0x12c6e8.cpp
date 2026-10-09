#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C6E8
// Address: 0x12c6e8 - 0x12c700
void sub_0012C6E8_0x12c6e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C6E8_0x12c6e8");
#endif

    ctx->pc = 0x12c6e8u;

    // 0x12c6e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c6e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c6ec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c6ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c6f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c6f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c6f4: 0x804faf6  j           func_13EBD8
    ctx->pc = 0x12C6F4u;
    ctx->pc = 0x12C6F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C6F4u;
            // 0x12c6f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EBD8u;
    if (runtime->hasFunction(0x13EBD8u)) {
        auto targetFn = runtime->lookupFunction(0x13EBD8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013EBD8_0x13ebd8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C6FCu;
    // 0x12c6fc: 0x0  nop
    ctx->pc = 0x12c6fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
