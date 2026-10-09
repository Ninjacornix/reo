#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B7B0
// Address: 0x15b7b0 - 0x15b7d8
void sub_0015B7B0_0x15b7b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B7B0_0x15b7b0");
#endif

    ctx->pc = 0x15b7b0u;

    // 0x15b7b0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x15b7b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x15b7b4: 0xac444ccc  sw          $a0, 0x4CCC($v0)
    ctx->pc = 0x15b7b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 19660), GPR_U32(ctx, 4));
    // 0x15b7b8: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x15B7B8u;
    {
        const bool branch_taken_0x15b7b8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x15B7BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B7B8u;
            // 0x15b7bc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b7b8) {
            ctx->pc = 0x15B7CCu;
            goto label_15b7cc;
        }
    }
    ctx->pc = 0x15B7C0u;
    // 0x15b7c0: 0x8c830188  lw          $v1, 0x188($a0)
    ctx->pc = 0x15b7c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 392)));
    // 0x15b7c4: 0x38630002  xori        $v1, $v1, 0x2
    ctx->pc = 0x15b7c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)2);
    // 0x15b7c8: 0x3100a  movz        $v0, $zero, $v1
    ctx->pc = 0x15b7c8u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
label_15b7cc:
    // 0x15b7cc: 0x3e00008  jr          $ra
    ctx->pc = 0x15B7CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B7CCu: goto label_15b7cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B7D4u;
    // 0x15b7d4: 0x0  nop
    ctx->pc = 0x15b7d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
