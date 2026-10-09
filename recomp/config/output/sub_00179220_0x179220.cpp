#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179220
// Address: 0x179220 - 0x179238
void sub_00179220_0x179220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179220_0x179220");
#endif

    ctx->pc = 0x179220u;

    // 0x179220: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179220u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179224: 0xac860008  sw          $a2, 0x8($a0)
    ctx->pc = 0x179224u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 6));
    // 0x179228: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x179228u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x17922c: 0x3e00008  jr          $ra
    ctx->pc = 0x17922Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17922Cu;
            // 0x179230: 0xac850004  sw          $a1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x179234u;
    // 0x179234: 0x0  nop
    ctx->pc = 0x179234u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
