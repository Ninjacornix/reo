#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C9A0
// Address: 0x12c9a0 - 0x12c9d8
void sub_0012C9A0_0x12c9a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C9A0_0x12c9a0");
#endif

    ctx->pc = 0x12c9a0u;

    // 0x12c9a0: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x12c9a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x12c9a4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x12c9a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x12c9a8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x12c9a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x12c9ac: 0xac83003c  sw          $v1, 0x3C($a0)
    ctx->pc = 0x12c9acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 3));
    // 0x12c9b0: 0xac820038  sw          $v0, 0x38($a0)
    ctx->pc = 0x12c9b0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 2));
    // 0x12c9b4: 0xa0800003  sb          $zero, 0x3($a0)
    ctx->pc = 0x12c9b4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x12c9b8: 0xac800098  sw          $zero, 0x98($a0)
    ctx->pc = 0x12c9b8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 152), GPR_U32(ctx, 0));
    // 0x12c9bc: 0xac80002c  sw          $zero, 0x2C($a0)
    ctx->pc = 0x12c9bcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 0));
    // 0x12c9c0: 0xac800030  sw          $zero, 0x30($a0)
    ctx->pc = 0x12c9c0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 0));
    // 0x12c9c4: 0xac800034  sw          $zero, 0x34($a0)
    ctx->pc = 0x12c9c4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 0));
    // 0x12c9c8: 0xac800040  sw          $zero, 0x40($a0)
    ctx->pc = 0x12c9c8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 64), GPR_U32(ctx, 0));
    // 0x12c9cc: 0x3e00008  jr          $ra
    ctx->pc = 0x12C9CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C9D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C9CCu;
            // 0x12c9d0: 0xac800044  sw          $zero, 0x44($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12C9D4u;
    // 0x12c9d4: 0x0  nop
    ctx->pc = 0x12c9d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
