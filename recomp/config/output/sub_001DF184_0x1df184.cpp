#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DF184
// Address: 0x1df184 - 0x1df204
void sub_001DF184_0x1df184(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DF184_0x1df184");
#endif

    ctx->pc = 0x1df184u;

    // 0x1df184: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1df184u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1df188: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1df188u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1df18c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1df18cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df190: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1df190u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1df194: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1df194u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df198: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df198u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df19c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1df19cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df1a0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df1a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df1a4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df1a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df1a8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df1a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df1ac: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1df1acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df1b0: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df1b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df1b4: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df1b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df1b8: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df1b8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df1bc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df1bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df1c0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1df1c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df1c4: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df1c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df1c8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df1c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df1cc: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df1ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df1d0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df1d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df1d4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df1d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df1d8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1df1d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df1dc: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df1dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df1e0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df1e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df1e4: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df1e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df1e8: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df1e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df1ec: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1df1ecu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1df1f0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1df1f0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df1f4: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1df1f4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1df1f8: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1df1f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1df1fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1DF1FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DF204u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
