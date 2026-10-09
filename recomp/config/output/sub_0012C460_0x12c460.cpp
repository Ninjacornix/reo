#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C460
// Address: 0x12c460 - 0x12c484
void sub_0012C460_0x12c460(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C460_0x12c460");
#endif

    ctx->pc = 0x12c460u;

    // 0x12c460: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c464: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x12c464u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c468: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c468u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c46c: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x12c46cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c470: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x12c470u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x12c474: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12c474u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c478: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c478u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c47c: 0x8050716  j           func_141C58
    ctx->pc = 0x12C47Cu;
    ctx->pc = 0x12C480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C47Cu;
            // 0x12c480: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141C58u;
    if (runtime->hasFunction(0x141C58u)) {
        auto targetFn = runtime->lookupFunction(0x141C58u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141C58_0x141c58(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C484u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
