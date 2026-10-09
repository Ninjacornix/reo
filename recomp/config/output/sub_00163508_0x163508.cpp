#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163508
// Address: 0x163508 - 0x163528
void sub_00163508_0x163508(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163508_0x163508");
#endif

    ctx->pc = 0x163508u;

    // 0x163508: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163508u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16350c: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x16350cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x163510: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x163514: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x163514u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163518: 0x8c450740  lw          $a1, 0x740($v0)
    ctx->pc = 0x163518u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1856)));
    // 0x16351c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16351cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163520: 0x80506f8  j           func_141BE0
    ctx->pc = 0x163520u;
    ctx->pc = 0x163524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163520u;
            // 0x163524: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141BE0u;
    if (runtime->hasFunction(0x141BE0u)) {
        auto targetFn = runtime->lookupFunction(0x141BE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141BE0_0x141be0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x163528u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
