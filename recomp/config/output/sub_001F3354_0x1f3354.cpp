#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3354
// Address: 0x1f3354 - 0x1f33b4
void sub_001F3354_0x1f3354(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3354_0x1f3354");
#endif

    ctx->pc = 0x1f3354u;

    // 0x1f3354: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f3354u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f3358: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f3358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f335c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f335cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3360: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f3360u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3364: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x1f3364u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3368: 0xac43001c  sw          $v1, 0x1C($v0)
    ctx->pc = 0x1f3368u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 3));
    // 0x1f336c: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1f336cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1f3370: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3370u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3374: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f3374u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f3378: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f3378u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f337c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F337Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F3384u;
    // 0x1f3384: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f3384u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f3388: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f3388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f338c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f338cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3390: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f3390u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3394: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x1f3394u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3398: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1f3398u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1f339c: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1f339cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1f33a0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f33a0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f33a4: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f33a4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f33a8: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f33a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f33ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1F33ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F33B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
