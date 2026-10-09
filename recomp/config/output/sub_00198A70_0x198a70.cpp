#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00198A70
// Address: 0x198a70 - 0x198a90
void sub_00198A70_0x198a70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00198A70_0x198a70");
#endif

    ctx->pc = 0x198a70u;

    // 0x198a70: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x198a70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x198a74: 0x8422fd5c  lh          $v0, -0x2A4($at)
    ctx->pc = 0x198a74u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294966620)));
    // 0x198a78: 0x821023  subu        $v0, $a0, $v0
    ctx->pc = 0x198a78u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x198a7c: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x198a7cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x198a80: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x198a80u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x198a84: 0x3e00008  jr          $ra
    ctx->pc = 0x198A84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x198A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198A84u;
            // 0x198a88: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x198A8Cu;
    // 0x198a8c: 0x0  nop
    ctx->pc = 0x198a8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
