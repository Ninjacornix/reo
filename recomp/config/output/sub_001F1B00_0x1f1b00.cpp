#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1B00
// Address: 0x1f1b00 - 0x1f1b34
void sub_001F1B00_0x1f1b00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1B00_0x1f1b00");
#endif

    ctx->pc = 0x1f1b00u;

    // 0x1f1b00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f1b00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f1b04: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f1b04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f1b08: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1b08u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1b0c: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1f1b0cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1b10: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1f1b10u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1b14: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f1b14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f1b18: 0xa462000c  sh          $v0, 0xC($v1)
    ctx->pc = 0x1f1b18u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1b1c: 0x9462000c  lhu         $v0, 0xC($v1)
    ctx->pc = 0x1f1b1cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x1f1b20: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1b20u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1b24: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f1b24u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f1b28: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f1b28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f1b2c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1B2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F1B34u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
