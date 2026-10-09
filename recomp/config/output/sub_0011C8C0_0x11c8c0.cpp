#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C8C0
// Address: 0x11c8c0 - 0x11c8dc
void sub_0011C8C0_0x11c8c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C8C0_0x11c8c0");
#endif

    switch (ctx->pc) {
        case 0x11c8d0u: goto label_11c8d0;
        default: break;
    }

    ctx->pc = 0x11c8c0u;

    // 0x11c8c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11c8c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11c8c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11c8c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11c8c8: 0xc0471ee  jal         func_11C7B8
    ctx->pc = 0x11C8C8u;
    SET_GPR_U32(ctx, 31, 0x11C8D0u);
    ctx->pc = 0x11C8CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C8C8u;
            // 0x11c8cc: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C7B8u;
    if (runtime->hasFunction(0x11C7B8u)) {
        auto targetFn = runtime->lookupFunction(0x11C7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C8D0u; }
        if (ctx->pc != 0x11C8D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C7B8_0x11c7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C8D0u; }
        if (ctx->pc != 0x11C8D0u) { return; }
    }
    ctx->pc = 0x11C8D0u;
label_11c8d0:
    // 0x11c8d0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11c8d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11c8d4: 0x3e00008  jr          $ra
    ctx->pc = 0x11C8D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C8D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C8D4u;
            // 0x11c8d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C8D0u: goto label_11c8d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C8DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
