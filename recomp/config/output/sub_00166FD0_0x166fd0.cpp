#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166FD0
// Address: 0x166fd0 - 0x166fe8
void sub_00166FD0_0x166fd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166FD0_0x166fd0");
#endif

    ctx->pc = 0x166fd0u;

    // 0x166fd0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166fd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x166fd4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x166fd4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166fd8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x166fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x166fdc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x166fdcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166fe0: 0x8059c00  j           func_167000
    ctx->pc = 0x166FE0u;
    ctx->pc = 0x166FE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166FE0u;
            // 0x166fe4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167000u;
    if (runtime->hasFunction(0x167000u)) {
        auto targetFn = runtime->lookupFunction(0x167000u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00167000_0x167000(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x166FE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
