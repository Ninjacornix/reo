#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175C98
// Address: 0x175c98 - 0x175cb8
void sub_00175C98_0x175c98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175C98_0x175c98");
#endif

    ctx->pc = 0x175c98u;

    // 0x175c98: 0xac800018  sw          $zero, 0x18($a0)
    ctx->pc = 0x175c98u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x175c9c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x175c9cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x175ca0: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x175ca0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x175ca4: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x175ca4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x175ca8: 0xac80000c  sw          $zero, 0xC($a0)
    ctx->pc = 0x175ca8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x175cac: 0xac800010  sw          $zero, 0x10($a0)
    ctx->pc = 0x175cacu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
    // 0x175cb0: 0x3e00008  jr          $ra
    ctx->pc = 0x175CB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175CB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175CB0u;
            // 0x175cb4: 0xac800014  sw          $zero, 0x14($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x175CB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
