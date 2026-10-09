#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A118
// Address: 0x12a118 - 0x12a130
void sub_0012A118_0x12a118(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A118_0x12a118");
#endif

    ctx->pc = 0x12a118u;

    // 0x12a118: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a118u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a11c: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x12a11cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a120: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12a120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a124: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a124u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a128: 0x804a034  j           func_1280D0
    ctx->pc = 0x12A128u;
    ctx->pc = 0x12A12Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A128u;
            // 0x12a12c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A130u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
