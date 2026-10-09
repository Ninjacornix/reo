#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F340C
// Address: 0x1f340c - 0x1f343c
void sub_001F340C_0x1f340c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F340C_0x1f340c");
#endif

    ctx->pc = 0x1f340cu;

    // 0x1f340c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f340cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f3410: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f3410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f3414: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f3414u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3418: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1f3418u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f341c: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x1f341cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1f3420: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f3420u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f3424: 0xac620020  sw          $v0, 0x20($v1)
    ctx->pc = 0x1f3424u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 32), GPR_U32(ctx, 2));
    // 0x1f3428: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3428u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f342c: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f342cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f3430: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f3430u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f3434: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3434u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F343Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
