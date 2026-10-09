#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102C10
// Address: 0x102c10 - 0x102c20
void sub_00102C10_0x102c10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102C10_0x102c10");
#endif

    ctx->pc = 0x102c10u;

    // 0x102c10: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x102c10u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x102c14: 0x34633c20  ori         $v1, $v1, 0x3C20
    ctx->pc = 0x102c14u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)15392);
    // 0x102c18: 0x3e00008  jr          $ra
    ctx->pc = 0x102C18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102C1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102C18u;
            // 0x102c1c: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x102C20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
