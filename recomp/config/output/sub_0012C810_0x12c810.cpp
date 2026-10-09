#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C810
// Address: 0x12c810 - 0x12c828
void sub_0012C810_0x12c810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C810_0x12c810");
#endif

    ctx->pc = 0x12c810u;

    // 0x12c810: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c810u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c814: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c818: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c818u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c81c: 0x804fc16  j           func_13F058
    ctx->pc = 0x12C81Cu;
    ctx->pc = 0x12C820u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C81Cu;
            // 0x12c820: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F058u;
    if (runtime->hasFunction(0x13F058u)) {
        auto targetFn = runtime->lookupFunction(0x13F058u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F058_0x13f058(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C824u;
    // 0x12c824: 0x0  nop
    ctx->pc = 0x12c824u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
