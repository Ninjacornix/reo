#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D448
// Address: 0x17d448 - 0x17d468
void sub_0017D448_0x17d448(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D448_0x17d448");
#endif

    ctx->pc = 0x17d448u;

    // 0x17d448: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d448u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d44c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d44cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d450: 0x8c840030  lw          $a0, 0x30($a0)
    ctx->pc = 0x17d450u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x17d454: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d454u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d458: 0x805e9fe  j           func_17A7F8
    ctx->pc = 0x17D458u;
    ctx->pc = 0x17D45Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D458u;
            // 0x17d45c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A7F8u;
    if (runtime->hasFunction(0x17A7F8u)) {
        auto targetFn = runtime->lookupFunction(0x17A7F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017A7F8_0x17a7f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D460u;
    // 0x17d460: 0x3e00008  jr          $ra
    ctx->pc = 0x17D460u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D460u;
            // 0x17d464: 0xac850034  sw          $a1, 0x34($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D468u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
