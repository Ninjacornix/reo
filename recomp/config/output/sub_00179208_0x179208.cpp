#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179208
// Address: 0x179208 - 0x179220
void sub_00179208_0x179208(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179208_0x179208");
#endif

    ctx->pc = 0x179208u;

    // 0x179208: 0xac80000c  sw          $zero, 0xC($a0)
    ctx->pc = 0x179208u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x17920c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x17920cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x179210: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x179210u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x179214: 0x3e00008  jr          $ra
    ctx->pc = 0x179214u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179214u;
            // 0x179218: 0xac800008  sw          $zero, 0x8($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17921Cu;
    // 0x17921c: 0x0  nop
    ctx->pc = 0x17921cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
