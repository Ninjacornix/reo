#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F324C
// Address: 0x1f324c - 0x1f327c
void sub_001F324C_0x1f324c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F324C_0x1f324c");
#endif

    ctx->pc = 0x1f324cu;

    // 0x1f324c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f324cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f3250: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f3250u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f3254: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f3254u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3258: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f3258u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f325c: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x1f325cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3260: 0xac430010  sw          $v1, 0x10($v0)
    ctx->pc = 0x1f3260u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 3));
    // 0x1f3264: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1f3264u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1f3268: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3268u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f326c: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f326cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f3270: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f3270u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f3274: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3274u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F327Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
