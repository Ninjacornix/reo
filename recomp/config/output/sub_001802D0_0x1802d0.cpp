#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001802D0
// Address: 0x1802d0 - 0x180310
void sub_001802D0_0x1802d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001802D0_0x1802d0");
#endif

    switch (ctx->pc) {
        case 0x1802e8u: goto label_1802e8;
        default: break;
    }

    ctx->pc = 0x1802d0u;

    // 0x1802d0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1802d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1802d4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1802d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1802d8: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x1802d8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x1802dc: 0xac43f9e0  sw          $v1, -0x620($v0)
    ctx->pc = 0x1802dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294965728), GPR_U32(ctx, 3));
    // 0x1802e0: 0x24846188  addiu       $a0, $a0, 0x6188
    ctx->pc = 0x1802e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24968));
    // 0x1802e4: 0x24833340  addiu       $v1, $a0, 0x3340
    ctx->pc = 0x1802e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 13120));
label_1802e8:
    // 0x1802e8: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x1802e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x1802ec: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x1802ecu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x1802f0: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x1802f0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x1802f4: 0xac80000c  sw          $zero, 0xC($a0)
    ctx->pc = 0x1802f4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x1802f8: 0x24840334  addiu       $a0, $a0, 0x334
    ctx->pc = 0x1802f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 820));
    // 0x1802fc: 0x83102a  slt         $v0, $a0, $v1
    ctx->pc = 0x1802fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x180300: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x180300u;
    {
        const bool branch_taken_0x180300 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x180300) {
            ctx->pc = 0x1802E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1802e8;
        }
    }
    ctx->pc = 0x180308u;
    // 0x180308: 0x3e00008  jr          $ra
    ctx->pc = 0x180308u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18030Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180308u;
            // 0x18030c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1802E8u: goto label_1802e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180310u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
