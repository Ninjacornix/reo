#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3224
// Address: 0x1f3224 - 0x1f324c
void sub_001F3224_0x1f3224(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3224_0x1f3224");
#endif

    ctx->pc = 0x1f3224u;

    // 0x1f3224: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f3224u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f3228: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f3228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f322c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f322cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3230: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f3230u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3234: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1f3234u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1f3238: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3238u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f323c: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f323cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f3240: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f3240u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f3244: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3244u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F324Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
