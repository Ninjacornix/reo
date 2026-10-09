#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E81C4
// Address: 0x1e81c4 - 0x1e820c
void sub_001E81C4_0x1e81c4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E81C4_0x1e81c4");
#endif

    ctx->pc = 0x1e81c4u;

    // 0x1e81c4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1e81c4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1e81c8: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1e81c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1e81cc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e81ccu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e81d0: 0x41600  sll         $v0, $a0, 24
    ctx->pc = 0x1e81d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x1e81d4: 0x3083ff00  andi        $v1, $a0, 0xFF00
    ctx->pc = 0x1e81d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65280);
    // 0x1e81d8: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1e81d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1e81dc: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1e81dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1e81e0: 0x3c0300ff  lui         $v1, 0xFF
    ctx->pc = 0x1e81e0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)255 << 16));
    // 0x1e81e4: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x1e81e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1e81e8: 0x31a02  srl         $v1, $v1, 8
    ctx->pc = 0x1e81e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
    // 0x1e81ec: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1e81ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1e81f0: 0x41e02  srl         $v1, $a0, 24
    ctx->pc = 0x1e81f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x1e81f4: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1e81f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1e81f8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e81f8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e81fc: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1e81fcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1e8200: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1e8200u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1e8204: 0x3e00008  jr          $ra
    ctx->pc = 0x1E8204u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1E820Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
