#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013BC50
// Address: 0x13bc50 - 0x13bc70
void sub_0013BC50_0x13bc50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013BC50_0x13bc50");
#endif

    ctx->pc = 0x13bc50u;

    // 0x13bc50: 0x8c820028  lw          $v0, 0x28($a0)
    ctx->pc = 0x13bc50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x13bc54: 0xdc850008  ld          $a1, 0x8($a0)
    ctx->pc = 0x13bc54u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x13bc58: 0x212f8  dsll        $v0, $v0, 11
    ctx->pc = 0x13bc58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 11);
    // 0x13bc5c: 0xa2182b  sltu        $v1, $a1, $v0
    ctx->pc = 0x13bc5cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x13bc60: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x13bc60u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x13bc64: 0x3e00008  jr          $ra
    ctx->pc = 0x13BC64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13BC68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BC64u;
            // 0x13bc68: 0x2103f  dsra32      $v0, $v0, 0 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13BC6Cu;
    // 0x13bc6c: 0x0  nop
    ctx->pc = 0x13bc6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
