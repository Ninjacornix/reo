#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160B78
// Address: 0x160b78 - 0x160b90
void sub_00160B78_0x160b78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160B78_0x160b78");
#endif

    ctx->pc = 0x160b78u;

    // 0x160b78: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160b78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160b7c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160b7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x160b80: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160b80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160b84: 0x805f45e  j           func_17D178
    ctx->pc = 0x160B84u;
    ctx->pc = 0x160B88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160B84u;
            // 0x160b88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D178u;
    if (runtime->hasFunction(0x17D178u)) {
        auto targetFn = runtime->lookupFunction(0x17D178u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D178_0x17d178(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160B8Cu;
    // 0x160b8c: 0x0  nop
    ctx->pc = 0x160b8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
