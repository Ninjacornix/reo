#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6720
// Address: 0x1d6720 - 0x1d6760
void sub_001D6720_0x1d6720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6720_0x1d6720");
#endif

    ctx->pc = 0x1d6720u;

    // 0x1d6720: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d6720u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d6724: 0x8c2245e8  lw          $v0, 0x45E8($at)
    ctx->pc = 0x1d6724u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17896)));
    // 0x1d6728: 0x38420003  xori        $v0, $v0, 0x3
    ctx->pc = 0x1d6728u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)3);
    // 0x1d672c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D672Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D672Cu;
            // 0x1d6730: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D6734u;
    // 0x1d6734: 0x0  nop
    ctx->pc = 0x1d6734u;
    // NOP
    // 0x1d6738: 0x0  nop
    ctx->pc = 0x1d6738u;
    // NOP
    // 0x1d673c: 0x0  nop
    ctx->pc = 0x1d673cu;
    // NOP
    // 0x1d6740: 0x4102b  sltu        $v0, $zero, $a0
    ctx->pc = 0x1d6740u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x1d6744: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d6744u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d6748: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1d6748u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1d674c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D674Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D674Cu;
            // 0x1d6750: 0xac2245f0  sw          $v0, 0x45F0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 17904), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D6754u;
    // 0x1d6754: 0x0  nop
    ctx->pc = 0x1d6754u;
    // NOP
    // 0x1d6758: 0x0  nop
    ctx->pc = 0x1d6758u;
    // NOP
    // 0x1d675c: 0x0  nop
    ctx->pc = 0x1d675cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
