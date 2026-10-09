#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E7BB8
// Address: 0x1e7bb8 - 0x1e7c00
void sub_001E7BB8_0x1e7bb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E7BB8_0x1e7bb8");
#endif

    ctx->pc = 0x1e7bb8u;

    // 0x1e7bb8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e7bb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e7bbc: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e7bbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e7bc0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e7bc0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7bc4: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1e7bc4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1e7bc8: 0x24428ca0  addiu       $v0, $v0, -0x7360
    ctx->pc = 0x1e7bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937760));
    // 0x1e7bcc: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x1e7bccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x1e7bd0: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e7bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7bd4: 0x3402cb18  ori         $v0, $zero, 0xCB18
    ctx->pc = 0x1e7bd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)51992);
    // 0x1e7bd8: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1e7bd8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1e7bdc: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e7bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7be0: 0x3c02fafa  lui         $v0, 0xFAFA
    ctx->pc = 0x1e7be0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)64250 << 16));
    // 0x1e7be4: 0x3442fafa  ori         $v0, $v0, 0xFAFA
    ctx->pc = 0x1e7be4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64250);
    // 0x1e7be8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e7be8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e7bec: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e7becu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7bf0: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e7bf0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e7bf4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e7bf4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e7bf8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E7BF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1E7C00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
