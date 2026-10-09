#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6B50
// Address: 0x1d6b50 - 0x1d6b80
void sub_001D6B50_0x1d6b50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6B50_0x1d6b50");
#endif

    switch (ctx->pc) {
        case 0x1d6b64u: goto label_1d6b64;
        case 0x1d6b70u: goto label_1d6b70;
        default: break;
    }

    ctx->pc = 0x1d6b50u;

    // 0x1d6b50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d6b50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d6b54: 0x4243c  dsll32      $a0, $a0, 16
    ctx->pc = 0x1d6b54u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1d6b58: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d6b58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d6b5c: 0xc075f30  jal         func_1D7CC0
    ctx->pc = 0x1D6B5Cu;
    SET_GPR_U32(ctx, 31, 0x1D6B64u);
    ctx->pc = 0x1D6B60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6B5Cu;
            // 0x1d6b60: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7CC0u;
    if (runtime->hasFunction(0x1D7CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D7CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6B64u; }
        if (ctx->pc != 0x1D6B64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7CC0_0x1d7cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6B64u; }
        if (ctx->pc != 0x1D6B64u) { return; }
    }
    ctx->pc = 0x1D6B64u;
label_1d6b64:
    // 0x1d6b64: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1d6b64u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6b68: 0xc0759b4  jal         func_1D66D0
    ctx->pc = 0x1D6B68u;
    SET_GPR_U32(ctx, 31, 0x1D6B70u);
    ctx->pc = 0x1D6B6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6B68u;
            // 0x1d6b6c: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D66D0u;
    if (runtime->hasFunction(0x1D66D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D66D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6B70u; }
        if (ctx->pc != 0x1D6B70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D66D0_0x1d66d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6B70u; }
        if (ctx->pc != 0x1D6B70u) { return; }
    }
    ctx->pc = 0x1D6B70u;
label_1d6b70:
    // 0x1d6b70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d6b70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6b74: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6B74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6B74u;
            // 0x1d6b78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6B64u: goto label_1d6b64;
            case 0x1D6B70u: goto label_1d6b70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6B7Cu;
    // 0x1d6b7c: 0x0  nop
    ctx->pc = 0x1d6b7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
