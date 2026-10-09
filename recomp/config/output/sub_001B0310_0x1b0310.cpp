#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0310
// Address: 0x1b0310 - 0x1b033c
void sub_001B0310_0x1b0310(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0310_0x1b0310");
#endif

    ctx->pc = 0x1b0310u;

    // 0x1b0310: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0310u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0314: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b0314u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0318: 0x802343fb  lb          $v1, 0x43FB($at)
    ctx->pc = 0x1b0318u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17403)));
    // 0x1b031c: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B031Cu;
    {
        const bool branch_taken_0x1b031c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B0320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B031Cu;
            // 0x1b0320: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b031c) {
            ctx->pc = 0x1B0334u;
            goto label_1b0334;
        }
    }
    ctx->pc = 0x1B0324u;
    // 0x1b0324: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b0324u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b0328: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B0328u;
    {
        const bool branch_taken_0x1b0328 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B032Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0328u;
            // 0x1b032c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0328) {
            ctx->pc = 0x1B0334u;
            goto label_1b0334;
        }
    }
    ctx->pc = 0x1B0330u;
    // 0x1b0330: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b0330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b0334:
    // 0x1b0334: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0334u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0334u: goto label_1b0334;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B033Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
