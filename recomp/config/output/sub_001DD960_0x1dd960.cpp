#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DD960
// Address: 0x1dd960 - 0x1ddb50
void sub_001DD960_0x1dd960(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DD960_0x1dd960");
#endif

    ctx->pc = 0x1dd960u;

    // 0x1dd960: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1dd960u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1dd964: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1dd964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1dd968: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1dd968u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd96c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1dd96cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dd970: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1dd970u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd974: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dd974u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd978: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1dd978u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1dd97c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1dd97cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1dd980: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1dd980u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dd984: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dd984u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd988: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1dd988u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1dd98c: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1dd98cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1dd990: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1dd990u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dd994: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1dd994u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1dd998: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dd998u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd99c: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1dd99cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1dd9a0: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1dd9a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1dd9a4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dd9a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dd9a8: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1dd9a8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1dd9ac: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1dd9acu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dd9b0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dd9b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd9b4: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1dd9b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1dd9b8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1dd9b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1dd9bc: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dd9bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dd9c0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1dd9c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dd9c4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1dd9c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dd9c8: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x1dd9c8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x1dd9cc: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1dd9ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd9d0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dd9d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd9d4: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1dd9d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1dd9d8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1dd9d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1dd9dc: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1dd9dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dd9e0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dd9e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd9e4: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1dd9e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1dd9e8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1dd9e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1dd9ec: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1dd9ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dd9f0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1dd9f0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1dd9f4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dd9f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd9f8: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1dd9f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1dd9fc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1dd9fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1dda00: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dda00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dda04: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1dda04u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1dda08: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1dda08u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dda0c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dda0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dda10: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1dda10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1dda14: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1dda14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1dda18: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dda18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dda1c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1dda1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dda20: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1dda20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dda24: 0xaca20014  sw          $v0, 0x14($a1)
    ctx->pc = 0x1dda24u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 2));
    // 0x1dda28: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1dda28u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dda2c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dda2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dda30: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1dda30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1dda34: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1dda34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1dda38: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1dda38u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dda3c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dda3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dda40: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1dda40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1dda44: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1dda44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1dda48: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1dda48u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dda4c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1dda4cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1dda50: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dda50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dda54: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1dda54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1dda58: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1dda58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1dda5c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dda5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dda60: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1dda60u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1dda64: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1dda64u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dda68: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dda68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dda6c: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1dda6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1dda70: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1dda70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1dda74: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1dda74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1dda78: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1dda78u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dda7c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1dda7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1dda80: 0xaca20018  sw          $v0, 0x18($a1)
    ctx->pc = 0x1dda80u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 2));
    // 0x1dda84: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1dda84u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dda88: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dda88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dda8c: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1dda8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1dda90: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1dda90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1dda94: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1dda94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dda98: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dda98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dda9c: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1dda9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1ddaa0: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1ddaa0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1ddaa4: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1ddaa4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ddaa8: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ddaa8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ddaac: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddaacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddab0: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x1ddab0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1ddab4: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ddab4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ddab8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddab8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddabc: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1ddabcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1ddac0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ddac0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddac4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddac4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddac8: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x1ddac8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1ddacc: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1ddaccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1ddad0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddad0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddad4: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ddad4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ddad8: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ddad8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddadc: 0xaca2001c  sw          $v0, 0x1C($a1)
    ctx->pc = 0x1ddadcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 28), GPR_U32(ctx, 2));
    // 0x1ddae0: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1ddae0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddae4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddae4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddae8: 0x8c420020  lw          $v0, 0x20($v0)
    ctx->pc = 0x1ddae8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1ddaec: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ddaecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ddaf0: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1ddaf0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1ddaf4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddaf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddaf8: 0x8c420020  lw          $v0, 0x20($v0)
    ctx->pc = 0x1ddaf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1ddafc: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1ddafcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1ddb00: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1ddb00u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ddb04: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ddb04u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ddb08: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddb08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddb0c: 0x8c430020  lw          $v1, 0x20($v0)
    ctx->pc = 0x1ddb0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1ddb10: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1ddb10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1ddb14: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddb14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddb18: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1ddb18u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ddb1c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1ddb1cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddb20: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddb20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddb24: 0x8c430020  lw          $v1, 0x20($v0)
    ctx->pc = 0x1ddb24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1ddb28: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1ddb28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1ddb2c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ddb2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ddb30: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ddb30u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ddb34: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ddb34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ddb38: 0xaca20020  sw          $v0, 0x20($a1)
    ctx->pc = 0x1ddb38u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 32), GPR_U32(ctx, 2));
    // 0x1ddb3c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1ddb3cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ddb40: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1ddb40u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ddb44: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1ddb44u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1ddb48: 0x3e00008  jr          $ra
    ctx->pc = 0x1DDB48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DDB50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
