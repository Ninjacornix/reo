#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001295F8
// Address: 0x1295f8 - 0x12960c
void sub_001295F8_0x1295f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001295F8_0x1295f8");
#endif

    ctx->pc = 0x1295f8u;

    // 0x1295f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1295f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1295fc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1295fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x129600: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x129600u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129604: 0x804a55a  j           func_129568
    ctx->pc = 0x129604u;
    ctx->pc = 0x129608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129604u;
            // 0x129608: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129568u;
    if (runtime->hasFunction(0x129568u)) {
        auto targetFn = runtime->lookupFunction(0x129568u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00129568_0x129568(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12960Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
