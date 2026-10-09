#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D9690
// Address: 0x1d9690 - 0x1d96b0
void sub_001D9690_0x1d9690(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D9690_0x1d9690");
#endif

    ctx->pc = 0x1d9690u;

    // 0x1d9690: 0x3082ffff  andi        $v0, $a0, 0xFFFF
    ctx->pc = 0x1d9690u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1d9694: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1d9694u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1d9698: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1d9698u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1d969c: 0x3063ff00  andi        $v1, $v1, 0xFF00
    ctx->pc = 0x1d969cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65280);
    // 0x1d96a0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1d96a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1d96a4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1d96a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1d96a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D96A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D96ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D96A8u;
            // 0x1d96ac: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D96B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
