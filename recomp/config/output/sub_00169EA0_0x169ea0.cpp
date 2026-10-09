#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169EA0
// Address: 0x169ea0 - 0x169eb8
void sub_00169EA0_0x169ea0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169EA0_0x169ea0");
#endif

    ctx->pc = 0x169ea0u;

    // 0x169ea0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x169ea0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x169ea4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x169ea4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x169ea8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x169ea8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169eac: 0x805a3d2  j           func_168F48
    ctx->pc = 0x169EACu;
    ctx->pc = 0x169EB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169EACu;
            // 0x169eb0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168F48u;
    if (runtime->hasFunction(0x168F48u)) {
        auto targetFn = runtime->lookupFunction(0x168F48u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00168F48_0x168f48(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x169EB4u;
    // 0x169eb4: 0x0  nop
    ctx->pc = 0x169eb4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
