#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A728
// Address: 0x17a728 - 0x17a750
void sub_0017A728_0x17a728(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A728_0x17a728");
#endif

    ctx->pc = 0x17a728u;

    // 0x17a728: 0x24820008  addiu       $v0, $a0, 0x8
    ctx->pc = 0x17a728u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x17a72c: 0x2406001f  addiu       $a2, $zero, 0x1F
    ctx->pc = 0x17a72cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x17a730: 0x24030064  addiu       $v1, $zero, 0x64
    ctx->pc = 0x17a730u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x17a734: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x17a734u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a738: 0xac430008  sw          $v1, 0x8($v0)
    ctx->pc = 0x17a738u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x17a73c: 0xac460004  sw          $a2, 0x4($v0)
    ctx->pc = 0x17a73cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 6));
    // 0x17a740: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x17a740u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x17a744: 0x3e00008  jr          $ra
    ctx->pc = 0x17A744u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A744u;
            // 0x17a748: 0xac850004  sw          $a1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17A74Cu;
    // 0x17a74c: 0x0  nop
    ctx->pc = 0x17a74cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
