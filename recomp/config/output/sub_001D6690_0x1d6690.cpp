#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6690
// Address: 0x1d6690 - 0x1d66d0
void sub_001D6690_0x1d6690(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6690_0x1d6690");
#endif

    switch (ctx->pc) {
        case 0x1d66bcu: goto label_1d66bc;
        default: break;
    }

    ctx->pc = 0x1d6690u;

    // 0x1d6690: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d6690u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d6694: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d6694u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d6698: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d6698u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d669c: 0xa02045d8  sb          $zero, 0x45D8($at)
    ctx->pc = 0x1d669cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17880), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d66a0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d66a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d66a4: 0xac2045e0  sw          $zero, 0x45E0($at)
    ctx->pc = 0x1d66a4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17888), GPR_U32(ctx, 0));
    // 0x1d66a8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d66a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d66ac: 0xac2045e8  sw          $zero, 0x45E8($at)
    ctx->pc = 0x1d66acu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17896), GPR_U32(ctx, 0));
    // 0x1d66b0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d66b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d66b4: 0xc075e04  jal         func_1D7810
    ctx->pc = 0x1D66B4u;
    SET_GPR_U32(ctx, 31, 0x1D66BCu);
    ctx->pc = 0x1D66B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D66B4u;
            // 0x1d66b8: 0xac2045f0  sw          $zero, 0x45F0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 17904), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7810u;
    if (runtime->hasFunction(0x1D7810u)) {
        auto targetFn = runtime->lookupFunction(0x1D7810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D66BCu; }
        if (ctx->pc != 0x1D66BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7810_0x1d7810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D66BCu; }
        if (ctx->pc != 0x1D66BCu) { return; }
    }
    ctx->pc = 0x1D66BCu;
label_1d66bc:
    // 0x1d66bc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d66bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d66c0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d66c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d66c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D66C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D66C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D66C4u;
            // 0x1d66c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D66BCu: goto label_1d66bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D66CCu;
    // 0x1d66cc: 0x0  nop
    ctx->pc = 0x1d66ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
