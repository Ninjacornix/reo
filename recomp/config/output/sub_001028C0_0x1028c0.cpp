#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001028C0
// Address: 0x1028c0 - 0x1028e0
void sub_001028C0_0x1028c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001028C0_0x1028c0");
#endif

    ctx->pc = 0x1028c0u;

    // 0x1028c0: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x1028c0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1028c4: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x1028c4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1028c8: 0x851025  or          $v0, $a0, $a1
    ctx->pc = 0x1028c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1028cc: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1028ccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1028d0: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x1028d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x1028d4: 0x34633820  ori         $v1, $v1, 0x3820
    ctx->pc = 0x1028d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14368);
    // 0x1028d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1028D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1028DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1028D8u;
            // 0x1028dc: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1028E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
