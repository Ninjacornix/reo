#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001226A8
// Address: 0x1226a8 - 0x1226c0
void sub_001226A8_0x1226a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001226A8_0x1226a8");
#endif

    ctx->pc = 0x1226a8u;

    // 0x1226a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1226a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1226ac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1226acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1226b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1226b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1226b4: 0x8047eee  j           func_11FBB8
    ctx->pc = 0x1226B4u;
    ctx->pc = 0x1226B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1226B4u;
            // 0x1226b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11FBB8u;
    if (runtime->hasFunction(0x11FBB8u)) {
        auto targetFn = runtime->lookupFunction(0x11FBB8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011FBB8_0x11fbb8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1226BCu;
    // 0x1226bc: 0x0  nop
    ctx->pc = 0x1226bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
