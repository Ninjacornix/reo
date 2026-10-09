#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187490
// Address: 0x187490 - 0x1874a8
void sub_00187490_0x187490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187490_0x187490");
#endif

    ctx->pc = 0x187490u;

    // 0x187490: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x187490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x187494: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x187494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x187498: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x187498u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18749c: 0x8061bda  j           func_186F68
    ctx->pc = 0x18749Cu;
    ctx->pc = 0x1874A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18749Cu;
            // 0x1874a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186F68u;
    if (runtime->hasFunction(0x186F68u)) {
        auto targetFn = runtime->lookupFunction(0x186F68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00186F68_0x186f68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1874A4u;
    // 0x1874a4: 0x0  nop
    ctx->pc = 0x1874a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
