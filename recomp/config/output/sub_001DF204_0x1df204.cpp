#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DF204
// Address: 0x1df204 - 0x1df2e0
void sub_001DF204_0x1df204(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DF204_0x1df204");
#endif

    ctx->pc = 0x1df204u;

    // 0x1df204: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1df204u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1df208: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1df208u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1df20c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1df20cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df210: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1df210u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1df214: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1df214u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df218: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df218u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df21c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1df21cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df220: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df220u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df224: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df224u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df228: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df228u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df22c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1df22cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df230: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df230u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df234: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df234u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df238: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df238u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df23c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df23cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df240: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1df240u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df244: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df244u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df248: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df248u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df24c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df24cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df250: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df250u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df254: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df254u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df258: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1df258u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df25c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df25cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df260: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df260u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df264: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df264u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df268: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df268u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df26c: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1df26cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1df270: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1df270u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df274: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df274u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df278: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1df278u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df27c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df27cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df280: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df280u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df284: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df284u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df288: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1df288u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df28c: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df28cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df290: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df290u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df294: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df294u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df298: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df298u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df29c: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1df29cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df2a0: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df2a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df2a4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df2a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df2a8: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df2a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df2ac: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df2acu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df2b0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df2b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df2b4: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1df2b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df2b8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df2bc: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df2bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df2c0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df2c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df2c4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df2c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df2c8: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1df2c8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1df2cc: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1df2ccu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df2d0: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1df2d0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1df2d4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1df2d4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1df2d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1DF2D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DF2E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
