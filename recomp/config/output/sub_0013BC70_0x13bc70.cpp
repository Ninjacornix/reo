#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013BC70
// Address: 0x13bc70 - 0x13bca0
void sub_0013BC70_0x13bc70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013BC70_0x13bc70");
#endif

    ctx->pc = 0x13bc70u;

    // 0x13bc70: 0x8c820028  lw          $v0, 0x28($a0)
    ctx->pc = 0x13bc70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x13bc74: 0x3c06ffff  lui         $a2, 0xFFFF
    ctx->pc = 0x13bc74u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)65535 << 16));
    // 0x13bc78: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x13bc78u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x13bc7c: 0xdc850008  ld          $a1, 0x8($a0)
    ctx->pc = 0x13bc7cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x13bc80: 0x212f8  dsll        $v0, $v0, 11
    ctx->pc = 0x13bc80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 11);
    // 0x13bc84: 0xa2182b  sltu        $v1, $a1, $v0
    ctx->pc = 0x13bc84u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x13bc88: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x13bc88u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x13bc8c: 0x461024  and         $v0, $v0, $a2
    ctx->pc = 0x13bc8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 6));
    // 0x13bc90: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x13bc90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x13bc94: 0x3e00008  jr          $ra
    ctx->pc = 0x13BC94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13BC98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BC94u;
            // 0x13bc98: 0x2103f  dsra32      $v0, $v0, 0 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13BC9Cu;
    // 0x13bc9c: 0x0  nop
    ctx->pc = 0x13bc9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
