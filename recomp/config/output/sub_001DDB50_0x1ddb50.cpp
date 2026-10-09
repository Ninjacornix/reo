#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DDB50
// Address: 0x1ddb50 - 0x1ddd9c
void sub_001DDB50_0x1ddb50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DDB50_0x1ddb50");
#endif

    ctx->pc = 0x1ddb50u;

    // 0x1ddb50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ddb50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ddb54: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1ddb54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1ddb58: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1ddb58u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ddb5c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1ddb5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1ddb60: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1ddb60u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddb64: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddb64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddb68: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1ddb68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1ddb6c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ddb6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ddb70: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1ddb70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1ddb74: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddb74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddb78: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1ddb78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1ddb7c: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1ddb7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1ddb80: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1ddb80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ddb84: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ddb84u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ddb88: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddb88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddb8c: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1ddb8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1ddb90: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ddb90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ddb94: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddb94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddb98: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1ddb98u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1ddb9c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ddb9cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddba0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddba0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddba4: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1ddba4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1ddba8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1ddba8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1ddbac: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddbacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddbb0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ddbb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ddbb4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ddbb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddbb8: 0xaca20014  sw          $v0, 0x14($a1)
    ctx->pc = 0x1ddbb8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 2));
    // 0x1ddbbc: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1ddbbcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddbc0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddbc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddbc4: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1ddbc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1ddbc8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ddbc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ddbcc: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1ddbccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1ddbd0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddbd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddbd4: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1ddbd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1ddbd8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1ddbd8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1ddbdc: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1ddbdcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ddbe0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ddbe0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ddbe4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddbe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddbe8: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1ddbe8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1ddbec: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ddbecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ddbf0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddbf0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddbf4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1ddbf4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ddbf8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ddbf8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddbfc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddbfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddc00: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1ddc00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1ddc04: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1ddc04u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1ddc08: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddc08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddc0c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ddc0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ddc10: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ddc10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddc14: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x1ddc14u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x1ddc18: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1ddc18u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddc1c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddc1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddc20: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1ddc20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1ddc24: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ddc24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ddc28: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1ddc28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1ddc2c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddc2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddc30: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1ddc30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1ddc34: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1ddc34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1ddc38: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1ddc38u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ddc3c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ddc3cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ddc40: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddc40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddc44: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1ddc44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1ddc48: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ddc48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ddc4c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddc4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddc50: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1ddc50u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1ddc54: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ddc54u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddc58: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddc58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddc5c: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1ddc5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1ddc60: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1ddc60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1ddc64: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddc64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddc68: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ddc68u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ddc6c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ddc6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddc70: 0xaca20018  sw          $v0, 0x18($a1)
    ctx->pc = 0x1ddc70u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 2));
    // 0x1ddc74: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1ddc74u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddc78: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddc78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddc7c: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1ddc7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1ddc80: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ddc80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ddc84: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1ddc84u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1ddc88: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddc88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddc8c: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1ddc8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1ddc90: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1ddc90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1ddc94: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1ddc94u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ddc98: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ddc98u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ddc9c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddc9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddca0: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x1ddca0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1ddca4: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ddca4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ddca8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddca8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddcac: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1ddcacu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1ddcb0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ddcb0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddcb4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddcb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddcb8: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x1ddcb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1ddcbc: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1ddcbcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1ddcc0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddcc0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddcc4: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ddcc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ddcc8: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ddcc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddccc: 0xaca2001c  sw          $v0, 0x1C($a1)
    ctx->pc = 0x1ddcccu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 28), GPR_U32(ctx, 2));
    // 0x1ddcd0: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1ddcd0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddcd4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddcd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddcd8: 0x8c420020  lw          $v0, 0x20($v0)
    ctx->pc = 0x1ddcd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1ddcdc: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ddcdcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ddce0: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1ddce0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1ddce4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddce4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddce8: 0x8c420020  lw          $v0, 0x20($v0)
    ctx->pc = 0x1ddce8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1ddcec: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1ddcecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1ddcf0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1ddcf0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ddcf4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ddcf4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ddcf8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddcf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddcfc: 0x8c430020  lw          $v1, 0x20($v0)
    ctx->pc = 0x1ddcfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1ddd00: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ddd00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ddd04: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddd04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddd08: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1ddd08u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1ddd0c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ddd0cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddd10: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddd10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddd14: 0x8c430020  lw          $v1, 0x20($v0)
    ctx->pc = 0x1ddd14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1ddd18: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1ddd18u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1ddd1c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddd1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddd20: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ddd20u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ddd24: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ddd24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddd28: 0xaca20020  sw          $v0, 0x20($a1)
    ctx->pc = 0x1ddd28u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 32), GPR_U32(ctx, 2));
    // 0x1ddd2c: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1ddd2cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddd30: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddd30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddd34: 0x8c420024  lw          $v0, 0x24($v0)
    ctx->pc = 0x1ddd34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x1ddd38: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ddd38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ddd3c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1ddd3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1ddd40: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddd40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddd44: 0x8c420024  lw          $v0, 0x24($v0)
    ctx->pc = 0x1ddd44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x1ddd48: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1ddd48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1ddd4c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1ddd4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ddd50: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ddd50u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ddd54: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddd54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddd58: 0x8c430024  lw          $v1, 0x24($v0)
    ctx->pc = 0x1ddd58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x1ddd5c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ddd5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ddd60: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddd60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddd64: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1ddd64u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ddd68: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ddd68u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddd6c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddd6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddd70: 0x8c430024  lw          $v1, 0x24($v0)
    ctx->pc = 0x1ddd70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x1ddd74: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1ddd74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1ddd78: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddd78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddd7c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ddd7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ddd80: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ddd80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddd84: 0xaca20024  sw          $v0, 0x24($a1)
    ctx->pc = 0x1ddd84u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 36), GPR_U32(ctx, 2));
    // 0x1ddd88: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1ddd88u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ddd8c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1ddd8cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ddd90: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1ddd90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1ddd94: 0x3e00008  jr          $ra
    ctx->pc = 0x1DDD94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DDD9Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
