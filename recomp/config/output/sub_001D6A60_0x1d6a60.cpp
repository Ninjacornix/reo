#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6A60
// Address: 0x1d6a60 - 0x1d6a90
void sub_001D6A60_0x1d6a60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6A60_0x1d6a60");
#endif

    switch (ctx->pc) {
        case 0x1d6a74u: goto label_1d6a74;
        case 0x1d6a80u: goto label_1d6a80;
        default: break;
    }

    ctx->pc = 0x1d6a60u;

    // 0x1d6a60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d6a60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d6a64: 0x4243c  dsll32      $a0, $a0, 16
    ctx->pc = 0x1d6a64u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1d6a68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d6a68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d6a6c: 0xc075fd8  jal         func_1D7F60
    ctx->pc = 0x1D6A6Cu;
    SET_GPR_U32(ctx, 31, 0x1D6A74u);
    ctx->pc = 0x1D6A70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6A6Cu;
            // 0x1d6a70: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7F60u;
    if (runtime->hasFunction(0x1D7F60u)) {
        auto targetFn = runtime->lookupFunction(0x1D7F60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6A74u; }
        if (ctx->pc != 0x1D6A74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7F60_0x1d7f60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6A74u; }
        if (ctx->pc != 0x1D6A74u) { return; }
    }
    ctx->pc = 0x1D6A74u;
label_1d6a74:
    // 0x1d6a74: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1d6a74u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6a78: 0xc0759b4  jal         func_1D66D0
    ctx->pc = 0x1D6A78u;
    SET_GPR_U32(ctx, 31, 0x1D6A80u);
    ctx->pc = 0x1D6A7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6A78u;
            // 0x1d6a7c: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D66D0u;
    if (runtime->hasFunction(0x1D66D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D66D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6A80u; }
        if (ctx->pc != 0x1D6A80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D66D0_0x1d66d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6A80u; }
        if (ctx->pc != 0x1D6A80u) { return; }
    }
    ctx->pc = 0x1D6A80u;
label_1d6a80:
    // 0x1d6a80: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d6a80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6a84: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6A84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6A84u;
            // 0x1d6a88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6A74u: goto label_1d6a74;
            case 0x1D6A80u: goto label_1d6a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6A8Cu;
    // 0x1d6a8c: 0x0  nop
    ctx->pc = 0x1d6a8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
