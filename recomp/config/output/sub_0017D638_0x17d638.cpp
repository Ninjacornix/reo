#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D638
// Address: 0x17d638 - 0x17d650
void sub_0017D638_0x17d638(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D638_0x17d638");
#endif

    ctx->pc = 0x17d638u;

    // 0x17d638: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d638u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d63c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d63cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d640: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d640u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d644: 0x805f8ee  j           func_17E3B8
    ctx->pc = 0x17D644u;
    ctx->pc = 0x17D648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D644u;
            // 0x17d648: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E3B8u;
    if (runtime->hasFunction(0x17E3B8u)) {
        auto targetFn = runtime->lookupFunction(0x17E3B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E3B8_0x17e3b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D64Cu;
    // 0x17d64c: 0x0  nop
    ctx->pc = 0x17d64cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
