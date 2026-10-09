#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B92B0
// Address: 0x1b92b0 - 0x1b92e0
void sub_001B92B0_0x1b92b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B92B0_0x1b92b0");
#endif

    ctx->pc = 0x1b92b0u;

    // 0x1b92b0: 0x94820bba  lhu         $v0, 0xBBA($a0)
    ctx->pc = 0x1b92b0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 3002)));
    // 0x1b92b4: 0x3c030038  lui         $v1, 0x38
    ctx->pc = 0x1b92b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)56 << 16));
    // 0x1b92b8: 0x90850003  lbu         $a1, 0x3($a0)
    ctx->pc = 0x1b92b8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1b92bc: 0x24637e90  addiu       $v1, $v1, 0x7E90
    ctx->pc = 0x1b92bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32400));
    // 0x1b92c0: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1b92c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1b92c4: 0x520c0  sll         $a0, $a1, 3
    ctx->pc = 0x1b92c4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1b92c8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b92c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b92cc: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1b92ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b92d0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b92d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b92d4: 0x90420006  lbu         $v0, 0x6($v0)
    ctx->pc = 0x1b92d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 6)));
    // 0x1b92d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B92D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B92DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B92D8u;
            // 0x1b92dc: 0x2102b  sltu        $v0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B92E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
