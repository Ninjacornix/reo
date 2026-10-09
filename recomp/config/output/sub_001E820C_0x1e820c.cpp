#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E820C
// Address: 0x1e820c - 0x1e8254
void sub_001E820C_0x1e820c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E820C_0x1e820c");
#endif

    ctx->pc = 0x1e820cu;

    // 0x1e820c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1e820cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1e8210: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1e8210u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1e8214: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e8214u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8218: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1e8218u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e821c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e821cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e8220: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8220u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8224: 0x3062ffff  andi        $v0, $v1, 0xFFFF
    ctx->pc = 0x1e8224u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1e8228: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e8228u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e822c: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1e822cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1e8230: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e8230u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8234: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e8234u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8238: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e8238u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e823c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e823cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e8240: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e8240u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8244: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1e8244u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1e8248: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1e8248u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1e824c: 0x3e00008  jr          $ra
    ctx->pc = 0x1E824Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1E8254u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
