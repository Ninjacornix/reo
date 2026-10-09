#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F33DC
// Address: 0x1f33dc - 0x1f340c
void sub_001F33DC_0x1f33dc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F33DC_0x1f33dc");
#endif

    ctx->pc = 0x1f33dcu;

    // 0x1f33dc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f33dcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f33e0: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f33e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f33e4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f33e4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f33e8: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f33e8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f33ec: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x1f33ecu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f33f0: 0xac430020  sw          $v1, 0x20($v0)
    ctx->pc = 0x1f33f0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 3));
    // 0x1f33f4: 0x8c420020  lw          $v0, 0x20($v0)
    ctx->pc = 0x1f33f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1f33f8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f33f8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f33fc: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f33fcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f3400: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f3400u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f3404: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3404u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F340Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
