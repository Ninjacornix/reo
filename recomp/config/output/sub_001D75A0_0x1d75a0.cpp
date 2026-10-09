#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D75A0
// Address: 0x1d75a0 - 0x1d75d0
void sub_001D75A0_0x1d75a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D75A0_0x1d75a0");
#endif

    switch (ctx->pc) {
        case 0x1d75b0u: goto label_1d75b0;
        default: break;
    }

    ctx->pc = 0x1d75a0u;

    // 0x1d75a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d75a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d75a4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d75a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d75a8: 0xc07639c  jal         func_1D8E70
    ctx->pc = 0x1D75A8u;
    SET_GPR_U32(ctx, 31, 0x1D75B0u);
    ctx->pc = 0x1D8E70u;
    if (runtime->hasFunction(0x1D8E70u)) {
        auto targetFn = runtime->lookupFunction(0x1D8E70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D75B0u; }
        if (ctx->pc != 0x1D75B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8E70_0x1d8e70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D75B0u; }
        if (ctx->pc != 0x1D75B0u) { return; }
    }
    ctx->pc = 0x1D75B0u;
label_1d75b0:
    // 0x1d75b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d75b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d75b4: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d75b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d75b8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d75b8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d75bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D75BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D75C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D75BCu;
            // 0x1d75c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D75B0u: goto label_1d75b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D75C4u;
    // 0x1d75c4: 0x0  nop
    ctx->pc = 0x1d75c4u;
    // NOP
    // 0x1d75c8: 0x0  nop
    ctx->pc = 0x1d75c8u;
    // NOP
    // 0x1d75cc: 0x0  nop
    ctx->pc = 0x1d75ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
