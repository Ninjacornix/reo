#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DED08
// Address: 0x1ded08 - 0x1ded88
void sub_001DED08_0x1ded08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DED08_0x1ded08");
#endif

    ctx->pc = 0x1ded08u;

    // 0x1ded08: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ded08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ded0c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1ded0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1ded10: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1ded10u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ded14: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1ded14u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1ded18: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1ded18u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ded1c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ded1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ded20: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1ded20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1ded24: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ded24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ded28: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1ded28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1ded2c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ded2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ded30: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1ded30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1ded34: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1ded34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1ded38: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1ded38u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ded3c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ded3cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ded40: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ded40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ded44: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1ded44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1ded48: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ded48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ded4c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ded4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ded50: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1ded50u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ded54: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ded54u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ded58: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ded58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ded5c: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1ded5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1ded60: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1ded60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1ded64: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ded64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ded68: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ded68u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ded6c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ded6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ded70: 0xaca20008  sw          $v0, 0x8($a1)
    ctx->pc = 0x1ded70u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
    // 0x1ded74: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1ded74u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ded78: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1ded78u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ded7c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1ded7cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1ded80: 0x3e00008  jr          $ra
    ctx->pc = 0x1DED80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DED88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
