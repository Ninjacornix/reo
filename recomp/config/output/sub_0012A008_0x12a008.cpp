#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A008
// Address: 0x12a008 - 0x12a01c
void sub_0012A008_0x12a008(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A008_0x12a008");
#endif

    ctx->pc = 0x12a008u;

    // 0x12a008: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a008u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a00c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12a00cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a010: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a010u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a014: 0x804d7ee  j           func_135FB8
    ctx->pc = 0x12A014u;
    ctx->pc = 0x12A018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A014u;
            // 0x12a018: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135FB8u;
    if (runtime->hasFunction(0x135FB8u)) {
        auto targetFn = runtime->lookupFunction(0x135FB8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135FB8_0x135fb8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A01Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
