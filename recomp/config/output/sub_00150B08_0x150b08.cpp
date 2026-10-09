#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150B08
// Address: 0x150b08 - 0x150b30
void sub_00150B08_0x150b08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150B08_0x150b08");
#endif

    ctx->pc = 0x150b08u;

    // 0x150b08: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x150B08u;
    {
        const bool branch_taken_0x150b08 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x150B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150B08u;
            // 0x150b0c: 0x2484011c  addiu       $a0, $a0, 0x11C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 284));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150b08) {
            ctx->pc = 0x150B18u;
            goto label_150b18;
        }
    }
    ctx->pc = 0x150B10u;
    // 0x150b10: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x150b10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x150b14: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x150b14u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_150b18:
    // 0x150b18: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x150B18u;
    {
        const bool branch_taken_0x150b18 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x150b18) {
            ctx->pc = 0x150B28u;
            goto label_150b28;
        }
    }
    ctx->pc = 0x150B20u;
    // 0x150b20: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x150b20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x150b24: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x150b24u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
label_150b28:
    // 0x150b28: 0x3e00008  jr          $ra
    ctx->pc = 0x150B28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150B18u: goto label_150b18;
            case 0x150B28u: goto label_150b28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150B30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
