#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102BF0
// Address: 0x102bf0 - 0x102c10
void sub_00102BF0_0x102bf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102BF0_0x102bf0");
#endif

    ctx->pc = 0x102bf0u;

    // 0x102bf0: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x102bf0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x102bf4: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x102bf4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x102bf8: 0x851025  or          $v0, $a0, $a1
    ctx->pc = 0x102bf8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x102bfc: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x102bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x102c00: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x102c00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x102c04: 0x34633c20  ori         $v1, $v1, 0x3C20
    ctx->pc = 0x102c04u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)15392);
    // 0x102c08: 0x3e00008  jr          $ra
    ctx->pc = 0x102C08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102C0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102C08u;
            // 0x102c0c: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x102C10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
