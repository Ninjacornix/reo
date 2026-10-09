#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001EB684
// Address: 0x1eb684 - 0x1eb764
void sub_001EB684_0x1eb684(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001EB684_0x1eb684");
#endif

    switch (ctx->pc) {
        case 0x1eb708u: goto label_1eb708;
        default: break;
    }

    ctx->pc = 0x1eb684u;

    // 0x1eb684: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1eb684u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1eb688: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1eb688u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1eb68c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1eb68cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb690: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1eb690u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1eb694: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eb694u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb698: 0x3c026745  lui         $v0, 0x6745
    ctx->pc = 0x1eb698u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)26437 << 16));
    // 0x1eb69c: 0x34422301  ori         $v0, $v0, 0x2301
    ctx->pc = 0x1eb69cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8961);
    // 0x1eb6a0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eb6a0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eb6a4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eb6a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6a8: 0x3c02efcd  lui         $v0, 0xEFCD
    ctx->pc = 0x1eb6a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)61389 << 16));
    // 0x1eb6ac: 0x3442ab89  ori         $v0, $v0, 0xAB89
    ctx->pc = 0x1eb6acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)43913);
    // 0x1eb6b0: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1eb6b0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1eb6b4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eb6b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6b8: 0x3c0298ba  lui         $v0, 0x98BA
    ctx->pc = 0x1eb6b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39098 << 16));
    // 0x1eb6bc: 0x3442dcfe  ori         $v0, $v0, 0xDCFE
    ctx->pc = 0x1eb6bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)56574);
    // 0x1eb6c0: 0xac620008  sw          $v0, 0x8($v1)
    ctx->pc = 0x1eb6c0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
    // 0x1eb6c4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eb6c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6c8: 0x3c021032  lui         $v0, 0x1032
    ctx->pc = 0x1eb6c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4146 << 16));
    // 0x1eb6cc: 0x34425476  ori         $v0, $v0, 0x5476
    ctx->pc = 0x1eb6ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)21622);
    // 0x1eb6d0: 0xac62000c  sw          $v0, 0xC($v1)
    ctx->pc = 0x1eb6d0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 2));
    // 0x1eb6d4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eb6d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6d8: 0x3c02c3d2  lui         $v0, 0xC3D2
    ctx->pc = 0x1eb6d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50130 << 16));
    // 0x1eb6dc: 0x3442e1f0  ori         $v0, $v0, 0xE1F0
    ctx->pc = 0x1eb6dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)57840);
    // 0x1eb6e0: 0xac620010  sw          $v0, 0x10($v1)
    ctx->pc = 0x1eb6e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 2));
    // 0x1eb6e4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6e8: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x1eb6e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x1eb6ec: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb6ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6f0: 0xac400018  sw          $zero, 0x18($v0)
    ctx->pc = 0x1eb6f0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 0));
    // 0x1eb6f4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb6f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb6f8: 0xac40001c  sw          $zero, 0x1C($v0)
    ctx->pc = 0x1eb6f8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 0));
    // 0x1eb6fc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb700: 0xac400020  sw          $zero, 0x20($v0)
    ctx->pc = 0x1eb700u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 0));
    // 0x1eb704: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1eb704u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1eb708:
    // 0x1eb708: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1eb708u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb70c: 0x28420050  slti        $v0, $v0, 0x50
    ctx->pc = 0x1eb70cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)80) ? 1 : 0);
    // 0x1eb710: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1EB710u;
    {
        const bool branch_taken_0x1eb710 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eb710) {
            ctx->pc = 0x1EB720u;
            goto label_1eb720;
        }
    }
    ctx->pc = 0x1EB718u;
    // 0x1eb718: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1EB718u;
    {
        const bool branch_taken_0x1eb718 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb718) {
            ctx->pc = 0x1EB750u;
            goto label_1eb750;
        }
    }
    ctx->pc = 0x1EB720u;
label_1eb720:
    // 0x1eb720: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1eb720u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb724: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1eb724u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb728: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1eb728u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1eb72c: 0x24430020  addiu       $v1, $v0, 0x20
    ctx->pc = 0x1eb72cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
    // 0x1eb730: 0x24820004  addiu       $v0, $a0, 0x4
    ctx->pc = 0x1eb730u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eb734: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1eb734u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1eb738: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1eb738u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1eb73c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1eb73cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb740: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1eb740u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1eb744: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1eb744u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1eb748: 0x1000ffef  b           . + 4 + (-0x11 << 2)
    ctx->pc = 0x1EB748u;
    {
        const bool branch_taken_0x1eb748 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb748) {
            ctx->pc = 0x1EB708u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eb708;
        }
    }
    ctx->pc = 0x1EB750u;
label_1eb750:
    // 0x1eb750: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1eb750u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb754: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1eb754u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1eb758: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1eb758u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1eb75c: 0x3e00008  jr          $ra
    ctx->pc = 0x1EB75Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1EB708u: goto label_1eb708;
            case 0x1EB720u: goto label_1eb720;
            case 0x1EB750u: goto label_1eb750;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1EB764u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
