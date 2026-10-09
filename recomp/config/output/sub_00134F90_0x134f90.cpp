#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134F90
// Address: 0x134f90 - 0x134f98
void sub_00134F90_0x134f90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134F90_0x134f90");
#endif

    ctx->pc = 0x134f90u;

    // 0x134f90: 0x3e00008  jr          $ra
    ctx->pc = 0x134F90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134F90u;
            // 0x134f94: 0xac850008  sw          $a1, 0x8($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x134F98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
