#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F32FC
// Address: 0x1f32fc - 0x1f332c
void sub_001F32FC_0x1f32fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F32FC_0x1f32fc");
#endif

    ctx->pc = 0x1f32fcu;

    // 0x1f32fc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f32fcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f3300: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f3300u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f3304: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f3304u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3308: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f3308u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f330c: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x1f330cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3310: 0xac430018  sw          $v1, 0x18($v0)
    ctx->pc = 0x1f3310u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 3));
    // 0x1f3314: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1f3314u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1f3318: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3318u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f331c: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f331cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f3320: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f3320u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f3324: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3324u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F332Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
