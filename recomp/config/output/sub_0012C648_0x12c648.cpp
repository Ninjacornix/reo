#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C648
// Address: 0x12c648 - 0x12c660
void sub_0012C648_0x12c648(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C648_0x12c648");
#endif

    ctx->pc = 0x12c648u;

    // 0x12c648: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c648u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c64c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c64cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c650: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c650u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c654: 0x804f9b0  j           func_13E6C0
    ctx->pc = 0x12C654u;
    ctx->pc = 0x12C658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C654u;
            // 0x12c658: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13E6C0u;
    if (runtime->hasFunction(0x13E6C0u)) {
        auto targetFn = runtime->lookupFunction(0x13E6C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013E6C0_0x13e6c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C65Cu;
    // 0x12c65c: 0x0  nop
    ctx->pc = 0x12c65cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
