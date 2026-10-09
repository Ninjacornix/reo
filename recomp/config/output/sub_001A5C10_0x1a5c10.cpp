#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5C10
// Address: 0x1a5c10 - 0x1a5c30
void sub_001A5C10_0x1a5c10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5C10_0x1a5c10");
#endif

    ctx->pc = 0x1a5c10u;

    // 0x1a5c10: 0x8ca60000  lw          $a2, 0x0($a1)
    ctx->pc = 0x1a5c10u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a5c14: 0x34830001  ori         $v1, $a0, 0x1
    ctx->pc = 0x1a5c14u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1);
    // 0x1a5c18: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1a5c18u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1a5c1c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5C1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5C20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5C1Cu;
            // 0x1a5c20: 0xac860000  sw          $a2, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A5C24u;
    // 0x1a5c24: 0x0  nop
    ctx->pc = 0x1a5c24u;
    // NOP
    // 0x1a5c28: 0x0  nop
    ctx->pc = 0x1a5c28u;
    // NOP
    // 0x1a5c2c: 0x0  nop
    ctx->pc = 0x1a5c2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
