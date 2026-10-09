#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C12A0
// Address: 0x1c12a0 - 0x1c12c0
void sub_001C12A0_0x1c12a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C12A0_0x1c12a0");
#endif

    ctx->pc = 0x1c12a0u;

    // 0x1c12a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c12a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c12a4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c12a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c12a8: 0x821804  sllv        $v1, $v0, $a0
    ctx->pc = 0x1c12a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 4) & 0x1F));
    // 0x1c12ac: 0x8c226c90  lw          $v0, 0x6C90($at)
    ctx->pc = 0x1c12acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27792)));
    // 0x1c12b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C12B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C12B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C12B0u;
            // 0x1c12b4: 0x431024  and         $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C12B8u;
    // 0x1c12b8: 0x0  nop
    ctx->pc = 0x1c12b8u;
    // NOP
    // 0x1c12bc: 0x0  nop
    ctx->pc = 0x1c12bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
