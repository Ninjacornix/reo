#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103378
// Address: 0x103378 - 0x10338c
void sub_00103378_0x103378(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103378_0x103378");
#endif

    ctx->pc = 0x103378u;

    // 0x103378: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x103378u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x10337c: 0x3463e060  ori         $v1, $v1, 0xE060
    ctx->pc = 0x10337cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)57440);
    // 0x103380: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x103380u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x103384: 0x3e00008  jr          $ra
    ctx->pc = 0x103384u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103384u;
            // 0x103388: 0xac640000  sw          $a0, 0x0($v1) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x10338Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
