#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001699B8
// Address: 0x1699b8 - 0x1699f0
void sub_001699B8_0x1699b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001699B8_0x1699b8");
#endif

    ctx->pc = 0x1699b8u;

    // 0x1699b8: 0x8c830078  lw          $v1, 0x78($a0)
    ctx->pc = 0x1699b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 120)));
    // 0x1699bc: 0x248400d4  addiu       $a0, $a0, 0xD4
    ctx->pc = 0x1699bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 212));
    // 0x1699c0: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1699C0u;
    {
        const bool branch_taken_0x1699c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1699C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1699C0u;
            // 0x1699c4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1699c0) {
            ctx->pc = 0x1699D4u;
            goto label_1699d4;
        }
    }
    ctx->pc = 0x1699C8u;
    // 0x1699c8: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x1699c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1699cc: 0x54600001  bnel        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1699CCu;
    {
        const bool branch_taken_0x1699cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1699cc) {
            ctx->pc = 0x1699D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1699CCu;
            // 0x1699d0: 0x8c820018  lw          $v0, 0x18($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1699D4u;
            goto label_1699d4;
        }
    }
    ctx->pc = 0x1699D4u;
label_1699d4:
    // 0x1699d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1699D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1699D4u: goto label_1699d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1699DCu;
    // 0x1699dc: 0x0  nop
    ctx->pc = 0x1699dcu;
    // NOP
    // 0x1699e0: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1699e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1699e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1699E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1699E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1699E4u;
            // 0x1699e8: 0x24420790  addiu       $v0, $v0, 0x790 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1936));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1699D4u: goto label_1699d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1699ECu;
    // 0x1699ec: 0x0  nop
    ctx->pc = 0x1699ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
