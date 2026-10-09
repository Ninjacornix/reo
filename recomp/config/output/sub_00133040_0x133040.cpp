#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133040
// Address: 0x133040 - 0x133054
void sub_00133040_0x133040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133040_0x133040");
#endif

    ctx->pc = 0x133040u;

    // 0x133040: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x133040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x133044: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x133044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x133048: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x133048u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13304c: 0x804a02a  j           func_1280A8
    ctx->pc = 0x13304Cu;
    ctx->pc = 0x133050u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13304Cu;
            // 0x133050: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280A8u;
    if (runtime->hasFunction(0x1280A8u)) {
        auto targetFn = runtime->lookupFunction(0x1280A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280A8_0x1280a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133054u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
