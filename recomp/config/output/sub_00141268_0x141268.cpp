#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141268
// Address: 0x141268 - 0x14127c
void sub_00141268_0x141268(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141268_0x141268");
#endif

    ctx->pc = 0x141268u;

    // 0x141268: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x141268u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14126c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x14126cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x141270: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x141270u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141274: 0x804e55a  j           func_139568
    ctx->pc = 0x141274u;
    ctx->pc = 0x141278u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141274u;
            // 0x141278: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139568u;
    if (runtime->hasFunction(0x139568u)) {
        auto targetFn = runtime->lookupFunction(0x139568u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00139568_0x139568(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x14127Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
