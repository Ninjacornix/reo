#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1B84
// Address: 0x1f1b84 - 0x1f1bac
void sub_001F1B84_0x1f1b84(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1B84_0x1f1b84");
#endif

    ctx->pc = 0x1f1b84u;

    // 0x1f1b84: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f1b84u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f1b88: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f1b88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f1b8c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1b8cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1b90: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f1b90u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1b94: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f1b94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f1b98: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1b98u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1b9c: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f1b9cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f1ba0: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f1ba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f1ba4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1BA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F1BACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
