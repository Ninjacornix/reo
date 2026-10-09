#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9190
// Address: 0x1a9190 - 0x1a91b4
void sub_001A9190_0x1a9190(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9190_0x1a9190");
#endif

    ctx->pc = 0x1a9190u;

    // 0x1a9190: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1a9190u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1a9194: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a9194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a9198: 0xffa70038  sd          $a3, 0x38($sp)
    ctx->pc = 0x1a9198u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 7));
    // 0x1a919c: 0xffa80040  sd          $t0, 0x40($sp)
    ctx->pc = 0x1a919cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 8));
    // 0x1a91a0: 0xffa90048  sd          $t1, 0x48($sp)
    ctx->pc = 0x1a91a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 9));
    // 0x1a91a4: 0xffaa0050  sd          $t2, 0x50($sp)
    ctx->pc = 0x1a91a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 10));
    // 0x1a91a8: 0xffab0058  sd          $t3, 0x58($sp)
    ctx->pc = 0x1a91a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 11));
    // 0x1a91ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1A91ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A91B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A91ACu;
            // 0x1a91b0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A91B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
