#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1A7C
// Address: 0x1f1a7c - 0x1f1aa4
void sub_001F1A7C_0x1f1a7c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1A7C_0x1f1a7c");
#endif

    ctx->pc = 0x1f1a7cu;

    // 0x1f1a7c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f1a7cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f1a80: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f1a80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f1a84: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1a84u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1a88: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f1a88u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1a8c: 0x9442000a  lhu         $v0, 0xA($v0)
    ctx->pc = 0x1f1a8cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 10)));
    // 0x1f1a90: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1a90u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1a94: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f1a94u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f1a98: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f1a98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f1a9c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1A9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F1AA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
