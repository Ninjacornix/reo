#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00143F88
// Address: 0x143f88 - 0x143fb0
void sub_00143F88_0x143f88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00143F88_0x143f88");
#endif

    ctx->pc = 0x143f88u;

    // 0x143f88: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x143f88u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x143f8c: 0x3c03ff7f  lui         $v1, 0xFF7F
    ctx->pc = 0x143f8cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65407 << 16));
    // 0x143f90: 0x34a52010  ori         $a1, $a1, 0x2010
    ctx->pc = 0x143f90u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)8208);
    // 0x143f94: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x143f94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x143f98: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x143f98u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0))); // MMIO: 0x10000000
    // 0x143f9c: 0x425c0  sll         $a0, $a0, 23
    ctx->pc = 0x143f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 23));
    // 0x143fa0: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x143fa0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x143fa4: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x143fa4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x143fa8: 0x3e00008  jr          $ra
    ctx->pc = 0x143FA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x143FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x143FA8u;
            // 0x143fac: 0xaca20000  sw          $v0, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x143FB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
