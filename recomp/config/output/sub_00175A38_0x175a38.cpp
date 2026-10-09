#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175A38
// Address: 0x175a38 - 0x175a48
void sub_00175A38_0x175a38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175A38_0x175a38");
#endif

    ctx->pc = 0x175a38u;

    // 0x175a38: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x175a38u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x175a3c: 0xac850008  sw          $a1, 0x8($a0)
    ctx->pc = 0x175a3cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 5));
    // 0x175a40: 0x3e00008  jr          $ra
    ctx->pc = 0x175A40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175A44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175A40u;
            // 0x175a44: 0xac800004  sw          $zero, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x175A48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
