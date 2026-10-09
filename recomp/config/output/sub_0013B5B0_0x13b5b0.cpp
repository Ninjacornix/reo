#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B5B0
// Address: 0x13b5b0 - 0x13b5e8
void sub_0013B5B0_0x13b5b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B5B0_0x13b5b0");
#endif

    switch (ctx->pc) {
        case 0x13b5c0u: goto label_13b5c0;
        default: break;
    }

    ctx->pc = 0x13b5b0u;

    // 0x13b5b0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13b5b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13b5b4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13b5b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b5b8: 0x2443daf0  addiu       $v1, $v0, -0x2510
    ctx->pc = 0x13b5b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957808));
    // 0x13b5bc: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x13b5bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
label_13b5c0:
    // 0x13b5c0: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x13b5c0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13b5c4: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x13b5c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x13b5c8: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x13b5c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x13b5cc: 0x62280a  movz        $a1, $v1, $v0
    ctx->pc = 0x13b5ccu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 3));
    // 0x13b5d0: 0x0  nop
    ctx->pc = 0x13b5d0u;
    // NOP
    // 0x13b5d4: 0x481fffa  bgez        $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x13B5D4u;
    {
        const bool branch_taken_0x13b5d4 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x13B5D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B5D4u;
            // 0x13b5d8: 0x24630030  addiu       $v1, $v1, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b5d4) {
            ctx->pc = 0x13B5C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13b5c0;
        }
    }
    ctx->pc = 0x13B5DCu;
    // 0x13b5dc: 0x3e00008  jr          $ra
    ctx->pc = 0x13B5DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B5E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B5DCu;
            // 0x13b5e0: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B5C0u: goto label_13b5c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B5E4u;
    // 0x13b5e4: 0x0  nop
    ctx->pc = 0x13b5e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
