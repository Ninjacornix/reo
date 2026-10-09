#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168F28
// Address: 0x168f28 - 0x168f48
void sub_00168F28_0x168f28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168F28_0x168f28");
#endif

    ctx->pc = 0x168f28u;

    // 0x168f28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x168f28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x168f2c: 0x3c050027  lui         $a1, 0x27
    ctx->pc = 0x168f2cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
    // 0x168f30: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x168f30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x168f34: 0x24040020  addiu       $a0, $zero, 0x20
    ctx->pc = 0x168f34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x168f38: 0x24a51808  addiu       $a1, $a1, 0x1808
    ctx->pc = 0x168f38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6152));
    // 0x168f3c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x168f3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x168f40: 0x805e406  j           func_179018
    ctx->pc = 0x168F40u;
    ctx->pc = 0x168F44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168F40u;
            // 0x168f44: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179018u;
    if (runtime->hasFunction(0x179018u)) {
        auto targetFn = runtime->lookupFunction(0x179018u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00179018_0x179018(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x168F48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
