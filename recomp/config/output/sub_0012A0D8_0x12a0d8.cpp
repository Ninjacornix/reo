#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A0D8
// Address: 0x12a0d8 - 0x12a0ec
void sub_0012A0D8_0x12a0d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A0D8_0x12a0d8");
#endif

    ctx->pc = 0x12a0d8u;

    // 0x12a0d8: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12a0d8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12a0dc: 0x2463f390  addiu       $v1, $v1, -0xC70
    ctx->pc = 0x12a0dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294964112));
    // 0x12a0e0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12a0e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12a0e4: 0x3e00008  jr          $ra
    ctx->pc = 0x12A0E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A0E4u;
            // 0x12a0e8: 0x2102b  sltu        $v0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12A0ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
