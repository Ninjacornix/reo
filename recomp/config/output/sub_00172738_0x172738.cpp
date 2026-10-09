#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172738
// Address: 0x172738 - 0x172768
void sub_00172738_0x172738(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172738_0x172738");
#endif

    ctx->pc = 0x172738u;

    // 0x172738: 0x8c83004c  lw          $v1, 0x4C($a0)
    ctx->pc = 0x172738u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x17273c: 0x8c850048  lw          $a1, 0x48($a0)
    ctx->pc = 0x17273cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 72)));
    // 0x172740: 0x28620002  slti        $v0, $v1, 0x2
    ctx->pc = 0x172740u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x172744: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x172744u;
    {
        const bool branch_taken_0x172744 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x172748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172744u;
            // 0x172748: 0x28640005  slti        $a0, $v1, 0x5 (Delay Slot)
        SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)5) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x172744) {
            ctx->pc = 0x172760u;
            goto label_172760;
        }
    }
    ctx->pc = 0x17274Cu;
    // 0x17274c: 0x54800004  bnel        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x17274Cu;
    {
        const bool branch_taken_0x17274c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x17274c) {
            ctx->pc = 0x172750u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17274Cu;
            // 0x172750: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172760u;
            goto label_172760;
        }
    }
    ctx->pc = 0x172754u;
    // 0x172754: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x172754u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x172758: 0x50620001  beql        $v1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x172758u;
    {
        const bool branch_taken_0x172758 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x172758) {
            ctx->pc = 0x17275Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172758u;
            // 0x17275c: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172760u;
            goto label_172760;
        }
    }
    ctx->pc = 0x172760u;
label_172760:
    // 0x172760: 0x3e00008  jr          $ra
    ctx->pc = 0x172760u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172760u;
            // 0x172764: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x172760u: goto label_172760;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172768u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
