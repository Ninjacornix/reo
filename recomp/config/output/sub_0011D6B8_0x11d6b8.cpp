#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D6B8
// Address: 0x11d6b8 - 0x11d6d0
void sub_0011D6B8_0x11d6b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D6B8_0x11d6b8");
#endif

    ctx->pc = 0x11d6b8u;

    // 0x11d6b8: 0x40026000  mfc0        $v0, Status
    ctx->pc = 0x11d6b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ctx->cop0_status);
    // 0x11d6bc: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x11d6bcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x11d6c0: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x11d6c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x11d6c4: 0x42000038  ei
    ctx->pc = 0x11d6c4u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x11d6c8: 0x3e00008  jr          $ra
    ctx->pc = 0x11D6C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D6CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D6C8u;
            // 0x11d6cc: 0x2102b  sltu        $v0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11D6D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
