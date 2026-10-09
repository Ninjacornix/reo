#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B92E0
// Address: 0x1b92e0 - 0x1b930c
void sub_001B92E0_0x1b92e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B92E0_0x1b92e0");
#endif

    ctx->pc = 0x1b92e0u;

    // 0x1b92e0: 0x94820bba  lhu         $v0, 0xBBA($a0)
    ctx->pc = 0x1b92e0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 3002)));
    // 0x1b92e4: 0x3c030038  lui         $v1, 0x38
    ctx->pc = 0x1b92e4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)56 << 16));
    // 0x1b92e8: 0x90850003  lbu         $a1, 0x3($a0)
    ctx->pc = 0x1b92e8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1b92ec: 0x24637e90  addiu       $v1, $v1, 0x7E90
    ctx->pc = 0x1b92ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32400));
    // 0x1b92f0: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1b92f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1b92f4: 0x520c0  sll         $a0, $a1, 3
    ctx->pc = 0x1b92f4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1b92f8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b92f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b92fc: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1b92fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b9300: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b9300u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b9304: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B9308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9304u;
            // 0x1b9308: 0x80420007  lb          $v0, 0x7($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 7)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B930Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
