#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129F88
// Address: 0x129f88 - 0x129f94
void sub_00129F88_0x129f88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129F88_0x129f88");
#endif

    ctx->pc = 0x129f88u;

    // 0x129f88: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x129f88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x129f8c: 0x3e00008  jr          $ra
    ctx->pc = 0x129F8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129F90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129F8Cu;
            // 0x129f90: 0xac44d100  sw          $a0, -0x2F00($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294955264), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x129F94u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
