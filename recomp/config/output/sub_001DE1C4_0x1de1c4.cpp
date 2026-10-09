#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DE1C4
// Address: 0x1de1c4 - 0x1de2fc
void sub_001DE1C4_0x1de1c4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DE1C4_0x1de1c4");
#endif

    ctx->pc = 0x1de1c4u;

    // 0x1de1c4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1de1c4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1de1c8: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1de1c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1de1cc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1de1ccu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de1d0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1de1d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1de1d4: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de1d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de1d8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de1d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de1dc: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1de1dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1de1e0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de1e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de1e4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de1e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de1e8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de1e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de1ec: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1de1ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1de1f0: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de1f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de1f4: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de1f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de1f8: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de1f8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de1fc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de1fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de200: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1de200u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1de204: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de204u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de208: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de208u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de20c: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1de20cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1de210: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de210u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de214: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de214u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de218: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1de218u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1de21c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de21cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de220: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de220u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de224: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de224u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de228: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de228u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de22c: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x1de22cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x1de230: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de230u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de234: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de234u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de238: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1de238u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1de23c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de23cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de240: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de240u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de244: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de244u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de248: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1de248u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1de24c: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de24cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de250: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de250u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de254: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de254u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de258: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de258u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de25c: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1de25cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1de260: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de260u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de264: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de264u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de268: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1de268u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1de26c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de26cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de270: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de270u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de274: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x1de274u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1de278: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de278u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de27c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de27cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de280: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de280u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de284: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de284u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de288: 0xaca20014  sw          $v0, 0x14($a1)
    ctx->pc = 0x1de288u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 2));
    // 0x1de28c: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de28cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de290: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de290u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de294: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1de294u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de298: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de298u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de29c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de29cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de2a0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de2a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de2a4: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1de2a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de2a8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de2a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de2ac: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de2acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de2b0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de2b0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de2b4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de2b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de2b8: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1de2b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de2bc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de2bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de2c0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de2c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de2c4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de2c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de2c8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de2c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de2cc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de2ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de2d0: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1de2d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de2d4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de2d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de2d8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de2d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de2dc: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de2dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de2e0: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de2e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de2e4: 0xaca20018  sw          $v0, 0x18($a1)
    ctx->pc = 0x1de2e4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 2));
    // 0x1de2e8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1de2e8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de2ec: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1de2ecu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1de2f0: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1de2f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1de2f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1DE2F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DE2FCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
