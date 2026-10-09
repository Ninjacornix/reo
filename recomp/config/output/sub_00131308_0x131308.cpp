#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131308
// Address: 0x131308 - 0x13131c
void sub_00131308_0x131308(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131308_0x131308");
#endif

    ctx->pc = 0x131308u;

    // 0x131308: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131308u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13130c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13130cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x131310: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x131310u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131314: 0x804ebba  j           func_13AEE8
    ctx->pc = 0x131314u;
    ctx->pc = 0x131318u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131314u;
            // 0x131318: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AEE8u;
    if (runtime->hasFunction(0x13AEE8u)) {
        auto targetFn = runtime->lookupFunction(0x13AEE8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013AEE8_0x13aee8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13131Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
