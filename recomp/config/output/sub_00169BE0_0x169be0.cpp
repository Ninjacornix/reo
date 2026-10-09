#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169BE0
// Address: 0x169be0 - 0x169bf8
void sub_00169BE0_0x169be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169BE0_0x169be0");
#endif

    ctx->pc = 0x169be0u;

    // 0x169be0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x169be0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x169be4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x169be4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x169be8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x169be8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169bec: 0x805a6fe  j           func_169BF8
    ctx->pc = 0x169BECu;
    ctx->pc = 0x169BF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169BECu;
            // 0x169bf0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169BF8u;
    if (runtime->hasFunction(0x169BF8u)) {
        auto targetFn = runtime->lookupFunction(0x169BF8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169BF8_0x169bf8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x169BF4u;
    // 0x169bf4: 0x0  nop
    ctx->pc = 0x169bf4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
