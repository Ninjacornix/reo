#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F2AE0
// Address: 0x1f2ae0 - 0x1f2b08
void sub_001F2AE0_0x1f2ae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F2AE0_0x1f2ae0");
#endif

    ctx->pc = 0x1f2ae0u;

    // 0x1f2ae0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f2ae0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f2ae4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f2ae4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f2ae8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f2ae8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2aec: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f2aecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f2af0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f2af0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2af4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f2af4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2af8: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f2af8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f2afc: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f2afcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f2b00: 0x3e00008  jr          $ra
    ctx->pc = 0x1F2B00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F2B08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
