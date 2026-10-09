#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C65D0
// Address: 0x1c65d0 - 0x1c65f4
void sub_001C65D0_0x1c65d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C65D0_0x1c65d0");
#endif

    ctx->pc = 0x1c65d0u;

    // 0x1c65d0: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1c65d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1c65d4: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x1c65d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1c65d8: 0x62082a  slt         $at, $v1, $v0
    ctx->pc = 0x1c65d8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c65dc: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C65DCu;
    {
        const bool branch_taken_0x1c65dc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C65E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C65DCu;
            // 0x1c65e0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c65dc) {
            ctx->pc = 0x1C65ECu;
            goto label_1c65ec;
        }
    }
    ctx->pc = 0x1C65E4u;
    // 0x1c65e4: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1c65e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1c65e8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c65e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1c65ec:
    // 0x1c65ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1C65ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C65ECu: goto label_1c65ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C65F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
