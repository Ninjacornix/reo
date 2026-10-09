#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177698
// Address: 0x177698 - 0x1776e0
void sub_00177698_0x177698(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177698_0x177698");
#endif

    switch (ctx->pc) {
        case 0x1776b8u: goto label_1776b8;
        default: break;
    }

    ctx->pc = 0x177698u;

    // 0x177698: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x177698u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x17769c: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x17769cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x1776a0: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x1776a0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x1776a4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1776a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1776a8: 0xac85000c  sw          $a1, 0xC($a0)
    ctx->pc = 0x1776a8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 5));
    // 0x1776ac: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1776acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1776b0: 0xac820010  sw          $v0, 0x10($a0)
    ctx->pc = 0x1776b0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 2));
    // 0x1776b4: 0x2482001c  addiu       $v0, $a0, 0x1C
    ctx->pc = 0x1776b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 28));
label_1776b8:
    // 0x1776b8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1776b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1776bc: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x1776bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
    // 0x1776c0: 0x0  nop
    ctx->pc = 0x1776c0u;
    // NOP
    // 0x1776c4: 0x0  nop
    ctx->pc = 0x1776c4u;
    // NOP
    // 0x1776c8: 0x0  nop
    ctx->pc = 0x1776c8u;
    // NOP
    // 0x1776cc: 0x461fffa  bgez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1776CCu;
    {
        const bool branch_taken_0x1776cc = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1776D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1776CCu;
            // 0x1776d0: 0x2442fffc  addiu       $v0, $v0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1776cc) {
            ctx->pc = 0x1776B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1776b8;
        }
    }
    ctx->pc = 0x1776D4u;
    // 0x1776d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1776d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1776d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1776D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1776DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1776D8u;
            // 0x1776dc: 0xac820020  sw          $v0, 0x20($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1776B8u: goto label_1776b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1776E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
