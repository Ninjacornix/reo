#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173550
// Address: 0x173550 - 0x173570
void sub_00173550_0x173550(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173550_0x173550");
#endif

    ctx->pc = 0x173550u;

    // 0x173550: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x173550u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x173554: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x173554u;
    {
        const bool branch_taken_0x173554 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x173558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173554u;
            // 0x173558: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173554) {
            ctx->pc = 0x173568u;
            goto label_173568;
        }
    }
    ctx->pc = 0x17355Cu;
    // 0x17355c: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x17355cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x173560: 0x2c632ba0  sltiu       $v1, $v1, 0x2BA0
    ctx->pc = 0x173560u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)11168) ? 1 : 0);
    // 0x173564: 0x3100a  movz        $v0, $zero, $v1
    ctx->pc = 0x173564u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
label_173568:
    // 0x173568: 0x3e00008  jr          $ra
    ctx->pc = 0x173568u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173568u: goto label_173568;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173570u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
