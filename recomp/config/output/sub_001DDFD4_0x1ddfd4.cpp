#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DDFD4
// Address: 0x1ddfd4 - 0x1de1c4
void sub_001DDFD4_0x1ddfd4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DDFD4_0x1ddfd4");
#endif

    ctx->pc = 0x1ddfd4u;

    // 0x1ddfd4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ddfd4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ddfd8: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1ddfd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1ddfdc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1ddfdcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ddfe0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1ddfe0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1ddfe4: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1ddfe4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddfe8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddfe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddfec: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1ddfecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1ddff0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ddff0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ddff4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1ddff4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1ddff8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ddff8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ddffc: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1ddffcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1de000: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de000u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de004: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de004u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de008: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de008u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de00c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de00cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de010: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1de010u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1de014: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de014u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de018: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de018u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de01c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de01cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de020: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de020u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de024: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de024u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de028: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1de028u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1de02c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de02cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de030: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de030u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de034: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de034u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de038: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de038u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de03c: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x1de03cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x1de040: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de040u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de044: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de044u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de048: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1de048u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1de04c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de04cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de050: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de050u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de054: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de058: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1de058u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1de05c: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de05cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de060: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de060u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de064: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de064u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de068: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de068u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de06c: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1de06cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1de070: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de070u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de074: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de074u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de078: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de078u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de07c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de07cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de080: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de080u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de084: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1de084u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1de088: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de088u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de08c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de08cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de090: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de090u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de094: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de094u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de098: 0xaca20014  sw          $v0, 0x14($a1)
    ctx->pc = 0x1de098u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 2));
    // 0x1de09c: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de09cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de0a0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de0a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de0a4: 0x8c420020  lw          $v0, 0x20($v0)
    ctx->pc = 0x1de0a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1de0a8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de0a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de0ac: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de0acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de0b0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de0b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de0b4: 0x8c420020  lw          $v0, 0x20($v0)
    ctx->pc = 0x1de0b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1de0b8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de0b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de0bc: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de0bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de0c0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de0c0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de0c4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de0c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de0c8: 0x8c430020  lw          $v1, 0x20($v0)
    ctx->pc = 0x1de0c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1de0cc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de0ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de0d0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de0d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de0d4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de0d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de0d8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de0d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de0dc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de0dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de0e0: 0x8c430020  lw          $v1, 0x20($v0)
    ctx->pc = 0x1de0e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1de0e4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de0e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de0e8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de0e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de0ec: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de0ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de0f0: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de0f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de0f4: 0xaca20020  sw          $v0, 0x20($a1)
    ctx->pc = 0x1de0f4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 32), GPR_U32(ctx, 2));
    // 0x1de0f8: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de0f8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de0fc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de0fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de100: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1de100u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de104: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de104u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de108: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de108u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de10c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de10cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de110: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1de110u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de114: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de114u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de118: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de118u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de11c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de11cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de120: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de120u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de124: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1de124u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de128: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de128u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de12c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de12cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de130: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de130u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de134: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de134u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de138: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de138u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de13c: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1de13cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de140: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de140u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de144: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de144u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de148: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de148u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de14c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de14cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de150: 0xaca20018  sw          $v0, 0x18($a1)
    ctx->pc = 0x1de150u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 2));
    // 0x1de154: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de154u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de158: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de158u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de15c: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1de15cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1de160: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de160u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de164: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de164u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de168: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de168u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de16c: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1de16cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1de170: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de170u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de174: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de174u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de178: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de178u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de17c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de17cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de180: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x1de180u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1de184: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de184u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de188: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de188u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de18c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de18cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de190: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de190u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de194: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de194u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de198: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x1de198u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1de19c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de19cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de1a0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de1a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de1a4: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de1a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de1a8: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de1a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de1ac: 0xaca2001c  sw          $v0, 0x1C($a1)
    ctx->pc = 0x1de1acu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 28), GPR_U32(ctx, 2));
    // 0x1de1b0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1de1b0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de1b4: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1de1b4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1de1b8: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1de1b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1de1bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1DE1BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DE1C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
