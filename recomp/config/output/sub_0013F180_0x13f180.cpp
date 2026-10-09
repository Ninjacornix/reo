#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F180
// Address: 0x13f180 - 0x13f19c
void sub_0013F180_0x13f180(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F180_0x13f180");
#endif

    ctx->pc = 0x13f180u;

    // 0x13f180: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f180u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f184: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f184u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f188: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f188u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f18c: 0x2484d9b0  addiu       $a0, $a0, -0x2650
    ctx->pc = 0x13f18cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957488));
    // 0x13f190: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f190u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f194: 0x8045a12  j           func_116848
    ctx->pc = 0x13F194u;
    ctx->pc = 0x13F198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F194u;
            // 0x13f198: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F19Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
