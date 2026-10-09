#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155EA8
// Address: 0x155ea8 - 0x155ebc
void sub_00155EA8_0x155ea8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155EA8_0x155ea8");
#endif

    ctx->pc = 0x155ea8u;

    // 0x155ea8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155ea8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155eac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155eacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155eb0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155eb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155eb4: 0x8041eac  j           func_107AB0
    ctx->pc = 0x155EB4u;
    ctx->pc = 0x155EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155EB4u;
            // 0x155eb8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107AB0_0x107ab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155EBCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
