#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187930
// Address: 0x187930 - 0x187970
void sub_00187930_0x187930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187930_0x187930");
#endif

    switch (ctx->pc) {
        case 0x187940u: goto label_187940;
        default: break;
    }

    ctx->pc = 0x187930u;

    // 0x187930: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x187930u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x187934: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x187934u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187938: 0x2446b8c8  addiu       $a2, $v0, -0x4738
    ctx->pc = 0x187938u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949064));
    // 0x18793c: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x18793cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
label_187940:
    // 0x187940: 0x24c6001c  addiu       $a2, $a2, 0x1C
    ctx->pc = 0x187940u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 28));
    // 0x187944: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x187944u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187948: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x187948u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x18794c: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x18794Cu;
    {
        const bool branch_taken_0x18794c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x187950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18794Cu;
            // 0x187950: 0x28a40002  slti        $a0, $a1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18794c) {
            ctx->pc = 0x187968u;
            goto label_187968;
        }
    }
    ctx->pc = 0x187954u;
    // 0x187954: 0x0  nop
    ctx->pc = 0x187954u;
    // NOP
    // 0x187958: 0x0  nop
    ctx->pc = 0x187958u;
    // NOP
    // 0x18795c: 0x5480fff8  bnel        $a0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x18795Cu;
    {
        const bool branch_taken_0x18795c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x18795c) {
            ctx->pc = 0x187960u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18795Cu;
            // 0x187960: 0x8cc30000  lw          $v1, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x187940u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_187940;
        }
    }
    ctx->pc = 0x187964u;
    // 0x187964: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x187964u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_187968:
    // 0x187968: 0x3e00008  jr          $ra
    ctx->pc = 0x187968u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x187940u: goto label_187940;
            case 0x187968u: goto label_187968;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187970u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
