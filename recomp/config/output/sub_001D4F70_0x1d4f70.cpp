#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4F70
// Address: 0x1d4f70 - 0x1d4f90
void sub_001D4F70_0x1d4f70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4F70_0x1d4f70");
#endif

    ctx->pc = 0x1d4f70u;

    // 0x1d4f70: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1d4f70u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d4f74: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d4f74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d4f78: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4f78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4f7c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d4f7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4f80: 0xa4232640  sh          $v1, 0x2640($at)
    ctx->pc = 0x1d4f80u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 9792), (uint16_t)GPR_U32(ctx, 3));
    // 0x1d4f84: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4f84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4f88: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4F88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4F8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4F88u;
            // 0x1d4f8c: 0xa0232658  sb          $v1, 0x2658($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 9816), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D4F90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
