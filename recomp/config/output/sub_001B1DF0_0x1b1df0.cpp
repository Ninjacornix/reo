#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1DF0
// Address: 0x1b1df0 - 0x1b1e20
void sub_001B1DF0_0x1b1df0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1DF0_0x1b1df0");
#endif

    switch (ctx->pc) {
        case 0x1b1e00u: goto label_1b1e00;
        default: break;
    }

    ctx->pc = 0x1b1df0u;

    // 0x1b1df0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b1df0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b1df4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b1df4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b1df8: 0xc06c72c  jal         func_1B1CB0
    ctx->pc = 0x1B1DF8u;
    SET_GPR_U32(ctx, 31, 0x1B1E00u);
    ctx->pc = 0x1B1DFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1DF8u;
            // 0x1b1dfc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1CB0u;
    if (runtime->hasFunction(0x1B1CB0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1CB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1E00u; }
        if (ctx->pc != 0x1B1E00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1CB0_0x1b1cb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1E00u; }
        if (ctx->pc != 0x1B1E00u) { return; }
    }
    ctx->pc = 0x1B1E00u;
label_1b1e00:
    // 0x1b1e00: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b1e00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b1e04: 0xa020ae0f  sb          $zero, -0x51F1($at)
    ctx->pc = 0x1b1e04u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946319), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1e08: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b1e08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1e0c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1E0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1E0Cu;
            // 0x1b1e10: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1E00u: goto label_1b1e00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1E14u;
    // 0x1b1e14: 0x0  nop
    ctx->pc = 0x1b1e14u;
    // NOP
    // 0x1b1e18: 0x0  nop
    ctx->pc = 0x1b1e18u;
    // NOP
    // 0x1b1e1c: 0x0  nop
    ctx->pc = 0x1b1e1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
