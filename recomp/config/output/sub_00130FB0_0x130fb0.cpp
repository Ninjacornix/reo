#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130FB0
// Address: 0x130fb0 - 0x130fcc
void sub_00130FB0_0x130fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130FB0_0x130fb0");
#endif

    ctx->pc = 0x130fb0u;

    // 0x130fb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130fb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130fb4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x130fb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x130fb8: 0xac85000c  sw          $a1, 0xC($a0)
    ctx->pc = 0x130fb8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 5));
    // 0x130fbc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x130fbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130fc0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x130fc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130fc4: 0x804c170  j           func_1305C0
    ctx->pc = 0x130FC4u;
    ctx->pc = 0x130FC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130FC4u;
            // 0x130fc8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305C0u;
    if (runtime->hasFunction(0x1305C0u)) {
        auto targetFn = runtime->lookupFunction(0x1305C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001305C0_0x1305c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x130FCCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
