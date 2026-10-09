#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001264F8
// Address: 0x1264f8 - 0x126510
void sub_001264F8_0x1264f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001264F8_0x1264f8");
#endif

    ctx->pc = 0x1264f8u;

    // 0x1264f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1264f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1264fc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1264fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x126500: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x126500u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x126504: 0x80505ba  j           func_1416E8
    ctx->pc = 0x126504u;
    ctx->pc = 0x126508u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x126504u;
            // 0x126508: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001416E8_0x1416e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12650Cu;
    // 0x12650c: 0x0  nop
    ctx->pc = 0x12650cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
