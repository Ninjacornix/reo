#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D63C
// Address: 0x11d63c - 0x11d660
void sub_0011D63C_0x11d63c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D63C_0x11d63c");
#endif

    switch (ctx->pc) {
        case 0x11d658u: goto label_11d658;
        default: break;
    }

    ctx->pc = 0x11d63cu;

    // 0x11d63c: 0x30a2007c  andi        $v0, $a1, 0x7C
    ctx->pc = 0x11d63cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)124);
    // 0x11d640: 0x3c010021  lui         $at, 0x21
    ctx->pc = 0x11d640u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)33 << 16));
    // 0x11d644: 0x220821  addu        $at, $at, $v0
    ctx->pc = 0x11d644u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x11d648: 0x8c21a140  lw          $at, -0x5EC0($at)
    ctx->pc = 0x11d648u;
    SET_GPR_S32(ctx, 1, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294943040)));
    // 0x11d64c: 0x3c1d0026  lui         $sp, 0x26
    ctx->pc = 0x11d64cu;
    SET_GPR_S32(ctx, 29, (int32_t)((uint32_t)38 << 16));
    // 0x11d650: 0x20f809  jalr        $at
    ctx->pc = 0x11D650u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 1);
        SET_GPR_U32(ctx, 31, 0x11D658u);
        ctx->pc = 0x11D654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D650u;
            // 0x11d654: 0x27bdf6c0  addiu       $sp, $sp, -0x940 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294964928));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x11D658u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D658u: goto label_11d658;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x11D658u; }
            if (ctx->pc != 0x11D658u) { return; }
        }
        }
    }
    ctx->pc = 0x11D658u;
label_11d658:
    // 0x11d658: 0x3ffffcd  break       1023, 1023
    ctx->pc = 0x11d658u;
    runtime->handleBreak(rdram, ctx);
    // 0x11d65c: 0x0  nop
    ctx->pc = 0x11d65cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
