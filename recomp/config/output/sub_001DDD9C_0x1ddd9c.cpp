#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DDD9C
// Address: 0x1ddd9c - 0x1dde78
void sub_001DDD9C_0x1ddd9c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DDD9C_0x1ddd9c");
#endif

    ctx->pc = 0x1ddd9cu;

    // 0x1ddd9c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ddd9cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ddda0: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1ddda0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1ddda4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1ddda4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ddda8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1ddda8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dddac: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1dddacu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dddb0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dddb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dddb4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dddb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dddb8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1dddb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1dddbc: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1dddbcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dddc0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dddc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dddc4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dddc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dddc8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1dddc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1dddcc: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1dddccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dddd0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1dddd0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1dddd4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dddd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dddd8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1dddd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ddddc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ddddcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ddde0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddde0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddde4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1ddde4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ddde8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ddde8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dddec: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dddecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dddf0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1dddf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dddf4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1dddf4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1dddf8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dddf8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dddfc: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1dddfcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dde00: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1dde00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dde04: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1dde04u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1dde08: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1dde08u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dde0c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dde0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dde10: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1dde10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dde14: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1dde14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1dde18: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1dde18u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dde1c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dde1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dde20: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1dde20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dde24: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1dde24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1dde28: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1dde28u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dde2c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1dde2cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1dde30: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dde30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dde34: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1dde34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dde38: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1dde38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1dde3c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dde3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dde40: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1dde40u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1dde44: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1dde44u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dde48: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dde48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dde4c: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1dde4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dde50: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1dde50u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1dde54: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dde54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dde58: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1dde58u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dde5c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1dde5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dde60: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1dde60u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1dde64: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dde64u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dde68: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1dde68u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1dde6c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1dde6cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1dde70: 0x3e00008  jr          $ra
    ctx->pc = 0x1DDE70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DDE78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
