#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177A90
// Address: 0x177a90 - 0x177ab0
void sub_00177A90_0x177a90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177A90_0x177a90");
#endif

    ctx->pc = 0x177a90u;

    // 0x177a90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x177a90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x177a94: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x177a94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177a98: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x177a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x177a9c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x177a9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x177aa0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x177aa0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177aa4: 0x805deb4  j           func_177AD0
    ctx->pc = 0x177AA4u;
    ctx->pc = 0x177AA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177AA4u;
            // 0x177aa8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177AD0u;
    if (runtime->hasFunction(0x177AD0u)) {
        auto targetFn = runtime->lookupFunction(0x177AD0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177AD0_0x177ad0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x177AACu;
    // 0x177aac: 0x0  nop
    ctx->pc = 0x177aacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
