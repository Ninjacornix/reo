#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DDE78
// Address: 0x1dde78 - 0x1ddef8
void sub_001DDE78_0x1dde78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DDE78_0x1dde78");
#endif

    ctx->pc = 0x1dde78u;

    // 0x1dde78: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1dde78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1dde7c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1dde7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1dde80: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1dde80u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dde84: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1dde84u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dde88: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1dde88u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dde8c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dde8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dde90: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dde90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dde94: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1dde94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1dde98: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1dde98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dde9c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dde9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddea0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1ddea0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ddea4: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1ddea4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1ddea8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1ddea8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ddeac: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ddeacu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ddeb0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddeb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddeb4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ddeb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ddeb8: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ddeb8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ddebc: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddebcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddec0: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1ddec0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ddec4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ddec4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddec8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddec8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddecc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ddeccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dded0: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1dded0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1dded4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dded4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dded8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1dded8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ddedc: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ddedcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddee0: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1ddee0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1ddee4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1ddee4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ddee8: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1ddee8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ddeec: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1ddeecu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1ddef0: 0x3e00008  jr          $ra
    ctx->pc = 0x1DDEF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DDEF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
