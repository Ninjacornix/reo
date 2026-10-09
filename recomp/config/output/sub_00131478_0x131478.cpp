#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131478
// Address: 0x131478 - 0x13148c
void sub_00131478_0x131478(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131478_0x131478");
#endif

    ctx->pc = 0x131478u;

    // 0x131478: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131478u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13147c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13147cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x131480: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x131480u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131484: 0x804f270  j           func_13C9C0
    ctx->pc = 0x131484u;
    ctx->pc = 0x131488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131484u;
            // 0x131488: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C9C0u;
    if (runtime->hasFunction(0x13C9C0u)) {
        auto targetFn = runtime->lookupFunction(0x13C9C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013C9C0_0x13c9c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13148Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
