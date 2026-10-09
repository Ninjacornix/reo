#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DE44C
// Address: 0x1de44c - 0x1de540
void sub_001DE44C_0x1de44c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DE44C_0x1de44c");
#endif

    ctx->pc = 0x1de44cu;

    // 0x1de44c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1de44cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1de450: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1de450u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1de454: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1de454u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de458: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1de458u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1de45c: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de45cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de460: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de460u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de464: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de464u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de468: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de468u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de46c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de46cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de470: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de470u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de474: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de474u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de478: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de478u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de47c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de47cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de480: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de480u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de484: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de484u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de488: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1de488u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de48c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de48cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de490: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de490u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de494: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de494u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de498: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de498u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de49c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de49cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de4a0: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1de4a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de4a4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de4a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de4a8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de4a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de4ac: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de4acu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de4b0: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de4b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de4b4: 0xaca20008  sw          $v0, 0x8($a1)
    ctx->pc = 0x1de4b4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
    // 0x1de4b8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de4b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de4bc: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1de4bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de4c0: 0x3c024e41  lui         $v0, 0x4E41
    ctx->pc = 0x1de4c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20033 << 16));
    // 0x1de4c4: 0x34424d45  ori         $v0, $v0, 0x4D45
    ctx->pc = 0x1de4c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19781);
    // 0x1de4c8: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1DE4C8u;
    {
        const bool branch_taken_0x1de4c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1de4c8) {
            ctx->pc = 0x1DE52Cu;
            goto label_1de52c;
        }
    }
    ctx->pc = 0x1DE4D0u;
    // 0x1de4d0: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1de4d0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de4d4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de4d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de4d8: 0x8c42000c  lw          $v0, 0xC($v0)
    ctx->pc = 0x1de4d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1de4dc: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1de4dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1de4e0: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1de4e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1de4e4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de4e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de4e8: 0x8c42000c  lw          $v0, 0xC($v0)
    ctx->pc = 0x1de4e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1de4ec: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1de4ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1de4f0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1de4f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1de4f4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1de4f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1de4f8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de4f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de4fc: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x1de4fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1de500: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1de500u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1de504: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de504u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de508: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1de508u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1de50c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1de50cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de510: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de510u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de514: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x1de514u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1de518: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1de518u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1de51c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1de51cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1de520: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1de520u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1de524: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1de524u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1de528: 0xaca2000c  sw          $v0, 0xC($a1)
    ctx->pc = 0x1de528u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 2));
label_1de52c:
    // 0x1de52c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1de52cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de530: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1de530u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1de534: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1de534u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1de538: 0x3e00008  jr          $ra
    ctx->pc = 0x1DE538u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DE52Cu: goto label_1de52c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DE540u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
