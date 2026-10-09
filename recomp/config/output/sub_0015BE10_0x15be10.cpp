#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015BE10
// Address: 0x15be10 - 0x15be30
void sub_0015BE10_0x15be10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015BE10_0x15be10");
#endif

    ctx->pc = 0x15be10u;

    // 0x15be10: 0x24024000  addiu       $v0, $zero, 0x4000
    ctx->pc = 0x15be10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x15be14: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x15be14u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x15be18: 0x24030700  addiu       $v1, $zero, 0x700
    ctx->pc = 0x15be18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1792));
    // 0x15be1c: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x15be1cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x15be20: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x15be20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x15be24: 0x3e00008  jr          $ra
    ctx->pc = 0x15BE24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15BE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BE24u;
            // 0x15be28: 0x431021  addu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15BE2Cu;
    // 0x15be2c: 0x0  nop
    ctx->pc = 0x15be2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
