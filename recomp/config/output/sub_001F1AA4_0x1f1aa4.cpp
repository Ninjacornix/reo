#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1AA4
// Address: 0x1f1aa4 - 0x1f1ad8
void sub_001F1AA4_0x1f1aa4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1AA4_0x1f1aa4");
#endif

    ctx->pc = 0x1f1aa4u;

    // 0x1f1aa4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f1aa4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f1aa8: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f1aa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f1aac: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1aacu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1ab0: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1f1ab0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1ab4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1f1ab4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1ab8: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f1ab8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f1abc: 0xa462000a  sh          $v0, 0xA($v1)
    ctx->pc = 0x1f1abcu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 10), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1ac0: 0x9462000a  lhu         $v0, 0xA($v1)
    ctx->pc = 0x1f1ac0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 10)));
    // 0x1f1ac4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1ac4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1ac8: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f1ac8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f1acc: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f1accu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f1ad0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1AD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F1AD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
