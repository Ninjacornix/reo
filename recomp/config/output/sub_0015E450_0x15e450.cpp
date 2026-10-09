#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E450
// Address: 0x15e450 - 0x15e478
void sub_0015E450_0x15e450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E450_0x15e450");
#endif

    ctx->pc = 0x15e450u;

    // 0x15e450: 0x8c850080  lw          $a1, 0x80($a0)
    ctx->pc = 0x15e450u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 128)));
    // 0x15e454: 0x8c82007c  lw          $v0, 0x7C($a0)
    ctx->pc = 0x15e454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 124)));
    // 0x15e458: 0x24a40001  addiu       $a0, $a1, 0x1
    ctx->pc = 0x15e458u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x15e45c: 0xa2182a  slt         $v1, $a1, $v0
    ctx->pc = 0x15e45cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x15e460: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x15E460u;
    {
        const bool branch_taken_0x15e460 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x15E464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E460u;
            // 0x15e464: 0x451026  xor         $v0, $v0, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e460) {
            ctx->pc = 0x15E470u;
            goto label_15e470;
        }
    }
    ctx->pc = 0x15E468u;
    // 0x15e468: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x15e468u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e46c: 0xa2200a  movz        $a0, $a1, $v0
    ctx->pc = 0x15e46cu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 5));
label_15e470:
    // 0x15e470: 0x3e00008  jr          $ra
    ctx->pc = 0x15E470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E470u;
            // 0x15e474: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E470u: goto label_15e470;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E478u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
