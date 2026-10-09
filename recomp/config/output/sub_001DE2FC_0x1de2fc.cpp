#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DE2FC
// Address: 0x1de2fc - 0x1de44c
void sub_001DE2FC_0x1de2fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DE2FC_0x1de2fc");
#endif

    ctx->pc = 0x1de2fcu;

    // 0x1de2fc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1de2fcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1de300: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1de300u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1de304: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1de304u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de308: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1de308u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1de30c: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de30cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de310: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de310u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de314: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1de314u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1de318: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de318u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de31c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de31cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de320: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de320u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de324: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1de324u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1de328: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de328u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de32c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de32cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de330: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de330u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de334: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de334u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de338: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1de338u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1de33c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de33cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de340: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de340u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de344: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de344u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de348: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de348u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de34c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de34cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de350: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1de350u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1de354: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de354u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de358: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de358u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de35c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de35cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de360: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de360u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de364: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1de364u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1de368: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de368u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de36c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de36cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de370: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1de370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1de374: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de374u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de378: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de378u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de37c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de37cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de380: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1de380u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1de384: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de384u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de388: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de388u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de38c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de38cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de390: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de390u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de394: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1de394u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1de398: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de398u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de39c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de39cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de3a0: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de3a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de3a4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de3a4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de3a8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de3a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de3ac: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1de3acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1de3b0: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de3b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de3b4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de3b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de3b8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de3b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de3bc: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de3bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de3c0: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1de3c0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1de3c4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de3c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de3c8: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1de3c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1de3cc: 0x3c024e41  lui         $v0, 0x4E41
    ctx->pc = 0x1de3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20033 << 16));
    // 0x1de3d0: 0x34424d45  ori         $v0, $v0, 0x4D45
    ctx->pc = 0x1de3d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19781);
    // 0x1de3d4: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1DE3D4u;
    {
        const bool branch_taken_0x1de3d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1de3d4) {
            ctx->pc = 0x1DE438u;
            goto label_1de438;
        }
    }
    ctx->pc = 0x1DE3DCu;
    // 0x1de3dc: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de3dcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de3e0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de3e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de3e4: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de3e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de3e8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de3e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de3ec: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de3ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de3f0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de3f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de3f4: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de3f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de3f8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de3f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de3fc: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de3fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de400: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de400u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de404: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de404u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de408: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1de408u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de40c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de40cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de410: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de410u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de414: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de414u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de418: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de418u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de41c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de41cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de420: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1de420u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de424: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de424u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de428: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de428u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de42c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de42cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de430: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de430u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de434: 0xaca20008  sw          $v0, 0x8($a1)
    ctx->pc = 0x1de434u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
label_1de438:
    // 0x1de438: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1de438u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de43c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1de43cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1de440: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1de440u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1de444: 0x3e00008  jr          $ra
    ctx->pc = 0x1DE444u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DE438u: goto label_1de438;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DE44Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
