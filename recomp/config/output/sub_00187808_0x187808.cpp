#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187808
// Address: 0x187808 - 0x187834
void sub_00187808_0x187808(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187808_0x187808");
#endif

    switch (ctx->pc) {
        case 0x187820u: goto label_187820;
        default: break;
    }

    ctx->pc = 0x187808u;

    // 0x187808: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x187808u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x18780c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x18780cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x187810: 0x8c44b8c4  lw          $a0, -0x473C($v0)
    ctx->pc = 0x187810u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949060)));
    // 0x187814: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x187814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x187818: 0xc045194  jal         func_114650
    ctx->pc = 0x187818u;
    SET_GPR_U32(ctx, 31, 0x187820u);
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187820u; }
        if (ctx->pc != 0x187820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187820u; }
        if (ctx->pc != 0x187820u) { return; }
    }
    ctx->pc = 0x187820u;
label_187820:
    // 0x187820: 0xf  sync
    ctx->pc = 0x187820u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x187824: 0x42000038  ei
    ctx->pc = 0x187824u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x187828: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x187828u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18782c: 0x3e00008  jr          $ra
    ctx->pc = 0x18782Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x187830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18782Cu;
            // 0x187830: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x187820u: goto label_187820;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187834u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
