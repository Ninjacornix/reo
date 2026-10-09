#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DE74C
// Address: 0x1de74c - 0x1de828
void sub_001DE74C_0x1de74c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DE74C_0x1de74c");
#endif

    ctx->pc = 0x1de74cu;

    // 0x1de74c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1de74cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1de750: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1de750u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1de754: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1de754u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de758: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1de758u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1de75c: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de75cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de760: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de760u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de764: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1de764u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1de768: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de768u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de76c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de76cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de770: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de770u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de774: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1de774u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1de778: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de778u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de77c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de77cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de780: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de780u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de784: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de784u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de788: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1de788u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1de78c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de78cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de790: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de790u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de794: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de794u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de798: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de798u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de79c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de79cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de7a0: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1de7a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1de7a4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de7a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de7a8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de7a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de7ac: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de7acu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de7b0: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de7b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de7b4: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x1de7b4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x1de7b8: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de7b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de7bc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de7bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de7c0: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1de7c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de7c4: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de7c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de7c8: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de7c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de7cc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de7ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de7d0: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1de7d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de7d4: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de7d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de7d8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de7d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de7dc: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de7dcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de7e0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de7e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de7e4: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1de7e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de7e8: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de7e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de7ec: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de7ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de7f0: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de7f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de7f4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de7f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de7f8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de7f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de7fc: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1de7fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1de800: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de800u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de804: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de804u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de808: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de808u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de80c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de80cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de810: 0xaca20018  sw          $v0, 0x18($a1)
    ctx->pc = 0x1de810u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 2));
    // 0x1de814: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1de814u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de818: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1de818u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1de81c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1de81cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1de820: 0x3e00008  jr          $ra
    ctx->pc = 0x1DE820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DE828u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
