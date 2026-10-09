#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D640
// Address: 0x15d640 - 0x15d678
void sub_0015D640_0x15d640(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D640_0x15d640");
#endif

    ctx->pc = 0x15d640u;

    // 0x15d640: 0x24840158  addiu       $a0, $a0, 0x158
    ctx->pc = 0x15d640u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 344));
    // 0x15d644: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x15d644u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x15d648: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x15d648u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x15d64c: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x15d64cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x15d650: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x15d650u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x15d654: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x15D654u;
    {
        const bool branch_taken_0x15d654 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15D658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D654u;
            // 0x15d658: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d654) {
            ctx->pc = 0x15D66Cu;
            goto label_15d66c;
        }
    }
    ctx->pc = 0x15D65Cu;
    // 0x15d65c: 0x8c860008  lw          $a2, 0x8($a0)
    ctx->pc = 0x15d65cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x15d660: 0xac83000c  sw          $v1, 0xC($a0)
    ctx->pc = 0x15d660u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 3));
    // 0x15d664: 0xc51021  addu        $v0, $a2, $a1
    ctx->pc = 0x15d664u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x15d668: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x15d668u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
label_15d66c:
    // 0x15d66c: 0x3e00008  jr          $ra
    ctx->pc = 0x15D66Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D66Cu;
            // 0x15d670: 0xc0102d  daddu       $v0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D66Cu: goto label_15d66c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D674u;
    // 0x15d674: 0x0  nop
    ctx->pc = 0x15d674u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
