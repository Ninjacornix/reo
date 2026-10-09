#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013AEE8
// Address: 0x13aee8 - 0x13aefc
void sub_0013AEE8_0x13aee8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013AEE8_0x13aee8");
#endif

    ctx->pc = 0x13aee8u;

    // 0x13aee8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13aee8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13aeec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13aeecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13aef0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13aef0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13aef4: 0x804e0d8  j           func_138360
    ctx->pc = 0x13AEF4u;
    ctx->pc = 0x13AEF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AEF4u;
            // 0x13aef8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138360u;
    if (runtime->hasFunction(0x138360u)) {
        auto targetFn = runtime->lookupFunction(0x138360u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00138360_0x138360(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13AEFCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
