#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001312D8
// Address: 0x1312d8 - 0x1312ec
void sub_001312D8_0x1312d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001312D8_0x1312d8");
#endif

    ctx->pc = 0x1312d8u;

    // 0x1312d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1312d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1312dc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1312dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1312e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1312e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1312e4: 0x804e816  j           func_13A058
    ctx->pc = 0x1312E4u;
    ctx->pc = 0x1312E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1312E4u;
            // 0x1312e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A058u;
    if (runtime->hasFunction(0x13A058u)) {
        auto targetFn = runtime->lookupFunction(0x13A058u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013A058_0x13a058(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1312ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
