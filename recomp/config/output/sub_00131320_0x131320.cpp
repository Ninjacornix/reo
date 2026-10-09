#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131320
// Address: 0x131320 - 0x131338
void sub_00131320_0x131320(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131320_0x131320");
#endif

    ctx->pc = 0x131320u;

    // 0x131320: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131320u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x131324: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x131324u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131328: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x131328u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13132c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13132cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131330: 0x804a034  j           func_1280D0
    ctx->pc = 0x131330u;
    ctx->pc = 0x131334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131330u;
            // 0x131334: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131338u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
