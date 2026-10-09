#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124810
// Address: 0x124810 - 0x124840
void sub_00124810_0x124810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124810_0x124810");
#endif

    ctx->pc = 0x124810u;

    // 0x124810: 0x8c88008c  lw          $t0, 0x8C($a0)
    ctx->pc = 0x124810u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 140)));
    // 0x124814: 0x8c82003c  lw          $v0, 0x3C($a0)
    ctx->pc = 0x124814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x124818: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x124818u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x12481c: 0x8c85008c  lw          $a1, 0x8C($a0)
    ctx->pc = 0x12481cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 140)));
    // 0x124820: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x124820u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x124824: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x124824u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x124828: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x124828u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x12482c: 0x8c850018  lw          $a1, 0x18($a0)
    ctx->pc = 0x12482cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x124830: 0x8c830088  lw          $v1, 0x88($a0)
    ctx->pc = 0x124830u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 136)));
    // 0x124834: 0xa32823  subu        $a1, $a1, $v1
    ctx->pc = 0x124834u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x124838: 0x3e00008  jr          $ra
    ctx->pc = 0x124838u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12483Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124838u;
            // 0x12483c: 0xace50000  sw          $a1, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x124840u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
