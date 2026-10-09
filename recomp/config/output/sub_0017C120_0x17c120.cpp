#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C120
// Address: 0x17c120 - 0x17c13c
void sub_0017C120_0x17c120(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C120_0x17c120");
#endif

    ctx->pc = 0x17c120u;

    // 0x17c120: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c120u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c124: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x17c124u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c128: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c128u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c12c: 0x24060018  addiu       $a2, $zero, 0x18
    ctx->pc = 0x17c12cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x17c130: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c130u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c134: 0x805f058  j           func_17C160
    ctx->pc = 0x17C134u;
    ctx->pc = 0x17C138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C134u;
            // 0x17c138: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C160u;
    if (runtime->hasFunction(0x17C160u)) {
        auto targetFn = runtime->lookupFunction(0x17C160u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017C160_0x17c160(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C13Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
