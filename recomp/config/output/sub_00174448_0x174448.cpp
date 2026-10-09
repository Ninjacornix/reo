#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174448
// Address: 0x174448 - 0x174518
void sub_00174448_0x174448(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174448_0x174448");
#endif

    switch (ctx->pc) {
        case 0x174478u: goto label_174478;
        case 0x1744b4u: goto label_1744b4;
        default: break;
    }

    ctx->pc = 0x174448u;

    // 0x174448: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x174448u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x17444c: 0xc76021  addu        $t4, $a2, $a3
    ctx->pc = 0x17444cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x174450: 0x8c8b0004  lw          $t3, 0x4($a0)
    ctx->pc = 0x174450u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x174454: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x174454u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174458: 0x1840002d  blez        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x174458u;
    {
        const bool branch_taken_0x174458 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x17445Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174458u;
            // 0x17445c: 0x8c890010  lw          $t1, 0x10($a0) (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174458) {
            ctx->pc = 0x174510u;
            goto label_174510;
        }
    }
    ctx->pc = 0x174460u;
    // 0x174460: 0x8c8f0000  lw          $t7, 0x0($a0)
    ctx->pc = 0x174460u;
    SET_GPR_S32(ctx, 15, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x174464: 0xa6302b  sltu        $a2, $a1, $a2
    ctx->pc = 0x174464u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x174468: 0x40702d  daddu       $t6, $v0, $zero
    ctx->pc = 0x174468u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17446c: 0xac682b  sltu        $t5, $a1, $t4
    ctx->pc = 0x17446cu;
    SET_GPR_U64(ctx, 13, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 12)) ? 1 : 0);
    // 0x174470: 0x91040  sll         $v0, $t1, 1
    ctx->pc = 0x174470u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x174474: 0x0  nop
    ctx->pc = 0x174474u;
    // NOP
label_174478:
    // 0x174478: 0x491021  addu        $v0, $v0, $t1
    ctx->pc = 0x174478u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x17447c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x17447cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x174480: 0x1e21021  addu        $v0, $t7, $v0
    ctx->pc = 0x174480u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 15), GPR_U32(ctx, 2)));
    // 0x174484: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x174484u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x174488: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x174488u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x17448c: 0xa3402b  sltu        $t0, $a1, $v1
    ctx->pc = 0x17448cu;
    SET_GPR_U64(ctx, 8, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x174490: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x174490u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x174494: 0x184102b  sltu        $v0, $t4, $a0
    ctx->pc = 0x174494u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 12) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x174498: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x174498u;
    {
        const bool branch_taken_0x174498 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17449Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174498u;
            // 0x17449c: 0x100182d  daddu       $v1, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174498) {
            ctx->pc = 0x1744C0u;
            goto label_1744c0;
        }
    }
    ctx->pc = 0x1744A0u;
    // 0x1744a0: 0x15000012  bnez        $t0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1744A0u;
    {
        const bool branch_taken_0x1744a0 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x1744A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1744A0u;
            // 0x1744a4: 0x25220001  addiu       $v0, $t1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1744a0) {
            ctx->pc = 0x1744ECu;
            goto label_1744ec;
        }
    }
    ctx->pc = 0x1744A8u;
    // 0x1744a8: 0xa4102b  sltu        $v0, $a1, $a0
    ctx->pc = 0x1744a8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x1744ac: 0x5040000f  beql        $v0, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x1744ACu;
    {
        const bool branch_taken_0x1744ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1744ac) {
            ctx->pc = 0x1744B0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1744ACu;
            // 0x1744b0: 0x25220001  addiu       $v0, $t1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1744ECu;
            goto label_1744ec;
        }
    }
    ctx->pc = 0x1744B4u;
label_1744b4:
    // 0x1744b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1744B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1744B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1744B4u;
            // 0x1744b8: 0x140102d  daddu       $v0, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174478u: goto label_174478;
            case 0x1744B4u: goto label_1744b4;
            case 0x1744C0u: goto label_1744c0;
            case 0x1744D0u: goto label_1744d0;
            case 0x1744ECu: goto label_1744ec;
            case 0x174500u: goto label_174500;
            case 0x174510u: goto label_174510;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1744BCu;
    // 0x1744bc: 0x0  nop
    ctx->pc = 0x1744bcu;
    // NOP
label_1744c0:
    // 0x1744c0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1744C0u;
    {
        const bool branch_taken_0x1744c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1744c0) {
            ctx->pc = 0x1744D0u;
            goto label_1744d0;
        }
    }
    ctx->pc = 0x1744C8u;
    // 0x1744c8: 0x15a0fffa  bnez        $t5, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1744C8u;
    {
        const bool branch_taken_0x1744c8 = (GPR_U64(ctx, 13) != GPR_U64(ctx, 0));
        if (branch_taken_0x1744c8) {
            ctx->pc = 0x1744B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1744b4;
        }
    }
    ctx->pc = 0x1744D0u;
label_1744d0:
    // 0x1744d0: 0x14c00006  bnez        $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x1744D0u;
    {
        const bool branch_taken_0x1744d0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1744D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1744D0u;
            // 0x1744d4: 0x25220001  addiu       $v0, $t1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1744d0) {
            ctx->pc = 0x1744ECu;
            goto label_1744ec;
        }
    }
    ctx->pc = 0x1744D8u;
    // 0x1744d8: 0x871023  subu        $v0, $a0, $a3
    ctx->pc = 0x1744d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1744dc: 0xa2102b  sltu        $v0, $a1, $v0
    ctx->pc = 0x1744dcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1744e0: 0x1440fff4  bnez        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1744E0u;
    {
        const bool branch_taken_0x1744e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1744e0) {
            ctx->pc = 0x1744B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1744b4;
        }
    }
    ctx->pc = 0x1744E8u;
    // 0x1744e8: 0x25220001  addiu       $v0, $t1, 0x1
    ctx->pc = 0x1744e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
label_1744ec:
    // 0x1744ec: 0x4b182a  slt         $v1, $v0, $t3
    ctx->pc = 0x1744ecu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 11)) ? 1 : 0);
    // 0x1744f0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1744F0u;
    {
        const bool branch_taken_0x1744f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1744F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1744F0u;
            // 0x1744f4: 0x254a0001  addiu       $t2, $t2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1744f0) {
            ctx->pc = 0x174500u;
            goto label_174500;
        }
    }
    ctx->pc = 0x1744F8u;
    // 0x1744f8: 0x12b1023  subu        $v0, $t1, $t3
    ctx->pc = 0x1744f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 11)));
    // 0x1744fc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1744fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_174500:
    // 0x174500: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x174500u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174504: 0x14e102a  slt         $v0, $t2, $t6
    ctx->pc = 0x174504u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 14)) ? 1 : 0);
    // 0x174508: 0x5440ffdb  bnel        $v0, $zero, . + 4 + (-0x25 << 2)
    ctx->pc = 0x174508u;
    {
        const bool branch_taken_0x174508 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x174508) {
            ctx->pc = 0x17450Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x174508u;
            // 0x17450c: 0x91040  sll         $v0, $t1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x174478u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_174478;
        }
    }
    ctx->pc = 0x174510u;
label_174510:
    // 0x174510: 0x3e00008  jr          $ra
    ctx->pc = 0x174510u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174510u;
            // 0x174514: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174478u: goto label_174478;
            case 0x1744B4u: goto label_1744b4;
            case 0x1744C0u: goto label_1744c0;
            case 0x1744D0u: goto label_1744d0;
            case 0x1744ECu: goto label_1744ec;
            case 0x174500u: goto label_174500;
            case 0x174510u: goto label_174510;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174518u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
