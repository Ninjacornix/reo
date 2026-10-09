#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3494
// Address: 0x1f3494 - 0x1f34bc
void sub_001F3494_0x1f3494(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3494_0x1f3494");
#endif

    ctx->pc = 0x1f3494u;

    // 0x1f3494: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f3494u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f3498: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f3498u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f349c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f349cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f34a0: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f34a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f34a4: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x1f34a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x1f34a8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f34a8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f34ac: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f34acu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f34b0: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f34b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f34b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F34B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F34BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
