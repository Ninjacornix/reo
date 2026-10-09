#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161670
// Address: 0x161670 - 0x161684
void sub_00161670_0x161670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161670_0x161670");
#endif

    ctx->pc = 0x161670u;

    // 0x161670: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161670u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x161674: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x161674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x161678: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x161678u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16167c: 0x8058576  j           func_1615D8
    ctx->pc = 0x16167Cu;
    ctx->pc = 0x161680u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16167Cu;
            // 0x161680: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1615D8u;
    if (runtime->hasFunction(0x1615D8u)) {
        auto targetFn = runtime->lookupFunction(0x1615D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001615D8_0x1615d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161684u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
