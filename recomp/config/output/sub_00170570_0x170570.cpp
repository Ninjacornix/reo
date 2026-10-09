#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170570
// Address: 0x170570 - 0x170580
void sub_00170570_0x170570(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170570_0x170570");
#endif

    ctx->pc = 0x170570u;

    // 0x170570: 0x8c831b30  lw          $v1, 0x1B30($a0)
    ctx->pc = 0x170570u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x170574: 0x3e00008  jr          $ra
    ctx->pc = 0x170574u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170574u;
            // 0x170578: 0x8c62007c  lw          $v0, 0x7C($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 124)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17057Cu;
    // 0x17057c: 0x0  nop
    ctx->pc = 0x17057cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
