#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E817C
// Address: 0x1e817c - 0x1e81c4
void sub_001E817C_0x1e817c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E817C_0x1e817c");
#endif

    ctx->pc = 0x1e817cu;

    // 0x1e817c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1e817cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1e8180: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1e8180u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1e8184: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e8184u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8188: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1e8188u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e818c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e818cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e8190: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8190u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8194: 0x3062ffff  andi        $v0, $v1, 0xFFFF
    ctx->pc = 0x1e8194u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1e8198: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e8198u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e819c: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1e819cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1e81a0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e81a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e81a4: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e81a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e81a8: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e81a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e81ac: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e81acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e81b0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e81b0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e81b4: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1e81b4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1e81b8: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1e81b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1e81bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1E81BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1E81C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
