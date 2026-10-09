#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F112C
// Address: 0x1f112c - 0x1f116c
void sub_001F112C_0x1f112c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F112C_0x1f112c");
#endif

    ctx->pc = 0x1f112cu;

    // 0x1f112c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f112cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f1130: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f1130u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f1134: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1134u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1138: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1f1138u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f113c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f113cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f1140: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f1140u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1144: 0x9482000e  lhu         $v0, 0xE($a0)
    ctx->pc = 0x1f1144u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x1f1148: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1f1148u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1f114c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f114cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f1150: 0x431026  xor         $v0, $v0, $v1
    ctx->pc = 0x1f1150u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x1f1154: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1f1154u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1f1158: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1158u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f115c: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f115cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f1160: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f1160u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f1164: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1164u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F116Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
