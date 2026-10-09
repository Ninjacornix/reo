#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B3B10
// Address: 0x1b3b10 - 0x1b3b40
void sub_001B3B10_0x1b3b10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B3B10_0x1b3b10");
#endif

    ctx->pc = 0x1b3b10u;

    // 0x1b3b10: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b3b10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b3b14: 0x94234414  lhu         $v1, 0x4414($at)
    ctx->pc = 0x1b3b14u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17428)));
    // 0x1b3b18: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B3B18u;
    {
        const bool branch_taken_0x1b3b18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3B1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3B18u;
            // 0x1b3b1c: 0x3c01002c  lui         $at, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3b18) {
            ctx->pc = 0x1B3B2Cu;
            goto label_1b3b2c;
        }
    }
    ctx->pc = 0x1B3B20u;
    // 0x1b3b20: 0xac24a9e0  sw          $a0, -0x5620($at)
    ctx->pc = 0x1b3b20u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945248), GPR_U32(ctx, 4));
    // 0x1b3b24: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b3b24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b3b28: 0xac25a9e4  sw          $a1, -0x561C($at)
    ctx->pc = 0x1b3b28u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945252), GPR_U32(ctx, 5));
label_1b3b2c:
    // 0x1b3b2c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3B2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B3B2Cu: goto label_1b3b2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B3B34u;
    // 0x1b3b34: 0x0  nop
    ctx->pc = 0x1b3b34u;
    // NOP
    // 0x1b3b38: 0x0  nop
    ctx->pc = 0x1b3b38u;
    // NOP
    // 0x1b3b3c: 0x0  nop
    ctx->pc = 0x1b3b3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
