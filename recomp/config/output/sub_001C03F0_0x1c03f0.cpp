#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C03F0
// Address: 0x1c03f0 - 0x1c0420
void sub_001C03F0_0x1c03f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C03F0_0x1c03f0");
#endif

    ctx->pc = 0x1c03f0u;

    // 0x1c03f0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c03f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c03f4: 0xac206ce8  sw          $zero, 0x6CE8($at)
    ctx->pc = 0x1c03f4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27880), GPR_U32(ctx, 0));
    // 0x1c03f8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c03f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c03fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1C03FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C03FCu;
            // 0x1c0400: 0xac206cf8  sw          $zero, 0x6CF8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 27896), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C0404u;
    // 0x1c0404: 0x0  nop
    ctx->pc = 0x1c0404u;
    // NOP
    // 0x1c0408: 0x0  nop
    ctx->pc = 0x1c0408u;
    // NOP
    // 0x1c040c: 0x0  nop
    ctx->pc = 0x1c040cu;
    // NOP
    // 0x1c0410: 0x3e00008  jr          $ra
    ctx->pc = 0x1C0410u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C0418u;
    // 0x1c0418: 0x0  nop
    ctx->pc = 0x1c0418u;
    // NOP
    // 0x1c041c: 0x0  nop
    ctx->pc = 0x1c041cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
