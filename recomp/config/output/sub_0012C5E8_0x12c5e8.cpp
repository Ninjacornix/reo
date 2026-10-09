#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C5E8
// Address: 0x12c5e8 - 0x12c5fc
void sub_0012C5E8_0x12c5e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C5E8_0x12c5e8");
#endif

    ctx->pc = 0x12c5e8u;

    // 0x12c5e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c5e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c5ec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c5ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c5f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c5f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c5f4: 0x804f97a  j           func_13E5E8
    ctx->pc = 0x12C5F4u;
    ctx->pc = 0x12C5F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C5F4u;
            // 0x12c5f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13E5E8u;
    if (runtime->hasFunction(0x13E5E8u)) {
        auto targetFn = runtime->lookupFunction(0x13E5E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013E5E8_0x13e5e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C5FCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
