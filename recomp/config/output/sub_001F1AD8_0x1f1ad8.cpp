#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1AD8
// Address: 0x1f1ad8 - 0x1f1b00
void sub_001F1AD8_0x1f1ad8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1AD8_0x1f1ad8");
#endif

    ctx->pc = 0x1f1ad8u;

    // 0x1f1ad8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f1ad8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f1adc: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f1adcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f1ae0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1ae0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1ae4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f1ae4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1ae8: 0x9442000c  lhu         $v0, 0xC($v0)
    ctx->pc = 0x1f1ae8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1f1aec: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1aecu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1af0: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f1af0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f1af4: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f1af4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f1af8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1AF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F1B00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
