#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101E00
// Address: 0x101e00 - 0x101e18
void sub_00101E00_0x101e00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101E00_0x101e00");
#endif

    ctx->pc = 0x101e00u;

    // 0x101e00: 0x4842e800  cfc2.ni     $v0, $vi29
    ctx->pc = 0x101e00u;
    SET_GPR_U32(ctx, 2, ctx->vu0_top);
    // 0x101e04: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x101e04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x101e08: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x101e08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x101e0c: 0x3e00008  jr          $ra
    ctx->pc = 0x101E0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101E0Cu;
            // 0x101e10: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x101E14u;
    // 0x101e14: 0x0  nop
    ctx->pc = 0x101e14u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
