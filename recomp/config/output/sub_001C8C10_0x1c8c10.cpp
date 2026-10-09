#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8C10
// Address: 0x1c8c10 - 0x1c8c20
void sub_001C8C10_0x1c8c10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8C10_0x1c8c10");
#endif

    ctx->pc = 0x1c8c10u;

    // 0x1c8c10: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8c10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8c14: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8C14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8C18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8C14u;
            // 0x1c8c18: 0xac24b648  sw          $a0, -0x49B8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294948424), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C8C1Cu;
    // 0x1c8c1c: 0x0  nop
    ctx->pc = 0x1c8c1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
