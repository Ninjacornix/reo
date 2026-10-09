#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DED88
// Address: 0x1ded88 - 0x1def1c
void sub_001DED88_0x1ded88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DED88_0x1ded88");
#endif

    ctx->pc = 0x1ded88u;

    // 0x1ded88: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ded88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ded8c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1ded8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1ded90: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1ded90u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ded94: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1ded94u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1ded98: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1ded98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ded9c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ded9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1deda0: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1deda0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1deda4: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1deda4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1deda8: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1deda8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dedac: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dedacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dedb0: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1dedb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1dedb4: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1dedb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1dedb8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1dedb8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dedbc: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1dedbcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1dedc0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dedc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dedc4: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1dedc4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1dedc8: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1dedc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1dedcc: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dedccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dedd0: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1dedd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1dedd4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1dedd4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dedd8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dedd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1deddc: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1deddcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1dede0: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1dede0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1dede4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dede4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dede8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1dede8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dedec: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1dedecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dedf0: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x1dedf0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x1dedf4: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1dedf4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dedf8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dedf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dedfc: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1dedfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1dee00: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1dee00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1dee04: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1dee04u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dee08: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dee08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dee0c: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1dee0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1dee10: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1dee10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1dee14: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1dee14u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dee18: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1dee18u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1dee1c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dee1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dee20: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1dee20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1dee24: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1dee24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1dee28: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dee28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dee2c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1dee2cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1dee30: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1dee30u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dee34: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dee34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dee38: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1dee38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1dee3c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1dee3cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1dee40: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dee40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dee44: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1dee44u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dee48: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1dee48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dee4c: 0xaca20014  sw          $v0, 0x14($a1)
    ctx->pc = 0x1dee4cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 2));
    // 0x1dee50: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1dee50u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dee54: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dee54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dee58: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1dee58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1dee5c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1dee5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1dee60: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1dee60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dee64: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dee64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dee68: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1dee68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1dee6c: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1dee6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1dee70: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1dee70u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dee74: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1dee74u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1dee78: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dee78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dee7c: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1dee7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1dee80: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1dee80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1dee84: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dee84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dee88: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1dee88u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1dee8c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1dee8cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dee90: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dee90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dee94: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1dee94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1dee98: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1dee98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1dee9c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dee9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1deea0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1deea0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1deea4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1deea4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1deea8: 0xaca20018  sw          $v0, 0x18($a1)
    ctx->pc = 0x1deea8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 2));
    // 0x1deeac: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1deeacu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1deeb0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1deeb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1deeb4: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1deeb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1deeb8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1deeb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1deebc: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1deebcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1deec0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1deec0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1deec4: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1deec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1deec8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1deec8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1deecc: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1deeccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1deed0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1deed0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1deed4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1deed4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1deed8: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x1deed8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1deedc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1deedcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1deee0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1deee0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1deee4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1deee4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1deee8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1deee8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1deeec: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1deeecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1deef0: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x1deef0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1deef4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1deef4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1deef8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1deef8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1deefc: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1deefcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1def00: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1def00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1def04: 0xaca2001c  sw          $v0, 0x1C($a1)
    ctx->pc = 0x1def04u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 28), GPR_U32(ctx, 2));
    // 0x1def08: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1def08u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1def0c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1def0cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1def10: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1def10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1def14: 0x3e00008  jr          $ra
    ctx->pc = 0x1DEF14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DEF1Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
