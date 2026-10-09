#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E778
// Address: 0x17e778 - 0x17e870
void sub_0017E778_0x17e778(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E778_0x17e778");
#endif

    ctx->pc = 0x17e778u;

    // 0x17e778: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x17e778u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x17e77c: 0x2466f988  addiu       $a2, $v1, -0x678
    ctx->pc = 0x17e77cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 4294965640));
    // 0x17e780: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x17e780u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x17e784: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17E784u;
    {
        const bool branch_taken_0x17e784 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E784u;
            // 0x17e788: 0x3c050027  lui         $a1, 0x27 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e784) {
            ctx->pc = 0x17E7A0u;
            goto label_17e7a0;
        }
    }
    ctx->pc = 0x17E78Cu;
    // 0x17e78c: 0x8ca26158  lw          $v0, 0x6158($a1)
    ctx->pc = 0x17e78cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24920)));
    // 0x17e790: 0x10440035  beq         $v0, $a0, . + 4 + (0x35 << 2)
    ctx->pc = 0x17E790u;
    {
        const bool branch_taken_0x17e790 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x17E794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E790u;
            // 0x17e794: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e790) {
            ctx->pc = 0x17E868u;
            goto label_17e868;
        }
    }
    ctx->pc = 0x17E798u;
    // 0x17e798: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x17E798u;
    {
        const bool branch_taken_0x17e798 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E79Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E798u;
            // 0x17e79c: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e798) {
            ctx->pc = 0x17E7A8u;
            goto label_17e7a8;
        }
    }
    ctx->pc = 0x17E7A0u;
label_17e7a0:
    // 0x17e7a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17e7a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e7a4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x17e7a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_17e7a8:
    // 0x17e7a8: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x17e7a8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x17e7ac: 0x14830006  bne         $a0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x17E7ACu;
    {
        const bool branch_taken_0x17e7ac = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x17E7B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E7ACu;
            // 0x17e7b0: 0xaca46158  sw          $a0, 0x6158($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 24920), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e7ac) {
            ctx->pc = 0x17E7C8u;
            goto label_17e7c8;
        }
    }
    ctx->pc = 0x17E7B4u;
    // 0x17e7b4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x17e7b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x17e7b8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17e7b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e7bc: 0x3e00008  jr          $ra
    ctx->pc = 0x17E7BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E7C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E7BCu;
            // 0x17e7c0: 0xfc62f980  sd          $v0, -0x680($v1) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 3), 4294965632), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E7A0u: goto label_17e7a0;
            case 0x17E7A8u: goto label_17e7a8;
            case 0x17E7C8u: goto label_17e7c8;
            case 0x17E818u: goto label_17e818;
            case 0x17E81Cu: goto label_17e81c;
            case 0x17E868u: goto label_17e868;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E7C4u;
    // 0x17e7c4: 0x0  nop
    ctx->pc = 0x17e7c4u;
    // NOP
label_17e7c8:
    // 0x17e7c8: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x17e7c8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x17e7cc: 0x3c020008  lui         $v0, 0x8
    ctx->pc = 0x17e7ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8 << 16));
    // 0x17e7d0: 0x3442ca00  ori         $v0, $v0, 0xCA00
    ctx->pc = 0x17e7d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)51712);
    // 0x17e7d4: 0x42880  sll         $a1, $a0, 2
    ctx->pc = 0x17e7d4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x17e7d8: 0xfc62f980  sd          $v0, -0x680($v1)
    ctx->pc = 0x17e7d8u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 4294965632), GPR_U64(ctx, 2));
    // 0x17e7dc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x17e7dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x17e7e0: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x17e7e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x17e7e4: 0x8c841580  lw          $a0, 0x1580($a0)
    ctx->pc = 0x17e7e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 5504)));
    // 0x17e7e8: 0x24030082  addiu       $v1, $zero, 0x82
    ctx->pc = 0x17e7e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 130));
    // 0x17e7ec: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x17e7ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17e7f0: 0x304200c7  andi        $v0, $v0, 0xC7
    ctx->pc = 0x17e7f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)199);
    // 0x17e7f4: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x17E7F4u;
    {
        const bool branch_taken_0x17e7f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17E7F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E7F4u;
            // 0x17e7f8: 0x3c060024  lui         $a2, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e7f4) {
            ctx->pc = 0x17E818u;
            goto label_17e818;
        }
    }
    ctx->pc = 0x17E7FCu;
    // 0x17e7fc: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x17e7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x17e800: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x17e800u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x17e804: 0x8c421590  lw          $v0, 0x1590($v0)
    ctx->pc = 0x17e804u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5520)));
    // 0x17e808: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x17e808u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x17e80c: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x17e80cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x17e810: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x17E810u;
    {
        const bool branch_taken_0x17e810 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E810u;
            // 0x17e814: 0x24c21590  addiu       $v0, $a2, 0x1590 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 5520));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e810) {
            ctx->pc = 0x17E81Cu;
            goto label_17e81c;
        }
    }
    ctx->pc = 0x17E818u;
label_17e818:
    // 0x17e818: 0x24c21590  addiu       $v0, $a2, 0x1590
    ctx->pc = 0x17e818u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 5520));
label_17e81c:
    // 0x17e81c: 0x3c060027  lui         $a2, 0x27
    ctx->pc = 0x17e81cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)39 << 16));
    // 0x17e820: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x17e820u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x17e824: 0x3c050027  lui         $a1, 0x27
    ctx->pc = 0x17e824u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
    // 0x17e828: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x17e828u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17e82c: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x17e82cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x17e830: 0x24846160  addiu       $a0, $a0, 0x6160
    ctx->pc = 0x17e830u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24928));
    // 0x17e834: 0x24a56170  addiu       $a1, $a1, 0x6170
    ctx->pc = 0x17e834u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24944));
    // 0x17e838: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x17e838u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17e83c: 0x3c070027  lui         $a3, 0x27
    ctx->pc = 0x17e83cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)39 << 16));
    // 0x17e840: 0x24e76180  addiu       $a3, $a3, 0x6180
    ctx->pc = 0x17e840u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 24960));
    // 0x17e844: 0x24c66184  addiu       $a2, $a2, 0x6184
    ctx->pc = 0x17e844u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 24964));
    // 0x17e848: 0xa4820008  sh          $v0, 0x8($a0)
    ctx->pc = 0x17e848u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x17e84c: 0xfc800000  sd          $zero, 0x0($a0)
    ctx->pc = 0x17e84cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 0));
    // 0x17e850: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x17e850u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17e854: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x17e854u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x17e858: 0xdc830008  ld          $v1, 0x8($a0)
    ctx->pc = 0x17e858u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x17e85c: 0xfca30008  sd          $v1, 0x8($a1)
    ctx->pc = 0x17e85cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 3));
    // 0x17e860: 0xace40000  sw          $a0, 0x0($a3)
    ctx->pc = 0x17e860u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x17e864: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x17e864u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
label_17e868:
    // 0x17e868: 0x3e00008  jr          $ra
    ctx->pc = 0x17E868u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E7A0u: goto label_17e7a0;
            case 0x17E7A8u: goto label_17e7a8;
            case 0x17E7C8u: goto label_17e7c8;
            case 0x17E818u: goto label_17e818;
            case 0x17E81Cu: goto label_17e81c;
            case 0x17E868u: goto label_17e868;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E870u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
