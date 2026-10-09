#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169EC8
// Address: 0x169ec8 - 0x169ee0
void sub_00169EC8_0x169ec8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169EC8_0x169ec8");
#endif

    ctx->pc = 0x169ec8u;

    // 0x169ec8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x169ec8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x169ecc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x169eccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x169ed0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x169ed0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169ed4: 0x804af5e  j           func_12BD78
    ctx->pc = 0x169ED4u;
    ctx->pc = 0x169ED8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169ED4u;
            // 0x169ed8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12BD78u;
    if (runtime->hasFunction(0x12BD78u)) {
        auto targetFn = runtime->lookupFunction(0x12BD78u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012BD78_0x12bd78(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x169EDCu;
    // 0x169edc: 0x0  nop
    ctx->pc = 0x169edcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
