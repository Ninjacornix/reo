#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013EC60
// Address: 0x13ec60 - 0x13ec7c
void sub_0013EC60_0x13ec60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013EC60_0x13ec60");
#endif

    ctx->pc = 0x13ec60u;

    // 0x13ec60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ec60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ec64: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13ec64u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13ec68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13ec68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13ec6c: 0x2484d848  addiu       $a0, $a0, -0x27B8
    ctx->pc = 0x13ec6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957128));
    // 0x13ec70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13ec70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ec74: 0x8045a12  j           func_116848
    ctx->pc = 0x13EC74u;
    ctx->pc = 0x13EC78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EC74u;
            // 0x13ec78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13EC7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
