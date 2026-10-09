#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125230
// Address: 0x125230 - 0x125248
void sub_00125230_0x125230(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125230_0x125230");
#endif

    ctx->pc = 0x125230u;

    // 0x125230: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x125230u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x125234: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x125234u;
    {
        const bool branch_taken_0x125234 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x125238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125234u;
            // 0x125238: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125234) {
            ctx->pc = 0x125240u;
            goto label_125240;
        }
    }
    ctx->pc = 0x12523Cu;
    // 0x12523c: 0xac820004  sw          $v0, 0x4($a0)
    ctx->pc = 0x12523cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 2));
label_125240:
    // 0x125240: 0x3e00008  jr          $ra
    ctx->pc = 0x125240u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125240u: goto label_125240;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125248u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
