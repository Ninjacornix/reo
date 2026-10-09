#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DE540
// Address: 0x1de540 - 0x1de678
void sub_001DE540_0x1de540(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DE540_0x1de540");
#endif

    ctx->pc = 0x1de540u;

    // 0x1de540: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1de540u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1de544: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1de544u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1de548: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1de548u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de54c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1de54cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1de550: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de550u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de554: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de554u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de558: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1de558u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1de55c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de55cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de560: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de560u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de564: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de564u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de568: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1de568u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1de56c: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de56cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de570: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de570u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de574: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de574u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de578: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de578u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de57c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1de57cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1de580: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de580u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de584: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de584u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de588: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de588u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de58c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de58cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de590: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de590u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de594: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1de594u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1de598: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de598u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de59c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de59cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de5a0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de5a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de5a4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de5a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de5a8: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1de5a8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1de5ac: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de5acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de5b0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de5b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de5b4: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1de5b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1de5b8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de5b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de5bc: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de5bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de5c0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de5c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de5c4: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1de5c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1de5c8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de5c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de5cc: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de5ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de5d0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de5d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de5d4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de5d8: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1de5d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1de5dc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de5dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de5e0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de5e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de5e4: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1de5e4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1de5e8: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de5e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de5ec: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de5ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de5f0: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1de5f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1de5f4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de5f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de5f8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de5f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de5fc: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de5fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de600: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de600u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de604: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1de604u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1de608: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de608u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de60c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de60cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de610: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de610u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de614: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de614u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de618: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de618u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de61c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de61cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de620: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de620u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de624: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de624u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de628: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de628u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de62c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de62cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de630: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de630u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de634: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1de634u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de638: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de638u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de63c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de63cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de640: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1de640u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1de644: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de644u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de648: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de648u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de64c: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1de64cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de650: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de650u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de654: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de654u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de658: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de658u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de65c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de65cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de660: 0xaca20008  sw          $v0, 0x8($a1)
    ctx->pc = 0x1de660u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
    // 0x1de664: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1de664u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de668: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1de668u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1de66c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1de66cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1de670: 0x3e00008  jr          $ra
    ctx->pc = 0x1DE670u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1DE678u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
