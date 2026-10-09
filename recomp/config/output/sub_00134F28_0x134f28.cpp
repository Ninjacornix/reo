#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134F28
// Address: 0x134f28 - 0x134f58
void sub_00134F28_0x134f28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134F28_0x134f28");
#endif

    ctx->pc = 0x134f28u;

    // 0x134f28: 0xa4870038  sh          $a3, 0x38($a0)
    ctx->pc = 0x134f28u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 56), (uint16_t)GPR_U32(ctx, 7));
    // 0x134f2c: 0xa4850034  sh          $a1, 0x34($a0)
    ctx->pc = 0x134f2cu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 52), (uint16_t)GPR_U32(ctx, 5));
    // 0x134f30: 0x3e00008  jr          $ra
    ctx->pc = 0x134F30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134F34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134F30u;
            // 0x134f34: 0xa4860036  sh          $a2, 0x36($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 54), (uint16_t)GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x134F38u;
    // 0x134f38: 0x94820034  lhu         $v0, 0x34($a0)
    ctx->pc = 0x134f38u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 52)));
    // 0x134f3c: 0xa4a20000  sh          $v0, 0x0($a1)
    ctx->pc = 0x134f3cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x134f40: 0x94830036  lhu         $v1, 0x36($a0)
    ctx->pc = 0x134f40u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 54)));
    // 0x134f44: 0xa4c30000  sh          $v1, 0x0($a2)
    ctx->pc = 0x134f44u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x134f48: 0x94820038  lhu         $v0, 0x38($a0)
    ctx->pc = 0x134f48u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 56)));
    // 0x134f4c: 0x3e00008  jr          $ra
    ctx->pc = 0x134F4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134F50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134F4Cu;
            // 0x134f50: 0xa4e20000  sh          $v0, 0x0($a3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x134F54u;
    // 0x134f54: 0x0  nop
    ctx->pc = 0x134f54u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
