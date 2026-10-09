#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FBD0
// Address: 0x12fbd0 - 0x12fbf8
void sub_0012FBD0_0x12fbd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FBD0_0x12fbd0");
#endif

    ctx->pc = 0x12fbd0u;

    // 0x12fbd0: 0x808202d6  lb          $v0, 0x2D6($a0)
    ctx->pc = 0x12fbd0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 726)));
    // 0x12fbd4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12fbd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12fbd8: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x12FBD8u;
    {
        const bool branch_taken_0x12fbd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x12fbd8) {
            ctx->pc = 0x12FBF0u;
            goto label_12fbf0;
        }
    }
    ctx->pc = 0x12FBE0u;
    // 0x12fbe0: 0x8c820048  lw          $v0, 0x48($a0)
    ctx->pc = 0x12fbe0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 72)));
    // 0x12fbe4: 0xa08302d6  sb          $v1, 0x2D6($a0)
    ctx->pc = 0x12fbe4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 726), (uint8_t)GPR_U32(ctx, 3));
    // 0x12fbe8: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x12fbe8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x12fbec: 0xac820048  sw          $v0, 0x48($a0)
    ctx->pc = 0x12fbecu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 2));
label_12fbf0:
    // 0x12fbf0: 0x3e00008  jr          $ra
    ctx->pc = 0x12FBF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FBF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FBF0u;
            // 0x12fbf4: 0xa48502e8  sh          $a1, 0x2E8($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 744), (uint16_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FBF0u: goto label_12fbf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FBF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
