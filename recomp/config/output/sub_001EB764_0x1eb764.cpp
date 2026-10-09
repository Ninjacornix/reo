#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001EB764
// Address: 0x1eb764 - 0x1eb830
void sub_001EB764_0x1eb764(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001EB764_0x1eb764");
#endif

    switch (ctx->pc) {
        case 0x1eb788u: goto label_1eb788;
        default: break;
    }

    ctx->pc = 0x1eb764u;

    // 0x1eb764: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1eb764u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1eb768: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1eb768u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1eb76c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1eb76cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb770: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1eb770u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1eb774: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1eb774u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1eb778: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1eb778u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb77c: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1eb77cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1eb780: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1eb780u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1eb784: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1eb784u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
label_1eb788:
    // 0x1eb788: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1eb788u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eb78c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1eb78cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb790: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1eb790u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1eb794: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1EB794u;
    {
        const bool branch_taken_0x1eb794 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eb794) {
            ctx->pc = 0x1EB7A4u;
            goto label_1eb7a4;
        }
    }
    ctx->pc = 0x1EB79Cu;
    // 0x1eb79c: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1EB79Cu;
    {
        const bool branch_taken_0x1eb79c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb79c) {
            ctx->pc = 0x1EB81Cu;
            goto label_1eb81c;
        }
    }
    ctx->pc = 0x1EB7A4u;
label_1eb7a4:
    // 0x1eb7a4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1eb7a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eb7a8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1eb7a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1eb7ac: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb7acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb7b0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eb7b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eb7b4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1eb7b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eb7b8: 0x21c00  sll         $v1, $v0, 16
    ctx->pc = 0x1eb7b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1eb7bc: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x1eb7bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1eb7c0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1eb7c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eb7c4: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1eb7c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1eb7c8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1eb7c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eb7cc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1eb7ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1eb7d0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb7d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb7d4: 0x622821  addu        $a1, $v1, $v0
    ctx->pc = 0x1eb7d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eb7d8: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1eb7d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eb7dc: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1eb7dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1eb7e0: 0x3442ff00  ori         $v0, $v0, 0xFF00
    ctx->pc = 0x1eb7e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65280);
    // 0x1eb7e4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1eb7e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1eb7e8: 0x22202  srl         $a0, $v0, 8
    ctx->pc = 0x1eb7e8u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1eb7ec: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1eb7ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eb7f0: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1eb7f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1eb7f4: 0x344200ff  ori         $v0, $v0, 0xFF
    ctx->pc = 0x1eb7f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)255);
    // 0x1eb7f8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1eb7f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1eb7fc: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1eb7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1eb800: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1eb800u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1eb804: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1eb804u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1eb808: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1eb808u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eb80c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1eb80cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1eb810: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1eb810u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1eb814: 0x1000ffdc  b           . + 4 + (-0x24 << 2)
    ctx->pc = 0x1EB814u;
    {
        const bool branch_taken_0x1eb814 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb814) {
            ctx->pc = 0x1EB788u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eb788;
        }
    }
    ctx->pc = 0x1EB81Cu;
label_1eb81c:
    // 0x1eb81c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1eb81cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb820: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1eb820u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1eb824: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1eb824u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1eb828: 0x3e00008  jr          $ra
    ctx->pc = 0x1EB828u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1EB788u: goto label_1eb788;
            case 0x1EB7A4u: goto label_1eb7a4;
            case 0x1EB81Cu: goto label_1eb81c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1EB830u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
