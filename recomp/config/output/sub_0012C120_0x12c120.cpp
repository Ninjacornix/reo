#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C120
// Address: 0x12c120 - 0x12c134
void sub_0012C120_0x12c120(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C120_0x12c120");
#endif

    ctx->pc = 0x12c120u;

    // 0x12c120: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c120u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c124: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c128: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c128u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c12c: 0x804ae00  j           func_12B800
    ctx->pc = 0x12C12Cu;
    ctx->pc = 0x12C130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C12Cu;
            // 0x12c130: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B800u;
    if (runtime->hasFunction(0x12B800u)) {
        auto targetFn = runtime->lookupFunction(0x12B800u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012B800_0x12b800(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C134u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
