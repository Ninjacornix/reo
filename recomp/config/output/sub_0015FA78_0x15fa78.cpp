#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FA78
// Address: 0x15fa78 - 0x15fa90
void sub_0015FA78_0x15fa78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FA78_0x15fa78");
#endif

    ctx->pc = 0x15fa78u;

    // 0x15fa78: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15fa78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15fa7c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15fa7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15fa80: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15fa80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fa84: 0x8057dfc  j           func_15F7F0
    ctx->pc = 0x15FA84u;
    ctx->pc = 0x15FA88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FA84u;
            // 0x15fa88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F7F0u;
    if (runtime->hasFunction(0x15F7F0u)) {
        auto targetFn = runtime->lookupFunction(0x15F7F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015F7F0_0x15f7f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FA8Cu;
    // 0x15fa8c: 0x0  nop
    ctx->pc = 0x15fa8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
