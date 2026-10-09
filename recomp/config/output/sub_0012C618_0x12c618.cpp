#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C618
// Address: 0x12c618 - 0x12c630
void sub_0012C618_0x12c618(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C618_0x12c618");
#endif

    ctx->pc = 0x12c618u;

    // 0x12c618: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c618u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c61c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c61cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c620: 0x8c84000c  lw          $a0, 0xC($a0)
    ctx->pc = 0x12c620u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x12c624: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c624u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c628: 0x804f9a2  j           func_13E688
    ctx->pc = 0x12C628u;
    ctx->pc = 0x12C62Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C628u;
            // 0x12c62c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13E688u;
    if (runtime->hasFunction(0x13E688u)) {
        auto targetFn = runtime->lookupFunction(0x13E688u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013E688_0x13e688(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C630u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
