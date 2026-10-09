#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1104
// Address: 0x1f1104 - 0x1f112c
void sub_001F1104_0x1f1104(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1104_0x1f1104");
#endif

    ctx->pc = 0x1f1104u;

    // 0x1f1104: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f1104u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f1108: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f1108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f110c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f110cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1110: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f1110u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1114: 0x9442000c  lhu         $v0, 0xC($v0)
    ctx->pc = 0x1f1114u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1f1118: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1118u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f111c: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f111cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f1120: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f1120u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f1124: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1124u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F112Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
