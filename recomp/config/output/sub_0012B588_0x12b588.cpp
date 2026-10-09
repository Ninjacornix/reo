#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B588
// Address: 0x12b588 - 0x12b59c
void sub_0012B588_0x12b588(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B588_0x12b588");
#endif

    ctx->pc = 0x12b588u;

    // 0x12b588: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12b588u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12b58c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12b58cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12b590: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12b590u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b594: 0x8050802  j           func_142008
    ctx->pc = 0x12B594u;
    ctx->pc = 0x12B598u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B594u;
            // 0x12b598: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142008u;
    if (runtime->hasFunction(0x142008u)) {
        auto targetFn = runtime->lookupFunction(0x142008u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00142008_0x142008(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12B59Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
