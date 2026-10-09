#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C798
// Address: 0x11c798 - 0x11c7b8
void sub_0011C798_0x11c798(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C798_0x11c798");
#endif

    switch (ctx->pc) {
        case 0x11c7a8u: goto label_11c7a8;
        default: break;
    }

    ctx->pc = 0x11c798u;

    // 0x11c798: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11c798u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11c79c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11c79cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11c7a0: 0xc047154  jal         func_11C550
    ctx->pc = 0x11C7A0u;
    SET_GPR_U32(ctx, 31, 0x11C7A8u);
    ctx->pc = 0x11C7A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C7A0u;
            // 0x11c7a4: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C550u;
    if (runtime->hasFunction(0x11C550u)) {
        auto targetFn = runtime->lookupFunction(0x11C550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C7A8u; }
        if (ctx->pc != 0x11C7A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C550_0x11c550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C7A8u; }
        if (ctx->pc != 0x11C7A8u) { return; }
    }
    ctx->pc = 0x11C7A8u;
label_11c7a8:
    // 0x11c7a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11c7a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11c7ac: 0x3e00008  jr          $ra
    ctx->pc = 0x11C7ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C7B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C7ACu;
            // 0x11c7b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C7A8u: goto label_11c7a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C7B4u;
    // 0x11c7b4: 0x0  nop
    ctx->pc = 0x11c7b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
