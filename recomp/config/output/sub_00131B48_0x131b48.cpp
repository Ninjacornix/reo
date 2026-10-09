#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131B48
// Address: 0x131b48 - 0x131b5c
void sub_00131B48_0x131b48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131B48_0x131b48");
#endif

    ctx->pc = 0x131b48u;

    // 0x131b48: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131b48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x131b4c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x131b4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x131b50: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x131b50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131b54: 0x804c6ba  j           func_131AE8
    ctx->pc = 0x131B54u;
    ctx->pc = 0x131B58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131B54u;
            // 0x131b58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131AE8u;
    {
        auto targetFn = runtime->lookupFunction(0x131AE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x131B5Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
