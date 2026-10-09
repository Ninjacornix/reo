#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1A40
// Address: 0x1f1a40 - 0x1f1a7c
void sub_001F1A40_0x1f1a40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1A40_0x1f1a40");
#endif

    ctx->pc = 0x1f1a40u;

    // 0x1f1a40: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f1a40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f1a44: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f1a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f1a48: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1a48u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1a4c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1f1a4cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1a50: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f1a50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f1a54: 0x21027  nor         $v0, $zero, $v0
    ctx->pc = 0x1f1a54u;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x1f1a58: 0x9483000e  lhu         $v1, 0xE($a0)
    ctx->pc = 0x1f1a58u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x1f1a5c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1f1a5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1f1a60: 0xa482000e  sh          $v0, 0xE($a0)
    ctx->pc = 0x1f1a60u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1a64: 0x9482000e  lhu         $v0, 0xE($a0)
    ctx->pc = 0x1f1a64u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x1f1a68: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1a68u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1a6c: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f1a6cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f1a70: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f1a70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f1a74: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1A74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F1A7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
