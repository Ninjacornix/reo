#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C97D0
// Address: 0x1c97d0 - 0x1c97f0
void sub_001C97D0_0x1c97d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C97D0_0x1c97d0");
#endif

    ctx->pc = 0x1c97d0u;

    // 0x1c97d0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c97d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c97d4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c97d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c97d8: 0x8423d998  lh          $v1, -0x2668($at)
    ctx->pc = 0x1c97d8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294957464)));
    // 0x1c97dc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c97dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c97e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C97E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C97E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C97E0u;
            // 0x1c97e4: 0xa023cc40  sb          $v1, -0x33C0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294954048), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C97E8u;
    // 0x1c97e8: 0x0  nop
    ctx->pc = 0x1c97e8u;
    // NOP
    // 0x1c97ec: 0x0  nop
    ctx->pc = 0x1c97ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
