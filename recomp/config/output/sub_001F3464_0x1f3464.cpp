#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3464
// Address: 0x1f3464 - 0x1f3494
void sub_001F3464_0x1f3464(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3464_0x1f3464");
#endif

    ctx->pc = 0x1f3464u;

    // 0x1f3464: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f3464u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f3468: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f3468u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f346c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f346cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3470: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f3470u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3474: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x1f3474u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3478: 0xac430024  sw          $v1, 0x24($v0)
    ctx->pc = 0x1f3478u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 36), GPR_U32(ctx, 3));
    // 0x1f347c: 0x8c420024  lw          $v0, 0x24($v0)
    ctx->pc = 0x1f347cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x1f3480: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3480u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3484: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f3484u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f3488: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f3488u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f348c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F348Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F3494u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
