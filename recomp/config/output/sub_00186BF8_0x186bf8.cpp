#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00186BF8
// Address: 0x186bf8 - 0x186c0c
void sub_00186BF8_0x186bf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00186BF8_0x186bf8");
#endif

    ctx->pc = 0x186bf8u;

    // 0x186bf8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x186bf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x186bfc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x186bfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x186c00: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x186c00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x186c04: 0x8061f4e  j           func_187D38
    ctx->pc = 0x186C04u;
    ctx->pc = 0x186C08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186C04u;
            // 0x186c08: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187D38u;
    if (runtime->hasFunction(0x187D38u)) {
        auto targetFn = runtime->lookupFunction(0x187D38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00187D38_0x187d38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x186C0Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
