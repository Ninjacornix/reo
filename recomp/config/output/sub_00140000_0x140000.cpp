#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140000
// Address: 0x140000 - 0x14001c
void sub_00140000_0x140000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140000_0x140000");
#endif

    ctx->pc = 0x140000u;

    // 0x140000: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140004: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x140004u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x140008: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x140008u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x14000c: 0x2484da88  addiu       $a0, $a0, -0x2578
    ctx->pc = 0x14000cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957704));
    // 0x140010: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x140010u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140014: 0x804fca2  j           func_13F288
    ctx->pc = 0x140014u;
    ctx->pc = 0x140018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140014u;
            // 0x140018: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F288u;
    if (runtime->hasFunction(0x13F288u)) {
        auto targetFn = runtime->lookupFunction(0x13F288u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F288_0x13f288(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x14001Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
