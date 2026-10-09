#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DEFF0
// Address: 0x1deff0 - 0x1df184
void sub_001DEFF0_0x1deff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DEFF0_0x1deff0");
#endif

    ctx->pc = 0x1deff0u;

    // 0x1deff0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1deff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1deff4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1deff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1deff8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1deff8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1deffc: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1deffcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1df000: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1df000u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df004: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df004u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df008: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1df008u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df00c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df00cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df010: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df010u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df014: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df014u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df018: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1df018u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df01c: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df01cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df020: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df020u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df024: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df024u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df028: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df028u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df02c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1df02cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df030: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df030u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df034: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df034u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df038: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df038u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df03c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df03cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df040: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df040u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df044: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1df044u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df048: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df048u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df04c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df04cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df050: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df050u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df054: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df054u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df058: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1df058u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1df05c: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1df05cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df060: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df060u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df064: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1df064u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df068: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df068u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df06c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df06cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df070: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df070u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df074: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1df074u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df078: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df078u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df07c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df07cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df080: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df080u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df084: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df084u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df088: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1df088u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df08c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df08cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df090: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df090u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df094: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df094u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df098: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df098u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df09c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df09cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df0a0: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1df0a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df0a4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df0a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df0a8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df0a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df0ac: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df0acu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df0b0: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df0b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df0b4: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1df0b4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1df0b8: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1df0b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df0bc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df0bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df0c0: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1df0c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1df0c4: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df0c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df0c8: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df0c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df0cc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df0ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df0d0: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1df0d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1df0d4: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df0d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df0d8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df0d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df0dc: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df0dcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df0e0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df0e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df0e4: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1df0e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1df0e8: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df0e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df0ec: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df0ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df0f0: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df0f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df0f4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df0f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df0f8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df0f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df0fc: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1df0fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1df100: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df100u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df104: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df104u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df108: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df108u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df10c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df10cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df110: 0xaca20008  sw          $v0, 0x8($a1)
    ctx->pc = 0x1df110u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
    // 0x1df114: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1df114u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df118: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df118u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df11c: 0x8c42000c  lw          $v0, 0xC($v0)
    ctx->pc = 0x1df11cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1df120: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df120u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df124: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df124u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df128: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df128u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df12c: 0x8c42000c  lw          $v0, 0xC($v0)
    ctx->pc = 0x1df12cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1df130: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df130u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df134: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df134u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df138: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df138u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df13c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df13cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df140: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x1df140u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1df144: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df144u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df148: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df148u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df14c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df14cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df150: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df150u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df154: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df154u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df158: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x1df158u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1df15c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df15cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df160: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df160u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df164: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df164u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df168: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df168u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df16c: 0xaca2000c  sw          $v0, 0xC($a1)
    ctx->pc = 0x1df16cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 2));
    // 0x1df170: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1df170u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df174: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1df174u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1df178: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1df178u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1df17c: 0x3e00008  jr          $ra
    ctx->pc = 0x1DF17Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DF184u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
