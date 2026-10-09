#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0014F6B0
// Address: 0x14f6b0 - 0x14f6d0
void sub_0014F6B0_0x14f6b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0014F6B0_0x14f6b0");
#endif

    ctx->pc = 0x14f6b0u;

    // 0x14f6b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x14f6b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14f6b4: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x14f6b4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x14f6b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x14f6b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x14f6bc: 0x24c6a808  addiu       $a2, $a2, -0x57F8
    ctx->pc = 0x14f6bcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294944776));
    // 0x14f6c0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x14f6c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14f6c4: 0x8053db4  j           func_14F6D0
    ctx->pc = 0x14F6C4u;
    ctx->pc = 0x14F6C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14F6C4u;
            // 0x14f6c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14F6D0u;
    if (runtime->hasFunction(0x14F6D0u)) {
        auto targetFn = runtime->lookupFunction(0x14F6D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0014F6D0_0x14f6d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x14F6CCu;
    // 0x14f6cc: 0x0  nop
    ctx->pc = 0x14f6ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
