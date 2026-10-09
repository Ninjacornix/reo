#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1C60
// Address: 0x1a1c60 - 0x1a1cb0
void sub_001A1C60_0x1a1c60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1C60_0x1a1c60");
#endif

    ctx->pc = 0x1a1c60u;

    // 0x1a1c60: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x1a1c60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a1c64: 0xac83000c  sw          $v1, 0xC($a0)
    ctx->pc = 0x1a1c64u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 3));
    // 0x1a1c68: 0xac850008  sw          $a1, 0x8($a0)
    ctx->pc = 0x1a1c68u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 5));
    // 0x1a1c6c: 0x8c850008  lw          $a1, 0x8($a0)
    ctx->pc = 0x1a1c6cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a1c70: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x1a1c70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1a1c74: 0x651826  xor         $v1, $v1, $a1
    ctx->pc = 0x1a1c74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 5));
    // 0x1a1c78: 0xa31824  and         $v1, $a1, $v1
    ctx->pc = 0x1a1c78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x1a1c7c: 0xac830010  sw          $v1, 0x10($a0)
    ctx->pc = 0x1a1c7cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 3));
    // 0x1a1c80: 0x8c85000c  lw          $a1, 0xC($a0)
    ctx->pc = 0x1a1c80u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1a1c84: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x1a1c84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a1c88: 0xa31826  xor         $v1, $a1, $v1
    ctx->pc = 0x1a1c88u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) ^ GPR_U64(ctx, 3));
    // 0x1a1c8c: 0xa31824  and         $v1, $a1, $v1
    ctx->pc = 0x1a1c8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x1a1c90: 0xac830014  sw          $v1, 0x14($a0)
    ctx->pc = 0x1a1c90u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 3));
    // 0x1a1c94: 0x8c850010  lw          $a1, 0x10($a0)
    ctx->pc = 0x1a1c94u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1a1c98: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x1a1c98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1a1c9c: 0xa31825  or          $v1, $a1, $v1
    ctx->pc = 0x1a1c9cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x1a1ca0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1CA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A1CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1CA0u;
            // 0x1a1ca4: 0xac830018  sw          $v1, 0x18($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A1CA8u;
    // 0x1a1ca8: 0x0  nop
    ctx->pc = 0x1a1ca8u;
    // NOP
    // 0x1a1cac: 0x0  nop
    ctx->pc = 0x1a1cacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
