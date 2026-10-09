#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D96B0
// Address: 0x1d96b0 - 0x1d96e0
void sub_001D96B0_0x1d96b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D96B0_0x1d96b0");
#endif

    switch (ctx->pc) {
        case 0x1d96c4u: goto label_1d96c4;
        default: break;
    }

    ctx->pc = 0x1d96b0u;

    // 0x1d96b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d96b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d96b4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d96b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d96b8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d96b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d96bc: 0xc07651c  jal         func_1D9470
    ctx->pc = 0x1D96BCu;
    SET_GPR_U32(ctx, 31, 0x1D96C4u);
    ctx->pc = 0x1D96C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D96BCu;
            // 0x1d96c0: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9470u;
    if (runtime->hasFunction(0x1D9470u)) {
        auto targetFn = runtime->lookupFunction(0x1D9470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D96C4u; }
        if (ctx->pc != 0x1D96C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9470_0x1d9470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D96C4u; }
        if (ctx->pc != 0x1D96C4u) { return; }
    }
    ctx->pc = 0x1D96C4u;
label_1d96c4:
    // 0x1d96c4: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1d96c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1d96c8: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1d96c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d96cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d96ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d96d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d96d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d96d4: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1d96d4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d96d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D96D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D96DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D96D8u;
            // 0x1d96dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D96C4u: goto label_1d96c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D96E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
